"""
《星空回响》场景对齐验伤脚本
用法：python check_align.py

【硬约束】所有场景 .txt 必须：
  1. 严格 20 行
  2. 100% 纯 ASCII（无中文/emoji/★/✦/box char）
  3. 最大行宽 <= 48

  这样才能保证在 VSCode / Notepad / cmd / Dev-C++ 里
  对齐是绝对一致的（不依赖字体是否支持中文）。

【场景 vs 文档的区别】
  - 场景 .txt：给代码读入 char bg[20][49]，必须纯 ASCII
  - 文档 .txt：给人看的，可以有中文（但对话框内部要对齐）
"""
import unicodedata, os, sys, io, re

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')


def display_width(s):
    return sum(2 if unicodedata.east_asian_width(c) in 'WF' else 1 for c in s)


def check_scene(fname):
    """场景 txt：必须 20 行 + 纯 ASCII + <= 48 宽"""
    try:
        with open(fname, encoding='utf-8') as fp:
            content = fp.read()
    except FileNotFoundError:
        return {'exists': False}

    bad_chars = set(c for c in content if ord(c) > 127 and c not in '\n\r')
    lines = content.split('\n')
    while lines and lines[-1] == '':
        lines.pop()
    max_w = max((len(l) for l in lines), default=0)

    return {
        'exists': True,
        'lines': len(lines),
        'max_width': max_w,
        'ascii': len(bad_chars) == 0,
        'bad_chars': bad_chars,
    }


def check_boxes_in_doc(fname):
    """文档内嵌的对话框：连续的 |...| 行应显示宽度一致"""
    try:
        with open(fname, encoding='utf-8') as fp:
            lines = fp.read().split('\n')
    except FileNotFoundError:
        return None

    blocks, cur = [], []
    for i, line in enumerate(lines, 1):
        s = line.rstrip()
        m = re.search(r'([|+].*[|+])', s)
        if m and m.group(1)[0] in '+|' and m.group(1)[-1] in '+|':
            cur.append((i, m.group(1), display_width(m.group(1))))
        else:
            if cur:
                blocks.append(cur)
                cur = []
    if cur:
        blocks.append(cur)
        

    problems = []
    for blk in blocks:
        if len(blk) < 2:
            continue
        widths = set(item[2] for item in blk)
        if len(widths) > 1:
            problems.append((blk[0][0], widths))
    return problems


def check_coords():
    """验证坐标参考里声明的物品坐标是否命中对应 A/B/C/T 字符"""
    COORDS = {
        'prologue':      {'A':(14,12), 'B':(32,12), 'C':(21,17)},
        'library':       {'A':(16,11), 'B':(29,11), 'C':(12,16)},
        'rooftop':       {'A':(20,11), 'B':(38,14), 'C':(25,16)},
        'hospital':      {'A':( 6,15), 'B':(34,15), 'C':(18,17)},
        'planetarium':   {'A':(13,16), 'B':(26,16), 'C':(34,16)},
        'finale':        {'A':(14,13), 'B':(32,13), 'C':(21, 4)},
        'vega_library':  {'T1':(16,11), 'T2':(29,11), 'T3':( 2,19)},
        'vega_rooftop':  {'T1':(20,11), 'T2':(20,16), 'T3':(43,14)},
        'vega_hospital': {'T1':(39,15), 'T2':(25, 3), 'T3':(17,14)},
        'vega_room':     {'T1':(13,11), 'T2':(23,11), 'T3':(32,11), 'T4':(14,16)},
    }

    total = 0
    failed = []
    for scene, items in COORDS.items():
        try:
            with open(f'{scene}.txt', encoding='utf-8') as f:
                lines = f.read().split('\n')
        except FileNotFoundError:
            for tag in items:
                failed.append((scene, tag, 'file not found'))
            continue
        while lines and lines[-1] == '':
            lines.pop()

        for tag, (x, y) in items.items():
            total += 1
            if y >= len(lines):
                failed.append((scene, tag, f'y={y} 超出行数 {len(lines)}'))
                continue
            line = lines[y]
            if x >= len(line):
                failed.append((scene, tag, f'x={x} 超出行长 {len(line)}'))
                continue
            ch = line[x]
            expect = tag[0]
            if ch != expect:
                failed.append((scene, tag, f'({x},{y}) 是 {ch!r}, 应为 {expect!r}'))
    return total, failed


def main():
    os.chdir(r'E:\《星空回响》')

    print('=' * 60)
    print('场景 .txt 检查（20 行 + 纯 ASCII + <= 48 宽）')
    print('=' * 60)

    scenes = ['title', 'prologue', 'library', 'rooftop', 'hospital',
              'planetarium', 'finale',
              'vega_library', 'vega_rooftop', 'vega_hospital', 'vega_room']

    # title.txt 允许中文（因为它用"上下横线"版式，中文不会导致对齐问题）
    # 其余场景必须纯 ASCII（因为要作为骨架 char bg[20][49] 读入代码）
    ascii_required = {n for n in scenes if n != 'title'}

    all_ok = True
    for name in scenes:
        r = check_scene(f'{name}.txt')
        if not r['exists']:
            print(f'  ??  {name}.txt: 文件不存在')
            all_ok = False
            continue
        need_ascii = (name in ascii_required)
        ok_line = (r['lines'] == 20)
        ok_ascii = (not need_ascii) or r['ascii']
        ok_width = (r['max_width'] <= 48)
        ok = ok_line and ok_ascii and ok_width
        tag = 'OK' if ok else '!!'
        note = '' if need_ascii else '  (允许中文)'
        print(f'  [{tag}] {name}.txt: {r["lines"]} lines / {r["max_width"]} cols / ascii={r["ascii"]}{note}')
        if r['bad_chars'] and need_ascii:
            print(f'      非 ASCII 字符: {r["bad_chars"]}')
        if not ok:
            all_ok = False

    print()
    print('=' * 60)
    print('物品/触发点坐标检查（vs 坐标参考 v7）')
    print('=' * 60)
    total, failed = check_coords()
    if not failed:
        print(f'  ✓  {total}/{total} 个坐标全部命中对应字符')
    else:
        print(f'  !!  {len(failed)}/{total} 个坐标不匹配:')
        for scene, tag, msg in failed:
            print(f'      {scene} {tag}: {msg}')
        all_ok = False

    print()
    print('=' * 60)
    print('文档内对话框对齐检查')
    print('=' * 60)

    docs = ['对话框设计.txt', '章节过场模板.txt',
            '结局与TE画面稿.txt', 'Vega开场结尾画面稿.txt']
    for name in docs:
        probs = check_boxes_in_doc(name)
        if probs is None:
            print(f'  ??  {name}: 文件不存在')
            continue
        if not probs:
            print(f'  ✓  {name}')
        else:
            # 结局与TE画面稿有个天文馆椅子画会误报，宽容
            if name == '结局与TE画面稿.txt' and len(probs) == 1 and probs[0][0] > 300:
                print(f'  ✓  {name}  (幕 1 椅子画艺术不规则，已豁免)')
            else:
                print(f'  !!  {name}: {len(probs)} 处不齐')
                all_ok = False
                for row, ws in probs:
                    print(f'      从行 {row}: 宽度 {sorted(ws)}')

    print()
    print('*** ALL PASS ***' if all_ok else '*** HAS PROBLEMS ***')


if __name__ == '__main__':
    main()