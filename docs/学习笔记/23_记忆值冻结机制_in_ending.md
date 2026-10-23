============================================================
学习笔记 23 · 记忆值冻结机制(in_ending)
============================================================

【时间】2026-07-30
【学到什么】
  · 怎么让记忆值在结局中"不扣分 + 不显示 UI"
  · 一个全局变量 + 4 处检查就够

============================================================
【目标】
============================================================

  玩家进入结局后:
    · 记忆值不再往下掉
    · 右上角"记忆值 100/100"不显示
    · 玩家专心看结局

  不能直接:
    · memory_zhi = 999999 → 显示丑
    · 清掉 UI 区 → 屏幕闪

============================================================
【机制 · 1 个开关 + 4 处检查】
============================================================

  // 1. 全局变量
  int in_ending = 0;

  // 2. now_time() 开头
  if (in_ending) return 0;
  // 后续原本的扣分逻辑
  int flag = 0;
  if (memory_zhi <= 0) return 0;
  if (time_top > 0) return 0;
  DWORD temp = GetTickCount();
  while (temp - memory_last >= memory_time && memory_zhi > 0) {
      memory_zhi--;
      memory_last = memory_last + memory_time;
      flag = 1;
  }
  if (memory_zhi == 0) return -1;
  return flag;

  // 3. draw_memory_secene() 开头
  if (in_ending) return;
  // 后续原本的 UI 绘制
  gotoxy(62, 0);
  setColor(memory_clorur(memory_zhi));
  // ...

  // 4. chongzhi_game() 里
  in_ending = 0;  // 回主菜单时清

  // 5. 每个结局函数第一行
  in_ending = 1;  // 冻结

============================================================
【运行流程】
============================================================

  游戏中:
    now_time() 每帧被调
    in_ending = 0
    走原本的扣分逻辑
    draw_memory_secene() 每帧被调
    走原本的 UI 绘制

  玩家进入结局:
    in_ending = 1
    now_time() 第一行直接 return 0 → 不扣分
    draw_memory_secene() 第一行直接 return → 不画 UI

  结局播完:
    return_to_titile() 调 chongzhi_game()
    in_ending 重置为 0
    回主菜单后一切正常

============================================================
【为什么不在结局里 push/pop_stack_time】
============================================================

  你之前的独白函数 play_jiejju_conver 里:
    push_stack_time();
    delay_with_Chinese(text, delay1);
    Sleep(delay2);
    ...
    pop_stack_time();

  这是用栈机制暂停扣分
  但:
    · 每个独白都要 push/pop
    · push/pop 嵌套多了容易错(看 bug 10)
    · in_ending 一次性解决 · 简单

  推荐:
    · 结局里把 push/pop 全删了
    · 只用 in_ending
    · 省事 + 不会嵌套错

============================================================
【对应源码位置】
============================================================

  int in_ending = 0;          // 全局 · 大概在第 97 行附近

  int now_time() {             // 138 行附近
      if (in_ending) return 0;
      // ...
  }

  void draw_memory_secene() {  // 105 行附近
      if (in_ending) return;
      // ...
  }

  void chongzhi_game() {       // 1405 行附近
      memory_zhi = 100;
      time_top = 0;
      memory_last = 0;
      in_ending = 0;            // 已加
      // ...
  }

============================================================
【待加(play_jieju_C 还没写)】
============================================================

  void play_jieju_C() {
      in_ending = 1;     // ← 待加

      play_C_item();
      Sleep(1000);

      draw_ending_room(2);
      draw_the_ending_C_room(0);
      // ... 独白 ...

      Sleep(5000);
      return_to_titile(2);
  }

  play_jieju_A 和 play_jieju_B 也都要在第一行加 in_ending = 1

============================================================
