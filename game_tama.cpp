#include"main.h"
#include"game_str.h"
#include"game.h"

extern unsigned long score;
extern unsigned int jikan;
extern unsigned int map_a[400][7];
extern STEKI steki_t[500];
/////////////////////////////////////////////////////////////////
/////////////////////�G�e����֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�G�̒e�C�j�V�����C�Y
void t_tama_init(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�����̎�ނɍ��킹�ă`�F���W�^�X�N
	switch(stama->kind){
	//���ʂ̒e
	case 1:
		stama->cnt =0;stama->g_cnt =0;stama->h =8;stama->w =8;
		task.ChangeTask("t_tama1",t_tama1);
		break;
	//�e����]���Ȃ���
	case 2:
		stama->cnt =0;stama->g_cnt =0;stama->h =8;stama->w =8;
		task.ChangeTask("t_tama2",t_tama2);
		break;
	//���@������p�i�΁j
	case 3:
		stama->cnt =0;stama->g_cnt =0;stama->h =8;stama->w =8;
		SetRect(&stama->rc ,0,175,16,191);
		task.ChangeTask("t_tama3",t_tama3);
		break;
	//�~�T�C���i��莞�Ԏ��@�ǔ��j
	case 4:
		stama->cnt =0;stama->g_cnt =0;stama->h =8;stama->w =8;stama->dir=0;stama->hp =0;stama->tensu =100;
		SetRect(&stama->rc ,16,175,32,191);
		task.ChangeTask("t_tama4",t_tama4_1);
		break;
	//�g�k�G�l���M�[�e
	case 5:
		stama->cnt =0;stama->g_cnt =0;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama5",t_tama5);
		break;
	//���[�U�[
	case 6:	
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama6",t_tama6_1);
		break;
	case 7:
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama6",t_tama6);
		break;
	//�M���i���蔻�薳���j
	case 8:	
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama8",t_tama8);
		break;
	//����~�T�C��
	case 9:
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama9",t_tama9);
		break;
	//�M���i���蔻�薳���j�i�e�����j
	case 10:	
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;
		task.ChangeTask("t_tama10",t_tama10);
		break;
	//��]���e
	case 11:	
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =8;stama->w =8;stama->dir=0;stama->angle =0;stama->hp =0;stama->tensu =100;
		task.ChangeTask("t_tama11",t_tama11);
		break;
	//��]���e
	case 12:	
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =20;stama->w =20;
		task.ChangeTask("t_tama12",t_tama12_1);
		break;
	//���[�U�[��
	case 13:
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =20;stama->w =20;
		task.ChangeTask("t_tama13",t_tama13);
		break;
	//���[�U�[��
	case 14:
		stama->cnt =0;stama->cnt2 =0;stama->g_cnt =4;stama->h =20;stama->w =20;
		task.ChangeTask("t_tama14",t_tama14);
		break;
	}
}
//�G�e�P
void t_tama1(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={8*stama->g_cnt,165,8*stama->g_cnt+8,173};
	draw.ClipBltCenter(5,stama->x,stama->y,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&stama->x ,&stama->y ,stama->angle ,stama->kyori );
	//���܂ŗ���ƃL��
	if(stama->cnt >1){
		stama->cnt =0;
		if(stama->g_cnt >6)
			stama->g_cnt=0;
		stama->g_cnt ++;
	}
	stama->cnt ++;
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	rimito(stama->x ,stama->y ,0);
}
//�G�e�Q
void t_tama2(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={12*stama->g_cnt,151,12*stama->g_cnt+12,163};
	draw.ClipBltCenter(5,stama->x,stama->y,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&stama->x ,&stama->y ,stama->angle ,stama->kyori );
	//���܂ŗ���ƃL��
	if(stama->cnt >1){
		stama->cnt =0;
		if(stama->g_cnt >7)
			stama->g_cnt=0;
		stama->g_cnt ++;
	}
	stama->cnt ++;
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	rimito(stama->x ,stama->y ,0);
}
//�G�e�R
void t_tama3(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	if(stama->z>0){
		stama->z-=2;
		if(stama->z<0)stama->z=0;
	}
	if(stama->z<0){
		stama->z+=2;
		if(stama->z>0)stama->z=0;
	}
	draw.TDTurnBlt ( 5,stama->x,stama->y,stama->z,1,stama->rc,stama->angle*5,8,8);
	draw.move72 (&stama->x ,&stama->y ,stama->angle ,stama->kyori );
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	rimito(stama->x ,stama->y ,0);
}
//�G�e�S
void t_tama4_1(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	SJIKI *sjiki=(SJIKI *)ji();
	if(stama->cnt <100){
		stama->dir =(int)(atan2((stama->y)-(sjiki->y),(sjiki->x)-(stama->x))*36/3.141592);
		if(stama->dir<0)stama->dir +=72;
		int i=(stama->dir-stama->angle);
		if(i<0)i+=72;
		if(i>36)
			stama->angle--;
		else
			stama->angle++;
		stama->cnt++;
	}else{
		stama->angle=stama->dir;
	}

	if(stama->angle<0)stama->angle=71;
	if(stama->angle>71)stama->angle=0;
	if(stama->z>0)stama->z-=2;
	if(stama->z<0)stama->z+=2;
	if(stama->z==0){
		stama->z=0;
		task.ChangeTask("tama4",t_tama4_2);
	}
	draw.TDTurnBlt ( 5,stama->x,stama->y,stama->z,1,stama->rc,stama->dir*5,8,8);
	draw.move72 (&stama->x ,&stama->y ,stama->angle,stama->kyori);
	rimito(stama->x ,stama->y ,stama->z);
}
void t_tama4_2(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	SJIKI *sjiki=(SJIKI *)ji();
	SBOMB *sbomb;
	if(stama->cnt <100){
		stama->dir =(int)(atan2((stama->y)-(sjiki->y),(sjiki->x)-(stama->x))*36/3.141592);
		if(stama->dir<0)stama->dir +=72;
	
		int i=(stama->dir-stama->angle);
		if(i<0)i+=72;
		if(i>36)
			stama->angle--;
		else
			stama->angle++;
		if(stama->angle<0)stama->angle=71;
		if(stama->angle>71)stama->angle=0;
	
		stama->cnt++;
	}else{
		stama->angle=stama->dir;
	}
	stama->z=0;
	if(stama->hp<0){
		sound.Play(2,stama->x);
		//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//���[�N�X�y�[�X�ɑ���i�������j
		sbomb->x=stama->x;sbomb->y=stama->y;sbomb->z=stama->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=randamize(0,72);sbomb->speed=2;sbomb->kind=3;
		task.KillTask();
		return;
	}

	draw.TDTurnBlt ( 5,stama->x,stama->y,stama->z,1,stama->rc,stama->dir*5,8,8);
	draw.move72 (&stama->x ,&stama->y ,stama->angle,stama->kyori);
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	rimito(stama->x ,stama->y ,stama->z);
}
//�G�e�T
void t_tama5(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={14*stama->g_cnt,191,14*stama->g_cnt+14,205};
	draw.ClipBltCenter(5,stama->x,stama->y,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&stama->x ,&stama->y ,stama->angle ,stama->kyori );
	//���܂ŗ���ƃL��
	if(stama->cnt >1){
		stama->cnt =0;
		if(stama->g_cnt >2)
			stama->g_cnt=0;
		stama->g_cnt ++;
	}
	stama->cnt ++;
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	rimito(stama->x ,stama->y ,0);
}
//���ˌ�
void t_tama6(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	if(stama->s>2)stama->s=2;
	if(stama->cnt >180)task.KillTask ();
	stama->cnt ++;
	stama->s+=0.1f;
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={13,204,34,225};
	draw.AlphaBlt ( 5,stama->x,stama->y,stama->z,stama->s,stama->s,2,rc,-1,1);
}
//���ˌ�2
void t_tama14(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(stama->s>2)stama->s=2;
	if(stama->cnt >180)task.KillTask ();
	stama->cnt ++;
	stama->s+=0.1f;
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={13,204,34,225};
	draw.AlphaBlt ( 5,steki->x,steki->y,steki->z,stama->s,stama->s,2,rc,-1,1);
}
//���[�U�[
void t_tama6_1(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�`�F���W
	if(stama->g_cnt <3){
		stama->g_cnt =3;
		task.ChangeTask ("t_tama6",t_tama6_2);
		return;
	}	
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={14*stama->g_cnt+172,36,14*stama->g_cnt+172+14,50};
	draw.TurnBltFastCenter ( 5,stama->x,stama->y,2,rc,stama->angle*5 ,7,13);
	if(stama->cnt >2){	
		stama->cnt =0;
		stama->g_cnt --;
	}
	stama->cnt ++;
}
void t_tama6_2(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	if(stama->cnt2 >150){
		task.ChangeTask ("t_tama6",t_tama6_3);
		return;
	}
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={14*stama->g_cnt+172,36,14*stama->g_cnt+172+14,50};
	draw.TurnBltFastCenter( 5,stama->x,stama->y,2,rc,stama->angle*5 ,7,13);
	//���܂ŗ���ƃL��
	if(stama->cnt >0){
		stama->cnt =0;
		if(stama->g_cnt >2)
			stama->g_cnt=1;
		stama->g_cnt ++;
	}
	stama->cnt ++;
	stama->cnt2 ++;
	jiki_hantei2(stama->x,stama->y,stama->z,stama->w,stama->h );
}
void t_tama6_3(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	//�`�F���W
	if(stama->g_cnt >3){
		task.KillTask ();
		return;
	}	
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={14*stama->g_cnt+172,36,14*stama->g_cnt+172+14,50};
	draw.TurnBltFastCenter ( 5,stama->x,stama->y,2,rc,stama->angle*5 ,7,13);
	if(stama->cnt >2){	
		stama->cnt =0;
		stama->g_cnt ++;
	}
	stama->cnt ++;
}

//�M���i���蔻�薳���j
void t_tama8(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	STAMA *stamap=(STAMA *)task.p_work_add ();
	RECT rc={34,203,55,225};
	draw.AlphaBlt ( 5,stama->x,stama->y+stamap->cnt,0,stama->s,stama->s,2,rc,7,1);
}
//����~�T�C���i���蔻�薳���j
void t_tama9(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	STAMA *stama2;
	int i,j,k,l,m;
	RECT rc={120,175,135,236};
	draw.ClipBltCenter ( 5,stama->x,stama->y+stama->cnt,1,1,1,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	switch(stama->cnt){
	case 70:
		for(l=0;l<4;l++){
			int dir =randamize(0,71);
			for(i=0,j=stama->x,k=stama->y;i<20;i++){
				stama2=(STAMA *)task.ChildMakeTask("t_tama_init",t_tama_init,0x5100,NO_TASK);
				stama2->x=j;stama2->y=k;stama2->z=0;stama2->angle =dir;stama2->kind =8;stama2->s =(float)(0.1*i);
				draw.move72 (&j,&k,dir,i);
			}
		}
		break;
	case 100:
		sound.Play (4,stama->x);
		SBOMB *sbomb;

		//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0xf000,NO_TASK);
		//���[�N�X�y�[�X�ɑ���i�������j
		sbomb->toumei=-14;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=6;
	
		//�쐬���ꂽ�^�X�N�̃��[�N�X�y�[�X���ԋp�����
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//���[�N�X�y�[�X�ɑ���i�������j
		sbomb->toumei=-2;sbomb->x=stama->x;sbomb->y=stama->y+stama->cnt;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
		sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.3f;sbomb->psy=0.3f;
		
		for(m=0;m<71;m+=6){
			stama2=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
			stama2->x=stama->x;stama2->y=stama->y+stama->cnt;stama2->z=0;stama2->kind =12;stama2->kyori =0;stama2->s=1;
			draw.move72 (&stama2->x,&stama2->y,m,30);
		}
				
		for(m=0;m<71;m+=4){
			stama2=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
			stama2->x=stama->x;stama2->y=stama->y+stama->cnt;stama2->z=0;stama2->kind =12;stama2->kyori =0;stama2->s=1;
			draw.move72 (&stama2->x,&stama2->y,m,60);
		}
		stama2=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama2->x=stama->x;stama2->y=stama->y+stama->cnt;stama2->z=0;stama2->kind =12;stama2->kyori =0;stama2->s=1;
		break;
	case 110:
		sound.Play (4,stama->x);
		task.KillTask ();
		break;
	}
	stama->cnt+=2;
}
//�M���i���蔻�薳���j�i�e�����j
void t_tama10(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	RECT rc={34,203,55,225};
	draw.AlphaBlt ( 5,stama->x,stama->y,0,stama->s,stama->s,2,rc,7,1);
}
//��]���e
void t_tama11(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	SJIKI *sjiki=(SJIKI *)ji();
	RECT rc={36,175,53,192};
	if(stama->cnt <100){
		int angle =(int)(atan2((stama->y)-(sjiki->y),(sjiki->x)-(stama->x))*36/3.141592);
		if(angle<0)angle+=72;
		int i=(angle-stama->angle);
		if(i<0)i+=72;
		if(i>36)
			stama->angle--;
		else
			stama->angle++;
		stama->cnt++;
	}
	if(stama->cnt==100){
		sound.Play (4,stama->x);
		STAMA *stama2;
		stama2=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama2->x=stama->x;stama2->y=stama->y;stama2->z=0;stama2->kind =12;stama2->kyori =0;stama2->s =2;
		stama2=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama2->x=stama->x;stama2->y=stama->y;stama2->z=0;stama2->kind =12;stama2->kyori =0;stama2->s =2;
		task.KillTask();
	}
	if(stama->angle<0)stama->angle=71;
	if(stama->angle>71)stama->angle=0;
	if(stama->dir<0)stama->dir=71;
	if(stama->dir>71)stama->dir=0;
	if(stama->z<0)stama->z=0;

	draw.TDTurnBlt ( 5,stama->x,stama->y,stama->z,1,rc,stama->dir*5,7,7);
	draw.move72 (&stama->x ,&stama->y ,stama->angle,3);
	rimito(stama->x ,stama->y ,stama->z);
	jiki_hantei(stama->x,stama->y,stama->z,stama->w,stama->h );
	stama->dir+=2;
	stama->z-=5;
}
//����
void t_tama12_1(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	RECT rc={34,203,55,225};
	if(stama->s>3.5)task.ChangeTask ("t_tama12",t_tama12_2);
	draw.AlphaBlt ( 5,stama->x,stama->y,0,stama->s,stama->s,2,rc,8,1);
	draw.move72 (&stama->x ,&stama->y ,stama->dir,stama->kyori);
	jiki_hantei2(stama->x,stama->y,stama->z,stama->w,stama->h );
	stama->s +=0.075f;
}
void t_tama12_2(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	RECT rc={34,203,55,225};
	if(stama->s<0)task.KillTask ();
	draw.AlphaBlt ( 5,stama->x,stama->y,0,stama->s,stama->s,2,rc,8,1);
	stama->s -=0.2f;
}
//���[�U�[��
void t_tama13(void){
	//�����̃��[�N�X�y�[�X
	STAMA *stama=(STAMA *)task.workspace ();
	RECT rc={172+14*stama->g_cnt,42,172+14*stama->g_cnt+14,46};
	if(stama->g_cnt >1)stama->g_cnt =0;
	draw.AlphaBltFastCenter ( 5,stama->x,stama->y,2,rc,-7,0);
	rimito(stama->x ,stama->y ,stama->z);
	jiki_hantei2(stama->x,stama->y,stama->z,stama->w,stama->h);
	stama->y +=2;
	stama->g_cnt ++;
}
/////////////////////////////////////////////////////////////////
/////////////////////�U���p�^�[���֐�////////////////////////////
/////////////////////////////////////////////////////////////////
//�p�^�[���P
//�~�T�C���R��
char t_tama_pa1(STEKI *steki,STEKI *steki2){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	switch(steki2->t_cnt){
	case 0:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+steki2->x ;stama->y=steki->y+steki2->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 15:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+steki2->x ;stama->y=steki->y+steki2->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 30:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+steki2->x ;stama->y=steki->y+steki2->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 40:
		steki2->t_cnt =0;
		return 1;
		break;
	}
	steki2->t_cnt ++;
	return 0;
}
//�p�^�[��2
char t_tama_pa2(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	switch(steki->t_cnt){
	case 0:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x;stama->y=steki->y-15 ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x;stama->y=steki->y+15 ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		steki->t_cnt =0;
		return 1;
		break;
	}
	steki->t_cnt ++;
	return 0;
}
char t_tama_pa3(STEKI *steki){
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();

	int i,j,k;
	switch(steki->t_cnt){
	case 0:
		sound.Play(20,steki->x);
		stama=(STAMA *)task.ChildMakeTask("t_tama_init",t_tama_init,0x5301,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->s=1;stama->kind =7;	
		sound.Play(7,steki->x);
		//���@�ւ̌X�������߂�
		//���[�U�[���Y��
		for(i=0,j=steki->x,k=steki->y;i<20;i++){
			stama=(STAMA *)task.ChildMakeTask("t_tama_init",t_tama_init,0x5300,E_SHOT1_TASK);
			stama->dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);	
			if(stama->dir <0)stama->dir +=72;
			stama->x=j;stama->y=k;stama->z=0;stama->angle =stama->dir;stama->kind =6;
			draw.move72 (&j,&k,stama->dir,14);	
		}
		break;
	case 200:
		return 1;
	}
	steki->t_cnt ++;
	return 0;
}
//�p�^�[��2
char t_tama_pa4(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	switch(steki->t_cnt){
	case 2:case 22:case 42:
		sound.Play (8,steki->x);
	case 4:case 6:case 8:case 10:case 24:case 26:case 28:case 30:case 44:case 46:case 48:case 50:
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=steki->z;stama->angle =steki->angle;stama->kind =3;stama->kyori =9;
		draw.move72 (&stama->x,&stama->y,stama->angle,35);
		break;
	case 102:case 122:case 142:
		sound.Play (8,steki->x);
	case 104:case 106:case 108:case 110:case 124:case 126:case 128:case 130:case 144:case 146:case 148:case 150:
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=steki->z;stama->angle =steki->angle;stama->kind =3;stama->kyori =9;
		draw.move72 (&stama->x,&stama->y,stama->angle,35);		
		break;
	case 160:
		return 1;	
	}
	steki->t_cnt ++;
	return 0;
}

//�p�^�[��5
char t_tama_pa5(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);	
	if(dir <0)dir +=72;

	switch(steki->t_cnt){
	case 10:case 20:case 30:case 40:case 50:case 60:case 70:case 80:case 90:case 100:
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=steki->z;stama->angle =dir;stama->kind =1;stama->kyori =4;

		dir+=9;
		if(dir>72)dir-=72;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=steki->z;stama->angle =dir;stama->kind =5;stama->kyori =4;

		dir-=18;
		if(dir<0)dir+=72;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=steki->z;stama->angle =dir;stama->kind =5;stama->kyori =4;
		break;
	}
	if(steki->t_cnt>150){
		steki->t_cnt=0;
		return 1;
	}
	steki->t_cnt ++;
	return 0;
}
//�p�^�[��6
char t_tama_pa6(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;

	switch(steki->t_cnt){
	case 0:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x ;stama->y=steki->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 15:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x ;stama->y=steki->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 40:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x ;stama->y=steki->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	case 55:
		sound.Play (12,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x;stama->y=steki->y ;stama->z=steki->z;stama->angle =54;stama->kind =4;stama->kyori =3;
		break;
	}
	if(steki->t_cnt>90){
		steki->t_cnt=0;
		return 1;
	}
	steki->t_cnt ++;
	return 0;
}
//�{�X�p
//�p�^�[��7
char t_tama_pa7(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	
	if(steki->t_cnt >13){
		steki->t_cnt =0;
		return 1;
	}
	if(steki->kind ==2){
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x+10;stama->y=steki->y+35;stama->z=0;stama->angle =(char)steki->t_cnt*5;stama->kind =2;stama->kyori =3;
	}else{
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x-10;stama->y=steki->y+35;stama->z=0;stama->angle =(char)69-steki->t_cnt*5;stama->kind =2;stama->kyori =3;
	}

	steki->t_cnt ++;
	return 0;
}

char t_tama_pa8(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);	
	if(dir <0)dir +=72;

	switch(steki->t_cnt){
	case 0:case 10:case 20:case 30:case 40:	case 50:case 60:case 70:case 80:case 90:
		sound.Play (9,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-60;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10;stama->y=steki->y-40;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-60 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-40 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		break;
	case 100:
		steki->t_cnt =0;
		return 1;
		break;
	}
	steki->t_cnt ++;
	return 0;
}
char t_tama_pa9(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	switch(steki->t_cnt){
	case 0:
		sound.Play (9,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-60;stama->z=steki->z;stama->angle =0;stama->kind =11;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10;stama->y=steki->y-40;stama->z=steki->z;stama->angle =0;stama->kind =11;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =0;stama->kind =11;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =0;stama->kind =11;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-60 ;stama->z=steki->z;stama->angle =36;stama->kind =11;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-40 ;stama->z=steki->z;stama->angle =36;stama->kind =11;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =36;stama->kind =11;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =36;stama->kind =11;stama->kyori =3;
		break;
	case 30:
		steki->t_cnt =0;
		return 1;
		break;
	}
	steki->t_cnt ++;
	return 0;
}

char t_tama_pa10(STEKI *steki){
	//�����̃��[�N�X�y�[�X
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	switch(steki->t_cnt){
	case 0:case 30:case 60:case 90:case 120:case 150:case 180:case 210:
		sound.Play (9,steki->x);
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-60;stama->z=steki->z;stama->angle =0;stama->kind =4;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x-10;stama->y=steki->y-40;stama->z=steki->z;stama->angle =0;stama->kind =4;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =0;stama->kind =4;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x-10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =0;stama->kind =4;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-60 ;stama->z=steki->z;stama->angle =36;stama->kind =4;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-40 ;stama->z=steki->z;stama->angle =36;stama->kind =4;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-20 ;stama->z=steki->z;stama->angle =36;stama->kind =4;stama->kyori =3;
		
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x+10 ;stama->y=steki->y-0 ;stama->z=steki->z;stama->angle =36;stama->kind =4;stama->kyori =3;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT2_TASK);
		stama->x=steki->x ;stama->y=steki->y+40 ;stama->z=steki->z;stama->angle =36;stama->kind =11;stama->kyori =3;
		break;
	case 250:
		steki->t_cnt =0;
		return 1;
		break;
	}
	steki->t_cnt ++;
	return 0;
}
