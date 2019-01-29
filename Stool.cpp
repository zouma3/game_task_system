///////////////////////////////////////////////////////////////////////////
//		�T�E���h�c�[���N���X�@�b�o�o
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

//�R���X�g���N�^
Stool::Stool(){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				lpSound[i][j]=NULL;
			}	
		}
	}
}
//�f�X�g���N�^
Stool::~Stool (){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				//�ȃf�[�^�������Ă���΃����[�X�A�m�t�k�k
				lpSound[i][j]->Release();
				lpSound[i][j]=NULL;
			}	
		}
	}
	//�T�E���h�̉��
	lpSPrimary->SetVolume(0);
	lpSPrimary->SetPan(0);
	lpSPrimary->Release();
	lpDSound->Release();
}
//�_�C���N�g�T�E���h�̃C�j�V�����C�Y
Stool::Init(HWND hwnd/*�E�B���h�E�n���h��*/){
	Hwnd = hwnd;
	//---------------------DirectSound�֘A-----------------------
	result=DirectSoundCreate(NULL, &lpDSound, NULL);
	if(result!=DS_OK)Error(Hwnd,"�T�E���h�̏��������ł��܂���");

	//�������x����ݒ�
	result=lpDSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY);
	if(result!=DS_OK)Error(Hwnd,"�T�E���h�̋������x���ݒ肪�ł��܂���");
	
	// �v���C�}���E�o�b�t�@�̍쐬
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc; 
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC); 
	// �v���C�}���E�o�b�t�@���w��
	dsbdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_PRIMARYBUFFER; 
	dsbdesc.dwBufferBytes = 0;
	dsbdesc.lpwfxFormat = NULL;
	// �o�b�t�@�����
	result=lpDSound->CreateSoundBuffer(&dsbdesc, &lpSPrimary, NULL);
	if(result!=DS_OK)Error(Hwnd,"�T�E���h�̃v���C�}���[�������o���܂���");
	
	// �v���C�}���E�o�b�t�@��Wave�t�H�[�}�b�g��ݒ�
	// �@�@�@�D�拦�����x���ȏ�̋������x�����ݒ肳��Ă���K�v������܂��D
	WAVEFORMATEX pcmwf; 
	ZeroMemory(&pcmwf, sizeof(WAVEFORMATEX)); 
	pcmwf.wFormatTag = WAVE_FORMAT_PCM; 
	pcmwf.nChannels = 2;		// �Q�`�����l���i�X�e���I�j
	pcmwf.nSamplesPerSec = 44100;	// �T���v�����O�E���[�g�@44.1kHz
	pcmwf.nBlockAlign = 4;
	pcmwf.nAvgBytesPerSec = pcmwf.nSamplesPerSec * pcmwf.nBlockAlign; 
	pcmwf.wBitsPerSample = 16;		// 16�r�b�g
	lpSPrimary->SetFormat(&pcmwf);

	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			lpSound[i][j]=NULL;
		}	
	}
}
//�T�E���h�̃��[�h
void Stool::Loadwave(int sound_cnt/*����*/,char *fname/*���O*/,int count/*����H*/){

	if((count<0)|(count>20))return;
	
	// WAVE�t�@�C�����J��
	CWaveSoundRead WaveFile;
	WaveFile.Open(fname);

	// �Z�J���_���E�o�b�t�@���쐬����
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc; 
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC); 
	dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
	dsbdesc.dwBufferBytes = WaveFile.m_ckIn.cksize;
	dsbdesc.lpwfxFormat = WaveFile.m_pwfx;

	// �o�b�t�@�����
	result=lpDSound->CreateSoundBuffer(&dsbdesc, &lpSound[sound_cnt][0], NULL); 
	if(result!=DS_OK)Error(Hwnd,"�T�E���h�̃Z�J���_���o�b�t�@�������o���܂���");
	
	// �Z�J���_���E�o�b�t�@��Wave�f�[�^����������
	LPVOID lpvPtr1;		// �ŏ��̃u���b�N�̃|�C���^
	DWORD dwBytes1;		// �ŏ��̃u���b�N�̃T�C�Y
	LPVOID lpvPtr2;		// �Q�Ԗڂ̃u���b�N�̃|�C���^
	DWORD dwBytes2;		// �Q�Ԗڂ̃u���b�N�̃T�C�Y

	result = lpSound[sound_cnt][0]->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0); 
	if(result!=DS_OK)Error(Hwnd,"�T�E���h�̃Z�J���_���o�b�t�@�������o���܂���");

	// DSERR_BUFFERLOST���Ԃ��ꂽ�ꍇ�CRestore���\�b�h���g���ăo�b�t�@�𕜌�����
	if(result==DSERR_BUFFERLOST)
	{
		lpSound[sound_cnt][0]->Restore();
		result = lpSound[sound_cnt][0]->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);
		if(result!=DS_OK)Error(Hwnd,"�T�E���h�̃Z�J���_���o�b�t�@�������o���܂���");
	} 
	if (SUCCEEDED(result))
	{
		// ���b�N����
		// �����ŁC�o�b�t�@�ɏ�������
		// �o�b�t�@�Ƀf�[�^���R�s�[����
		UINT rsize;
		WaveFile.Read(dwBytes1, (LPBYTE)lpvPtr1, &rsize);
		if ( 0 != dwBytes2 )
			WaveFile.Read(dwBytes2, (LPBYTE)lpvPtr2, &rsize);

	   // �������݂��I������炷����Unlock����D
		result =lpSound[sound_cnt][0]->Unlock(lpvPtr1, dwBytes1, lpvPtr2, dwBytes2); 
		if(result!=DS_OK)Error(Hwnd,"�T�E���h�̃Z�J���_���o�b�t�@�������o���܂���");
	}

	//�ő�点��T�E���h��(�����H)
	if(count>WAVE_COPY_MAX)count=WAVE_COPY_MAX;
	for(int i=0;i<count;i++){
		lpDSound->DuplicateSoundBuffer(lpSound[sound_cnt][0],&lpSound[sound_cnt][i]);
	}
}
//�T�E���h�Đ�
Stool::Play (int cnt/*���ڂ̃T�E���h�H*/,int x/*���E�̃p���̒���*/){
	unsigned long flg;
	//�����ꏊ�ɉ����ăp����ύX
	long pan=(x-140)*5;

	for(int i=0;i<WAVE_COPY_MAX;i++){
		//�f�[�^��������΃u���C�N
		if(lpSound[cnt][i]==NULL)break;
		//���̏�Ԃ����
		lpSound[cnt][i]->GetStatus(&flg);
		//�g�p���Ė�����Ζ炷
		if((flg&DSBSTATUS_PLAYING)==0){
			lpSound[cnt][i]->SetPan (0+pan);
			lpSound[cnt][i]->Play(0,0,0);
			break;	
		}		
	}
}
//�����[�X
Stool::Release(){
	for(int i=0;i<WAVE_MAX;i++){
		for(int j=0;j<WAVE_COPY_MAX;j++){
			if(lpSound[i][j]!=NULL){
				//�ȃf�[�^�������Ă���΃����[�X�A�m�t�k�k
				lpSound[i][j]->Release();
				lpSound[i][j]=NULL;
			}	
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//		�v�`�u�d�����Ǎ��@��
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
