#include"main.h"
#include"game_str.h"
#include"game.h"

extern unsigned long score;
extern unsigned int jikan;
extern unsigned int map_a[400][7];
extern STEKI steki_t[500];

/////////////////////////////////////////////////////////////////
////////////////////敵操作表示関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵総合関数
void teki(void){
	STEKI *steki;
	//敵を出現させる
	for(int i=0;i<350;i++){
		//時間がくれば、フラグを立てる
		if(jikan==steki_t[i].jikan){
			switch(steki_t[i].kind){
			case 1:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki1_1",teki1_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 2:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki2_1",teki2_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 3:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki3_1",teki3_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 4:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki4_1",teki4_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 5:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki5_1",teki5_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 6:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki6_1",teki6_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 7:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki7_1",teki7_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 8:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki8_1",teki8_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 9:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki9_1",teki9_init,0x4000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 10:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki10_1",teki10_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 11:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki11_1",teki11_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 12:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki12_1",teki12_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 13:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki13_1",teki13_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 14:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki14_1",teki14_init,0x4500,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 15:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki15_1",teki15_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 16:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki16_1",teki16_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 17:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki17_1",teki17_init,0x5000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 19:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki19_1",teki19_init,0x4000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			case 20:
				//作成されたタスクのワークスペースが返却される
				steki=(STEKI *)task.MakeTask ("teki20_1",teki20_init,0x4000,NO_TASK);
				//ワークスペースに代入（初期化）
				steki->x=steki_t[i].x;steki->y=steki_t[i].y;steki->z=steki_t[i].z;
				break;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////
////////////////////敵１爆発関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki1_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;

	task.KillTask ();	
	sound.Play(3,steki->x);

	//作成されたタスクのワークスペースが返却される
	sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
	//ワークスペースに代入（初期化）
	sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=6;sbomb->speed=4;sbomb->kind=2;

	//作成されたタスクのワークスペースが返却される
	sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
	//ワークスペースに代入（初期化）
	sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=6;sbomb->speed=3;sbomb->kind=1;
}
/////////////////////////////////////////////////////////////////
////////////////////敵１操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１の行動
void teki1_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->dir =64;
	steki->cnt =0;
	steki->cnt2 =3;
	steki->speed =4;
	steki->gra_cnt =4;
	steki->hp =1;
	SetRect(&steki->rc,0,0,20,30);
	steki->score =200;
	steki->w =20;
	steki->h =30;

	task.ChildMakeTask ("t1_s",teki1_1,0x5000,NO_TASK);
	task.ChangeTask ("t1",teki1);
}
//敵１描画関数
void teki1(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SetRect(&steki->rc,0+20*steki->gra_cnt,0,20+20*steki->gra_cnt,30);
	draw.ClipBltCenter (5,steki->x,steki->y,1,1,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１操作関数
void teki1_1(void){
	STEKI *steki=(STEKI *)task.p_work_add();
	SJIKI *sjiki=(SJIKI *)ji();
	if(sjiki->x-50 < steki->x){
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =5;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =6;

		steki->dir =51;
		task.ChangeTask ("teki1_2",teki1_2);
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki1_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->cnt >3){
		steki->cnt=0;
		//グラフィックの変更
		steki->gra_cnt --;
		if(steki->gra_cnt <0)steki->gra_cnt =0;	
		//角度の変更
		if(steki->cnt2<0)steki->cnt2 =0;
		steki->dir-=steki->cnt2;
		steki->cnt2--;
		//スピードの変更
		steki->speed ++;
	}
	steki->cnt++;
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵２操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
//敵２の行動
void teki2_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->dir =45;
	steki->cnt =0;
	steki->cnt2 =3;
	steki->speed =3;
	steki->gra_cnt =0;
	steki->hp =1;
	SetRect(&steki->rc,0,0,20,30);
	steki->score =200;
	steki->w =20;
	steki->h =30;
	task.ChildMakeTask ("t2_s",teki2_1,0x5000,NO_TASK);
	task.ChangeTask ("t2",teki2);
}
//敵２描画関数
void teki2(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SetRect(&steki->rc,0+20*steki->gra_cnt,0,20+20*steki->gra_cnt,30);
	draw.ClipBltCenter (5,steki->x,steki->y,1,1,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵２操作関数
void teki2_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	SJIKI *sjiki=(SJIKI *)ji();
	if(sjiki->x+50 > steki->x){

		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =5;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =6;

		steki->dir =60;
		task.ChangeTask ("teki2_2",teki2_2);
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki2_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->cnt >3){
		steki->cnt=0;
		//グラフィックの変更		
		steki->gra_cnt ++;
		if(steki->gra_cnt >4)steki->gra_cnt =4;
		//角度の変更		
		if(steki->cnt2<0)steki->cnt2 =0;
		steki->dir+=steki->cnt2;
		steki->cnt2--;
		//スピードの変更
		steki->speed ++;
	}
	steki->cnt++;
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵３爆発関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki3_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;
	int kakudo,i;
	switch(steki->z){
	case 0:case 20:case 40:case 60:
		sound.Play(3,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=6;sbomb->speed=3;sbomb->kind=1;
		kakudo=randamize(10,60);
		break;
	case 80:
		sound.Play(1,steki->x);
		sound.Play(4,steki->x);
		kakudo=randamize(10,60);
		for(i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=15;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
		}
	}
	if(steki->z>80)task.KillTask ();
	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->z+=2;
	z_prio(steki->z);
}
/////////////////////////////////////////////////////////////////
////////////////////敵３操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
//敵３の行動
//敵３のイニシャライズ
void teki3_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->t_cnt =0;
	steki->dir =54;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =3;
	steki->gra_cnt =0;
	steki->hp =20;
	steki->change =0;
	SetRect(&steki->rc,0,30,42,81);
	steki->score =4000;
	steki->w =42;
	steki->h =51;

	//両側の機械
	task.ChildMakeTask ("teki3_c",teki3_c_1_init,0x5300,NO_TASK);
	task.ChildMakeTask ("teki3_c",teki3_c_2_init,0x5300,NO_TASK);

	task.ChildMakeTask ("t3_s",teki3_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki3",teki3);
}
//敵３描画
void teki3(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki3_baku);
	}//描画
	draw.ClipBltCenter (5,steki->x,steki->y,1,1,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
}
void teki3_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//子の位置に着たならば
	if(steki->y>50){
		//子供に知らせるためのフラグ
		steki->change =1;
		steki->speed =0;
		//次へチェンジ
		task.ChangeTask ("teki3",teki3_2);
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki3_2(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add  ();
	if(steki->change ==2){
		if(steki->cnt2>2){
			steki->cnt2 =0;
			steki->speed ++;
		}
		steki->cnt2 ++;
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
////////////////////敵３の子供１//////////////////////
void teki3_c_1_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	steki->x =-16;
	steki->y = 15;
	steki->z =stekip->z ;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->gra_cnt =0;
	SetRect(&steki->rc,84,30,116,61);
	steki->w =32;
	steki->h =31;
	steki->t_cnt =0;

	task.ChildMakeTask ("teki3_c",teki3_c_1,0x5300,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki3_c",teki3_c);
}
void teki3_c_2_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	steki->x =16 ;
	steki->y =15 ;
	steki->z =stekip->z ;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->gra_cnt =0;
	SetRect(&steki->rc,84,30,115,61);
	steki->w =32;
	steki->h =31;
	steki->t_cnt =0;

	task.ChildMakeTask ("teki3_c",teki3_c_1,0x5300,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki3_c",teki3_c);
}

//敵３の子供描画関数
void teki3_c(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	if(steki->gra_cnt <0)steki->gra_cnt =0;
	if(steki->gra_cnt >3)steki->gra_cnt =3;
	//描画	
	steki->z=stekip->z;
	SetRect(&steki->rc,84+32*steki->gra_cnt,30,84+32*steki->gra_cnt+32,61);
	draw.TDClipBltCenter ( 5,stekip->x+steki->x ,stekip->y+steki->y+steki->cnt,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
}
//敵３の子供操作関数
void teki3_c_1(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(stekip->change ==1)task.ChangeTask ("teki3_c",teki3_c_2);
}
void teki3_c_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(steki->cnt >14){
		steki->cnt =14;
		task.ChangeTask ("teki3_c",teki3_c_3);
		return;
	}
	steki->cnt++;
}
void teki3_c_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(steki->gra_cnt >=3){
		steki->gra_cnt =3;	
		task.ChangeTask ("teki3_c",teki3_c_4);
		return;
	}
	steki->gra_cnt ++;
}
void teki3_c_4(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	
	//次へチェンジ
	
	if(t_tama_pa1(stekip,steki))task.ChangeTask ("teki3_c",teki3_c_5);
}
void teki3_c_5(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(steki->gra_cnt <=0){
		steki->gra_cnt =0;
		task.ChangeTask ("teki3_c",teki3_c_6);
		return;
	}
	steki->gra_cnt --;
}
void teki3_c_6(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(steki->cnt <0){
		steki->cnt =0;
		stekip->change =2;
		return;
	}
	steki->cnt--;
}
/////////////////////////////////////////////////////////////////
////////////////////敵４操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki4_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	SJIKI *sjiki=(SJIKI *)ji();
	steki->dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->dir <0)steki->dir +=72;

	steki->cnt =0;
	steki->speed =4;
	steki->gra_cnt =0;
	steki->hp =1;
	steki->change =0;
	SetRect(&steki->rc,110,0,132,30);
	steki->score =200;
	steki->w =22;
	steki->h =30;

	task.ChildMakeTask ("t4_s",teki4_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki4",teki4);
}
//敵４描画関数
void teki4(void){
	STEKI *steki=(STEKI *)task.workspace ();
	if(steki->gra_cnt >3)steki->gra_cnt =0;
	//描画
	SetRect(&steki->rc,110+steki->gra_cnt*22,0,110+steki->gra_cnt*22+22,30);
	draw.TurnBltFastCenter( 5,steki->x,steki->y,11,steki->rc,steki->dir*5,11,10);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵４操作関数
void teki4_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt =0;
		steki->gra_cnt++ ;
	}
	steki->cnt ++;
}
/////////////////////////////////////////////////////////////////
////////////////////敵５６爆発関数///////////////////////////////
/////////////////////////////////////////////////////////////////
void teki56_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;
	int kakudo,i;
	switch(steki->cnt){
	case 0:case 20:case 40:case 60:
		sound.Play(3,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=6;sbomb->speed=3;sbomb->kind=1;
		kakudo=randamize(10,60);
		break;
	case 80:
		sound.Play(1,steki->x);
		sound.Play(4,steki->x);
		kakudo=randamize(10,60);
		for(i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=randamize(36,72);sbomb->z_dir=15;sbomb->speed=randamize(1,4);sbomb->kind=2;

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
		}
	}
	if(steki->cnt>80)task.KillTask ();
	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->z-=4;
	steki->cnt+=2;
}
/////////////////////////////////////////////////////////////////
////////////////////敵５操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki5_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->t_cnt =0;
	steki->cnt =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =1;
	steki->change =0;
	SetRect(&steki->rc,274,0,297,37);
	steki->score =1200;
	steki->w =23;
	steki->h =37;

	task.ChildMakeTask ("t4_s",teki5_1,0x5000,NO_TASK);
	//本体
	task.ChangeTask ("teki4",teki5);
}
//敵５描画関数
void teki5(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;	
		task.ChangeTask ("baku",teki56_baku);
	}
}
//敵５操作関数
void teki5_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(steki->z>100)task.ChangeTask ("t5",teki5_2);
	steki->z +=2;
}
void teki5_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(steki->z<=0)task.ChangeTask ("t5",teki5_3);
	steki->z -=2;
}
void teki5_3(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(t_tama_pa2(steki))task.ChangeTask ("t5",teki5_4);
}
void teki5_4(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	if(steki->hp <0)task.KillTask ();
	if(steki->z>240)task.KillTask();
	steki->z+=2;
}
/////////////////////////////////////////////////////////////////
////////////////////敵６操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki6_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->t_cnt =0;
	steki->cnt =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =1;
	steki->change =0;
	SetRect(&steki->rc,297,0,320,37);
	steki->score =1200;
	steki->w =23;
	steki->h =37;

	task.ChildMakeTask ("t6_s",teki6_1,0x5000,NO_TASK);
	//本体
	task.ChangeTask ("teki6",teki6);
}
//敵６描画関数
void teki6(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki56_baku);
	}
}
//敵６操作関数
void teki6_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(steki->z>100)task.ChangeTask ("t6",teki6_2);
	steki->z +=2;
}
void teki6_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(steki->z<=0)task.ChangeTask ("t6",teki6_3);
	steki->z -=2;
}
void teki6_3(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	steki->y+=randamize(-2,2);
	if(steki->hp <0)task.KillTask ();
	if(t_tama_pa2(steki))task.ChangeTask ("t6",teki6_4);
}
void teki6_4(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	if(steki->hp <0)task.KillTask ();
	steki->z+=2;
}

/////////////////////////////////////////////////////////////////
////////////////////敵７操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki7_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->dir =0;
	steki->cnt =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =1;
	steki->change =0;
	SetRect(&steki->rc,0,0,34,34);
	steki->score =1200;
	steki->w =34;
	steki->h =34;

	task.ChildMakeTask ("t7_s",teki7_1,0x5000,NO_TASK);
	//本体
	task.ChangeTask ("teki7",teki7);
}
//敵７描画関数
void teki7(void){
	STEKI *steki=(STEKI *)task.workspace ();

	//描画
	if(steki->dir>=72)steki->dir =0;
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}

	draw.TDTurnBlt( 5,steki->x,steki->y,steki->z,11,steki->rc,steki->dir*5,17,17);
	steki->dir +=2;
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	z_prio(steki->z);
}
//敵７操作関数
void teki7_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	SJIKI *sjiki=(SJIKI *)ji();
	//移動
	if(steki->hp <0)task.KillTask ();
	if((steki->z<3)&&(steki->z>-3)){
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =4;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =5;
	}
	steki->z +=4;
}
/////////////////////////////////////////////////////////////////
////////////////////敵８操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki8_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->dir =0;
	steki->cnt =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =60;
	steki->change =0;
	SetRect(&steki->rc,220,0,268,48);
	steki->score =1200;
	steki->w =48;
	steki->h =48;

	task.ChildMakeTask ("t8_s",teki8_c_init,0x5100,NO_TASK);

	task.ChildMakeTask ("t8_s",teki8_1,0x5100,NO_TASK);
	//本体
	task.ChangeTask ("teki8",teki8);
}
//敵８描画関数
void teki8(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	if(steki->dir>=72)steki->dir =0;
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki3_baku);
	}
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
}
//敵８操作関数
void teki8_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	if(steki->y>40){
		steki->speed =0;
		steki->change =1;
		task.ChangeTask("t_8",teki8_2);
	}
	draw.move72 (&steki->x,&steki->y,54,steki->speed);
}
void teki8_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->change ==2){
		if(steki->cnt>0){
			steki->cnt =0;
			steki->speed ++;
			steki->z+=6;
		}
		steki->cnt ++;
	}
	draw.move72 (&steki->x,&steki->y,54,steki->speed);
}
//敵８の子供
void teki8_c_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	steki->dir=54;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->change =0;
	SetRect(&steki->rc,40,0,96,57);
	steki->w =21;
	steki->h =57;

	task.ChildMakeTask ("teki8_c",teki8_c_1,0x5100,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki8_c",teki8_c);
}

void teki8_c(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画
	steki->x=stekip->x;
	steki->y=stekip->y;
	steki->z=stekip->z;
	draw.TDTurnBlt ( 5,steki->x-1,steki->y,steki->z,11,steki->rc,steki->dir*5,29,29);
}
//敵３の子供操作関数
void teki8_c_1(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(stekip->change ==1)task.ChangeTask ("teki8_c",teki8_c_2);
}
void teki8_c_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	int kakudo;
	//砲台？を自機に向ける
	//自機を探す
	SJIKI *sjiki=(SJIKI *)ji();
	kakudo =(int)(atan2((stekip->y)-(sjiki->y),(sjiki->x)-(stekip->x))*36/3.141592);
	if(kakudo <0)kakudo +=72;
	if(kakudo<steki->dir)steki->dir --;
	if(kakudo>steki->dir)steki->dir ++;
	if(stekip->hp <0)task.KillTask();

	if(kakudo==steki->dir){
		task.ChangeTask ("teki8_c",teki8_c_3);
		return;
	}	  
}
void teki8_c_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	steki->x=stekip->x;
	steki->y=stekip->y;
	//次へチェンジ
	if(t_tama_pa3(steki)){
		if(steki->change ==1){
			task.ChangeTask ("teki8_c",teki8_c_4);
			return;
		}
		task.ChangeTask ("teki8_c",teki8_c_2);
		steki->change =1;
		steki->t_cnt =0;
		return;
	}
	steki->gra_cnt ++;
}
void teki8_c_4(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	stekip->change =2;
	if(stekip->hp <0)task.KillTask();
}
/////////////////////////////////////////////////////////////////
////////////////////敵９操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki9_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->cnt =0;
	steki->speed =4;
	steki->gra_cnt =0;
	steki->hp =1;
	steki->change =0;
	SetRect(&steki->rc,103,0,131,29);
	steki->score =200;
	steki->dir = 18;
	steki->w =25;
	steki->h =25;

	task.ChildMakeTask ("t9_s",teki9_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki9",teki9);
}
//敵９描画関数
void teki9(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	SetRect(&steki->rc,103,0,131,29);
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵９操作関数
void teki9_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵１０操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki10_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =randamize(6,8);
	steki->gra_cnt =0;
	steki->hp =10;
	steki->change =0;
	SetRect(&steki->rc,134,1,166,29);
	steki->score =200;
	steki->dir = randamize(31,51);
	steki->w =25;
	steki->h =25;

	task.ChildMakeTask ("t10_s",teki10_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki10",teki10);
}
//敵１０描画関数
void teki10(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	SetRect(&steki->rc,134,1,166,29);
	draw.ClipBltCenter( 5,steki->x,steki->y,1,1,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１０操作関数
void teki10_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	if(steki->speed <0)task.ChangeTask ("teki10",teki10_2);
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt=0;
		steki->speed --;
	}
	steki->cnt++;
}
void teki10_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	steki->speed =randamize(6,8);
	steki->dir = randamize(26,46);
	task.ChangeTask ("teki10",teki10_3);
}
void teki10_3(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	SJIKI *sjiki=(SJIKI *)ji();
	if(steki->cnt2 >20){
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =4;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =5;

		steki->cnt2 =0;
		task.ChangeTask ("teki10",teki10_1);
	}
	steki->cnt2 ++;
}
/////////////////////////////////////////////////////////////////
////////////////////敵１１操作関数/////////////////////////////////
/////////////////////////////////////////////////////////////////
void teki11_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =randamize(6,8);
	steki->gra_cnt =0;
	steki->hp =10;
	steki->change =0;
	SetRect(&steki->rc,134,1,166,29);
	steki->score =200;

	int i=randamize(1,2);
	if(i=1){
		steki->dir = randamize(0,10);
	}else{
		steki->dir = randamize(61,71);
	}

	steki->w =25;
	steki->h =25;

	task.ChildMakeTask ("t11_s",teki11_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki11",teki11);
}
//敵１１描画関数
void teki11(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	SetRect(&steki->rc,134,1,166,29);
	draw.ClipBltCenter( 5,steki->x,steki->y,1,1,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１１操作関数
void teki11_1(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//移動
	if(steki->speed <0)task.ChangeTask ("teki11",teki11_2);
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt=0;
		steki->speed --;
	}
	steki->cnt++;
}
void teki11_2(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	steki->speed =randamize(6,8);
	int i=randamize(1,2);
	if(i=1){
		steki->dir = randamize(0,10);
	}else{
		steki->dir = randamize(61,71);
	}
	
	task.ChangeTask ("teki11",teki11_3);
}
void teki11_3(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	SJIKI *sjiki=(SJIKI *)ji();
	if(steki->cnt2 >20){
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =4;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =3;stama->kyori =5;

		steki->cnt2 =0;
		task.ChangeTask ("teki11",teki11_1);
	}
	steki->cnt2 ++;
}
/////////////////////////////////////////////////////////////////
////////////////////敵１２操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１２初期化
void teki12_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =3;
	steki->change =0;
	SetRect(&steki->rc,2,31,34,63);
	steki->score =200;
	steki->dir =54;
	steki->angle =54;

	steki->w =20;
	steki->h =20;

	task.ChildMakeTask ("t12_s",teki12_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki12",teki12);
}
//敵１２描画関数
void teki12(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDTurnBlt( 5,steki->x,steki->y,steki->z,11,steki->rc,steki->angle*5,16,16);
	//リミットチェック
	z_prio(steki->z);
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１２操作関数
void teki12_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//一定の位置に来ると
	if(steki->y >40)task.ChangeTask ("teki12",teki12_2);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki12_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照
	SJIKI *sjiki=(SJIKI *)ji();
	//自分から自機への角度を求める
	steki->angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;
	//自機と同高度の時
	if(steki->z<0){
		steki->z=0;
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =5;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =6;
		task.ChangeTask ("teki12",teki12_3);
		return;
	}
	//高度を上げる
	steki->z-=2;
}
void teki12_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照	
	SJIKI *sjiki=(SJIKI *)ji();
	//自分と自機との反対の向きを求める
	char angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(angle<0)angle +=72;
	angle-=31;
	if(angle <0)angle +=72;
	//角度の少ない方向から向かせる
	char i=(angle-steki->angle );
	if(i<0)i+=72;
	if(i>36){
		steki->dir --;
		steki->angle --;
	}else{
		steki->dir ++;
		steki->angle++;
	}
	//リミットチェック
	if(steki->angle<0)steki->angle=71;
	if(steki->angle>71)steki->angle=0;
	if(steki->dir<0)steki->dir=71;
	if(steki->dir>71)steki->dir=0;

	//スピードを少しづつ上げる
	if(steki->cnt >3){
		steki->cnt =0;
		steki->speed ++;
	}
	steki->cnt ++;
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵１３操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１３初期化
void teki13_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;
	//敵の初期化
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =2;
	steki->gra_cnt =0;
	steki->hp =3;
	steki->change =0;
	SetRect(&steki->rc,2,31,34,63);
	steki->score =200;
	steki->dir =18;
	steki->angle =18;
	steki->w =20;
	steki->h =20;
	//移動用の子供を産む
	task.ChildMakeTask ("t13_s",teki13_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki13",teki13);
}
//敵１３描画関数
void teki13(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDTurnBlt( 5,steki->x,steki->y,steki->z,11,steki->rc,steki->angle*5,16,16);
	//リミットチェック
	z_prio(steki->z);
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１３操作関数
void teki13_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//一定の位置に来ると
	if(steki->y <200)task.ChangeTask ("teki13",teki13_2);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki13_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照
	SJIKI *sjiki=(SJIKI *)ji();
	//自分から自機への角度を求める
	steki->angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;
	//自機と同高度の時
	if(steki->z<0){
		steki->z=0;
		int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
		if(dir <0)dir +=72;

		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =5;

		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->angle =dir;stama->kind =1;stama->kyori =6;
		task.ChangeTask ("teki13",teki13_3);
		return;
	}
	//高度を上げる
	steki->z-=2;
}
void teki13_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照	
	SJIKI *sjiki=(SJIKI *)ji();
	//自分と自機との反対の向きを求める
	char angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(angle<0)angle +=72;
	angle-=31;
	if(angle <0)angle +=72;
	//角度の少ない方向から向かせる
	char i=(angle-steki->angle );
	if(i<0)i+=72;
	if(i>36){
		steki->dir --;
		steki->angle --;
	}else{
		steki->dir ++;
		steki->angle++;
	}
	//リミットチェック
	if(steki->angle<0)steki->angle=71;
	if(steki->angle>71)steki->angle=0;
	if(steki->dir<0)steki->dir=71;
	if(steki->dir>71)steki->dir=0;
	//スピードを少しづつ上げる
	if(steki->cnt >3){
		steki->cnt =0;
		steki->speed ++;
	}
	steki->cnt ++;
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵１４操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１４初期化
void teki14_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;
	//敵の初期化
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =3;
	steki->gra_cnt =0;
	steki->hp =5;
	steki->change =0;
	SetRect(&steki->rc,197,0,218,21);
	steki->score =200;
	steki->dir =54;
	steki->angle =18;
	steki->w =20;
	steki->h =20;
	//移動用の子供を産む
	task.ChildMakeTask ("t14_s",teki14_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki14",teki14);
}
//敵１４描画関数
void teki14(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	RECT rc={172,3,197,26};
	draw.ClipBltCenter ( 5,steki->x,steki->y,1,1,10,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	draw.TurnBltFastCenter ( 5,steki->x,steki->y,11,steki->rc,steki->angle*5,11,11);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１４操作関数
void teki14_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照
	SJIKI *sjiki=(SJIKI *)ji();

	//自分から自機への角度を求める
	steki->angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;

	//一定の位置に来ると
	if(steki->y >40)task.ChangeTask ("teki14",teki14_2);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki14_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照
	SJIKI *sjiki=(SJIKI *)ji();

	//自分から自機への角度を求める
	steki->angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;

	if(steki->cnt >7){
		steki->cnt =0;
		sound.Play(9,steki->x);
		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=50;stama->angle =steki->angle;stama->kind =3;stama->kyori =3;
	}
	steki->cnt++;
	if(steki->y>210){
		task.ChangeTask ("teki14",teki14_3);
		return;
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki14_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照	
	SJIKI *sjiki=(SJIKI *)ji();
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
/////////////////////////////////////////////////////////////////
////////////////////敵１５操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１５初期化
void teki15_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;
	//敵の初期化
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =10;
	steki->hp =2;
	steki->change =0;
	SetRect(&steki->rc,218,0,248,32);
	steki->score =200;

	steki->angle =(int)(atan2((steki->y)-120,140-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;

	steki->dir =steki->angle;
	steki->w =25;
	steki->h =25;
	//移動用の子供を産む
	task.ChildMakeTask ("t15_s",teki15_1,0x5300,NO_TASK);
	//本体
	task.ChangeTask ("teki15",teki15);
}
//敵１５描画関数
void teki15(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TurnBltFastCenter ( 5,steki->x,steki->y,11,steki->rc,steki->angle*5,15,16);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki1_baku);
	}
}
//敵１５操作関数
void teki15_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//一定の位置に来ると
	if(steki->y>90){
		steki->speed =5;
		steki->angle_temp =72-steki->dir; 
		task.ChangeTask ("teki15",teki15_2);
	}
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki15_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//自機を参照
	SJIKI *sjiki=(SJIKI *)ji();
	if(steki->angle <steki->angle_temp)steki->angle =steki->angle_temp ;	
	if(steki->dir <steki->angle_temp)steki->dir =steki->angle_temp ;
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);

	int i;
	//角度計算
	i=(steki->angle_temp-steki->angle);
	if(i<0)i+=72;
	if(i>36)
		steki->angle-=2;
	else
		steki->angle+=2;
	if(steki->angle<0)steki->angle=71;
	if(steki->angle>71)steki->angle=0;
	//アングル計算
	i=(steki->angle_temp-steki->dir);
	if(i<0)i+=72;
	if(i>36)
		steki->dir--;
	else
		steki->dir++;
	if(steki->dir<0)steki->dir=71;
	if(steki->dir>71)steki->dir=0;	
}
/////////////////////////////////////////////////////////////////
////////////////////敵１６爆発関数///////////////////////////////
/////////////////////////////////////////////////////////////////
void teki16_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;
	int i,kakudo;
	sound.Play(4,steki->x);
	kakudo=randamize(20,40);
	for(i=0;i<20;i++){
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+randamize(-50,50);sbomb->y=steki->y+randamize(-50,50);sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=10;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+randamize(-50,50);sbomb->y=steki->y+randamize(-50,50);sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=2;sbomb->speed=11-i;sbomb->kind=3;
	}
	for(i=0;i<10;i++){
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x-50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
	}
	task.KillTask ();
}
/////////////////////////////////////////////////////////////////
////////////////////敵１６操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//敵１６の行動
//敵１６のイニシャライズ
void teki16_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->t_cnt =0;
	steki->dir =27;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =5;
	steki->gra_cnt =0;
	steki->hp =50;
	steki->change =0;
	SetRect(&steki->rc,166,62,236,155);
	steki->score =4000;
	steki->w =60;
	steki->h =60;

	//両側の機械
	task.ChildMakeTask ("teki16_c",teki16_c_1_init,0x5100,NO_TASK);
	task.ChildMakeTask ("teki16_c",teki16_c_2_init,0x5100,NO_TASK);

	task.ChildMakeTask ("t16_s",teki16_1,0x5100,NO_TASK);
	//本体
	task.ChangeTask ("teki16",teki16);
}
//敵１７のイニシャライズ
void teki17_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->t_cnt =0;
	steki->dir =9;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =5;
	steki->gra_cnt =0;
	steki->hp =70;
	steki->change =0;
	SetRect(&steki->rc,166,62,236,155);
	steki->score =4000;
	steki->w =60;
	steki->h =60;

	//両側の機械
	task.ChildMakeTask ("teki16_c",teki16_c_1_init,0x5100,NO_TASK);
	task.ChildMakeTask ("teki16_c",teki16_c_2_init,0x5100,NO_TASK);

	task.ChildMakeTask ("t16_s",teki16_1,0x5100,NO_TASK);
	//本体
	task.ChangeTask ("teki16",teki16);
}
//敵１６描画
void teki16(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki16_baku);
	}//描画
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	rimito(steki->x ,steki->y ,steki->z);
}
void teki16_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//子の位置に着たならば
	if(steki->z<0){
		//子供に知らせるためのフラグ
		steki->z=0;
		steki->change =1;
		steki->speed =0;
		//次へチェンジ
		task.ChangeTask ("teki16",teki16_2);
		return;
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	steki->z--;
}
void teki16_2(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add  ();
	if(steki->change ==2){
		if(steki->cnt2>2){
			steki->cnt2 =0;
			steki->speed ++;
		}
		steki->cnt2 ++;
	}
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
////////////////////敵１６の子供１//////////////////////
void teki16_c_1_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	steki->px =-31;
	steki->py = -15;
	steki->z =stekip->z ;
	steki->angle =54;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->gra_cnt =0;
	SetRect(&steki->rc,149,112,167,160);
	steki->w =16;
	steki->h =30;
	steki->t_cnt =0;

	task.ChildMakeTask ("teki16_c",teki16_c_1,0x5100,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki16_c",teki16_c);
}
void teki16_c_2_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	steki->px =31 ;
	steki->py =-15 ;
	steki->z =stekip->z ;
	steki->angle =54;
	steki->cnt =0;
	steki->cnt2 =0;
	steki->gra_cnt =1;
	SetRect(&steki->rc,149,63,167,111);
	steki->w =16;
	steki->h =30;
	steki->t_cnt =0;

	task.ChildMakeTask ("teki16_c",teki16_c_1,0x5100,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki16_c",teki16_c);
}

//敵１６の子供描画関数
void teki16_c(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画	
	steki->z=stekip->z;

	RECT rc;
	if(stekip->change ==1)task.ChangeTask ("teki16",teki16_c2);
	if(steki->gra_cnt ==0){
		SetRect(&rc,80,139,97,187);
		draw.TDClipBltCenter ( 5,steki->x-steki->cnt,steki->y,steki->z,145,120,10,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	}else{
		SetRect(&rc,80,188,97,236);
		draw.TDClipBltCenter ( 5,steki->x+steki->cnt,steki->y,steki->z,145,120,10,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	}
}
void teki16_c2(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//親のワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画	
	steki->z=stekip->z;
	if(steki->gra_cnt ==0)
		draw.TurnBltFastCenter ( 5,steki->x-steki->cnt,steki->y,10,steki->rc,steki->angle*5 ,8,24);
	else
		draw.TurnBltFastCenter ( 5,steki->x+steki->cnt,steki->y,10,steki->rc,steki->angle*5 ,8,24);
}
//敵１６の子供操作関数
void teki16_c_1(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();

	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;

	if(stekip->hp <0)task.KillTask();
	if(stekip->change ==1)task.ChangeTask ("teki16_c",teki16_c_2);
}
void teki16_c_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();
	if(steki->cnt >7){
		task.ChangeTask ("teki16_c",teki16_c_3);
		return;
	}
	steki->cnt++;
}
void teki16_c_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	SJIKI *sjiki=(SJIKI *)ji();
	steki->angle =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);
	if(steki->angle <0)steki->angle +=72;

	if(steki->angle>63)steki->angle=63;
	if(steki->angle<45)steki->angle=45;

	if(t_tama_pa4(steki))task.ChangeTask ("teki16_c",teki16_c_4);

	if(stekip->hp <0)task.KillTask();
}
void teki16_c_4(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();

	if(steki->angle >54)steki->angle --;
	if(steki->angle <54)steki->angle ++;

	if(steki->cnt<0)steki->cnt=0;

	if((steki->cnt==0)){
		sound.Play(11,stekip->x);
		stekip->dir=54;
		stekip->speed=0;
		stekip->change=2;
		task.ChangeTask ("teki16_c",teki16_c_5);
	
	}
	steki->cnt--;
}
void teki16_c_5(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(stekip->hp <0)task.KillTask();

	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;
}
/////////////////////////////////////////////////////////////////
////////////////////敵１９爆発関数///////////////////////////////
/////////////////////////////////////////////////////////////////
void teki19_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;
	int kakudo,i;
	switch(steki->baku_cnt){
	case 10:case 20:case 40:case 50:case 70:case 80:
		sound.Play(3,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=10;sbomb->speed=10;sbomb->kind=1;
		break;
	case 30:case 60:case 90:
		sound.Play(4,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=10;sbomb->speed=10;sbomb->kind=2;
		break;
	case 100:
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
		sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0;sbomb->psy=0.25f;

		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
		sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.25f;sbomb->psy=0;
		break;
	case 110:
		sound.Play(4,steki->x);
		sound.Play(5,steki->x);
		kakudo=randamize(36,71);

		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
		sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.2f;sbomb->psy=0.2f;
	
		for(i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=40;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x+50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x-50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
		}

		audio.Play (6,MM_CD_LOOPING);
		jikan=5000;
		break;
	}
	if(steki->baku_cnt >110)task.KillTask ();
	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->baku_cnt +=2;
	steki->z++;
}
/////////////////////////////////////////////////////////////////
////////////////////敵１９操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////中ボス操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//初期化
void teki19_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;
	//敵の初期化
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =11;
	steki->gra_cnt =0;
	steki->t_cnt =0;
	steki->hp =80;
	steki->baku_cnt =0;
	steki->change =0;
	SetRect(&steki->rc,88,68,137,136);
	steki->score =10000;
	steki->dir =0;
	steki->angle =54;
	steki->w =40;
	steki->h =55;

	task.ChildMakeTask ("t19_s",teki19_c1_init,0x4011,NO_TASK);
	task.ChildMakeTask ("t19_s",teki19_c2_init,0x4011,NO_TASK);

	//移動用の子供を産む
	task.ChildMakeTask ("t19_s",teki19_1,0x4000,NO_TASK);
	//本体
	task.ChangeTask ("teki19",teki19);
}
//描画関数
void teki19(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		score+=steki->score ;
		task.ChangeTask ("baku",teki19_baku);
		return;
	}
	if((steki->x<-20)||(steki->x>300))sound.Play (3,steki->x);
	if(steki->z<-500){
		audio.Play (6,MM_CD_LOOPING);
		jikan=5000;
		task.KillTask ();
		return;
	}
}
//操作関数
void teki19_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//一定に来ると
	if(steki->speed <0){
		steki->change =1;
		steki->speed =0;
		task.ChangeTask ("teki19_c",teki19_2);
		return;
	}
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt=0;
		steki->speed --;
	}
	steki->cnt ++;
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		task.ChangeTask ("teki19_c",teki19_10);
		return;
	}
}
void teki19_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->change ==2){
		steki->speed =-5;
		task.ChangeTask ("teki19_c",teki19_3);
		return;
	}
	if(steki->cnt>2){
		steki->cnt=0;
		steki->x++;
	}
	steki->cnt ++;	
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
}
void teki19_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->x>400){
		steki->speed =0;
		task.ChangeTask ("teki19_c",teki19_4);
		return;
	}
	if(steki->cnt>1){
		steki->cnt=0;
		steki->speed++;
	}
	steki->cnt ++;	
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
}
void teki19_4(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->z>100){
		steki->dir =36;
		steki->speed =13;
		task.ChangeTask ("teki19_c",teki19_5);
		return;
	}
	steki->z +=2;
}
void teki19_5(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->speed <0){
		steki->change =3;
		steki->speed =0;
		task.ChangeTask ("teki19_c",teki19_6);
		return;
	}
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt=0;
		steki->speed --;
	}
	steki->cnt ++;	
}
void teki19_6(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->change ==4){
		if(steki->cnt2 ==1){
			task.ChangeTask ("teki19_c",teki19_9);
			return;
		}
		task.ChangeTask ("teki19_c",teki19_7);
		return;
	}
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>2){
		steki->cnt=0;
		steki->x--;
	}
	steki->cnt ++;	
}
void teki19_7(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->x<-120){
		steki->speed =0;
		task.ChangeTask ("teki19_c",teki19_8);
		return;
	}
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	if(steki->cnt>1){
		steki->cnt=0;
		steki->speed++;
	}
	steki->cnt ++;	
}
void teki19_8(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//ｚ軸を自機と同じへ
	if(steki->z<0){
		steki->speed =11;
		steki->change =0;
		steki->x =-60;
		steki->dir =0;
		steki->cnt2 =1;
		steki->z=0;
		task.ChangeTask ("teki19_c",teki19_1);
		return;
	}
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	//移動
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	steki->z-=2;	
}
void teki19_9(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//一定を超えるとキル（中ボスなので時間等等変更）
	//移動
	if(steki->hp <0)task.ChangeTask ("teki19_c",teki19_10);
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	steki->z-=5;
	steki->y-=1;
}
void teki19_10(void){
}
/////////敵１９の子供////////////
void teki19_c1_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->px =-25;
	steki->py =50;
	steki->hp =80;
	steki->z =stekip->z ;
	steki->t_cnt =0;
	steki->cnt =0;
	steki->cnt2 =0;
	SetRect(&steki->rc,0,82,35,148);
	steki->w =25;
	steki->h =55;

	task.ChildMakeTask ("teki19_c",teki19_c_1,0x4101,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki19_c",teki19_c);
}
void teki19_c2_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();

	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->px =25;
	steki->py =50;
	steki->hp =80;
	steki->z =stekip->z ;
	steki->t_cnt =0;
	steki->cnt =0;
	steki->cnt2 =0;
	SetRect(&steki->rc,36,82,71,148);
	steki->w =25;
	steki->h =55;

	task.ChildMakeTask ("teki19_c",teki19_c_1,0x4101,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki19_c",teki19_c);
}

void teki19_c(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画
	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);

	if(steki->hp <0){	
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		steki->rc.top +=66;
		steki->rc.bottom +=66;

		SBOMB *sbomb;
		sound.Play(1,steki->x);
		sound.Play(4,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5100,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
		sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.25f;sbomb->psy=0;

		int kakudo=randamize(36,71);
		for(int i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5100,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=15;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5100,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
		}
		task.ChangeTask ("teki19_c",teki19_c2);
	}
}
void teki19_c2(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画
	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
}

void teki19_c_1_init(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();

	steki->t_cnt =0;
	stekip->change =4;

	task.ChangeTask ("teki19_c",teki19_c_1);
}

void teki19_c_2_init(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();

	steki->t_cnt =0;
	stekip->change =2;

	task.ChangeTask ("teki19_c",teki19_c_1);
}
//敵１９の子供操作関数
void teki19_c_1(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(steki->hp <0){
		steki->t_cnt=0;
		score+=steki->score ;
		task.ChangeTask ("teki19_c",teki19_c_2);
		return;
	}
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	if(stekip->change ==3){
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
		case 120:
			task.ChangeTask ("teki19_c",teki19_c_1_init);
			return;
			break;
		}
		steki->t_cnt ++;	
	}	
	if(stekip->change ==1){
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
		case 120:
			task.ChangeTask ("teki19_c",teki19_c_2_init);
			return;
			break;
		}
		steki->t_cnt ++;
	}
}
void teki19_c_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	STAMA *stama;
	SJIKI *sjiki=(SJIKI *)ji();
	if(stekip->change ==3){
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
		case 120:
			task.ChangeTask ("teki19_c",teki19_c_1_init);
			return;
			break;
		}
		steki->t_cnt ++;	
	}	
	if(stekip->change ==1){
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
		case 120:
			task.ChangeTask ("teki19_c",teki19_c_2_init);
			return;
			break;
		}
		steki->t_cnt ++;
	}
}

/////////////////////////////////////////////////////////////////
////////////////////敵２０爆発関数///////////////////////////////
/////////////////////////////////////////////////////////////////
void teki20_baku(void){
	STEKI *steki=(STEKI *)task.workspace ();
	SBOMB *sbomb;
	int kakudo,i;
	if((steki->baku_cnt>0)&&(steki->baku_cnt<200)){		
		if((steki->baku_cnt%6)==0)sound.Play(3,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+randamize(-20,20);sbomb->y=steki->y+randamize(-40,40);sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=10;sbomb->speed=10;sbomb->kind=1;
	}
	if((steki->baku_cnt>200)&&(steki->baku_cnt<350)){
		if((steki->baku_cnt%6)==0)sound.Play(4,steki->x);
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+randamize(-20,20);sbomb->y=steki->y+randamize(-40,40);sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=54;sbomb->z_dir=10;sbomb->speed=10;sbomb->kind=2;
	}
	if(steki->baku_cnt >350){
			sound.Play(4,steki->x);
			sound.Play(5,steki->x);
			kakudo=randamize(36,71);

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0xf000,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-14;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=6;
		
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
			sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0;sbomb->psy=0.25f;

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
			sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.25f;sbomb->psy=0;

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
			sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.2f;sbomb->psy=0.2f;
		
			for(i=0;i<10;i++){
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=40;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x+50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x-50;sbomb->y=steki->y+i*25-50;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=0;sbomb->dir=randamize(0,72);sbomb->speed=2;sbomb->kind=2;
			}
			
			SJI *sji=(SJI *)task.MakeTask ("b_o",b_o,0xf000,NO_TASK);
			sji->jika=jikan+300;
			task.KillTask ();
		}
	if(steki->speed<0)steki->speed++;
	if(steki->speed>0)steki->speed--;
	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);
	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->baku_cnt +=2;
	steki->z++;
}
void teki20_baku1(void){
	STEKI *steki=(STEKI *)task.workspace ();
	STEKI *stekip=(STEKI *)task.p_work_add ();
	SBOMB *sbomb;
	int kakudo,i;
	if(steki->baku_cnt >100){
			sound.Play(4,steki->x);
			kakudo=randamize(36,71);
		
			
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0xf000,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-14;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=6;

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
			sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.2f;sbomb->psy=0.2f;
		
			for(i=0;i<10;i++){
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=40;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
			}
			stekip->dir =0;
			stekip->speed =8;
			task.KillTask ();
		}

	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;

	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->baku_cnt +=2;
	steki->z++;
}
void teki20_baku2(void){
	STEKI *steki=(STEKI *)task.workspace ();
	STEKI *stekip=(STEKI *)task.p_work_add ();
	SBOMB *sbomb;
	int kakudo,i;
	if(steki->baku_cnt >200){
			sound.Play(4,steki->x);
			kakudo=randamize(36,71);
			
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0xf000,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-14;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=6;

			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-2;sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-20;sbomb->cnt=0;sbomb->cnt2=0;sbomb->kind=5;
			sbomb->sx=0.4f;sbomb->sy=0.4f;sbomb->psx=0.2f;sbomb->psy=0.2f;
		
			for(i=0;i<10;i++){
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=40;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
				//作成されたタスクのワークスペースが返却される
				sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5200,NO_TASK);
				//ワークスペースに代入（初期化）
				sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z-50 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
			}
			stekip->dir =36;
			stekip->speed =8;
			task.KillTask ();
		}

	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;

	draw.TDClipBltCenter(5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	steki->baku_cnt +=2;
	steki->z++;
}
/////////////////////////////////////////////////////////////////
////////////////////敵２０操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//////////////////////ボス操作関数///////////////////////////////
/////////////////////////////////////////////////////////////////
//初期化
void teki20_init(void){
	STEKI *steki=(STEKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;
	//敵の初期化
	steki->cnt =0;
	steki->cnt2 =0;
	steki->speed =0;
	steki->gra_cnt =0;
	steki->t_cnt =0;
	steki->hp =20000;
	steki->baku_cnt =0;
	steki->change =0;
	SetRect(&steki->rc,237,84,286,236);
	steki->score =10000;
	steki->dir =0;
	steki->angle =54;
	steki->w =48;
	steki->h =140;

	task.ChildMakeTask ("t20_s",teki20_c1_init,0x4000,NO_TASK);
	task.ChildMakeTask ("t20_s",teki20_c2_init,0x4000,NO_TASK);

	//移動用の子供を産む
	task.ChildMakeTask ("t20_s",teki20_1,0x4000,NO_TASK);
	//本体
	task.ChangeTask ("teki20",teki20);
}
//描画関数
void teki20(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//描画
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	//リミットチェック
	SBOMB *sbomb;
	if(steki->hp<300){
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x-20;sbomb->y=steki->y+30;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=randamize(45,62);sbomb->z_dir=0;sbomb->speed=2;sbomb->kind=3;
	}
	if(steki->hp<200){
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x+20;sbomb->y=steki->y+30;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=randamize(45,62);sbomb->z_dir=0;sbomb->speed=2;sbomb->kind=3;
	}
	if(steki->hp<100){
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=steki->x;sbomb->y=steki->y+40;sbomb->z=steki->z;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=randamize(45,62);sbomb->z_dir=0;sbomb->speed=2;sbomb->kind=3;
	}
	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		steki->speed =0;
		score+=steki->score;
		audio.Stop ();
		task.ChangeTask ("baku",teki20_baku);
		return;
	}
}
//何もしない関数（破壊した時用）
void teki20_0(void){


}
//操作関数
void teki20_1(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->y >-30)task.ChangeTask ("teki20_c",teki20_2);
	steki->y ++;
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
}
void teki20_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	STAMA *stama;
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->x <50)task.ChangeTask ("teki20_c",teki20_3);

	if(steki->t_cnt==0){
		sound.Play(20,steki->x);
		sound.Play(7,steki->x);
	}
	stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
	stama->x=steki->x-15;stama->y=steki->y+70;stama->z=0;stama->angle =54;stama->kind =13;
	
	stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
	stama->x=steki->x+15;stama->y=steki->y+70;stama->z=0;stama->angle =54;stama->kind =13;
	steki->t_cnt ++;
	steki->x-=1;
}
void teki20_3(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	STAMA *stama;
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->x>230)task.ChangeTask ("teki20_c",teki20_4);	

	stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
	stama->x=steki->x-15;stama->y=steki->y+70;stama->z=0;stama->angle =54;stama->kind =13;
	
	stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
	stama->x=steki->x+15;stama->y=steki->y+70;stama->z=0;stama->angle =54;stama->kind =13;

	steki->x+=1;
}
void teki20_4(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->y>20){
		steki->t_cnt =0;
		steki->change =1;
		task.ChangeTask ("teki20_c",teki20_5);
		return;
	}
	if(steki->y>20)steki->y=20;
	if(steki->x<140)steki->x=140;

	steki->x-=2;
	steki->y++;
}
void teki20_5(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->x<80){
		if(steki->cnt>0){
			steki->change =0;
			task.ChangeTask ("teki20_c",teki20_7);
			return;
		}
		task.ChangeTask ("teki20_c",teki20_6);
		return;
	}
	steki->x-=2;
}
void teki20_6(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->x>210){
		steki->cnt++;
		task.ChangeTask ("teki20_c",teki20_5);
		return;
	}
	steki->x+=2;
}
void teki20_7(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->z>70){
		steki->t_cnt =0;
		steki->cnt =0;
		task.ChangeTask ("teki20_c",teki20_8);
		return;
	}

	if(steki->x>140)steki->x=140;
	if(steki->y>200)steki->y=200;
	steki->x +=3;
	steki->z ++;
	steki->y +=3;
}
void teki20_8(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->gra_cnt ==2){
		task.ChangeTask ("teki20_c",teki20_10);
		return;
	}
	if(t_tama_pa8(steki)){
		steki->t_cnt =0;
		task.ChangeTask ("teki20_c",teki20_9);
		return;
	}
}
void teki20_9(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->y<-30){
		steki->z=0;
		steki->t_cnt =0;
		task.ChangeTask ("teki20_c",teki20_2);
		return;
	}
	steki->z-=1;
	steki->y-=3;
}
void teki20_10(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if(steki->y>310){
		steki->z=0;
		steki->t_cnt =0;
		task.ChangeTask ("teki20_c",teki20_11);
		return;
	}
	if(steki->z <0)steki->z=0;
	steki->z-=1;
	steki->y+=3;
}
void teki20_11(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);
	if((steki->y>50)&&(steki->y<53)){
		STAMA *stama;
		stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x4000,NO_TASK);
		stama->x=steki->x;stama->y=steki->y;stama->z=0;stama->kind =9;
	}

	if(steki->y<-120){
		steki->speed =16;
		steki->dir=54;
		task.ChangeTask ("teki20_c",teki20_12);
		return;
	}
	steki->y-=2;
}

void teki20_12(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);

	if(steki->speed<0){
		steki->change =3;
		task.ChangeTask ("teki20_c",teki20_13);
		return;
	}

	draw.move72 (&steki->x ,&steki->y ,steki->dir,steki->speed);

	if(steki->cnt2>1){
		steki->cnt2 =0;
		steki->speed --;
	}
	steki->cnt2++;
}

void teki20_13(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);

	if(t_tama_pa9(steki)){
		steki->change = 4;
		task.ChangeTask ("teki20_c",teki20_14);
		return;
	}

}
void teki20_14(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);

	if(steki->z>70){
		steki->change =5;
		steki->t_cnt =0;
		task.ChangeTask ("teki20_c",teki20_15);
		return;
	}
	if(steki->z<140)steki->y=140;

	steki->z+=2;
	steki->y-=2;
}
void teki20_15(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	if(steki->hp <0)task.ChangeTask ("teki20_c",teki20_0);

	if(t_tama_pa10(steki)){
		steki->change =3;
		task.ChangeTask ("teki20_c",teki20_10);
		return;
	}
}
/////////敵２０の子供////////////
void teki20_c1_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->kind =1;
	steki->px =-40;
	steki->py =47;
	steki->hp =200;
	steki->z =stekip->z ;
	steki->t_cnt =0;
	steki->cnt =0;
	steki->cnt2 =0;
	SetRect(&steki->rc,98,136,130,240);
	steki->w =30;
	steki->h =70;

	task.ChildMakeTask ("teki20_c",teki20_c_1,0x4000,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki20_c",teki20_c);
}
void teki20_c2_init(void){
	//自分のワークスペース
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();

	TCB *t=(TCB *)task.add_ret ();
	t->type =ENEMY_TASK;

	steki->kind =2;
	steki->px =40;
	steki->py =47;
	steki->hp =200;
	steki->z =stekip->z ;
	steki->t_cnt =0;
	steki->cnt =0;
	steki->cnt2 =0;
	SetRect(&steki->rc,288,40,320,144);
	steki->w =30;
	steki->h =70;

	task.ChildMakeTask ("teki20_c",teki20_c_1,0x4000,NO_TASK);
	//次へチェンジ
	task.ChangeTask ("teki20_c",teki20_c);
}

void teki20_c(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画
	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;

	if(steki->hp <0){
		TCB *t=(TCB *)task.add_ret ();
		t->type =NO_TASK;
		sound.Play(1,steki->x);
		sound.Play(4,steki->x);
		int kakudo;
		SBOMB *sbomb;
		kakudo=randamize(10,60);
		for(int i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->z_dir=15;sbomb->dir=randamize(36,72);sbomb->speed=randamize(1,4);sbomb->kind=2;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=steki->x;sbomb->y=steki->y;sbomb->z=steki->z ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo-i;sbomb->z_dir=15;sbomb->speed=11-i;sbomb->kind=3;
		}

		if(steki->kind ==1)
			SetRect(&steki->rc,206,165,237,240);
		else
			SetRect(&steki->rc,286,164,317,240);
		stekip->gra_cnt++;
		if(stekip->gra_cnt ==2)stekip->hp =600;
		steki->py =41;
		task.ChangeTask ("teki20_c",teki20_c2);
	}
	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
}

void teki20_c2(void){
	STEKI *steki=(STEKI *)task.workspace ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_work_add();
	//描画
	steki->z=stekip->z;
	steki->x =stekip->x+steki->px ;
	steki->y =stekip->y+steki->py ;

	if(stekip->hp<0){
		if(steki->kind ==1)
			task.ChangeTask ("teki20_c",teki20_baku1);
		else
			task.ChangeTask ("teki20_c",teki20_baku2);
	}

	draw.TDClipBltCenter( 5,steki->x,steki->y,steki->z,145,120,10,steki->rc,DDBLT_KEYSRC|DDBLT_WAIT);
}
void teki20_c_1_init(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();

	steki->t_cnt =0;
	stekip->change =4;

	task.ChangeTask ("teki20_c",teki20_c_1);
}

void teki20_c_2_init(void){
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();

	steki->t_cnt =0;
	stekip->change =2;

	task.ChangeTask ("teki20_c",teki20_c_1);
}
//敵２０の子供操作関数
void teki20_c_0(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
}

void teki20_c_1(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	if(steki->hp <0){
		score+=steki->score ;
		task.ChangeTask ("teki20_c",teki20_c_2);
		return;
	}
	if(stekip->change ==1){
		t_tama_pa7(steki);
	}
}

void teki20_c_2(void){
	//親のワークスペース
	STEKI *steki=(STEKI *)task.p_work_add ();
	//おじんのワークスペース
	STEKI *stekip=(STEKI *)task.p_p_work_add();
	STAMA *stama;

	SJIKI *sjiki=(SJIKI *)ji();
	int dir =(int)(atan2((steki->y)-(sjiki->y),(sjiki->x)-(steki->x))*36/3.141592);	
	if(dir <0)dir +=72;

	if(stekip->hp <0){
		score+=steki->score ;
		task.ChangeTask ("teki20_c",teki20_c_0);
		return;
	}
	if(stekip->change ==5){
		if((steki->t_cnt %30)==0){
			sound.Play (9,steki->x);
			stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5000,E_SHOT1_TASK);
			stama->x=steki->x ;stama->y=steki->y+35;stama->z=steki->z;stama->angle =dir;stama->kind =3;stama->kyori =3;
		}
		steki->t_cnt ++;
	}	
	if(stekip->change ==1){
		if((steki->t_cnt %4)==0){
			stama=(STAMA *)task.MakeTask("t_tama_init",t_tama_init,0x5200,E_SHOT1_TASK);
			stama->x=steki->x;stama->y=steki->y+30;stama->z=steki->z;stama->angle =54;stama->kind =1;stama->kyori =4;
		}
		steki->t_cnt ++;
	}
}


