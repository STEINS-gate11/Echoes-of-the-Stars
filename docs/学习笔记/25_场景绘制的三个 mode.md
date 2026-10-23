============================================================
学习笔记 25 · 场景绘制的三个 mode
============================================================

【时间】2026-07-30
【学到什么】
  · 怎么用结构体 + 数组管理三套颜色
  · 一个 draw_ending_room(mode) 函数搞定三结局共用场景
  · 保留玩家代码风格

============================================================
【目标】
============================================================

  A/B/C 三个结局都从书房开始:
    · A 暖色(白+金+深黄)
    · B 冷色(灰)
    · C 暗色(极暗 · 唯一亮的台灯)

  共用一套绘制代码 · 靠 mode 参数切换颜色

============================================================
【颜色表(已写进源.cpp)】
============================================================

  struct ending_color {
      int star;          // 星轨 . ' *
      int vega;          // 织女星 ✦
      int window_frame;  // 窗框
      int wall;          // 书房外墙
      int desk_frame;    // 书桌框
      int shelf_frame;   // 书架框
      int shelf_book;    // 书架里的书
      int lamp;          // 台灯
      int desk_line;     // 桌面装饰线
      int player;        // 主角 @
      int curtain;       // 窗帘
      int carpet;        // 地毯
      int line;          // 独白分隔
      int mono_text;     // 独白文字
      int hint;          // 按键提示
  };

  ending_color ending_colors[3] = {
      { 11, 14,  11, 11,  6,  6,  6,  14,  6, 15,  4,  6,  8, 15,  8 },  // A
      {  8,  8,   8,  8,  7,  8,  8,   6,  8,  7,  7,  8,  8,  7,  8 },  // B
      {  1,  1,   8,  8,  8,  8,  8,   7,  8, 15,  1,  1,  8, 15,  8 }   // C
  };

============================================================
【绘制函数(已写进源.cpp)】
============================================================

  void draw_ending_room(int mode) {
      system("cls");
      ending_color c = ending_colors[mode];

      setColor(c.star);
      gotoxy(1, 0);  printemoji(L" .   '   *        .");
      gotoxy(1, 1);  printemoji(L"    .         *");
      gotoxy(1, 2);  printemoji(L" *      .              *");
      gotoxy(1, 3);  printemoji(L"          '");

      setColor(c.window_frame);
      gotoxy(29, 0);  printemoji(L"┌──────────┐");
      gotoxy(29, 1);  printemoji(L"│");
      gotoxy(29, 2);  printemoji(L"│");
      gotoxy(29, 3);  printemoji(L"│");

      setColor(c.star);
      gotoxy(31, 1);  printemoji(L".");
      gotoxy(33, 2);  printemoji(L".");
      gotoxy(31, 3);  printemoji(L"*");
      gotoxy(37, 3);  printemoji(L".");

      setColor(c.vega);
      gotoxy(35, 1);  printemoji(L"✦");

      // ... 等等
  }

============================================================
【关键点 1 · 结构体存颜色】
============================================================

  ending_color c = ending_colors[mode];
  setColor(c.star);   // 用结构体字段

  好处:
    · 一处改颜色,影响整个 mode
    · 三个 mode 切换清晰
    · 字段名有意义(star / vega / lamp / etc.)

============================================================
【关键点 2 · 三个 mode 的关键差异】
============================================================

  元素        A 暖色  B 冷色  C 暗色
  star        11(蓝) 8(灰)  1(极暗)
  vega        14(金) 8(灰)  1(极暗)
  lamp        14(金) 6(深黄) 7(灰白)
  player      15(白) 7(灰)  15(白)
  curtain     4(红) 7(灰)  1(极暗)
  carpet      6(黄) 8(灰)  1(极暗)
  desk_frame  6(黄) 7(灰)  8(灰)
  shelf_frame 6(黄) 8(灰)  8(灰)
  shelf_book  6(黄) 8(灰)  8(灰)

  C 的特别之处:
    · 玩家 @ 还是白 15
    · 但周围都极暗
    · 只有台灯亮(灰白 7)—— 唯一暖光
    · 呼应"台灯是最后熄的"主题

============================================================
【B/C 独有的元素】
============================================================

  draw_the_ending_B_room():
    · 茶印子 o(x=25 y=14)
    · 便利店灯 .(x=37 y=4)

  draw_the_ending_C_room(int if_youren):
    · 左上角小镜子(╔═══╗ ... ╚═══╝)
    · if_youren=0:显示 ?
    · if_youren=1:显示 @

  这两个函数不共用模式
  各自画各自的独有元素
  在 draw_ending_room 之后调用

============================================================
【街道/楼梯/天台(A 独有)】
============================================================

  draw_the_Ade_street():
    · system("cls") 开画
    · 不靠 mode 切换(只 A 有)

  draw_the_Ade_stair():
    · 同上

  draw_the_Ade_tiantai():
    · 复用 rooftop.txt
    · cur_chapter = 3; load_secene("rooftop.txt", ...);
    · 抹掉 A/B/C 拾取标记
    · 加织女星 + 主角 @

============================================================
【场景调用顺序】
============================================================

  A 结局:
    draw_ending_room(0)        // 书房暖色
    独白 1-9
    draw_the_Ade_street()      // 街道
    独白 10-11
    draw_the_Ade_stair()       // 楼梯
    独白 11 后半
    draw_the_Ade_tiantai()     // 天台
    独白 12-20

  B 结局:
    draw_ending_room(1)        // 书房冷色
    draw_the_ending_B_room()   // 加茶印子 + 便利店灯
    独白 1-7(全程书房)

  C 结局:
    play_C_item()              // 消散
    draw_ending_room(2)        // 书房暗色
    draw_the_ending_C_room(0) // 镜子显示 ?
    独白 1(停 3 秒 → 镜子变 @)
    draw_the_ending_C_room(1)
    独白 2-7(全程书房)

============================================================
【源码位置】
============================================================

  ending_color 结构在 1454 行附近
  ending_colors 数组紧接其后
  draw_ending_room 在 1465 行附近
  draw_the_ending_B_room 在 1532 行附近
  draw_the_ending_C_room 在 1537 行附近
  draw_the_Ade_street 在 1554 行附近
  draw_the_Ade_stair 在 1596 行附近
  draw_the_Ade_tiantai 在 1624 行附近

============================================================
