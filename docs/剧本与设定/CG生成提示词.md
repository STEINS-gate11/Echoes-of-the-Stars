# 《星空回响》CG 生成提示词手册 · 24 张

> **依据**：`新建 文本文档 (11).txt`（第一至第四章全文本）里每个物品自带的两段「画面描述」。
> **数量**：4 章 × 3 物品 × 2 张 = **24 张**。
> **工具**：GPT Image 2。挂参考图 + 一段自然语言指令。
>
> **修订说明**：本文件是重写版。旧版只有 12 张，且把第四章写成了「电影院」（实际是**城南天文馆**）、
> 编了一件正文里不存在的「藏青色外套」当伏笔、并且把三章的衣服统一写成了同一套。这些错误已全部修掉。

---

## 零、先看这张表：24 张里只有 8 张需要她的脸

这是最省事的一点。大部分 CG 是物品特写、第一人称、或主角背影 —— **不出现她**，也就不存在角色一致性问题，可以随便重跑。

| 章 | 物品 | A 图 | B 图 |
|---|---|---|---|
| 一 · 图书馆 | 📚 天文书籍 | 书页特写（主角的手） | **她**·书架缝隙对视 ★ |
| 一 · 图书馆 | ☕ 两杯咖啡 | 两杯咖啡俯拍（无人） | **她**·端着咖啡站书架旁 ★ |
| 一 · 图书馆 | 📝 手写便签 | 便签滑落（无人） | 主角背影·雨窗 |
| 二 · 天台 | 🔭 望远镜 | 镜筒刻字微距（无人） | **她**·蹲在望远镜旁 ★ |
| 二 · 天台 | 📸 拍立得 | 相纸显影（主角手 + **她半张脸** ★） | **她**·看照片的侧脸 ★ |
| 二 · 天台 | 🎵 耳机 | 耳机线特写（主角手） | **她**·闭眼靠栏杆 ★ |
| 三 · 医院 | 📋 检查报告 | **她**·病床上抬头看你 ★ | 主角侧面·低头看报告 |
| 三 · 医院 | 📱 手机屏幕 | 手机 17 个未接（主角手） | **她**·睡着 + 主角坐床边 ★ |
| 三 · 医院 | 💊 未开封的药 | 药瓶特写（无人） | **她**·仰头看他 + 主角站着 ★ |
| 四 · 天文馆 | 🎫 两张门票 | 两张票俯拍（无人） | 主角背影·仰头看穹顶 |
| 四 · 天文馆 | 💌 没寄出的信 | 信纸特写（无人） | 信在膝盖上（主角第一人称） |
| 四 · 天文馆 | ⭐ 拆开的星星 | 地板上的星星（无人） | 手心摊开的票根（主角手） |

★ = 需要挂参考图锁脸，共 **8 张**（1-1B、1-2B、2-1B、2-2A、2-2B、3-1A、3-2B、3-3B）。
**第四章她一张脸都没有** —— 她已经走了，整章只有物品和主角。这是文本自己的设计，不要给第四章加人。

**跑图顺序建议**：先跑那 8 张有脸的（同一个对话里连着跑，脸最稳），跑完锁定；剩下 16 张随便什么时候跑，互不影响。

---

## 一、角色设定

### 她（锁死，8 张有脸的都照这个）

| 项目 | 设定 |
|---|---|
| 发色 | 银白，带**极淡的薰衣草紫**（#EDE9F2 → 发梢 #DCD6E8），不是纯白 |
| 发型 | 超长直发，**过膝**；中分偏刘海；两侧耳前长鬓发垂到胸前；发梢微微内扣 |
| 眼睛 | **大**，上眼线平缓、**眼尾略下垂**（最关键的一点）；虹膜**浅蓝偏一点紫**，大颗高光 |
| 脸型 | 小脸，圆额头，**尖下巴**；鼻子极小 |
| 肤色 | 瓷白，脸颊极淡的粉 |
| 表情基调 | 平时**无表情或极淡的忧郁**，嘴小且闭合。她笑的时候**只是嘴角动一下** |
| 身形 | 155cm，纤细，17–20 岁 |

**衣服按章换**（正文里明确写了，不要统一）：

| 章 | 衣服 |
|---|---|
| 一 · 图书馆 | **米白色毛衣**，领口处隐约一根**细银链** |
| 二 · 天台 | **浅灰色毛衣**；随身一个**帆布包** |
| 三 · 医院 | **宽大的病号服**；脸色比之前白，嘴唇颜色淡；**头发比之前更长**；手背上有留置针胶布 |
| 四 · 天文馆 | 不出现 |

### 他（主角）

正文是第一人称，没给外形。**统一处理成：只画背影、侧面、或手，永远不给正脸。** 深色外套、短发、男大学生。这样既不用定他的长相，也符合第一人称叙事 —— 玩家自己就是他。

### 场景色调

| 章 | 色调 |
|---|---|
| 一 · 图书馆 | 暖黄，百叶窗**条纹光栅**，空气里有浮尘；深棕色木桌；窗外老银杏 |
| 二 · 天台 | 深蓝夜空；远处城市灯火连成一条**暖黄色的带子**；生锈铁栏杆 |
| 三 · 医院 | 走廊是**偏蓝的冷白炽灯**，病房里偏暖；整体降饱和 |
| 四 · 天文馆 | **深蓝穹顶投影星空**；放映厅一片空；出口应急灯是唯一实光源 |

---

## 二、GPT Image 2 怎么用

### 参考图

已经从原图裁好，在 `E:\《星空回响》\CG参考\`：

| 文件 | 尺寸 | 用途 |
|---|---|---|
| `ref_full.png` | 760 × 1610 | **全身立绘** —— 8 张有脸的都挂它 |
| `ref_face.png` | 520 × 580 | **面部特写** —— 脸跑偏时第二张一起挂 |

日文竖排台词、数据表、Q 版小人、水印都已裁掉，只剩人物本身。

### 有脸的 8 张，用这个模板

新开一个对话（不要在跑过别的角色的对话里接着跑，上下文会污染脸），上传 `ref_full.png`，然后：

```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤，
表情是没有表情或极淡的忧郁，嘴小且闭着，笑的时候只是嘴角动一下。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、电影感构图、精致的眼睛。

【场景】

只画她一个人。不要双马尾、丸子头、短发，不要改发色瞳色，
不要张嘴大笑或夸张表情，不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
【比例】
```

### 没脸的 16 张，不用挂图，直接说

```
galgame CG 风格的场景插画：柔和赛璐璐上色、干净线稿、电影感构图、
浅景深、光影细腻。画面里不出现人的脸。

【场景】

不要文字水印，不要 3D 渲染或写实照片风格，手要画对不要多指。
【比例】
```

### 尺寸：**已定案 —— 走弹窗 PNG**（`system("start xxx.png")`）

不用迁就控制台画布了，按每张的画面内容取最合适的比例。GPT Image 2 只有三个原生尺寸：

| 尺寸 | 比例 | 用在哪 | 张数 |
|---|---|---|---|
| `1024×1536` | 2:3 竖 | **人物全身/中景** —— 站着、蹲着、背影，纵向构图 | 7 |
| `1536×1024` | 3:2 横 | **特写和横向场面** —— 桌面、俯拍、躺着、并排的两个东西 | 16 |
| `1024×1024` | 1:1 方 | 只有 3-2A 手机屏幕（竖屏 UI 塞进方图最稳） | 1 |

逐张对照表（下面每张标题下也重复标了）：

| 竖版 `1024×1536`（7 张） | 横版 `1536×1024`（16 张） |
|---|---|
| 1-1B 书架缝隙对视 | 1-1A 书页特写 |
| 1-2B 她端咖啡站书架旁 | 1-2A 两杯咖啡俯拍 |
| 1-3B 主角雨窗背影 | 1-3A 便签滑落 |
| 2-1B 她蹲在望远镜旁 | 2-1A 镜筒刻字微距 |
| 3-1A 她病床上抬头 | 2-2A 拍立得显影 |
| 3-1B 主角低头看报告 | 2-2B 她看照片侧脸 |
| 3-3B 她仰头看他 | 2-3A 耳机线特写 |
| | 2-3B 她闭眼靠栏杆 |
| | 3-2B 她睡着+他坐床边 |
| | 3-3A 药瓶特写 |
| | 4-1A 两张票俯拍 |
| | 4-1B 主角仰头看穹顶 |
| | 4-2A 信纸特写 |
| | 4-2B 信在膝盖上 |
| | 4-3A 地板上的星星 |
| | 4-3B 手心摊开的票根 |

> 有几张我把原本标「竖版」的改成了横版，理由写在那张下面 ——
> 2-2B、2-3B 要带上远处那条城市灯火的光带，横着才装得下；
> 4-1B 要让「空着的那个座位」和他并排出现在同一画面里。

**走弹窗路线之后，第八节（ASCII 那套高对比度要求）整节都不用管了。**
可以放心保留「电影感构图、浅景深、精细光影」—— 这些在 PNG 里全都是加分项，
在 ASCII 里才是负担。

### 几个必须知道的坑

- **它吃自然语言，不吃逗号堆 tag。** 下面每张我给了**中文自然语言版**（你用这个）和英文 tag 版（换工具时用）。
- **没有 `--cref` / `--cw` / vibe 强度滑块。** 一致性全靠：挂着参考图 + 指令里明写"保持长相不变"。这两句都不能省。
- **没有负面提示词框。** 排除项要写成"不要…"的句子接在末尾（模板里已经带了）。
- **比例靠说不靠参数。** 说"竖版 2:3"或"横版 3:2"，别写 `--ar`，它不认。
- **同一个对话里可以接着改。** 出图后直接说"眼尾再下垂一点""外套改深一点""背景再虚一点"，比重跑稳，脸也不会变。
- **手写中文它画不准。** 凡是画面里有字的（1-1A 扉页、1-3A 便签、2-1A 镜筒刻字、4-2A 信纸、4-3B 票根），大概率出乱码。两种办法：① 指令里写"字迹看得出是手写但不需要可读"，接受它糊过去；② **让它在那块留白，出图后你自己用画图/PS 把字加上去** —— 4-3B 是全篇揭示点，建议走第二种。

---

## 三、第一章 · 初遇 · 图书馆

### 📚 物品A：天文书籍

#### CG 1-A　阳光下翻开书页的特写
> 景别：特写（手 + 书页 + 光栅）　氛围：安静、暖黄、发现　**无脸** · 横版 `1536×1024`

中文：
```
第一人称特写。深棕色木桌占据画面下半部分，一册旧书摊开在桌面上，
扉页上有一行铅笔手写字，在百叶窗的条纹光线下微微反光。
一只手从画面左侧入镜，指尖停在离纸面约一指宽的位置，没有碰到纸。
桌角另有一本摊开的笔记，上面画着一颗红色五角星，旁边有一行手写的小字。
午后阳光透过百叶窗在桌面上切出明暗交替的条纹光栅，光柱里有细小的浮尘缓缓飘动。
暖黄色调，浅景深。字迹看得出是手写但不需要可读。
```
英文 tag 版：
```
first person close-up, old book open on dark brown wooden desk, faint pencil handwriting on the
title page, horizontal striped light from venetian blinds across the desk, dust motes floating in
light beams, a hand entering from the left, fingertip hovering one inch above the paper,
open notebook at the corner with a small red five-pointed star drawn on it,
warm amber tones, shallow depth of field, no face
```

#### CG 1-B　隔着书架的第一次对视 ★挂参考图
> 景别：主角视角（书架缝隙 + 她 + 地面光斑）　氛围：被发现了，但不想藏　**有脸** · 竖版 `1024×1536`

中文：
```
主角视角。前景是书架，透过书脊之间一道狭窄的缝隙看过去，她站在书架对面。
她穿米白色毛衣，被午后的光照得有点透，领口处隐约可见一根细银链。
她的目光穿过那道缝隙，不躲不闪，直直落在镜头这一侧。嘴角只有很小但很明确的一点弧度。
她的右手搭在书脊上，食指停在某一本书的顶端，像是刚把它放回去，那本书封面上印着星座图。
午后的光从书架高处的窗户斜射进来，在地面上落下一个梯形的光斑，正好在两人之间。
暖黄色调，画面被书架的竖线分割。
```
英文 tag 版：
```
1girl, seen through a narrow gap between books on a tall bookshelf, standing on the other side,
off-white cream sweater backlit by afternoon sun, thin silver necklace faintly visible at the collar,
looking directly through the gap at the viewer, very faint small smile,
right hand resting on a book spine, index finger at the top of a book with a constellation chart cover,
trapezoid patch of sunlight on the floor between them, warm amber tones, vertical framing
```

---

### ☕ 物品B：两杯咖啡

#### CG 2-A　桌上的两杯咖啡
> 景别：俯拍特写（两杯咖啡 + 笔记本 + 影子）　氛围：凉的温柔　**无脸** · 横版 `1536×1024`

中文：
```
俯拍特写。两个白色陶瓷咖啡杯并排放在深棕色木桌上。
左边那杯是满的，深褐色液面平整，表面浮着一层冷却后的油膜，反光钝而模糊，像一面磨砂的镜子。
右边那杯液面低了一小截，杯沿内侧有一个很浅的唇印。
两杯之间是摊开的笔记本，上面画着一颗红色五角星和一行手写小字。
午后的光已经偏斜，把两个杯子的影子拉得很长，两道影子在桌面上几乎连在一起，
但没有真的碰上 —— 像一个不太确定该不该靠近的人，最终停在半步之外。
暖黄色调，浅景深。
```
英文 tag 版：
```
overhead close-up, two white ceramic coffee cups side by side on a dark brown wooden desk,
left cup full with a cooled oily film on the surface, dull matte reflection,
right cup slightly drunk with a faint lip mark on the rim, open notebook between them
with a small red star drawn on it, low slanting afternoon light casting two long shadows
that almost touch but do not, warm amber tones, shallow depth of field, no face
```

#### CG 2-B　她端着咖啡站在书架旁 ★挂参考图
> 景别：侧面中景（她 + 咖啡 + 书架）　氛围：最后一句话还没说　**有脸** · 竖版 `1024×1536`

中文：
```
侧面中景。她站在书架旁边，身体微微侧向镜头的方向。
右手端着那杯喝过的纸咖啡杯，杯沿快要碰到嘴唇但还没碰到 —— 像是在犹豫要不要喝最后一口。
左手抓着帆布包的背带，包挂在肩上。她穿米白色毛衣。
暖橙色的斜阳从画面左侧的窗户照进来，在她身后的地面上拉出一道长长的人影。
她的目光落在镜头的方向，嘴角带着一点几乎看不出来的弧度。
身后书架上的书脊颜色在昏暗里一片一片连在一起，虚焦。
暖黄偏橙的色调。
```
英文 tag 版：
```
1girl, side view medium shot, standing beside a bookshelf, body turned slightly toward the viewer,
right hand holding a paper coffee cup, rim almost touching her lips but not quite, hesitating,
left hand gripping a canvas tote bag strap on her shoulder, off-white cream sweater,
warm orange late afternoon light from a window on the left, her long shadow stretching behind her,
looking toward the viewer, barely perceptible faint smile,
blurred bookshelf spines behind her, warm amber orange tones
```

---

### 📝 物品C：手写便签

#### CG 3-A　便签从书页间滑落
> 景别：桌面特写（便签 + 书页 + 光带）　氛围：发现的瞬间　**无脸** · 横版 `1536×1024`

中文：
```
特写。一册翻开的书躺在深棕色桌面上，书页中央夹着一张浅黄色的方形便签，
边缘刚刚从纸页间滑出来一半，一角微微翘起，形成一个细小的弧度。
便签上用蓝色圆珠笔写着两行手写字，笔迹纤瘦。
百叶窗的条纹光带横跨桌面，正好落在便签纸的上半部分。
便签背面隐约透出另一行字的墨迹，看得出来是后来补上去的。
暖黄色调，浅景深。字迹看得出是手写但不需要可读。
```
英文 tag 版：
```
desk close-up, open book on a dark brown wooden desk, a pale yellow square sticky note
half slipped out from between the pages, one corner slightly curled up,
two lines of thin blue ballpoint handwriting on it,
striped light from venetian blinds crossing the desk, falling on the upper half of the note,
faint ink from another line showing through from the back,
warm amber tones, shallow depth of field, no face
```

#### CG 3-B　主角站在窗前看雨夜
> 景别：中景（背影 + 雨窗 + 便签）　氛围：错过、安静的、下着雨的　**只有主角背影** · 竖版 `1024×1536`

中文：
```
男生的背影中景，不要露出脸。他站在宿舍窗前，穿深色外套，短发。
窗外是一片深蓝色的雨夜，雨丝在玻璃上斜斜地滑落，
把窗外的城市灯火拉成一道道细长的光痕。
玻璃上浅浅地映着他自己的轮廓，是一个很模糊的影子。
天空被厚重的云层完全遮住，一颗星星也看不见。
他的左手垂在身侧，指尖夹着一张浅黄色的便签纸，边缘微微卷起。
窗台上放着一杯水，已经凉了。
深蓝与冷灰的色调，房间里没开灯，唯一的光来自窗外。
```
英文 tag 版：
```
1boy, back view medium shot, no face visible, standing at a dormitory window, dark coat, short hair,
deep blue rainy night outside, raindrops sliding diagonally down the glass,
city lights stretched into long thin streaks, his own faint reflection on the glass,
thick cloud cover, no stars at all,
left hand at his side holding a pale yellow sticky note between his fingertips, edge slightly curled,
a glass of water gone cold on the windowsill,
deep blue and cold grey tones, room unlit, only light from outside
```

---

## 四、第二章 · 相伴 · 天台

### 🔭 物品A：望远镜

#### CG 1-A　镜筒上的两个字母
> 景别：微距特写（刻字 + 镜筒 + 夜露）　氛围：被发现的心跳　**无脸** · 横版 `1536×1024`

中文：
```
微距特写。一段银灰色的天文望远镜镜筒占据画面大部分，
表面的漆已经斑驳，剥落处露出下面暗青色的金属底漆。
镜筒中间段刻着两个大写字母，并排，间距均匀，笔画利落，
刻痕的边缘微微发亮，像是被反复触摸过。
手电筒的冷白色光从画面外斜打过来，让两个刻痕投下细长的阴影。
镜筒表面结了一层薄薄的夜露，在手电光下折射出细碎的光点。
背景虚焦成深蓝色的夜空。
```
> 刻的是「主角首字母」和「她的首字母」。你自己的设定是什么就填什么，或者让它画两个笼统的字母，出图后自己改。

英文 tag 版：
```
macro close-up, silver grey astronomical telescope tube filling most of the frame,
worn chipped paint exposing dark teal metal primer underneath,
two carved capital letters side by side in the middle of the tube, evenly spaced, clean strokes,
carved edges slightly polished as if touched many times,
cold white flashlight beam from off-frame casting long thin shadows in the grooves,
thin night dew on the metal surface refracting tiny points of light,
deep blue night sky bokeh background, no face
```

#### CG 1-B　她蹲在望远镜旁 ★挂参考图
> 景别：侧面中景（她 + 望远镜 + 天台）　氛围：「如果有一天」　**有脸** · 竖版 `1024×1536`

中文：
```
侧面中景。夜晚的水泥天台上，她蹲在一台旧望远镜旁边，身体微微前倾，
目光落在镜筒上的刻字处。她的手搭在镜筒旁边，没有碰到刻字，只是很靠近。
她穿浅灰色毛衣。夜风从画面右侧吹来，把她的长发吹起来几缕。
天台上方是深蓝色的夜空，远处的城市灯火在天际线处连成一条暖黄色的带子。
她的轮廓在暗光中很清晰。她的表情很安静，像是在想什么。
冷调深蓝为主，远处一条暖黄的光带，星光做轮廓光。
```
英文 tag 版：
```
1girl, side view medium shot, crouching beside an old astronomical telescope on a concrete rooftop
at night, leaning slightly forward, looking at the carved letters on the tube,
her hand resting near the carving but not touching it, light grey sweater,
night wind from the right lifting a few strands of her long silver hair,
deep blue night sky above, distant city lights forming a warm amber band along the horizon,
clear silhouette in dim light, quiet thoughtful expression,
cool deep blue palette with a warm amber band, starlight rim lighting
```

---

### 📸 物品B：拍立得照片

#### CG 2-A　拍立得刚吐出来的瞬间 ★挂参考图
> 景别：第一人称近景（相纸 + 主角手 + 她凑近的半张脸）　氛围：等待显影的那几十秒　**有半张脸** · 横版 `1536×1024`

中文：
```
第一人称近景。画面前景是一只手，捏着一张刚从拍立得里吐出来的相纸，
相纸正在显影中 —— 上面只有模糊的、正在慢慢浮现的轮廓，还看不清内容。
背景虚焦：她正凑过来看这张相纸，肩膀近在咫尺，
半张脸出现在画面右上方，只有一只眼睛完整地出现在画面里，正盯着相纸看。
她穿浅灰色毛衣。画面下缘是野餐垫的一角，
远处的城市灯火连成一条模糊的暖黄光带。夜晚，冷调深蓝。
```
> 她只露半张脸，但那只眼睛必须对 —— 眼尾下垂、浅蓝偏紫。参考图还是要挂。

英文 tag 版：
```
first person close-up, a hand in the foreground holding a freshly ejected polaroid photo,
image still developing, only vague emerging shapes, nothing legible yet,
背景 out of focus: 1girl leaning in to look at the photo, her shoulder very close,
half of her face at the upper right of the frame, only one eye fully visible, fixed on the photo,
light grey sweater, corner of a picnic blanket at the bottom edge,
distant city lights as a blurred warm amber band, night, cool deep blue tones
```

#### CG 2-B　她看着照片的侧脸 ★挂参考图
> 景别：侧面近景（她 + 照片 + 月光）　氛围：「那就以后再拍」　**有脸** · 横版 `1536×1024`
> （原定竖版，改横版 —— 要把远处那条城市灯火的光带带进来，横着才装得下）

中文：
```
侧面近景。夜晚的天台，她低头看着手里那张拍立得照片，
嘴角带着一点还没来得及收回去的笑意 —— 很淡，但是真的。
夜风把她的长发吹起来几缕。她穿浅灰色毛衣。
她的手指捏着照片的边缘，指节微微泛白 —— 捏得比需要的力气大一点。
一小片月光落在她的手背上。
身后是天台的铁栏杆，在远处城市灯火的衬托下变成一道深色的剪影。
背景是深蓝色的夜空和远处那条暖黄的光带。冷调深蓝，月光做主光。
```
英文 tag 版：
```
1girl, side view close-up, night rooftop, looking down at a polaroid photo in her hands,
a faint genuine smile she hasn't put away yet,
night wind lifting a few strands of her long silver hair, light grey sweater,
fingers pinching the edge of the photo, knuckles slightly pale from gripping too hard,
a small patch of moonlight on the back of her hand,
rooftop iron railing behind her as a dark silhouette against distant city lights,
deep blue night sky, warm amber band on the horizon, moonlight as key light
```

---

### 🎵 物品C：耳机

#### CG 3-A　两只耳机连在同一根线上
> 景别：特写（耳机线 + 手 + 夜空）　氛围：同一首歌、同一个频率　**无脸** · 横版 `1536×1024`

中文：
```
特写。两根白色的有线耳机线从画面左右两侧分别延伸到中间，在中间缠在一起。
左边那只耳机被一只手握在手心里，右边那只悬空垂着，
就在一只耳朵旁边（只画到耳朵和一点头发，不画脸）。
背景是深蓝色的夜空，耳机的轮廓旁边有一颗星星在微微发亮。
白色的耳机线在暗光里格外醒目，像是两个世界之间唯一连着的那根线。
冷调深蓝，浅景深，画面简洁。
```
英文 tag 版：
```
close-up, two white wired earphone cables entering from the left and right edges,
tangled together in the middle, the left earbud held in the palm of a hand,
the right earbud hanging in the air beside an ear (only ear and a little hair visible, no face),
deep blue night sky background, a single star glowing faintly beside the earbud silhouette,
the white cable strikingly bright in the dim light,
cool deep blue tones, shallow depth of field, minimal composition
```

---

##### ⚠ 上面那版跑不出来 —— 用下面的重写版

原因不是描述不够细，是**上面那段物理上是错的**，模型只能瞎猜：

| 错在哪 | 后果 |
|---|---|
| 「两根线从左右延伸到中间」 | 一副耳机只有**一根**线，Y 形分叉。写成两根线对撞 → 画成一团乱麻 |
| 「悬空垂着」+「就在一只耳朵旁边」 | 自相矛盾：到底是悬空还是贴着耳朵 |
| 「只画耳朵和一点头发，不画脸」 | **最致命**。局部人体是所有图像模型的死穴，它只会给你整张脸，或者一个畸形肉块 |

重写的核心改动：**把耳朵整个删掉**，让线从画面右上角出画。
看不见的那个人反而更强 —— 「线通向画外」本身就是「她已经不在了」的视觉写法。
最难画的部分正好被绕开。

**主方案**（先跑这个）：
```
夜晚天台的特写镜头，画面里只有一只手、一根耳机线和夜空。没有人物，没有脸。

构图：一只摊开的手掌从画面左下方伸进来，掌心朝上，手指自然微微弯曲。
掌心里躺着一只白色的入耳式耳机，很小，线从耳机尾部垂下来。
这根白色的耳机线从掌心出发，向右上方延伸，中途有一个Y形分叉点
（一根线分成两股的那个小塑料接头），
然后其中一股继续往右上方走，最后从画面的右上角出画 ——
线的另一端在画面外面，看不见。

被拉着的那股线是绷紧的、有轻微的弧度，不是松垮地堆着。
背景是深蓝色的夜空和大片的星星，虚焦。
画面右下方有一小截生锈的铁栏杆，也是虚焦的，很暗。

光线：主要光源是远处城市灯火的暖黄色余光，从画面下方很微弱地打上来，
只照亮手的边缘和耳机线。白色的线在深蓝色的夜空里是画面里最亮的东西，
像一道细细的白光划过。星光在耳机附近有一颗稍微亮一点。

色调：冷调深蓝为主，只有手的边缘带一点暖黄。浅景深，只有手和耳机是清晰的。
构图极简，大片留给夜空。手要画对，五指自然，不要多指。
```

**主方案还不行就退到备选**（纯静物，完全没有人体，几乎不可能失败）：
```
夜晚天台的静物特写。画面里没有人。
一副白色入耳式耳机放在水泥地面上。线是自然松开的，
不是缠在一起的一团，而是舒展开来的 —— 从中间的Y形分叉点向两边分出两股，
两只耳机分别落在地上，彼此隔开大约一个手掌的距离，
朝着相反的方向，中间是一段空的地面。

水泥地面有细小的颗粒质感和一点夜露的湿痕。
背景往上是深蓝色的星空，虚焦。
远处城市灯火的暖黄色余光从画面一侧极微弱地照过来，
白色的耳机线在暗色的水泥地上格外醒目。

冷调深蓝，浅景深，构图极简，安静。不要出现人，不要出现手。
```
> 备选版其实更狠：**两只耳机朝着相反的方向，中间隔着一段空地面。**
> 分开的两端 —— 比原来那版更贴第二章末尾那句「那首歌我再也没有找到过」。

**追问话术**（同一个对话里接着说，比重跑稳）：

| 出了什么问题 | 追这一句 |
|---|---|
| 线画成两根、或一团乱麻 | 「只有一根耳机线，中间一个Y形分叉，其中一股从画面右上角出画。不要有第二根独立的线。」 |
| 冒出一张脸或一只耳朵 | 「画面里完全不要出现人的头部、脸、耳朵。只保留那只手。」 |
| 手画坏了、多指 | 「重画那只手：掌心朝上摊开，五根手指清楚可数，手指自然放松微弯。」 |
| 线太暗看不清 | 「把耳机线画得更亮更清楚，它应该是整个画面里最亮的东西，像一道白光划过深蓝色的夜空。」 |
| 背景太满、星星太碎 | 「背景简化，减少星星的数量，留大片干净的深蓝色夜空。」 |
| 画成了大耳罩 | 「是入耳式的小耳机，不是头戴式耳罩。」 |

英文 tag 版（重写版，同样无耳朵）：
```
night rooftop close-up, no people, no face, no ear,
an open palm entering from the lower left of the frame, facing up, fingers naturally curved,
a single small white in-ear earbud resting in the palm,
one white cable running from the palm toward the upper right,
passing a Y-shaped splitter, then continuing off the top-right edge of the frame,
the far end outside the picture, unseen,
the cable taut with a slight curve, not coiled or piled,
deep blue starry night sky in soft focus, a small section of rusted iron railing lower right, blurred,
faint warm amber glow from distant city lights rimming the hand and cable from below,
the white cable the brightest element in the frame like a thin streak of light,
cool deep blue tones, shallow depth of field, minimal composition, large empty sky,
anatomically correct hand, five fingers, no extra fingers
```

#### CG 3-B　她闭着眼靠在栏杆上听歌 ★挂参考图
> 景别：中景（她 + 栏杆 + 城市灯火）　氛围：温柔的、不用说话的　**有脸** · 横版 `1536×1024`
> （原定竖版，改横版 —— 左边缘要留出他的肩膀和手臂，还要装下身后那片城市光晕）

中文：
```
中景。夜晚的天台，她背靠在生锈的铁栏杆上，双手自然垂在身侧，
一只耳朵里塞着白色有线耳机，线垂下来。
她闭着眼睛，表情放松，嘴角带着一点几乎看不出来的弧度。
夜风把她的长发吹起来几缕。她穿浅灰色毛衣。
远处的城市灯火在她身后连成一片模糊的暖黄光晕。
画面左侧边缘可以看到另一个人的一小截肩膀和手臂 —— 他站在她旁边，
隔着大约一个肩膀的距离，不多也不少。
冷调深蓝，城市灯火做背光，人物有明显的轮廓光。
```
英文 tag 版：
```
1girl, medium shot, night rooftop, leaning back against a rusted iron railing,
hands hanging naturally at her sides, one white wired earbud in her ear, cable dangling,
eyes closed, relaxed, a barely perceptible curve at the corner of her mouth,
night wind lifting a few strands of her long silver hair, light grey sweater,
distant city lights as a blurred warm amber glow behind her,
at the left edge of the frame a sliver of another person's shoulder and arm,
standing about one shoulder-width away from her,
cool deep blue tones, city lights as backlight, strong rim lighting on the figure
```

---

## 五、第三章 · 裂缝 · 医院走廊

> **本章通用**：她脸色比之前白，嘴唇颜色淡到几乎和皮肤融在一起；**头发比之前更长**；
> 穿**宽大的病号服**；手背上有留置针的胶布。整体**降饱和**。
> 走廊是偏蓝的冷白炽灯，病房里偏暖 —— 这个冷暖对比是本章的关键。

### 📋 物品A：检查报告

#### CG 1-A　病床上的她 · 抬起头看你 ★挂参考图
> 景别：近景（她 + 病床 + 白炽灯）　氛围：「你来了」——那三个字包含了一切　**有脸** · 竖版 `1024×1536`

中文：
```
近景。病房里，她半躺在病床上，白色被子拉到胸口，长发散在枕头上。
脸色有些苍白，嘴唇的颜色淡得几乎和皮肤融在一起。
但她看到门口出现的人影时，嘴角动了一下 —— 是一个很轻的笑，不是灿烂的笑。
她穿宽大的病号服。
医院的白炽灯从画面外的上方照下来，在她脸上投下淡淡的阴影。
她的眼睛看着门的方向，瞳孔里映着走廊透进来的一点冷光。
整体降饱和，冷白偏一点淡蓝，病房里有一点暖意。
```
英文 tag 版：
```
1girl, close-up, hospital room, half lying in a white bed, blanket pulled up to her chest,
long silver hair spread across the pillow, pale face, lips so pale they nearly blend into her skin,
the corner of her mouth just moved — a very faint smile, not a bright one,
oversized hospital patient gown,
fluorescent light from above out of frame casting soft shadows on her face,
eyes looking toward the door, a hint of cold corridor light reflected in her pupils,
desaturated, cold white with pale blue, slight warmth inside the room
```

#### CG 1-B　主角低头看着检查报告
> 景别：侧面中景（他 + 报告 + 白墙裂缝）　氛围：那一行字，他假装不认识　**只有主角侧面** · 竖版 `1024×1536`

中文：
```
侧面中景，不要露出正脸。一个男生坐在病床旁边的椅子上，低着头，
手里翻开着一个文件夹。他穿深色外套，短发。
医院的白炽冷光从头顶照下来。
他的指尖停在纸页的某一处 —— 那里有一行字，被灯光照得格外清楚。
他的目光落在那一行字上，整个人像是定住了，肩膀没有动。
背景是病房的白墙，墙上有一道很浅的裂缝，
从天花板的角落一直延伸到窗框附近。
窗外的天空是深色的，没有星星。
降饱和的冷白色调。
```
> 墙上那道裂缝是本章的题眼（章节名就叫「裂缝」），别省。

英文 tag 版：
```
1boy, side view medium shot, no frontal face, sitting on a chair beside a hospital bed,
head lowered, an open document folder in his hands, dark coat, short hair,
cold fluorescent light from directly above,
his fingertip stopped at a spot on the page where one line is lit unusually clearly,
his gaze fixed on that line, completely still, shoulders motionless,
white hospital wall behind him with a faint crack running from the ceiling corner
down toward the window frame,
dark starless sky outside the window, desaturated cold white tones
```

---

### 📱 物品B：手机屏幕

#### CG 2-A　手机屏幕 · 17 个未接来电
> 景别：特写（手机屏幕 + 未接来电 + 悬停的拇指）　氛围：17 次震动，三年没有点开　**无脸** · 方图 `1024×1024`
> （唯一一张用方图 —— 手机是竖屏 UI，塞进 2:3 会上下空一大截，方图最稳）

中文：
```
特写。一只手握着手机，屏幕亮着，显示通话记录页面。
屏幕上是一整列红色标记的未接来电，同一个联系人的名字重复出现了很多次，
排满了整个屏幕，时间从五天前的下午一直排到两天前的晚上。
屏幕最底部是一条语音留言，时长 23 秒，旁边有一个「未播放」的蓝色圆点。
主角的拇指悬在屏幕上方，指尖离屏幕大约一指宽 —— 悬着，没有按下去。
背景是虚化的医院病房，很暗。
屏幕的冷光是画面唯一的主光源，照亮拇指和手指的边缘。
降饱和的蓝色调。界面上的字不需要可读。
```
> 「17 通未接 + 23 秒未播放的语音」是全篇最重的伏笔之一，**数字和时长要出现**。模型画数字容易错，出图后自己改。

英文 tag 版：
```
close-up, a hand holding a phone, screen on, call history page displayed,
a full column of red-marked missed calls, the same contact name repeated many times
filling the whole screen, timestamps spanning several days,
at the bottom a voicemail entry with a duration and an unplayed blue dot,
the thumb hovering about one inch above the screen, not pressing,
blurred dark hospital room background,
the cold screen glow as the only key light, rimming the thumb and fingers,
desaturated blue tones, UI text need not be legible
```

#### CG 2-B　她睡着了 · 主角坐在床边 ★挂参考图
> 景别：近景（睡着的她 + 他 + 熄屏的手机）　氛围：坐在她旁边，但 17 通电话已经打了　**有脸（睡颜）** · 横版 `1536×1024`

中文：
```
近景。病房里，她睡着了，侧着脸朝向镜头，长发散在枕头上，呼吸很浅。
一只手从被子里伸出来放在床沿上 —— 手背上贴着留置针头的胶布。
她穿宽大的病号服，脸色苍白。
一个男生坐在床边的椅子上，低着头，不要露出正脸，穿深色外套。
他手里握着手机，手机屏幕已经熄灭了，像一面黑色的镜子。
他没有在看她 —— 目光落在自己膝盖上的某一点。
病房的灯光在他脸的侧面投下冷白色的阴影。
两个人在同一个画面里，但没有在看对方。
降饱和，冷白偏蓝，只有床头一点暖光。
```
英文 tag 版：
```
close-up, hospital room, 1girl asleep, face turned toward the viewer, long silver hair on the pillow,
shallow breathing, one hand out from under the blanket resting on the bed edge,
medical tape and IV cannula on the back of that hand, oversized patient gown, pale face,
1boy sitting on a chair at the bedside, head lowered, no frontal face, dark coat,
holding a phone with a dark screen like a black mirror,
he is not looking at her, his gaze fixed on a point on his own knee,
cold white light casting shadows on the side of his face,
both in frame but neither looking at the other,
desaturated cold blue white, one small warm bedside light
```

---

### 💊 物品C：未开封的药

#### CG 3-A　床头柜上的白色药瓶
> 景别：特写（药瓶 + 水杯 + 病床）　氛围：一个过期的、你没有拆开过的证据　**无脸** · 横版 `1536×1024`

中文：
```
特写。一个白色的小药瓶立在病房的床头柜上，大约拇指的高度，很小很轻的样子。
标签朝上，上面印着名字、药名、用法用量，还有一行有效日期。
瓶盖是完整的，封膜没有拆开过。
清晨的光照在标签上，字迹清晰。
旁边是一杯半满的水，玻璃杯壁上残留着淡淡的水痕。
背景是虚化的白色床单和病床的金属栏杆。
阴天早晨那种灰白的光，降饱和。标签上的字不需要可读。
```
英文 tag 版：
```
close-up, a small white pill bottle standing on a hospital bedside table, about a thumb tall,
label facing up with printed name, drug name, dosage and an expiry date line,
cap intact, seal unopened,
early morning light on the label,
a half-full glass of water beside it with faint water marks on the inside of the glass,
blurred white bedsheets and metal bed railing in the background,
overcast grey-white morning light, desaturated, label text need not be legible
```

#### CG 3-B　主角把药瓶放进口袋 ★挂参考图
> 景别：中景（他站着 + 她坐着 + 晨光）　氛围：「你留着吧」——轻到像一句告别　**有脸** · 竖版 `1024×1536`

中文：
```
中景。病房里，一个男生站在病床旁边，低着头，不要露出正脸，穿深色外套。
他的左手刚从外套口袋里抽出来 —— 药瓶已经放进去了。
右手垂在身侧，指节微微泛白。
她坐在床上，仰着头看他。她穿宽大的病号服，长发散着，脸色苍白。
她的眼神很平静，嘴角有一点微不可见的弧度 —— 是一种不想让他太担心的表情。
她伸出一只手 —— 是那只没有打针的手 —— 轻轻碰了一下他垂下来的小臂。
只是碰了一下，没有握住。
晨光从窗户照进来，是阴天那种灰白色的光。
降饱和，灰白偏一点冷蓝。
```
> 「她伸手碰他小臂、但没有握住」是这张的核心。模型很容易画成牵手，出图后如果牵上了，追一句"只是指尖轻碰他的手臂，不要握住"。

英文 tag 版：
```
medium shot, hospital room, 1boy standing beside the bed, head lowered, no frontal face, dark coat,
his left hand just withdrawn from his coat pocket, the pill bottle now inside it,
right hand at his side, knuckles slightly pale,
1girl sitting up in bed looking up at him, oversized patient gown, long silver hair loose, pale face,
calm eyes, an almost invisible curve at her mouth — the look of someone not wanting him to worry,
she reaches out with the hand without the IV and lightly touches his hanging forearm,
just a touch, not holding on,
overcast grey-white morning light from the window,
desaturated, grey white with a hint of cold blue
```

---

## 六、第四章 · 缺席 · 空天文馆

> **本章通用**：她**完全不出现**。整章只有物品、空座位、和主角的背影/手。
> 场景是**城南天文馆的放映厅**，冬天下午，**深蓝色穹顶投影星空**，座位一排排延伸到黑暗里，
> 整个厅是空的。这一章的核心是**空**。不要给这一章加人。

### 🎫 物品A：两张门票

#### CG 1-A　两张票并排放着
> 景别：俯拍特写（两张票 + 座椅绒布 + 星光）　氛围：两张票，一个人　**无脸** · 横版 `1536×1024`

中文：
```
俯拍特写。两张浅蓝色的天文馆票根并排放在深蓝色绒布座椅上，
一张在左，一张在右，间距大约是一个人肩宽的距离。
左边那张边角平整，右边那张微微卷起一角。
票面上印着场次和日期，被放映厅穹顶的暗光映着，字很小。
座椅的绒布纹理在微光中呈现细密的网格状。
画面下方的座椅边缘垂着一小截深色外套的衣角。
深蓝色调，头顶穹顶投影的星光是唯一光源，很暗。票面文字不需要可读。
```
英文 tag 版：
```
overhead close-up, two pale blue planetarium ticket stubs placed side by side on a deep blue
velvet theater seat, one on the left one on the right, about a shoulder-width apart,
the left one flat, the right one with a slightly curled corner,
small printed showtime and date on them, lit only by dim projected starlight,
fine grid texture of the velvet visible in the low light,
a corner of a dark coat hanging over the seat edge at the bottom of the frame,
deep blue tones, projected dome starlight as the only light source, very dim, no face
```

---

##### ⚠ 上面那版出成了写实照片 —— 用下面的重写版

跑出来的结果是**写实照片/3D 渲染**，跟另外 23 张 galgame CG 完全不是同一个媒介。
根因在提示词，不在操作：

| 问题 | 原因 |
|---|---|
| **风格跑偏成照片**（最严重） | 我那段通篇是**摄影语言** —— 「俯拍特写」「绒布纹理」「浅景深」「微光映着」。模型顺着这些词往照片方向走，模板里那句「galgame 风格」被整段摄影术语压掉了 |
| **座椅画成了椅背，不是坐垫** | 只写了「深蓝色绒布座椅」，没说是**人坐的那个水平面** |
| **左上角冒出弧形窗框，像飞机舷窗** | 这张我**根本没写背景该有什么**，只写了「穹顶的暗光」，模型就自己编了个窗户 |
| **右下角一大团灰色看不出是什么** | 「垂着一小截外套衣角」写得太含糊，它画成占了 1/4 画面 |

> 票面上印星图是模型自己加的，这个好，重写版里保留了。

**重写版**（风格声明放最前面，且明确否掉照片）：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，不是照片，不是3D渲染，不是CG建模。

画面内容：天文馆放映厅里，一个双人座的**坐垫平面**（人屁股坐的那个水平面，
不是椅背），从斜上方俯视看下去。坐垫是深蓝色的布面。

坐垫上并排放着两张浅蓝色的天文馆票根，一张在左一张在右，
间距大约一个人肩宽那么远，中间是空的坐垫。
左边那张平整地躺着，右边那张微微卷起一个角。
票面上印着简单的星图圆盘图案和几行小字。

背景：画面上方和左右两侧是放映厅内部的黑暗，
能看到前排座椅模糊的深色剪影，一排排往画面深处退去。
背景**不要有窗户，不要有弧形的窗框，不要有舷窗**。
画面右上角远处能看到一小块深蓝色的穹顶，上面有投影的星点。

光线：唯一的光来自头顶穹顶的投影星光，非常暗，
淡蓝色的微光落在两张票上，票是画面里最亮的东西。座椅大部分在暗处。

色调：深蓝色为主，明暗对比强，大面积的暗部。构图简洁。
不要出现人，不要出现手。票面上的字不需要可读。
```

**追问话术**（同一个对话里接着说）：

| 出了什么问题 | 追这一句 |
|---|---|
| 还是像照片/3D | 「重画成手绘动漫插画风格，平面色块，看得出笔触和线稿，完全不要照片质感和真实材质反射。」 |
| 画的是椅背不是坐垫 | 「视角要看到的是座椅的坐垫，就是人坐下去的那个水平面，票是平放在坐垫上的。不要画椅背。」 |
| 又冒出窗户/舷窗 | 「删掉画面里所有窗户和弧形框，背景只有放映厅内部的黑暗和前排座椅的剪影。」 |
| 右下角那团东西 | 「删掉画面下方那件外套，坐垫上只有两张票，别的什么都没有。」 |
| 两张票挨太近 | 「两张票之间要隔开一个人肩宽的距离，中间留出明显的空坐垫。」 |

> 这张的意义全在**两张票中间那段空着的坐垫**上 —— 他买了两张票，只有一个人来。
> 如果两张票被画得挨在一起，这张就白跑了，一定要追那句。

英文 tag 版（重写版）：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, NOT a photograph, NOT 3d render,
planetarium auditorium interior, looking down at an angle onto the horizontal SEAT CUSHION
of a two-person theater seat (the surface people sit on, not the backrest), dark blue fabric,
two pale blue planetarium ticket stubs lying side by side on the cushion,
about a shoulder-width apart with empty cushion between them,
the left one flat, the right one with one corner slightly curled,
simple star chart disc pattern and small print on the tickets,
background: dark auditorium interior, blurred dark silhouettes of front-row seats receding,
NO windows, NO curved window frames, NO portholes,
a small patch of deep blue dome with projected stars at the upper right,
only light source is dim projected starlight, pale blue glow on the tickets,
tickets are the brightest thing in frame, most of the seat in shadow,
deep blue palette, strong contrast, large dark areas, simple composition,
no people, no hands
```

#### CG 1-B　主角坐在双人座上仰头看星
> 景别：背影中景（他 + 空座位 + 穹顶星空）　氛围：空着的座位　**只有主角背影** · 横版 `1536×1024`
> （原定竖版，改横版 —— 「他」和「空着的那个座位」必须并排出现在同一画面里，这张的意义全在那个空位上）

中文：
```
背影中景，不要露出脸。一个男生坐在天文馆放映厅的双人座正中间，
微微仰着头，看着上方的穹顶。他穿深色外套，短发。
穹顶上是投影出来的星空 —— 一颗很亮的蓝白色星在偏东南的位置闪着，
淡蓝色的光落在他的肩膀上。
他旁边的座位是空的，座椅上放着一张浅蓝色的票根。
整个放映厅空空荡荡，座位一排一排延伸到黑暗里，没有别人。
他没有靠椅背，身体微微前倾 —— 像是还在等旁边的人坐下。
深蓝色调，穹顶星光做唯一光源，人物是剪影，肩线有一点蓝白色的边光。
```
英文 tag 版：
```
1boy, back view medium shot, no face, sitting in the exact middle of a two-person seat
in a planetarium theater, head tilted slightly up toward the dome, dark coat, short hair,
projected starfield on the dome above, one bright blue-white star prominent,
pale blue light falling on his shoulders,
the seat beside him empty with a single pale blue ticket stub on it,
the whole auditorium empty, rows of seats receding into darkness, nobody else,
not leaning back, torso tilted slightly forward as if still waiting for someone to sit down,
deep blue tones, dome starlight as the only light, figure mostly silhouette with blue-white rim light
```

---

### 💌 物品B：没寄出的信

#### CG 2-A　信纸特写 · 「对不起」
> 景别：微距特写（信纸 + 字迹 + 星光）　氛围：写了很久，寄不出去　**无脸** · 横版 `1536×1024`

中文：
```
微距特写。一张信纸被摊开，借着穹顶投下来的暗光可以看到上面的字。
纸已经有些软了，折痕很深，被折过很多次。
最上面**没有称呼**，直接就是第一行字 —— 手写，笔迹比一般用力，像是压着笔写的。
第二行还有一行字。第三行只有三个点。
然后就是一大片空白 —— 后面什么都没有写。
纸的边缘有细小的褶皱。
背景是虚化的深蓝色穹顶和遥远的投影星光。
深蓝色调，很暗，只有一点点光落在纸面上。字迹看得出是手写但不需要可读。
```
> 「**没有称呼**」和「**第三行只有三个点然后一片空白**」是这张的全部意义 —— 他写不下去了。构图上要让那片空白占足够大的面积。

英文 tag 版：
```
macro close-up, a letter unfolded, lit only by dim projected starlight,
the paper soft and worn with deep fold creases from being folded many times,
NO salutation at the top — the first line starts immediately, handwritten,
pressed harder than normal as if written with force,
a second line, then a third line containing only three dots,
then a large expanse of blank paper — nothing more written,
fine wrinkles along the paper edge,
blurred deep blue dome and distant projected stars in the background,
deep blue tones, very dim, only a little light on the paper, handwriting need not be legible
```

#### CG 2-B　信放在膝盖上
> 景别：第一人称近景（信 + 票根 + 膝盖）　氛围：读了一半，又合上了　**无脸** · 横版 `1536×1024`

中文：
```
第一人称近景。视线往下看自己的膝盖 —— 深色长裤的膝盖上摊着一封信，
借着穹顶的微光可以看到开头的几行手写字。
两只手放在信纸的两侧，没有拿起来，只是压着。
膝盖上还放着一张浅蓝色的票根，日期隐约可见。
旁边有一部熄屏的手机，黑色的屏幕上倒映着穹顶的星空 —— 
星星映在一块黑玻璃上。
整个画面笼罩在深蓝与灰色之间，很暗。字迹不需要可读。
```
> 「星空倒映在熄掉的手机屏幕上」是这张最好的一笔（第三章那部没点开的手机又出现了一次）。别漏。

英文 tag 版：
```
first person close-up, looking down at one's own knees, a letter spread open on dark trousers,
the first few handwritten lines visible in the dim light,
both hands resting on either side of the paper, not lifting it, just holding it down,
a pale blue ticket stub also on the knee, date faintly visible,
beside it a phone with a dark screen, the projected starfield of the dome reflected in the black glass,
stars mirrored on a piece of dark glass,
the whole frame between deep blue and grey, very dim, handwriting need not be legible
```

---

### ⭐ 物品C：拆开的星星（隐藏）

> **这两张是全篇的揭示点。** 观众到这里才知道：那颗折纸星星是**她**折的，
> 里面那张票根的日期是**她离开的前一天**。两张里都**不要出现任何人的脸**。

#### CG 3-A　地板上的折纸星星
> 景别：低角度近景（星星 + 座椅底座 + 应急灯光）　氛围：谁放在那里的，不知道　**无脸** · 横版 `1536×1024`

中文：
```
低角度近景，镜头几乎贴着地面。深灰色的地板和深蓝色的座椅金属底座之间，
躺着一小团浅色的折纸星星。很小，五个角，叠得很规整。
纸面已经微微发黄，边角有些褪色发白。
只有一小束光落在它身上 —— 是从放映厅出口应急灯来的，绿白色的、很微弱的光，
恰好照亮星星的一侧，另一侧还在暗处。
背景是一排排座椅底座延伸进去的黑暗，虚焦。
整体很暗，深灰与深蓝，只有那一小束应急灯光。
```
英文 tag 版：
```
low angle close-up, camera almost at floor level, between dark grey flooring and the deep blue
metal base of a theater seat lies a small pale origami star, five points, neatly folded,
the paper slightly yellowed, corners faded to off-white,
a single narrow beam of light falls on it — faint greenish-white light from an exit emergency sign —
lighting one side of the star while the other stays in shadow,
rows of seat bases receding into darkness in the blurred background,
very dim overall, dark grey and deep blue, only that one small beam, no face
```

#### CG 3-B　手心摊开的纸
> 景别：特写（手掌 + 摊开的票根 + 字迹）　氛围：两年前的字迹　**无脸** · 横版 `1536×1024`
> **★ 全篇最重要的一张。建议让模型留白，字自己加。**

中文：
```
特写。一只手掌心朝上摊开，掌心里放着一张被展平的票根。
票根是浅蓝色的，被折痕分成许多个规则的小方块 —— 看得出来它刚刚是一颗折纸星星。
边角已经褪成灰白，折痕很深，有些折痕的凸起处微微发亮。
票根的空白处有一行手写的圆珠笔字。左下角印着一个日期，字体很小。
背景是虚焦的放映厅座椅和已经暗下来的深蓝色穹顶。
深蓝与灰的色调，光很少，只有一点微光落在掌心和纸面上。
手要画对，五指自然摊开。画面里不要出现脸。
```
> **两点必须做到**：① 纸上要看得出**规则的方格折痕** —— 它刚刚还是一颗星星，这是视觉证据；
> ② 字和日期建议**让它留白或画成糊的**，出图后你自己用画图加上
> 「如果你看到这个，说明你已经准备好了」和那个日期 —— 这是全篇的落点，不能交给模型碰运气。

英文 tag 版：
```
close-up, an open palm facing up, a flattened ticket stub lying in it,
the stub pale blue, divided by fold creases into many regular small squares —
clearly it was an origami star a moment ago,
corners faded to grey-white, creases deep, some raised fold ridges catching a faint sheen,
a line of handwritten ballpoint text in the blank area, a small printed date in the lower left corner,
blurred theater seats and the darkened deep blue dome in the background,
deep blue and grey tones, very little light, only a faint glow on the palm and paper,
anatomically correct hand, five fingers naturally spread, no face in frame
```

---

## 七、排除项

GPT Image 2 **没有独立的负面提示词框**，下面这段要写成句子接在指令末尾（第二节模板里已经带了）：

**有她的那 8 张**：
```
只画她一个人。不要双马尾、丸子头、短发，不要改发色和瞳色，
不要红眼睛绿眼睛，不要张嘴大笑或夸张表情，不要胸部夸张或露肤过多，
不要文字、水印、logo，不要 3D 渲染、写实照片、油画或草稿感。
不要多余的手指，手要画对。
```

**没有她的那 16 张**：
```
画面里不要出现人的脸。不要文字水印，不要 3D 渲染或写实照片风格，
手要画对不要多指，不要画成插画封面或海报排版。
```

换到别的工具时用这个填负面框：

```
lowres, bad anatomy, bad hands, extra fingers, missing fingers, deformed face,
asymmetric eyes, cross-eyed, blurry, jpeg artifacts, watermark, signature, text, logo,
multiple girls, two people, twintails, ponytail, hair buns, short hair, blonde hair, pink hair,
red eyes, green eyes, huge breasts, exposed skin, revealing clothes, cleavage,
open mouth, wide smile, laughing, exaggerated expression,
3d render, realistic photo, oil painting, sketch, unfinished
```

> `hair buns / 丸子头` 必须排除 —— 她是纯长直发，模型很容易顺手给她扎起来。

---

## 八、如果要转成控制台 ASCII

如果这 24 张最终要塞进 `源.cpp` 当字符画（约 100×19 字符、10 级灰度），指令里再加一句：

```
高对比度，背景尽量简单干净，主体轮廓大而清晰，
用强轮廓光把主体和背景分开，减少细碎的细节。
```

英文：
```
high contrast, simple uncluttered background, large clear silhouette,
strong rim light separating subject from background, minimal fine detail
```

要注意的是：**ASCII 只有大块明暗关系能存活**，睫毛、发丝、瞳孔高光、票根上的字全部会消失。所以

- 主体必须占画面 **1/3 以上**
- 比例改成**横版**（控制台是 100×19，极宽），竖版 2:3 转过去会被压扁
- 「电影感构图」「浅景深」这时候要**去掉**
- 逆光/轮廓光远好于正面平光 —— 这一点第二章（星光背光）和第四章（穹顶星光）天然占优，第一章的暖黄平光最吃亏

**本手册里最不适合转 ASCII 的**：4-2A 信纸、4-3B 手心票根、3-2A 手机屏幕 —— 它们全靠"纸上的字"传达信息，转成字符画之后字必然消失，整张就没意义了。这三张建议走弹窗 PNG 路线（`system("start xxx.png")`），或者干脆在控制台里用文字呈现。

---

## 九、注意

参考图是 Key / Visual Arts《Summer Pockets》的鸣濑白羽，Na-Ga 原画，是有版权的商业角色设计。
提示词里**没有**写角色名和作品名，只写外观特征 —— 出来的是"这一类长相"，不是那个具体角色。
GPT Image 2 也不容易因为识别到商业角色而拒绝生成。
你如果直接写 `鸣濑白羽` / `Summer Pockets`，相似度更高但大概率被拒，而且交课设不好看，自己权衡。
