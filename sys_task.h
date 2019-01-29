///////////////////////////////////////////////////////////////////////////
//		�[���^�X�N�V�X�e���N���X
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#ifndef _TASK_
#define _TASK_

//�֐��A�h���X�̐錾
typedef void (*prac_addr)(void);

//�s�b�a�\����
struct TCB{
	int type;
	prac_addr t_tcb;  //practice address�@�֐��̎��s�A�h���X
	unsigned int prio;//priority�i�v���C�I�[���e�B�j�D�揇��
	char name[15];    //�^�X�N�̖��O
	char work[128];   //���[�N�X�y�[�X
	char flag;        //�v���t���O
	struct TCB *prev; //�v�������[�i�O�̍\���̂̃A�h���X�j	
	struct TCB *next; //�l�N�X�g�i���̍\���̂̃A�h���X�j
	struct TCB *parent;//�e�̃A�h���X
	//��Ɨp
	unsigned int prio_temp;//priority�i�v���C�I�[���e�B�j�D�揇��
	struct TCB *parent_temp;//�e�̃A�h���X
};
//�V�X�e���s�b�a�̐錾
struct SYS_TCB{
	prac_addr t_tcb;  //practice address�@�֐��̎��s�A�h���X
	char work[128];   //���[�N�X�y�[�X(�V�X�e�����Ǘ�����f�[�^�i���_��牽���j)
	char re_flag;     //���^�[�����邩�̃t���O
};
//�^�[�~�l�[�^�̐錾
struct TER_TCB{
	prac_addr t_tcb;  //practice address�@�֐��̎��s�A�h���X
	struct TER_TCB *prev; //�v�������[�i�O�̍\���̂̃A�h���X�j	
	struct TER_TCB *next; //�l�N�X�g�i���̍\���̂̃A�h���X�j
};
//�s�b�a�̐�
#define TCB_MAX 1000//�s�b�a�̍ő吔
#define TER_MAX 5//�s�b�a�̍ő吔
//�V�X�e���^�X�N�̃t���O
#define RETURN 1
#define NORETURN 2
//�v���t���O
#define TASK_KILL 1
#define TASK_STOP 2
#define TASK_CHAN 3
#define TASK_CHAN2 4
//�^�C�v
#define	SYSTEM 0	// �V�X�e��
#define	NO_TASK 1	// �Ȃ�
#define	JIKI_TASK 2	// ���@�^�X�N
#define	JIKI_DEAD_TASK 3	// ���@�^�X�N
#define	ENEMY_TASK 4// �G�l�~�[�^�X�N
#define	SHOT_TASK 5	// �V���b�g�^�X�N
#define	E_SHOT1_TASK 6	// �V���b�g�^�X�N
#define	E_SHOT2_TASK 7	// �V���b�g�^�X�N

//�^�X�N�N���X
class Ctask{
private:
	SYS_TCB system_tcb[1]; //�V�X�e���^�X�N�i��Ɉ�������݁j
	SYS_TCB *Sys_tcb;

	TER_TCB Terminator[5];
	TER_TCB *Ter_tcb;

	TCB tcb[TCB_MAX];//�^�X�N�{��
	TCB *Active_tcb; //�^�X�N�A�h���X�V���[�Y
	TCB *Wait_tcb;   //
	TCB *Active;     //���s�p

public:
	Ctask();//�R���X�g���N�^
	~Ctask();//�f�X�g���N�^

	//�V�X�e���^�X�N���s
	char Sys_Task();
	
	//�V�X�e���^�X�N�i�C�j�V�G�[�^�j
	Sys_Task_Initiator(prac_addr t_tcb,char re_flag);//
	
	//�V�X�e���^�X�N�i�^�[�~�l�[�^�j
	Sys_Task_Terminator();//�P�������s
	Sys_Task_AllTerminator();//�S�Ď��s
	Sys_Task_SetTerminator(prac_addr t_tcb);//�^�[�~�l�[�^�̃Z�b�g

	//�^�X�N�ǉ�����
	void *MakeTask(char *name,prac_addr p_a,unsigned int prio,char type/*�^�X�N�̃^�C�v*/);
	void *RemakeTask(unsigned int prio/*�D��x*/);
	//�q�^�X�N�ǉ�����
	void *ChildMakeTask(char *name,/*���O*/prac_addr p_a/*���s�A�h���X*/,unsigned int prio/*�D��x*/,char type/*�^�X�N�̃^�C�v*/);
	//�����A�h���X�̕ύX�i���łɖ��O���l�I�j
	ChangeTask(char *name,/*���O*/prac_addr p_a);
	//�D�揇�ʂ̕ύX//�q������̏ꍇ
	void ChangePrio(unsigned int prio);
	//�q�������̏ꍇ
	void ChangePrio2(unsigned int prio);
	//���[�N�X�y�[�X
	void *workspace();
	//�����̃A�h���X��Ԃ�
	TCB *add_ret();
	//�e�̃A�h���X��Ԃ�
	void *p_add();
	//�e�̐e�̃A�h���X��Ԃ�
	void *p_p_add();
	//�e�̃��[�N�X�y�[�X��Ԃ�
	void *p_work_add();
	//������̃��[�N�X�y�[�X��Ԃ�
	void *p_p_work_add();
	//�A�N�e�B�u�̃A�h���X
	void *ActiveTop();
	//��ԕω��i��~��������@���삳������j
	void MaskTask(unsigned int m_prio,unsigned int a_prio,char flag); 
	//�������E��
	KillTask();
	//�e�����ʗ\��Ȃ�Ύq�����E��
	ChildKill();
	//�e�����ʗ\��Ȃ�Ύq�����E��
	ChildChange();
	//�I�[���L��
	AllKill();
	//�L�������s
	Kill();
	//�`�F���W�����s
	Change();

	//�w��D�揇�ʂ��E��
	void TergetKillTask(unsigned int prio);
	//�w�肵���͈͂��E��
	void CircleKillTask(unsigned int m_prio,unsigned int a_prio);

	//�A�����X�g�̃^�X�N�����Ɏ��s
	void Dispatcher();

	//�f�o�b�O�p
	a_name();
	w_cnt();
};

#endif _TASK_