#include"main.h"
#include"game_str.h"
#include"game.h"

extern unsigned long score;
extern unsigned int jikan;
extern unsigned int map_a[400][7];
extern STEKI steki_t[500];

/////////////////////////////////////////////////////////////////
/////////////////////爆発操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//爆発イニシャライズ
void bomb_init(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//爆発の種類に合わせてチェンジタスク
	switch(sbomb->kind){
	//中爆発
	case 1:
		task.ChangeTask("bomb1",bomb1);
		break;
	//大爆発
	case 2:
		task.ChangeTask("bomb2",bomb2);
		break;
	//小爆発
	case 3:
		task.ChangeTask("bomb3",bomb3);
		break;
	//半透明破片
	case 4:
		task.ChangeTask("bomb4",bomb4);
		break;
	//半透明衝撃波
	case 5:
		task.ChangeTask("bomb5",bomb5);
		break;
	//半透明衝撃波
	case 6:
		task.ChangeTask("bomb6",bomb6);
		break;
	}
}
//爆発１
void bomb1(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//カウントに合わせてグラフィック変更
	RECT rc={16,0+32*sbomb->cnt,48,0+32*sbomb->cnt+32};
	draw.TDClipBltCenter ( 5,sbomb->x,sbomb->y,sbomb->z,145,120,12,rc,DDBLT_KEYSRC|DDBLT_WAIT);		
	draw.move72 (&sbomb->x ,&sbomb->y ,sbomb->dir,sbomb->speed);
	sbomb->z -=sbomb->z_dir ;
	//一定まで来るとキル
	z_prio2(sbomb->z);
	if(sbomb->cnt >5)task.KillTask ();
	if(sbomb->cnt2 >1){
		sbomb->cnt2 =0;
		sbomb->cnt ++;
	}
	sbomb->cnt2 ++;
}
//爆発２
void bomb2(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//描画
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
//爆発３
void bomb3(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//描画
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
//爆発４（ってゆうか破片っぽいやつ）
void bomb4(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//描画
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
//爆発５（ってゆうか衝撃波っぽいやつ）
void bomb5(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//描画
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
//爆発６（全体を明るく）
void bomb6(void){
	//自分のワークスペース
	SBOMB *sbomb=(SBOMB *)task.workspace ();
	//描画
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