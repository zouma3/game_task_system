#ifndef _game_
#define _game_

//�\���̃V���[�Y
//���@�\����
typedef struct{
	int x,y;//���A�����W
	short w,h;//��
	char flag;//�����t���O
	short	sx;//��ʂ̒��S
	char t;//�o�ꂷ��Ƃ�
	float s;//�o�ꂷ��Ƃ�
	char zanki;//�c�@
	char shield;//�V�[���h��
	char shield_h;//�ω��p
	float raigeki;//�����G�l���M�[
	char g_cnt;//�O���t�B�b�N�̈ʒu
	char tha_cnt;//�T���_�[�̃J�E���g
	char tha_flag;//�T���_�[�̃t���O
	char tha_bai;//�T���_�[�̔{��
	char t_cnt;//���̒e�܂ł̃J�E���g
	char m_cnt;//���G�̃J�E���g
	char toumei;//��������
	short cnt;//�\��
}SJIKI;
//�G�\����
typedef struct{
	int x,y,z;//���A�����W
	short px,py;
	unsigned int w,h;//�����A�c��
	unsigned int jikan;//�o������
	RECT rc;//�G���N�g
	char speed;//�ړ���
	char dir;//�p�x
	char angle_temp;
	char angle;//����
	short hp;//�q�b�g�|�C���g
	short gra_cnt;//���݂̃O���t�B�b�N
	short kind;//�G�̎��
	char change;//�`�F���W�t���O
	short score;//�G���̂̓_��
	short t_cnt;//�e�����J�E���g
	short baku_cnt;//�e�����J�E���g
	char lock;
	char cnt;//�\��
	char cnt2;//�\��
}STEKI;
//�����\����
typedef struct{
	//�ʒu�֌W
	int x,y,z;//���W
	float sx;//�g�嗦
	float sy;//�g�嗦
	float psx;//�g�嗦�v���X
	float psy;//�g�嗦�v���X
	char dir;//����
	char z_dir;//�����ړ���
	char kind;//�����̎��
	char speed;//����
	char toumei;//�����x
	char cnt;//�\��
	char cnt2;//�\��
}SBOMB;
//����\����
typedef struct{
	char y;//�O���t�B�b�N�̈ʒu
}SSYOU;
//�T�u�^�C�g���\����
typedef struct{
	char tomeido;//�����x
	char time;//����
	RECT rc;//���N�g
	short x2,y2;//���W
	float w;//���i�g�嗦�j
	float h;//���i�g�嗦�j
}SSUB;
//�����\����
typedef struct{
	int x,y,z;//���A�����W
	unsigned int w,h;//�����A�c��
	char angle;//�p�x
	char dir;//���@��
	char kyori;//�ړ�����
	char kind;//��� 
	int cnt;//�\��
}STHA;
//�e�\����
typedef struct{
	int x,y,z;//���A�����W
	unsigned int w,h;//�����A�c��
	char angle;//�p�x
	char dir;//���@��
	char kyori;//�ړ�����
	RECT rc;//�O���t�B�b�N�̃��N�g
	char g_cnt;//�O���t�B�b�N�̈ʒu
	char kind;//��� 
	char hp;//
	float s;//�g�嗦
	short cnt;//�\��
	short cnt2;//�\��
	short tensu;
}STAMA;
//�e���������㏈��
typedef struct{
	int x,y,z;//���A�����W
	char cnt;//�O���t�B�b�N�̈ʒu
	char cnt2;//�\��
}SLOCK;
//�e���������㏈��
typedef struct{
	int x,y;//���A�����W
	RECT rc;//�O���t�B�b�N�̃��N�g
	char g_cnt;//�O���t�B�b�N�̈ʒu
}SKAGE;
//�w�i
typedef struct{
	int y;//�X�N���[���p
	int z;//�����G	
}SHAI;
//�w�i
typedef struct{
	int map_cnt;
	int map_cnt2;
	int z;//�����G	
}SMAP;
//�w�i
typedef struct{
	int cnt;//�o�Ă��鎞��	
}SSDE;
//�_���\��
typedef struct{
	int x,y,z;//�\���ʒu
	int tensu;//�_��
	char bai;//�{��
	char cnt;//�o�Ă��鎞��
}STEN;
typedef struct{
	unsigned int jika;//�o�Ă��鎞��	
}SJI;

//�v���g�^�C�v�錾
//�e�֌W
void tama1_init(void);
void tama2_init(void);
void tama3_init(void);
void tama4_init(void);
void tama5_init(void);
void tama6_init(void);
void k_tama(void);
void tama_idou(void);
//�e�֌W
void thander_init(void);
void thander(void);
//���@�֌W
void jiki_init(void);
void jiki_init1(void);
void jiki_init2(void);
void jiki_0(void);
void jiki(void);
void jiki_t(void);
void jiki_s1(void);
void jiki_s2(void);
//�������֌W
void jiki_sde_init(void);
void jiki_sde(void);
//�Ə��֌W
void syou(void);
//�T�u�^�C�g���֌W
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
//�T�u�{�X�^�C�g���֌W
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
//�ڍו\���֌W
void syousai_init(void);
void syousai(void);
//�w�i�֌W
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

//�G�֌W
//�G�e�C�j�V�����C�Y
void t_tama_init(void);
//�G�e1
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

//�G�U���p�^�[��
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

////////////�G�o���p///////////
void teki(void);
//�G�P
void teki1_init(void);
void teki1(void);
void teki1_1(void);
void teki1_2(void);
//�G�Q
void teki2_init(void);
void teki2(void);
void teki2_1(void);
void teki2_2(void);
//�G�R
void teki3_init(void);
void teki3(void);
void teki3_1(void);
void teki3_2(void);
//�G�R�̎q��
void teki3_c_1_init(void);
void teki3_c_2_init(void);
void teki3_c(void);
void teki3_c_1(void);
void teki3_c_2(void);
void teki3_c_3(void);
void teki3_c_4(void);
void teki3_c_5(void);
void teki3_c_6(void);
//�G�S
void teki4_init(void);
void teki4(void);
void teki4_1(void);
//�G�T
void teki5_init(void);
void teki5(void);
void teki5_1(void);
void teki5_2(void);
void teki5_3(void);
void teki5_4(void);
//�G�U
void teki6_init(void);
void teki6(void);
void teki6_1(void);
void teki6_2(void);
void teki6_3(void);
void teki6_4(void);
//�G�V
void teki7_init(void);
void teki7(void);
void teki7_1(void);
//�G�W
void teki8_init(void);
void teki8(void);
void teki8_1(void);
void teki8_2(void);
//�G�W�̎q��
void teki8_c_init(void);
void teki8_c(void);
void teki8_c_1(void);
void teki8_c_2(void);
void teki8_c_3(void);
void teki8_c_4(void);
void teki8_c_5(void);
void teki8_c_6(void);
//�G�X
void teki9_init(void);
void teki9(void);
void teki9_1(void);
//�G�P�O
void teki10_init(void);
void teki10(void);
void teki10_1(void);
void teki10_2(void);
void teki10_3(void);
//�G�P�P
void teki11_init(void);
void teki11(void);
void teki11_1(void);
void teki11_2(void);
void teki11_3(void);
//�G�P�Q
void teki12_init(void);
void teki12(void);
void teki12_1(void);
void teki12_2(void);
void teki12_3(void);
//�G�P�R
void teki13_init(void);
void teki13(void);
void teki13_1(void);
void teki13_2(void);
void teki13_3(void);
//�G�P�S
void teki14_init(void);
void teki14(void);
void teki14_1(void);
void teki14_2(void);
void teki14_3(void);
//�G�P�T
void teki15_init(void);
void teki15(void);
void teki15_1(void);
void teki15_2(void);
void teki15_3(void);
//�G�P�U
void teki16_init(void);
void teki17_init(void);
void teki16(void);
void teki16_1(void);
void teki16_2(void);
//�G�P�U�̎q��
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

//�G�P�X
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
//�G�P�X�̎q��
void teki19_c_init(void);
void teki19_c(void);
void teki19_c2(void);
void teki19_c1_init(void);
void teki19_c2_init(void);
void teki19_c_1(void);
void teki19_c_2(void);
//�G�Q�O
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
//�G�Q�O�̎q��
void teki20_c_init(void);
void teki20_c(void);
void teki20_c2(void);
void teki20_c1_init(void);
void teki20_c2_init(void);
void teki20_c_0(void);
void teki20_c_1(void);
void teki20_c_2(void);

/////////����//////////
void bomb_init(void);
void bomb1(void);
void bomb2(void);
void bomb3(void);
void bomb4(void);
void bomb5(void);
void bomb6(void);

//����֌W
void jiki_hantei(int x,int y,int z,int w,int h);
void jiki_hantei2(int x,int y,int z,int w,int h);
void hantei_rai(int x,int y,int z,int w,int h);
void hantei(int x,int y,int z,int w,int h);

//�V�X�e���֌W
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
