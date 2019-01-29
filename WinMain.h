#ifndef _winmain_
#define _winmain_

extern void game_init(void);
extern void title_init(void);
extern void score_init(void);
extern void entry_init(void);
//ウィンドウハンドル
HWND hwnd;

//各クラス
Ctask task;
Dtool draw;
Stool sound;
Atool audio;

#endif _winmain_