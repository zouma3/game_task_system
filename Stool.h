///////////////////////////////////////////////////////////////////////////
//		サウンドツールクラス　Ｈ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#ifndef _STOOL_
#define _STOOL_

#include <mmsystem.h>
#include <mmreg.h>

//デファイン宣言

//サウンドの最大数
#define WAVE_MAX 21
//サウンドのコピーの最大数
#define WAVE_COPY_MAX 10

class Stool{
private:
	//ダイレクトサウンド
	LPDIRECTSOUND lpDSound;
	LPDIRECTSOUNDBUFFER lpSPrimary;
	LPDIRECTSOUNDBUFFER lpSound[WAVE_MAX][WAVE_COPY_MAX];

	//クラス内で使うウィンドウハンドル（保存用）
	HWND Hwnd; 
	//初期化出来なかったとき
	HRESULT result;
public:
	//コンストラクタ
	Stool();
	//デストラクタ
	~Stool();
	//ダイレクトサウンドイニシャライズ（ウィンドウハンドル）
	Init(HWND hwnd);
	//ウェブロード（ロードするナンバー、ロードするファイル名、コピーを幾つ作るか）
	void Loadwave(int sound_cnt,char *fname,int count);
	//パンを使用してのプレイ（サウンドナンバー、パンの位置（０～２８０））
	Play(int cnt,int x);
	//リリース
	Release();
};

///////////////////////////////////////////////////////////////////////////
//		ＷＡＶＥ総合読込　↓
///////////////////////////////////////////////////////////////////////////
#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
class CWaveSoundRead{
public:
    WAVEFORMATEX* m_pwfx;       
    HMMIO         m_hmmioIn;    
    MMCKINFO      m_ckIn;        
    MMCKINFO      m_ckInRiff;   

    CWaveSoundRead();
    ~CWaveSoundRead();
    HRESULT Open( CHAR* strFilename );
    HRESULT Reset();
    HRESULT Read( UINT nSizeToRead, BYTE* pbData, UINT* pnSizeRead );
    HRESULT Close();
};

#endif _STOOL_
