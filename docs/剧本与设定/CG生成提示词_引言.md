
# 《星空回响》CG 生成提示词手册 · 引言（楔子独白）· 3 张

> 配套 `CG生成提示词.md`（主手册 24 张）、`CG生成提示词_序幕与第五层.md`（12 张）、`CG生成提示词_结局A.md`（18 张）。
> 本册只管**引言**，也就是 `源.cpp` 的 `mujian_sanwen[0]`（`498`–`615` 行，共 **24 段**），由 `play_the_pangbai(0)` 播放。
> 每张图下面都标了**锚点行号**，写 Ren'Py 脚本时按行号插图，不要凭记忆。

---

## 零、这 3 张的分割点不是我定的，是 `gaoliang()` 定的

引言不是普通独白，它有一层**画面在跟着文字走**。`play_the_pangbai(0)` 每翻一页就调 `gaoliang(0, page)`（`源.cpp:1149`–`1168`），按页码逐步点亮固定 ASCII 书房剖面上的东西：

| 页码 | `gaoliang(0, page)` 做的事 | 含义 |
|---|---|---|
| 0 – 3 | 什么都不点，只有顶上一个 `✦` | **画面里还没有人** |
| `>=4` | 点亮 `O` + `/|\`（`setColor(14)` / `6`） | **人出现了** —— 对应 `513` 「台灯是我自己拧开的」 |
| `>=8` | ⭐ 亮（`setColor(14)` 亮黄） | 折纸星星 —— 对应 `528`「桌上有三样东西」 |
| `>=9` | 📖 亮（`setColor(6)` 暗黄） | 日记本 |
| `>=10` | 🖼 亮（`setColor(7)` 灰白） | 模糊照片 |

**所以三张 CG 就切在 4 / 8–10 / 收尾这三个地方**，等于把 ASCII 版已经写好的节奏翻译成图。这不是我加的结构，是你自己在 `gaoliang` 里埋的。

| # | 编号 | 锚点行 | 段号 | 画面 | 脸 | 比例 |
|---|---|---|---|---|---|---|
| 1 | **★★ P-1** | `499`–`512` | 1–4 | 空屋 · 台灯已经亮着 · **画面里没有人** | 无（无人） | 横 `1536×1024` |
| 2 | **★★★ P-2** | `528`–`547` | 8–11 | 桌上三样东西 · 背影已经在那里 | 无（背影） | 横 |
| 3 | **★★★ P-3** | `588`–`613` | 20–24 | 极远景 · 星空占满 · 书房缩成一个亮着的小窗 | 无（无人） | 横 |

**全部 `1536×1024` 横版。** 和结局A册同一条规矩：这一批不许出竖版。

---

## 一、★★★ 三张的内在逻辑：人是"出现"，然后"退开"

这是我读完 24 段之后认为引言真正在干的事，也是三张图必须按这个顺序看的原因：

| | 画面里有没有人 | 说明 |
|---|---|---|
| **P-1** | **没有** | 献词、"这是一个不成熟的故事"、"我会说「你」" —— 叙述者还在画外，还没进场 |
| **P-2** | **有（背影）** | 他坐下了，三样东西被一件一件看过去 —— 这是全册唯一有人的一张 |
| **P-3** | **没有** | 镜头拉到二十五光年之外，人被尺度吃掉了 —— "现在,可以开始了" |

**有 → 无**，不是我编的对称，是 `509`「下面的故事里,我会说「你」」这句决定的：作者自己讲完这几页就要交出人称，从"我"退成"你"。所以第三张必须**把他从画面里拿掉**。

出图顺序：**`P-1` → `P-2` 必须同一对话连着跑**（同一间屋子、同一个机位家族，只多一个人和三样亮起来的东西）。`P-3` 是完全不同的机位，单独跑。

---

## 二、★★ 场景设定：直接照抄序幕册，一个字都不要改

**书房设定不在本册重写。** 见 `CG生成提示词_序幕与第五层.md` 第二节「场景设定（12 张共用，锁死）」——钨丝台灯、木书桌靠窗、旧木椅漆磨掉坐垫压扁、窗缝没关严、木地板、笔筒 + 一叠书。

引言和序幕是**同一间书房**，两册共用一套设定，抄两遍必然抄歪。

引言相对序幕唯一的差别：

| | 序幕 12 张 | 引言 3 张 |
|---|---|---|
| **谁在说话** | 「你」（第二人称，游戏正文） | 「我」（作者自己，还没换人称） |
| **画面重点** | 物品**特写**（星星、日记、照片各一张） | **全景**——整间屋子、三样东西一起、人在里面 |
| **有没有人** | `0-3B` 有背影，其余无 | `P-2` 有背影，`P-1`/`P-3` 无人 |

**所以引言 3 张和序幕 12 张不重复：那 12 张是"物品是什么样"，这 3 张是"这间屋子里有谁"。**

### ★ 藏青色外套：到这里有出处了，矛盾解除

序幕册第三节列了一个"必须你拍板的矛盾"——`CG生成提示词.md` 的修订说明里写「编了一件正文里不存在的藏青色外套」，判它是错的。

**它不是编的。** `源.cpp:532` 原文：

> `528` 桌上有三样东西。
> `529` 一颗折纸星星,一个角磨破了。
> `530` 一本没有写过一个字的日记本。
> `531` 一张模糊的照片——
> `532` **其中一个人的肩上,披着藏青色的外套。**

写在引言里，是全作**第一次**出现这件外套，而且是照片的关键细节。再加上结局A册第三节已经给它补了来历（`S-1`：她从病房跑出来那天披着的、他的外套），这条线是完整的：

**引言的照片里看见它 → 三年前她披着它写信 → 玩家读完结局 A 回头才明白照片上那个肩膀是谁。**

所以：
- 序幕册第三节那个"甲/乙/丙"三选一，**答案是甲（保留外套）**，不必再拍板；
- `CG生成提示词.md` 的修订说明里"藏青色外套是编的、已修掉"那条**是错的，要删**（结局A册待办里已列）。

但 `P-2` 里那张照片**依然画成模糊看不清颜色**——不是为了搁置矛盾，而是因为 `545`–`547` 明写「照片糊得像隔着一层雾」「我看不清他们的脸」。外套的**颜色**留到结局 A 再给，引言这里只给一个"肩上披着深色外套"的轮廓。**先埋轮廓，后给颜色**，这才是伏笔的正确顺序。

---

## 三、GPT Image 2 模板（3 张都用这个「没脸」版）

### ★ 先记住这条：风格声明必须放最前面，而且必须显式否掉照片

`CG生成提示词.md:780` 记着一次真实翻车：`4-1A` 出成了写实照片，原因是那段提示词**通篇摄影语言**，模板里那句「galgame 风格」被整段摄影术语压掉了。

所以：**「电影感构图」「浅景深」「精细光影」这类摄影词一个都不要写。**
要表达"背景模糊"，就说「背景用大面积暗色块简化处理」，不要说「浅景深」。

> ⚠ 注意：`CG生成提示词_序幕与第五层.md:116`–`117` 的模板**还是旧的摄影语言版**（`电影感构图、浅景深、光影细腻`），那 12 张一张都还没生成，**跑之前先照下面这个版本改掉**。

```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：

【画面描述】

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```

英文头：

```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
```

### ⚠ 出图后如果还是像照片，同一对话里追这句

> 「重画成手绘动漫插画风格，平面色块，看得出笔触和线稿，完全不要照片质感和真实材质反射。」

### ⚠ 画面里的字

`P-2` 里日记本封面有「给未来的你」（`540`，而且 `541` 特意写「**不是我的字**」）。AI 写中文必出乱码。
**这张走留白后期手填**：让它把封面那块画成空的浅色标签区，出图后自己加字。
这四个字是全作最重要的伏笔之一，不能交给 AI。

---

## 四、正文 3 张

### CG P-1　★★ 空屋 · 台灯已经亮着 · 画面里没有人
> 锚点 `499`–`512`（第 1–4 段：献词 → 「这是一个不成熟的故事」→「我会说「你」」）
> 景别：中景 · 略微俯视　氛围：叙述者还没进场　**无人** · 横版 `1536×1024`
> **★ 与 `P-2` 同机位，同一对话连着跑。这张是"人还没坐下"，`P-2` 是"人坐下了"。**

源码依据：
> `499` 向着星空、向着一个我已经叫不出名字的人——／`500` 我写下了这个故事。
> `509` 下面的故事里,我会说「你」。／`511` 我试过说「我」。／`512` 写到第三页就写不下去了。
> `513` 台灯是我自己拧开的,我记得。 ← **灯已经开了，人却还没画进去**

### ⚠ 这张的内容就是"空"

`gaoliang(0, page)` 在第 4 页才点亮 `O` + `/|\`，也就是说**前四页画面里确实没有人**。
这张图最容易画错的地方是"顺手加一个背影"——加了就毁了。
**灯亮着、椅子空着、人不在**，这三件事同时成立，才是引言开头那四段的语气。

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
深夜的书房，中景，机位比桌面略高一点，从侧前方看向书桌和窗户。
画面里没有人。一把旧木椅空着，从桌边稍微拉开一点，像是刚刚有人站起来，
或者还没有坐下。椅子的漆磨掉了几块，坐垫被压得扁扁的。
木书桌靠着窗。桌上只有一盏钨丝台灯亮着，灯罩压得很低，
光偏黄，在桌面上落下一小片边缘柔和的暖光，像倒了一小滩温水。
除了这一小片光，整个房间都沉在暗色块里，只能勉强看出书架和木地板的轮廓。
桌上还有一个笔筒（里面插着几支铅笔）和一叠书，都在光域的边缘，半明半暗。
窗外是黑的，只有很稀疏的几颗星，很暗。窗户没有关严，留着一道细缝。
暖黄和深蓝的对比：桌上一小片暖，其余全是冷的暗。
非常安静，空，有一点点被留下的感觉，但不要画成荒废或者脏乱。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
a study at night, medium shot, camera slightly above the desk surface looking at the desk and window
from the front side, NO people in the frame, an old empty wooden chair pulled slightly away from the
desk as if someone just stood up or has not yet sat down, paint chipped off the chair in places,
the seat cushion flattened, a wooden desk against the window, only a single tungsten desk lamp lit
with its shade low, warm yellow light pooling on the desk surface with soft edges like a small
puddle of warm water, everything outside that pool of light sinking into dark color blocks with the
bookshelf and wooden floor only barely readable, a pencil cup with a few pencils and a stack of books
at the edge of the light half lit, the window dark with only a few very faint sparse stars,
the window not fully closed leaving a thin gap, contrast of one small warm pool against overall cold
darkness, very quiet and empty with a faint sense of being left behind,
NOT derelict NOT messy, no people, no face,
horizontal 3:2, no text watermark, no photographic texture
```

---

### CG P-2　★★★ 桌上三样东西 · 背影已经在那里
> 锚点 `528`–`547`（第 8–11 段：三样东西 → 折纸星星 → 日记本 → 模糊照片）
> 景别：中景 · 与 `P-1` 同机位　氛围：一件一件看过去　**无脸（背影）** · 横版
> **★★★ 全册最重要的一张。三样东西必须一次全在画面里 —— 序幕那 12 张是拆开的特写，这一张是它们的合影。**
> **★ 画面带字（日记封面），走留白后期手填。**

源码依据：
> `528` 桌上有三样东西。
> `529` 一颗折纸星星,**一个角磨破了**。
> `530` 一本**没有写过一个字**的日记本。
> `531` 一张模糊的照片——／`532` **其中一个人的肩上,披着藏青色的外套。**
> `533` 折纸星星是**浅蓝色**的。每一道折痕都压得很实。／`539` **我没有拆。**
> `540` 日记本封面上写着「给未来的你」。／`541` **不是我的字。**
> `545` 照片糊得像隔着一层雾。／`547` 我看不清他们的脸。

### ⚠ 三个细节一个都不能省

| 细节 | 出处 | 为什么不能省 |
|---|---|---|
| 星星**一个角磨破了** | `529` | 磨破 = 被反复摸过。这是三年的物证 |
| 日记本封面的字**不是他的字** | `541` | 玩家现在不知道是谁的，读完才知道。字迹要画得**比他的笔迹秀气** |
| 照片里**肩上披着深色外套** | `532` | 全作第一次出现这件外套。**只给轮廓，不给颜色** —— 颜色留到结局 A |

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
深夜的书房，中景，和前一张完全相同的机位、焦距和构图 ——
同一张靠窗的木书桌，同一盏钨丝台灯，同一把旧木椅，同一扇留着细缝的窗。
这一次椅子上坐着一个人：一个年轻男生的背影，稍微偏侧，占画面左侧，
微微前倾看着桌面。看不见他的脸 —— 只看得到后脑、短发、和肩膀的轮廓。
他穿着一件旧的深色外套，肩线有点松。他没有在写字，两只手都放在桌面上，没有动。

桌上摊着三样东西，被台灯的光照到，是画面里唯一亮的部分，从左到右排开：
一，一颗折好的浅蓝色纸星星，五个角，折痕压得很实很深，
其中一个角已经磨破了、起毛发白，像被手指反复摸过很多次。
二，一本深色硬壳日记本，合着的，封面右下角有一小块浅色的标签区域，
这块标签留成空白，不要写任何字。
三，一张小的方形照片，照片本身糊得像隔着一层雾 ——
只看得出两个人的轮廓在星空下并排站着，脸完全看不清，五官不要画出来；
其中一个人的肩上松松地披着一件深色的外套，颜色看不出来，只是一块深色的形状。

台灯的光只够照亮桌面这一片和他的一侧肩膀，房间其余部分全是暗色块。
窗外是黑的，几颗很暗的星。暖黄的桌面 + 冷暗的房间。
安静、克制，一点点困惑，不要悲伤的表情或动作。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
a study at night, medium shot, identical camera position focal length and composition as the previous
image, same wooden desk against the window, same tungsten desk lamp, same old wooden chair,
same window with a thin gap, this time a young man sits in the chair seen from behind and slightly to
the side on the left of the frame, leaning forward a little looking at the desk, face not visible,
only the back of his head, short hair and the outline of his shoulders, wearing an old dark jacket
with loose shoulder lines, not writing, both hands resting motionless on the desk,
three objects laid out on the desk lit by the lamp as the only bright area, from left to right:
first a folded pale blue paper star with five points and deep crisp creases, one of its points worn
through and frayed pale as if touched by fingers many times,
second a dark hardcover diary lying closed with a small pale blank label area at the lower right of
the cover, that label left completely empty with no text,
third a small square photograph blurred as if seen through mist, only two human silhouettes standing
side by side under a starry sky, faces completely illegible with no facial features drawn,
one of them with a dark jacket draped loosely over the shoulders as an indistinct dark shape with no
readable color,
the lamplight reaching only the desk and one of his shoulders, the rest of the room in dark color
blocks, dark window with a few faint stars, warm amber desk against cold dark room,
quiet and restrained with a trace of confusion, no sad expression or gesture, no face,
horizontal 3:2, no text watermark, no photographic texture
```

### ★ 后期手填的字

日记封面标签区填：**「给未来的你」**（`源.cpp:540`）
**写得比他的笔迹秀气** —— `541` 明写「不是我的字」，玩家读完全作才知道是谁写的。
用细一点的手写体，不要用印刷体。

---

### CG P-3　★★★ 极远景 · 二十五光年 · 书房缩成一个亮着的小窗
> 锚点 `588`–`613`（第 20–24 段：织女星 → 二十五光年 → "这是一个从星光始,由回响终的故事"）
> 景别：**极远景（全册唯一）**　氛围：把人从画面里拿掉　**无人** · 横版
> **★★★ 全作的开场定音。**

源码依据：
> `588` 窗外,一颗星比其它星都亮。／`589` 那是天琴座的 α 星。中文的名字叫「织女」。
> `590` 距离地球二十五光年。／`591` ——我此刻看见的它,／`592` 是二十五年前的、它。
> `593` 二十五年前我三岁。／`594` 她也三岁。／`596` 我们住在同一座城市的两条不同的街上。／`597` **那颗光已经在路上了。**
> `608` 一颗星星。一本书。一件外套。／`612` **这是一个从星光始,由回响终的故事。**／`613` 现在,可以开始了。

### ⚠⚠ 这张必须换机位，否则和三张已有的图撞车

项目里已经有三张"窗前 / 桌前 + 织女星"：

| 已有 | 内容 |
|---|---|
| `0-3B`（序幕册） | 主角坐在桌前背影 |
| `5-3B`（序幕册） | 主角站在窗前抬头 |
| `A-2`（结局A册） | 窗前抬头看织女星 |

**再画一张"窗前抬头"就是第四张同类图。** 所以 `P-3` 走一个别处都没有的机位：
**从屋外很远的地方看** —— 星空占满画面上方五分之四，整栋楼压成画面底部一小条剪影，
那间书房只是剪影上**一个亮着的小方块**。

这样做的三个理由：
1. `590` 写的是**二十五光年**。只有把镜头拉到楼外，这个尺度才真的进画面；
2. `597`「那颗光已经在路上了」—— 光的旅程要有距离才画得出来；
3. 引言结尾是作者**交出人称**（`509` 我会说「你」）。人从画面里消失，正好是这件事的图像版。

中文：
```
动漫风格的场景插画，galgame 视觉小说 CG，手绘赛璐璐上色，干净的线稿，
平面化的色块，柔和的动漫光影。不是照片，不是3D渲染，不是写实风格。

画面内容：
极远景，夏天的深夜，从很远的屋外往回看这座城市。画面里没有人。
画面上方五分之四全部是夜空：深蓝到近黑的渐变，很多很多细小的星点，
银河淡淡地斜过去一道。
偏西南方向有一颗明显比其它星都亮的白色星，画出四道细长的十字光芒，
它的位置在画面上方偏右，是全图最亮的一点。
从这颗星向着画面下方，画一道极淡、极细、几乎看不见的光的痕迹，
像它的光正在走过来的路上 —— 要非常克制，几乎只是一层淡色的渐变，
不要画成流星，不要画成光柱，不要画成箭头。
画面最下方五分之一是城市的剪影：低矮的居民楼，纯黑的色块，
只有轮廓，没有细节。整排楼几乎全是黑的、没有灯。
在这排剪影中间偏左的位置，有唯一一个亮着的窗口 ——
一个很小的暖黄色方块，小到只有几个像素那么大的感觉，
是整个下半部分唯一的暖色。窗口里看不清任何东西。
冷蓝的夜空 + 纯黑的城市 + 一点暖黄。开阔、安静、有距离感。
不要月亮，不要云，不要文字。

横版 3:2。画面里不出现人的脸。不要文字水印，不要照片质感和真实材质反射。
```
英文 tag 版：
```
anime style illustration, galgame visual novel CG, hand-drawn cel shading, clean lineart,
flat color, soft anime lighting, NOT a photograph, NOT 3d render, NOT realistic,
extreme wide shot, deep summer night seen from far outside looking back at the city,
NO people in the frame, the upper four fifths of the frame entirely night sky, a deep blue to near
black gradient with a great many fine stars and the milky way faint and diagonal,
one white star toward the southwest distinctly brighter than all others with four fine long cross
diffraction spikes, positioned upper right, the brightest point in the image,
from that star toward the lower part of the frame an extremely faint barely visible trace of light as
if its light were still traveling toward the viewer, very restrained, almost only a pale gradient,
NOT a meteor NOT a light beam NOT an arrow,
the lowest fifth of the frame a city silhouette of low residential buildings as pure black color
blocks with outlines only and no detail, almost all of them unlit,
a single lit window slightly left of center in that silhouette, a very small warm amber square,
tiny, the only warm color in the lower half, nothing readable inside the window,
cold blue sky plus pure black city plus one point of warm amber,
open quiet and full of distance, no moon no clouds no text, no face,
horizontal 3:2, no text watermark, no photographic texture
```

### ★ 这张在 Ren'Py 里的用法建议

`P-3` 是引言最后一张，接着就是 `613`「现在,可以开始了。」
建议**在这张图上停久一点**（`delay` 给到 2000ms 以上），然后直接 `dissolve` 进序幕的第一张。
那个亮着的小窗 → 序幕的书房内景，等于镜头推进去。这个转场不用写台词，玩家自己会懂。

---

## 五、生成完之后

### 文件名（沿用现有约定，纯 ASCII）

```
E:\《星空回响》\cg\
  P1.png  P2.png  P3.png
```

Ren'Py 会自动把 `P1.png` 认成 `image p1`，`scene p1 with dissolve` 直接可用。

### 跑图顺序

1. 新开对话 → 跑 `P-1` → **同一对话接着跑 `P-2`** → 关掉（同机位，必须连着）
2. 新开对话 → 跑 `P-3`（机位完全不同，单独跑）

`P-1` 跑完之后，`P-2` 就这么追：

> 「保持完全相同的机位、焦距和构图，书桌、台灯、窗户、椅子的位置全部不变。现在椅子上坐一个男生的背影，看不见脸；桌上摊开三样东西：一颗磨破一个角的浅蓝色折纸星星、一本合着的深色日记本（封面标签留白）、一张糊得看不清脸的照片。」

### 全项目 CG 总数

| 批次 | 张数 | 状态 |
|---|---|---|
| 主手册 第一～四章 | 24 | ✅ 已完成（在 `E:\《星空回响》\cg\`） |
| **引言（本册）** | **3** | ⬜ 待生成 |
| 序幕 + 第五层 | 12 | ⬜ 待生成 |
| 结局 A | 18 | ⬜ 待生成 |
| 结局 B / C | 0 | ✅ 定案不做 |
| **合计** | **57** | 24 / 57 |

### 待办

- [ ] `P-2` 日记封面「给未来的你」后期手填（**比他的笔迹秀气**，细手写体）
- [ ] ★ 改 `CG生成提示词_序幕与第五层.md:116`–`117` 的模板：还是旧的摄影语言版，那 12 张跑之前必须改（本册第三节有正确版本）
- [ ] ★ 改 `CG生成提示词_序幕与第五层.md` 第三节：藏青色外套的"甲/乙/丙"三选一可以撤掉了，`源.cpp:532` 就是出处，答案是甲
- [ ] ★ 删 `CG生成提示词.md` 修订说明里"藏青色外套是编的、已修掉"那条 —— 它在源码里
- [ ] 主手册那 8 张竖版 + 1 张方图裁成 3:2，让 57 张统一比例
- [ ] `P-3` → 序幕第一张的 `dissolve` 转场（亮着的小窗推进屋内）

---

## 六、顺手记下来的两处源码问题（**没改，等你定**）

读 `mujian_sanwen[0]` 时看到的，都不影响出图，只是记下来：

| 行 | 内容 | 说明 |
|---|---|---|
| `592` | 「是二十五年前的、它。」 | 「的、它」中间那个顿号很怪。如果是想强调"它"，也许「是二十五年前的它」或者「是二十五年前的、那颗它」更顺。**但这可能是你故意的停顿**，所以没动 |
| `608` | 「一颗星星。一本书。一件外套。」 | 全段唯一用**句号**排比的地方，其余段落都是逗号。和 `529`–`531` 的「星星／日记本／照片」对不上 —— 这里是「书」和「外套」。**外套在照片里，不在桌上**，所以这句是把三件物证换了一种数法。如果是有意的，就不用改 |

---

## 七、改动记录

- **2026-08-10**　建册。引言 3 张（`P-1` 空屋 / `P-2` 三样东西 + 背影 / `P-3` 极远景星空）。
  分割点按 `源.cpp:1149 gaoliang()` 的点亮时序定（第 4 页出人、8–10 页三样东西依次亮）。
  `P-3` 刻意换成极远景，避开已有的 `0-3B` / `5-3B` / `A-2` 三张「窗前抬头」。
- **2026-08-10**　★ 藏青色外套矛盾**解除**：`源.cpp:532` 就是它的出处，序幕册第三节的三选一取「甲（保留）」，主手册修订说明里判它是编造的那条是错的。
