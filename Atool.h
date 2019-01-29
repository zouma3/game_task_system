///////////////////////////////////////////////////////////////////////////
//		�I�[�f�B�I�c�[���N���X�@�g
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#ifndef _ATOOL_
#define _ATOOL_

//���[�v���鎞�g�p
#define MM_CD_LOOPING 1

class Atool{
private:
	//�E�B���h�E�n���h���i�ۑ��p�j
	HWND Hwnd;
	//�h�c
	DWORD	Id;
	//�I�[�v�����Ă��邩���f
	BOOL	IsOpen;
	//���t���Ă���g���b�N
	int	PlayTrack;
	//���t���Ă��邩���f
	char Play_flag;
	//���[�v�t���O
	char loop;
public:
	//�R���X�g���N�^
	Atool(void);
	//�f�X�g���N�^
	~Atool(void);

	//�b�c�̃I�[�v��(�E�B���h�E�n���h����)
	BOOL	Open(HWND hwnd);
	//�b�c�̃N���[�Y
	BOOL	Close();
	//�b�c�̉��t�i�g���b�N�i���o�[�A���[�v�t���O�i���[�v���鎞 MM_CD_LOOPING�j�j
	BOOL	Play(int no,char loop);
	//�b�c�̃��v���C
	BOOL	RePlay();
	//�b�c�̉��t���Ƃ߂�
	BOOL	Stop();
	// ���t�I�����ɁA�E�C���h�E����Ăі߂��Ă��炤���[�`��
	BOOL	MciNotify(DWORD id);
	// ���f�B�A���}������Ă��邩�`�F�b�N����
	int		MediaPresent();
	// �g���b�N�������߂�
	int		NumberOfTracks();
};

/*�@�`�[���̊F�����
//WindowFunc�ɂ����ǉ���

  �@case WM_CREATE:
		audio.Open(hwnd);
        break;

	case MM_MCINOTIFY:
		//MCI����I���ʒm��������
		if(wParam == MCI_NOTIFY_SUCCESSFUL)audio.RePlay();
		break;

//	�I�������̓f�X�g���N�^������ɂ���Ă���܂��B

*/
#endif _ATOOL_
