///////////////////////////////////////////////////////////////////////////
//		�T�E���h�c�[���N���X�@�g
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#ifndef _STOOL_
#define _STOOL_

#include <mmsystem.h>
#include <mmreg.h>

//�f�t�@�C���錾

//�T�E���h�̍ő吔
#define WAVE_MAX 21
//�T�E���h�̃R�s�[�̍ő吔
#define WAVE_COPY_MAX 10

class Stool{
private:
	//�_�C���N�g�T�E���h
	LPDIRECTSOUND lpDSound;
	LPDIRECTSOUNDBUFFER lpSPrimary;
	LPDIRECTSOUNDBUFFER lpSound[WAVE_MAX][WAVE_COPY_MAX];

	//�N���X���Ŏg���E�B���h�E�n���h���i�ۑ��p�j
	HWND Hwnd; 
	//�������o���Ȃ������Ƃ�
	HRESULT result;
public:
	//�R���X�g���N�^
	Stool();
	//�f�X�g���N�^
	~Stool();
	//�_�C���N�g�T�E���h�C�j�V�����C�Y�i�E�B���h�E�n���h���j
	Init(HWND hwnd);
	//�E�F�u���[�h�i���[�h����i���o�[�A���[�h����t�@�C�����A�R�s�[�����邩�j
	void Loadwave(int sound_cnt,char *fname,int count);
	//�p�����g�p���Ẵv���C�i�T�E���h�i���o�[�A�p���̈ʒu�i�O�`�Q�W�O�j�j
	Play(int cnt,int x);
	//�����[�X
	Release();
};

///////////////////////////////////////////////////////////////////////////
//		�v�`�u�d�����Ǎ��@��
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
