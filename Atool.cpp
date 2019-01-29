///////////////////////////////////////////////////////////////////////////
//		オーディオツールクラス　ＣＰＰ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#include "main.h"

//クラスのコンストラクタ
Atool::Atool(){ 
	Id=0;
	IsOpen=FALSE;
	PlayTrack=0;
	Play_flag=0;
	loop=0;
	return; 
}

//クラスのデストラクタ
Atool::~Atool(){ 
	Stop();
	Close();
	return; 
}

//ＣＤのオープン
Atool::Open(HWND hwnd){
	Hwnd=hwnd;
	// デバイスのオープン
	MCI_OPEN_PARMS	open;
	open.lpstrDeviceType = "cdaudio";
	if ((mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE|MCI_WAIT, (DWORD)&open)) != 0) {
		//開けないとき処理を返す
		return FALSE;
	}
	//ＩＤを取得
	Id = open.wDeviceID;

	// タイムフォーマットをTMSFにする
	MCI_SET_PARMS	set;
	set.dwTimeFormat = (DWORD)MCI_FORMAT_TMSF;
	if (mciSendCommand(Id, MCI_SET, MCI_SET_TIME_FORMAT|MCI_WAIT, (DWORD)&set)) {
		mciSendCommand(Id, MCI_CLOSE, MCI_WAIT, 0);
		Id = 0;
		return FALSE;
	}
	IsOpen = TRUE;
	return TRUE;
}

// ＣＤのクローズ
BOOL Atool::Close(){
	//ＩＤがある場合（オープンされている場合）
	if (Id != 0) {
		Stop();
		mciSendCommand(Id, MCI_CLOSE, MCI_WAIT, 0);
		Id = 0;
	}
	IsOpen = FALSE;
	return TRUE;
}

// 指定トラックの演奏
BOOL Atool::Play(int no,char flag){
	//オープンされていないとき返す
	if (!IsOpen)return FALSE;
	//演奏されていたらストップ
	Stop();
	if(Play_flag==1)return FALSE;
	PlayTrack = no;

	if(flag>0)flag=1;
	loop=flag;

	// トラックの演奏時間を得る
	MCI_STATUS_PARMS	status;
	status.dwItem = MCI_STATUS_LENGTH;
	status.dwTrack = no;
	if ((mciSendCommand(Id, MCI_STATUS, MCI_STATUS_ITEM|MCI_TRACK|MCI_WAIT, (DWORD)&status)) != 0) {
		return FALSE;
	}
	// 演奏時間はstatus.dwReturnにMSFフォーマットで格納されている

	// 演奏位置を指定して演奏する
	MCI_PLAY_PARMS	play;
	play.dwCallback =(DWORD)Hwnd;
	// 開始時間:指定トラック:0分:0秒:0フレーム
	play.dwFrom = MCI_MAKE_TMSF(no, 0, 0, 0);
	// 終了時間:指定トラックの最終位置
	play.dwTo = MCI_MAKE_TMSF(no,			// トラック
		MCI_MSF_MINUTE(status.dwReturn),	// 分
		MCI_MSF_SECOND(status.dwReturn),	// 秒
		MCI_MSF_FRAME(status.dwReturn));	// フレーム

    if (mciSendCommand(Id, MCI_PLAY, MCI_NOTIFY|MCI_FROM|MCI_TO, (DWORD)&play)!=0) {
		return FALSE;
	}
	Play_flag=1;
	return TRUE;
}

// 指定トラックの演奏
BOOL Atool::RePlay(){
	//オープンされていないとき返す
	if (!IsOpen)return FALSE;

	//ループを指定されていないとき返す
	if(loop==0)return FALSE;

	// トラックの演奏時間を得る
	MCI_STATUS_PARMS	status;
	status.dwItem = MCI_STATUS_LENGTH;
	status.dwTrack = PlayTrack;
	if ((mciSendCommand(Id, MCI_STATUS, MCI_STATUS_ITEM|MCI_TRACK|MCI_WAIT, (DWORD)&status)) != 0) {
		return FALSE;
	}
	// 演奏時間はstatus.dwReturnにMSFフォーマットで格納されている

	// 演奏位置を指定して演奏する
	MCI_PLAY_PARMS	play;
	play.dwCallback =(DWORD)Hwnd;
	// 開始時間:指定トラック:0分:0秒:0フレーム
	play.dwFrom = MCI_MAKE_TMSF(PlayTrack, 0, 0, 0);
	// 終了時間:指定トラックの最終位置
	play.dwTo = MCI_MAKE_TMSF(PlayTrack,
		MCI_MSF_MINUTE(status.dwReturn),	// 分
		MCI_MSF_SECOND(status.dwReturn),	// 秒
		MCI_MSF_FRAME(status.dwReturn));	// フレーム
		
    if (mciSendCommand(Id, MCI_PLAY, MCI_NOTIFY|MCI_FROM|MCI_TO, (DWORD)&play)!=0) {
		return FALSE;
	}
	return TRUE;
}

// 演奏停止
BOOL Atool::Stop(){
	//オープンされていないとき返す
	if (!IsOpen)return FALSE;

	if (PlayTrack > 0) {
		mciSendCommand(Id, MCI_STOP, MCI_WAIT, 0);
		PlayTrack = 0;
		Play_flag=0;
	}
	return TRUE;
}

// 演奏終了時に、ウインドウから呼び戻してもらうルーチン
BOOL Atool::MciNotify(DWORD id){
	if (Id != id)
		return FALSE;
	return TRUE;
}
