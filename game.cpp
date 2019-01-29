#include"main.h"
#include"game_str.h"	
#include"game.h"

//システムタスク用
void title_init(void);
void entry_init(void);
//各変数軍
unsigned long score=0;
unsigned int jikan=0;
unsigned int map_a[400][7];
STEKI steki_t[350];

/////////////////////////////////////////////////////////////////
/////////////////////ゲーム総合初期化関数////////////////////////
/////////////////////////////////////////////////////////////////
void game_init(void){
	//画面のクリア
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	Sleep(1000);
	//登録されているタスクを全てキル
	task.AllKill ();
	//登録されている画像、サウンドを全て解放
	draw.Release();
	sound.Release();
	Sleep(1000);

	//サーフェイスを作る（画像読込）
	draw.MakeSurface (1,"gra\\syousai.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (2,"gra\\syousai_s.bmp",DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	draw.MakeSurface (3,"gra\\map_tip.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (4,"gra\\subtitle.bmp",DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	draw.MakeSurface (7,"gra\\map_tip2.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (9,"gra\\map_tip3.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (10,"gra\\teki.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (11,"gra\\teki_s.bmp",DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	draw.MakeSurface (12,"gra\\bomb.bmp",DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (13,"gra\\map_tip4.bmp",DDSCAPS_OFFSCREENPLAIN,253);

	//サーフェイスを作るだけ
	draw.MakeSurface (5,320,320,DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (6,320,320,DDSCAPS_OFFSCREENPLAIN,253);
	draw.MakeSurface (8,320,480,DDSCAPS_OFFSCREENPLAIN,253);
		
	//画面のクリア
	draw.Cls(0,0,0,320,240,RGB(0,0,0));
	draw.FontShow(0,"N O W  L O A D I N G...",10,160,220,RGB(255,255,255));
	draw.Flip();

	sound.Loadwave(1,"sound\\kamui_shot.wav",10);
	sound.Loadwave(2,"sound\\kamui_exp_01.wav",10);
	sound.Loadwave(3,"sound\\kamui_exp_02.wav",10);
	sound.Loadwave(4,"sound\\kamui_exp_03.wav",10);
	sound.Loadwave(5,"sound\\kamui_exp_04.wav",10);
	sound.Loadwave(6,"sound\\kamui_hit_01.wav",10);
	sound.Loadwave(7,"sound\\kamui_laser_b.wav",10);
	sound.Loadwave(8,"sound\\kamui_laser_h.wav",10);
	sound.Loadwave(9,"sound\\kamui_laser_n.wav",10);
	sound.Loadwave(10,"sound\\kamui_lockon.wav",10);
	sound.Loadwave(11,"sound\\kamui_macine_01.wav",10);
	sound.Loadwave(12,"sound\\kamui_missile.wav",10);
	sound.Loadwave(13,"sound\\kamui_pitem.wav",10);
	sound.Loadwave(14,"sound\\kamui_sItem.wav",10);
	sound.Loadwave(15,"sound\\kamui_raigekiHit.wav",10);
	sound.Loadwave(16,"sound\\kamui_raitou.wav",10);
	sound.Loadwave(17,"sound\\kamui_sde.wav",10);
	sound.Loadwave(18,"sound\\kamui_thunder_01.wav",10);
	sound.Loadwave(19,"sound\\kamui_arert.wav",10);
	sound.Loadwave(20,"sound\\kamui_charge.wav",10);

	//ゲームの詳細設定
	score=0;
	jikan=0;

	int i;
	FILE *fp;
	////////////ファイル操作////////////////
	if((fp=fopen("map1_a.dat","r"))!=NULL){
		//ファイルがある場合
		for(i=0;i<300;i++){
			if(fscanf(fp,"%x %x %x %x %x %x %x",&map_a[i][0],&map_a[i][1],&map_a[i][2],&map_a[i][3],&map_a[i][4],&map_a[i][5],&map_a[i][6])==EOF){
				break;
			}
		}
		fclose(fp);
	}else{
		//ファイルが無い場合強制終了
		PostQuitMessage(0);
	}
	if((fp=fopen("map1_b.dat","r"))!=NULL){
		//ファイルがある場合
		fclose(fp);
	}else{
		//ファイルが無い場合強制終了
		PostQuitMessage(0);
	}
	if((fp=fopen("teki_init.dat","r"))!=NULL){
		//ファイルがある場合
		for(i=0;;i++){
			if(fscanf(fp,"%d %d %d %d %d",&steki_t[i].jikan,&steki_t[i].kind,&steki_t[i].x,&steki_t[i].y,&steki_t[i].z)==EOF){
				break;
			}
		}
	fclose(fp);
	}else{
		//ファイルが無い場合強制終了
		PostQuitMessage(0);
	}

	/////////////////////////////////
	//////////タスクの設定///////////
	/////////////////////////////////
	//塗りつぶし
	task.MakeTask ("cls",back,0x1000,NO_TASK);

	//ゲーム本体
	task.MakeTask ("scrl1",scrool1_init,0x4100,NO_TASK);
	task.MakeTask ("teki",teki,0x5000,NO_TASK);	
	task.MakeTask ("jiki",jiki_init,0x5200,JIKI_DEAD_TASK);

	//作業サーフェイスからフリップ
	task.MakeTask ("mapflip",map_flip,0xf000,NO_TASK);

	//サブタイトル表示
	task.MakeTask ("subinit",sub_title_init,0xfff0,NO_TASK);
	
	//自機を参照し詳細を表示（残機やらなんやら）
	task.MakeTask ("syoinit",syousai_init,0xfffd,NO_TASK);
	
	//時間のカウント
	task.MakeTask ("jika",timer,0xfffe,NO_TASK);
	
	//システムタスク
	task.Sys_Task_Initiator (NULL,NORETURN);
	
	//ＣＤの再生
	audio.Play(5,MM_CD_LOOPING);
}
/////////////////////////////////////////////////////////////////
/////////////////////各種操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//自機のワークスペースを返す
void *ji(void){
	//自機を探す
	TCB *t=(TCB *)task.ActiveTop();
	//時機を探す
	while(t->next!=NULL){
		//自機は一機しかいないので見つかったら抜ける
		if((t->type==JIKI_TASK)|(t->type==JIKI_DEAD_TASK))break;
		t=t->next ;
	}
	//時機のワークスペースを返す
	return t->work ;
}
//ｚ座標により、優先順位変更(子供有りバージョン)
void z_prio(int z){
	if((z >100)&&(z <200))task.ChangePrio (0x4000);
	if((z >0)&&(z <100))task.ChangePrio (0x5000);
	if(z <-0)task.ChangePrio (0x6000);
}
//ｚ座標により、優先順位変更(子供無しバージョン)
void z_prio2(int z){
	if((z >100)&&(z <200))task.ChangePrio2(0x4000);
	if((z >-0)&&(z <100))task.ChangePrio2 (0x5000);
	if(z <-0)task.ChangePrio2 (0x6000);
}
//リミットチェック専用（インライン関数）
void rimito(int x,int y,int z){
	if(!((x>-150)&&(x<470)))task.KillTask ();
	if(!((y>-150)&&(y<390)))task.KillTask ();
	if(!((z>-250)&&(z<240)))task.KillTask ();
}
void timer(void){
	if((GetAsyncKeyState(VK_F11)&0x8000)){
		audio.Stop ();
		task.AllKill ();
		task.Sys_Task_Initiator(title_init,RETURN);
		return;
	}
	//時間のリミットチェック
	if(jikan>65000)jikan=65000;
	jikan++;  
}
void b_o(void){
	//自分のワークスペース
	SJI *sji=(SJI *)task.workspace ();
	if(sji->jika >jikan){
		if(draw.BlackOut (2)){
			audio.Stop ();
			task.AllKill ();
			task.Sys_Task_Initiator(entry_init,RETURN);
			return;
		}
	}
}
void b_o2(void){
	//自分のワークスペース
	SJI *sji=(SJI *)task.workspace ();
	if(sji->jika >jikan){
		if(draw.BlackOut (4)){
			audio.Stop ();
			task.AllKill ();
			task.Sys_Task_Initiator(title_init,RETURN);
			return;
		}
	}
}
/////////////////////////////////////////////////////////////////
/////////////////////判定操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//弾が当った時のグラフィック
void kage(void){
	//自分のワークスペース
	SKAGE *skage=(SKAGE *)task.workspace ();
	if(skage->g_cnt >3)task.KillTask ();
	SetRect(&skage->rc ,0+skage->g_cnt*20,115,0+skage->g_cnt*20+20,138);
	draw.ClipBltCenter(5,skage->x ,skage->y,1,1,1,skage->rc,DDBLT_KEYSRC|DDBLT_WAIT);	
	skage->g_cnt ++;
}
//ヒットチェック
char HitCheck(int x1,int y1,int z1,int w1,int h1,int x2,int y2,int z2,int w2,int h2){
	if (y1 < (y2 + h2) && (y1 + h1) > y2 &&(x1 < (x2 + w2) && (x1 + w1) > x2)&&(z1==z2))	
		return 1;
	else 		
		return 0;
}
//敵当り判定用
void hantei(int x,int y,int z,int w,int h){
	TCB *Active=(TCB *)task.ActiveTop ();
	SKAGE *skage;
	STEKI *steki;
	STAMA *stama;
	//敵を調べる
	while(Active->next !=NULL){
		//敵ならば
		if(Active->type ==ENEMY_TASK){
			//敵のワークスペースを返す
			steki=(STEKI *)Active->work;
			//その敵との当り判定
			if(HitCheck(x-(w>>1),y-(h>>1),z,w,h,steki->x-(steki->w>>1),steki->y-(steki->h>>1),steki->z,steki->w,steki->h)){
				//当れば音を鳴らす
				sound.Play (6,x);
				//ヒットポイントを減らす
				steki->hp --;
				//当った時のグラフィックをメイク
				skage=(SKAGE *)task.MakeTask("kege",kage,0x5150,NO_TASK);
				skage->x =x;skage->y =y;skage->g_cnt =0;SetRect(&skage->rc ,0,115,20,138);
				//自分は死ぬ
				task.KillTask();
			}
		}
		if(Active->type ==E_SHOT2_TASK){
			//敵のワークスペースを返す
			stama=(STAMA *)Active->work;
			//その敵との当り判定
			if(HitCheck(x-(w>>1),y-(h>>1),z,w,h,stama->x-(stama->w>>1),stama->y-(stama->h>>1),stama->z,stama->w,stama->h)){
				//ヒットポイントを減らす
				stama->hp --;
				//当った時のグラフィックをメイク
				skage=(SKAGE *)task.MakeTask("kege",kage,0x5150,NO_TASK);
				skage->x =x;skage->y =y;skage->g_cnt =0;SetRect(&skage->rc ,0,115,20,138);
				//自分は死ぬ
				task.KillTask();
			}
		}
		Active=Active->next ;
	}
}
//自機当り判定用
void jiki_hantei(int x,int y,int z,int w,int h){
	TCB *Active=(TCB *)task.ActiveTop ();
	while(Active->next !=NULL){
		//敵ならば
		if(Active->type ==JIKI_TASK){
			//敵のワークスペースを返す
			SJIKI *sjiki=(SJIKI *)Active->work;
			//その敵との当り判定
			if(HitCheck(x-(w>>1),y-(h>>1),z,w,h,sjiki->x-(sjiki->w>>1),sjiki->y-(sjiki->h>>1),0,sjiki->w,sjiki->h)){
				if(sjiki->flag ==0){
					sjiki->flag =1;
					//ヒットポイントを減らす
					sjiki->shield --;
					//自分は死ぬ
					task.KillTask();
				}
				return;
			}
		}
		Active=Active->next ;
	}
}
//自機当り判定用２
void jiki_hantei2(int x,int y,int z,int w,int h){
	TCB *Active=(TCB *)task.ActiveTop ();
	while(Active->next !=NULL){
		//敵ならば
		if(Active->type ==JIKI_TASK){
			//敵のワークスペースを返す
			SJIKI *sjiki=(SJIKI *)Active->work;
			//その敵との当り判定
			if(HitCheck(x-(w>>1),y-(h>>1),z,w,h,sjiki->x-(sjiki->w>>1),sjiki->y-(sjiki->h>>1),0,sjiki->w,sjiki->h)){
				if(sjiki->flag ==0){
					sjiki->flag =1;
					//ヒットポイントを減らす
					sjiki->shield --;
				}
				return;
			}
		}
		Active=Active->next ;
	}
}
/////////////////////////////////////////////////////////////////
/////////////////////弾　操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//////弾初期化//////
void tama1_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,184,0,192,25);
	stama->w =8;
	stama->h =25;
	stama->angle =18;
	stama->kyori =20;	
	task.ChangeTask ("tama1",tama_idou);
}
void tama2_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,191,0,199,25);
	stama->w =8;
	stama->h =25;
	stama->angle =18;
	stama->kyori =20;	
	task.ChangeTask ("tama2",tama_idou);
}
void tama3_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,173,9,179,28);
	stama->w =6;
	stama->h =19;
	stama->angle =22;
	stama->kyori =20;	
	task.ChangeTask ("tama3",tama_idou);
}
void tama4_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,202,9,208,28);
	stama->w =6;
	stama->h =19;
	stama->angle =14;
	stama->kyori =20;	
	task.ChangeTask ("tama4",tama_idou);
}
void tama5_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,163,11,171,25);
	stama->w =8;
	stama->h =14;
	stama->angle =24;
	stama->kyori =20;	
	task.ChangeTask ("tama5",tama_idou);
}
void tama6_init(void){
	STAMA *stama=(STAMA *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	t->type =SHOT_TASK;
	SetRect(&stama->rc ,210,11,218,25);
	stama->w =8;
	stama->h =14;
	stama->angle =12;
	stama->kyori =20;	
	task.ChangeTask ("tama6",tama_idou);
}
//////弾移動処理//////
void tama_idou(void){
	STAMA *stama=(STAMA *)task.workspace ();
	if((stama->x<-50)||(stama->y<-50)||(stama->x>370)||(stama->y>290))task.KillTask ();
	draw.ClipBltCenter(5,(int)stama->x ,(int)stama->y,1,1,1,stama->rc,DDBLT_KEYSRC|DDBLT_WAIT);	
	draw.move72(&stama->x,&stama->y,stama->angle ,stama->kyori );
	hantei(stama->x,stama->y,stama->z,stama->w,stama->h);
}
//発射時のグラフィック処理
void k_tama(void){
	SJIKI *sjiki=(SJIKI *)task.p_p_work_add ();
	static char cnt=0;
	RECT kazari_rc[4]={{144,32,168,57},{168,32,192,57},{192,32,216,57},{216,32,240,57}};
	if(cnt>3){cnt=0;task.KillTask ();}
	draw.ClipBltFast(5,sjiki->x-11,sjiki->y-35 ,1,kazari_rc[cnt],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	cnt++;
}
/////////////////////////////////////////////////////////////////
/////////////////////雷撃操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
void thander_init(void){
	//サンダーのワークスペース
	STHA *stha=(STHA *)task.workspace();
	//初期設定
	stha->z=0;
	stha->w=8;
	stha->h=8;
	stha->cnt =0;
	stha->kyori=10;
	//次へチェンジ
	task.ChangeTask ("thander",thander);
}
void thander_s(void){
	//サンダーのワークスペース
	STHA *stha=(STHA *)task.workspace ();
	//レクト
	RECT rc;
	SetRect(&rc,19*stha->kind,206,19*stha->kind+19,224);
	//カウントが来るとキル
	if(stha->cnt>0)task.KillTask ();
	//描画
	draw.TDAlphaBlt ( 5,stha->x,stha->y,stha->z,1,rc,stha->cnt,2);
	stha->cnt ++;
}
void thander(void){
	//各ワークスペース
	STHA *stha=(STHA *)task.workspace();
	STHA *sthas;
	STEKI *steki=NULL;
	//レクト
	RECT rc;
	SetRect(&rc,19*stha->kind,206,19*stha->kind+19,224);
	//描画
	draw.TDTurnBlt ( 5,stha->x,stha->y,stha->z,1,rc,stha->dir*5,10,10);
	//移動
	stha->kyori =25;
	stha->z +=15;	
	draw.move72 (&stha->x ,&stha->y ,stha->dir,stha->kyori);
	//サンダーの残像をメイク
	sthas=(STHA *)task.MakeTask ("tha_s",thander_s,0x5000,SHOT_TASK);
	sthas->x =stha->x;sthas->y =stha->y;sthas->z =stha->z;sthas->w =8;sthas->h =8;sthas->cnt =-8;sthas->kind =randamize(0,4);
	//リミットチェック
	rimito(stha->x,stha->y,stha->z);
}
//サンダー作成総合関数
char thander_make(SJIKI *sjiki){
	//アクティブのトップを取得
	TCB *Active=(TCB *)task.ActiveTop ();
	int i;
	//サンダーをだす
	switch(sjiki->tha_cnt){
	case 0:case 5:case 10:case 15:case 20:case 25:case 30:case 35:case 40:case 45:
		sound.Play(18,sjiki->x);
		for(i=0;i<8;i++){
			STHA *stha=(STHA *)task.MakeTask ("thander",thander_init,0x5000,NO_TASK);
			stha->x =sjiki->x;stha->y =sjiki->y;stha->z =0;stha->dir=randamize(0,71);stha->kind=randamize(0,4);	
		}

		//ダメージを与える
		while(Active->next !=NULL){
			//敵ならば
			if(Active->type ==ENEMY_TASK){
				//敵のワークスペースを返す
				STEKI *steki=(STEKI *)Active->work;
				if(steki->z>5){
					steki->hp -=3;
					if(steki->hp<0){
						STEN *sten=(STEN *)task.MakeTask ("ten",tensu,0xe000,NO_TASK);	
						sten->cnt=0;sten->tensu=steki->score;sten->bai =sjiki->tha_bai;sten->x=steki->x;sten->y=steki->y;sten->z=steki->z;
					}
				}
			}
			Active=Active->next ;
		}
		break;
	}

	//シールド倍数に合った分だけ出すとかえす
	if(sjiki->tha_bai*5<sjiki->tha_cnt){
		sjiki->tha_cnt=0;
		return 1;
	}
	sjiki->tha_cnt ++;
	return 0;
}
/////////////////////////////////////////////////////////////////
/////////////////////自機操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//自機初期化//
void jiki_init(void){
	SJIKI *sjiki=(SJIKI *)task.workspace ();
	//自機の初期パラメータ
	sjiki->x=140;
	sjiki->y=140;
	sjiki->w=10;
	sjiki->h=10;
	sjiki->t=0;
	sjiki->s=2.0f;
	sjiki->sx =20;
	sjiki->g_cnt=4;	
	sjiki->t_cnt=0;
	sjiki->tha_cnt=0;
	sjiki->tha_bai=0;
	sjiki->tha_flag=0;
	sjiki->shield =4;
	sjiki->shield_h =4;
	sjiki->zanki =2;
	sjiki->raigeki =0;
	sjiki->flag =1;
	sjiki->toumei=0;
	sjiki->m_cnt=0;
	sjiki->cnt=0;

	//自機操作タスクをメイク
	task.ChildMakeTask("jiki_s1",jiki_s1,0x5210,NO_TASK);
	//登場するタスクにチェンジ
	task.ChangeTask ("jiki",jiki);
}
void jiki_init1(void){
	SJIKI *sjiki=(SJIKI *)task.workspace ();
	//登場するタスクにチェンジ
	if(sjiki->cnt>30)
		task.ChangeTask ("jiki",jiki_init2);
	sjiki->cnt ++;
}
void jiki_init2(void){
	SJIKI *sjiki=(SJIKI *)task.workspace ();
	
	//自機の初期パラメータ
	sjiki->x=140;
	sjiki->y=140;
	sjiki->t=0;
	sjiki->s=2.0f;
	sjiki->g_cnt=4;
	sjiki->t_cnt=0;
	sjiki->tha_cnt=0;
	sjiki->tha_bai=0;
	sjiki->tha_flag=0;
	sjiki->shield =4;
	sjiki->shield_h =4;
	sjiki->raigeki =0;
	sjiki->flag =1;
	sjiki->toumei=0;
	sjiki->m_cnt=0;
	sjiki->cnt=0;
	
	//残機が無い時
	if(sjiki->zanki <0){
		SJI *sji=(SJI *)task.MakeTask ("b_o",b_o2,0xf000,NO_TASK);
		sji->jika=jikan+300;
		task.ChangeTask ("jiki",jiki_0);
		return;
	}

	//自機操作タスクをメイク
	task.ChildMakeTask("jiki_s1",jiki_s1,0x5210,NO_TASK);
	//登場するタスクにチェンジ
	task.ChangeTask ("jiki",jiki);
}
//何もしない関数
void jiki_0(void){

}

//自機操作//
void jiki(void){
	SJIKI *sjiki=(SJIKI *)task.workspace ();
	TCB *t=(TCB *)task.add_ret ();
	RECT jiki_rect[9]={{0,0,32,32},{32,0,64,32},{64,0,96,32},{96,0,128,32},{128,0,160,32},{0,32,32,64},{32,32,64,64},{64,32,96,64},{96,32,128,64}};
	//移動位置のリミットチェック
	if(sjiki->x<0)sjiki->x=0;
	if(sjiki->x>280)sjiki->x=280;
	if(sjiki->y<0)sjiki->y=0;
	if(sjiki->y>240)sjiki->y=240;
	//グラフィックのリミットチェック
	if(sjiki->g_cnt<0)sjiki->g_cnt=0;
	if(sjiki->g_cnt>8)sjiki->g_cnt=8;

	if(sjiki->flag ==1)
		t->type =JIKI_DEAD_TASK;
	else
		t->type =JIKI_TASK;

	//描画
	draw.ClipBltCenter(5,sjiki->x ,sjiki->y ,1,1,1,jiki_rect[sjiki->g_cnt],DDBLT_KEYSRC|DDBLT_WAIT);	
	//雷撃溜めグラフィック
	static int i=0;
	if(i>3)i=0;
	RECT rc={0+30*i,34,30+30*i,65};
	if(sjiki->raigeki > 20)
		draw.AlphaBltFast(5,sjiki->x-14 ,sjiki->y-23 ,2,rc,(char)(16-(sjiki->raigeki)/5),1);
	else
		draw.AlphaBltFast(5,sjiki->x-14 ,sjiki->y-23 ,2,rc,(char)(sjiki->raigeki)>>2,2);
	i++;
	///////ショットエネルギー関連/////////
	sjiki->raigeki +=0.2f;
	if(sjiki->raigeki <0)sjiki->raigeki =0;
	if(sjiki->raigeki >73)sjiki->raigeki =73;
	//シールドが無くなれば爆発
	if(sjiki->shield<0){
		SBOMB *sbomb;
		int kakudo;
		sound.Play(1,sjiki->x);
		sound.Play(4,sjiki->x);
		for(i=0;i<72;i+=6){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=sjiki->x;sbomb->y=sjiki->y;sbomb->z=0;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=i;sbomb->z_dir=6;sbomb->speed=8;sbomb->kind=1;
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=sjiki->x;sbomb->y=sjiki->y;sbomb->z=0;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=i;sbomb->z_dir=6;sbomb->speed=4;sbomb->kind=1;
		}
		kakudo=randamize(10,60);
		for(i=0;i<10;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->x=sjiki->x;sbomb->y=sjiki->y;sbomb->z=0 ;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=kakudo+i;sbomb->speed=4+i;sbomb->kind=3;
		}
		//作成されたタスクのワークスペースが返却される
		sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
		//ワークスペースに代入（初期化）
		sbomb->x=sjiki->x;sbomb->y=sjiki->y;sbomb->z=0;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=-1;sbomb->z_dir=15;sbomb->speed=0;sbomb->kind=2;

		sjiki->zanki --;
		task.ChangeTask ("jiki",jiki_init1) ;
	}
}
//自機点滅
void jiki_t(void){
	//自機のワークスペース
	SJIKI *sjiki=(SJIKI *)task.p_p_work_add();
	//自機専用レクト
	RECT jiki_rect[9]={{0,0,32,32},{32,0,64,32},{64,0,96,32},{96,0,128,32},{128,0,160,32},{0,32,32,64},{32,32,64,64},{64,32,96,64},{96,32,128,64}};
	//半透明リミットチェック
	if(sjiki->toumei >8)sjiki->toumei =0;
	//点滅時間
	if(sjiki->m_cnt >100){
		sjiki->flag =0;
		task.KillTask ();
	}
	//半透明転送
	draw.AlphaBltFastCenter( 5,sjiki->x,sjiki->y,1,jiki_rect[sjiki->g_cnt],-sjiki->toumei,2);
	sjiki->m_cnt ++;
	sjiki->toumei ++;
}
//自機ヒットアニメーションイニシャライズ
void jiki_sde_init(void){
	//ＳＤＥワークスペース
	SSDE *ssde=(SSDE *)task.workspace();
	//初期設定
	ssde->cnt=0;
	//次にチェンジ
	task.ChangeTask ("jiki_sde",jiki_sde);
}
//自機ヒットアニメーション
void jiki_sde(void){
	//自機のワークスペース
	SJIKI *sjiki=(SJIKI *)task.p_p_work_add();
	//ＳＤＥワークスペース
	SSDE *ssde=(SSDE *)task.workspace();
	//ボムワークスペース
	SBOMB *sbomb;
	//ＳＤＥレクト
	RECT rc={256,0,320,64};
	//時間が来たら
	if(ssde->cnt >10){
		//ボム（ＳＤＥ用）を作成
		for(int i=0;i<30;i++){
			//作成されたタスクのワークスペースが返却される
			sbomb=(SBOMB *)task.MakeTask ("bom",bomb_init,0x5300,NO_TASK);
			//ワークスペースに代入（初期化）
			sbomb->toumei=-11;sbomb->x=sjiki->x;sbomb->y=sjiki->y;sbomb->cnt=0;sbomb->cnt2=0;sbomb->dir=randamize(0,72);sbomb->speed=randamize(2,6);sbomb->kind=4;
		}
		//自分をキル
		task.KillTask ();
	}
	//半透明転送
	draw.AlphaBltFastCenter(5,sjiki->x,sjiki->y,2,rc,-10,0);
	//カウントを進める
	ssde->cnt++;
}
//自機登場
void jiki_s1(void){
	//自機ワークスペース
	SJIKI *sjiki=(SJIKI *)task.p_work_add();
	if(sjiki->s<=1)sjiki->s=1;
	//通常位置まできたら次へ
	if(sjiki->t>27){
		//自機点滅タスクをメイク
		task.ChildMakeTask("jiki_t",jiki_t,0x5220,NO_TASK);	
		task.ChangeTask ("jikis2",jiki_s2);
	}
	//物理（ジャンプ）の法則を使い登場させる
	sjiki->y=(-28*sjiki->t+1*sjiki->t*sjiki->t)+200;
	sjiki->t++;
	sjiki->s-=0.1f;
}
//自機操作
void jiki_s2(void){
	//自機ワークスペース
	SJIKI *sjiki=(SJIKI *)task.p_work_add();
	//弾作成用ワークスペース
	STAMA *stama;
	//////////キー判定/////////
	//左右同時に押された場合
	if((((GetAsyncKeyState(VK_RIGHT)&0x8000)==0)&&((GetAsyncKeyState(VK_LEFT)&0x8000)==0))||
		((GetAsyncKeyState(VK_RIGHT)&0x8000))&&((GetAsyncKeyState(VK_LEFT)&0x8000))){
		if(sjiki->g_cnt<4)sjiki->g_cnt++;
		if(sjiki->g_cnt>4)sjiki->g_cnt--;
	}
	///////ショット関連/////////
	static char x_key,z_key;
	if(sjiki->t_cnt>0)sjiki->t_cnt -=1;
	if((GetAsyncKeyState('Z')&0x8000)&&(sjiki->t_cnt<=0)&&(x_key==0)){
		z_key=1;
		sound.Play(1,sjiki->x);
		//通常の弾
		stama=(STAMA *)task.MakeTask ("tama1init",tama1_init,0x50d1,NO_TASK);
		stama->x =sjiki->x-6;stama->y =sjiki->y-25;stama->z=0;
		stama=(STAMA *)task.MakeTask ("tama2init",tama2_init,0x50d1,NO_TASK);
		stama->x =sjiki->x+8;stama->y =sjiki->y-25;stama->z=0;
		//エネルギーが上がってくると撃てる弾１
		if(sjiki->raigeki >25){
			stama=(STAMA *)task.MakeTask ("tama3init",tama3_init,0x50d1,NO_TASK);
			stama->x =sjiki->x-12;stama->y =sjiki->y-25;stama->z=0;	
			stama=(STAMA *)task.MakeTask ("tama4init",tama4_init,0x50d1,NO_TASK);
			stama->x =sjiki->x+14;stama->y =sjiki->y-25;stama->z=0;
		}
		//エネルギーが上がってくると撃てる弾２
		if(sjiki->raigeki >55){
			stama=(STAMA *)task.MakeTask ("tama5init",tama5_init,0x50d1,NO_TASK);
			stama->x =sjiki->x-12;stama->y =sjiki->y-25;stama->z=0;	
			stama=(STAMA *)task.MakeTask ("tama6init",tama6_init,0x50d1,NO_TASK);
			stama->x =sjiki->x+14;stama->y =sjiki->y-25;stama->z=0;
		}
		//発射グラフィック
		task.ChildMakeTask ("ktama",k_tama,0x5210,NO_TASK);
		//次撃てる弾までのカウント
		sjiki->t_cnt =3;
	}
	if(((GetAsyncKeyState('Z')&0x8000)==0)){
		z_key=0;
	}
	////////////サンダー//////////////
	if((GetAsyncKeyState('X')&0x8000)&&(sjiki->tha_flag==0)&&(z_key==0)){
		if(x_key==0){task.ChildMakeTask ("syou",syou,0xfffc,NO_TASK);x_key=1;}
		sjiki->raigeki +=0.3f;
	}
	if(((GetAsyncKeyState('X')&0x8000)==0)&&(sjiki->tha_flag ==0)&&(z_key==0)){
		if(x_key==1){
			sjiki->tha_bai=(char)sjiki->raigeki/7;
			sjiki->tha_flag =1;
			sjiki->raigeki =0;
		}
		x_key=0;
	}

	//サンダーをだす
	if(sjiki->tha_flag ==1){
		if(thander_make(sjiki))sjiki->tha_flag =0;
	}

	///////十字キー//////////
	if(GetAsyncKeyState(VK_UP)&0x8000){sjiki->y-=3;}
	if(GetAsyncKeyState(VK_DOWN)&0x8000){sjiki->y+=3;}
	if(GetAsyncKeyState(VK_LEFT)&0x8000){sjiki->x-=3;sjiki->g_cnt--;}
	if(GetAsyncKeyState(VK_RIGHT)&0x8000){sjiki->x+=3;sjiki->g_cnt++;}

	////////////当り判定////////////
	TCB *Active=(TCB *)task.ActiveTop ();
	STEKI *steki;
	//敵を調べる
	while(Active->next !=NULL){
		//敵で自機タスクならば
		if((Active->type ==ENEMY_TASK)&&(sjiki->flag ==0)){
			//敵のワークスペースを返す
			steki=(STEKI *)Active->work;
			//その敵との当り判定
			if(HitCheck(sjiki->x-(sjiki->w>>1),sjiki->y-(sjiki->h>>1),0,sjiki->w,sjiki->h,steki->x-(steki->w>>1),steki->y-(steki->h>>1),steki->z,steki->w,steki->h)){
				sjiki->flag =1;
				sjiki->shield --;
			}
		}
		Active=Active->next ;
	}
	//シールド数に変化があると
	if(sjiki->shield_h !=sjiki->shield){
		sjiki->flag =1;
		sjiki->m_cnt =0;
		sjiki->toumei =0;
		if(sjiki->shield <0){
			task.KillTask ();
			return;	
		}	
		//自機点滅タスクをメイク
		task.ChildMakeTask("jiki_t",jiki_t,0x5220,NO_TASK);	
		task.ChildMakeTask("jiki_sde",jiki_sde_init,0x5230,NO_TASK);
		//当れば音を鳴らす
		sound.Play (17,sjiki->x);
	}
	sjiki->shield_h =sjiki->shield;
}
/////////////////////////////////////////////////////////////////
/////////////////////////照準関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//照準を拡大しながら描画
void syou(void){
	static int s=50;
	if(s<0)s=0;
	//×印
	RECT rect={146,87,159,100};
	draw.TDClipBlt(0,96,54,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	draw.TDClipBlt(0,214,54,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	draw.TDClipBlt(0,96,174,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	draw.TDClipBlt(0,214,174,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	//左右
	SetRect(&rect,196,61,207,165);
	draw.TDClipBlt(0,40,136,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,207,61,218,165);
	draw.TDClipBlt(0,269,136,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,218,61,229,165);
	draw.TDClipBlt(0,40,0,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,229,61,240,165);
	draw.TDClipBlt(0,269,0,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	//上下
	SetRect(&rect,110,100,196,109);
	draw.TDClipBlt(0,51,3,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,110,109,196,118);
	draw.TDClipBlt(0,179,3,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,110,118,196,127);
	draw.TDClipBlt(0,51,231,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rect,110,127,196,136);
	draw.TDClipBlt(0,179,231,s,145,120,1,rect,DDBLT_KEYSRC|DDBLT_WAIT);
	s-=10;
	if((GetAsyncKeyState('X')&0x8000)==0){s=50;task.KillTask ();}
}
/////////////////////////////////////////////////////////////////
/////////////////////詳細表示関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//後ろのデジタル縞模様
void sub_title_init(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//初期設定
	ssub->tomeido =12;
	ssub->time =90;
	//表示関数へチェンジ
	task.ChangeTask ("subtitle",sub_title1);
}
//表示関数1
void sub_title1(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//バックのデジタルレクト
	RECT rc={0,0,240,128};
	//表示止めようかな関数へ
	if(ssub->time <0){ssub->time =0;task.ChangeTask ("subtitle2",sub_title2);}
	//時間がくれば子タスク生成
	if(ssub->time ==80)task.ChildMakeTask ("",sub1_init,0xfffe,NO_TASK);
	if(ssub->time ==70)task.ChildMakeTask ("",sub2_init,0xfffe,NO_TASK);
	if(ssub->time ==60)task.ChildMakeTask ("",sub3_init,0xfffe,NO_TASK);
	//半透明転送
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	ssub->time --;	
}
//表示止めようかな関数
void sub_title2(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//バックのデジタルレクト
	RECT rc={0,0,240,128};
	//明るさ絶好調　次へ！
	if(ssub->tomeido <5){task.ChangeTask ("subtitle3",sub_title3);}
	//半透明転送
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	//透明度を変え、明るく。
	ssub->tomeido--;
}
//デジタル表示終了関数
void sub_title3(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//バックのデジタルレクト
	RECT rc={0,0,240,128};
	//透明度が一定まで来るとキル
	if(ssub->tomeido >8){task.KillTask ();}
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	//透明度下げ。
	ssub->tomeido++;
}
//文字列１初期設定
void sub1_init(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//初期設定
	SetRect(&ssub->rc,0,128,105,144);
	ssub->tomeido =12;
	ssub->time =80;
	ssub->x2 =120;
	ssub->y2 =40;
	ssub->w =1;
	ssub->h =1;
	//次へチェンジ
	task.ChangeTask ("sub1",sub_1);
}
//文字列２初期設定
void sub2_init(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//初期設定
	SetRect(&ssub->rc ,0,144,203,162);
	ssub->tomeido =12;
	ssub->time =70;
	ssub->x2 =160;
	ssub->y2 =60;
	ssub->w =1;
	ssub->h =1;
	//次へチェンジ
	task.ChangeTask ("sub1",sub_1);
}
//文字列３初期設定
void sub3_init(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//初期設定
	SetRect(&ssub->rc,0,161,107,227);	
	ssub->tomeido =12;
	ssub->time =60;
	ssub->x2 =160;
	ssub->y2 =110;
	ssub->w =1;
	ssub->h =1;
	//次へチェンジ
	task.ChangeTask ("sub1",sub_1);
}
//文字列を透明度変更で出現
void sub_1(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//透明度が一定まで来るとチェンジ
	if(ssub->tomeido <10)task.ChangeTask ("sub32",sub_2);
	draw.AlphaBltFastCenter(0,ssub->x2,ssub->y2,4,ssub->rc,ssub->tomeido ,1);
	ssub->tomeido--;
}
//時間が来るまで表示
void sub_2(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//出ている時間が来るとチェンジ
	if(ssub->time <0)task.ChangeTask ("sub33",sub_3);
	draw.ClipBltCenter(0,ssub->x2,ssub->y2,ssub->w,ssub->h,4,ssub->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	ssub->time --;
}
//拡縮で文字列消去
void sub_3(void){
	//サブタイトルワークスペース
	SSUB *ssub=(SSUB *)task.workspace ();
	//拡縮率が一定まで来るとキル
	if(ssub->h<0)task.KillTask ();
	draw.ClipBltCenter(0,ssub->x2,ssub->y2,ssub->w,ssub->h,4,ssub->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	ssub->w+=0.020f;
	ssub->h-=0.1f;
}
/////////////////////////////////////////////////////////////////
/////////////////////ボス詳細表示関数////////////////////////////
/////////////////////////////////////////////////////////////////
//後ろのデジタル縞模様
void sub_title_init2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	ssub->tomeido =12;
	ssub->time =90;
	//表示関数へチェンジ
	task.ChangeTask ("subtitle",sub2_title1);
}
//表示関数1
void sub2_title1(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	//表示止めようかな関数へ
	if(ssub->time <0){ssub->time =0;task.ChangeTask ("subtitle2",sub2_title2);}
	//時間がくれば子タスク生成
	if(ssub->time ==80)task.ChildMakeTask ("",sub1_init2,0xfffe,NO_TASK);
	if(ssub->time ==70)task.ChildMakeTask ("",sub2_init2,0xfffe,NO_TASK);
	if(ssub->time ==60)task.ChildMakeTask ("",sub3_init2,0xfffe,NO_TASK);
	RECT rc={0,0,240,128};
	//半透明転送
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	ssub->time --;	
}
//表示止めようかな関数
void sub2_title2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	//明るさ絶好調　次へ！
	if(ssub->tomeido <5){task.ChangeTask ("subtitle3",sub2_title3);}
	RECT rc={0,0,240,128};
	//半透明転送
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	//透明度を変え、明るく。
	ssub->tomeido--;
}
//デジタル表示終了関数
void sub2_title3(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	if(ssub->tomeido >8){task.KillTask ();}
	RECT rc={0,0,240,128};
	draw.AlphaBltFast(0,40,20,4,rc,ssub->tomeido,1);
	//透明度下げ。
	ssub->tomeido++;
}
//文字列１初期設定
void sub1_init2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	SetRect(&ssub->rc,0,128,205,144);
	ssub->tomeido =12;
	ssub->time =80;
	ssub->x2 =160;
	ssub->y2 =40;
	ssub->w =1;
	ssub->h =1;
	task.ChangeTask ("sub1",sub_1);
}
//文字列２初期設定
void sub2_init2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	SetRect(&ssub->rc ,0,144,135,162);
	ssub->tomeido =12;
	ssub->time =70;
	ssub->x2 =190;
	ssub->y2 =60;
	ssub->w =1;
	ssub->h =1;
	task.ChangeTask ("sub1",sub_1);
}
//文字列３初期設定
void sub3_init2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	SetRect(&ssub->rc,0,161,107,227);	
	ssub->tomeido =12;
	ssub->time =60;
	ssub->x2 =160;
	ssub->y2 =110;
	ssub->w =1;
	ssub->h =1;
	task.ChangeTask ("sub1",sub_1);
}
//文字列を透明度変更で出現
void sub2_1(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	if(ssub->tomeido <10)task.ChangeTask ("sub32",sub_2);
	draw.AlphaBltFastCenter(0,ssub->x2,ssub->y2,4,ssub->rc,ssub->tomeido ,1);
	ssub->tomeido--;
}
//時間が来るまで表示
void sub2_2(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	if(ssub->time <0)task.ChangeTask ("sub33",sub_3);
	draw.ClipBltCenter(0,ssub->x2,ssub->y2,ssub->w,ssub->h,4,ssub->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	ssub->time --;
}
//拡縮で文字列消去
void sub2_3(void){
	SSUB *ssub=(SSUB *)task.workspace ();
	if(ssub->h<0)task.KillTask ();
	draw.ClipBltCenter(0,ssub->x2,ssub->y2,ssub->w,ssub->h,4,ssub->rc,DDBLT_KEYSRC|DDBLT_WAIT);
	ssub->w+=0.020f;
	ssub->h-=0.1f;
}
/////////////////////////////////////////////////////////////////
/////////////////////詳細表示関数////////////////////////////////
/////////////////////////////////////////////////////////////////
void tensu(void){
	STEN *sten=(STEN *)task.workspace ();
	//点数
	RECT tensu_rc[10]={{197,200,201,208},{201,200,205,208},{209,200,213,208},{213,200,217,208},{217,200,221,208},{221,200,225,208},{225,200,229,208},{229,200,233,208},{233,200,237,208}};
	RECT tensu_rc2={237,200,240,208};
	char t_cnt,c_cnt;
	if(sten->cnt>20){
		score+=sten->bai *sten->tensu ;
		task.KillTask ();
		return;
	}
	char text[10];
	wsprintf(text,"%d",sten->tensu );
	char j=strlen(text);
	//点数を描画
	for(t_cnt=j-1,c_cnt=0;t_cnt>=0;t_cnt--,c_cnt++){
		switch (text[t_cnt]){
		case '0':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50,140,120,1,tensu_rc[0],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '1':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[1],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '2':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50,140,120,1,tensu_rc[2],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '3':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50,140,120,1,tensu_rc[3],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '4':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[4],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '5':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[5],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '6':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[6],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '7':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[7],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '8':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[8],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '9':
			draw.TDBlt ( 5,sten->x-c_cnt*6-6,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[9],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		}
	}
	//掛けるの表示
	draw.TDBlt ( 5,sten->x,sten->y-sten->cnt ,50,140,120,1,tensu_rc2,DDBLT_KEYSRC|DDBLT_WAIT);
	wsprintf(text,"%d",sten->bai);
	j=strlen(text);
	//倍数を描画
	for(t_cnt=j-1,c_cnt=0;t_cnt>=0;t_cnt--,c_cnt++){
		switch (text[t_cnt]){
		case '0':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[0],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '1':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[1],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '2':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[2],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '3':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[3],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '4':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[4],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '5':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[5],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '6':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[6],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '7':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[7],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '8':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[8],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		case '9':
			draw.TDBlt ( 5,sten->x-c_cnt*6+18,sten->y-sten->cnt ,50 ,140,120,1,tensu_rc[9],DDBLT_KEYSRC|DDBLT_WAIT);
			break;
		}
	}
	sten->cnt++;
}
/////////////////////////////////////////////////////////////////
/////////////////////詳細表示関数////////////////////////////////
/////////////////////////////////////////////////////////////////
//詳細設定
void syousai_init(void){
	SSYOU *ssyou=(SSYOU *)task.workspace ();
	ssyou->y =18;
	//時間がくれば次へ
	task.ChangeTask ("syousai",syousai);
}
//上下から出現
void syousai(void){
	SJIKI *sjiki=(SJIKI *)ji();
	SSYOU *ssyou=(SSYOU *)task.workspace ();
	//上下からだす
	ssyou->y--;
	//現状維持
	if(ssyou->y<0)ssyou->y=0;

	/////////////////////////////////////上部分///////////////////////////////////////////
	RECT rc={99,0,240,18};
	draw.AlphaBltFast(0,139,0-ssyou->y ,2,rc,0,0);
	//金属部分
	SetRect(&rc,78,67,119,75);
	draw.ClipBltFast (0,137,0-ssyou->y ,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,121,67,127,84);
	draw.ClipBltFast (0,274,0-ssyou->y ,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//残機
	RECT zanki_rc={132,85,146,100};
	for(int i=0;i<sjiki->zanki ;i++)
		draw.ClipBltFast (0,40+i*18,0-ssyou->y ,1,zanki_rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//点数
	RECT tensu_rc[10]={{0,88,12,100},{12,88,24,100},{24,88,36,100},{36,88,48,100},{48,88,60,100},{60,88,72,100},{72,88,84,100},{84,88,96,100},{96,88,108,100},{108,88,120,100}};
	RECT tensu_rc2={120,88,132,100};
	char text[10];
	wsprintf(text,"%d",score);
	char j=strlen(text);
	//点数を描画
	for(char t_cnt=j-1,c_cnt=0;t_cnt>=0;t_cnt--,c_cnt++){
		switch (text[t_cnt]){
		case '0':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[0],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '1':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[1],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '2':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[2],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '3':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[3],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '4':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[4],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '5':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[5],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '6':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[6],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '7':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[7],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '8':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[8],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		case '9':
			draw.ClipBltFast (0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc[9],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
			break;
		}
	}
	//残りのゼロを描画
	for(;c_cnt<8;c_cnt++)	
		draw.AlphaBltFast(0,262-c_cnt*12,0-ssyou->y ,1,tensu_rc2,11,1);
	//////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////下部分///////////////////////////////////////////
	SetRect(&rc,0,18,240,34);
	draw.AlphaBltFast (0,40,224+ssyou->y ,2,rc,0,0);
	//金属部分
	SetRect(&rc,0,79,79,88);
	draw.ClipBltFast (0,40,230+ssyou->y,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,79,83,106,88);
	draw.ClipBltFast (0,40,225+ssyou->y,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,79,83,106,88);
	draw.ClipBltFast (0,40,225+ssyou->y,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	SetRect(&rc,79,78,102,83);
	draw.ClipBltFast (0,220,233+ssyou->y,1,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//シールド
	static char cnt=4;
	RECT shield_rc1[5]={{153,64,156,77},{156,64,159,77},{162,64,165,77},{165,64,168,77},{168,64,171,77}};
	RECT shield_rc2[5]={{134,64,137,77},{137,64,140,77},{140,64,143,77},{143,64,147,77},{147,64,150,77}};
	for(i=0;i<sjiki->shield ;i++){
		if(cnt<0)cnt=4;
		if(i>1)
			draw.ClipBltFast (0,274-i*4,226+ssyou->y,1,shield_rc2[cnt],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
		else
			draw.ClipBltFast (0,274-i*4,226+ssyou->y,1,shield_rc1[cnt],DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
		cnt--;
	}
	//雷刀、雷撃
	RECT raigeki_rc={4,73,4+(int)sjiki->raigeki ,79};
	draw.ClipBltFast (0,44,230+(int)ssyou->y,1,raigeki_rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//////////////////////////////////////////////////////////////////////////////////////
}
