///////////////////////////////////////////////////////////////////////////
//		�l�[���G���g���@�g
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#ifndef _entry_
#define _entry_

extern void score_init(void);

void e_cls(void);
void e_cls2(void);
void e_back(void);

void e_sele_init(void);
void e_sele(void);
void e_sele_c(void);
void e_sele_c1(void);

void bom_init(void);
void bom1(void);
void bom2(void);
void bom3(void);


void tensu(int tensu,int x,int y);
extern unsigned long score;
char cnt;

typedef struct{
	//�ʒu�֌W
	int x,y;
	//�L�[�֌W
	char key_u,key_d,key_l,key_r,key_x,key_z;
	//���O�֌W
	unsigned int name[8];
	//�o�^��
	char cnt;
}SXY;

typedef struct{
	unsigned int name[8];
	unsigned long score;
}SSC;

typedef struct{
	//�ʒu�֌W
	int x,y;
	char kind;
	//�o�^��
	char cnt;
}SBOM;



#endif _entry_
