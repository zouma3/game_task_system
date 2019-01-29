///////////////////////////////////////////////////////////////////////////
//		オーディオツールクラス　Ｈ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#ifndef _ATOOL_
#define _ATOOL_

//ループする時使用
#define MM_CD_LOOPING 1

class Atool{
private:
	//ウィンドウハンドル（保存用）
	HWND Hwnd;
	//ＩＤ
	DWORD	Id;
	//オープンしているか判断
	BOOL	IsOpen;
	//演奏しているトラック
	int	PlayTrack;
	//演奏しているか判断
	char Play_flag;
	//ループフラグ
	char loop;
public:
	//コンストラクタ
	Atool(void);
	//デストラクタ
	~Atool(void);

	//ＣＤのオープン(ウィンドウハンドルを)
	BOOL	Open(HWND hwnd);
	//ＣＤのクローズ
	BOOL	Close();
	//ＣＤの演奏（トラックナンバー、ループフラグ（ループする時 MM_CD_LOOPING））
	BOOL	Play(int no,char loop);
	//ＣＤのリプレイ
	BOOL	RePlay();
	//ＣＤの演奏をとめる
	BOOL	Stop();
	// 演奏終了時に、ウインドウから呼び戻してもらうルーチン
	BOOL	MciNotify(DWORD id);
	// メディアが挿入されているかチェックする
	int		MediaPresent();
	// トラック数を求める
	int		NumberOfTracks();
};

/*　チームの皆さんへ
//WindowFuncにこれを追加↓

  　case WM_CREATE:
		audio.Open(hwnd);
        break;

	case MM_MCINOTIFY:
		//MCIから終了通知がきた時
		if(wParam == MCI_NOTIFY_SUCCESSFUL)audio.RePlay();
		break;

//	終了処理はデストラクタか勝手にやってくれます。

*/
#endif _ATOOL_
