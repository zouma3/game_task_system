
#include"main.h"
#include"title.h"


void title_init(void){
	//��ʂ̃N���A
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	Sleep(1000);
	//�o�^����Ă���^�X�N��S�ăL��
	task.AllKill ();
	//�o�^����Ă���摜�A�T�E���h��S�ĉ��
	draw.Release();
	sound.Release();
	Sleep(1000);

	//�T�[�t�F�C�X�����i�摜�Ǎ��j
	draw.MakeSurface (1,"gra\\title_back.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (2,"gra\\title.bmp",DDSCAPS_OFFSCREENPLAIN,253);

	//��ʂ̃N���A
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	sound.Loadwave(1,"sound\\kamui_macine_01.wav",10);

	/////////////////////////////////
	//////////�^�X�N�̐ݒ�///////////
	/////////////////////////////////

	task.MakeTask ("cls",cls,0x1000,NO_TASK);
	task.MakeTask ("title",title_ini,0x5000,NO_TASK);
	task.MakeTask ("cls",cls2,0xe000,NO_TASK);

	//�V�X�e���^�X�N
	task.Sys_Task_Initiator (NULL,NORETURN);
}
/////////////////////////////////////////////////////////////////
/////////////////////�h��ׂ��֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�o�b�N�̃N���A
void cls(void){
	draw.Cls (0,40,0,280,240,252);
}
//��ԏ�̃N���A
void cls2(void){
	draw.Cls (0,0,0,40,240,RGB(0,0,0));
	draw.Cls (0,280,0,320,240,RGB(0,0,0));
}
/////////////////////////////////////////////////////////////////
/////////////////////�Z���N�g�֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�C�j�V�����C�Y
void sele_init(void){
	SKEY *skey=(SKEY *)task.workspace ();
	skey->key =0;
	skey->cnt =0;
	skey->time =500;
	task.ChangeTask ("sele1",sele1);
}
//�Z���N�g�P�i�v�b�V���y�L�[�j
void sele1(void){
	SKEY *skey=(SKEY *)task.workspace ();
	RECT rc={0,50,97,75};
		
	if(skey->time <0){
		task.AllKill ();
		task.Sys_Task_Initiator(score_init,RETURN);
		return;
	}
	skey->time --;

	if(skey->cnt >20)skey->cnt =0;
	if(skey->cnt <=10)draw.ClipBltCenter (0,160,180,1,1,2,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	skey->cnt++;

	if((GetAsyncKeyState('Z')&0x8000)){
		skey->key=1;
		sound.Play (1,160);
		task.ChangeTask ("sele2",sele2);
	}
}
//�Z���N�g�Q�i�Z���N�g�j
void sele2(void){
	SKEY *skey=(SKEY *)task.workspace ();
	static char cnt=0;
	RECT rc={0,75,97,120};
	RECT rc2={0,125,97,145};

	if(cnt>1)cnt=1;
	if(cnt<0)cnt=0;

	switch(cnt){
	case 0:
		draw.ClipBltCenter (0,160,176,1,1,2,rc2,DDBLT_KEYSRC|DDBLT_WAIT);
		if((GetAsyncKeyState('Z')&0x8000)&&(skey->key ==0)){
			sound.Play (1,160);
			//�V�X�e���ȊO�̃^�X�N�폜
			task.AllKill ();
			task.Sys_Task_Initiator (game_init,RETURN);
			cnt=0;
		}
		break;
	case 1:
		draw.ClipBltCenter (0,160,198,1,1,2,rc2,DDBLT_KEYSRC|DDBLT_WAIT);
		if((GetAsyncKeyState('Z')&0x8000)&&(skey->key ==0)){
			cnt=0;
			//�I��
			PostQuitMessage(0);
		}
		break;
	default:
		break;
	}
	if((GetAsyncKeyState('Z')&0x8000)==0)skey->key =0;

	if(GetAsyncKeyState(VK_UP)&0x8000)cnt--;
	if(GetAsyncKeyState(VK_DOWN)&0x8000)cnt++;

	draw.ClipBltCenter (0,160,180,1,1,2,rc,DDBLT_KEYSRC|DDBLT_WAIT);
}
/////////////////////////////////////////////////////////////////
/////////////////////�^�C�g���֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�C�j�V�����C�Y
void title_ini(void){
	SCNT *scnt=(SCNT *)task.workspace ();
	scnt->cnt =0;
	task.ChangeTask ("title1",title_1);
}
//�^�C�g��
void title_1(void){
	SCNT *scnt=(SCNT *)task.workspace ();
	RECT rc={0,0,97,50};
	draw.ClipBltCenter (0,160,120,1,1,2,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	scnt->cnt ++;
	if(scnt->cnt>40){
		task.ChangeTask ("title2",title_2);
		scnt->cnt=1;
	}
}
void title_2(void){
	SCNT *scnt=(SCNT *)task.workspace ();
	RECT rc={0,0,97,50};
	draw.ClipBltCenter (0,160,120,scnt->cnt,scnt->cnt,2,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	scnt->cnt+=0.2f;
	if(draw.WhiteOut(10)){
		task.ChangeTask ("title3",title_3);
	}
}
void title_3(void){
	RECT rc={0,0,240,240};
	draw.ClipBltCenter (0,160,120,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	if(draw.WhiteIn(20)){
		task.ChangeTask ("title4",title_4);
		task.MakeTask ("sele1",sele_init,0x6000,NO_TASK);
	}
}
void title_4(void){
	RECT rc={0,0,240,240};
	draw.ClipBltCenter (0,160,120,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);
}
