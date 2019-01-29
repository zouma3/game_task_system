///////////////////////////////////////////////////////////////////////////
//		システムツールクラス　Ｈ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#ifndef _tool_
#define _tool_

//プロトタイプ宣言
void FrameCnt(void);
int randamize(int low, int high);
BOOL Error(HWND hwnd,char* message);

BOOL IsCPUID();
BOOL IsMMX();

#endif _tool_
