///////////////////////////////////////////////////////////////////////////
//		�I�[�f�B�I�c�[���N���X�@�b�o�o
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#include "main.h"

//�N���X�̃R���X�g���N�^
Atool::Atool(){ 
	Id=0;
	IsOpen=FALSE;
	PlayTrack=0;
	Play_flag=0;
	loop=0;
	return; 
}

//�N���X�̃f�X�g���N�^
Atool::~Atool(){ 
	Stop();
	Close();
	return; 
}

//�b�c�̃I�[�v��
Atool::Open(HWND hwnd){
	Hwnd=hwnd;
	// �f�o�C�X�̃I�[�v��
	MCI_OPEN_PARMS	open;
	open.lpstrDeviceType = "cdaudio";
	if ((mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE|MCI_WAIT, (DWORD)&open)) != 0) {
		//�J���Ȃ��Ƃ�������Ԃ�
		return FALSE;
	}
	//�h�c���擾
	Id = open.wDeviceID;

	// �^�C���t�H�[�}�b�g��TMSF�ɂ���
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

// �b�c�̃N���[�Y
BOOL Atool::Close(){
	//�h�c������ꍇ�i�I�[�v������Ă���ꍇ�j
	if (Id != 0) {
		Stop();
		mciSendCommand(Id, MCI_CLOSE, MCI_WAIT, 0);
		Id = 0;
	}
	IsOpen = FALSE;
	return TRUE;
}

// �w��g���b�N�̉��t
BOOL Atool::Play(int no,char flag){
	//�I�[�v������Ă��Ȃ��Ƃ��Ԃ�
	if (!IsOpen)return FALSE;
	//���t����Ă�����X�g�b�v
	Stop();
	if(Play_flag==1)return FALSE;
	PlayTrack = no;

	if(flag>0)flag=1;
	loop=flag;

	// �g���b�N�̉��t���Ԃ𓾂�
	MCI_STATUS_PARMS	status;
	status.dwItem = MCI_STATUS_LENGTH;
	status.dwTrack = no;
	if ((mciSendCommand(Id, MCI_STATUS, MCI_STATUS_ITEM|MCI_TRACK|MCI_WAIT, (DWORD)&status)) != 0) {
		return FALSE;
	}
	// ���t���Ԃ�status.dwReturn��MSF�t�H�[�}�b�g�Ŋi�[����Ă���

	// ���t�ʒu���w�肵�ĉ��t����
	MCI_PLAY_PARMS	play;
	play.dwCallback =(DWORD)Hwnd;
	// �J�n����:�w��g���b�N:0��:0�b:0�t���[��
	play.dwFrom = MCI_MAKE_TMSF(no, 0, 0, 0);
	// �I������:�w��g���b�N�̍ŏI�ʒu
	play.dwTo = MCI_MAKE_TMSF(no,			// �g���b�N
		MCI_MSF_MINUTE(status.dwReturn),	// ��
		MCI_MSF_SECOND(status.dwReturn),	// �b
		MCI_MSF_FRAME(status.dwReturn));	// �t���[��

    if (mciSendCommand(Id, MCI_PLAY, MCI_NOTIFY|MCI_FROM|MCI_TO, (DWORD)&play)!=0) {
		return FALSE;
	}
	Play_flag=1;
	return TRUE;
}

// �w��g���b�N�̉��t
BOOL Atool::RePlay(){
	//�I�[�v������Ă��Ȃ��Ƃ��Ԃ�
	if (!IsOpen)return FALSE;

	//���[�v���w�肳��Ă��Ȃ��Ƃ��Ԃ�
	if(loop==0)return FALSE;

	// �g���b�N�̉��t���Ԃ𓾂�
	MCI_STATUS_PARMS	status;
	status.dwItem = MCI_STATUS_LENGTH;
	status.dwTrack = PlayTrack;
	if ((mciSendCommand(Id, MCI_STATUS, MCI_STATUS_ITEM|MCI_TRACK|MCI_WAIT, (DWORD)&status)) != 0) {
		return FALSE;
	}
	// ���t���Ԃ�status.dwReturn��MSF�t�H�[�}�b�g�Ŋi�[����Ă���

	// ���t�ʒu���w�肵�ĉ��t����
	MCI_PLAY_PARMS	play;
	play.dwCallback =(DWORD)Hwnd;
	// �J�n����:�w��g���b�N:0��:0�b:0�t���[��
	play.dwFrom = MCI_MAKE_TMSF(PlayTrack, 0, 0, 0);
	// �I������:�w��g���b�N�̍ŏI�ʒu
	play.dwTo = MCI_MAKE_TMSF(PlayTrack,
		MCI_MSF_MINUTE(status.dwReturn),	// ��
		MCI_MSF_SECOND(status.dwReturn),	// �b
		MCI_MSF_FRAME(status.dwReturn));	// �t���[��
		
    if (mciSendCommand(Id, MCI_PLAY, MCI_NOTIFY|MCI_FROM|MCI_TO, (DWORD)&play)!=0) {
		return FALSE;
	}
	return TRUE;
}

// ���t��~
BOOL Atool::Stop(){
	//�I�[�v������Ă��Ȃ��Ƃ��Ԃ�
	if (!IsOpen)return FALSE;

	if (PlayTrack > 0) {
		mciSendCommand(Id, MCI_STOP, MCI_WAIT, 0);
		PlayTrack = 0;
		Play_flag=0;
	}
	return TRUE;
}

// ���t�I�����ɁA�E�C���h�E����Ăі߂��Ă��炤���[�`��
BOOL Atool::MciNotify(DWORD id){
	if (Id != id)
		return FALSE;
	return TRUE;
}
