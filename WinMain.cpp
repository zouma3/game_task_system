//メイン（ウィンドウ作成）
#include"main.h"
#include"WinMain.h"

/*/////////////////////////////////////////////////////////////////////////
　　 			 ＜　２Ｄシューティング　タスクバージョン　＞
  ２Ｄシューティングを擬似タスク処理を使用して書き直したシューティング  
/*/////////////////////////////////////////////////////////////////////////

//動作制限用デファイン
#define WAIT 33
//アクティブフラグ
char ac_flag=0;

//ウィンドウ操作用コールバック関数
LRESULT CALLBACK WindowFunc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg){
	case WM_CREATE:
		//ＩＤのチェック
		IsCPUID();
		//ＭＭＸのチェック
		IsMMX();

		//確認のため
//		if(IsMMX())Error(hwnd,"ＭＭＸをサポートしています。");
	
		//初期設定
		draw.Init(hwnd);
		sound.Init(hwnd);
		audio.Open(hwnd);
		break;
	case WM_ACTIVATEAPP:
		//リストア、再読込（再描画）
//		draw.BackRestore ();
		break;
	case WM_ACTIVATE:
		switch(LOWORD(wParam)){
		case WA_ACTIVE:
			ac_flag=0;
			break;
		case WA_CLICKACTIVE:
			ac_flag=0;
			break;
		case WA_INACTIVE:
			ac_flag=1;
			break;
		}
		break;
	case MM_MCINOTIFY:
		//MCIから終了通知がきた時
		if(wParam == MCI_NOTIFY_SUCCESSFUL)audio.RePlay();
		break;
	case WM_PAINT:
		break;
	case WM_KEYDOWN:
		//メインキーの判定
		switch(wParam){
		case VK_ESCAPE:
			//終了
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY://終了されるとき実行
		break;		
	}
	return  DefWindowProc(hwnd,msg,wParam,lParam);
}	

//ウィンメイン（ウィンドウ作成等）
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpszArgs, int nCmdshow)
{
	WNDCLASSEX   wcx;	
	/*ウインドウクラスの名前*/
	char className[]="task";
	MSG  msg;

	/*ウィンドウクラスＥＸの定義*/
	wcx.cbSize=sizeof(WNDCLASSEX);
	wcx.style=CS_DBLCLKS;
	wcx.lpfnWndProc=WindowFunc;
	wcx.cbClsExtra=0;
	wcx.cbWndExtra=0;
	wcx.hInstance=hInst;
	wcx.hIcon=(HICON)LoadImage(hInst,MAKEINTRESOURCE(IDI_ICON1),IMAGE_ICON,32,32,LR_DEFAULTCOLOR);
	wcx.hIconSm=(HICON)LoadImage(hInst,MAKEINTRESOURCE(IDI_ICON1),IMAGE_ICON,16,16,LR_DEFAULTCOLOR);
	wcx.hCursor=LoadCursor(NULL,IDC_ARROW);
	wcx.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wcx.lpszMenuName=NULL;
	wcx.lpszClassName=className;

	/*ウィンドウクラスの登録*/
	if(!RegisterClassEx(&wcx)){ MessageBox(NULL,"ウィンドウクラスの登録に失敗しました！",0,0); return 1;} 

	/*ウィンドウの生成*/
	hwnd=CreateWindowEx(
		WS_EX_TOPMOST,
		className,
		"神威",
		WS_CAPTION|WS_POPUPWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,			
		320,
		240,
		NULL,
		NULL,
		hInst,
		NULL
		);
			
	if(!hwnd)return FALSE;

	/*ウィンドウの表示*/
	ShowWindow(hwnd,nCmdshow);
	UpdateWindow(hwnd);
	SetFocus(hwnd);
	ShowCursor(FALSE);//カーソルを見えなくする
	SetCursorPos(0,0);

	//システムタスクに設定（すべての始まり）
	task.Sys_Task_Initiator (title_init,RETURN);

	/*メッセージループ*/	
	while(1){
		if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			if(!GetMessage(&msg,NULL,0,0))
				return msg.wParam;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else{
			//動作制限
			static DWORD NowTime,PrevTime;
			NowTime = timeGetTime();
			if( NowTime - PrevTime< WAIT )continue;
			PrevTime = NowTime;
			
			//非アクティブ時実行しない
			if(ac_flag==1)continue;
			//バックバッファを黒に
			draw.Cls (0,0,0,320,240,RGB(0,0,0));
			//ゲームのメイン（タスクを動かす）
			task.Dispatcher ();
			//フリップ
			draw.Flip ();
		}
	}
	return msg.wParam;
}
