///////////////////////////////////////////////////////////////////////////
//		�h���[�c�[���N���X�@�g
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#ifndef _DTOOL_
#define _DTOOL_

//�f�t�@�C���錾
//�X�N���[���̍ő�l
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

//�T�[�t�F�C�X�̍ő吔
#define DRAW_MAX 21

//�T�[�t�F�C�X�\����
typedef struct {
	LPDIRECTDRAWSURFACE Surface;       // �r�b�g�}�b�v�ێ��p�T�[�t�F�X
	// �T�[�t�F�X���X�g�΍�f�[�^��
	char                 SaveData[30]; //�t�@�C���l�[��
	DWORD	             dwWidth;      // �T�[�t�F�X�T�C�Y
	DWORD	             dwHeight;
	DWORD	             dwPitch;
	char                 kind;
	int                  flag;
	COLORREF             ColorKey;     // �J���[�L�[
} SurfaceData;

class Dtool{
private:
	//�_�C���N�g�h���[
	LPDIRECTDRAW lpDDraw;
	//�v���C�}���[�T�[�t�F�C�X
	LPDIRECTDRAWSURFACE lpPrimary;
	
	//�O�Ԃ��o�b�N�o�b�t�@�ƂȂ�i���܂Ƀo�b�N�o�b�t�@�����삷�邽�߁j
	//�Q�O�Ԃ��������A��]�̊g�k�p�e���v�T�[�t�F�C�X
	SurfaceData lpSurface[DRAW_MAX];

	//�������p�e�[�u���i��p�̃p���b�g���K�v�j
	char tomei_tbl[16][16];
	//�T�C���A�R�T�C���A�e�[�u��
	double sin_tbl[360],cos_tbl[360];
	//�p���b�g����p
	PALETTEENTRY pe[256];
	//�p���b�g���삵���Ƃ��̕ۑ��p
	PALETTEENTRY pe_temp[256];

	//�N���X���Ŏg���E�B���h�E�n���h���i�ۑ��p�j
	HWND Hwnd; 
	//�������o���Ȃ������Ƃ�
	HRESULT result;
public:
	//�R���X�g���N�^
	Dtool();
	//�f�X�g���N�^
	~Dtool();
	//�_�C���N�g�h���E�C�j�V�����C�Y
	Init(HWND hwnd);
	
	//72�����ړ��֐�
	void move72(int *x,int *y,char dir,int kyori);

	//�r�b�g�}�b�v�̑傫���ɍ��킹�A�T�[�t�F�C�X�쐬
	//���łɃJ���[�L�[�Z�b�g
	void MakeSurface(char draw_cnt,char *fname,int flag,int color);
	//�T�[�t�F�C�X��邾���iMakeSurface�̃I�[�o�[���[�h�j
	void MakeSurface(char draw_cnt,int w,int h,int flag,int color);
	//�o�b�N�o�b�t�@�̓h��Ԃ�
	Cls(int cnt,int x,int y,int w,int h,int color);
	//���C���̕`��
	DrawLine(int cnt,int x1,int y1,int x2,int y2, int size, int rgb);
	

	//��]�]��(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A��]�p�x�A���S���A���S���A�J���[�L�[�m�n)
	TurnBltFast(int tar,int x,int y,int sou,RECT rc,int Angle,int cx,int cy,int tou);
	//��]���S�]��(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A��]�p�x�A���S���A���S��)
	TurnBltFastCenter(int tar,int x,int y,int sou,RECT rc,int Angle,int cx,int cy);
	//�������]���֐�(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A�����x�A�]���̎��)
	AlphaBltFast(int tar,int x,int y,int sou,RECT rc,char tomeido,char flag);
	//���������S�]���֐�(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A�����x�A�]���̎��)
	AlphaBltFastCenter(int tar,int x,int y,int sou,RECT rc,char tomeido,char flag);
	//
	AlphaBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z,float sx/*���g�嗦*/,float sy/*���g�嗦*/,int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,char tomeido/*�����x*/,char flag/*�t���O*/);
	
	//�������]���֐�(�]����m�n�A�����W�A�����W�A�����W�A�]�����m�n�A���N�g�A�����x�A�]���̎��)
	TDAlphaBlt(int tar,int x,int y,int z,int sou,RECT rc,char tomeido,char flag);
	//�g�k��]�]��
	//��]���S�]��(�]����m�n�A�����W�A�����W�A�����W�A�]�����m�n�A���N�g�A��]�p�x�A���S���A���S��)
	TDTurnBlt(int tar,int x,int y,int z,int sou,RECT rc,int Angle,int cx,int cy);

	//�ʏ�u���b�g�t�@�[�X�g(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A�t���O)
	BltFast(int tar,int x,int y,int sou,RECT rc,int flag);
	//�N���b�v���ău���b�g�t�@�[�X�g(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A�t���O)
	ClipBltFast(int tar,int x,int y,int sou,RECT rc,int flag);
	//�N���b�v���ău���b�g�t�@�[�X�g(�]����m�n�A�����W�A�����W�A�]�����m�n�A���N�g�A�t���O)
	ClipBltFast2(int tar,int x,int y,int sou,RECT rc,int flag);
	//�N���b�v���ău���b�g(�]����m�n�A�����W�A�����W�A�����g�嗦�A�c���g�嗦�A�]�����m�n�A���N�g�A�t���O)
	RECT ClipBlt(int tar,int x, int y,float sx, float sy,int sou,RECT rc,int flag);
	//���S�N���b�v�u���b�g(�]����m�n�A�����W�A�����W�A�����g�嗦�A�c���g�嗦�A�]�����m�n�A���N�g�A�t���O)
	ClipBltCenter(int tar,int x, int y,float sx, float sy,int sou,RECT rc,int flag);
	//�X�N���[���u���b�g(�]����m�n�A�����W�i�A�h���X�j�A�����W�i�A�h���X�j�A���X�s�[�h�A���X�s�[�h�A�]�����m�n�A���N�g�A�t���O)
	ScroolBlt(int tar,float *RollX,float *RollY,float xSpeed,float ySpeed,int sou,RECT rc ,int flag);
	//�[���R�c�u���b�g(�]����m�n�A�����W�A�����W�A�����W�A���Ɍ������āA���Ɍ������āA�]�����m�n�A���N�g�A�t���O)
	TDClipBlt(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	//�[���R�c�u���b�g�Z���^�[(�]����m�n�A�����W�A�����W�A�����W�A���Ɍ������āA���Ɍ������āA�]�����m�n�A���N�g�A�t���O)
	TDClipBltCenter(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	//�摜�̑傫���͂��̂܂܂ŁA���A�����ɓ]��
	TDBlt(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	
	//�S�ă����[�X
	Release();
	//�v���C�}���[�ƃo�b�N�o�b�t�@�̃��X�g�A
	BackRestore();
	//�b�m�s�̃T�[�t�F�C�X�̃��X�g�A
	Restore(int cnt);
	//������̕`��i�T�[�t�@�����i���o�[�A������A�����T�C�Y�A�`��ʒu���A�`��ʒu���A�����F�j
	FontShow(int cnt,char *str, int size, int x, int y, int rgb);
	//cnt�ԍ��̃T�[�t�F�C�X�̃f�o�C�X�R���e�L�X�g�擾
	GetDC(int cnt,HDC *hdc);
	//cnt�ԍ��̃T�[�t�F�C�X�̃f�o�C�X�R���e�L�X�g���
	ReleaseDC(int cnt,HDC hdc);
	//�����猳�ɂ��ǂ��i�����j
	char BlackIn(char nrgb);
	//���Ƀt�F�[�h�C���i�����j
	char BlackOut(char nrgb);
	//�����猳�ɂ��ǂ��i�����j
	char WhiteIn(char nrgb);
	//���Ƀt�F�[�h�C���i�����j
	char WhiteOut(char nrgb);
	//�t���b�v����
	void Flip();
};

#endif _DTOOL_
