#ifndef _game_
#define _game_

//構造体シリーズ
//自機構造体
typedef struct{
	int x,y;//ｘ、ｙ座標
	short w,h;//幅
	char flag;//生死フラグ
	short	sx;//画面の中心
	char t;//登場するとき
	float s;//登場するとき
	char zanki;//残機
	char shield;//シールド数
	char shield_h;//変化用
	float raigeki;//雷撃エネルギー
	char g_cnt;//グラフィックの位置
	char tha_cnt;//サンダーのカウント
	char tha_flag;//サンダーのフラグ
	char tha_bai;//サンダーの倍数
	char t_cnt;//次の弾までのカウント
	char m_cnt;//無敵のカウント
	char toumei;//半透明率
	short cnt;//予備
}SJIKI;
//敵構造体
typedef struct{
	int x,y,z;//ｘ、ｙ座標
	short px,py;
	unsigned int w,h;//横幅、縦幅
	unsigned int jikan;//出現時間
	RECT rc;//敵レクト
	char speed;//移動量
	char dir;//角度
	char angle_temp;
	char angle;//向き
	short hp;//ヒットポイント
	short gra_cnt;//現在のグラフィック
	short kind;//敵の種類
	char change;//チェンジフラグ
	short score;//敵自体の点数
	short t_cnt;//弾を撃つカウント
	short baku_cnt;//弾を撃つカウント
	char lock;
	char cnt;//予備
	char cnt2;//予備
}STEKI;
//爆発構造体
typedef struct{
	//位置関係
	int x,y,z;//座標
	float sx;//拡大率
	float sy;//拡大率
	float psx;//拡大率プラス
	float psy;//拡大率プラス
	char dir;//方向
	char z_dir;//ｚ軸移動量
	char kind;//爆発の種類
	char speed;//速さ
	char toumei;//透明度
	char cnt;//予備
	char cnt2;//予備
}SBOMB;
//飾り構造体
typedef struct{
	char y;//グラフィックの位置
}SSYOU;
//サブタイトル構造体
typedef struct{
	char tomeido;//透明度
	char time;//時間
	RECT rc;//レクト
	short x2,y2;//座標
	float w;//幅（拡大率）
	float h;//幅（拡大率）
}SSUB;
//雷撃構造体
typedef struct{
	int x,y,z;//ｘ、ｙ座標
	unsigned int w,h;//横幅、縦幅
	char angle;//角度
	char dir;//自機へ
	char kyori;//移動距離
	char kind;//種類 
	int cnt;//予備
}STHA;
//弾構造体
typedef struct{
	int x,y,z;//ｘ、ｙ座標
	unsigned int w,h;//横幅、縦幅
	char angle;//角度
	char dir;//自機へ
	char kyori;//移動距離
	RECT rc;//グラフィックのレクト
	char g_cnt;//グラフィックの位置
	char kind;//種類 
	char hp;//
	float s;//拡大率
	short cnt;//予備
	short cnt2;//予備
	short tensu;
}STAMA;
//弾が当った後処理
typedef struct{
	int x,y,z;//ｘ、ｙ座標
	char cnt;//グラフィックの位置
	char cnt2;//予備
}SLOCK;
//弾が当った後処理
typedef struct{
	int x,y;//ｘ、ｙ座標
	RECT rc;//グラフィックのレクト
	char g_cnt;//グラフィックの位置
}SKAGE;
//背景
typedef struct{
	int y;//スクロール用
	int z;//高さ；	
}SHAI;
//背景
typedef struct{
	int map_cnt;
	int map_cnt2;
	int z;//高さ；	
}SMAP;
//背景
typedef struct{
	int cnt;//出ている時間	
}SSDE;
//点数表示
typedef struct{
	int x,y,z;//表示位置
	int tensu;//点数
	char bai;//倍数
	char cnt;//出ている時間
}STEN;
typedef struct{
	unsigned int jika;//出ている時間	
}SJI;

//プロトタイプ宣言
//弾関係
void tama1_init(void);
void tama2_init(void);
void tama3_init(void);
void tama4_init(void);
void tama5_init(void);
void tama6_init(void);
void k_tama(void);
void tama_idou(void);
//弾関係
void thander_init(void);
void thander(void);
//自機関係
void jiki_init(void);
void jiki_init1(void);
void jiki_init2(void);
void jiki_0(void);
void jiki(void);
void jiki_t(void);
void jiki_s1(void);
void jiki_s2(void);
//当った関係
void jiki_sde_init(void);
void jiki_sde(void);
//照準関係
void syou(void);
//サブタイトル関係
void sub_title_init(void);
void sub_title1(void);
void sub_title2(void);
void sub_title3(void);
void sub1_init(void);
void sub2_init(void);
void sub3_init(void);
void sub_1(void);
void sub_2(void);
void sub_3(void);
//サブボスタイトル関係
void sub_title_init2(void);
void sub2_title1(void);
void sub2_title2(void);
void sub2_title3(void);
void sub1_init2(void);
void sub2_init2(void);
void sub3_init2(void);
void sub2_1(void);
void sub2_2(void);
void sub2_3(void);
//詳細表示関係
void syousai_init(void);
void syousai(void);
//背景関係
void back(void);
void scrool0(void);
void scrool1(void);
void scrool1_init(void);
void scrool1_1(void);
void scrool1_2(void);
void scrool1_2_init(void);
void scrool2_ini(void);
void scrool2(void);
void scrool3_ini(void);
void scrool3(void);

void scrool4_init(void);
void scrool4_1(void);

void scrool1_1(void);
void scrool2_init(void);
void scrool2_1(void);
void scrool3_init(void);
void scrool3_1(void);

void map_flip(void);

//敵関係
//敵弾イニシャライズ
void t_tama_init(void);
//敵弾1
void t_tama1(void);
void t_tama2(void);
void t_tama3(void);
void t_tama4_1(void);
void t_tama4_2(void);
void t_tama5(void);

void t_tama6(void);
void t_tama6_1(void);
void t_tama6_2(void);
void t_tama6_3(void);


void t_tama8(void);
void t_tama9(void);
void t_tama10(void);
void t_tama11(void);
void t_tama12_1(void);
void t_tama12_2(void);
void t_tama13(void);
void t_tama14(void);

//敵攻撃パターン
char t_tama_pa1(STEKI *steki,STEKI *steki2);
char t_tama_pa2(STEKI *steki);
char t_tama_pa3(STEKI *steki);
char t_tama_pa4(STEKI *steki);
char t_tama_pa5(STEKI *steki);
char t_tama_pa6(STEKI *steki);
char t_tama_pa7(STEKI *steki);
char t_tama_pa8(STEKI *steki);
char t_tama_pa9(STEKI *steki);
char t_tama_pa10(STEKI *steki);
char t_tama_pa11(STEKI *steki);

////////////敵出現用///////////
void teki(void);
//敵１
void teki1_init(void);
void teki1(void);
void teki1_1(void);
void teki1_2(void);
//敵２
void teki2_init(void);
void teki2(void);
void teki2_1(void);
void teki2_2(void);
//敵３
void teki3_init(void);
void teki3(void);
void teki3_1(void);
void teki3_2(void);
//敵３の子供
void teki3_c_1_init(void);
void teki3_c_2_init(void);
void teki3_c(void);
void teki3_c_1(void);
void teki3_c_2(void);
void teki3_c_3(void);
void teki3_c_4(void);
void teki3_c_5(void);
void teki3_c_6(void);
//敵４
void teki4_init(void);
void teki4(void);
void teki4_1(void);
//敵５
void teki5_init(void);
void teki5(void);
void teki5_1(void);
void teki5_2(void);
void teki5_3(void);
void teki5_4(void);
//敵６
void teki6_init(void);
void teki6(void);
void teki6_1(void);
void teki6_2(void);
void teki6_3(void);
void teki6_4(void);
//敵７
void teki7_init(void);
void teki7(void);
void teki7_1(void);
//敵８
void teki8_init(void);
void teki8(void);
void teki8_1(void);
void teki8_2(void);
//敵８の子供
void teki8_c_init(void);
void teki8_c(void);
void teki8_c_1(void);
void teki8_c_2(void);
void teki8_c_3(void);
void teki8_c_4(void);
void teki8_c_5(void);
void teki8_c_6(void);
//敵９
void teki9_init(void);
void teki9(void);
void teki9_1(void);
//敵１０
void teki10_init(void);
void teki10(void);
void teki10_1(void);
void teki10_2(void);
void teki10_3(void);
//敵１１
void teki11_init(void);
void teki11(void);
void teki11_1(void);
void teki11_2(void);
void teki11_3(void);
//敵１２
void teki12_init(void);
void teki12(void);
void teki12_1(void);
void teki12_2(void);
void teki12_3(void);
//敵１３
void teki13_init(void);
void teki13(void);
void teki13_1(void);
void teki13_2(void);
void teki13_3(void);
//敵１４
void teki14_init(void);
void teki14(void);
void teki14_1(void);
void teki14_2(void);
void teki14_3(void);
//敵１５
void teki15_init(void);
void teki15(void);
void teki15_1(void);
void teki15_2(void);
void teki15_3(void);
//敵１６
void teki16_init(void);
void teki17_init(void);
void teki16(void);
void teki16_1(void);
void teki16_2(void);
//敵１６の子供
void teki16_c_1_init(void);
void teki16_c_2_init(void);
void teki16_c(void);
void teki16_c2(void);
void teki16_c_1(void);
void teki16_c_2(void);
void teki16_c_3(void);
void teki16_c_4(void);
void teki16_c_5(void);
void teki16_c_6(void);

//敵１９
void teki19_init(void);
void teki19(void);
void teki19_1(void);
void teki19_2(void);
void teki19_3(void);
void teki19_4(void);
void teki19_5(void);
void teki19_6(void);
void teki19_7(void);
void teki19_8(void);
void teki19_9(void);
void teki19_10(void);
//敵１９の子供
void teki19_c_init(void);
void teki19_c(void);
void teki19_c2(void);
void teki19_c1_init(void);
void teki19_c2_init(void);
void teki19_c_1(void);
void teki19_c_2(void);
//敵２０
void teki20_init(void);
void teki20(void);
void teki20_0(void);
void teki20_1(void);
void teki20_2(void);
void teki20_3(void);
void teki20_4(void);
void teki20_5(void);
void teki20_6(void);
void teki20_7(void);
void teki20_8(void);
void teki20_9(void);
void teki20_10(void);
void teki20_11(void);
void teki20_12(void);
void teki20_13(void);
void teki20_14(void);
void teki20_15(void);
//敵２０の子供
void teki20_c_init(void);
void teki20_c(void);
void teki20_c2(void);
void teki20_c1_init(void);
void teki20_c2_init(void);
void teki20_c_0(void);
void teki20_c_1(void);
void teki20_c_2(void);

/////////爆発//////////
void bomb_init(void);
void bomb1(void);
void bomb2(void);
void bomb3(void);
void bomb4(void);
void bomb5(void);
void bomb6(void);

//判定関係
void jiki_hantei(int x,int y,int z,int w,int h);
void jiki_hantei2(int x,int y,int z,int w,int h);
void hantei_rai(int x,int y,int z,int w,int h);
void hantei(int x,int y,int z,int w,int h);

//システム関係
void tensu(void);
void sys_init(void);
void timer(void);
void b_o(void);
void b_o2(void);
void game_term(void);
void *ji(void);
void rimito(int x,int y,int z);
void z_prio(int z);
void z_prio2(int z);

#endif _game_
