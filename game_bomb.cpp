#include"main.h"
#include"game_str.h"
#include"game.h"

extern unsigned long score;
extern unsigned int jikan;
extern unsigned int map_a[400][7];
extern STEKI steki_t[500];

/////////////////////////////////////////////////////////////////
/////////////////////��������֐�////////////////////////////////
/////////////////////////////////////////////////////////////////
//�����C�j�V�����C�Y
void bomb_init(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�����̎�ނɍ��킹�ă`�F���W�^�X�N
	switch(sbomb->kind){
	//������
	case 1:
		task.ChangeTask("bomb1",bomb1);
		break;
	//�唚��
	case 2:
		task.ChangeTask("bomb2",bomb2);
		break;
	//������
	case 3:
		task.ChangeTask("bomb3",bomb3);
		break;
	//�������j��
	case 4:
		task.ChangeTask("bomb4",bomb4);
		break;
	//�������Ռ��g
	case 5:
		task.ChangeTask("bomb5",bomb5);
		break;
	//�������Ռ��g
	case 6:
		task.ChangeTask("bomb6",bomb6);
		break;
	}
}
//�����P
void bomb1(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�J�E���g�ɍ��킹�ăO���t�B�b�N�ύX
	RECT rc={16,0+32*sbomb->cnt,48,0+32*sbomb->cnt+32};
	draw.TDClipBltCenter ( 5,sbomb->x,sbomb->y,sbomb->z,145,120,12,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&sbomb->x ,&sbomb->y ,sbomb->dir,sbomb->speed);
	sbomb->z -=sbomb->z_dir ;
	//���܂ŗ���ƃL��
	z_prio2(sbomb->z);
	if(sbomb->cnt >5)task.KillTask ();
	if(sbomb->cnt2 >1){
		sbomb->cnt2 =0;
		sbomb->cnt ++;
	}
	sbomb->cnt2 ++;
}
//�����Q
void bomb2(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�`��
	RECT rc={48,0+48*sbomb->cnt,96,0+48*sbomb->cnt+48};
	draw.TDClipBltCenter ( 5,sbomb->x,sbomb->y,sbomb->z,145,120,12,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&sbomb->x ,&sbomb->y ,sbomb->dir,sbomb->speed);
	sbomb->z -=sbomb->z_dir ;
	z_prio2(sbomb->z);
	if(sbomb->cnt >8)task.KillTask ();
	if(sbomb->cnt2 >1){
		sbomb->cnt2 =0;
		sbomb->cnt ++;
	}
	sbomb->cnt2 ++;
}
//�����R
void bomb3(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�`��
	RECT rc={0,0+16*sbomb->cnt,16,0+16*sbomb->cnt+16};
	draw.TDClipBltCenter ( 5,sbomb->x,sbomb->y,sbomb->z,145,120,12,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&sbomb->x ,&sbomb->y ,sbomb->dir,sbomb->speed);
	if(sbomb->cnt >7){
		task.KillTask ();	
	}
	if(sbomb->cnt2 >1){
		sbomb->cnt2 =0;
		sbomb->cnt ++;
	}
	sbomb->cnt2 ++;
}
//�����S�i���Ă䂤���j�Ђ��ۂ���j
void bomb4(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�`��
	if(sbomb->cnt >3)sbomb->cnt =0;
	RECT rc={7*sbomb->cnt,195,7*sbomb->cnt+7,202};
	draw.AlphaBltFastCenter(  5,sbomb->x,sbomb->y,2,rc,sbomb->toumei,2);		
	draw.move72 (&sbomb->x ,&sbomb->y ,sbomb->dir,sbomb->speed);
	if(sbomb->toumei >0)task.KillTask();
	if(sbomb->cnt2 >2){
		sbomb->cnt ++;
		sbomb->cnt2 =0;
		sbomb->toumei ++;
	}
	sbomb->cnt2 ++;
}
//�����T�i���Ă䂤���Ռ��g���ۂ���j
void bomb5(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�`��
	RECT rc={0,68,126,192};
	draw.AlphaBlt ( 5,sbomb->x,sbomb->y,sbomb->z,sbomb->sx,sbomb->sy,2,rc,sbomb->toumei,1);		
	if(sbomb->toumei >9)task.KillTask();
	if(sbomb->cnt >0){
		sbomb->cnt =0;
		sbomb->sx +=sbomb->psx;
		sbomb->sy +=sbomb->psy;
		sbomb->toumei ++;
	}
	sbomb->cnt ++;
}
//�����U�i�S�̂𖾂邭�j
void bomb6(void){
	//�����̃��[�N�X�y�[�X
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//�`��
	RECT rc={0,0,280,320};
	draw.Cls (8,0,0,320,320,5);
	draw.AlphaBltFast( 5,0,0,8,rc,sbomb->toumei,2);
	if(sbomb->toumei >0)task.KillTask();
	if(sbomb->cnt >0){
		sbomb->cnt =0;
		sbomb->toumei ++;
	}
	sbomb->cnt ++;
}