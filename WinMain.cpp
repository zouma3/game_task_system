//���C���i�E�B���h�E�쐬�j
#include"main.h"
#include"WinMain.h"

/*/////////////////////////////////////////////////////////////////////////
�@�@ 			 ���@�Q�c�V���[�e�B���O�@�^�X�N�o�[�W�����@��
  �Q�c�V���[�e�B���O���[���^�X�N�������g�p���ď����������V���[�e�B���O  
/*/////////////////////////////////////////////////////////////////////////

//���쐧���p�f�t�@�C��
#define WAIT 33
//�A�N�e�B�u�t���O
char ac_flag=0;

//�E�B���h�E����p�R�[���o�b�N�֐�
LRESULT CALLBACK WindowFunc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg){
	case WM_CREATE:
		//�h�c�̃`�F�b�N
		IsCPUID();
		//�l�l�w�̃`�F�b�N
		IsMMX();

		//�m�F�̂���
//		if(IsMMX())Error(hwnd,"�l�l�w���T�|�[�g���Ă��܂��B");
	
		//�����ݒ�
		draw.Init(hwnd);
		sound.Init(hwnd);
		audio.Open(hwnd);
		break;
	case WM_ACTIVATEAPP:
		//���X�g�A�A�ēǍ��i�ĕ`��j
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
		//MCI����I���ʒm��������
		if(wParam == MCI_NOTIFY_SUCCESSFUL)audio.RePlay();
		break;
	case WM_PAINT:
		break;
	case WM_KEYDOWN:
		//���C���L�[�̔���
		switch(wParam){
		case VK_ESCAPE:
			//�I��
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY://�I�������Ƃ����s
		break;		
	}
	return  DefWindowProc(hwnd,msg,wParam,lParam);
}	

//�E�B�����C���i�E�B���h�E�쐬���j
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpszArgs, int nCmdshow)
{
	WNDCLASSEX   wcx;	
	/*�E�C���h�E�N���X�̖��O*/
	char className[]="task";
	MSG  msg;

	/*�E�B���h�E�N���X�d�w�̒�`*/
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

	/*�E�B���h�E�N���X�̓o�^*/
	if(!RegisterClassEx(&wcx)){ MessageBox(NULL,"�E�B���h�E�N���X�̓o�^�Ɏ��s���܂����I",0,0); return 1;} 

	/*�E�B���h�E�̐���*/
	hwnd=CreateWindowEx(
		WS_EX_TOPMOST,
		className,
		"�_��",
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

	/*�E�B���h�E�̕\��*/
	ShowWindow(hwnd,nCmdshow);
	UpdateWindow(hwnd);
	SetFocus(hwnd);
	ShowCursor(FALSE);//�J�[�\���������Ȃ�����
	SetCursorPos(0,0);

	//�V�X�e���^�X�N�ɐݒ�i���ׂĂ̎n�܂�j
	task.Sys_Task_Initiator (title_init,RETURN);

	/*���b�Z�[�W���[�v*/	
	while(1){
		if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			if(!GetMessage(&msg,NULL,0,0))
				return msg.wParam;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else{
			//���쐧��
			static DWORD NowTime,PrevTime;
			NowTime = timeGetTime();
			if( NowTime - PrevTime< WAIT )continue;
			PrevTime = NowTime;
			
			//��A�N�e�B�u�����s���Ȃ�
			if(ac_flag==1)continue;
			//�o�b�N�o�b�t�@������
			draw.Cls (0,0,0,320,240,RGB(0,0,0));
			//�Q�[���̃��C���i�^�X�N�𓮂����j
			task.Dispatcher ();
			//�t���b�v
			draw.Flip ();
		}
	}
	return msg.wParam;
}
