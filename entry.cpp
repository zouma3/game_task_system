#include"main.h"
#include"entry.h"

SSC sc[11];

void entry_init(void){	
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
	draw.MakeSurface (3,"gra\\syousai_s.bmp",DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	draw.MakeSurface (4,"gra\\bomb.bmp",DDSCAPS_OFFSCREENPLAIN,253);

	//��ʂ̃N���A
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	//�T�E���h�̃��[�h
	sound.Loadwave(1,"sound\\kamui_lockon.wav",10);
	sound.Loadwave(2,"sound\\kamui_exp_03.wav",10);
	sound.Loadwave(3,"sound\\kamui_exp_04.wav",10);
	sound.Loadwave(4,"sound\\kamui_sde.wav",10);
	
	/////////////////////////////////
	//////////�^�X�N�̐ݒ�///////////
	/////////////////////////////////

	//�t�@�C������Ǎ�
	FILE *fp;
	int i,j;
	if((fp=fopen("score.dat","rb"))!=NULL){
		//�t�@�C��������΂��ꂩ��Ǎ�
		for(i=0;i<10;i++){
			fscanf(fp,"%x %x %x %x %x %x %x %x %d",
				&sc[i].name[0],&sc[i].name[1],&sc[i].name[2],&sc[i].name[3],&sc[i].name[4],&sc[i].name[5],&sc[i].name[6],&sc[i].name[7],
				&sc[i].score);
		}
		fclose(fp);
	}else{
		//�t�@�C����������΂��ׂĂO��
		for(i=0;i<10;i++){
			for(j=0;j<8;j++){
				sc[i].name [j]=0;
			}
			sc[i].score =0;
		}
	}
	score=300000;
	//���ʂ�T��������
	sc[10].score =0;
	for(i=0;i<10;i++){
		if(sc[i].score >= score && sc[i+1].score < score){
			cnt=i+1;
			break;
		}	
	}
	//�����L���O�O�Ȃ�X�R�A��
	if(cnt==11){
		task.Sys_Task_Initiator (score_init,RETURN);
		return;
	}
	//�����L���O���Ȃ�e�^�X�N�����C�N
	task.MakeTask ("cls",e_cls,0x1000,NO_TASK);
	task.MakeTask ("back",e_back,0x3000,NO_TASK);
	task.MakeTask ("cls",e_cls2,0xe000,NO_TASK);
	task.MakeTask ("sele",e_sele_init,0xe000,NO_TASK);

	//�V�X�e���^�X�N
	task.Sys_Task_Initiator (NULL,NORETURN);
}
/////////////////////////////////////////////////////////////////
/////////////////////�h��ׂ��֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�o�b�N�̃N���A
void e_cls(void){
	draw.Cls (0,40,0,280,240,252);
}
//��ԏ�̃N���A
void e_cls2(void){
	draw.Cls (0,0,0,40,240,RGB(0,0,0));
	draw.Cls (0,280,0,320,240,RGB(0,0,0));
}
void e_back(void){
	RECT rc={0,0,80,80};
	static float x,y,xs=10,ys=10;
	//�w�i�̃X�N���[��
	draw.ScroolBlt (0,&x,&y,xs,ys,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//�`��
	SetRect(&rc,0,50,240,240);
	draw.ClipBltFast ( 0,36,10,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,0,18,141,21);
	draw.ClipBltFast ( 0,40,180,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,91,122,244,124);
	draw.ClipBltFast ( 0,127,235,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,2,32,85,45);
	draw.ClipBltFast ( 0,50,200,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);

	SetRect(&rc,245,0+14*cnt,280,14+14*cnt);
	draw.ClipBltFast ( 0,130,50,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
}
//�Z���N�g�̃C�j�V�����C�Y
void e_sele_init(void){
	SXY *sxy=(SXY *)task.workspace ();
	sxy->x  =0;
	sxy->y  =0;
	//�L�[�t���O
	sxy->key_u=0;
	sxy->key_d=0;
	sxy->key_l=0;
	sxy->key_r=0;
	sxy->key_x=0;
	sxy->key_z=0;
	//�����̃N���A
	for(int i=0;i<8;i++)sxy->name[i]=0x0063;
	//������
	sxy->cnt =0;
	//���̃`�F���W
	task.ChildMakeTask ( "sele_c",e_sele_c,0xe000,NO_TASK);
	task.ChangeTask ("sele",e_sele);
}
//�Z���N�g��ʕ`��
void e_sele(void){
	SXY *sxy=(SXY *)task.workspace ();
	RECT rc={91,25,111,45};
	//���O�̕\��
	for(int i=0;i<8;i++){	
		unsigned int tmp1=0,tmp2=0;
		if(sxy->name[i]==0x0093)break;
		tmp1=sxy->name[i]>>4;//��ʂS�r�b�g
		tmp2=sxy->name[i]&0x000f;//���ʂS�r�b�g
		SetRect(&rc,30+tmp1*20,138+tmp2*20,30+tmp1*20+20,138+tmp2*20+20);	
		draw.ClipBltFast( 0,160+12*i,200,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	}
	//�_���̕\��
	tensu(score,-10,70);
}

void e_sele_c(void){
	//���[�N�X�y�[�X
	SXY *sxy=(SXY *)task.p_work_add ();
	RECT rc={91,25,111,45};
	//���~�b�g�`�F�b�N
	if(sxy->cnt <0)sxy->cnt =0;
	if(sxy->cnt >7)sxy->cnt =7;
	if(sxy->x <0)sxy->x=0;
	if(sxy->x >9)sxy->x=9;
	if(sxy->y <0)sxy->y=0;
	if(sxy->y >3)sxy->y=3;
	//�J�[�\���`��
	draw.ClipBltFast ( 0,61+20*sxy->x ,94+20*sxy->y ,2,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//�o�^�\�蕶���\���i�������j
	SetRect(&rc,30+sxy->x*20,138+sxy->y*20,30+sxy->x*20+20,138+sxy->y *20+20);
	draw.AlphaBltFast ( 0,160+12*sxy->cnt ,200,2,rc,0,1);
	//�L�[�֌W
	//�t���O�������Ă��鎞������
	if((GetAsyncKeyState(VK_UP)&0x8000)&&(sxy->key_u==0)){sxy->y --;sxy->key_u=1;sound.Play(1,160);}
	if((GetAsyncKeyState(VK_DOWN)&0x8000)&&(sxy->key_d==0)){sxy->y ++;sxy->key_d=1;sound.Play(1,160);}
	if((GetAsyncKeyState(VK_LEFT)&0x8000)&&(sxy->key_l==0)){sxy->x --;sxy->key_l=1;sound.Play(1,160);}
	if((GetAsyncKeyState(VK_RIGHT)&0x8000)&&(sxy->key_r==0)){sxy->x ++;sxy->key_r=1;sound.Play(1,160);}
	//�t���O�̕ω�
	if((GetAsyncKeyState(VK_UP)&0x8000)==0)sxy->key_u=0;
	if((GetAsyncKeyState(VK_DOWN)&0x8000)==0)sxy->key_d=0;
	if((GetAsyncKeyState(VK_LEFT)&0x8000)==0)sxy->key_l=0;
	if((GetAsyncKeyState(VK_RIGHT)&0x8000)==0)sxy->key_r=0;
	
	//����//
	unsigned int temp;
	SBOM *sbom;
	if((GetAsyncKeyState('Z')&0x8000)&&(sxy->key_z==0)){
		//�r�b�g���Z�ɂ��g�ݍ��킹
		temp=sxy->x <<4;
		temp=temp|sxy->y;
		//�����i���o�[������
		sxy->name [sxy->cnt]=temp;

		//�Ōォ�d�m�c��I�����ꂽ���I��
		if((sxy->cnt ==7)||(sxy->name[sxy->cnt]==0x0093)){
			sound.Play (3,160);
			//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
			sbom=(SBOM *)task.MakeTask ("bom",bom_init,0xff00,NO_TASK);
			//���[�N�X�y�[�X�ɑ���i�������j
			sbom->x=160+12*sxy->cnt;sbom->y=200;sbom->cnt=0;sbom->kind=2;

			int i;
			//���e�����炵�Ă���
			for(i=10;i>cnt;i--){
				memcpy(&sc[i],&sc[i-1],36);
			}
			//���ʓ��ɓ���
			for(i=0;i<8;i++){
				sc[cnt].name[i]=sxy->name[i];
				sc[cnt].score=score;
			}
			//�������ݏ�������
			FILE *fp;
			fp=fopen("score.dat","wb");
			for(i=0;i<10;i++){
				fprintf(fp,"%x %x %x %x %x %x %x %x %d\n",
					sc[i].name[0],sc[i].name[1],sc[i].name[2],sc[i].name[3],sc[i].name[4],sc[i].name[5],sc[i].name[6],sc[i].name[7],
					sc[i].score);
			}
			fclose(fp);
				
			//�������Ȃ��֐��փ`�F���W
			task.ChangeTask ("e_sele_c",e_sele_c1);
			return;
		}

		sound.Play (2,160);
		//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
		sbom=(SBOM *)task.MakeTask ("bom",bom_init,0xff00,NO_TASK);
		//���[�N�X�y�[�X�ɑ���i�������j
		sbom->x=160+12*sxy->cnt;sbom->y=200;sbom->cnt=0;sbom->kind=1;

		sxy->cnt++;sxy->key_z=1;
	}
	if((GetAsyncKeyState('Z')&0x8000)==0)sxy->key_z=0;

	//�L�����Z��//
	if((GetAsyncKeyState('X')&0x8000)&&(sxy->key_x==0)){	
		//�O�ȍ~�͎��s�����Ȃ�
		if((sxy->cnt!=0)){
			sound.Play (4,160);
			//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
			sbom=(SBOM *)task.MakeTask ("bom",bom_init,0xff00,NO_TASK);
			//���[�N�X�y�[�X�ɑ���i�������j
			sbom->x=160+12*sxy->cnt;sbom->y=200;sbom->cnt=0;sbom->kind=3;
		}
		//�����Ȃ��O���t�B�b�N������
		sxy->name [sxy->cnt-1]=0x0063;
		//�J�E���g��߂�
		sxy->cnt--;sxy->key_x=1;
	}
	if((GetAsyncKeyState('X')&0x8000)==0)sxy->key_x=0;
}
//�������s�����Ȃ��֐�
void e_sele_c1(void){
	//���[�N�X�y�[�X
	SXY *sxy=(SXY *)task.p_work_add ();

}
//�����C�j�V�����C�Y
void bom_init(void){
	//�����̃��[�N�X�y�[�X
	SBOM *sbom=(SBOM *)task.workspace ();
	//�����̎�ނɍ��킹�ă`�F���W�^�X�N
	switch(sbom->kind){
	case 1:
		task.ChangeTask("bom1",bom1);
		break;
	case 2:
		task.ChangeTask("bom2",bom2);
		break;
	case 3:
		task.ChangeTask("bom3",bom3);
		break;
	}
}
//�����P
void bom1(void){
	//�����̃��[�N�X�y�[�X
	SBOM *sbom=(SBOM *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={16,0+32*sbom->cnt,48,0+32*sbom->cnt+32};
	draw.ClipBltCenter (0,sbom->x+5 ,sbom->y +6,1,1,4,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//���܂ŗ���ƃL��
	if(sbom->cnt >5)task.KillTask ();
	sbom->cnt ++;
}
//�����Q�i���ꂪ���s�����ƏI���j
void bom2(void){
	//�����̃��[�N�X�y�[�X
	SBOM *sbom=(SBOM *)task.workspace ();
	//�`��
	RECT rc={48,0+48*sbom->cnt,96,0+48*sbom->cnt+48};
	draw.ClipBltCenter (0,sbom->x+5 ,sbom->y +6,1,1,4,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//�e���J�E���g�̌�I��
	if(sbom->cnt >10){
		task.AllKill ();
		task.Sys_Task_Initiator (score_init,RETURN);
	}
	sbom->cnt ++;
}
//�L�����Z���p����
void bom3(void){
	//�����̃��[�N�X�y�[�X
	SBOM *sbom=(SBOM *)task.workspace ();
	//�`��
	RECT rc={256,0,320,64};
	draw.AlphaBltFast( 0,sbom->x-27,sbom->y-27,3,rc,-sbom->cnt,0);
	//���܂ŗ���ƏI��
	if(sbom->cnt >10)task.KillTask ();
	sbom->cnt ++;
}