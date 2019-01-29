///////////////////////////////////////////////////////////////////////////
//		�V�X�e���c�[���N���X�@�b�o�o
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#include "main.h"

//�t���[�����J�E���g
void FrameCnt(void){
	static DWORD NowTime=0,PrevTime=0;
	static char text[10];
	HDC hdc;
	NowTime = timeGetTime();
	sprintf(text,"FPS:%3.0f",(float)1000 / (NowTime - PrevTime));

	draw.GetDC (0,&hdc);
	TextOut(hdc,0,0,text,strlen(text));
	draw.ReleaseDC (0,hdc);

	PrevTime = NowTime;
}
//�����_��
int randamize(int low, int high)
{
	return ((int)((high - low + 1) * (rand() / 32767.1) + low));
}
//�G���[���̏���
BOOL Error(HWND hwnd,char* message){
	MessageBox(hwnd, message, "�G���[����", MB_OK);
	PostQuitMessage(0);
	return FALSE;
}

/* CPUID �̑��݃`�F�b�N���܂� */
BOOL IsCPUID(){
	//�`�F�b�N�p�t���O
    DWORD dwPreEFlags, dwPostEFlags;
	////�h�c�̃`�F�b�N////
    //�C�����C���A�Z���u���J�n//
    _asm {
        //EFlags �̒l�̎擾
        pushfd
        pop     eax
        mov     dwPreEFlags, eax
        //CPUID ���߂̑��݂̃`�F�b�N (ID �t���O�̃`�F�b�N)
        xor     eax, 00200000h
        push    eax
        popfd
        //EFlags �̒l�̎擾
        pushfd
        pop     eax
        mov     dwPostEFlags, eax
    }
	//�t���O�������Ȃ��
    if(dwPreEFlags == dwPostEFlags)
        return FALSE;
    return TRUE;
}

/* MMX �e�N�m���W�T�|�[�g�̃`�F�b�N���܂� */
BOOL IsMMX(){
	//�`�F�b�N�p�t���O
    DWORD dwRetEDX;
    // CPUID ���߂̃`�F�b�N
    if(!IsCPUID()){
		Error(NULL,"MMX���T�|�[�g����Ă��܂���");
		return FALSE;
	}
    ////MMX �e�N�m���W�̃`�F�b�N////
    //�C�����C���A�Z���u���J�n//
    _asm {
		//eax���W�X�^�ɂP����
        mov     eax, 1
		//eax���P�łb�o�t�h�c�����s����ƃt���O���A���Ă���
        cpuid
        //MMX���߂͂Q�S�r�b�g�ڂ̕����Ƀt���O������
		and     edx, 00800000h
		//�`�F�b�N�p�ϐ��ɑ��
        mov     dwRetEDX, edx
    }
	//�`�F�b�N�����܂�
    if(dwRetEDX) return TRUE;
    return FALSE;
}
