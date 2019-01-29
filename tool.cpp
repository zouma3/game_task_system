///////////////////////////////////////////////////////////////////////////
//		システムツールクラス　ＣＰＰ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#include "main.h"

//フレームをカウント
void FrameCnt(void){
	static DWORD NowTime=0,PrevTime=0;
	static char text[10];
	HDC hdc;
	NowTime = timeGetTime();
	sprintf(text,"FPS:%3.0f",(float)1000 / (NowTime - PrevTime));

	draw.GetDC (0,&hdc);
	TextOut(hdc,0,0,text,strlen(text));
	draw.ReleaseDC (0,hdc);

	PrevTime = NowTime;
}
//ランダム
int randamize(int low, int high)
{
	return ((int)((high - low + 1) * (rand() / 32767.1) + low));
}
//エラー時の処理
BOOL Error(HWND hwnd,char* message){
	MessageBox(hwnd, message, "エラー発生", MB_OK);
	PostQuitMessage(0);
	return FALSE;
}

/* CPUID の存在チェックします */
BOOL IsCPUID(){
	//チェック用フラグ
    DWORD dwPreEFlags, dwPostEFlags;
	////ＩＤのチェック////
    //インラインアセンブラ開始//
    _asm {
        //EFlags の値の取得
        pushfd
        pop     eax
        mov     dwPreEFlags, eax
        //CPUID 命令の存在のチェック (ID フラグのチェック)
        xor     eax, 00200000h
        push    eax
        popfd
        //EFlags の値の取得
        pushfd
        pop     eax
        mov     dwPostEFlags, eax
    }
	//フラグが同じならば
    if(dwPreEFlags == dwPostEFlags)
        return FALSE;
    return TRUE;
}

/* MMX テクノロジサポートのチェックします */
BOOL IsMMX(){
	//チェック用フラグ
    DWORD dwRetEDX;
    // CPUID 命令のチェック
    if(!IsCPUID()){
		Error(NULL,"MMXがサポートされていません");
		return FALSE;
	}
    ////MMX テクノロジのチェック////
    //インラインアセンブラ開始//
    _asm {
		//eaxレジスタに１を代入
        mov     eax, 1
		//eaxが１でＣＰＵＩＤを実行するとフラグが帰ってくる
        cpuid
        //MMX命令は２４ビット目の部分にフラグが立つ
		and     edx, 00800000h
		//チェック用変数に代入
        mov     dwRetEDX, edx
    }
	//チェックをします
    if(dwRetEDX) return TRUE;
    return FALSE;
}
