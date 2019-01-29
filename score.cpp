
#include"main.h"
#include"score.h"

SSCR scr[10];

void score_init(void){
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
	draw.MakeSurface (1,"gra\\score_back.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (2,"gra\\score.bmp",DDSCAPS_OFFSCREENPLAIN,253);

	//��ʂ̃N���A
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	/////////////////////////////////
	//////////�^�X�N�̐ݒ�///////////
	/////////////////////////////////

	task.MakeTask ("cls",s_cls,0x1000,NO_TASK);
	task.MakeTask ("back",s_back,0x3000,NO_TASK);
	task.MakeTask ("score",score_ini,0x5000,NO_TASK);
	task.MakeTask ("cls",s_cls2,0xe000,NO_TASK);

	//�V�X�e���^�X�N
	task.Sys_Task_Initiator (NULL,NORETURN);
}
/////////////////////////////////////////////////////////////////
/////////////////////�h��ׂ��֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�o�b�N�̃N���A
void s_cls(void){
	draw.Cls (0,40,0,280,240,252);
}
//��ԏ�̃N���A
void s_cls2(void){
	draw.Cls (0,0,0,40,240,RGB(0,0,0));
	draw.Cls (0,280,0,320,240,RGB(0,0,0));
}
void s_back(void){
	RECT rc={0,0,80,80};
	static float x,y,xs=10,ys=10;
	draw.ScroolBlt (0,&x,&y,xs,ys,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
}
/////////////////////////////////////////////////////////////////
/////////////////////�X�R�A�\���֐�//////////////////////////////
/////////////////////////////////////////////////////////////////
void score_ini(void){
	FILE *fp;
	int i,j;
	if((fp=fopen("score.dat","rb"))!=NULL){
		//�t�@�C��������΂��ꂩ��Ǎ�
		for(i=0;i<10;i++){
			fscanf(fp,"%x %x %x %x %x %x %x %x %d",
				&scr[i].name[0],&scr[i].name[1],&scr[i].name[2],&scr[i].name[3],&scr[i].name[4],&scr[i].name[5],&scr[i].name[6],&scr[i].name[7],
				&scr[i].score);
		}
		fclose(fp);
	}else{
		//�t�@�C����������΂��ׂĂO��
		for(i=0;i<10;i++){
			for(j=0;j<8;j++){
				scr[i].name [j]=0;
			}
			scr[i].score =0;
		}
	}

	task.ChildMakeTask ("score_c",score_c_00,0x6000,NO_TASK);
	task.ChangeTask ("score",score_1);
}
void score_1(void){
	if((GetAsyncKeyState('Z')&0x8000)){
		task.AllKill ();
		task.Sys_Task_Initiator(title_init,RETURN);
		return;
	}
}
/////////////////////////////////////////////////////////////////
/////////////////////�\���֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//////////////////�q���O//////////////////////
void score_c_00(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =0;
	stime->time =800;
	task.ChangeTask ("score_c",score_c_01);
}
void score_c_01(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->x >40){
		stime->x =40;
		task.MakeTask ( "score10",score_c_100,0x6000,NO_TASK);
		task.ChangeTask ("score",score_c_02);
		return;
	}
	RECT rc={0,0,185,21};
	draw.ClipBltFast( 0,stime->x,stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	stime->x +=5;
}
void score_c_02(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->time <0){
		task.ChangeTask ("score",score_c_03);
		return;
	}
	RECT rc={0,0,185,21};
	draw.ClipBltFast( 0,stime->x,stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	stime->time--;
}
void score_c_03(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->x <-200){
		task.AllKill ();
		task.Sys_Task_Initiator(title_init,RETURN);
		return;
	}
	RECT rc={0,0,185,21};
	draw.ClipBltFast( 0,stime->x,stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	stime->x -=5;
}
/////////////////////////////////////////////////////////////////
/////////////////////�_���\���֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
inline void make(int cnt){
	switch(cnt){
	case 2:
		task.MakeTask ( "score10",score_c_10,0x6000,NO_TASK);
		break;
	case 3:
		task.MakeTask ( "score20",score_c_20,0x6000,NO_TASK);
		break;
	case 4:
		task.MakeTask ( "score30",score_c_30,0x6000,NO_TASK);
		break;
	case 5:
		task.MakeTask ( "score40",score_c_40,0x6000,NO_TASK);
		break;
	case 6:
		task.MakeTask ( "score50",score_c_50,0x6000,NO_TASK);
		break;
	case 7:
		task.MakeTask ( "score60",score_c_60,0x6000,NO_TASK);
		break;
	case 8:
		task.MakeTask ( "score70",score_c_70,0x6000,NO_TASK);
		break;
	case 9:
		task.MakeTask ( "score80",score_c_80,0x6000,NO_TASK);
		break;
	case 10:
		task.MakeTask ( "score90",score_c_90,0x6000,NO_TASK);
		break;
	}
}
inline void name(int no,int x,int y){

	RECT bg_Scr;
	for(int i=0;i<8;i++){
			unsigned int tmp1=0,tmp2=0;
			if(scr[no-1].name [i]==0x0093)break;
			tmp1=scr[no-1].name[i]>>4;//��ʂS�r�b�g
			tmp2=scr[no-1].name[i]&0x000f;//���ʂS�r�b�g
			SetRect(&bg_Scr,30+tmp1*20,138+tmp2*20,30+tmp1*20+20,138+tmp2*20+20);	
			draw.ClipBltFast( 0,i*11+40+x,y-10,2,bg_Scr,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	}
}

inline void tensu(int tensu,int x,int y){
	RECT tensu_rc[10]={{30,138,40,150},{50,138,60,150},{70,138,80,150},{90,138,100,150},{110,138,120,150},{130,138,140,150},{150,138,160,150},{170,138,180,150},{190,138,200,150},{210,138,220,150}};
	char text[10];
	wsprintf(text,"%d",tensu);
	char j=strlen(text);
	//�_����`��
	for(char t_cnt=j-1,c_cnt=0;t_cnt>=0;t_cnt--,c_cnt++){
		switch (text[t_cnt]){
		case '0':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[0],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '1':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[1],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '2':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[2],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '3':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[3],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '4':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[4],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '5':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[5],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '6':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[6],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '7':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[7],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '8':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[8],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '9':
			draw.ClipBltFast (0,270+x-c_cnt*12,y ,2,tensu_rc[9],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////
/////////////////////�\�������֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
void score_c_100(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =210;
	stime->time =250;
	stime->no=10;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_90(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =170;
	stime->time =250;
	stime->no=9;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_80(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =130;
	stime->time =250;
	stime->no=8;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_70(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =90;
	stime->time =250;
	stime->no=7;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_60(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =50;
	stime->time =250;
	stime->no=6;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_50(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =210;
	stime->time =250;
	stime->no=5;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_40(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =170;
	stime->time =250;
	stime->no=4;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_30(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =130;
	stime->time =250;
	stime->no=3;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_20(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =90;
	stime->time =250;
	stime->no=2;
	task.ChangeTask ("score_c",score_c_1);
}
void score_c_10(void){
	STIME *stime=(STIME *)task.workspace ();
	stime->x =-200;
	stime->y =50;
	stime->time =250;
	stime->no=1;
	task.ChangeTask ("score_c",score_c_1);
}
/////////////////////////////////////////////////////////////////
/////////////////////////�\���֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
void score_c_1(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->x >0){
		stime->x =0;
		if(stime->no !=6)make(stime->no);
		task.ChangeTask ("score",score_c_2);
		return;
	}
	RECT rc={90,110,240,125};
	draw.ClipBltFast(0,130+(-stime->x),stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,85,76,135,86);
	draw.ClipBltFast(0,230+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,245,0+(stime->no-1) *14,280,0+(stime->no-1) *14+14);
	draw.ClipBltFast(0,130+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);

	tensu(scr[stime->no-1].score ,-stime->x ,stime->y );
	name(stime->no,stime->x,stime->y);
	
	stime->x +=10;
}
void score_c_2(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->time <0){
		task.ChangeTask ("score",score_c_3);
		return;
	}
	RECT rc={90,110,240,125};
	draw.ClipBltFast(0,130+(-stime->x),stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,85,76,135,86);
	draw.ClipBltFast(0,230+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,245,0+(stime->no-1) *14,280,0+(stime->no-1) *14+14);
	draw.ClipBltFast(0,130+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	
	tensu(scr[stime->no-1].score ,-stime->x ,stime->y );
	name(stime->no,stime->x,stime->y);

	stime->time--;
}
void score_c_3(void){
	STIME *stime=(STIME *)task.workspace ();

	if(stime->x <-200){
		if(stime->no ==6)make(stime->no);
		task.KillTask();
		return;
	}
	RECT rc={90,110,240,125};
	draw.ClipBltFast(0,130+(-stime->x),stime->y,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,85,76,135,86);
	draw.ClipBltFast(0,230+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,245,0+(stime->no-1) *14,280,0+(stime->no-1) *14+14);
	draw.ClipBltFast(0,130+(-stime->x),stime->y-20,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);

	tensu(scr[stime->no-1].score ,-stime->x ,stime->y );
	name(stime->no,stime->x,stime->y);

	stime->x -=10;
}
