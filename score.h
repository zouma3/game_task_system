///////////////////////////////////////////////////////////////////////////
//		ÉXÉRÉAï\é¶Å@Çg
//								    Programmed by éGï~Å@ê≥éj				
///////////////////////////////////////////////////////////////////////////

#ifndef _score_
#define _score_

extern void title_init(void);

void s_cls(void);
void s_cls2(void);

void s_back(void);

void score_ini(void);
void score_1(void);
void score_2(void);
void score_3(void);
void score_4(void);

void score_c_00(void);
void score_c_01(void);
void score_c_02(void);
void score_c_03(void);
void score_c_04(void);

void score_c_100(void);
void score_c_90(void);
void score_c_80(void);
void score_c_70(void);
void score_c_60(void);
void score_c_50(void);
void score_c_40(void);
void score_c_30(void);
void score_c_20(void);
void score_c_10(void);

void score_c_1(void);
void score_c_2(void);
void score_c_3(void);

typedef struct{
	unsigned int name[8];
	unsigned long score;
}SSCR;
typedef struct{
	int x,y;
	int no;
	int time;
}STIME;

#endif _score_
