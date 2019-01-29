///////////////////////////////////////////////////////////////////////////
//		サウンドツールクラス　ＣＰＰ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

//コンストラクタ
Stool::Stool(){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				lpSound[i][j]=NULL;
			}	
		}
	}
}
//デストラクタ
Stool::~Stool (){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				//曲データが入っていればリリース、ＮＵＬＬ
				lpSound[i][j]->Release();
				lpSound[i][j]=NULL;
			}	
		}
	}
	//サウンドの解放
	lpSPrimary->SetVolume(0);
	lpSPrimary->SetPan(0);
	lpSPrimary->Release();
	lpDSound->Release();
}
//ダイレクトサウンドのイニシャライズ
Stool::Init(HWND hwnd/*ウィンドウハンドル*/){
	Hwnd = hwnd;
	//---------------------DirectSound関連-----------------------
	result=DirectSoundCreate(NULL, &lpDSound, NULL);
	if(result!=DS_OK)Error(Hwnd,"サウンドの初期化ができません");

	//協調レベルを設定
	result=lpDSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY);
	if(result!=DS_OK)Error(Hwnd,"サウンドの協調レベル設定ができません");
	
	// プライマリ・バッファの作成
	// DSBUFFERDESC構造体を設定
	DSBUFFERDESC dsbdesc; 
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC); 
	// プライマリ・バッファを指定
	dsbdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_PRIMARYBUFFER; 
	dsbdesc.dwBufferBytes = 0;
	dsbdesc.lpwfxFormat = NULL;
	// バッファを作る
	result=lpDSound->CreateSoundBuffer(&dsbdesc, &lpSPrimary, NULL);
	if(result!=DS_OK)Error(Hwnd,"サウンドのプライマリーが生成出来ません");
	
	// プライマリ・バッファのWaveフォーマットを設定
	// 　　　優先協調レベル以上の協調レベルが設定されている必要があります．
	WAVEFORMATEX pcmwf; 
	ZeroMemory(&pcmwf, sizeof(WAVEFORMATEX)); 
	pcmwf.wFormatTag = WAVE_FORMAT_PCM; 
	pcmwf.nChannels = 2;		// ２チャンネル（ステレオ）
	pcmwf.nSamplesPerSec = 44100;	// サンプリング・レート　44.1kHz
	pcmwf.nBlockAlign = 4;
	pcmwf.nAvgBytesPerSec = pcmwf.nSamplesPerSec * pcmwf.nBlockAlign; 
	pcmwf.wBitsPerSample = 16;		// 16ビット
	lpSPrimary->SetFormat(&pcmwf);

	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			lpSound[i][j]=NULL;
		}	
	}
}
//サウンドのロード
void Stool::Loadwave(int sound_cnt/*何個目*/,char *fname/*名前*/,int count/*幾つ作る？*/){

	if((count<0)|(count>20))return;
	
	// WAVEファイルを開く
	CWaveSoundRead WaveFile;
	WaveFile.Open(fname);

	// セカンダリ・バッファを作成する
	// DSBUFFERDESC構造体を設定
	DSBUFFERDESC dsbdesc; 
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC); 
	dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
	dsbdesc.dwBufferBytes = WaveFile.m_ckIn.cksize;
	dsbdesc.lpwfxFormat = WaveFile.m_pwfx;

	// バッファを作る
	result=lpDSound->CreateSoundBuffer(&dsbdesc, &lpSound[sound_cnt][0], NULL); 
	if(result!=DS_OK)Error(Hwnd,"サウンドのセカンダリバッファが生成出来ません");
	
	// セカンダリ・バッファにWaveデータを書き込む
	LPVOID lpvPtr1;		// 最初のブロックのポインタ
	DWORD dwBytes1;		// 最初のブロックのサイズ
	LPVOID lpvPtr2;		// ２番目のブロックのポインタ
	DWORD dwBytes2;		// ２番目のブロックのサイズ

	result = lpSound[sound_cnt][0]->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0); 
	if(result!=DS_OK)Error(Hwnd,"サウンドのセカンダリバッファが生成出来ません");

	// DSERR_BUFFERLOSTが返された場合，Restoreメソッドを使ってバッファを復元する
	if(result==DSERR_BUFFERLOST)
	{
		lpSound[sound_cnt][0]->Restore();
		result = lpSound[sound_cnt][0]->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);
		if(result!=DS_OK)Error(Hwnd,"サウンドのセカンダリバッファが生成出来ません");
	} 
	if (SUCCEEDED(result))
	{
		// ロック成功
		// ここで，バッファに書き込む
		// バッファにデータをコピーする
		UINT rsize;
		WaveFile.Read(dwBytes1, (LPBYTE)lpvPtr1, &rsize);
		if ( 0 != dwBytes2 )
			WaveFile.Read(dwBytes2, (LPBYTE)lpvPtr2, &rsize);

	   // 書き込みが終わったらすぐにUnlockする．
		result =lpSound[sound_cnt][0]->Unlock(lpvPtr1, dwBytes1, lpvPtr2, dwBytes2); 
		if(result!=DS_OK)Error(Hwnd,"サウンドのセカンダリバッファが生成出来ません");
	}

	//最大鳴らせるサウンド数(何個作る？)
	if(count>WAVE_COPY_MAX)count=WAVE_COPY_MAX;
	for(int i=0;i<count;i++){
		lpDSound->DuplicateSoundBuffer(lpSound[sound_cnt][0],&lpSound[sound_cnt][i]);
	}
}
//サウンド再生
Stool::Play (int cnt/*何個目のサウンド？*/,int x/*左右のパンの調整*/){
	unsigned long flg;
	//発生場所に応じてパンを変更
	long pan=(x-140)*5;

	for(int i=0;i<WAVE_COPY_MAX;i++){
		//データが無ければブレイク
		if(lpSound[cnt][i]==NULL)break;
		//今の状態を取る
		lpSound[cnt][i]->GetStatus(&flg);
		//使用して無ければ鳴らす
		if((flg&DSBSTATUS_PLAYING)==0){
			lpSound[cnt][i]->SetPan (0+pan);
			lpSound[cnt][i]->Play(0,0,0);
			break;	
		}		
	}
}
//リリース
Stool::Release(){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				//曲データが入っていればリリース、ＮＵＬＬ
				lpSound[i][j]->Release();
				lpSound[i][j]=NULL;
			}	
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//		ＷＡＶＥ総合読込　↓
///////////////////////////////////////////////////////////////////////////
HRESULT ReadMMIO( HMMIO hmmioIn, MMCKINFO* pckInRIFF, WAVEFORMATEX** ppwfxInfo )
{
    MMCKINFO        ckIn;           
    PCMWAVEFORMAT   pcmWaveFormat;      

    *ppwfxInfo = NULL;

    if( ( 0 != mmioDescend( hmmioIn, pckInRIFF, NULL, 0 ) ) )
        return E_FAIL;

    if( (pckInRIFF->ckid != FOURCC_RIFF) ||
        (pckInRIFF->fccType != mmioFOURCC('W', 'A', 'V', 'E') ) )
        return E_FAIL;

    ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
    if( 0 != mmioDescend(hmmioIn, &ckIn, pckInRIFF, MMIO_FINDCHUNK) )
        return E_FAIL;
       if( ckIn.cksize < (LONG) sizeof(PCMWAVEFORMAT) )
           return E_FAIL;
    if( mmioRead( hmmioIn, (HPSTR) &pcmWaveFormat, 
                  sizeof(pcmWaveFormat)) != sizeof(pcmWaveFormat) )
        return E_FAIL;

    if( pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM )
    {
        if( NULL == ( *ppwfxInfo = new WAVEFORMATEX ) )
            return E_FAIL;

        memcpy( *ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat) );
        (*ppwfxInfo)->cbSize = 0;
    }
    else
    {
        WORD cbExtraBytes = 0L;
        if( mmioRead( hmmioIn, (CHAR*)&cbExtraBytes, sizeof(WORD)) != sizeof(WORD) )
            return E_FAIL;

        *ppwfxInfo = (WAVEFORMATEX*)new CHAR[ sizeof(WAVEFORMATEX) + cbExtraBytes ];
        if( NULL == *ppwfxInfo )
            return E_FAIL;
        memcpy( *ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat) );
        (*ppwfxInfo)->cbSize = cbExtraBytes;
        if( mmioRead( hmmioIn, (CHAR*)(((BYTE*)&((*ppwfxInfo)->cbSize))+sizeof(WORD)),
                      cbExtraBytes ) != cbExtraBytes )
        {
            delete *ppwfxInfo;
            *ppwfxInfo = NULL;
            return E_FAIL;
        }
    }
    if( 0 != mmioAscend( hmmioIn, &ckIn, 0 ) )
    {
        delete *ppwfxInfo;
        *ppwfxInfo = NULL;
        return E_FAIL;
    }

    return S_OK;
}
HRESULT WaveOpenFile( CHAR* strFileName, HMMIO* phmmioIn, WAVEFORMATEX** ppwfxInfo,
                  MMCKINFO* pckInRIFF )
{
    HRESULT hr;
    HMMIO   hmmioIn = NULL;
    
    if( NULL == ( hmmioIn = mmioOpen( strFileName, NULL, MMIO_ALLOCBUF|MMIO_READ ) ) )
        return E_FAIL;

    if( FAILED( hr = ReadMMIO( hmmioIn, pckInRIFF, ppwfxInfo ) ) )
    {
        mmioClose( hmmioIn, 0 );
        return hr;
    }

    *phmmioIn = hmmioIn;

    return S_OK;
}
HRESULT WaveStartDataRead( HMMIO* phmmioIn, MMCKINFO* pckIn,
                           MMCKINFO* pckInRIFF )
{
 
    if( -1 == mmioSeek( *phmmioIn, pckInRIFF->dwDataOffset + sizeof(FOURCC),
                        SEEK_SET ) )
        return E_FAIL;

    pckIn->ckid = mmioFOURCC('d', 'a', 't', 'a');
    if( 0 != mmioDescend( *phmmioIn, pckIn, pckInRIFF, MMIO_FINDCHUNK ) )
        return E_FAIL;

    return S_OK;
}
HRESULT WaveReadFile( HMMIO hmmioIn, UINT cbRead, BYTE* pbDest,
                      MMCKINFO* pckIn, UINT* cbActualRead )
{
    MMIOINFO mmioinfoIn; 

    *cbActualRead = 0;

    if( 0 != mmioGetInfo( hmmioIn, &mmioinfoIn, 0 ) )
        return E_FAIL;
                
    UINT cbDataIn = cbRead;
    if( cbDataIn > pckIn->cksize ) 
        cbDataIn = pckIn->cksize;       

    pckIn->cksize -= cbDataIn;
    
    for( DWORD cT = 0; cT < cbDataIn; cT++ )
    {
   
        if( mmioinfoIn.pchNext == mmioinfoIn.pchEndRead )
        {
            if( 0 != mmioAdvance( hmmioIn, &mmioinfoIn, MMIO_READ ) )
                return E_FAIL;

            if( mmioinfoIn.pchNext == mmioinfoIn.pchEndRead )
                return E_FAIL;
        }
		*((BYTE*)pbDest+cT) = *((BYTE*)mmioinfoIn.pchNext);
        mmioinfoIn.pchNext++;
    }
    if( 0 != mmioSetInfo( hmmioIn, &mmioinfoIn, 0 ) )
        return E_FAIL;

    *cbActualRead = cbDataIn;
    return S_OK;
}
CWaveSoundRead::CWaveSoundRead()
{
    m_pwfx   = NULL;
}
CWaveSoundRead::~CWaveSoundRead()
{
    Close();
    SAFE_DELETE( m_pwfx );
}
HRESULT CWaveSoundRead::Open( CHAR* strFilename )
{
    SAFE_DELETE( m_pwfx );
    HRESULT  hr;    
    if( FAILED( hr = WaveOpenFile( strFilename, &m_hmmioIn, &m_pwfx, &m_ckInRiff ) ) )
        return hr;
    if( FAILED( hr = Reset() ) )
        return hr;
    return hr;
}
HRESULT CWaveSoundRead::Reset()
{
    return WaveStartDataRead( &m_hmmioIn, &m_ckIn, &m_ckInRiff );
}
HRESULT CWaveSoundRead::Read( UINT nSizeToRead, BYTE* pbData, UINT* pnSizeRead )
{
    return WaveReadFile( m_hmmioIn, nSizeToRead, pbData, &m_ckIn, pnSizeRead );
}
HRESULT CWaveSoundRead::Close()
{
    mmioClose( m_hmmioIn, 0 );
    return S_OK;
}
