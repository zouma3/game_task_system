#include"main.h"
#include"game_str.h"
#include"game.h"

extern unsigned long score;
extern unsigned int jikan;
extern unsigned int map_a[400][7];
extern STEKI steki_t[500];


/////////////////////////////////////////////////////////////////
/////////////////////map 操作関数////////////////////////////////
/////////////////////////////////////////////////////////////////
void back(void){
	draw.Cls(5,0,0,320,320,208);
	draw.Cls(6,0,0,320,320,253);
}
void scrool0(void){
	RECT rc;
	static float x,y;
	//背景表示
	SetRect(&rc,0,0,280,145);
	draw.ScroolBlt ( 5,&x,&y,0,0.3f,13,rc,DDBLTFAST_WAIT);
}
void scrool1_init(void){
	SMAP *smap=(SMAP *)task.workspace ();

	smap->map_cnt =0;
	smap->map_cnt2 =0;
	smap->z =0;

	task.ChangeTask ("scrl1",scrool1);
}
//一番上のマップ
void scrool1(void){
	//データからマップを作る
	RECT bg_Scr;
	SMAP *smap=(SMAP *)task.workspace ();
	int i,j,k=0;
	//リミットチェック
	if(smap->map_cnt2>=40){smap->map_cnt++;smap->map_cnt2=0;}
	if(smap->map_cnt>=400)smap->map_cnt=400;
	//マップを作業サーフェスに作成
	for(i=smap->map_cnt,k=7;i<8+smap->map_cnt;i++,k--){
		for(j=0;j<7;j++){
			unsigned int tmp1=0,tmp2=0;
			if(map_a[i][j]==0x0000)continue;
			tmp1=map_a[i][j]>>4;//上位４ビット
			tmp2=map_a[i][j]&0x000f;//下位４ビット
			SetRect(&bg_Scr,tmp1*40,tmp2*40,tmp1*40+40,tmp2*40+40);	
			draw.ClipBltFast(6,j*40,k*40,3,bg_Scr,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
		}
	}
	//範囲を擬似３Ｄ転送
	SetRect(&bg_Scr,0,40-smap->map_cnt2,320,320-smap->map_cnt2);
	draw.TDClipBlt(5,0,0,smap->z,145,120,6,bg_Scr,DDBLT_KEYSRC|DDBLT_WAIT);
	//マップのスピード
	smap->map_cnt2+=10;
	//時間がくれば、拡大し、次へ
	if(jikan>700)smap->z-=10;

	z_prio2(smap->z);
	if(smap->z==-100)task.MakeTask ("scrl2",scrool2_init,0x4000,NO_TASK);
	if(smap->z==-350)task.MakeTask ("scrl2",scrool2_init,0x4000,NO_TASK);
	if(smap->z==-500)task.ChangeTask("scrl1",scrool1_1);
}
void scrool1_1(void){
	SHAI *shai2;
	int i;
	switch(jikan){
	//金属をメイク
	case 5010:case 5020:case 5030:case 5040:case 5050:case 5060:case 5070:
		shai2=(SHAI *)task.MakeTask ("scrl4",scrool4_init,0x4100,NO_TASK);
		break;
	//ファイル読込
	case 5100:
		FILE *fp;
		fp=fopen("map1_b.dat","r");
		for(i=0;i<300;i++){
			if(fscanf(fp,"%x %x %x %x %x %x %x",&map_a[i][0],&map_a[i][1],&map_a[i][2],&map_a[i][3],&map_a[i][4],&map_a[i][5],&map_a[i][6])==EOF){
				break;
			}
		}
		fclose(fp);
		break;
	//チェンジ
	case 5110:
		task.MakeTask ("scrl0",scrool0,0x3000,NO_TASK);
		task.ChangePrio2 (0x4000);
		task.ChangeTask ("scrl1",scrool1_2_init);
		break;
	}
}
void scrool1_2_init(void){
	SMAP *smap=(SMAP *)task.workspace ();

	smap->map_cnt =0;
	smap->map_cnt2 =0;
	smap->z =0;

	task.ChangeTask ("scrl1",scrool1_2);
}
void scrool1_2(void){
	//データからマップを作る
	RECT bg_Scr;
	SMAP *smap=(SMAP *)task.workspace ();
	int i,j,k=0;
	//リミットチェック
	if(jikan==8200){
		audio.Stop ();
		sound.Play (19,140);
		draw.MakeSurface (4,"gra\\subtitle2.bmp",DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
		task.MakeTask ("subinit",sub_title_init2,0xfff0,NO_TASK);
	}
	if(jikan==8350)audio.Play (8,MM_CD_LOOPING);
	if(jikan==8600)task.KillTask ();
	if(smap->z<0)smap->z=0;
	if(smap->map_cnt2>=40){smap->map_cnt++;smap->map_cnt2=0;}
	if(smap->map_cnt>=400)smap->map_cnt=400;
	//マップを作業サーフェスに作成
	for(i=smap->map_cnt,k=7;i<8+smap->map_cnt;i++,k--){
		for(j=0;j<7;j++){
			unsigned int tmp1=0,tmp2=0;
			if(map_a[i][j]==0x0000)continue;
			tmp1=map_a[i][j]>>4;//上位４ビット
			tmp2=map_a[i][j]&0x000f;//下位４ビット
			SetRect(&bg_Scr,tmp1*40,tmp2*40,tmp1*40+40,tmp2*40+40);	
			draw.ClipBltFast(6,j*40,k*40,3,bg_Scr,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
		}
	}
	//範囲を擬似３Ｄ転送
	SetRect(&bg_Scr,0,40-smap->map_cnt2,320,320-smap->map_cnt2);
	draw.TDClipBlt(5,0,0,smap->z,145,110,6,bg_Scr,DDBLT_KEYSRC|DDBLT_WAIT);
	//マップのスピード
	smap->map_cnt2+=2;
	smap->z-=2;
}
//岩の表示
void scrool2_init(void){
	SHAI *shai=(SHAI *)task.workspace ();
	shai->z=200;
	shai->y=0;
	task.ChangePrio2 (0x4000);
	
	SHAI *shai2;
	shai2=(SHAI *)task.MakeTask ("scrl3",scrool3_1,0x4100,NO_TASK);
	shai2->y =0;shai2->z=100;
	shai2=(SHAI *)task.MakeTask ("scrl3",scrool3_1,0x4100,NO_TASK);
	shai2->y =240;shai2->z=100;
	
	task.ChangeTask ("scro2",scrool2_1);
}
void scrool2_1(void){
	SHAI *shai=(SHAI *)task.workspace ();
	RECT rc;
	//スクロール
	SetRect(&rc,0,shai->y,216,480);
	draw.BltFast(8,0,0,7,rc,DDBLTFAST_WAIT);
	SetRect(&rc,0,0,216,shai->y);
	draw.BltFast(8,0,480-shai->y,7,rc,DDBLTFAST_WAIT);
	shai->y-=10;
	if(shai->y<0)shai->y=480;
	//背景表示
	SetRect(&rc,0,0,68,480);
	draw.TDClipBltCenter ( 5,0,120,shai->z,145,120,8,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rc,68,0,136,480);
	draw.TDClipBltCenter ( 5,285,120,shai->z,145,120,8,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	shai->z -=5;
	if((jikan>5000)&&(shai->z<-60)){
		task.KillTask();
		return;
	}
	if(shai->z<-60)task.ChangeTask("scrl2",scrool2_init);
	z_prio2(shai->z);
}
//金属の横棒
void scrool3_1(void){
	SHAI *shai=(SHAI *)task.workspace ();
	RECT rc;
	shai->y+=10;
	z_prio2(shai->z);
	if(shai->y>480)task.KillTask ();
	if(shai->z <-60)task.KillTask ();
	//描画
	SetRect(&rc,0,0,280,16);
	draw.TDClipBltCenter ( 5,140,shai->y,shai->z,145,120,9,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	shai->z -=5;
}
//サイド金属の表示
void scrool4_init(void){
	SHAI *shai=(SHAI *)task.workspace ();
	shai->z=200;
	shai->y=0;
	task.ChangePrio2 (0x4000);	
	task.ChangeTask ("scrl4",scrool4_1);
}
void scrool4_1(void){
	SHAI *shai=(SHAI *)task.workspace ();
	RECT rc;
	//スクロール
	SetRect(&rc,0,shai->y,216,480);
	draw.BltFast(8,0,0,7,rc,DDBLTFAST_WAIT);
	SetRect(&rc,0,0,216,shai->y);
	draw.BltFast(8,0,480-shai->y,7,rc,DDBLTFAST_WAIT);
	shai->y-=5;
	if(shai->y<0)shai->y=480;
	//背景表示
	SetRect(&rc,136,0,176,480);
	draw.TDClipBltCenter ( 5,0,120,shai->z,145,120,8,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	SetRect(&rc,176,0,216,480);
	draw.TDClipBltCenter ( 5,285,120,shai->z,145,120,8,rc,DDBLT_KEYSRC|DDBLT_WAIT);
	shai->z -=3;
	if((jikan>5100)&&(shai->z<-60)){
		task.KillTask();
		return;
	}
	if(shai->z <-60)task.ChangeTask ("",scrool4_init);
	z_prio2(shai->z);
}

//マップ作業サーフェイスからプライマリーへ
void map_flip(void){
	//親の構造体のアドレス
	SJIKI *sjiki=(SJIKI *)ji();
	//リミットチェック
	if(sjiki->sx<0){sjiki->sx=0;}
	if(sjiki->sx>40){sjiki->sx=40;}
	//範囲の描画
	RECT rc={0+sjiki->sx,0,240+sjiki->sx,240};
	draw.ClipBltFast(0,40,0,5,rc,DDBLTFAST_SRCCOLORKEY|DDBLTFAST_WAIT);
	//プラス
	if((sjiki->x)>145)sjiki->sx+=1;
	if((sjiki->x)<135)sjiki->sx-=1;
}