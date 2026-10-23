#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <wchar.h>
int cur_chapter = 0;

void gotoxy(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void hideCursor() {
	CONSOLE_CURSOR_INFO info = { 1, FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

char now_bgm[100]="";
void stop_bgm() {
	PlaySoundA(NULL, NULL, 0);
	memset(now_bgm, 0, sizeof(now_bgm));
}
void play_bgm(const char *file) {
	if (strcmp(now_bgm, file) == 0) {
		return;
	}
	if (PlaySoundA(file, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP) == FALSE) {
		memset(now_bgm, 0, sizeof(now_bgm));
		return;
	}
	strcpy(now_bgm, file);
}
const char* bgm_chapter[7] = {
		"bgm/hall.wav",
		"bgm/ch0.wav",
		"bgm/ch1.wav",
		"bgm/ch2.wav",
		"bgm/ch3.wav",
		"bgm/ch4.wav",
		"bgm/ch5_planetarium.wav"
};

void setColor(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct every_secene_color {
	char ch;
	int color;
};
every_secene_color chaptercolors[7][12] = {

	{ {'=', 8}, {'D', 14}, {0, 0} },


	{ {'.', 14},  {'\'', 14}, {'*', 14},
	  {'+', 6},   {'-', 6},   {'|', 6},
	  {'=', 6},
	  {'\\', 15}, {'/', 15},  {'_', 15},
	  {'O', 14},
	  {'~', 1} 
    },


	  { {'=', 6},   {'|', 6},
		{'+', 7},   {'-', 7},
		{'\\', 15}, {'/', 15}, {'_', 15},
		{'.', 8},   {'\'', 8},
		{'*', 14},
		{0, 0} },

	
		{ {'.', 15},  {'\'', 15},
		  {'*', 14},
		  {'=', 8},   {'[', 8},  {']', 8}, {'#', 8},
		  {'\\', 15}, {'/', 15}, {'_', 15},
		  {'|', 7},
		  {'~', 11} },

		
		  { {'=', 15},  {'+', 15},
			{'~', 11},
			{'|', 7},   {'-', 7},  {'[', 7}, {']', 7},
			{'.', 8},   {'_', 8},
			{'(', 15},  {')', 15},
			{'/', 8}
          },

		
			{ {'\\', 13}, {'|', 13}, {'/', 13},
			  {'*', 14},
			  {'+', 5},   {'-', 5},
			  {'.', 13},  {'\'', 13},
			  {'=', 5},
			  {'[', 15},  {']', 15},
			  {0, 0} 
            },

		
			  { {'*', 14},  {'.', 14}, {'\'', 14},
				{'/', 14},  {'\\', 14},
				{'+', 6},   {'-', 6},  {'|', 6},
				{'=', 6},
				{'O', 14},  {'_', 6},
				{'~', 14}
              }
};
int get_senece_color(char ch, int chapter) {
	if (chapter < 0 || chapter> 6) return 15;
	for (int i = 0; i <12; i++) {
		if (chaptercolors[chapter][i].ch == 0) return 15;
		if (chaptercolors[chapter][i].ch == ch) return chaptercolors[chapter][i].color;
	}
	return 15;
}

int memory_zhi = 100;
DWORD memory_time = 8000;
DWORD memory_last = 0;
DWORD time_zone[15];
int time_top = 0;
int in_ending = 0;

int memory_clorur(int x) {
	if (x >= 60) return 15;
	if (x >= 30) return 14;
	return 12;
}
void draw_memory_secene() {
	if (in_ending)return;
	gotoxy(62, 0);
	setColor(memory_clorur(memory_zhi));
	if (memory_zhi >= 60) {
		printf("记忆值 %03d / 100      ", memory_zhi);
	}
	else if (memory_zhi >= 30) {
		printf("记忆值 %03d / 100 · 模糊", memory_zhi);
	}
	else {
		printf("记忆值 %03d / 100 · 消散", memory_zhi);
	}
	setColor(15);
}
void create_time() {
	memory_last = GetTickCount();
	time_top = 0;
	memory_zhi = 100;
}
void push_stack_time() {
	if (time_top < 15) {
		time_zone[time_top] = GetTickCount();
		time_top++;
	}
}
void pop_stack_time() {
	if (time_top <= 0) return;
	time_top--;
	if (time_top == 0) {
		DWORD temp = GetTickCount() - time_zone[0];
		memory_last = memory_last + temp;
	}
}
int now_time() {
	if (in_ending)return 0;
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
}

const char* the_chapter_Walls[7] = {
	  "=DFT",      
	  "=",        
	  "=",        
	  "=[]#",     
	  "=",        
	  "",
	  "="
};
int checkwall(char c) {
	if (cur_chapter < 0 || cur_chapter>6) return 0;
	if (c == 'A' || c == 'B' || c == 'C') return 1;
	const char* curr = the_chapter_Walls[cur_chapter];
	for (int i = 0; curr[i] != '\0'; i++) {
		if (curr[i] == c) return 1;
	}
	return 0;
}

int isreact(int x, int y, int px, int py) {
	int dx = abs(x - px);
	int dy = abs(y - py);
	return (dx + dy == 1);
}

void clear(int line) {
	gotoxy(0, line);
	for (int i = 0; i < 79; i++) {
		printf(" ");
	}
}

void clearbutter() {
	while (_kbhit()) {
		_getch();
	}
}

void delay_with_Chinese(const wchar_t* text, int times) {
	HANDLE print = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; text[i] != L'\0'; i++) {
	     DWORD wrriten;
		 WriteConsoleW(print, &text[i], 1, &wrriten, NULL);
		 Sleep(times);
	}
}

void draw_dialog(int x, int y, int length, int width) {
	gotoxy(x, y);
	setColor(8);
	for(int i = 0; i < length; i++) {
		printf("-");
	}
	gotoxy(x, y + width - 1);
	for(int i=0;i<length; i++) {
		printf("-");
	}
}

void cleararray(int x, int y) {
	for (int i = x; i < x + y; i++) {
		clear(i);	
	}
}

void printemoji(const wchar_t* text) {
	HANDLE print = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD wrriten;
	int len = 0;
	while (text[len] != L'\0') {
		len++;
	}
	WriteConsoleW(print, text, len, &wrriten, NULL);
}

struct inner_star {
	int x;
	int y;
	int diff;
};
void begin_title() {
	int liu_xing_tai = 0;
	int liu_xing_count = 0;
	int liu_xing_jishi = 10;
	inner_star inner_stars[6] = {
		{ 12, 7,  0 },
		{ 45, 8,  2 },
		{ 20, 11, 1 },
		{ 50, 14, 3 },
		{ 35, 17, 4 },
		{ 60, 18, 2 },
	};
	char temp[25][80];
	FILE* fp = fopen("title.txt", "r");
	if (!fp) {
		printf("Failed to open title.txt\n");
		exit(0);
	}
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 25; i++) {
		if (fgets(temp[i], 80, fp) == NULL) break;
		int len = 0;
		while (temp[i][len] != '\n' && temp[i][len] != '\0') {
			len++;
		}
		temp[i][len] = '\0';
	}
	fclose(fp);
	system("cls");
	setColor(15);
	for (int y = 0; y < 25; y++) {
		gotoxy(0, y);
		printf("%s", temp[y]);
	}
	gotoxy(14, 5);  setColor(14); printemoji(L"★    星空回响    ★");
	gotoxy(14, 6);  setColor(6);  printemoji(L"Echoes of the Stars");
	gotoxy(9, 10);  setColor(6);  printemoji(L"一个关于星星、约定和告别的故事");
	gotoxy(14, 12); setColor(15); printemoji(L"[ 空格 ]   开始旅程");
	gotoxy(14, 13); setColor(15); printemoji(L"[   Q  ]   退出");
	gotoxy(9, 15);  setColor(8);  printemoji(L"献给每一个曾经抬头看星星的人");
	const wchar_t* jiyu[5] = {
		  L"如果你看到这个,说明你已经准备好了。",
		  L"星光走了 25 年,才到你眼睛里。",
		  L"有些星星,在夜空里,也在你记得的地方。",
		  L"她答应过你——星星还会在这里。",
		  L"一颗折了又拆的纸星星。",
	};
	int jiyu_shijain = ((int)time(NULL)) % 5;
	gotoxy(10, 16);
	setColor(6);
	printemoji(jiyu[jiyu_shijain]);
	int xunhuannumber = 0;
	int color_total[5] = { 8,7,6,7,8 };
	setColor(8);
	gotoxy(64, 4);
	printemoji(L".");
	gotoxy(66, 5);
	printemoji(L".");
	gotoxy(68, 6); 
	printemoji(L"✦");
	gotoxy(66, 7); 
	printemoji(L".");
	gotoxy(70, 8); 
	printemoji(L".");
	while (1) {
		int number = xunhuannumber % 5;
		gotoxy(0, 0); setColor(color_total[number]);
		printemoji(L"   *    .    '    *    .    '    *    .    '   ");
		gotoxy(0, 1); setColor(color_total[number]);
		printemoji(L"     .    *    '    .    *    '    .    *      ");
		gotoxy(0, 20); setColor(color_total[number]);
		printemoji(L"     .    *    '    .    *    '    .    *      ");
		for (int i = 0; i < 6; i++) {
			int idx = (xunhuannumber + inner_stars[i].diff)%5;
			gotoxy(inner_stars[i].x, inner_stars[i].y);
			setColor(color_total[idx]);
			printemoji(L"*");
		}
		if (liu_xing_tai == 0) {
			liu_xing_jishi--;
			if (liu_xing_jishi <= 0) {
				liu_xing_tai = 1;
				liu_xing_count = 0;
				liu_xing_jishi = 10 + (xunhuannumber % 8);
			}
		}
		if (liu_xing_tai) {
			int x = 70 - liu_xing_count * 4;
			int y = 3 + liu_xing_count;
				if (x > 40&& y < 9) {
					if (liu_xing_count > 0) {
						int px = 70 - (liu_xing_count - 1) * 4;
						int py = 2 + liu_xing_count;
						gotoxy(px, py);
						printemoji(L" ");
					}
					gotoxy(x, y);
					setColor(14); 
					printemoji(L"✦");
					liu_xing_count++;
				}
				else {
					if (liu_xing_count > 0) {
						int px = 70 - (liu_xing_count - 1) * 4;
						int py = 2 + liu_xing_count;
						gotoxy(px, py);
						printemoji(L" ");
					}
					liu_xing_tai = 0;
				}
		}
		xunhuannumber++;
		clearbutter();
		for (int i = 0; i < 10; i++) {
			if (_kbhit()) {
				char c = _getch();
				if (c == ' ') return;
				if (c == 'q') { 
					system("cls");
				    exit(0); 
				}
			}
			Sleep(50);
		}
	}
}

void show_the_big_zhi() {
	system("cls");
	Sleep(500);
	gotoxy(10, 7);
	setColor(8);
	printemoji(L".    ✦    .    ·    .    ✦    .    ·    .    ✦    .");
	gotoxy(10, 13);
	setColor(8);
	printemoji(L"·    .    ✦    .    ·    ✦    .    ·    ✦    .    ·");
	const wchar_t* temp[4] = { L"星", L"空", L"回", L"响" };
	int zhi_number[4] = { 18, 26, 34, 42 };
	for (int i = 0; i < 4; i++) {
		setColor(14);
		gotoxy(zhi_number[i], 10);
		printemoji(temp[i]);
		Sleep(400);
		setColor(6);
		gotoxy(zhi_number[i], 10);
		printemoji(temp[i]);
		Sleep(400);
		setColor(14);
		gotoxy(zhi_number[i], 10);
		printemoji(temp[i]);
		Sleep(400);
	}
	Sleep(400);
	for (int i = 0; i < 4; i++) {
		setColor(14);
		gotoxy(zhi_number[i], 10);
		printemoji(temp[i]);
	}
	gotoxy(4, 4);   setColor(14); printemoji(L"✦"); Sleep(100);
	gotoxy(74, 4);  setColor(14); printemoji(L"✦"); Sleep(100);
	gotoxy(4, 16);  setColor(14); printemoji(L"✦"); Sleep(100);
	gotoxy(74, 16); setColor(14); printemoji(L"✦"); Sleep(500);
	gotoxy(20, 14);
	setColor(6);
	delay_with_Chinese(L"天琴座 α · 距离地球二十五光年", 80);
	Sleep(1000);
	gotoxy(15, 15);
	setColor(8);
	delay_with_Chinese(L"———— 一个关于星星、约定和告别的故事 ————", 60);
	Sleep(1000);
	gotoxy(30, 17);
	setColor(8);
	printemoji(L"·   ·   ·   ·   ·");
	Sleep(500);
	for (int i = 0; i < 8; i++) {
		int x = 72 - i * 8;
		int y = 3 +2 * i;
		if (i > 0) {
			int px = 72 - (i - 1) * 8;
			int py = 1 +2 * i;
			gotoxy(px, py);
			printemoji(L" ");
		}
		gotoxy(x, y);
		setColor(14);
		printemoji(L"✦");                               
		Sleep(80);
	}
	gotoxy(16, 17);
	printemoji(L" ");                               
	Sleep(500);
	int color_number[5] = { 8,7,6,7,8 };
	int xunhuannumber = 0;
	clearbutter();
	while (1) {
		gotoxy(28, 21);
		setColor(color_number[xunhuannumber % 5]);
		printemoji(L"[ 星光回响之中 · 按空格继续 ]");
		xunhuannumber++;
		for (int i = 0; i < 10; i++) {
			if (_kbhit()) {
				char c = _getch();
				if (c == ' ') { 
					system("cls"); return;
				}
			}
			Sleep(50);
		}
	}
}

int pangbai_alredy[7] = { 0,0,0,0,0,0,0 };
const wchar_t* mujian_secene[20] = {
	L"                                                ",
	L"    .    .    .    .   ✦    .    .    .    .   ",
	L"                                                ",
	L"                                                ",
	L"               +----------------+               ",
	L"               |                |               ",
	L"               |       O        |               ",
	L"               |      /|\\       |               ",
	L"   +-----------+----------------+-----------+   ",
	L"                                                ",
	L"         ⭐         📖         🖼               ",
	L"                                                ",
	L"   +----------------------------------------+   ",
	L"   ==========================================   ",
	L"                                                ",
	L"                                                ",
	L"                                                ",
	L"                                                ",
	L"                                                ",
	L"                                                ",
};
const wchar_t* mujian_sanwen[7][25][12] = {

	{
		{ L"向着星空、向着一个我已经叫不出名字的人——",
		  L"我写下了这个故事。", NULL },
		{ L"这是一个不成熟的故事,它有很多缺点。",
		  L"人物也许太薄,情节也许太慢,",
		  L"星星与星星之间的距离,",
		  L"也许远得让人放弃走完。", NULL },
		{ L"可我还是想把它写下来——",
		  L"因为在很多个不睡的夜晚,",
		  L"是这个故事里的那个「她」,",
		  L"让我愿意再多留下来一会儿。", NULL },
		{ L"下面的故事里,我会说「你」。",
		  L"",
		  L"我试过说「我」。",
		  L"写到第三页就写不下去了。", NULL },
		{ L"台灯是我自己拧开的,我记得。",
		  L"扭开关的时候「咔哒」一声,",
		  L"比我印象里应该有的声音要轻。",
		  L"灯泡是钨丝的,",
		  L"光落在桌面上像倒了一小滩温水。", NULL },
		{ L"椅子会响。",
		  L"",
		  L"有一晚我数过。四十一次。",
		  L"数到第二十几次的时候我就知道这没有意义,",
		  L"可是我还是数完了。", NULL },
		{ L"窗户关不严。",
		  L"我一直没有修。",
		  L"",
		  L"去年冬天冷的时候想过要修,",
		  L"后来天暖了就算了。", NULL },
		{ L"桌上有三样东西。",
		  L"一颗折纸星星,一个角磨破了。",
		  L"一本没有写过一个字的日记本。",
		  L"一张模糊的照片——",
		  L"其中一个人的肩上,披着藏青色的外套。", NULL },
		{ L"折纸星星是浅蓝色的。",
		  L"每一道折痕都压得很实。",
		  L"",
		  L"我的手指知道怎么把它拆开。",
		  L"从两端捏松,底面掀一层,背面拉一层。",
		  L"",
		  L"我没有拆。", NULL },
		{ L"日记本封面上写着「给未来的你」。",
		  L"不是我的字。",
		  L"",
		  L"我翻开过三次。",
		  L"三次都停在第一页。", NULL },
		{ L"照片糊得像隔着一层雾。",
		  L"两个人的轮廓,在星空下并排站着。",
		  L"我看不清他们的脸。", NULL },
		{ L"抽屉最里面有一部手机。",
		  L"三年没开过机。电池早就没了。",
		  L"",
		  L"有时候我把它拿出来,",
		  L"翻过来,翻过去,",
		  L"然后屏幕朝下扣在桌上。", NULL },
		{ L"手机下面压着一叠信。",
		  L"信封都拆开过。",
		  L"里面的纸被人反复折过又展平,",
		  L"折痕的地方已经快断了。", NULL },
		{ L"楼下便利店的收银员换了一个。",
		  L"",
		  L"以前那个见我进门会点一下头。",
		  L"新来的这个不会。",
		  L"",
		  L"我也没跟她说过话。", NULL },
		{ L"街对面那家面馆关了。",
		  L"玻璃门上贴了一张纸,写着「店铺转让」。",
		  L"",
		  L"我从上礼拜开始看着那张纸。",
		  L"没有进去问过。", NULL },
		{ L"有一晚我去便利店买水。",
		  L"拿了两瓶。",
		  L"到收银台的时候才想起来,",
		  L"只需要一瓶。", NULL },
		{ L"我不喝挂耳了。",
		  L"一个人喝挂耳太麻烦。",
		  L"",
		  L"改喝速溶。",
		  L"她当年不喜欢我喝速溶。", NULL },
		{ L"——我不记得这三样东西,",
		  L"我是什么时候放上来的。",
		  L"可是我的手指知道该抓住灯座的哪一段。",
		  L"我的手记得这间屋子。",
		  L"可是我的脑子,不记得这间屋子里的任何一件事。", NULL },
		{ L"最奇怪的不是忘记。",
		  L"",
		  L"最奇怪的是我知道我忘了。",
		  L"我知道有一个人应该在这里,",
		  L"可是我说不出她的名字。", NULL },
		{ L"窗外,一颗星比其它星都亮。",
		  L"那是天琴座的 α 星。中文的名字叫「织女」。",
		  L"距离地球二十五光年。",
		  L"——我此刻看见的它,",
		  L"是二十五年前的、它。", NULL },
		{ L"二十五年前我三岁。",
		  L"她也三岁。",
		  L"",
		  L"我们住在同一座城市的两条不同的街上。",
		  L"那颗光已经在路上了。", NULL },
		{ L"那颗星也许早就熄了。",
		  L"天文系的同学说过,",
		  L"这种白色巨星在最后几百万年会变得更亮。",
		  L"",
		  L"我今晚还能看见它。", NULL },
		{ L"今晚有点热。",
		  L"风从那道关不严的缝里进来,",
		  L"带一点潮气,不冷。",
		  L"",
		  L"我坐了很久。", NULL },
		{ L"一颗星星。一本书。一件外套。",
		  L"一通没有接的电话。一次没有等到的第二天。",
		  L"一颗折了又拆的纸星星。",
		  L"",
		  L"这是一个从星光始,由回响终的故事。",
		  L"现在,可以开始了。", NULL },
		{ NULL }
	},

	{
		{ L"我睁开眼睛的时候,仍然是这间书房。",
		  L"台灯还亮着。桌上那三样东西都在原位。",
		  L"和我刚才离开的时候一模一样。", NULL },
		{ L"我不知道现在几点。",
		  L"墙上没有钟。",
		  L"手机在抽屉里,三年没开过机。",
		  L"",
		  L"天还黑着。",
		  L"--------", NULL },
		{ L"这间屋子我住了很多年。",
		  L"书架从地板顶到天花板,",
		  L"最上面两层放不下的书横着塞进去。",
		  L"",
		  L"我记得每一本书在哪。",
		  L"我不记得是谁替我排的。", NULL },
		{ L"台灯下方的桌面上有一个印子。",
		  L"深色的,圆的,大概杯底那么大。",
		  L"",
		  L"是热水杯放久了留下来的。",
		  L"我没有擦过它。", NULL },
		{ L"我伸手拿起那颗折纸星星,",
		  L"放在掌心里。",
		  L"它比我想的软——",
		  L"像是被人一次又一次拆开过、又折回去,",
		  L"纸的纤维已经软化了。", NULL },
		{ L"星星有一个角磨破了。",
		  L"不是撕的,是摸的——",
		  L"被人反复捏过同一个地方。",
		  L"",
		  L"我把它翻过来看了看背面。",
		  L"背面什么都没有。", NULL },
		{ L"我翻开那本空白日记本。",
		  L"翻到大约第二十页的时候,",
		  L"一张薄薄的纸条从书页里滑了出来。", NULL },
		{ L"上面是铅笔字,非常轻,",
		  L"像是写字的人不希望被读到——",
		  L"",
		  L"「如果你看到这张纸条,说明你已经忘了。",
		  L" 别着急。你只是需要重新想起。」", NULL },
		{ L"是铅笔字。不是钢笔。",
		  L"",
		  L"我在笔筒里找了一下,",
		  L"里面有三支铅笔,都削好了。",
		  L"",
		  L"我不记得是我削的。", NULL },
		{ L"我又把相框拿起来,凑到台灯下。",
		  L"两个人的轮廓,在星空下并排站着。",
		  L"糊得像是隔着一层雾。",
		  L"——其中一个人的肩上,",
		  L"披着一件藏青色的外套。", NULL },
		{ L"藏青色的。",
		  L"",
		  L"我衣柜里也有一件藏青色的外套。",
		  L"挂在最外面那一格。",
		  L"",
		  L"我没有去比对。", NULL },
		{ L"我把三样东西都放回了原位,",
		  L"然后坐着。",
		  L"",
		  L"坐了大概二十分钟。",
		  L"什么都没有想起来。", NULL },
		{ L"窗外的街空着。",
		  L"路灯有一盏坏了,上礼拜就坏了。",
		  L"",
		  L"楼下便利店的灯还亮着。",
		  L"收银台后面有人,低着头。", NULL },
		{ L"我把纸条重新夹回日记本。",
		  L"相框放回原位。",
		  L"折纸星星也放回原位。",
		  L"",
		  L"——好。我准备好了。", NULL },
		{ NULL }
	},

	{
		{ L"我又坐回了桌前。",
		  L"指尖擦过桌面,扫到了一张薄薄的东西——",
		  L"一张便签,正方形的,浅黄色的,",
		  L"被压在日记本底下、只露出一个角。", NULL },
		{ L"我把它抽了出来。",
		  L"上面是铅笔字,非常轻——",
		  L"",
		  L"「下周三,天文台开放夜。",
		  L" 一起来吗?」", NULL },
		{ L"[注] 那一年我大一。",
		  L"我们学校的天文台在西南区的小土丘顶上,",
		  L"每周三晚上向天文爱好者协会开放。",
		  L"我是协会成员——",
		  L"可我并不记得,那年下周三我到底去没去。", NULL },
		{ L"那个「吗」字,",
		  L"最后一笔向下撇得比常规多了一点。",
		  L"像是问出这句话的人在犹豫要不要收笔。",
		  L"——她也许是那种,",
		  L"把话已经写完了、还要再回头看一眼的人。", NULL },
		{ L"我把便签翻过来。",
		  L"背面什么都没有。",
		  L"",
		  L"只有一点点铅笔的印子透过来,",
		  L"是正面那几个字的反面。", NULL },
		{ L"[注] 图书馆三楼靠窗有几张长桌。",
		  L"第二排那个位置,下午三点以后有太阳。",
		  L"",
		  L"那个位置很难占到。",
		  L"我不记得我占到过几次。", NULL },
		{ L"那本书叫《恒星与星系》。",
		  L"第三版,精装,很厚。",
		  L"",
		  L"借书卡上盖过很多次章。",
		  L"最后一次归还日期是那一年的十月八号。",
		  L"",
		  L"不是我还的。", NULL },
		{ L"有一次我从外面买了两杯咖啡回来,",
		  L"放在桌上。",
		  L"",
		  L"一杯喝了。",
		  L"一杯没有。",
		  L"",
		  L"等我想起来的时候已经凉了。", NULL },
		{ L"我又低头看了看桌上那颗折纸星星。",
		  L"——我第一次学会怎么折星星,是大一那年。",
		  L"那不是我教自己的。",
		  L"",
		  L"[注] 窗外琴声是萨蒂的《玄秘曲第一号》。",
		  L"没有小节线,也没有拍号——",
		  L"弹的人自己决定,这一小节应该有多慢。", NULL },
		{ L"我不记得她的声音。",
		  L"",
		  L"我记得她说过的一些话,",
		  L"可是那些话在我脑子里,",
		  L"是我自己的声音在说。", NULL },
		{ L"[注] 图书馆晚上十点闭馆。",
		  L"九点五十开始放音乐,",
		  L"是很老的一首钢琴曲,每天都一样。",
		  L"",
		  L"我听了四年。",
		  L"一直没有查过那首曲子叫什么。", NULL },
		{ L"我记得那张桌子。",
		  L"虽然我并不记得,",
		  L"我什么时候在那张桌子上,见过什么人。",
		  L"",
		  L"——好。我去还那本书。", NULL },
		{ NULL }
	},

	{
		{ L"我把手指搭在了桌上那台小小的望远镜的镜筒上。",
		  L"那是我自己的那一台——",
		  L"一个 76 毫米口径的入门牛反。",
		  L"占了桌面靠窗那一角。", NULL },
		{ L"[注] 目镜——她当年替我买的,",
		  L"用的是她那个学期助学金的钱。",
		  L"她说过一句话:",
		  L"「你这个专业,怎么可以没有一台自己的望远镜。」",
		  L"她不解释,也不让我道谢。", NULL },
		{ L"我用手指擦了一下镜筒。",
		  L"指腹上有一层灰。",
		  L"",
		  L"三年了。",
		  L"我没有用过它。", NULL },
		{ L"我记得那栋楼——教学楼 3 号楼,八层。",
		  L"钥匙在电工班的老师那里,",
		  L"可她不知道从哪里搞到过一副复制的。",
		  L"「你陪我上去看看。」——一句话,说完就走。",
		  L"她说话总是那样——不多不少的字。", NULL },
		{ L"[注] 3 号楼没有电梯。",
		  L"从一楼到八层,一百二十六级。",
		  L"",
		  L"她走得比我快。她从来不看脚下。",
		  L"",
		  L"每次到平台的时候她会停下来等我。", NULL },
		{ L"我们那时候会带一张野餐垫,",
		  L"铺在东北角、离栏杆一米远的地方。",
		  L"八月的织女星,就在那个方向。",
		  L"",
		  L"[注] 天台正中的那台望远镜,",
		  L"镜筒的侧面刻着两个字母。",
		  L"一个是她的,一个是我的。", NULL },
		{ L"那张拍立得是她拍的。",
		  L"她把相机举得很高,手伸得很直。",
		  L"",
		  L"照片下面那一条白边上写了一个日期,",
		  L"墨水糊了,只能看出是八月。", NULL },
		{ L"耳机是有线的。",
		  L"一只塞给她,一只我自己戴。",
		  L"",
		  L"线不够长,所以我们得靠得很近。",
		  L"",
		  L"我不记得那是谁的耳机。", NULL },
		{ L"——我还记得她那天说了一句像玩笑的话:",
		  L"「如果有一天我们不在一起了,",
		  L" 星星还会在这里。」",
		  L"",
		  L"我以为她说的是星星。",
		  L"——可是此刻我知道,她说的从来都不是星星。", NULL },
		{ L"[注] 那天风很大,",
		  L"把野餐垫的一角掀起来了。",
		  L"",
		  L"她压了一块砖在上面。",
		  L"",
		  L"她说她最喜欢这种风。", NULL },
		{ L"我们从来不看时间。",
		  L"",
		  L"有一次下楼的时候楼道的灯已经灭了,",
		  L"我们摸着扶手一级一级下来。",
		  L"",
		  L"她在前面。",
		  L"她说别怕,我数着呢。", NULL },
		{ L"她说过,那首歌像星星一样温柔。",
		  L"可我并不记得,那首歌叫什么。",
		  L"",
		  L"——好。我上去看她。", NULL },
		{ NULL }
	},

	{
		{ L"我不想想起下面这一段。",
		  L"",
		  L"我坐在桌前很久,什么都没做。",
		  L"手放在桌面上,什么都没拿。", NULL },
		{ L"七月十四号。",
		  L"",
		  L"星期几我不记得了。",
		  L"那天下不下雨我也不记得。",
		  L"",
		  L"我只记得日期。", NULL },
		{ L"[注] 我的手机在书房抽屉的最里面。",
		  L"已经三年没有开过机。",
		  L"那一天,我在开会。",
		  L"手机在我裤子口袋里震动——", NULL },
		{ L"[注] 那是一个项目复盘会。",
		  L"下午两点开始,会议室在六楼。",
		  L"",
		  L"讲了什么我一点都不记得。",
		  L"",
		  L"我记得我坐在靠门的位置。",
		  L"我记得空调很冷。", NULL },
		{ L"第一次的时候,我把它翻过去,屏幕朝下。",
		  L"第五次的时候,我按了静音。",
		  L"第十次的时候,我把它放进了包里。",
		  L"",
		  L"第十七次已经是晚上了。", NULL },
		{ L"第十七次之后就没有了。",
		  L"",
		  L"那天晚上我回家吃了饭,洗了澡,",
		  L"看了一会儿手机上的新闻。",
		  L"",
		  L"我告诉自己:明天再回去。", NULL },
		{ L"我伸手把手机从抽屉里拿了出来。",
		  L"它是黑的。三年了,电池早就没了。",
		  L"我把它翻过来,屏幕朝下,扣在了桌面上。",
		  L"",
		  L"——就像那一天。", NULL },
		{ L"我盯着这个动作看了很久,",
		  L"然后我把手机重新翻了回来。",
		  L"",
		  L"屏幕依然是黑的。",
		  L"可我知道,第一次亮起来的那一瞬间——",
		  L"    未接来电 17。",
		  L"    语音留言 1。", NULL },
		{ L"语音留言 1。",
		  L"",
		  L"三年了,我没有点开过。",
		  L"",
		  L"我怕一旦听了,",
		  L"就再也没有办法假装她只是出了一趟远门。", NULL },
		{ L"[注] 那张检查报告我看过一次。",
		  L"",
		  L"上面很多术语我不认识。",
		  L"有一个词我认识。",
		  L"",
		  L"我没有查它是什么意思。",
		  L"我已经知道了。", NULL },
		{ L"抽屉里还有一盒药。",
		  L"标签上是她的名字。",
		  L"",
		  L"没有拆开过。早就过期了。",
		  L"",
		  L"我一直没有扔。", NULL },
		{ L"窗外的织女星还在那里。",
		  L"二十五年前,我三岁。她也三岁。",
		  L"那时候我们并不认识。",
		  L"",
		  L"——好。就算已经太晚,",
		  L"我这一次,也必须走到她的病房门口。", NULL },
		{ NULL }
	},

	{
		{ L"我坐了很久。",
		  L"桌上那颗折纸星星,还在原位。",
		  L"我的手指知道该怎么把它拆开。",
		  L"可是这两次坐在这张桌前,我都没有拆。", NULL },
		{ L"[注] 是十二月。",
		  L"具体哪一天我不记得了。",
		  L"",
		  L"那天很冷,",
		  L"我出门的时候忘了带手套。", NULL },
		{ L"[注] 她走以后的第二年,那时候是初冬,",
		  L"我一个人去了城南新开的那间天文馆。",
		  L"演出主题是「北天春季星空」。",
		  L"票价二十元。",
		  L"我买了两张。", NULL },
		{ L"我记得那个我们本来约好一起坐的位置——",
		  L"中央第七排双人座。",
		  L"",
		  L"我在售票口对着售票员说了两个字:",
		  L"    「两张。」", NULL },
		{ L"她抬头看了我一眼,然后低头,",
		  L"撕了两张票——",
		  L"一张递给我,",
		  L"一张也递给了我。",
		  L"我把两张票都攥在了手里。", NULL },
		{ L"我进场的时候里面已经暗了。",
		  L"",
		  L"第七排双人座。",
		  L"我坐在左边。",
		  L"",
		  L"右边那个位置一直空着。", NULL },
		{ L"开场前广播说请关手机。",
		  L"",
		  L"我把手机拿出来看了一眼,然后关机。",
		  L"",
		  L"关机的时候我想起了什么,",
		  L"可是想不清楚是什么。", NULL },
		{ L"[注] 那天演出到七点五十五分左右,",
		  L"穹顶的星空开始一颗、一颗地暗下去。",
		  L"可是有一颗光——正中央偏东南的那颗——",
		  L"一直没有灭。",
		  L"",
		  L"那颗光的位置,就是天琴座 α。",
		  L"——就是织女星。", NULL },
		{ L"散场的时候灯亮了。",
		  L"",
		  L"我坐着没动,等所有人都走完。",
		  L"",
		  L"清场的工作人员在门口看着我。",
		  L"我说了一句抱歉,然后出去了。", NULL },
		{ L"回来以后我写了一封信。",
		  L"",
		  L"开头写了两个字,又划掉。",
		  L"又写了两个字,又划掉。",
		  L"",
		  L"后来我干脆不写称呼了。",
		  L"那封信一直在抽屉里。", NULL },
		{ L"从天文馆回家要走二十分钟。",
		  L"",
		  L"那天很冷,",
		  L"我把两张票都放在外套的内袋里,",
		  L"一路用手按着。",
		  L"",
		  L"到家的时候票被汗弄湿了一点。", NULL },
		{ L"我从桌上拿起那颗折纸星星,",
		  L"放进了自己上衣的口袋。",
		  L"",
		  L"——今晚我把它带上。",
		  L"——因为我必须要在那个双人座上,",
		  L"把它拆开。", NULL },
		{ NULL }
	},

	{
		{ L"我睁开眼睛的时候,仍然是这间书房。",
		  L"台灯还亮着。桌上——那本日记本、那张相框——",
		  L"摆着,还是原来的位置。",
		  L"",
		  L"只有那颗折纸星星,不在桌上了。", NULL },
		{ L"我把手伸进上衣的口袋,把它拿了出来。",
		  L"——它现在已经不是星星了。",
		  L"它是一张展平的、被折出很多道折痕的、",
		  L"浅蓝色的纸。",
		  L"它的正中央——写着一行字。", NULL },
		{ L"[注] 折痕我数过。",
		  L"十七道。",
		  L"",
		  L"不多不少,十七道。",
		  L"",
		  L"我不知道这个数字有没有意义。",
		  L"可我记住了。", NULL },
		{ L"我并不急着把那行字凑到台灯的光下面来看清楚。",
		  L"因为我知道,它一直在那里。",
		  L"这三年里它就一直在。",
		  L"它可以再多等我一会儿。", NULL },
		{ L"今晚我不慌。",
		  L"",
		  L"前面那些晚上,",
		  L"我坐在这张桌前的时候,",
		  L"手总是不知道该放在哪。",
		  L"",
		  L"今晚我知道。", NULL },
		{ L"[注] 窗外,天琴座流星雨正过峰值。",
		  L"辐射点就在织女星旁边——",
		  L"也就是说,今晚从她那颗星那里,",
		  L"会飞出来一些光。",
		  L"不多,一个小时大约二十颗,持续到天快亮。", NULL },
		{ L"我把窗户推开了一点。",
		  L"",
		  L"七月末的风进来了。",
		  L"带一点潮气,不冷。",
		  L"",
		  L"就是她说过的那种。", NULL },
		{ L"我从笔筒里拿出一支铅笔。",
		  L"",
		  L"不是钢笔。",
		  L"",
		  L"她说过写那一句话的时候用铅笔比较好,",
		  L"写错了可以擦。",
		  L"",
		  L"我不打算写错。", NULL },
		{ L"——今后我会怎样呢。我不知道。",
		  L"可我知道桌上这本日记会怎样。",
		  L"它不会再空着了。",
		  L"",
		  L"我也知道,那张模糊的照片不会再模糊下去了。",
		  L"因为我已经开始——从模糊里,",
		  L"慢慢地、慢慢地——认出来那是我们。", NULL },
		{ L"我想起她的声音了。",
		  L"",
		  L"不多,就一点点。",
		  L"",
		  L"是她说「你陪我上去看看」那一句。",
		  L"只有那一句。",
		  L"",
		  L"我不知道明天还记不记得。", NULL },
		{ L"椅子今晚响了一次。",
		  L"",
		  L"就一次。",
		  L"",
		  L"我坐下来的时候响的。",
		  L"后来我一直没有动,所以它没有再响。", NULL },
		{ L"她也答应过我:",
		  L"    星星,还会在这里。",
		  L"",
		  L"我把手放在桌上那张浅蓝色的纸上,很轻。",
		  L"",
		  L"——先坐一会儿。", NULL },
		{ NULL }
	},

};

struct mujian_zhuanhuan {
	const wchar_t* label;
	const wchar_t* name;
	const wchar_t* pangbai1;
	const wchar_t* pangbai2;
};
mujian_zhuanhuan chapter_zhuanhuan[7] = {
	  { NULL, NULL, NULL, NULL },
	  { L"序   幕", L"深    夜", NULL, NULL },
	  { L"第 一 章", L"初    遇",
		L"你不记得她是谁了。",
		L"但你还记得,你答应过她要去看星星。" },
	  { L"第 二 章", L"相    伴",
		L"后来你们真的去看了很多次星星。",
		L"那时候你以为,这只是个开始。" },
	  { L"第 三 章", L"裂    缝",
		L"然后有一天,你发现星星也会消失。",
		L"你只是没想到,这一次会轮到她。" },
	  { L"第 四 章", L"缺    席",
		L"她没有怪你。",
		L"但你怪了自己很久。" },
	  { L"第 五 章", L"回    响",
		L"你终于回来了，",
		L"你终于准备好了。",
	  },
};
void play_pangpai(int chapter) {
	push_stack_time();
	if (chapter < 1 || chapter>6) { pop_stack_time(); return; }
	system("cls");
	mujian_zhuanhuan* temp = &chapter_zhuanhuan[chapter];
	hideCursor();
	Sleep(500);
	gotoxy(15, 3);
	setColor(15);
	printemoji(L"═══════════════════════════════════════════");
	Sleep(200);
	gotoxy(33, 5);
	setColor(15);
	delay_with_Chinese(temp->label, 100);
	Sleep(400);
	gotoxy(33, 7);
	setColor(15);
	delay_with_Chinese(temp->name, 200);
	Sleep(500);
	gotoxy(15, 9);
	setColor(15);
	printemoji(L"═══════════════════════════════════════════");
	Sleep(800);
	gotoxy(10, 11);
	setColor(6);
	printemoji(L"·  .   ✦   .    ·   ✦    .   ·   ✦    .   ·");
	Sleep(150);
	if (temp->pangbai1 != NULL) {
		gotoxy(12, 13);
		setColor(15);
		delay_with_Chinese(temp->pangbai1, 40);
		Sleep(300);
	}
	if (temp->pangbai2 != NULL) {
		gotoxy(12, 14);
		setColor(15);
		delay_with_Chinese(temp->pangbai2, 40);
		Sleep(300);
	}
	Sleep(1000);
	gotoxy(10, 17);
	setColor(6);
	printemoji(L"·  .   ✦   .    ·   ✦    .   ·   ✦    .   ·");
	Sleep(150);
	gotoxy(30, 18);
	setColor(8);
	printemoji(L"·   ·   ·   ·   ·");
	Sleep(200);
	gotoxy(28, 20);
	setColor(8);
	printemoji(L"[  按 空 格 继 续  ]");
	clearbutter();
	while (_getch() != ' ') {

	}
	system("cls");
	pop_stack_time();
}
void draw_the_pangbai() {
	setColor(8);
	for (int i = 0; i < 20; i++) {
		gotoxy(0, i);
		printemoji(mujian_secene[i]);
	}
}
void gaoliang(int nowwerchapter, int nowwerpage) {
	gotoxy(23, 1);
	setColor(nowwerchapter == 4 ? 8 : 14);
	printemoji(L"✦");
	switch (nowwerchapter) {
	case 0:  
		if (nowwerpage >= 4) {
			gotoxy(23, 6); setColor(14); printemoji(L"O");
			gotoxy(22, 7); setColor(6);  printemoji(L"/|\\");
		}
		if (nowwerpage >= 8) {
			gotoxy(9, 10);  setColor(14); printemoji(L"⭐");
		}
		if (nowwerpage >= 9) {
			gotoxy(20, 10); setColor(6);  printemoji(L"📖");
		}
		if (nowwerpage >= 10) {
			gotoxy(31, 10); setColor(7);  printemoji(L"🖼");
		}
		break;

	case 1:   
		if (nowwerpage >= 4) {
			gotoxy(9, 10); setColor(14); printemoji(L"⭐");
		}
		if (nowwerpage >= 6) {
			gotoxy(20, 10); setColor(6); printemoji(L"📖");
		}
		if (nowwerpage >= 7) {
			gotoxy(20, 10); setColor(14); printemoji(L"📖");
		}
		if (nowwerpage >= 9) {
			gotoxy(31, 10); setColor(7); printemoji(L"🖼");
		}
		if (nowwerpage >= 12) {
			gotoxy(9, 10);  setColor(6); printemoji(L"⭐");
			gotoxy(20, 10); setColor(6); printemoji(L"📖");
			gotoxy(31, 10); setColor(6); printemoji(L"🖼");
		}
		break;

	case 2:   
		if (nowwerpage >= 0) {
			gotoxy(20, 10); setColor(6); printemoji(L"📖");
		}
		if (nowwerpage >= 6) {
			gotoxy(20, 10); setColor(14); printemoji(L"📖");
		}
		if (nowwerpage >= 8) {
			gotoxy(9, 10); setColor(14); printemoji(L"⭐");
		}
		break;

	case 3:  
		if (nowwerpage >= 0) {
			gotoxy(31, 10); setColor(6); printemoji(L"🖼");
		}
		if (nowwerpage >= 6) {
			gotoxy(31, 10); setColor(14); printemoji(L"🖼");
		}
		if (nowwerpage >= 8) {
			gotoxy(9, 10); setColor(14); printemoji(L"⭐");
		}
		break;

	case 4:  
		break;

	case 5:   
		if (nowwerpage >= 0 && nowwerpage <= 10) {
			gotoxy(9, 10); setColor(14); printemoji(L"⭐");
		}
		if (nowwerpage >= 5) {
			gotoxy(20, 10); setColor(14); printemoji(L"📖");
			gotoxy(31, 10); setColor(14); printemoji(L"🖼");
		}
		if (nowwerpage == 11) {
			gotoxy(9, 10); setColor(15); printemoji(L"  ");
		}
		break;

	case 6:   
		gotoxy(9, 10); setColor(15); printemoji(L"  ");
		if (nowwerpage >= 0) {
			gotoxy(9, 10); setColor(6); printemoji(L"▬▬");
		}
		if (nowwerpage >= 2) {
			gotoxy(9, 10); setColor(14); printemoji(L"▬▬");
		}
		if (nowwerpage >= 5) {
			gotoxy(28, 1); setColor(14); printemoji(L"╲");
		}
		if (nowwerpage >= 8) {
			gotoxy(20, 10); setColor(6); printemoji(L"📖");
			gotoxy(31, 10); setColor(7); printemoji(L"🖼");
		}
		if (nowwerpage == 11) {
			gotoxy(9, 10);  setColor(6); printemoji(L"▬▬");
			gotoxy(20, 10); setColor(6); printemoji(L"📖");
			gotoxy(31, 10); setColor(6); printemoji(L"🖼");
		}
		break;
	}
}
void play_the_pangbai(int idx) {
	push_stack_time();
	if (idx < 0 || idx > 6) { pop_stack_time(); return; }
	if (pangbai_alredy[idx] == 1) { pop_stack_time(); return; }
	for (int i = 0; i < 25; i++) {
		if (mujian_sanwen[idx][i][0] == NULL)break;
		hideCursor();
		system("cls");
		draw_the_pangbai();
		gaoliang(idx, i);
		setColor(15);
		for (int j = 0; j < 12; j++) {
			const wchar_t* temp = mujian_sanwen[idx][i][j];
			if (temp == NULL)break;
			gotoxy(4, 14 + j);
			delay_with_Chinese(temp, 55);
		}
		gotoxy(28, 27);
		setColor(8);
		printemoji(L"—— 按 Enter 继续 ——");
		clearbutter();
		while (_getch() != '\r') {

		}
	}
	system("cls");
	pangbai_alredy[idx] = 1;
	pop_stack_time();
}

void load_secene(const char* secene, char bg[20][50],
	int* ax, int* ay, int* bx, int* by, int* cx, int* cy) {
	FILE* fp;
	fp = fopen(secene, "r");
	if (!fp) {
		printf("Failed to open file");
		exit(0);
	}
	memset(bg, 0, sizeof(char) * 20 * 50);
	for (int y = 0; y < 20; y++) {
		fgets(bg[y], 50, fp);
		int flag = 0;
		while (bg[y][flag] != '\0' && bg[y][flag] != '\n') {
			flag++;
		}
		bg[y][flag] = '\0';
	}
	fclose(fp);
	*ax = -1; *ay = -1; *bx = -1; *by = -1; *cx = -1; *cy = -1;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			if (bg[i][j] == 'A') {
				*ax = j;
				*ay = i;
			}
			if (bg[i][j] == 'B') {
				*bx = j;
				*by = i;
			}
			if (bg[i][j] == 'C') {
				*cx = j;
				*cy = i;
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			char ch = bg[i][j];
			if (ch == '\0' || ch == ' ' || ch == 'A' || ch == 'B' || ch == 'C' || ch == '?' || ch == 'F' || ch == 'T') {
				continue;
			}
			setColor(get_senece_color(ch, cur_chapter));
			gotoxy(j, i);
			printf("%c",ch);
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			if (bg[i][j] == 'A' || bg[i][j] == 'B') {
				setColor(14);
				gotoxy(j, i);
				printf("%c", bg[i][j]);
			}
			if (bg[i][j] == 'C' || bg[i][j] == '?') {
				gotoxy(j, i);
				printf(" ");
			}
		}
	}
}

struct doors {
	int x, y;
	const char* text;
};
doors difsecene[6] = {
	{  5, 9, "prologue.txt"    },
	{ 13, 9, "library.txt"     },
	{ 21, 9, "rooftop.txt"     },
    { 29, 9, "hospital.txt"    },
    { 37, 9, "planetarium.txt" },
	{ 45, 9, "finale.txt"      }
};

int game_begin_locked[7] = { 0,1,0,0,0,0,0 };

struct item_with_conversation {
	const wchar_t* name;
	const wchar_t* item_line[5];
};
item_with_conversation item_everyconversition[6][3]= {
	// 章 1：prologue 深夜书房
	{
		{ L"⭐ 折纸星星", { L"你拿起那颗星星。", L"它很旧了，边角都卷了起来。", L"你不记得是谁折的，", L"但你的手指还记得过去的微微星光。", NULL } },
		{ L"📖 空白日记本", { L"封面写着:「给未来的你。」", L"里面一页都没写过。", L"但你翻开的时候，掉出一张纸条:",
    L"「如果你看到这张纸条，说明你已经忘了。", L" 别着急。你只是需要重新想起。」" } },
		{ L"🖼 模糊照片", { L"照片很模糊，像是很久以前拍的。", L"星空映照着两个人的身影。", L"你看不清他们的脸。", L"但你觉得其中一个，是你。", NULL } }
	},
	// 章 2：library 大学图书馆
	{
		{ L"📚 天文书籍", { L"你翻开那本书。", L"扉页上有人用铅笔写了一句:", L"「你也喜欢星星吗？」", L"字迹很轻，像是怕打扰到谁。", NULL } },
		{ L"☕ 两杯咖啡", { L"其中一杯是满的，已经凉了很久。", L"另一杯有一点点喝过的痕迹。", L"它们放在同一张桌子上。", L"好像有人等你等了很久。", NULL }
        },
		{ L"📝 手写便签", { L"「下周三，天文台开放夜。", L" 一起来吗？」", L"你记得你没去。", L"但你又记得你本来想去的。", NULL } }
	},
	// 章 3：rooftop 学校天台
	{
		{ L"🔭 望远镜", { L"镜筒上刻着两个名字。", L"一个是你的，一个是她的。", L"刻得很认真。", L"似乎是刻的人反复描了好几次。", NULL } },
		{ L"📸 拍立得照片", { L"照片里你们并排坐着。", L"她笑得很开心。", L"你也是。", L"那时候你们都不知道后来会发生什么。", NULL } },
		{ L"🎵 耳机", { L"里面还放着同一首歌。", L"你忘了歌名。", L"但你记得她说过:", L"「这首歌像星星一样温柔。」", NULL } }
	},
	// 章 4：hospital 医院走廊
	{
		{ L"📋 检查报告", { L"你看了很久。", L"上面有很多术语，你都不认识。", L"但有一个词。", L"你没办法假装不认识。", NULL } },
		{ L"📱 手机屏幕", { L"17 个未接来电。", L"最后一条留言是:", L"「没关系，你忙吧。", L" 我只是有点想你。」", L"你没有回。" } },
		{ L"💊 未开封的药", { L"标签上写着她的名字。", L"药已经过期了。", L"你没有拆开过。", NULL, NULL } }
	},
	// 章 5：planetarium 空天文馆
	{
		{ L"🎫 两张门票", { L"日期是两年前。", L"也是你对她最后一次的邀约。", L"你们本来约好要来看星星。", L"你一个人来了。", NULL } },
		{ L"💌 没寄出的信", { L"「对不起。", L" 我应该早点回来的。", L" 对不起。。。」", L"你没有写称呼。", L"因为你已经不知道该怎么叫她了。" } },
		{ L"⭐ 拆开的星星", { L"你终于把星星拆开了。", L"里面有一行字，是她写的:", L"「如果你看到这个，", L" 说明你已经准备好了。」", NULL } }
	},
	// 章 6：finale 回响 · 同一书房
	{
		{ L"⭐ 星星里的字", { L"你看着那行字。", L"这一次你没有哭。", L"你只是轻轻说了一句:", L"「嗯，我准备好了。」", NULL } },
		{ L"✍ 日记的第一行", { L"你拿起笔。", L"在空白的日记本上写下:", L"「今天，我重新想起了她。」", L"这是你写下的第一行字。", NULL } },
		{ L"🌠 窗外流星", { L"你抬起头。", L"一颗流星刚好划过。", L"你没有许愿。", L"因为你已经知道，", L"她要你好好生活。" } }
	}
};

struct conver_node {
	conver_node* prev;
	conver_node* next;
	const wchar_t* name;
	const wchar_t* line[5];
	int cur_chapter;
};
conver_node* head = NULL;
conver_node* tail = NULL;
int total_size = 0;

void insert_tail(item_with_conversation* item, int chapter) {
	conver_node* node = (conver_node*)malloc(sizeof(conver_node));
	node->cur_chapter = chapter;
	node->name = item->name;
	for (int i = 0; i < 5; i++) {
		node->line[i] = item->item_line[i];
	}
	node->next = NULL;
	node->prev = tail;
	if (tail) {
		tail->next = node;
	}
	else {
		head = node;
	}
	tail = node;
	total_size++;
}

void clear_and_see_you() {
	conver_node* temp = NULL;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
	tail = NULL;
	total_size = 0;
}

int have_already_pick(int chapter, int slot) {
	const wchar_t* pickedname = item_everyconversition[chapter - 1][slot].name;
	conver_node* p = head;
	while (p) {
		if (p->cur_chapter == chapter && wcscmp(p->name , pickedname)==0) {
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void draw_conver_history(conver_node* p, int idx) {
	system("cls");
	setColor(14);
	gotoxy(2, 1);
	printemoji(L"═══ 对话回放 ═══");
	setColor(11);
	gotoxy(50, 1);
	printf("[ %d / %d ]", idx, total_size);
	setColor(11);
	gotoxy(2, 4);
	printf("第 %d 章", p->cur_chapter);
	setColor(14);
	gotoxy(2, 6);
	printemoji(p->name);
	setColor(15);
	for (int i = 0; i < 5; i++) {
		if (p->line[i] == NULL) break;
		gotoxy(5, 8 + i);
		printemoji(p->line[i]);
	}
	setColor(8);
	gotoxy(2, 22);
	printemoji(L"A/D 翻页    Q 返回");
}

void begin_conver_history() {
	push_stack_time();
	conver_node* p = tail;
	int idx = total_size;
	if (!tail) {
		cleararray(21, 3);
		gotoxy(2, 22);
		setColor(8);
		printemoji(L"（还没拾取任何物品）");
		clearbutter();
		_getch();
		cleararray(21, 3);
		pop_stack_time();
		return;
	}
	while (1) {
		draw_conver_history(p, idx);
		clearbutter();
		char c = _getch();
		if (c == 'q') break;
		if (c == 'a' && p->prev != NULL) {
			p = p->prev;
			idx--;
		}
		if (c == 'd' && p->next != NULL) {
			p = p->next;
			idx++;
		}
	}
	pop_stack_time();
}


int six_chapter_done() {
	for (int i = 1; i <= 6; i++) {
		if (pangbai_alredy[i] == 0) {
			return 0;
		}
	}
	return 1;
}

int hall_react(int px,int py) {
	if (!six_chapter_done()) {
		return 0;
	}	
	if (isreact(px, py, 24, 13)) {
		return 1;
	}
	if (isreact(px, py, 25, 13)) {
		return 1;
	}
	return 0;
}

void draw_the_beginning_room() {
	gotoxy(14, 17);
	setColor(14);
	printemoji(L"星空回响 · 回廊之厅");
	gotoxy(10, 18);
	setColor(6);
	printemoji(L"ps: 建议按先后顺序游玩");
	for (int i = 0; i < 6; i++) {
		int curchapter = i + 1;
		gotoxy(difsecene[i].x, difsecene[i].y);
		if (!game_begin_locked[curchapter]) {
			setColor(8);
			printf("D");
		}
		else {
			setColor(14);
				printf("D");
		}
	}
	if (six_chapter_done()) {
		setColor(14);
		gotoxy(24, 13);
		printemoji(L"✦");
		setColor(6);
		gotoxy(17, 14);
		printemoji(L"—— 终章 ——");
	}
}

void get_to_the_hall(char*curscene,char bg[20][50],
	int* ax, int* ay, int* bx, int* by, int* cx, int* cy,
	int* px, int* py,
	int* flagA, int* flagB, int* flagC) {
	system("cls");
	if (pangbai_alredy[0] == 0) {
		play_bgm("bgm/titile-hall.wav");
	}
	play_the_pangbai(0);
	play_bgm(bgm_chapter[0]);
	*flagA = 0; *flagB = 0; *flagC = 0;
	*px = 24; *py = 11;
	strcpy(curscene, "hall.txt");
	cur_chapter = 0;
	load_secene(curscene, bg, ax, ay, bx, by, cx, cy);
	draw_the_beginning_room();
}

void get_to_the_secene(char* curscene, char bg[20][50],
	int* ax, int* ay, int* bx, int* by, int* cx, int* cy,
	int* px, int* py,
	int* flagA, int* flagB, int* flagC,
	int chapter) {
	system("cls");
	if (pangbai_alredy[chapter] == 0) {
		play_pangpai(chapter);
		play_bgm(bgm_chapter[chapter]);
		play_the_pangbai(chapter);

	}
	else {
		play_bgm(bgm_chapter[chapter]);
	}
	*flagA = have_already_pick(chapter, 0);
	*flagB = have_already_pick(chapter, 1);
	*flagC = have_already_pick(chapter, 2) ? 3 : 0;
	*px = 24; *py = 18;
	cur_chapter = chapter;
	strcpy(curscene, difsecene[chapter - 1].text);
	load_secene(curscene, bg, ax, ay, bx, by, cx, cy);
	if (chapter < 6) {
		game_begin_locked[chapter + 1] = 1;
	}
	if (*flagA == 1 && *ax >= 0) {
		bg[*ay][*ax]= ' ';
		gotoxy(*ax, *ay);
		setColor(15);
		printf(" ");
	}
	if (*flagB == 1 && *bx >= 0) {
		bg[*by][*bx] = ' ';
		gotoxy(*bx, *by);
		setColor(15);
		printf(" ");
	}
	if (*flagC == 3 && *cx >= 0) {
		bg[*cy][*cx] = ' ';
		gotoxy(*cx, *cy);
		setColor(15);
		printf(" ");
	}
}

void playconversation(item_with_conversation* item, int colornmber) {
	push_stack_time();
	for (int i = 0; i < 5; i++) {
		if (item->item_line[i] == NULL) break;
		cleararray(21, 5);
		draw_dialog(0, 21, 60, 5);
		gotoxy(2, 22);
		setColor(colornmber);
		printemoji(item->name);
		gotoxy(2, 23);
		setColor(15);
		delay_with_Chinese(item->item_line[i], 80);
		gotoxy(55, 24);
		setColor(8);
		printf("▼");
		clearbutter();
		_getch();
	}
	cleararray(21, 5);
	pop_stack_time();
}

void show_the_jiejuDEzhimu(const wchar_t* temp1, const wchar_t* temp2,int delay) {
	int len1 = 0;
	int len2 = 0;
	for (int i = 0; temp1[i] != L'\0'; i++) {
		len1++;
	}
	for (int j = 0; temp2[j] != L'\0'; j++) {
     	len2++;
	}
	int x1 = 60 - len1;
	int x2 = 60 - len2;
	if (x1 < 0) x1 = 0;
	if (x2 < 0) x2 = 0;
	setColor(15);
	gotoxy(x1, 11);
	delay_with_Chinese(temp1, 20);
	setColor(8);
	gotoxy(x2, 13);
	delay_with_Chinese(temp2, 20);
	Sleep(delay);
}

void clear_new_right(int line) {
	gotoxy(52, line);
	for (int i = 52; i < 119; i++) {
		printf(" ");
	}
}
void delay_with_huanhang(const wchar_t* text, int x, int y, int max_cols, int delay) {
	int cur_x = x;
	int cur_y = y;
	int cur_cols = 0;
	setColor(15);
	gotoxy(cur_x, cur_y);
	for (int i = 0; text[i] != L'\0'; i++) {
		int temp = 0;
		if (text[i] < 0x80) temp = 1;
		else temp = 2;
		if (cur_cols + temp > max_cols) {
			cur_x = x;
			cur_y++;
			cur_cols = 0;
			gotoxy(cur_x, cur_y);
		}
		gotoxy(cur_x, cur_y);
		HANDLE temp2 = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD written;
		WriteConsoleW(temp2, &text[i], 1, &written, NULL);
		Sleep(delay);
		cur_x = cur_x + temp;
		cur_cols = cur_cols + temp;
	}
}
void play_jiejju_conver(const wchar_t*text,int y,int delay1,int delay2) {
	for (int i = y; i < y + 8; i++) {
		clear_new_right(i);
	}
	gotoxy(55, y);
	setColor(15);
	delay_with_huanhang(text, 55, y, 60, delay1);
	Sleep(delay2);
	gotoxy(76, 29);
	setColor(8);
	printemoji(L"[ 按 空 格 继 续 ]");
	clearbutter();
	while (_getch() != ' ') {

	}
	clear(24);
}

void show_last_world(int what_ending) {
	system("cls");
	int vega_color;
	if (what_ending == 0) vega_color = 14;
	else if (what_ending == 1) vega_color = 8;
	else vega_color = 1;
	gotoxy(60, 9);
	setColor(vega_color);
	printemoji(L"✦");
	Sleep(1000);
	const wchar_t* lines_A[] = {
		  L"献给她。",
		  L"献给三年那个不能回去的夕阳。",
		  L"献给每一个抬头看星星的人。",
		  L"你做到了。",
		  NULL
	};
	const wchar_t* lines_B[] = {
		L"献给那些今夜也睡不着的人。",
		L"献给那些不是因为想过、",
		L"而是因为得过的人。",
		L"献给拆了又折回去的人。",
		L"到了明天",
		L"你还会把那颗星星折回去。",
		NULL
	};
	const wchar_t* lines_C[] = {
		L"献给那些已经忘记的人。",
		L"献给那些记得一切、",
		L"却不知道为什么重要的人。",
		L"献给她。",
		L"—— 即使你已经不记得她是谁。",
		NULL
	};
	int xianci_count = 0;
	const wchar_t** text = NULL;
	if (what_ending == 0) {
		xianci_count = 4;
		text = lines_A;
	}
	else if (what_ending == 1) {
		xianci_count = 6;
		text = lines_B;
	}
	else {
		xianci_count = 5;
		text = lines_C;
	}
	for (int i = 0; i < xianci_count; i++) {
		int color = 15;
		if (what_ending == 0 && i == xianci_count - 1) color = 14;
		else if (what_ending == 1) color = 7;
		else if (what_ending == 2) {
			if (i == xianci_count - 2) color = 15;
			else color = 7;
		}
		int len = 0;
		while (text[i][len] != L'\0') {
			len++;
		}
		int x = 60 - len;
		if (x < 0) {
			x = 0;
		}
		int y = 11 + i;
		gotoxy(x, y);
		setColor(color);
		printemoji(text[i]);
		Sleep(200);
	}
	Sleep(400);
	gotoxy(54, 20);
	setColor(8);
	printemoji(L"《星空回响》");
	Sleep(300);
	gotoxy(51, 24);
	setColor(8);
	printemoji(L"[ 按 空 格 继 续 ]");
	clearbutter();
	while (_getch() != ' ') {

	}
}

void xiaochu_hall() {
	cleararray(0, 3);
	Sleep(500);
	clear(3);
	Sleep(300);
	cleararray(5, 2);
	Sleep(300);
	clear(7);
	Sleep(500);
	cleararray(8, 17);
	Sleep(400);
	system("cls");
}

void chongzhi_game() {
	memory_zhi = 100;
	time_top = 0;
	memory_last = 0;
	in_ending = 0;
	for (int i = 0; i < 7; i++) {
		pangbai_alredy[i] = 0;
	}
	for (int i = 0; i < 7; i++) {
		game_begin_locked[i] = 0;
	}
	game_begin_locked[1] = 1;
	total_size = 0;
	cur_chapter = 0;
	clear_and_see_you();
}

void return_to_titile(int what_ending) {
	int delay;
	if (what_ending == 0) delay = 1000;
	else if (what_ending == 1) delay = 3000;
	else delay = 5000;
	system("cls");
	Sleep(delay);
	show_last_world(what_ending);
	system("cls");
	Sleep(500);
	chongzhi_game();
	begin_title();
}

struct ending_color {
	int star;
	int vega;
	int window_frame;
	int wall;
	int desk_frame;
	int shelf_frame;
	int shelf_book;
	int lamp;
	int desk_line;
	int player;
	int curtain;
	int carpet;
	int line;
	int mono_text;
	int hint;
};
ending_color  ending_colors[3] = {
	{ 11, 14,  11, 11,  6,  6,  6,  14,  6, 15,  4,  6,  8, 15,  8 },
	{  8,  8,   8,  8,  7,  8,  8,   6,  8,  7,  7,  8,  8,  7,  8 },
	{  1,  1,   8,  8,  8,  8,  8,   7,  8, 15,  1,  1,  8, 15,  8 }
};
void draw_ending_room(int mode) {
	system("cls");
	ending_color c = ending_colors[mode];
	setColor(c.star);
	gotoxy(1, 0);  printemoji(L" .   '   *        .              ");
	gotoxy(1, 1);  printemoji(L"    .         *                  ");
	gotoxy(1, 2);  printemoji(L" *      .              *          ");
	gotoxy(1, 3);  printemoji(L"          '                      ");
	setColor(c.window_frame);
	gotoxy(29, 0);  printemoji(L"┌──────────┐");
	gotoxy(29, 1);  printemoji(L"│");  gotoxy(39, 1); printemoji(L" │");
	gotoxy(29, 2);  printemoji(L"│");  gotoxy(39, 2); printemoji(L" │");
	gotoxy(29, 3);  printemoji(L"│");  gotoxy(39, 3); printemoji(L" │");
	setColor(c.star);
	gotoxy(31, 1);  printemoji(L".");
	gotoxy(33, 2);  printemoji(L".");
	gotoxy(31, 3);  printemoji(L"*");
	gotoxy(37, 3);  printemoji(L".");
	setColor(c.vega);
	gotoxy(35, 1);  printemoji(L"✦");
	setColor(c.wall);
	gotoxy(1, 4);
	printemoji(L"┌───────────────────────────┴──────────┘────────┐");
	for (int y = 5; y <= 16; y++) {
		gotoxy(1, y);   printemoji(L"│");
		gotoxy(49, y);  printemoji(L"│");
	}
	gotoxy(1, 17);
	printemoji(L"└───────────────────────────────────────────────┘");
	setColor(c.desk_frame);
	gotoxy(5, 6);
	printemoji(L"╔═══════════════════════════════════════╗");
	for (int y = 7; y <= 14; y++) {
		gotoxy(5, y);   printemoji(L"║");
		gotoxy(45, y);  printemoji(L"║");
	}
	gotoxy(5, 15);
	printemoji(L"╚═══════════════════════════════════════╝");
	setColor(c.shelf_frame);
	gotoxy(7, 7);   printemoji(L"╭──────╮");
	gotoxy(7, 12);  printemoji(L"╰──────╯");
	setColor(c.shelf_book);
	for (int y = 8; y <= 11; y++) {
		gotoxy(7, y);   printemoji(L"│▓▓▓▓▓▓│");
	}
	setColor(c.lamp);
	gotoxy(27, 7);  printemoji(L"___");
	gotoxy(26, 8);  printemoji(L"|___|");
	gotoxy(28, 9);  printemoji(L"|");
	setColor(c.desk_line);
	gotoxy(20, 10);  printemoji(L"──────────────────");
	gotoxy(20, 12);  printemoji(L"──────────────────");
	setColor(c.desk_line);
	gotoxy(23, 11);  printemoji(L"⭐");
	gotoxy(29, 11);  printemoji(L"📖");
	gotoxy(35, 11);  printemoji(L"🖼");
	gotoxy(29, 13);  printemoji(L"☕");
	setColor(c.player);
	gotoxy(26, 14);  printemoji(L"@");
	setColor(c.curtain);
	gotoxy(2, 16);  printemoji(L"⋮⋮⋮⋮⋮⋮");
	setColor(c.carpet);
	gotoxy(8, 16);  printemoji(L"▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨");
	setColor(c.line);
	gotoxy(1, 18);
	printemoji(L"═════════════════════════════════════════════════");
}
void draw_the_ending_B_room() {
	setColor(8);
	gotoxy(25, 14);  printemoji(L"o");   
	gotoxy(37, 4);   printemoji(L".");
}
void draw_the_ending_C_room(int if_youren) {
	setColor(8);
	gotoxy(2, 6);   printemoji(L"╔═══╗");
	gotoxy(2, 7);   printemoji(L"║   ║");
	gotoxy(2, 8);   printemoji(L"║   ║");
	gotoxy(2, 9);   printemoji(L"║   ║");
	gotoxy(2, 10);  printemoji(L"╚═══╝");
	gotoxy(4, 8);
	if (if_youren) {
		setColor(15);
		printemoji(L"@");
	}
	else {
		setColor(8);
		printemoji(L"?");
	}
}
void draw_the_Ade_street() {
	system("cls");
	setColor(11);
	gotoxy(0, 0); 
	printemoji(L" .    *   .        '     *      .          ");
	setColor(14);
	gotoxy(47, 0);
	printemoji(L"✦");   
	setColor(11);
	gotoxy(0, 1); 
	printemoji(L"        .          *           .");
	setColor(8);
	gotoxy(40, 5);  printemoji(L" ╱╲");
	gotoxy(39, 6);  printemoji(L" ╱  ╲");
	gotoxy(38, 7);  printemoji(L"┌──────┐");
	gotoxy(38, 8);  printemoji(L"│▒▒▒▒▒▒│");
	gotoxy(38, 9);  printemoji(L"│▒▒▒▒▒▒│");
	gotoxy(38, 10); printemoji(L"│  ██  │");
	gotoxy(38, 11); printemoji(L"└──────┘");
	setColor(15);
	gotoxy(20, 7);  printemoji(L"┌────┐");
	gotoxy(20, 8);  printemoji(L"│≡≡≡≡│");
	gotoxy(20, 9);  printemoji(L"├────┤");
	setColor(7);
	gotoxy(20, 10); printemoji(L"│ .  │");
	setColor(8);
	gotoxy(20, 11); printemoji(L"└─╔╗─┘");
	setColor(6);
	gotoxy(2, 7);   printemoji(L"  ═══╤═══");
	gotoxy(7, 8);   printemoji(L"│");
	gotoxy(4, 9);   printemoji(L"┌──┴──┐");
	gotoxy(4, 10);  printemoji(L"│     │");
	gotoxy(4, 11);  printemoji(L"└     ┘"); 
	setColor(8);
	gotoxy(0, 13);
	printemoji(L"- - - - - - - - - - - - - - - - - - - - - - - -");
	gotoxy(0, 15);
	printemoji(L"- - - - - - - - - - - - - - - - - - - - - - - -");
	setColor(8);
	gotoxy(0, 18);
	printemoji(L"═════════════════════════════════════════════════");
}
void draw_the_Ade_stair() {
	system("cls");
	setColor(8);
	gotoxy(20, 1);  printemoji(L"┌────┐");
	gotoxy(20, 2);  printemoji(L"│    │");
	setColor(6);
	gotoxy(20, 3);  printemoji(L"└─╔╗─┘");
	setColor(8);
	int stair_zuobiao[10][2] = {
		  {23, 4},
		  {22, 5},
		  {21, 6},
		  {20, 7},
		  {19, 8},
		  {18, 9},
		  {17, 10},
		  {16, 11},
		  {15, 12},
		  {13, 13}
	};
	for (int i = 0; i < 10; i++) {
		gotoxy(stair_zuobiao[i][0], stair_zuobiao[i][1]);
		printemoji(L" ▬▬▬▬▬▬▬");
	}
	setColor(8);
	gotoxy(0, 18);
	printemoji(L"═════════════════════════════════════════════════");
}
void draw_the_Ade_tiantai() {
	system("cls");
	char bg[20][50];
	int ax=-1,ay=-1 ,bx=-1, by=-1, cx=-1, cy=-1;
	cur_chapter = 3;
	load_secene("rooftop.txt", bg, &ax, &ay, &bx, &by, &cx, &cy);
	if (ax >= 0) { 
	   gotoxy(ax, ay);
	   printf(" "); 
	}
	if (bx >= 0) {
	   gotoxy(bx, by); 
	   printf(" "); 
	}
	if (cx >= 0) { 
	   gotoxy(cx, cy); 
	   printf(" "); 
	}
	clear(19);
	setColor(14);
	gotoxy(47, 0);
	printemoji(L"✦");
	setColor(8);
	gotoxy(0, 18);
	printemoji(L"═════════════════════════════════════════════════");
	setColor(15);
	gotoxy(28, 14);
	printemoji(L"@");
}
void play_C_item() {
	system("cls");
	conver_node* p = head;
	int count = 0;
	while (p != NULL) {
		int y = 9 + count * 3;
		gotoxy(15, y);
		setColor(6);
		delay_with_Chinese(p->name, 28);
		Sleep(400);
		count++;
		if (count == 3) {
			Sleep(800);
			system("cls");
			Sleep(400);
			count = 0;
		}
		p = p->next;
	}
	if (count > 0) {
		Sleep(800);
		system("cls");
		Sleep(400);
	}
	Sleep(900);
}

void play_jieju_C() {
	in_ending = 1;
	play_bgm("bgm/ending_c.wav");
	play_C_item();
	Sleep(500);
	draw_ending_room(2);
	draw_the_ending_C_room(0);
	play_jiejju_conver(L"你回到桌前。", 11, 28, 100);
	play_jiejju_conver(L"台灯亮着——你觉得应该是你自己出门前忘了关的。可是你也不确定,这些天你总是记不清关没关灯,记不清昨晚吃过没吃过晚饭,记不清昨天早上有没有喝那杯速溶咖啡。你觉得这些记不清的事情本身, 应该让你慌一下——可是不知道为什么, 你并不慌。你只是坐了下来。", 11, 28, 150);
	play_jiejju_conver(L"椅子发出「吱」的一声。你不记得这把椅子什么时候开始会响的,可是你觉得,应该是很久以前就开始响了——有一些日常的、无关紧要的声音,可能是一直都在的, 只是你从前有别的事情要在意, 所以听不见。现在没有别的事情了, 所以你听见了。", 11, 28, 150);
	play_jiejju_conver(L"桌上有三样东西——一颗折纸星星,一本没有写过一个字的日记本,一张模糊的照片。", 11, 28, 150);
	play_jiejju_conver(L"——你抬头看向了对面的墙。", 11, 28, 150);
	play_jiejju_conver(L"墙上有一面小小的、你自己也不记得什么时候挂上去的镜子。镜子里有一个人。那个人的头发有一点长,有一点乱,眼睛下面有很深的黑眼圈,像是很多年没有睡好一样。那个人看着你, 你也看着他。", 11, 28, 250);
    Sleep(2500);
	draw_the_ending_C_room(1);
	play_jiejju_conver(L"你花了大概三秒钟,才想起来——那个人是你。", 11, 28, 250);
	play_jiejju_conver(L"——原来你今夜看起来是这个样子的。", 11, 28, 150);
	play_jiejju_conver(L"你转过头,把视线从镜子里移开。你不想再看下去。你也不知道从什么时候开始,你已经不太认得镜子里的自己了。可能是从某一天开始的。可能是从上一个月开始的。可能是——从很久以前的某一年, 你把手机翻过去、屏幕朝下的那一秒开始的。你今夜什么都记不清。", 11, 28, 250);
	play_jiejju_conver(L"你伸手把那颗折纸星星拿了起来。", 11, 28, 100);
	play_jiejju_conver(L"它是浅蓝色的,折得很仔细,每一个折痕都压得很实。它比你想的软——像是被人一次又一次拆开过、又折回去,纸的纤维已经软化了。你的手指知道该怎么把它拆开——它先是被从两端捏松, 再从底面掀开一层, 再从背面拉开一层, 最后一层一层展平——你的手指做过这个动作, 而且做过很多次, 才会这么熟练。", 11, 28, 150);
	play_jiejju_conver(L"——这就奇怪了。你不记得你自己什么时候学过折星星,更不记得你什么时候做过这个“拆开又折回去”的动作。可是你的手指记得。", 11, 28, 150);
	play_jiejju_conver(L"你把它拆开了。里面写着一行字:“如果你看到这个,说明你已经准备好了。”", 11, 28, 150);
	play_jiejju_conver(L"——你笑了。", 11, 28, 250);
	play_jiejju_conver(L"你笑得很轻,几乎没有声音,只是嘴角微微地动了一下。你不知道你为什么笑——大概是因为,这句话像一个陌生人放在你桌上的、一个奇怪的笑话。准备好了什么 ? 桌上有一颗折纸星星、一本没写过字的日记本、一张模糊的照片, 和一个镜子里你自己都认不出来的人——这个屋子里没有任何东西, 是“准备好了”可以让你去做的。你甚至不知道, 今夜之外, 还有没有“明天”这种东西, 值得让你“准备好”。", 11, 28, 250);
	play_jiejju_conver(L"字迹很秀气——不是你的字。", 11, 28, 100);
	play_jiejju_conver(L"你想弄明白,谁会给你留这样一句话,谁会用铅笔写字,谁会把纸折成星星,谁会在写完之后小心翼翼地把它放在你的桌上,让你很多年之后、一个人坐下来的某一晚、把它打开。", 11, 28, 150);
	play_jiejju_conver(L"你想不起来。", 11, 28, 100);
	play_jiejju_conver(L"你把那张纸,重新折了回去。你的手指记得所有的折痕。可是你的脑子不记得那些折痕是从哪里来的。", 11, 28, 250);
	play_jiejju_conver(L"桌上还有一本日记本。", 11, 28, 100);
	play_jiejju_conver(L"封面上写着“给未来的你”,字迹和折纸星星里的那一行,是同一个人写的。", 11, 28, 150);
	play_jiejju_conver(L"你打开日记本。翻到第一页。", 11, 28, 100);
	play_jiejju_conver(L"——第一页的顶上,有一行淡淡的痕迹。", 11, 28, 150);
	play_jiejju_conver(L"不是字。是有过字、可是被人擦掉之后剩下的、铅笔的印子。你看得很仔细,想认出来那行字曾经写的是什么。你甚至用指腹去摸那些印子,试图靠触感, 把那些擦掉的字重新读出来。", 11, 28, 150);
	play_jiejju_conver(L"——可是你摸不出来。你也读不出来。", 11, 28, 150);
	play_jiejju_conver(L"你不记得你什么时候写过一行字在这里。你也不记得你什么时候擦过它。你只是知道——曾经有过一行字。曾经有一个坐在这张桌前、拿着一支铅笔的你——不是你今夜这个坐在这张桌前的你, 是从前的、某一个你——写下过一行字, 然后又把它擦掉了。", 11, 28, 250);
	play_jiejju_conver(L"你想过要不要在原来那行字的位置上,重新写点什么。可是你想不出该写什么。你甚至不知道,你重新写下的字,会不会又在你不记得的、某一个明天, 被你自己再擦掉一次。", 11, 28, 250);
	play_jiejju_conver(L"你把日记本合上。你把铅笔放回了笔筒。", 11, 28, 150);
	play_jiejju_conver(L"你觉得,今夜大概,不是这本日记本的开始。", 11, 28, 150);
	play_jiejju_conver(L"——也许它,从来就没有过开始。", 11, 28, 250);
	play_jiejju_conver(L"桌上还有一张模糊的照片。", 11, 28, 100);
	play_jiejju_conver(L"照片很旧了,像是很久以前拍的。照片里有两个人的轮廓,站在夜空底下,并肩靠着。你看不清他们的脸——不是因为照片糊,是因为你今夜好像本来就没有能力去看清那两张脸。", 11, 28, 150);
	play_jiejju_conver(L"其中一个人的肩上,披着一件藏青色的外套。", 11, 28, 150);
	play_jiejju_conver(L"你看着那件外套,看了很久。你觉得眼熟。你觉得——你见过这件外套。你觉得你知道这件外套是谁的。你觉得你甚至知道,那个人当年穿着这件外套的时候, 身上是什么味道——是一种浅浅的、洗过很多次的洗衣皂的味道, 混着一点点书页放旧了以后的那种气味, 再混着一点点你自己也说不清是什么、可你就是熟悉的东西。",11, 28, 250);
	play_jiejju_conver(L"——就在这时,你忽然停住了。", 11, 28, 250);
	play_jiejju_conver(L"你低下头,看你自己身上穿的那件外套。", 11, 28, 150);
	play_jiejju_conver(L"——它也是藏青色的。", 11, 28, 350);
	play_jiejju_conver(L"你抬起自己的手臂,把袖子凑到鼻子跟前,闻了一下。", 11, 28, 150);
	play_jiejju_conver(L"——洗衣皂。书页。还有那一点点你说不清是什么、可你就是熟悉的东西。", 11, 28, 150);
	play_jiejju_conver(L"——是你自己身上的味道。", 11, 28, 350);
	play_jiejju_conver(L"你把手臂放下。你的心脏,今夜第一次,跳了一下——不是“惊”,是“钝”,像是一个已经很久没用过的机器,忽然想动一下,可是关节都锈住了,动不了。",11, 28, 250);
	play_jiejju_conver(L"你不知道你什么时候开始有这件外套的。你不知道这件外套原本是谁的。你甚至不知道——照片里那个人肩上披着这件外套的那一天,是你披的,还是别人替你披的, 还是别人披着这件外套走过你的身边, 然后过了很多年, 那件外套, 不知道怎么就到了你的衣柜里, 又不知道怎么, 今夜就穿在了你的身上。", 11, 28, 250);
	play_jiejju_conver(L"——你不记得。", 11, 28, 250);
	play_jiejju_conver(L"你只是知道——你今夜身上的味道,和照片里那个“披着藏青色外套的人”身上的味道,是一样的。", 11, 28, 150);
	play_jiejju_conver(L"你有可能就是照片里的那个人。你也有可能不是。你今夜连这件事都分不清了。", 11, 28, 250);
	play_jiejju_conver(L"你把照片放回原位。你的胸口,有一种说不清楚的痛——可是你找不到那种痛的源头。", 11, 28, 250);
	play_jiejju_conver(L"你站起来,走到窗前。", 11, 28, 100);
	play_jiejju_conver(L"你不记得你为什么要走到窗前。你只是觉得,今夜坐得有点久了,应该起来走一走。窗外是七月末的夜,楼下便利店的灯还亮着,一个你不认识的收银员低着头, 可能在看手机。街上没有别的人。天空里没有云。", 11, 28, 150);
	play_jiejju_conver(L"你抬起头。", 11, 28, 150);
	play_jiejju_conver(L"——有一颗星,比其他所有星都要亮。", 11, 28, 250);
	play_jiejju_conver(L"你看着那颗星,看了很久。你记得那颗星——你记得它叫什么名字。天琴座α。中文名叫织女。距离地球二十五光年。这些你都记得。你甚至记得, 那颗光是二十五年前从她那里出发的, 穿过二十五年的空, 今晚, 才落到你的眼睛里。你甚至记得, 二十五年前你三岁, 那颗光刚出发的时候, 你还是一个不会仰头看星星的小孩, 住在这座城市的某一条街上, 不知道自己有一天会一个人站在这扇窗前, 把这颗光, 看这么久。", 11, 28,250);
	play_jiejju_conver(L"这些你都知道。", 11, 28, 100);
	play_jiejju_conver(L"——从她那里出发的。", 11, 28, 350);
	play_jiejju_conver(L"你脑子里冒出了“她”这个字。", 11, 28, 150);
	play_jiejju_conver(L"你自己也吓了一跳。因为你不知道,“她”是谁。你不知道你为什么会用“她”这个字。你不知道——为什么这颗二十五光年之外的光,应该是从一个“她”那里出发的, 而不是从任何别的地方。", 11, 28, 150);
	play_jiejju_conver(L"你努力去想。你想“她”这个字的意思。你想“她”是不是一个具体的人。你想“她”如果是一个具体的人,那“她”的脸是什么样子,“她”的声音是什么样子, “她”和你之间, 曾经发生过什么。", 11, 28, 250);
	play_jiejju_conver(L"——你脑子里的“她”这个字,是空的。", 11, 28, 350);
	play_jiejju_conver(L"它就是一个字。一个语法上的字。“她”这个字,今夜对你来说,和“桌子”“水杯”“七月末的风”这些字,没有任何分别。", 11, 28, 250);
	play_jiejju_conver(L"——你不知道,为什么这颗星,对你来说,重要。", 11, 28, 250);
	play_jiejju_conver(L"——你不知道,为什么你今夜看着这颗星的时候,眼眶,会热。", 11, 28, 350);
	play_jiejju_conver(L"你在窗前站着,站了很久。", 11, 28, 100);
	play_jiejju_conver(L"眼眶还是热的。可是眼泪没有掉下来。你也没有出声。你只是站着,看那颗二十五光年之外的光,像一个人在看一份他曾经很熟悉、可是现在读不出内容的文件——你知道这份文件对你重要, 你知道这份文件里写着某些你曾经在意过的事情, 可是你今夜就是读不出来。", 11, 28, 250);
	play_jiejju_conver(L"你想哭。", 11, 28, 150);
	play_jiejju_conver(L"你不知道你为什么想哭。你想哭是因为丢了什么东西——可是你连丢了什么,都想不起来了。你甚至不确定,你今夜的这个“想哭”本身,是真的想哭,还是你只是记得, 从前你在这种时候是会想哭的, 所以你今夜也应该想哭。", 11, 28, 250);
	play_jiejju_conver(L"你知道——有些东西,今夜从你这里溜走了。你不知道那些东西是什么,你也不知道那些东西是从什么时候开始溜走的。可能是从今夜开始的,可能是从这三年里的某一天开始的, 可能是从更早的、某一年、某一个下午, 你把手机翻过去、屏幕朝下、不接电话的那一秒开始的——那次不接电话的事, 你还记得, 可是你已经想不起来那时候电话另一头, 究竟是谁。", 11, 28, 250);
	play_jiejju_conver(L"你只是知道——有些东西,应该在的,今夜不在了。", 11, 28, 150);
	play_jiejju_conver(L"你的胸口那种说不清楚的痛,慢慢地淡下去了。淡到像一杯放在桌上没人喝的水——凉了,还在,可是你已经不记得,为什么倒了这杯水,也不记得这杯水, 原本是给谁的。", 11, 28, 250);
	play_jiejju_conver(L"窗外一颗流星划过。", 11, 28, 250);
	play_jiejju_conver(L"——你没有许愿。", 11, 28, 350);
	play_jiejju_conver(L"——因为你不记得,你曾经想向谁许愿。", 11, 28, 350);
	play_jiejju_conver(L"——你甚至不记得,“愿望”这个词,是什么意思。", 11, 28, 450);
	Sleep(3000);
	return_to_titile(2);
}

void play_jieju_B() {
	in_ending = 1;
	play_bgm("bgm/ending_b.wav");
	draw_ending_room(1);
	draw_the_ending_B_room();
	play_jiejju_conver(L"你回到桌前。", 11, 28, 100);
	play_jiejju_conver(L"台灯还亮着——你记得,今晚出门的时候忘了关。\n这盏灯是钨丝的,光有一点点黄,落在桌面上的时候,像倒了一小滩温水。\n三年了,你一直没有换过它, 虽然它的寿命, 按照常理, 应该早就到了。", 11, 28, 150);
	play_jiejju_conver(L"台灯的光只照亮了桌面,桌面之外的书房是暗的。\n你没有开顶灯——你从来没有习惯开顶灯。\n这栋房子里的顶灯只有很少的几次被打开过,几乎全是因为她。\n她当年来这里的时候, 总是嫌台灯不够亮, 她会一进门就把顶灯打开。\n三年了, 顶灯没有再被打开过, 你也不知道那颗灯泡是不是还能亮。", 11, 28, 200);
	play_jiejju_conver(L"桌上那三样东西还在原位:\n一颗折纸星星,一本没有写过一个字的日记本,一张模糊的照片。\n照片里两个人的轮廓,其中一个人的肩上,披着藏青色的外套。", 11, 28, 150);
	play_jiejju_conver(L"你在椅子上坐了下来。\n椅子发出「吱」的一声——是那种,只有在深夜里、只有在整间书房里没有别的声音的时候,才听得到的、极轻的响声。\n你不记得这把椅子什么时候开始会响的, 可能是从她走以后的某一天开始的, 也可能一直都在响, 只是你从前没有听过。\n你在这张椅子上坐过三年, 你数过它响过多少次, 你也数过—	—你从来没有真的坐够。", 11, 28, 200);		play_jiejju_conver(L"你伸手把那颗折纸星星拿了起来。", 11, 28, 100);
	play_jiejju_conver(L"它比你想的软,像是被人一次又一次拆开过、又折回去,纸的纤维已经软化了。\n你的手指知道该怎么把它拆开——它先是被从两端捏松,再从底面掀开一层, 再从背面拉开一层。\n你的手指做过这个动作三年了, 只是你三年里一次都没有真的做过。\n今夜你做了。", 11, 28, 150);
	play_jiejju_conver(L"你把它拆开了。\n它现在已经不是星星了,是一张展平的、被折出很多道折痕的、浅蓝色的纸。\n纸的正中央,写着一行字。是她的字迹,你一眼就认得出来。\n你把那一行字凑到台灯的光下, 看了很久——「如果你看到这个, 说明你已经准备好了」。", 11, 28, 200);
	play_jiejju_conver(L"你以为你会哭。\n你以为读到这一行字的这一秒,你会觉得,那些等了三年的话,终于有一个地方可以放。\n可是没有。\n你只是看着那一行字,像看着一份别人替你写好的功课, 写好了三年, 一直等着你打开。\n你知道你应该按上面写的去做, 你已经准备好了, 你应该抬起头, 应该微笑, 应该说一句什么。\n可是你的心里是空的	, 是那种你已经熟悉了三年的空。", 11, 28, 250);
	play_jiejju_conver(L"你不知道那一行字是从她当年的哪一秒里写出来的。\n你不知道她写字的那一晚,窗外有没有下雨,桌上有没有她喝到一半的水。\n那些细节,是当年	在你眼前发生过的, 可你三年没有再想起过, 今夜你也没有想起。", 11, 28, 200);
	play_jiejju_conver(L"台灯的光落在纸上,让那一行字微微地泛着黄。\n屋子里没有别的声音,只有远处——很远的地方,大概是隔了两条街的方向——一辆车缓缓开过的声音。	\n那辆车开得很慢, 你听着它从街的这一头慢慢滑到那一头消失。\n像是有一个人今夜也睡不着, 一个人开着车, 不知道要去哪。\n你想那个人可能和你一样——你也不知道自己要	去哪。", 11, 28, 200);
	play_jiejju_conver(L"你把那张展平的纸,轻轻地放在桌上。", 11, 28, 100);
	play_jiejju_conver(L"你打开那本空白的日记本,翻到第一页。\n这本日记本的封面上,有一行她当年替你写上去的字——「给未来的你」。\n三年了,你没有翻开过这本日记本超过三次。\n今夜是第四次。", 11, 28, 200);
	play_jiejju_conver(L"你从桌上的笔筒里拿出一支铅笔。\n笔筒是她当年从校门口那家小店里替你挑的,是一个陶做的、蓝白花的、样子不太好看的小罐子。\n当年她还笑	着说这个笔筒像一只没洗干净的碗。\n你现在倒是觉得挺贴切。", 11, 28, 200);
	play_jiejju_conver(L"你的手悬在纸面上,悬了很久。\n你想写「今天,我重新想起了她」,也想写「对不起,我来晚了」,也想写「她答应过我,星星还会在这里」。\n可是	每一个句子刚起了一个头, 笔就抬起来了。\n不是因为你不想写, 是因为你写不真。", 11, 28, 200);
	play_jiejju_conver(L"你知道,你今夜写下的每一个字,都不完全是你想说的。\n你今夜能说的话,只是你今夜能说的话。\n她走了三年了,这三年里她一个人在你不知道的	地方过了三年, 而你一个人在她不知道的地方也过了三年。\n你今夜坐在这里, 想替你们两个人的这三年一起说话, 可是你只知道你自己那一半。\n她那一半你今夜依然什么都不	知道, 她当年的心事、她当年的怕、她当年在你不知道的地方蹲过的那些下午——\n你今夜依然什么都不知道。", 11, 28, 250);
	play_jiejju_conver(L"台灯下方的桌面上有一个小小的、深色的印子。\n是当年她把一杯热茶放在这里的时候留下来的。\n三年了,你没有擦过它,你也没有想过要擦掉它	。\n你只是每次看见它就想起来, 那杯茶是她放下的。\n你今夜写下的任何一句话, 都不会像那个茶印子那么真。\n因为那个茶印子是她当年在你眼前发生过的, 而你今夜写下的字, 只是你今夜写下的字。", 11, 28, 250);		
	play_jiejju_conver(L"你把笔放下了。你在纸上一个字也没写。", 11, 28, 200);
	play_jiejju_conver(L"你站起来,走到窗前。", 11, 28, 100);
	play_jiejju_conver(L"窗外的这条街,深夜里比白天更长。\n楼下那家开了很多年的便利店的灯还亮着,是那种偏冷的、有一点点白的荧光。\n收银台里的人今夜不是白天那个, 你不认识她。\n她低着头, 大概在看手机; 你从窗外看过去, 只能看见她头顶上那一小片头发的形状。\n她也不知道有人在楼上一动不动地看着她低头。", 11, 28, 200);
	play_jiejju_conver(L"除了那盏便利店的灯,街上没有别的光。\n路灯早就该修了,那盏最近的路灯上个礼拜坏掉,一直没有人来换。\n街上没有人。\n街的对面,那家你和	她当年一起去过的小面馆, 已经关了。\n玻璃门上贴着一张纸, 写着「店铺转让」。\n你从上礼拜开始就看着那张纸, 可你没有走进去问过。", 11, 28, 200);
	play_jiejju_conver(L"你抬起头。", 11, 28, 150);
	play_jiejju_conver(L"天琴座 α,中文名叫织女,距离地球二十五光年——\n她今夜和别的晚上没什么两样。\n天空里有一点点云,不多,是那种很薄的、挡不住星星、只是让星星的光看起来比平常再远一点的云。\n你在窗前站着, 风从没关严的缝隙里挤进来, 是七月末的风, 带着一点点潮气, 不冷。", 11, 28, 200);
	play_jiejju_conver(L"你想说「你看,我来了」。\n可是这句话你今夜说不出口,因为你不确定她能听到。\n你也不确定,你今夜看到的那颗光,和三年前你抬头看到的那颗光, 以及她当年抬头看到的那颗光, 是不是同一颗。", 11, 28, 250);
	play_jiejju_conver(L"你也想说「我想成为你的——」。\n可是这句话你说不下去,因为你不知道你想成为她的什么。\n你不知道她要的是什么,你也不知道,你三年前不知道她要什么和三年后不知道她要什么有什么分别。\n三年过去了, 你还是不知道她要什么——你连她当年不要什么, 都不知道。", 11, 28, 250);		play_jiejju_conver(L"你在窗前站着,站了很久。\n远处的那辆车已经消失了,便利店里那个低头的人不知道什么时候站起来去补了货,又坐回去。\n你都看着。你也不知道		你为什么看着一个不认识的人做完这些不重要的事。", 11, 28, 200);
	play_jiejju_conver(L"你想哭,可是你今夜连眼泪也挤不出来。\n你的眼睛是干的,你的胸口是空的。\n你不知道你为什么坐在这里,你不知道拆开那颗星星、读到那行字应	该给你什么。\n你也不知道, 你今夜如果真的哭出来, 那些眼泪是给她的、给你自己的, 还是给这三年里那个你没有救、也救不了的、那个一个人的、坐在这张桌前的自己的。\n		你不知道。", 11, 28, 250);		play_jiejju_conver(L"你从窗前转过身,走回桌前,在椅子上重新坐了下来。\n椅子又「吱」了一声。\n你没有再听见街上那辆车的声音了,屋子里只剩下你的呼吸。", 11,	28, 200);
	play_jiejju_conver(L"你把那张展平的、浅蓝色的纸,重新拿了起来。\n你的手指记得所有的折痕,它比你想的还要容易折回去。\n你一层一层地把它折回来,把它折回星星的形状, 把它放回了桌上的原位。", 11, 28, 200);
	play_jiejju_conver(L"你不能让它就这样停在展开的样子。\n因为你明天早上还要起床,明天早上还要出门。\n你不能让那张展开的纸在你明天的桌上躺一整天。\n你不能	让明天回到这间书房里的自己一进门就看见桌上摊着那张纸——\n那样你明天就没办法坐下来, 没办法喝一口水, 没办法翻开电脑开始工作。\n你得把它折回去, 因为明天你还要活下去。", 11, 28, 250);
	play_jiejju_conver(L"桌上三样东西——\n一颗折纸星星,一本没有写过一个字的日记本,一张模糊的照片。\n和你今夜走进这间书房的时候,一模一样。", 11, 28, 200);
	play_jiejju_conver(L"什么都没有发生过。", 11, 28, 150);
	play_jiejju_conver(L"台灯还亮着,桌面上那个茶印子还在原位,你的椅子还在响——\n只是这一次响得轻了一点,窗外那盏便利店的灯和上一秒相比也没有比刚才更暗。",11, 28, 200);
	play_jiejju_conver(L"你今夜以为你抵达了一个什么地方,你今夜以为你说了一句什么话,你今夜以为你重新认得那颗二十五光年之外的光——\n可是天亮之后,你会照样从被窝里爬起来, 走到浴室, 拧开水龙头, 让冷水冲一冲脸。\n然后回到厨房, 烧一壶水, 泡一杯速溶咖啡。\n她当年不喜欢你喝速溶, 可是这三年里你已经不再买挂耳的了, 因为一个人喝挂耳太麻烦。\n你会把那杯速溶端到桌前, 坐下, 喝一口, 然后打开电脑, 开始今天该做的事。", 11, 28, 250);
	play_jiejju_conver(L"你会照样过下去。\n不是因为你想过,是因为你得过。\n你也不知道从什么时候开始,这两件事是不一样的——\n可能是从她走以后的第一年,可能是从第一年之后你意识到你没有权利就这样躺在床上不起来的那一天。\n可能是从你意识到「想过」和「得过」两件事之间只有一线之隔,	而你三年里已经不小心走到了后面那一边的那一秒。", 11, 28, 250);
	play_jiejju_conver(L"你会走出这间书房,走出这栋楼,走过楼下那家便利店——\n今夜看你不认识的那个人可能就是白天开始看你的那个人。\n你会走过图书馆,走过学校的	侧门, 走到你上班的地方, 和某一个不认识你、也不认识她的同事打一个招呼「早」。\n然后对方也会回你一句「早」。\n然后你们会坐到各自的位置上, 做各自今天该做的事, 喝	完那杯已经放凉了的速溶咖啡。\n把那些邮件、那些表格、那些不需要用心的事情一件一件做完, 直到又一次天黑, 直到又一次你可以回家, 回到这间书房, 坐回这张桌前。", 11,			28, 300);
	play_jiejju_conver(L"你会在下一个七月末的夜晚,想起她,然后想不清楚,然后回到这张桌前——\n就像今夜一样,就像三年前她走的那一晚一样,就像三年里的每一个七月末一样。\n就像大概你的一辈子里以后每一个坐得回来、又走不出去的晚上一样。", 11, 28, 250);
	play_jiejju_conver(L"可是你还是得过下去。\n因为如果不过下去,她当年答应过你的那句「星星还会在这里」——\n就再也没有一个活着的人替她记着了。", 11, 28,300);
	play_jiejju_conver(L"台灯还亮着。你没有关它。", 11, 28, 200);
	play_jiejju_conver(L"你只是把手放在了桌上那颗折纸星星旁边,没有碰它,也没有再拿起笔——\n你就这样坐着。", 11, 28, 200);
	play_jiejju_conver(L"远处那条街的另一端,又有一辆车开过,声音和刚才那辆一样慢。\n你没有转过头去看,你只是听着它从街的一头滑到另一头消失。\n你想那个开车的人大概也和你一样, 他今夜也睡不着, 他今夜也开着车, 不知道要去哪。\n可是他还是得开, 他还是得在天亮之前把这辆车开到某一个地方停下来, 然后自己走回家, 倒在床上, 把明	天过完。\n你和他一样。", 11, 28, 250);
	play_jiejju_conver(L"窗外——很远的、你今夜没有再看的地方——一颗流星划过。\n你没有看见,你也没有想看见。\n可是你知道,它划过了,你也知道天上还有下一颗,以及再下一颗。\n以及以后每一年七月末的这几个夜晚里, 一颗接一颗你都不会去看的那些颗。", 11, 28, 250);
	play_jiejju_conver(L"不是今晚。可是明天你还是要过下去,哪怕下一次未必会来。", 11, 28, 300);
	Sleep(3000);
	return_to_titile(1);
}

void draw_street_dongtai() {
	int secene[4] = { 40,25,10,2 };
	int cur_x = 44, cur_y = 14;
	gotoxy(44, 14);
	setColor(15);
	printemoji(L"@");
	Sleep(500);
	for (int i = 0; i < 4; i++) {
		int x = secene[i];
		while (cur_x != x ) {
			gotoxy(cur_x, 14);
			printf(" ");
			if (cur_x > x) cur_x--;
			gotoxy(cur_x, 14);
			setColor(15);
			printemoji(L"@");
			Sleep(200);
		}
		switch (i) {
		case 0:
			play_jiejju_conver(L"走过图书馆,它今晚关了灯。", 11, 28, 200);
			break;
		case 1:
			play_jiejju_conver(L"走过路口那家便利店,里面有个你不认识的人正在低头看手机。", 11, 28, 200);
			break;
		case 2:
			play_jiejju_conver(L"走过学校的侧门,那扇门这么多年了,还是没有锁,像是知道有一个人会在这一天回来,替他留着。", 11, 28, 200);
			break;
		case 3:
			play_jiejju_conver(L"你走到了天文台。", 11, 28, 300);
			break;
		}
	}
}

void draw_stair_dongtai() {
	int secene[10][2] = {
		{13, 13}, {15, 12}, {16, 11}, {17, 10}, {18, 9},
		{19, 8},  {20, 7},  {21, 6},  {22, 5},  {23, 4}
	};
	int cur_x = 13, cur_y = 13;
	gotoxy(cur_x, cur_y);
	setColor(15);
	printemoji(L"@");
	Sleep(500);
	for (int i = 0; i < 10; i++) {
		int x = secene[i][0];
		int y = secene[i][1];
		while (cur_x != x || cur_y != y) {
			gotoxy(cur_x, cur_y);
			printf(" ");
			if (cur_x < x) cur_x++;
			if (cur_y > y) cur_y--;
			gotoxy(cur_x, cur_y);
			setColor(15);
			printemoji(L"@");
			Sleep(500);
		}
		Sleep(200);
	}
}

void draw_tiantai() {
	static int A_xunhuannumber = 0;
	int number = A_xunhuannumber % 5;
	int color_total[5] = { 8, 7, 6, 14, 6 };
	setColor(color_total[number]);
	gotoxy(0, 0);
	printemoji(L"   *    .    '    *    .    '    *    .    '   ");
	gotoxy(0, 1);
	printemoji(L"     .    *    '    .    *    '    .    *      ");
	setColor(color_total[number]);
	gotoxy(47, 0);
	printemoji(L"✦");
	A_xunhuannumber++;
	static int A_liu_xing_tai = 0;
	static int A_liu_xing_count = 0;
	static int A_liu_xing_jishi = 10;
	if (A_liu_xing_tai == 0) {
		A_liu_xing_jishi--;
		if (A_liu_xing_jishi <= 0) {
			A_liu_xing_count = 0;
			A_liu_xing_tai = 1;
			A_liu_xing_jishi = 10 + (A_xunhuannumber % 8);
		}
	}
	if (A_liu_xing_tai) {
		int x = 100 - A_liu_xing_count * 7;
		int y = 3 + A_liu_xing_count;
		if (x > 40 && y < 11) {
			if (A_liu_xing_count > 0) {
				int px = 100 - (A_liu_xing_count - 1) * 7;
				int py = 2 + A_liu_xing_count;
				gotoxy(px, py);
				printf(" ");
			}
			gotoxy(x, y);
			setColor(14);
			printemoji(L"✦");
			A_liu_xing_count++;
		}
		else {
			if (A_liu_xing_count > 0) {
				int px = 100 - (A_liu_xing_count - 1) * 7;
				int py = 2 + A_liu_xing_count;
				gotoxy(px, py);
				printf(" ");
			}
		  A_liu_xing_tai = 0;
		}
	}
}

void draw_A_liuxing() {
	for (int i = 0; i < 6; i++) {
		int x = 90 - i * 10;
		int y = 3 + 2 * i;
		if (i > 0) {
			int px = 90 - (i - 1) * 10;
			int py = 1 + 2 * i;
			gotoxy(px, py);
			printf(" ");
	    }
		gotoxy(x, y);
		setColor(14);
		printemoji(L"✦");
		Sleep(400);
	}
}

void play_A_tiantai_dubai(const wchar_t* text, int delay1, int delay2) {
	for (int i = 11; i <= 18; i++) {
		clear_new_right(i);
	}
	gotoxy(55, 11);
	setColor(15);
	delay_with_huanhang(text, 55, 11, 60, delay1);
	Sleep(delay2);
	gotoxy(76, 29);
	setColor(8);
	printemoji(L"[ 按 空 格 继 续 ]");
	clearbutter();
	while (_getch() != ' ') {
		draw_tiantai();
		Sleep(50);
	}
	clear(29);
}

void houji_line(const wchar_t* text, int y, int color, int delay) {
	int len = 0;
	while (text[len] != L'\0') {
		len++;
	}
	int x = 60 - len;
	if (x < 0) {
		x = 0;
	}
	gotoxy(x, y);
	setColor(color);
	delay_with_Chinese(text, delay);
}

void houji_wait() {
	gotoxy(51, 26);
	setColor(8);
	printemoji(L"[ 按 空 格 继 续 ]");
	clearbutter();
	while (_getch() != ' ') {

	}
	for (int i = 8; i <= 22; i++) {
		clear(i);
	}
	clear(26);
}
void play_A_houji() {
	play_bgm("bgm/houji.wav");
	system("cls");
	Sleep(1500);
	setColor(8);
	gotoxy(38, 2);
	printemoji(L"·   .   ✦   .   ·   ✦   .   ·   ✦   .   ·");
	Sleep(800);
	gotoxy(38, 24);
	printemoji(L"·   .   ✦   .   ·   ✦   .   ·   ✦   .   ·");
	Sleep(1000);
	setColor(15);
	gotoxy(57, 5);
	delay_with_Chinese(L"后  记", 250);
	Sleep(1500);
	houji_line(L"晨光透过旧窗棂的时候,", 10, 15, 70);
	houji_line(L"我在清理一只尘封的纸箱。", 11, 15, 70);
	houji_line(L"最底层有一本泛黄的素描本。", 13, 15, 70);
	houji_line(L"翻开的时候,飞出一只被时间风干的蝴蝶。", 14, 15, 70);
	Sleep(800);
	houji_wait();
	houji_line(L"它曾是活的。", 11, 15, 70);
	Sleep(600);
	houji_line(L"我十岁那年的夏天。", 13, 15, 70);
	Sleep(1000);
	houji_wait();
	houji_line(L"那只凤蝶是被我捏在指间的。", 10, 15, 70);
	houji_line(L"翅膀在我指尖碎裂。", 11, 15, 70);
	houji_line(L"我永远记得那种触感——", 13, 15, 70);
	houji_line(L"薄翼如纸,碎裂的声音细微却刺鼻。", 14, 15, 70);
	Sleep(1000);
	houji_wait();
	houji_line(L"后来我画过无数完美的蝴蝶。", 11, 15, 70);
	Sleep(700);
	houji_line(L"却再没碰过任何一只活着的美。", 13, 15, 70);
	Sleep(1200);
	houji_wait();
	houji_line(L"一个孩子如何因为渴望占有美,", 10, 15, 70);
	houji_line(L"而毁灭了美本身。", 11, 15, 70);
	houji_line(L"这成了我关于遗憾的最初记忆。", 13, 15, 70);
	Sleep(1000);
	houji_wait();
	houji_line(L"每一个选择都在杀死其他所有的可能。", 10, 15, 70);
	houji_line(L"十岁那年我选择了捕捉,", 12, 15, 70);
	houji_line(L"便杀死了让它继续飞翔的可能;", 13, 15, 70);
	houji_line(L"后来我选择了不再触碰,", 14, 15, 70);
	houji_line(L"又杀死了另一种体验世界的可能。", 15, 15, 70);
	Sleep(1000);
	houji_wait();
	houji_line(L"我们永远活在选择的废墟之上。", 11, 15, 70);
	Sleep(700);
	houji_line(L"遗憾便是那些被埋葬的时空,", 13, 15, 70);
	houji_line(L"在心底投下的长影。", 14, 15, 70);
	Sleep(1200);
	houji_wait();
	houji_line(L"可是庄子梦见蝴蝶的时候,", 10, 15, 70);
	houji_line(L"问的不是「我是谁」,", 11, 15, 70);
	houji_line(L"而是「谁在梦谁」。", 12, 15, 70);
	Sleep(800);
	houji_line(L"界限消失了。", 14, 15, 70);
	Sleep(1000);
	houji_wait();
	houji_line(L"如果那对翅膀注定要在我指尖碎裂,", 10, 15, 70);
	houji_line(L"那么碎裂本身,", 11, 15, 70);
	houji_line(L"是不是也是一种完整的形态?", 12, 15, 70);
	Sleep(900);
	houji_line(L"它此刻躺在我掌心,近乎透明——", 14, 15, 70);
	houji_line(L"它的美不再是飞行的美,", 15, 15, 70);
	houji_line(L"而成了光线的容器。", 16, 15, 70);
	Sleep(1200);
	houji_wait();
	houji_line(L"这个故事里那个人,", 10, 15, 70);
	houji_line(L"在望远镜的底座下面找到了一封信。", 11, 15, 70);
	Sleep(900);
	houji_line(L"没有人给我藏过。", 13, 15, 70);
	Sleep(1100);
	houji_line(L"所以我自己写了一个。", 15, 14, 70);
	Sleep(1500);
	houji_wait();
	houji_line(L"和解从来不是原谅自己做错了什么。", 10, 15, 70);
	houji_line(L"而是接受自己只能做一件事、", 12, 15, 70);
	houji_line(L"成为一个人、活一次生命。", 13, 15, 70);
	Sleep(900);
	houji_line(L"我们都曾是那个笨拙的孩子,", 15, 15, 70);
	houji_line(L"带着满手碎片长大——", 16, 15, 70);
	Sleep(700);
	houji_line(L"然后在某一天突然明白:", 17, 6, 70);
	houji_line(L"碎片本身,就是完整的另一种形态。", 18, 6, 70);
	Sleep(1500);
	houji_wait();
	houji_line(L"阳光移开了。", 10, 15, 70);
	houji_line(L"纸箱合上,蝴蝶留在桌上。", 11, 15, 70);
	Sleep(800);
	houji_line(L"它不再属于过去,它属于此刻——", 13, 15, 70);
	houji_line(L"而此刻的我,终于可以轻轻放下它,", 14, 15, 70);
	houji_line(L"像放下一个终于被理解的句子。", 15, 15, 70);
	Sleep(2500);
	houji_wait();
	houji_line(L"又到了一个平常的深夜。", 11, 15, 70);
	houji_line(L"我看着我的电脑屏幕,", 13, 15, 70);
	houji_line(L"又想起了一些事。", 14, 15, 70);
	Sleep(1500);
	houji_wait();
	houji_line(L"为什么我会写这个故事呢?", 13, 15, 90);
	Sleep(2000);
	houji_wait();
	houji_line(L"2025 年九月初,", 10, 15, 70);
	houji_line(L"作为隐藏小作家的我,", 11, 15, 70);
	houji_line(L"积极地在网上投稿。", 12, 15, 70);
	Sleep(700);
	houji_line(L"我喜欢哲学。", 14, 15, 70);
	Sleep(1200);
	houji_wait();
	houji_line(L"十月份,偶然的一次机会,", 10, 15, 70);
	houji_line(L"我遇到了一位同样喜欢哲学的网友。", 11, 15, 70);
	Sleep(800);
	houji_line(L"交谈甚好。", 13, 15, 70);
	Sleep(1500);
	houji_wait();
	houji_line(L"直到远在千里的她说出", 10, 15, 70);
	houji_line(L"「抑郁」「想死」这类的话时——", 11, 15, 70);
	Sleep(1200);
	houji_line(L"我才意识到,", 13, 15, 70);
	houji_line(L"我手机之外的那个她,", 14, 15, 70);
	houji_line(L"与我不是一个世界的人。", 15, 15, 70);
	Sleep(1800);
	houji_wait();
	houji_line(L"虚无主义。海德格尔。西西弗斯。", 11, 15, 80);
	Sleep(1000);
	houji_line(L"我读的任何哲学,", 13, 15, 70);
	houji_line(L"都显得苍白无力。", 14, 15, 70);
	Sleep(1800);
	houji_wait();
	houji_line(L"尝试了许多办法。", 11, 15, 70);
	Sleep(1000);
	houji_line(L"最终两个月后,", 13, 15, 70);
	houji_line(L"那个她离世了。", 14, 15, 70);
	Sleep(2500);
	houji_wait();
	houji_line(L"我并没有哭泣,也没有惋惜。", 10, 15, 70);
	Sleep(800);
	houji_line(L"这不关乎儿女情长。", 12, 15, 70);
	Sleep(900);
	houji_line(L"我只知道,", 14, 15, 70);
	houji_line(L"我所书写的一切面对死亡,", 15, 15, 70);
	houji_line(L"是那么的无力。", 16, 15, 70);
	Sleep(2200);
	houji_wait();
	houji_line(L"我一直在想死亡究竟是什么。", 10, 15, 70);
	Sleep(700);
	houji_line(L"为什么每个人都会害怕死亡。", 12, 15, 70);
	Sleep(700);
	houji_line(L"害怕死亡与性,", 14, 15, 70);
	houji_line(L"真的都是基因层面的事物吗?", 15, 15, 70);
	Sleep(1800);
	houji_wait();
	houji_line(L"为何有人能以微笑面对明天,", 10, 15, 70);
	houji_line(L"乐观地生活下去。", 11, 15, 70);
	Sleep(800);
	houji_line(L"而又有人只能在虚无与抑郁中度过?", 13, 15, 70);
	Sleep(1200);
	houji_line(L"这真的是没有任何办法能解决的吗?", 15, 15, 70);
	Sleep(2000);
	houji_wait();
	houji_line(L"死亡。遗憾。和解。妥协。", 10, 15, 80);
	Sleep(1000);
	houji_line(L"我们又该怎么面对遗憾与死亡呢?", 12, 15, 70);
	Sleep(1000);
	houji_line(L"我想,只有亘古不变的两个字——", 14, 15, 70);
	Sleep(600);
	houji_line(L"意义。", 15, 14, 120);
	Sleep(2000);
	houji_wait();
	houji_line(L"赋予你生活下去的意义。", 10, 15, 70);
	Sleep(900);
	houji_line(L"可这终究只是空谈。", 12, 15, 70);
	Sleep(1000);
	houji_line(L"毕竟我直到现在,", 14, 15, 70);
	houji_line(L"也不知道我活下去的意义。", 15, 15, 70);
	Sleep(2200);
	houji_wait();
	houji_line(L"这不关乎死亡,", 10, 15, 70);
	houji_line(L"也不关乎命运,成功。", 11, 15, 70);
	Sleep(1000);
	houji_line(L"我真的能与内心的自己和解吗?", 13, 15, 70);
	Sleep(2200);
	houji_wait();
	houji_line(L"我想和解绝不是一场决战后的握手,", 10, 15, 70);
	houji_line(L"而更像学会同时携带碎裂与完整。", 11, 15, 70);
	Sleep(1000);
	houji_line(L"那个「未和解」的部分,", 13, 15, 70);
	houji_line(L"恰恰让你保持了敏锐,", 14, 15, 70);
	houji_line(L"让你没有滑入冷漠的答案里。", 15, 15, 70);
	Sleep(1800);
	houji_wait();
	houji_line(L"可这或许也是纸面言语。", 13, 8, 90);
	Sleep(2200);
	houji_wait();
	houji_line(L"我想恐惧死亡,", 10, 15, 70);
	houji_line(L"恰恰是因为我们真正恐惧的是", 11, 15, 70);
	houji_line(L"「未完成」——", 12, 15, 70);
	Sleep(900);
	houji_line(L"未说完的话。", 14, 15, 70);
	houji_line(L"未和解的关系。", 15, 15, 70);
	houji_line(L"未成为的自己。", 16, 15, 70);
	Sleep(2000);
	houji_wait();
	houji_line(L"基因只管繁衍。", 10, 15, 70);
	Sleep(800);
	houji_line(L"但人会为一句诗落泪,", 12, 15, 70);
	houji_line(L"会为一个虚拟角色失眠。", 13, 15, 70);
	Sleep(900);
	houji_line(L"这些早已超出生存本能。", 15, 15, 70);
	Sleep(1800);
	houji_wait();
	houji_line(L"所以死亡带来的刺痛,", 11, 15, 70);
	houji_line(L"不是生理警报,", 12, 15, 70);
	houji_line(L"而是意义系统在震荡。", 13, 15, 70);
	Sleep(2000);
	houji_wait();
	houji_line(L"可这也是纸面语言。", 13, 8, 90);
	Sleep(2500);
	houji_wait();
	houji_line(L"究竟怎样的纸面语言,", 11, 15, 80);
	houji_line(L"才能展现真实的自我?", 12, 15, 80);
	Sleep(2500);
	houji_wait();
	houji_line(L"我想纸面语言就是这样:", 10, 15, 70);
	Sleep(1000);
	houji_line(L"它无法承载死亡,", 12, 15, 70);
	Sleep(1200);
	houji_line(L"但它可以承载", 14, 14, 90);
	houji_line(L"你承载死亡的那个姿势。", 15, 14, 90);
	Sleep(3000);
	houji_wait();
	houji_line(L"献给屏幕前的你————", 11, 14, 90);
	Sleep(1200);
	houji_line(L"遗憾常伴终生。", 13, 15, 90);
	Sleep(1800);
	houji_wait();
	houji_line(L"当你恒常以诗的悲哀征服生命的悲哀", 10, 15, 70);
	houji_line(L"我试图以文学的悬崖瓦解宿命的悬崖", 11, 15, 70);
	Sleep(900);
	houji_line(L"当我无法安慰你", 13, 15, 70);
	houji_line(L"或你不再能关怀我", 14, 15, 70);
	Sleep(900);
	houji_line(L"请千万记住,在我们菲薄的流年", 16, 6, 70);
	houji_line(L"曾有十二只白鹭鸶飞过秋天的湖泊", 17, 6, 70);
	Sleep(3000);
	gotoxy(51, 26);
	setColor(8);
	printemoji(L"[ 按 空 格 继 续 ]");
	clearbutter();
	while (_getch() != ' ') {

	}
	system("cls");
	Sleep(800);
}

void play_jieju_A() {
	in_ending = 1;
	play_bgm("bgm/ending_a1.wav");
	draw_ending_room(0);
	play_A_tiantai_dubai(L"你回到桌前。", 28, 200);
	play_A_tiantai_dubai(L"台灯还亮着——你记得,今晚出门的时候忘了关。这盏灯是钨丝的,光有一点点黄,落在桌面上的时候,像倒了一小滩温水,你已经很多年没有换过它了, 虽然它的寿命, 按照常理, 应该早就到了。不知道为什么, 你有点感激它, 感激它一直亮到今晚。", 28, 200);
	play_A_tiantai_dubai(L"桌上那三样东西还在原位。一颗折纸星星,一本没有写过一个字的日记本,一张模糊的照片,照片里两个人的轮廓,其中一个人的肩上,披着藏青色的外套。", 28, 200);
	play_A_tiantai_dubai(L"你在椅子上坐了下来。椅子发出「吱」的一声——是那种,只有在深夜里、只有在整间书房里没有别的声音的时候,才听得到的、极轻的响声。你不	记得这把椅子什么时候开始会响的, 可能是从她走以后的某一天开始的, 也可能一直都在响, 只是你从前没有听过。", 28, 200);
    play_A_tiantai_dubai(L"你伸手把那颗折纸星星拿了起来。它比你想的软,像是被人一次又一次拆开过、又折回去,纸的纤维已经软化了。你的手指知道该怎么把它拆开,这三年里你都知道——因为你的手指记得。", 28, 200);
	play_A_tiantai_dubai(L"大二那年的九月,天文台开放夜。你去了,她也在。你们并肩坐在望远镜边上,她把一张浅蓝色的纸放在你手里,说:「你会折星星吗?我教你,你以后	一个人的时候, 可以自己折。」你那时没往心里去, 因为你以为你们会一直在一起, 以为没有「一个人的时候」。", 28, 200);
	play_A_tiantai_dubai(L"她低下头,一次又一次地对折,一次又一次地摊开,一次又一次地对折。夜风把她的头发吹到你的脸颊上,你没有把它拨开——你舍不得那一阵风,舍不得她低头折纸的样子, 舍不得她说话时候用的那个「以后」。", 28, 200);
	play_A_tiantai_dubai(L"你的手指记住了那些折痕,它们比你的脑子记得清楚。", 28, 250);
	play_A_tiantai_dubai(L"桌上那本空白的日记本,你也一直没有写过一个字。", 28, 200);
	play_A_tiantai_dubai(L"你不是没有拿起过笔。三年前的冬天,她走了之后的第二个月,你坐在这张桌子前,笔尖悬在纸面上,悬了很久,你想写「对不起」,也想写「我记得你」, 还想过写「那天我为什么没有接电话」——可是每一个句子刚起了一个头, 笔就抬起来了, 因为你知道, 写下来的字是给活人看的, 她已经不在了。", 28, 200);
	play_A_tiantai_dubai(L"你也想过,把这些话说出来,可是屋子里只有你一个人,你的嗓子发不出声音——你不是发不出来,你只是不忍心把这些话说给一个空屋子听。后来你	就把笔放下, 再也没有拿起来过。", 28, 200);
	play_A_tiantai_dubai(L"那时你还不明白,不写字,并不代表你没有在跟她说话。你只是把话说到了别的地方——说到了每一次抬头看天琴座的时候,说到了每一次听见她曾经喜欢的那首歌的时候, 说到了她走以后的那些年, 你还没有搬家, 还住在这间书房里, 虽然这间书房——按你自己的话说——已经不再是「你的」书房, 是「你们的」。", 28, 250);
	play_A_tiantai_dubai(L"你也不是不知道那一天该做什么。", 28, 200);
	play_A_tiantai_dubai(L"她住院是七月十四号。你收到消息的时候,手机在你的裤子口袋里震动,你在开会,你把它翻过去,屏幕朝下,第五次的时候按了静音,第十次的时候把它放进了包里, 第十七次已经是晚上了。你告诉自己:明天再回去——可是有些明天, 不会来。", 28, 250);
	play_A_tiantai_dubai(L"后来,你的手机在书房抽屉的最里面,压在一叠她写给你的信下面,已经三年没有开过机,电池早就没了。你有时候会把它拿出来,翻过来、翻过去,像那一天一样, 屏幕朝下, 扣在桌面上, 你不打开它, 你也不需要打开, 你已经记住了它第一次亮起的那一瞬间——未接来电 17, 语音留言 1。", 28, 250);
	play_A_tiantai_dubai(L"你没有点开那条语音留言,三年了,你都没有,因为你知道,你还没有准备好听她的声音——你怕一旦听了,你就再也没有办法假装,她只是出了一趟远门。", 28, 250);
    play_A_tiantai_dubai(L"今夜,你准备好了。", 28, 250);
	play_A_tiantai_dubai(L"你把那颗折纸星星凑到台灯下,慢慢地、一层一层地把它拆开,它比你想的更容易被拆开,因为这三年里,它已经等过很多次了。", 28, 200);
	play_A_tiantai_dubai(L"它现在已经不是星星了,是一张展平的、被折出很多道折痕的、浅蓝色的纸。纸的正中央,写着一行字——是她的字迹,你一眼就认得出来,她写字的时候, 「你」字最后一笔总是往下撇得比常规多一点, 像是把一句话已经写完了, 还要再回头看一眼。", 28, 250);
	play_A_tiantai_dubai(L"纸上写着:「如果你看到这个,说明你已经准备好了。」", 28, 250);
	play_A_tiantai_dubai(L"你看着那一行字,看了很久。她好像就坐在你的对面,她好像从来没有走远。", 28, 250);
	play_A_tiantai_dubai(L"你想起来了。", 28, 200);
	play_A_tiantai_dubai(L"她走以后的第二年,冬天,你一个人去过一次城南的天文馆。演出的主题是「北天春季星空」,票价二十元。你在售票口对着售票员说了两个字:「两张。」售票员抬头看了你一眼, 又低头, 撕了两张票——一张递给你, 一张也递给了你。", 28, 250);
	play_A_tiantai_dubai(L"你在双人座上坐了一场演出,一张票放在自己的口袋里,一张票攥在手心里。那天演出到七点五十五分左右,穹顶的星空开始一颗、一颗地暗下去,可是有一颗光——正中央偏东南的那颗——一直没有灭, 那颗光的位置, 就是天琴座 α, 就是织女星。", 28, 250);
	play_A_tiantai_dubai(L"那时候你就应该明白的,你花了三年才明白。三年里你一直问自己:她是不是真的走了,她是不是,以某种方式,还在。今夜你明白了——她一直都在,她只是变成了另外一种形状。", 28, 300);
	play_A_tiantai_dubai(L"你把那张纸放回桌上,然后打开那本空白的日记本,翻到第一页。你从桌上的笔筒里拿起一支铅笔——不是钢笔,是铅笔,因为她曾经跟你说过,写下这一句话的时候用铅笔比较好, 写错了可以擦。你没打算写错, 你只是想遵守她说过的每一件小事。", 28, 250);
	play_A_tiantai_dubai(L"你在第一页的顶上,写下了一行字:「今天,我重新想起了她。」", 28, 300);
	play_A_tiantai_dubai(L"你写完,笔尖没有抬起来,你在那一行字下面,又停了很久。你有很多话想接着写,可是你知道,后面的每一天,都会自己写下去。你把笔放下了。",	28, 250);
	play_A_tiantai_dubai(L"你从椅子上站起来,走到窗前。", 28, 200);
	play_A_tiantai_dubai(L"三年了,窗外的这条街,没有什么变化。楼下那家开了很多年的便利店的灯还亮着,收银台里的人换了一个,但你不认识新来的这个,也不认识以前那个。夜风从没关严的窗缝里挤进来, 是七月末的风, 带着一点点潮气, 不冷。", 28, 200);
	play_A_tiantai_dubai(L"你抬起头。", 28, 200);
	play_A_tiantai_dubai(L"天琴座 α,中文名叫织女,距离地球二十五光年——你此刻看见的它,是二十五年前的它。二十五年前你三岁,她也三岁,那时候你们并不认识,住在同一座城市的两条不同的街上, 她那时候会抬头看星星吗 ? 你不知道。可是那一颗光, 在那一年就已经从她那颗星星那里出发了, 穿过二十五年的空, 今晚, 才到你的眼睛里。", 28,250);
	play_A_tiantai_dubai(L"你等了它二十五年,它也等了你二十五年。", 28, 300);
	play_A_tiantai_dubai(L"你看了它很久。", 28, 200);
	play_A_tiantai_dubai(L"眼眶有一点热,你没有让它掉下来——你已经答应过她,不哭。这三年你违约过很多次,一个人回家的路上、路过图书馆的时候、看到别人在望远镜前弯腰的时候, 你都哭过, 可是唯独今晚, 你不想哭。你想笑给她看, 你想让她知道, 你已经能笑着抬起头了。", 28, 300);
	play_A_tiantai_dubai(L"你轻轻地对那颗星星说:「你看,我来了。」", 28, 300);
	play_A_tiantai_dubai(L"声音很轻,可是你知道,二十五光年的距离,今夜是没有距离的。她答应过你——星星还会在这里——她做到了,那么你也要做到。", 28, 250);
	play_A_tiantai_dubai(L"果然,我和她的想法,是一样的——我想成为你的牛郎星。", 28, 300);
	show_the_jiejuDEzhimu(L"—— 两个月后 · 八月中旬 ——", L"街道 · 深夜", 2000);
	system("cls");
	Sleep(500);
	draw_the_Ade_street();
	play_A_tiantai_dubai(L"两个月过去了。", 28, 200);
	play_A_tiantai_dubai(L"你没有再拆过桌上那颗折纸星星——你在那一晚把它拆开、读完之后,又折了回去,然后放回原位,让它在你的桌上继续保持你已经保持了三年的那个形状。这三年里你一直保留着的那个形状, 你舍不得让它就这样再也不是形状。只有你自己知道, 你今夜要把它带走。", 28, 250);
	play_A_tiantai_dubai(L"是八月中旬。你查过——天琴座流星雨今夜过峰值,也就是说,今晚,天琴座 α是这一整年里最亮的一晚。她当年就跟你说过这件事, 是在天台上的某一个八月的傍晚, 你们并肩坐着, 她一边用小拇指指着西南方向的天空, 一边跟你解释一颗行将熄灭的白色巨星如何在结束前的最后几百万年里变得比原来还要亮。你那时没有把这句话记进心里, 因为你不明白她为什么讲这些, 因为你只想看她说话时候的样子, 因为你以为这样并肩坐着的傍晚以后还有很多个——可是不知道为什么, 这三年里, 这个日子你从来没有忘, 像是有什么东西替你把它记住了, 替你把它每一年都往前推。", 28, 300);
	play_A_tiantai_dubai(L"你把那颗折纸星星,轻轻地放进上衣的口袋。", 28, 200);
	draw_street_dongtai();
	play_A_tiantai_dubai(L"天文台的门是开的,你不知道谁在几年前把它敲坏的,也不知道为什么这些年里没有人来修。这栋建筑,除了你,大概不会有人还记得——天文系换了新的观测楼, 那栋楼在校区的另一头, 更亮、更新、更方便, 你偶尔从校门口路过的时候会远远地看见它顶上白色的圆顶, 像一颗放在山脊上的、亮着的、冷冷的鸡蛋。这一栋, 在小土丘顶上、油漆已经开始脱落的旧天文台, 已经很少有人上来了。", 28, 250);
	play_A_tiantai_dubai(L"你走上楼梯。楼梯还是那些楼梯,每一级石阶上都有一个凹下去的地方,是几十年的脚踩出来的。你和她当年经常走这条楼梯——她走得比你快,她从来不看脚下, 她一边爬一边跟你讲一些你后来才明白是重要的话, 而你那时候只是一边喘一边喊「慢一点」。她从来不慢下来, 可是每一次到平台的时候, 她都会停下, 回头, 等你,让你先走完最后几级, 然后你们再一起推开那扇天台的门。", 28, 300);
	play_A_tiantai_dubai(L"你今夜是自己一个人,你走得很慢,你不用喊「慢一点」了,因为你走得比她还慢,你也不用回头,因为身后没有人,你只是把一级一级的石阶,一级一	级地, 踩过去。", 28, 300);
	play_A_tiantai_dubai(L"你推开天台的门。夜风扑面而来,是七月末刚过的风,是八月刚开始的风,是她曾经说过「我最喜欢的那种风」的风。你在门口站了一会儿,让眼睛	适应了黑, 然后你抬起头。", 28, 300);
	show_the_jiejuDEzhimu(L"—— 天文台 · 门口 ——", L"楼梯", 2000);
	system("cls");
	Sleep(500);
	draw_the_Ade_stair();
	draw_stair_dongtai();
	show_the_jiejuDEzhimu(L"—— 天文台 · 天台 ——", L"夜风扑面", 2000);
	system("cls");
	Sleep(500);
	draw_the_Ade_tiantai();
	play_bgm("bgm/ending_a2.wav");
	play_A_tiantai_dubai(L"她今晚真的很亮。", 28, 300);
	play_A_tiantai_dubai(L"你花了三年才认得这颗星。这三年里,你抬过很多次头,可是有些晚上她被云遮住,有些晚上你自己在流泪,看不清;有些晚上你分明看见了她,可是你的心里那时候还有别的事, 那些别的事挡在你和她之间, 让你看她的时候像是隔了一层水。今夜没有云, 今夜是这三年里最清楚的一晚。", 28, 300);
	play_A_tiantai_dubai(L"天琴座 α,中文名叫织女,距离地球二十五光年。你此刻看见的这颗光,是二十五年前的它——二十五年前你三岁,她也三岁,你们住在同一座城市的两	条不同的街上, 不知道彼此存在, 可是那一年, 那颗光就已经从她那颗星星那里出发了, 穿过了二十五年的、比你的一生还要长的空, 穿过了她的病、她的手术、她的离开, 穿过了你的每一个不敢抬头的夜晚, 今晚, 才落到你的眼睛里。", 28, 350);
	play_A_tiantai_dubai(L"你把手伸进上衣的口袋,握住那颗折纸星星,你没有拿出来,你只是让它,在你的口袋里,和你一起,看着这颗二十五光年之外的、二十五年前就出发	的光。", 28, 300);
	play_A_tiantai_dubai(L"你在天台上站了很久。你以为你今夜是来看她的,你没想到她也在等你。", 28, 300);
	play_A_tiantai_dubai(L"天台正中的那台望远镜,还在原位。", 28, 200);
	play_A_tiantai_dubai(L"它比你记忆里的更旧了,镜筒的漆掉了几块,露出下面暗青色的金属;三脚架的一条腿,不知道什么时候被谁撞过一下,微微有一点歪,让整台望远镜看起来像是一个上了年纪的、不太肯低头的、还在坚持看天的老人。可是它还能用——你走到它跟前, 把手放在镜筒上, 是冰的, 是那种在夏夜里也仍然冰的、金属的冰, 是被她的手, 和你的手, 和你们之间这三年的时间, 一起摸过的冰。", 28, 350);
	play_A_tiantai_dubai(L"你今夜是来看星星的,你想用这台老望远镜,替她,再看一次她说过的那颗最亮的织女。你调整了一下镜筒的角度,让目镜对准了西南方向的天空——这个方向, 是她当年一遍又一遍指给你看的方向, 是你哪怕闭着眼睛也不会调错的方向。你俯下身, 把眼睛凑到目镜上——你看见她了。", 28, 350);
	play_A_tiantai_dubai(L"二十五光年之外的那颗光,通过这台旧望远镜的镜片,被放大了、拉近了、变得比肉眼看时更清晰、更冷、更亮。你在目镜前站了很久,像是要把这	些年里没有看够的、被自己错过的、被云挡住的每一个抬头的夜晚, 一并补回来。", 28, 300);
	play_A_tiantai_dubai(L"你在望远镜前蹲了下来。你不知道你为什么蹲下来——你只是觉得,你今夜不只是想通过目镜看她,你还想看看这台老望远镜本身,看看它的三脚架,	看看它底座上积了多少灰, 看看这三年里有没有人来动过它。", 28, 300);
	play_A_tiantai_dubai(L"你的手电照到底座的时候,你忽然停住了。", 28, 300);
	play_A_tiantai_dubai(L"底座和水泥地面之间,有一条极窄的缝隙——那条缝里,塞着什么东西。", 28, 300);
	play_A_tiantai_dubai(L"你把手指伸进去,碰到了纸的边缘。你小心翼翼地把它抽出来——是一张折好的纸,折了很多层,压得很扁,像是被塞进去之后,被底座的重量,压了很久很久。", 28, 300);
	play_A_tiantai_dubai(L"你的手停在那里。你没有马上展开它。你把它捧在手心里,用手电的光照着它——纸已经发黄了,边缘有一点点卷,折痕压得很深,像是折它的人当年,把每一道折痕都用指甲反复压过。你的心跳得很快, 快到你听得见自己的呼吸——因为你认得这种折法。你认得这种把纸叠成很小很小、再一层一层压实的方式。这是她的方式。这是她当年折那颗星星的时候, 用的同一种方式。", 28, 350);
	play_A_tiantai_dubai(L"你不敢展开它。你怕展开之后,里面什么都没写。你也怕展开之后,里面写的是你三年来一直想听到、却一直没有听到的那些话。你不知道哪一种	更让你害怕。", 28, 300);
	play_A_tiantai_dubai(L"你深深地吸了一口气。", 28, 400);
	play_A_tiantai_dubai(L"你把它展开了。", 28, 300);
	play_A_tiantai_dubai(L"是她的字。你一眼就认得出来——是她那种,「你」字最后一笔向下撇得比常规多一点的字,是她那种,笔画简单、但每一笔都很用力的字。纸上有些地方的墨迹被风吹得有一点点晕开, 有些地方的笔画因为纸被风掀起来而断了一下又接上, 你能想象她当年坐在这里, 一只手压着纸, 一只手写字, 风一直在吹, 她一直在写。", 28,350);
	play_A_tiantai_dubai(L"她写了很多。", 28, 400);
	play_A_tiantai_dubai(L"那是她的字。", 28, 300);
	play_A_tiantai_dubai(L"你一眼就认得出来——是她那种,「你」字最后一笔向下撇得比常规多一点的字,是她那种,笔画简单、但每一笔都很用力的字,是她那种,写字的时候会把纸压得比一般人低一点、下巴几乎要碰到桌面的字。", 28, 300);
	play_A_tiantai_dubai(L"你的手在抖,你几乎握不住那张纸,你用另一只手扶住膝盖,让手电的光,尽量不动。", 28, 300);
	play_A_tiantai_dubai(L"她写在上面的字,一行一行,是这样的——", 28, 300);
	play_A_tiantai_dubai(L"「如果你看到这封信——说明你还是来了。」", 28, 350);
	play_A_tiantai_dubai(L"「——我就知道你会来。」", 28, 400);
	play_A_tiantai_dubai(L"你的呼吸停了了半拍。你不明白她当年是什么时候来这里藏的,你不明白她当年为什么要藏,你也不明白她当年怎么就「知道」你多年后会在今晚来	到这里——你只能继续往下看, 因为你的手, 已经不肯把这张纸从眼前放下了。", 28, 300);
	play_A_tiantai_dubai(L"「——我想，对你而言，这一定是人生中最为艰难的时刻。你一定孤零零地身处在那个最为可怕的黑夜里。所以，我想把你从那绝望的黑夜中拯救出来。把你带回到阳光普照的世界。所以，我来了，我穿越时空来拯救你了」," ,28, 450);
	play_A_tiantai_dubai(L"「这封信是我从医院跑出来的那天写的。那天下过雨,水泥地是湿的,凉的,我从病房出来的时候没有告诉任何人。我一个人上来,坐在这台望远镜的底座旁边, 把这张纸铺在膝盖上, 写了差不多一个小时。风很大, 纸一直被吹起来, 我用手压着, 写一行就要停一会儿, 等风小了再继续。你不知道在风里写字有多难——笔会被吹歪,我的字本来就写得不好看, 在风里写, 更不好看, 可是我想留一点东西, 留给以后。」", 28, 350);
	play_A_tiantai_dubai(L"「——我知道我可能好不起来了。」", 28, 400);
	play_A_tiantai_dubai(L"「——我也知道,你可能没办法在最后一刻,赶到医院。」", 28, 400);
	play_A_tiantai_dubai(L"「所以我在这里,替你,替我,先做了一件事。」", 28, 400);
	play_A_tiantai_dubai(L"「你还记得吗?那天我拉你上来的时候,天已经很冷了。我们坐在这里,吃过一整袋没有味道的膨化食品,是你从校门口那个便利店买的,买错了牌子。可是我们没有下去换, 因为你说『上来一次不容易』。那时你还不知道, 你说这句话的时候, 我心里在想什么。」", 28, 400);
	play_A_tiantai_dubai(L"「我心里想的是——『以后每次冷,我都想跟他一起坐在这里。』」", 28, 400);
	play_A_tiantai_dubai(L"「——我一直没有告诉你。」", 28, 400);
	play_A_tiantai_dubai(L"「因为我知道,如果我说了,后来的『以后』没有来的时候,你会更难过。」", 28, 300);
	play_A_tiantai_dubai(L"「——可是后来,『以后』真的没有来。」", 28, 400);
	play_A_tiantai_dubai(L"「我有无数次想要向你坦白，想要向你表明我的心意，但是——不过没事，因为我知道，在无数由由命运交织的时空中，一定有一个你会来的」", 28, 300);
	play_A_tiantai_dubai(L"「抬起头。她今晚最亮——是我当年就算好的。」", 28, 400);
	play_A_tiantai_dubai(L"「不是每一年八月,她都这么亮。是这一年八月。是今晚。是你今晚站在这里的这一秒。」", 28, 300);
	play_A_tiantai_dubai(L"「——是我算好的,你会在今晚来。」", 28, 400);
	play_A_tiantai_dubai(L"「我知道你要花几年。我知道你不会一走就来到这里,我知道你要一个人在书房里,反反复复地看着桌上那颗折纸星星,反反复复地不敢拆开它,反反复复地跟自己说『明天再说』、跟自己说『我还没准备好』、跟自己说『再多留她一天在这里』。我知道你会把手机从抽屉里拿出来, 又放回去, 来来回回很多次, 可是那条语音留言, 你三年里一次都没有点开。我知道你会站在窗前看织女星, 可是那些晚上, 你的眼睛没有真的看她, 你的眼睛看的是我, 是你自己, 是三年前你没有接的那 17 次电话。」",28, 350);
	play_A_tiantai_dubai(L"「——我都知道。」", 28, 400);
	play_A_tiantai_dubai(L"「我算过这几年,你会在哪一天,准备好走出那扇书房的门。我算过你走出门以后,会往哪里去。我算过你去了以后,会不会走到这栋旧的天文台。我算过你走到之后, 会不会走上这条楼梯, 会不会推开天台的门, 会不会蹲在这台望远镜的底座旁边, 会不会看见底座下面藏着的这封信。」", 28, 350);
	play_A_tiantai_dubai(L"「——所以我把这封信,藏在这里。」", 28, 400);
	play_A_tiantai_dubai(L"「——所以我说,我一直在等你。」", 28, 400);
	play_A_tiantai_dubai(L"「我知道我在医院的最后一次跟你说话的时候,对你说过——『如果我走了,不要回来找我,往前走,不要总是抬头,不要总是想我。』」", 28, 300);
	play_A_tiantai_dubai(L"「——那是骗你的。」", 28, 450);
	play_A_tiantai_dubai(L"「我怕你会难过,我怕你会一直不肯放下,我怕你会因为回来找我,就再也没办法往前走,所以我跟你说不要回来,所以我跟你说往前走,所以我跟你说别抬头——可是你今夜站在这里, 读到这封信, 你就知道了, 那些话每一句都是骗你的。因为我在医院对你说完那些话的第二天, 我就跑到这里来, 一个人, 坐在这台望远镜的底座旁边, 把『我一直在等你』这句话, 写在了这封只有你今夜才会找到的信里。」", 28, 300);
	play_A_tiantai_dubai(L"「——我怕说『我爱你』三个字太重,你以后一个人的时候会背不动,所以我从来没有说过。」", 28, 300);
	play_A_tiantai_dubai(L"「可是——你既然已经走到这里了,你既然已经摸到了这行字,你既然已经花了三年,在没有我的世界里,一个人,把那些没接的电话、那些没写的日记、那些没拆的星星, 一样一样地重新走了一遍——那我今夜就说了。」", 28, 300);
	play_A_tiantai_dubai(L"「我爱你。」", 28, 500);
	play_A_tiantai_dubai(L"「我一直爱你。」", 28, 500);
	play_A_tiantai_dubai(L"「就算变成了一颗二十五光年之外的、你今晚终于抬头看见的星,我也在爱你。」", 28, 400);
	play_A_tiantai_dubai(L"-------", 28, 400);
	play_A_tiantai_dubai(L"「啊啊……啊啊啊啊……」堵在你心上的那个栓子彷佛被汹涌的情绪冲走似的，完全止不住", 28, 400);
	play_A_tiantai_dubai(L"「P.S.」", 28, 300);
	play_A_tiantai_dubai(L"「这位同学。」", 28, 300);
	play_A_tiantai_dubai(L"「就是你——就是这个现在蹲在望远镜下面、用手电照着我写的的这些字、眼睛已经红了、手已经在抖、连呼吸都开始不太顺的这位同学。」", 28,300);
	play_A_tiantai_dubai(L"「我记得我跟你说过——不要难过,不要哭,不要一个人熬夜,不要总是抬头,不要回来找我,不要不要不要——」", 28, 300);
	play_A_tiantai_dubai(L"「——可是你今晚,一条都没有做到。」", 28, 350);
	play_A_tiantai_dubai(L"「你难过了,你哭了,你熬夜到了这么晚,你抬头看了织女星,你走了那么远的路,爬了那么多级楼梯,一个人推开了那扇天台的门,一路走到这台旧望远镜的下面, 蹲下来, 一行一行地读完了我三年前写的这封信——你没有做到我要求你的任何一条。一条, 都没有做到。」", 28, 300);
	play_A_tiantai_dubai(L"「——可是我要告诉你——」", 28, 400);
	play_A_tiantai_dubai(L"「谢谢你。」", 28, 500);
	play_A_tiantai_dubai(L"「谢谢你,一条都没有做到。」", 28, 500);
	play_A_tiantai_dubai(L"「谢谢你,没有忘记我;谢谢你,回来找我;谢谢你,今夜替我坐在这里;谢谢你,替我抬起头;谢谢你,替我看着二十五光年之外那一颗光;谢谢你,在这三年里, 一次都没有真的把我放下过——虽然你自己一直以为你已经放下了, 虽然你自己一直以为你已经『走出来了』, 虽然你自己一直以为你只是『过着日子』——可是你今晚走到这里, 就说明你从来没有放下过, 你从来没有走出来过, 你从来没有真的忘记过。」", 28, 350);
	play_A_tiantai_dubai(L"「——还有一件事。」", 28, 400);
	play_A_tiantai_dubai(L"「我曾经和你并肩坐在这里,一遍又一遍地告诉你我是织女星,是 Vega,是天琴座	α, 是夏季大三角里最亮的那一颗, 是你迟早要抬头去看的那颗——我告诉你这些的时候, 我心里一直藏着另外一句话, 我一直没有对你说过。因为我知道, 如果我说了, 那句话就会替我在你的心里, 留一辈子。我怕留下一辈子的东西你以后一个人背不动, 所以我一直没有说。」", 28, 300);
	play_A_tiantai_dubai(L"「可是——今夜你既然已经走到了这里,你既然已经愿意替我坐一会儿,替我抬头,替我看星,你既然已经在这三年里,一次都没有真的把我放下过——」",28, 300);
	play_A_tiantai_dubai(L"「————」", 28, 400);
	play_A_tiantai_dubai(L"「我想成为你的 Vega。」", 28, 500);
	play_A_tiantai_dubai(L"「我想成为你抬头就能看见的那颗星。」", 28, 400);
	play_A_tiantai_dubai(L"「我想成为——你二十五年前就已经开始爱着、只是那时候还不知道那颗光叫什么名字的、那颗星。」", 28, 350);
	play_A_tiantai_dubai(L"「——所以你要抬头,好吗?」", 28, 400);
	play_A_tiantai_dubai(L"「不是今夜。是每一夜。」", 28, 450);
	play_A_tiantai_dubai(L"「——因为我一直,一直,一直都在。」", 28, 500);
	play_A_tiantai_dubai(L"「我愿让那些你以为走不出的雨季，成为能滋养你的生命的河流---」",28,450);
	play_A_tiantai_dubai(L"「我愿与你一起成为那道流星，划过几光年外的宇宙---」", 28, 450);
	play_A_tiantai_dubai(L"「如果有一天,你虚弱到连眼泪都流不出来——」", 28, 400);
	play_A_tiantai_dubai(L"「不要紧。」", 28, 400);
	play_A_tiantai_dubai(L"「你抬起头就好。」", 28, 400);
	play_A_tiantai_dubai(L"「二十五光年之外那颗光,你看得见的。」", 28, 300);
	play_A_tiantai_dubai(L"「它从我这里出发的时候,我还在。」", 28, 350);
	play_A_tiantai_dubai(L"「它落到你眼睛里的时候,我已经不在了。」", 28, 400);
	play_A_tiantai_dubai(L"「可是它在路上的那二十五年里——我一直都在。」", 28, 450);
	play_A_tiantai_dubai(L"「所以你抬头的时候,让它落进眼睛里。」", 28, 400);
	play_A_tiantai_dubai(L"「我想成为你的Vega。」", 28, 500);
	play_A_tiantai_dubai(L"「我想替你把这三年里没有流完的,一滴一滴地流完。」", 28, 400);
	play_A_tiantai_dubai(L"「我想把你心里那点咸给冲开。」", 28, 400);
	play_A_tiantai_dubai(L"「我想把你送到明天早上——送回那个还有太阳的地方。」", 28, 450);
	play_A_tiantai_dubai(L"「然后——」", 28, 400);
	play_A_tiantai_dubai(L"「我想成为你的明天。」", 28, 500);
	play_A_tiantai_dubai(L"——————————", 28, 250);
	play_A_tiantai_dubai(L"你读完了。", 28, 400);
	play_A_tiantai_dubai(L"手电的光还照在那张纸上,可是你的眼睛已经看不清了,因为泪水已经把那些字模糊成了一片浅浅的、抖动的、不再是字的光。你没有把那张纸放下——你没有力气把它放下, 你甚至没有力气把它移开一寸, 你只是让手电的光继续照着, 让她那些三年前写下来的、一直等着你今夜来读的字, 继续在你眼前, 慢慢地、一层一层地	融化成你的眼泪。", 28, 400);
	play_A_tiantai_dubai(L"你慢慢地蹲了下来,你没有出声,你把额头轻轻地靠在了那个冰凉的望远镜底座上,你的手还握着那封信,你的另一只手还握着口袋里那颗折纸星星——你就这样, 以一个不太像是在哭的姿势、一个更像是在拥抱这台早已生锈的、老旧的、可是替她保留了三年秘密的望远镜的姿势, 哭了。", 28, 400);
	play_A_tiantai_dubai(L"你已经不知道你哭了多久。天台上没有人,风一直在吹,你的眼泪一滴一滴掉在水泥地上,掉在了三年前她一个人坐在这里写信的时候可能也曾经掉过的那些眼泪的同一块水泥地上。你没有说话, 你不需要说话——她已经替你把这三年里你没能说出口的每一句话, 都替你说完了。", 28, 400);
	play_A_tiantai_dubai(L"你抬起头。", 28, 400);
	play_A_tiantai_dubai(L"织女星还在原位,她比刚才更亮了一点——也可能是你的眼睛已经习惯了黑,也可能是她真的更亮了。你已经不需要弄清楚是哪一种,因为无论是哪一种, 她都在。", 28, 400);
	play_A_tiantai_dubai(L"你从口袋里,把那颗折纸星星拿了出来,轻轻地,放在了望远镜的三脚架下面,让她替你,再看一会儿这颗二十五光年之外的、今晚是这一整年里最亮的、她当年计算好了会在你今夜抬头的这一秒最亮的光。", 28, 400);
	play_A_tiantai_dubai(L"你转过身,慢慢地,一级一级地,走下楼梯。夏夜的风还在吹。", 28, 400);
	play_A_tiantai_dubai(L"向前迈出一步，强烈的头晕便立刻袭来，我摇摇晃晃地用手扶住墙壁。我有些担心自己那皮包骨一般过分纤细的手臂会不会断掉，膝盖也在不停地发抖。我再次向前迈出了一步。双腿都如同灌了铅一般沉重。我强撑着不让自己倒下。要是在这里倒下了的话，我想我就再也没法站起来了。我一步一步地向前缓慢迈进。就像是在沼泽中艰难行进。我走上了马路。来来往往的汽车都在飞快地穿行。", 28, 450);
	play_A_tiantai_dubai(L"今后,我会怎样呢。", 28, 400);
	play_A_tiantai_dubai(L"我不知道。", 28, 450);
	play_A_tiantai_dubai(L"可是只要慢慢地好起来就可以了。", 28, 400);
	play_A_tiantai_dubai(L"楼下那盏坏了的路灯,只要有人来换就可以了。", 28, 350);
	play_A_tiantai_dubai(L"街对面那家关掉的面馆,只要有人重新开起来就可以了。", 28, 350);
	play_A_tiantai_dubai(L"关不严的那扇窗,只要修好就可以了。", 28, 350);
	play_A_tiantai_dubai(L"抽屉里那部手机,只要有一天敢开机就可以了。", 28, 400);
	play_A_tiantai_dubai(L"那盒过期的药,只要有一天舍得扔就可以了。", 28, 400);
	play_A_tiantai_dubai(L"失去某些东西的空白,不会永远疼下去。", 28, 400);
	play_A_tiantai_dubai(L"历经漫长时日,那些空白也终有一天会被填上。", 28, 350);
	play_A_tiantai_dubai(L"不是被相同的东西填上，而是被别的，更有意义的事物填上", 28, 400);
	play_A_tiantai_dubai(L"而那些别的东西,也许会比原来的更好看。", 28, 450);
	play_A_tiantai_dubai(L"就像那台三脚架歪了、漆掉了几块,可是今夜还能对准西南方向的旧望远镜那样。", 28, 400);
	play_A_tiantai_dubai(L"就像那扇被人敲坏了、这些年没有人来修、所以今夜是开着的天文台的门那样。", 28, 400);
	play_A_tiantai_dubai(L"就像那张被拆开过很多次、纸的纤维已经软化了、可是每一次都还能折回星星的浅蓝色的纸那样。", 28, 400);
	play_A_tiantai_dubai(L"就像那颗也许早就熄灭了、可是今晚是这一整年里最亮的星那样。", 28, 500);
	play_A_tiantai_dubai(L"成为某一个不认识你的人,某一个夜晚抬头时看见的那颗光。", 28, 450);
	play_A_tiantai_dubai(L"呐，你知道吗", 28, 450);
	play_A_tiantai_dubai(L"我不想成为你身体的一部分。那太重了,你背不动。", 28, 400);
	play_A_tiantai_dubai(L"我也不想成为你的记忆——", 28, 350);
	play_A_tiantai_dubai(L"记忆会掉的。这件事我已经知道了。", 28, 500);
	play_A_tiantai_dubai(L"——————", 28, 450);
	play_A_tiantai_dubai(L"她答应过你的:星星,还会在这里。她做到了。你也做到了。", 28, 500);
	play_A_tiantai_dubai(L"果然，我的想法她一样——", 28, 400);
	play_A_tiantai_dubai(L"我想成为你的那颗星————",28,400);
	play_A_tiantai_dubai(L"完——", 28, 400);
	gotoxy(47, 0);
	setColor(14);
	printemoji(L"✦");
	Sleep(3000);
	draw_A_liuxing();
	Sleep(3000);
	play_A_houji();
	return_to_titile(0);
}

void draw_jieju_kaichangxing(int temp) {
	setColor(temp);
	gotoxy(40, 2);
	printemoji(L"·   .   ✦   .   ·   ✦   .   ·   ✦   .   ·");
	gotoxy(40, 20);
	printemoji(L"·   .   ✦   .   ·   ✦   .   ·   ✦   .   ·");
}
void fenqi_AB() {
	stop_bgm();
	system("cls");
	Sleep(500);
	int color_tatol[3] = { 8,6,14 };
	for (int i = 0; i < 3; i++) {
		draw_jieju_kaichangxing(color_tatol[i]);
		Sleep(200);
	}
	draw_jieju_kaichangxing(6);
	Sleep(400);
	setColor(8);
	gotoxy(39, 4);
	printemoji(L"═══════════════════════════════════════════");
	Sleep(300);
	setColor(15);
	gotoxy(52, 6);
	printemoji(L"—— 终章 ——");
	Sleep(500);
	setColor(8);
	gotoxy(39, 8);
	printemoji(L"═══════════════════════════════════════════");
	Sleep(600);
	int vega_color[6] = { 6, 14, 6, 14, 6, 14 };
	for (int i = 0; i < 6; i++) {
		setColor(vega_color[i]);
		gotoxy(59, 10);
		printemoji(L"✦");
		Sleep(260);
	}
	Sleep(300);
	setColor(7);
	gotoxy(49, 12);
	delay_with_Chinese(L"你已走过那六个夜晚——", 70);
	Sleep(600);
	setColor(8);
	gotoxy(46, 13);
	delay_with_Chinese(L"桌上那三样东西,已经等了三年。", 70);
	Sleep(800);
	setColor(11);
	gotoxy(50, 15);
	printf("记忆的碎片   %d / 18", total_size);
	Sleep(1000);
	if (total_size >= 18) {
		setColor(14);
		gotoxy(51, 17);
		delay_with_Chinese(L"—— 星光彼岸 ——", 140);
		Sleep(700);
		setColor(7);
		gotoxy(44, 18);
		delay_with_Chinese(L"她留下的每一样东西,你都拾起来了。", 70);
		Sleep(700);
		setColor(6);
		gotoxy(51, 19);
		delay_with_Chinese(L"今夜,你准备好了。", 70);
		Sleep(1200);
		draw_jieju_kaichangxing(14);
		Sleep(700);
		gotoxy(51, 22);
		setColor(8);
		printemoji(L"[ 按 空 格 继 续 ]");
		clearbutter();
		while (_getch() != ' ') {

		}
		play_jieju_A();
	}
	else {
		setColor(8);
		gotoxy(50, 17);
		delay_with_Chinese(L"—— 遥远的暗星 ——", 140);
		Sleep(700);
		setColor(7);
		gotoxy(47, 18);
		delay_with_Chinese(L"还有一些东西,你没有拾起来。", 70);
		Sleep(700);
		setColor(8);
		gotoxy(45, 19);
		delay_with_Chinese(L"可是今夜,你还是要坐回那张桌前。", 70);
		Sleep(1200);
		draw_jieju_kaichangxing(8);
		Sleep(700);
		gotoxy(51, 22);
		setColor(8);
		printemoji(L"[ 按 空 格 继 续 ]");
		clearbutter();
		while (_getch() != ' ') {

		}
		play_jieju_B();
	}
}

int main() {
	hideCursor();
	char bg[20][50];
	int ax, ay, bx, by, cx, cy;
	int flagA = 0, flagB = 0, flagC = 0;
	int px, py;
	char cursecene[70];
	play_bgm("bgm/title.wav");
	begin_title();
	show_the_big_zhi();
	create_time();
	get_to_the_hall(cursecene, bg, &ax, &ay, &bx, &by, &cx, &cy, &px, &py,
	&flagA, &flagB, &flagC);
	while (1) {
		if (strcmp(cursecene, "hall.txt")!= 0) {
			int taken = flagA + flagB + (flagC == 3 ? 1 : 0);
			setColor(11);
			gotoxy(35, 20);
			printf("拾取: %d/3", taken);
		}
		setColor(8);
		gotoxy(0, 24);
		printf("  WASD 移动  E 交互  B 回看  Q 返回/退出  ");
		setColor(7);
		gotoxy(px, py);
		printf("@");
		draw_memory_secene();
		int ending_c = 0;
		while (!_kbhit()) {
			Sleep(50);
			int temp = now_time();
			if (temp == -1) {
				ending_c = 1;
				break;
			}
			if (temp == 1) {
				draw_memory_secene();
			}
		}
		if (ending_c) {
			stop_bgm();
			system("cls");
			Sleep(500);
			gotoxy(35, 12);
			setColor(7);
			printemoji(L"—— 终章 · 星尘归海 ——");
			Sleep(2000);
			play_jieju_C();
			break;
		}
		char c = _getch();
		gotoxy(px, py);
		if (bg[py][px] == 'A' || bg[py][px] == 'B') {
			setColor(14);
			printf("%c", bg[py][px]);
		}
		else if (bg[py][px] == 'C' || bg[py][px] == '?') {
			printf(" ");
		}
		else if (bg[py][px] != '\0') {
			setColor(get_senece_color(bg[py][px], cur_chapter));
			printf("%c", bg[py][px]);
		}
		else if (bg[py][px] == '\0') {
			printf(" ");
		}
		if (c == 'q') {
			if (strcmp(cursecene, "hall.txt") == 0) {
				break;
			}
			else {
				get_to_the_hall(cursecene, bg, &ax, &ay, &bx, &by, &cx, &cy, &px, &py,
					&flagA, &flagB, &flagC);
			}
		}
		else if (c == 'b') {
			begin_conver_history();
			system("cls");
			load_secene(cursecene, bg, &ax, &ay, &bx, &by, &cx, &cy);
			if (strcmp(cursecene, "hall.txt") == 0) {
				draw_the_beginning_room();
			}
			else {
				if (flagA == 1) { 
					bg[ay][ax] = ' '; 
					gotoxy(ax, ay); 
					printf(" "); 
				}
				if (flagB == 1) { 
					bg[by][bx] = ' '; 
					gotoxy(bx, by); 
					printf(" "); 
				}
				if (flagC == 2) { 
					setColor(4);	
					gotoxy(cx, cy); 
					printf("C"); 
				}
				else if (flagC == 3) { 
					bg[cy][cx] = ' '; 
					gotoxy(cx, cy); 
					printf(" ");
				}
			}
		}
		else if (c == 'e') {
			if (strcmp(cursecene, "hall.txt") == 0) {
				if (hall_react(px, py)) {
					fenqi_AB();
					break;
				}
				for (int i = 0; i < 6; i++) {
					int curchapter = i + 1;
					if (!game_begin_locked[curchapter]) {
						continue;
					}
					if (isreact(px, py, difsecene[i].x, difsecene[i].y)) {
						get_to_the_secene(cursecene, bg, &ax, &ay, &bx, &by, &cx, &cy, &px, &py,
						&flagA, &flagB, &flagC, curchapter);
						break;
					}
				}
			}
			else {
				item_with_conversation* item = item_everyconversition[cur_chapter - 1];
				if (!flagA && isreact(px, py, ax, ay)) {
					playconversation(&item[0], 14);
					insert_tail(&item[0], cur_chapter);
					bg[ay][ax] = ' ';
					gotoxy(ax, ay); setColor(15); printf(" ");
					flagA = 1;
				}
				else if (!flagB && isreact(px, py, bx, by)) {
					playconversation(&item[1], 14);
					insert_tail(&item[1], cur_chapter);
					bg[by][bx] = ' ';
					gotoxy(bx, by); setColor(15); printf(" ");
					flagB = 1;
				}
				else if (flagC == 0 && isreact(px, py, cx, cy)) {
					cleararray(21, 5);
					draw_dialog(0, 21, 60, 5);
					gotoxy(2, 22);
					setColor(13);
					delay_with_Chinese(L"......", 80);
					gotoxy(2, 23);
					setColor(15);
					delay_with_Chinese(L"你察觉到附近好像有什么东西……", 80);
					gotoxy(55, 24);
					setColor(8);
					printf("▼");
					clearbutter();
					_getch();
					cleararray(21, 5);
					flagC = 1;
				}
				else if (flagC == 1 && isreact(px, py, cx, cy)) {
					cleararray(21, 5);
					draw_dialog(0, 21, 60, 5);
					gotoxy(2, 22);
					setColor(13);
					delay_with_Chinese(L"......", 80);
					gotoxy(2, 23);
					setColor(15);
					delay_with_Chinese(L"你似乎要看清了，即使它像暗星一样...", 80);
					gotoxy(55, 24);
					setColor(8);
					printf("▼");
					clearbutter();
					_getch();
					cleararray(21, 5);
					flagC = 2;
					setColor(4);
					gotoxy(cx, cy);
					printf("C");
				}
				else if (flagC == 2 && isreact(px, py, cx, cy)) {
					playconversation(&item[2], 14);
					insert_tail(&item[2], cur_chapter);
					bg[cy][cx] = ' ';
					gotoxy(cx, cy); setColor(15); printf(" ");
					flagC = 3;
				}

			}
		}
		else if (c == 'w' && py > 0 && !checkwall(bg[py - 1][px]))py--;
		else if (c == 'a' && px > 0 && !checkwall(bg[py][px - 1]))px--;
		else if (c == 's' && py < 19 && !checkwall(bg[py + 1][px]))py++;
		else if (c == 'd' && px < 47 && !checkwall(bg[py][px + 1]))px++;
	}
	clear_and_see_you();
	stop_bgm();
	gotoxy(0, 22);
	return 0;
}
