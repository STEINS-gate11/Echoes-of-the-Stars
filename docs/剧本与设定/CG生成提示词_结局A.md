
# 《星空回响》CG 生成提示词手册 · 结局A · 18 张

> 配套 `CG生成提示词.md`（主手册 24 张）与 `CG生成提示词_序幕与第五层.md`（12 张）。
> 本册只管**结局 A**，不含 B / C —— 已定案：**只做 A**。
> 对应源码：`源.cpp` `play_jieju_A()` 2657–2857（173 句独白）+ `play_A_houji()` 2397–2656（129 句后记）。
> 每张图下面都标了**锚点行号**，写 Ren'Py 脚本时按行号插图，不要凭记忆。

---

## 零、先看这张表：18 张里只有 4 张需要她的脸

| # | 编号 | 锚点行 | 画面 | 脸 | 比例 |
|---|---|---|---|---|---|
| 1 | **A-1** | 2677–2681 | 台灯下拆开折纸星星 | 无 | 横 `1536×1024` |
| 2 | **A-2** | 2689–2698 | 窗前抬头看织女星 | 无（背影） | 横 |
| 3 | **A-3** | 2702–2706 | 深夜空街 · 远处天文台剪影 | 无 | 横 |
| 4 | **A-4** | 2711–2720 | 推开天台的门 | 无 | 横 |
| 5 | **★★★ A-5** | 2731–2734 | 蹲在底座旁 · 手电照到缝隙 | 无 | 横 |
| 6 | **A-6** | 2738–2744 | 摊开的信 · 她的字 | 无 | 横 |
| 7 | **★★★ A-7** | 2814–2817 | 额头靠在望远镜底座上（读完信） | 无 | 横 |
| 8 | **★★ A-8** | 2820 | 折纸星星放在三脚架下 | 无 | 横 |
| 9 | **★★ A-9** | 2821 | 走下楼梯 · 泪痕还没干 | 无（背影） | 横 |
| 10 | A-10（可省） | 2853 | 一道流星 | 无 | 横 |
| 11 | **★★★ S-1** | 2749 | 三年前 · 她在底座旁写这封信 | **有** | 横 |
| 12 | **S-2** | 2753 | 更早 · 两人并肩 · 一袋膨化食品 | **有** | 横 |
| 13 | **★★ S-3** | 2788 | 她指着西南方的天空说「我是 Vega」 | **有** | 横 |
| 14 | **★★ S-4** | 2767 | 病房 · 她说那句谎 | **有** | 横 |
| 15 | **★★★ H-1** | 2412–2415 | 晨光 · 纸箱最底层风干的凤蝶 | 无 | 横 |
| 16 | **★★ H-2** | 2463–2465 | 掌心托着近乎透明的蝴蝶 | 无 | 横 |
| 17 | H-3 | 2495–2497 | 深夜 · 电脑屏幕的冷光 | 无（背影） | 横 |
| 18 | **★★ H-4** | 2643–2644 | 秋天的湖泊 · 十二只白鹭鸶 | 无 | 横 |

**全部 `1536×1024` 横版，不许出竖版。** 主手册那 8 张竖版是"一次弹一张 PNG"时代的遗物；Ren'Py 跑 1920×1080，竖图左右各留 600px 黑边。这一批不能再制造第二种比例。

**不配图的三处**（配了反而弱，纯黑 + 停顿最狠）：
- `2533`「那个她离世了。」
- `2776`「啊啊……啊啊啊啊……」
- `2784`「谢谢你。」

---

## 一、必须成组生成，不能一张一张单独跑

分开生成 = 一定不像。**同一次对话里，按下面的顺序连着出**：

| 组 | 顺序 | 为什么必须绑在一起 |
|---|---|---|
| **第 1 组 ★★★** | `S-1` → `A-5` → `A-7` → `A-8` | **同一个位置、同一个姿势、四个时间。** 见下面第二节 |
| **第 2 组** | `S-4` → `S-1` | 隔一天的连续两张，同一套病号服 + 留置针（`S-1` 已在第 1 组出过，这里只是补锁人物一致性；若第 1 组先跑，就改成 `S-1` → `S-4`） |
| **第 3 组** | `S-2` → `S-3` | 同一晚的两个机位，同一套衣服 |
| **第 4 组** | `A-5` → `H-1` | `H-1` 要蹭到 `A-5`「光打进容器最底部」的构图记忆 |
| **第 5 组** | `H-1` → `H-2` | 同一只蝴蝶，同一个早上 |
| 单张 | `A-1` `A-2` `A-3` `A-4` `A-6` `A-9` `A-10` `H-3` `H-4` | 随便 |

出图后在同一对话里直接说「机位再低一点」「手电光锥收窄」，比重跑稳。

---

## 二、★★★ 四张同机位：结局 A 的结构核心

`S-1` / `A-5` / `A-7` / `A-8` 是**同一个位置（望远镜底座旁的水泥地）、同一个姿势（蹲/坐下去）、四个时间**：

| | 谁 | 干什么 | 时间 | 光 | 地面 |
|---|---|---|---|---|---|
| **S-1** | 她 | **写**这封信 | 三年前 · 雨后 · 白昼将尽 | 阴天余光，无方向性 | 湿的深灰，有积水 |
| **A-5** | 他 | **找到**这封信 | 今夜 · 深夜 | 手电光锥，硬边 | 干的浅灰，积灰 |
| **A-7** | 他 | **额头靠上去**（读完） | 今夜 · 紧接着 | 手电掉在地上，横着打光，没照到他 | 干的浅灰 + 几滴刚落的水痕 |
| **A-8** | 他 | **放下**折纸星星 | 今夜稍晚 | 手电已收，只有星光 | 干的浅灰 |

**四张的机位、焦距、构图必须严格一致。** 望远镜三脚架在画面中的位置、大小、那条歪了的腿的角度，四张里完全相同。只换：人、姿势、光、季节、地面湿度。

`A-7` 那几滴水痕，就是 `S-1` 里满地积水在三年后剩下的量 —— 这个对位不用说，玩家自己会撞上。

做出来玩家不需要任何一行提示，会自己发现。**这一组比什么都重要，如果只做四张，就做这四张。**

技术写法：跑完 `S-1` 之后，在同一对话里说
> 「保持完全相同的机位、焦距和构图，望远镜和三脚架位置不变。现在把画面里的人换成……，时间改成深夜，光源改成手电筒。」

接着 `A-7`、`A-8` 继续在同一对话里追：
> 「机位、焦距、构图、望远镜位置全部不变。人不动位置，改成额头靠在底座上；手电筒改成掉在地上、光横着打在地面、不照到人。」
> 「机位构图全部不变。这次画面里没有人、没有手，只在三脚架正中的地面上放一颗浅蓝色折纸星星，手电收掉，只留星光。」

---

## 三、她的四张 · 人设与服装

参考图（和主手册同一套，不要换）：
- 全身 `E:\《星空回响》\CG参考\ref_full.png`（760×1610）
- 脸 `E:\《星空回响》\CG参考\ref_face.png`（520×580）

锁死设定（照抄主手册第一节）：**银白带极淡薰衣草紫的过膝直发，眼尾略下垂，浅蓝偏紫的瞳色，尖下巴，瓷白皮肤，155cm。**

服装按时间线：

| 编号 | 时间 | 穿什么 |
|---|---|---|
| S-2 / S-3 | 第二章 · 天冷的某个夜晚 | 米白毛衣 + 细银链（第一章款） |
| **S-4** | 第三章 · 病房 · 说谎那天 | 病号服 + 手背留置针 |
| **S-1** | **说谎的第二天** · 从病房跑出来 | 病号服 + 外面胡乱套着**藏青色外套**（大一号，明显不是她的）+ 留置针**还没拆** |

### ★★ 藏青色外套的来历（已解决，别再当成错误）

主手册的修订记录写着「编了一件正文里不存在的『藏青色外套』当伏笔……这些错误已全部修掉」。
**这条记录作废。** 2026-08-10 改掉 `源.cpp:2749` 的时间线之后（信从"住院前一周"改成"从医院跑出来的那天"），这件外套拿到了来历：

> **它是他的。那天她从病房跑出来，穿走了。`源.cpp:2663` 那张模糊照片里"披在肩上的藏青色外套"，就是这一件。**

所以 `S-1` 里必须有它，而且必须**明显大一号、不合身**。这不是穿搭，这是证据。

### 回忆化处理（四张统一）

四张全部：**偏暖、略微褪色的色调，像一段被反复回想过的记忆** ——
但仍然是动漫赛璐璐上色，**不要做成旧照片质感**。
"今夜"那一批（A-x）是冷蓝夜景。两批必须**一眼分得开**，玩家不需要看字幕就知道这是回忆。

---

## 四、GPT Image 2 模板

### ★ 先记住这条：风格声明必须放最前面，而且必须显式否掉照片

主手册 `4-1A` 就是反面教材（见主手册 780 行）——那段通篇摄影语言，
开头那句「galgame 风格」被整段摄影术语压掉，跑出来变成写实照片，整张重做。
所以：**「电影感构图」「浅景深」「精细光影」这类摄影词一个都不要写。**
画面里要表达"背景模糊"，就说「背景用大面积色块简化处理」，不要说「浅景深」。

### 有脸的 4 张（S-1 ~ S-4），用这个

新开一个对话（不要在跑过别的角色的对话里接着跑，上下文会污染脸），
上传 `ref_full.png`，然后：

```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、平面化色块、精致的眼睛。不是照片，不是3D渲染，不是写实风格。


整张图用偏暖的、略微褪色的色调，像一段被反复回想过的记忆 ——
但仍然是动漫赛璐璐上色，不是做旧照片。
只画她一个人。横版 3:2。
不要双马尾、丸子头、短发，不要改发色瞳色，不要张嘴大笑或夸张表情，
不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
```

「保持这张脸不变」这句和挂参考图，**两个都不能省**（没有 `--cref`，一致性全靠这两样）。

### 无脸的 14 张，不用挂图，直接说

```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：

【画面描述】

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```

### ⚠ 出图后如果还是像照片，同一对话里追这句

> 「重画成手绘动漫插画风格，平面色块，看得出笔触和线稿，完全不要照片质感和真实材质反射。」

### ⚠ 手写中文一定糊

`A-1`（纸上一行字）、`A-6`（整封信）、`S-1`（她正在写的字）三张画面里有字，AI 写中文必出乱码。两种办法：

1. 指令里写「字迹看得出是手写但不需要可读」，接受它糊过去；
2. **让它在那块留白，出图后自己用画图/PS 把字加上去。**

**`A-6` 必须走第二种。** 她的信是全作最关键的文字，交给 AI 写中文等于毁掉它。
`A-1` 也建议走第二种，要填的就一句：**「如果你看到这个,说明你已经准备好了。」**（`源.cpp:2680`）

---

## 五、正文 10 张

### CG A-1　台灯下拆开折纸星星
> 锚点 `2677–2681`　景别：特写（手 + 摊平的纸 + 台灯）　氛围：三年之后终于动手　**无脸** · 横版 `1536×1024`

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
深夜书房，特写。深棕色木桌，一盏钨丝台灯从画面左上斜照下来，光偏黄，
在桌面上落下一小片边缘柔和的暖光，像倒了一小滩温水。
桌面正中是一张刚被展开摊平的浅蓝色薄纸，纸上有很多道深刻的折痕，
折痕交错成放射状，纸的纤维已经软化、微微起毛，边缘有一点点卷。
纸的正中央留出一片空白（后期手动加字）。
一双手从画面下方入镜，指尖还停在纸的两个角上，刚刚把最后一层展开，没有离开。
背景是大面积的深色块，只有台灯的光域是亮的。暖黄色调，明暗对比清楚。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
close-up, dark study at night, warm tungsten desk lamp light from upper left pooling on a dark
brown wooden desk, a pale blue thin sheet of paper freshly unfolded flat at the center,
covered with deep radial fold creases, paper fibers softened and slightly fuzzy, edges curled,
blank space at the center of the paper, two hands entering from the bottom, fingertips still
holding two corners of the paper, large dark color-block background, warm amber tones, clear light-shadow contrast, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-2　窗前抬头看织女星
> 锚点 `2689–2698`　景别：中景（背影 + 窗 + 星空）　氛围：想笑给她看　**无脸（背影）** · 横版

中文：
![alt text](image.png)
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
medium shot from behind, a young man standing at a window at night, back to camera, head tilted
slightly up, only shoulder and head silhouette rimmed by light from outside, old wooden window
frame with one pane left slightly ajar, late summer night sky, a small warm convenience store
light across the street below, one distinctly bright white star in the upper southwest with fine
cross-shaped diffraction spikes, unlit interior, deep blue to near black foreground,
cool blue tones, silhouette, strong light-shadow contrast, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-3　深夜空街 · 远处天文台剪影
> 锚点 `2702–2706`　景别：大远景　氛围：两个月后，出门了　**无脸** · 横版

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
大远景，深夜的街道。空无一人，柏油路面还带着一点湿气，反着路灯的光。
街道向画面深处延伸，两侧是有年头的居民楼，只有零星几个窗还亮着。
最近的一盏路灯是坏的，灯罩黑着；后面几盏是暖黄的，一盏一盏往远处小下去。
街道尽头的坡上，有一栋旧建筑的剪影，顶上是一个半球形的圆顶，没有亮灯，
在深蓝的夜空里只是一个更暗的形状。
天空是八月中旬的夜空，星比城市里常见的要多。
冷蓝色调，只有路灯是暖的，大面积的暗色块，空旷。画面里不要有人。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme wide shot, deserted street at deep night, asphalt slightly damp reflecting streetlights,
street receding into the distance, aged apartment blocks on both sides with a few lit windows,
nearest streetlight broken and dark, further ones warm amber diminishing into the distance,
on the hill at the end of the street the silhouette of an old building with an unlit hemispherical
dome, darker shape against deep blue sky, mid-August starry sky, cool blue tones with warm
streetlights only, large dark areas, vast and empty, no people,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-4　推开天台的门
> 锚点 `2711–2720`　景别：门框 POV　氛围：天空豁然打开　**无脸** · 横版

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
第一人称视角，从一扇刚被推开的铁门里往外看。
画面四周是厚重的门框和门内的黑暗，形成一个偏方形的暗色边框，占据画面外圈。
门开着，正中是豁然打开的夜空 —— 深蓝到近黑的渐变，布满星点，
偏西南方有一颗明显最亮的白色星。
门外是天台的水泥地，只看到很近的一小块，被门外的天光照成灰白。
铁门的边缘有锈迹和一处明显被外力敲坏、变形的锁扣。
风的感觉：门内侧挂着的一根旧电线在轻微摆动。
冷蓝色调，强烈的明暗对比，前景是大块暗色，中心亮。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
first person POV looking out through a just-pushed-open iron door, heavy door frame and interior
darkness forming a dark border around the frame, center revealing a wide open night sky, deep blue
to near black gradient full of stars, one distinctly brightest white star toward the southwest,
a small patch of concrete rooftop just outside lit pale grey by skylight, rust on the door edge
and a visibly broken deformed latch, an old wire swaying slightly inside the doorway,
cool blue tones, strong contrast, large dark foreground, bright center, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-5　★★★ 蹲在底座旁 · 手电照到缝隙
> 锚点 `2731–2734`　景别：低机位近景　氛围：全作张力最高的一秒　**无脸** · 横版
> **★ 与 `S-1` `A-7` 同机位，必须同一次对话连着出。这一张是必做项。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
极低机位，近景，几乎贴着地面。深夜天台的水泥地面，干的，浅灰，积了灰。
画面右侧是一台旧天文望远镜的三脚架下半部分和黑色金属底座，
其中一条腿明显有点歪，漆掉了几块，露出下面暗青色的金属。
底座和水泥地面之间有一条极窄的缝隙，缝里露出一角折得很扁的浅蓝色纸，纸已经发黄。
一束手电筒的光从画面左侧打进来，光锥边缘画成清楚的直边，正好照在那条缝隙上，
光里能看见浮起的灰尘。画面左下角有一只手的一部分入镜，手指刚要伸向那条缝。
除了手电光锥之外整个画面都很暗，冷蓝的夜色打底，手电的光是偏白的。
背景用大面积的暗色块简化处理，视觉重点在那一角纸上。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme low angle close-up, almost at ground level, dry pale grey dusty concrete rooftop at night,
right side of the frame shows the lower tripod legs and black metal base of an old astronomical
telescope, one leg visibly bent, paint chipped exposing dark teal metal underneath,
a very narrow gap between the base and the concrete, a corner of tightly folded yellowed pale blue
paper protruding from the gap, a flashlight beam with clean straight edges entering from the left illuminating
exactly that gap, dust motes visible in the beam, part of a hand entering at the lower left with
fingers reaching toward the gap, everything outside the beam very dark, cool blue night base with
cold white flashlight, simplified dark background, visual focus on the paper corner, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-6　摊开的信 · 她的字
> 锚点 `2738–2744`　景别：特写　氛围：认得出是她　**无脸** · 横版
> **★ 字必须留白手填。她的信是全作最关键的文字。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
特写，手电光下的一张展开的旧信纸，占据画面大部分。
纸是浅蓝色的，已经发黄，折了很多层，折痕压得极深，像被指甲反复压过，
摊开后纸面并不平，沿折痕微微鼓起，边缘有一点点卷。
纸面留白（后期手动加字），只在几处保留很淡的墨迹晕开的痕迹和纸的纤维质感。
一只手的拇指从画面下方压住纸的一角，手在轻微发抖（画出几道细的抖动重影线来表现）。
手电筒的光从画面左上打下来，光斑中心在纸的中央，边缘暗下去。
背景是深暗的水泥地面，几乎看不清。冷白的光，暖黄的纸，明暗对比清楚。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
close-up of an unfolded old letter under flashlight, filling most of the frame, pale blue paper
yellowed with age, many deep fold creases as if pressed repeatedly with a fingernail, surface not
flat, ridged along the creases, edges slightly curled, paper left blank with only faint ink bleed
marks and visible paper fiber texture, a thumb pressing one corner from below with very slight
motion blur suggesting trembling, flashlight beam from upper left with the hotspot at the center
of the paper falling off toward the edges, dark concrete floor barely visible behind,
cold white light on warm yellowed paper, clear light-shadow contrast, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-7　★★★ 额头靠在望远镜底座上（读完信）
> 锚点 `2814`–`2817`　景别：极低机位近景　氛围：不太像在哭，更像在抱住这台望远镜　**无脸** · 横版
> **★★★ 与 `A-5`、`A-8` 严格同机位 —— 同一块水泥地，同一个蹲姿，三次。**

源码原话：
> `2814` 你读完了。
> `2816` 你的额头靠在望远镜的底座上。
> `2817` 你已经不知道你哭了多久。

### ⚠ 这张不能画成"哭脸特写"

`2816` 写的是**一个不太像是在哭的姿势** —— 额头抵着冰凉的金属。
画出脸和眼泪，它就退化成一个普通的哭戏；画背影和那把掉在地上的手电，
比任何表情都狠。**手电横躺着、光锥打在地上、没有照到他**，这是这张图的题眼。

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
极低机位，近景，和 A-5、A-8 完全相同的机位、焦距和构图。
深夜的天台，干的浅灰水泥地面。画面右侧是同一台旧天文望远镜的三脚架下半部分
和黑色金属底座，同一条歪了的腿。
一个男生蹲在底座旁边，深深地低着头，额头轻轻地靠在那个冰凉的黑色金属底座上。
看不见他的脸 —— 只看得到低下去的后颈、肩膀的轮廓、和垂下来遮住侧脸的头发。
他的一只手还握着那张展开的浅蓝色信纸，纸的一角垂下来，快要碰到地面；
另一只手按在上衣口袋外面，隔着布料握着里面那颗折纸星星。
他的肩膀塌下去一点，整个姿势不太像是在哭，更像是在抱住这台旧望远镜。
手电筒掉在旁边的水泥地上，还亮着，光锥横着打在地面上，没有照到他 ——
所以他整个人是逆光的一团暗色块，只有肩线和后颈被勾出一道很细的冷白边。
地面上有几滴刚落下的水痕，在手电的光里反光。
冷蓝色调，大面积的暗色块，非常安静，不要夸张的表情或动作。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme low angle close-up, identical camera position focal length and composition as A-5 and A-8,
observatory rooftop at night, dry pale grey concrete floor, the same old telescope tripod lower legs
and black metal base on the right with the same bent leg, a young man crouching beside the base,
head bowed deeply, forehead resting lightly against the cold black metal base, face not visible,
only the bowed nape of his neck, the outline of his shoulders and hair falling to hide his profile,
one hand still holding the unfolded pale blue letter with one corner drooping toward the ground,
the other hand pressed against his jacket pocket holding the paper star through the fabric,
shoulders slightly collapsed, a posture that reads less like crying and more like embracing the old
telescope, a flashlight dropped on the concrete nearby still lit, its beam lying sideways across the
ground and NOT falling on him, so he is a backlit dark mass with only a thin cold white rim on his
shoulder line and nape, a few fresh water drops on the ground catching the flashlight,
cool blue tones, large dark color blocks, very quiet, no exaggerated expression or gesture,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-8　★★ 折纸星星放在三脚架下
> 锚点 `2820`　景别：低机位近景　氛围：把她留在这里　**无脸** · 横版
> **★ 与 `A-5`、`A-7` 严格同机位。蹲下找到信 ↔ 额头靠底座 ↔ 蹲下放下星星。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
极低机位，近景，和 A-5、A-7 完全相同的机位、焦距和构图 ——
同一台旧望远镜的三脚架下半部分和黑色金属底座在画面右侧，同一条歪了的腿。
这一次没有手电筒。地面上，紧贴着三脚架的中心，放着一颗折好的浅蓝色纸星星，
五个角，折痕清晰，纸面已经软化。
唯一的光源是天光和星光，整个画面是很暗的冷蓝，只有那颗纸星星因为颜色浅，
在暗部里是最亮的一点。画面上方一小条露出夜空，能看见几颗星。
没有人，没有手。背景用大面积暗色块简化处理，视觉重点在纸星星上。安静、克制、留白。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme low angle close-up, identical camera position focal length and composition as A-5 and A-7,
same old telescope tripod lower legs and black metal base on the right, same bent leg,
no flashlight this time, a folded pale blue paper star with five points resting on the concrete
right at the center of the tripod, creases crisp, paper softened, lit only by skylight and starlight,
overall very dark cool blue, the pale paper star being the brightest point in the frame,
a thin strip of night sky with a few stars at the top, no people no hands,
simplified dark background, visual focus on the paper star,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-9　★★ 走下楼梯 · 泪痕还没干
> 锚点 `2821`　景别：中景 · 侧后方俯视　氛围：慢，不是奔跑　**无脸（背影）** · 横版
> **★ 与 `A-2` 构成一对背影，方向相反：`A-2` 抬头看天，这张低头往下走。**

源码原话（`2821`）：
> 你转过身,**慢慢地,一级一级地**,走下楼梯。夏夜的风还在吹。

### ⚠ 这张不能画成飞奔，理由在源码里

`2822` 紧接着写：「向前迈出一步，强烈的头晕便立刻袭来……膝盖也在不停地发抖……
双腿都如同灌了铅一般沉重……就像是在沼泽中艰难行进。」——**他走不快。**

而且这个"慢"是**故意埋的回扣**：

| 行 | 内容 |
|---|---|
| `2709` | 当年**她走得比你快**，她从来不看脚下，你在后面一边喘一边喊「慢一点」；可她每次到平台都会停下、回头、等你 |
| `2710` | 今夜你一个人上楼，「你走得很慢，**因为你走得比她还慢**」，「你也不用回头，因为身后没有人」 |
| `2821` | 下楼，「**慢慢地,一级一级地**」 |

画成飞奔，这条跨三年的伏笔就断了。**"慢"才是这张图的内容。**
眼泪照给足 —— `2817`「你已经不知道你哭了多久」，他是**哭完之后**才下楼的，泪痕没擦。

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
天文台的旧石头楼梯，从侧后方稍高的位置往下看。
楼梯很窄，一侧是斑驳的水泥墙，另一侧是简单的铁栏杆，栏杆的漆掉了不少。
每一级石阶的正中都有一个被几十年的脚磨出来的凹陷，边缘磨得很圆。
一个男生正走在楼梯中段，背对镜头偏侧，比镜头低几级，正往画面深处、往下走。
看不见他的脸 —— 只看得到后脑、垂下来的头发、肩膀的轮廓，和一点点侧脸的下颌线。
他走得非常慢：一只手扶在铁栏杆上，手指是握紧的；重心压在后面那条腿上，
前脚刚落到下一级台阶还没踩实。整个姿势是沉的、撑着的，不是奔跑，不是跨步。
他的侧脸下颌线上有一道还没干的泪痕，反着一点微光；
下巴的最低处正挂着一滴将要落下的眼泪。他没有去擦。
他没有回头。身后上方是天台的门，开着，门外是一小片夜空。
光：楼梯间没有灯，唯一的光从上方那扇开着的天台门里漏下来，
在他的肩膀和几级石阶上打出一小片冷白，越往下越暗，
画面下方的楼梯完全沉进黑色。
冷蓝色调，大面积的暗色块，安静、疲惫、但不悲惨。
不要奔跑的动作，不要甩起来的头发，不要动感线，不要夸张的表情。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
old stone staircase of an observatory seen from slightly above and behind, narrow stairwell,
a weathered concrete wall on one side and a simple iron railing with chipped paint on the other,
each stone step worn with a rounded hollow at its center from decades of footsteps,
a young man in the middle of the staircase, back to camera and slightly turned, a few steps below the
viewer, moving downward into the depth of the frame, face not visible, only the back of his head,
hair falling forward, the outline of his shoulders and a sliver of his jawline,
walking very slowly: one hand gripping the iron railing with tight fingers, weight still on the rear
leg, front foot just touching the next step without settling, the whole posture heavy and supported,
NOT running, NOT striding, a fresh undried tear track along his visible jawline catching a faint
highlight, a single tear hanging at the lowest point of his chin about to fall, he does not wipe it,
he does not look back, above and behind him the rooftop door stands open with a small patch of night
sky beyond, no lights in the stairwell, the only light spilling down from that open door casting a
small cold white patch on his shoulder and a few steps, falling off downward until the lower part of
the staircase sinks into black, cool blue tones, large dark color blocks,
quiet and exhausted but not miserable, no running pose, no flying hair, no speed lines,
no exaggerated expression, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG A-10　一道流星（可省）
> 锚点 `2853`　景别：仰拍天空　氛围：收束　**无脸** · 横版
> **建议省掉**：源码里 `draw_A_liuxing()` 本来就是动画，Ren'Py 用 `A-4` 的天空 + ATL 划一道更好，省一张图。要做就按下面。

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
仰拍纯夜空，画面里没有地面、没有建筑。深蓝到近黑的渐变，密集的星点。
偏西南方有一颗明显最亮的白色星，带四道细长的十字光芒。
从画面右上到中部偏左，有一道流星的轨迹，头部亮、尾部渐淡，很细，不夸张，
轨迹没有穿过那颗最亮的星，而是从它下方掠过。
冷蓝色调，干净，没有云，没有月亮，不要文字。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
looking straight up at the night sky, no ground no buildings, deep blue to near black gradient,
dense stars, one distinctly brightest white star toward the southwest with fine cross diffraction
spikes, a single thin meteor trail from upper right toward center-left, bright head fading tail,
subtle not exaggerated, the trail passing below the brightest star rather than through it,
cool blue tones, clean, no clouds no moon, no text,
horizontal 3:2, no text watermark, no photographic texture
```

---

## 六、回忆 4 张（她）

### CG S-1　★★★ 三年前 · 她在底座旁写这封信
> 锚点 `2749`（插在她说「这封信是我从医院跑出来的那天写的」之后）
> 景别：低机位近景 · 与 `A-5` 同机位　氛围：偷跑出来的一个小时　**有脸** · 横版
> **★ 全册最重要的一张。**

中文：
```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、平面化色块、精致的眼睛。不是照片，不是3D渲染，不是写实风格。

【场景】
低机位近景，雨后的天台，白昼将尽。水泥地面是湿的，深灰，有几处浅浅的积水，
映着阴天的灰白天光。
画面右侧是一台旧天文望远镜的三脚架下半部分和黑色金属底座，其中一条腿有点歪。
她一个人坐在底座旁边的湿水泥地上，侧身对着镜头，
身上是浅蓝色的病号服，外面胡乱套着一件明显大一号、不合身的藏青色外套，
外套的袖子长出一截，肩线垮在她的上臂上。她的左手背上还留着没拆的留置针，
针口贴着一小块医用胶布。
一张浅蓝色的薄纸铺在她的膝盖上，她的左手死死压着纸的一角，右手握着笔正在写，
下巴压得很低，几乎要碰到膝盖。风把纸的另一角掀起来了，也把她的头发吹到脸侧。
她没有看镜头，全部注意力都在那张纸上。
天空是雨后的灰白，没有太阳。横版 3:2。不要动漫大眼，不要浓妆，不要笑，不要背景人物。

整张图用偏暖的、略微褪色的色调，像一段被反复回想过的记忆 ——
但仍然是动漫赛璐璐上色，不是做旧照片。
只画她一个人。横版 3:2。
不要双马尾、丸子头、短发，不要改发色瞳色，不要张嘴大笑或夸张表情，
不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
```
英文 tag 版：
```
1girl, anime style illustration, galgame visual novel CG, hand-drawn cel shading,
clean lineart, flat color, detailed anime eyes, NOT a photograph, NOT 3d render, NOT realistic,
low angle close-up, rooftop after rain at dusk, wet dark grey concrete with shallow puddles
reflecting pale grey overcast sky, old telescope tripod lower legs and black base on the right with one
bent leg, she sits alone on the wet concrete beside the base in profile,
pale blue hospital gown with an oversized ill-fitting navy coat thrown over it, sleeves too long,
shoulder seams hanging down her upper arms, an unremoved IV cannula on the back of her left hand
with a small medical tape patch, a pale blue sheet of paper spread on her knees,
left hand pressing one corner firmly, right hand writing with a pen, chin lowered almost to her knees,
wind lifting the other corner of the paper and blowing her hair across her cheek,
not looking at camera, pale grey post-rain sky no sun, warm slightly faded memory tones, still anime cel shading,
horizontal 3:2, solo, no text watermark
```

---

### CG S-2　更早 · 两人并肩 · 一袋膨化食品
> 锚点 `2753`（「那天我拉你上来的时候,天已经很冷了……吃过一整袋没有味道的膨化食品」）
> 景别：中景 · 侧后方　氛围：上来一次不容易　**有脸（侧脸）** · 横版

中文：
```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、平面化色块、精致的眼睛。不是照片，不是3D渲染，不是写实风格。

【场景】
中景，从侧后方拍。深秋或初冬的夜晚，天台边缘，两个人并肩坐在矮护墙上，
背对着镜头偏侧，能看见她的侧脸，男生只有背影和一点侧脸轮廓，看不清五官。
她穿米白色毛衣，领口露出一根很细的银链，毛衣有点大，袖口盖住半只手。
两人之间的水泥台面上放着一袋已经撕开的膨化食品，包装是廉价的亮色，
在整个冷色画面里是唯一一块跳出来的暖色，袋口翻卷着。
天很冷 —— 她呼出的气看得见，是很淡的一小团白。
她微微低着头，手拢在袖子里，肩膀和男生的肩膀之间还留着一点距离，没有靠上。
远处是城市的灯火，简化成一条暖色的光带，压在画面下方三分之一处。
天空是深蓝的冬夜，星不多。横版 3:2。不要动漫大眼，不要浓妆，不要露出牙齿的笑。

整张图用偏暖的、略微褪色的色调，像一段被反复回想过的记忆 ——
但仍然是动漫赛璐璐上色，不是做旧照片。
只画她一个人。横版 3:2。
不要双马尾、丸子头、短发，不要改发色瞳色，不要张嘴大笑或夸张表情，
不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
```
英文 tag 版：
```
1girl, anime style illustration, galgame visual novel CG, hand-drawn cel shading,
clean lineart, flat color, detailed anime eyes, NOT a photograph, NOT 3d render, NOT realistic,
1girl and 1boy seen from behind and to the side, medium shot, late autumn night on a rooftop,
both sitting side by side on a low parapet wall, her profile visible, the boy only a back and faint
profile outline with indistinct features, she wears an oversized off-white cream sweater with a thin
silver necklace at the collar, cuffs covering half her hands, an opened bag of cheap brightly
packaged puffed snacks on the concrete between them, the only warm color in a cold frame,
her visible breath as a faint white puff in the cold air, head slightly lowered, hands drawn into
her sleeves, a small gap remaining between her shoulder and his, distant city lights simplified into a
warm band across the lower third, deep blue winter sky with few stars,
warm slightly faded memory tones, still anime cel shading,
horizontal 3:2, solo, no text watermark
```

---

### CG S-3　★★ 她指着西南方的天空说「我是 Vega」
> 锚点 `2788`（「我曾经和你并肩坐在这里,一遍又一遍地告诉你我是织女星,是 Vega」）
> 景别：近景 · 仰角　氛围：**全项目唯一一张她"活着并且在发光"的图**　**有脸** · 横版

中文：
```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、平面化色块、精致的眼睛。不是照片，不是3D渲染，不是写实风格。

【场景】
近景，略仰角，从她的侧下方拍。和上一张同一个夜晚、同一套米白色毛衣。
她抬着头看天，右手抬起来，用小拇指指向画面右上方偏西南的天空。
她的下巴、脖颈和喉线被天光照亮，是画面里最亮的部分。
她的眼睛睁得很亮，视线在天上，不在镜头。嘴唇微微张开，像正在说话的中途。
她的表情是全篇里最放松、最亮的一次 —— 有一点笑，但很轻，是在讲一件自己很喜欢的事的表情。
夜风把她的头发往一侧吹起一小束。
她指的方向上，天空有一颗明显最亮的白色星。
背景是深蓝夜空，城市灯火简化成大片模糊的色块，视觉重点在她的脸和抬起的手之间。横版 3:2。不要动漫大眼，不要浓妆，不要露出牙齿的大笑。

整张图用偏暖的、略微褪色的色调，像一段被反复回想过的记忆 ——
但仍然是动漫赛璐璐上色，不是做旧照片。
只画她一个人。横版 3:2。
不要双马尾、丸子头、短发，不要改发色瞳色，不要张嘴大笑或夸张表情，
不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
```
英文 tag 版：
```
1girl, anime style illustration, galgame visual novel CG, hand-drawn cel shading,
clean lineart, flat color, detailed anime eyes, NOT a photograph, NOT 3d render, NOT realistic,
close-up from slightly below, same night and same off-white cream sweater as before,
head tilted up looking at the sky, right arm raised pointing with her little finger toward the upper
right southwest sky, her chin throat and neckline lit by skylight as the brightest area of the frame,
eyes bright and looking upward not at the camera, lips slightly parted mid-sentence,
her most relaxed and luminous expression in the whole story, a very faint smile, the look of someone
explaining something she loves, a small strand of hair lifted by the night wind,
one distinctly brightest white star in the direction she points, deep blue night sky, city lights behind simplified into large soft color blocks, visual focus between her face and raised hand,
warm slightly faded memory tones, still anime cel shading,
horizontal 3:2, solo, no text watermark
```

---

### CG S-4　★★ 病房 · 她说那句谎
> 锚点 `2767`（「如果我走了,不要回来找我,往前走,不要总是抬头,不要总是想我。」）
> **下一句 `2768` 是「——那是骗你的。」**
> 景别：近景 · 平视　氛围：她在撒一个为了他好的谎　**有脸** · 横版
> **★ 和 `S-1` 是隔一天的连续两张，同一套病号服 + 同一处留置针位置。**

中文：
```
这是我的原创角色参考图。请严格保持她的长相不变 ——
银白带极淡薰衣草紫的超长直发（过膝）、中分刘海、耳前长鬓发垂到胸前、
大眼睛、浅蓝偏紫的瞳孔、眼尾微微下垂、小脸、尖下巴、瓷白皮肤。

保持这张脸不变，把她画进下面这个场景。galgame CG 风格：柔和赛璐璐上色、
干净线稿、平面化色块、精致的眼睛。不是照片，不是3D渲染，不是写实风格。

【场景】
近景，平视，从床边的高度拍。白天的病房，窗帘半开，
窗外的天光是一片没有细节的、没有温度的白色块，从画面左侧大面积漫进来。
她半坐在病床上，背后垫着枕头，穿浅蓝色的病号服，领口松着。
左手放在被子上，手背上有留置针，针口贴着一小块医用胶布，
针管连着的输液线垂到画面外。她比前面几张明显瘦了，
颧骨和手腕的骨头形状更清楚，嘴唇没有血色。
她看着镜头这一侧 —— 是全篇唯一一张她直视镜头的图 —— 但眼神是平的、稳的，
嘴角有一点很轻的、刻意做出来的笑，那种为了让对方安心而摆出来的表情。
她的眼睛没有在笑。
床头柜上有一个白色的药瓶和一只没动过的水杯。横版 3:2。不要动漫大眼，不要浓妆，不要哭，不要眼泪，不要背景人物。

整张图用偏暖的、略微褪色的色调，像一段被反复回想过的记忆 ——
但仍然是动漫赛璐璐上色，不是做旧照片。
只画她一个人。横版 3:2。
不要双马尾、丸子头、短发，不要改发色瞳色，不要张嘴大笑或夸张表情，
不要露肤过多，不要文字水印，不要 3D 或写实照片风格。
```
英文 tag 版：
```
1girl, anime style illustration, galgame visual novel CG, hand-drawn cel shading,
clean lineart, flat color, detailed anime eyes, NOT a photograph, NOT 3d render, NOT realistic,
close-up at eye level from bedside height, daytime hospital room, curtains half open,
large flat area of featureless cold white daylight flooding in from the left,
she sits half upright in the hospital bed propped on pillows, pale blue hospital gown with a loose
collar, left hand on the blanket with an IV cannula on the back of the hand and a small medical tape
patch, IV line running out of frame, visibly thinner than before with more defined cheekbones and
wrist bones, colorless lips, looking directly at the viewer with a flat steady gaze,
a very faint deliberately composed smile meant to reassure, the smile not reaching her eyes,
a white pill bottle and an untouched glass of water on the bedside table,
warm slightly faded memory tones, still anime cel shading,
horizontal 3:2, solo, no text watermark
```

---

## 七、后记 4 张

> 后记是**作者本人**的声音，不是主角。四张里没有她，也没有主角 —— 换了一个世界。
> `H-1` `H-2` 是"蝴蝶"乐章（晨光/暖白），`H-3` 是"自白"（深夜/冷），`H-4` 是献词（白天/秋）。

### CG H-1　★★★ 晨光 · 纸箱最底层风干的凤蝶
> 锚点 `2412–2415`　景别：俯拍近景　氛围：清理旧物时撞见的东西　**无脸** · 横版
> **★ 构图要呼应 `A-5`：都是"一束光照进一个容器的最底部"。紧跟 `A-5` 在同一对话里出。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
俯拍近景，清晨的室内。一束晨光从画面左上方斜切进来，边界清楚，
光里有细小的浮尘。光柱正好落进一只打开的旧纸箱内部，照到箱子的最底层，
箱子外面的部分是暗的。
纸箱是发黄的硬纸板，箱口的胶带已经老化开裂，箱壁上有旧的折痕和水渍。
箱子最底层是一本泛黄的素描本，封面卷边，摊开着。
摊开的纸页上，静静地停着一只被时间风干的凤蝶 —— 完整，但明显已经很脆，
翅膀的颜色褪成了淡褐和灰白，翅脉清晰，一侧的翅缘有一处很小的缺损。
画面里没有人。暖白色调，晨光是偏冷的白但落在旧纸上显出暖意，
强烈的明暗对比，视觉重点在蝴蝶上。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
overhead close-up, indoor early morning, a shaft of morning light with clean straight edges entering from the
upper left with fine dust motes, the beam falling into the interior of an opened old cardboard box
and illuminating its very bottom, the outside of the box in shadow,
yellowed cardboard with cracked aged tape and old creases and water stains,
at the bottom of the box an open yellowed sketchbook with curled cover,
on the open page rests a time-dried swallowtail butterfly, intact but visibly brittle,
wing colors faded to pale brown and grey-white, wing veins clearly visible, a tiny notch missing
from one wing edge, no people, warm white tones, cool white morning light warming on old paper,
strong light-shadow contrast, visual focus on the butterfly,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG H-2　★★ 掌心托着近乎透明的蝴蝶
> 锚点 `2463–2465`（「它此刻躺在我掌心,近乎透明——它的美不再是飞行的美,而成了光线的容器。」）
> 景别：特写 · 逆光　氛围：全篇论点图　**无脸** · 横版

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
特写，强烈的逆光。一只摊开的手掌从画面下方伸进来，掌心朝上，
托着那只风干的凤蝶。晨光从蝴蝶的背后直射过来，
光完全穿透了它的翅膀 —— 翅膜变成半透明的琥珀色，
翅脉在透光下变成一张清晰的深色网络，像一片被照亮的叶子的叶脉。
翅膀的边缘有一圈很细的光晕。手掌的皮肤和指缝也被逆光照出边缘的暖红。
背景是一整片纯白的高光色块，看不出是什么地方，只有一点光晕和简化的窗框轮廓。
整张图的主体只有：光、翅膜、翅脉、和托着它的那只手。
暖白色调，背景用大面积的白色块简化处理，视觉重点在翅脉上。没有脸。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme close-up, strong backlight, an open palm entering from below facing up, holding the
time-dried swallowtail butterfly, morning light coming directly from behind the butterfly and fully
transmitting through the wings, wing membranes turned translucent amber, wing veins rendered as a
clear dark network like the veins of a backlit leaf, a fine rim of glow along the wing edges,
warm red rim light on the skin of the palm and between the fingers,
background as one flat pure white highlight area with faint bloom and a simplified window frame outline,
subject is only light, membrane, veins and the hand holding it,
warm white tones, simplified white background, visual focus on the wing veins, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG H-3　深夜 · 电脑屏幕的冷光
> 锚点 `2495–2497`（「又到了一个平常的深夜。我看着我的电脑屏幕,又想起了一些事。」）
> 景别：中景 · 背影　氛围：唯一一张"现实世界"　**无脸（背影）** · 横版
> **★ 色温必须和前面所有夜景反着来：冷白，不是暖黄。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
中景，从背后拍。一个平常的深夜，房间里没有开灯。
一个人坐在桌前，背对镜头，只有肩膀和后脑的轮廓，被屏幕的光从正面打亮，
在轮廓边缘形成一道冷白的光边。看不见脸，也看不见屏幕上的内容。
桌上是一台笔记本电脑，屏幕是这个画面里唯一的光源，光是冷白偏蓝的，
把桌面、键盘、和一只放在触摸板边上没有动作的手照亮，
其余部分迅速衰减到黑。桌上还有一只杯子和几张摊着的纸。
背景是完全的暗，只能勉强看出墙和一扇没有拉严的窗帘，窗外没有光。
冷蓝白色调，和整个故事里的暖黄夜景完全相反。背景大面积留暗，安静，一点点疲惫感。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
medium shot from behind, an ordinary late night in an unlit room, a person sitting at a desk with
back to camera, only shoulder and head silhouette rimmed by cold white light from the screen in
front, face not visible, screen content not visible, a laptop on the desk as the sole light source,
cold blue-white light illuminating the desk surface keyboard and one motionless hand resting at the
edge of the trackpad, everything else falling off rapidly to black, a cup and a few loose sheets of
paper on the desk, fully dark background with a barely discernible wall and half-drawn curtain,
no light outside, cold blue-white tones opposite to the warm night scenes elsewhere,
large dark areas, quiet, faint fatigue, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG H-4　★★ 秋天的湖泊 · 十二只白鹭鸶
> 锚点 `2643–2644`（「请千万记住,在我们菲薄的流年／曾有十二只白鹭鸶飞过秋天的湖泊」）
> 景别：大远景　氛围：**全作最后一张，也是唯一一张白天的大自然**　**无脸** · 横版
> **★ 300 句夜戏之后放这一张，作用是"松开"。数量必须给足十二只。**

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
大远景，秋日下午的湖泊。湖面很宽，占据画面下半部分，水面平静，
反着天空的浅金色，只有远处有一点细碎的波光。
对岸是低矮的树线，叶子是秋天的颜色 —— 赭黄、锈红、还有没落尽的深绿，
被距离和薄雾洗淡了一层。天空是高的、清的，浅蓝到暖金的渐变，
低处有几缕横向的薄云。
十二只白鹭鸶正从画面左侧飞向右上方，排成不规则的斜列，翅膀展开，
最前面的几只已经飞到画面中部偏上，最后面的两只还压在水面附近，
翅膀在水上留下极淡的倒影。数量正好是十二只，不多不少。
没有人，没有建筑，没有船。明亮、开阔、温暖、干净，
和整个故事里所有的夜晚完全相反。不要文字。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme wide shot, a lake on an autumn afternoon, wide calm water filling the lower half of the
frame reflecting pale gold sky with faint glitter in the distance, low tree line on the far shore in
autumn colors of ochre rust red and remaining deep green, washed pale by distance and haze,
high clear sky with a pale blue to warm gold gradient and a few horizontal wisps of cloud near the
horizon, exactly twelve white egrets flying from the left toward the upper right in an irregular
diagonal formation with wings spread, the leading few already in the upper middle of the frame,
the last two still low near the water leaving very faint reflections,
no people no buildings no boats, bright open warm and clean, opposite to every night scene in the
story, no text,
horizontal 3:2, no text watermark, no photographic texture
```

---

## 八、生成完之后

### 文件名（沿用现有约定，纯 ASCII）

```
E:\《星空回响》\cg\
  A1.png  A2.png  A3.png  A4.png  A5.png
  A6.png  A7.png  A8.png  A9.png  A10.png
  S1.png  S2.png  S3.png  S4.png
  H1.png  H2.png  H3.png  H4.png
```

Ren'Py 会自动把 `A5.png` 认成 `image a5`，`scene a5 with dissolve` 直接可用。

### 全项目 CG 总数

| 批次 | 张数 | 状态 |
|---|---|---|
| 主手册 第一～四章 | 24 | ✅ 已完成（在 `E:\《星空回响》\cg\`） |
| 序幕 + 第五层 | 12 | ⬜ 待生成 |
| **结局 A（本册）** | **18** | ⬜ 待生成 |
| 结局 B | 0 | ✅ 定案不做（空白就是它的设计意图） |
| 结局 C | 0 | ✅ 定案不做（只做 A） |
| **合计** | **54** | 24 / 54 |

比最初估的"估计能有 50 张"多了 4 张，都在结局 A 上。

### 待办

- [ ] 主手册那 8 张竖版 + 1 张方图裁成 3:2（约 8 分钟），让 54 张统一比例
- [ ] `A-1` `A-6` `S-1` 三张的手写字后期手动填（`A-6` 必须手填）
- [ ] 改 `CG生成提示词.md` 的修订记录：**删掉"藏青色外套是错误、已修掉"那条**，它现在有来历了（见本册第三节）
- [ ] 把 302 句独白转成 Ren'Py 脚本，按本册的锚点行号插图
- [ ] `源.cpp` 里 `setColor(14)/(8)/(6)` 的三级强调必须在 Ren'Py 里用 `{color=#...}` 保留 —— 那是作者语气，丢了就变成一片平的白字

---

## 九、改动记录

- **2026-08-10**　★ 补 `A-9`「走下楼梯 · 泪痕还没干」（锚点 `2821`）。按源码 `2821`/`2822` 定为**极慢、扶着栏杆**，不是飞奔 —— 回扣 `2709`/`2710`「当年她走得比你快」→「今夜你走得比她还慢」。旧 `A-9`（流星）顺移为 `A-10`。
- **2026-08-10**　★ 补 `A-7`「额头靠在望远镜底座上」（锚点 `2814`–`2817`）。此前漏了男主**读完信**这个情绪最高点。因此同机位组从三张变四张：`S-1` 写 → `A-5` 找到 → `A-7` 崩 → `A-8` 放下。旧 `A-7`（放下星星）顺移为 `A-8`。
- **2026-08-10**　建册。16 张（正文 8 + 回忆 4 + 后记 4）。
- **2026-08-10**　`源.cpp:2749` 时间线修正：信从「住院之前一个礼拜」改为「从医院跑出来的那天」，「从家里出来」改为「从病房出来」。理由：`2767` 在信里引用了住院期间的对话，写在住院前不可能引用。连带确定 `S-1` 的服装（病号服 + 藏青色外套 + 未拆留置针），并给藏青色外套补上了来历。
- **2026-08-10**　`2741`/`2742` 重复段、`2748` 语气、`2822` 段落归属 —— 三处经确认**保持原样，不改**。
