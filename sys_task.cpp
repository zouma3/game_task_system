///////////////////////////////////////////////////////////////////////////
//		�[���^�X�N�V�X�e���N���X
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

void ret(void){
	return;
}

//�R���X�g���N�^
Ctask::Ctask(){//�S�Ă̂s�b�a���q����
	int i;
	//SystemTCB ini
	Sys_tcb=&system_tcb[0];
	Sys_tcb->t_tcb=NULL;
	//SystemTCB ter
	Ter_tcb=&Terminator[0];
	Terminator[0].t_tcb=NULL;
	for(i=1;i<TER_MAX;i++){
		Terminator[i].next=&Terminator[i+1];
		Terminator[i].prev=&Terminator[i-1];
		Terminator[i].t_tcb=NULL;
	}
	Terminator[0].prev=NULL;
	Terminator[0].t_tcb=NULL;
	Terminator[0].next=&Terminator[1];
	Terminator[TER_MAX].next=NULL;
	//ActiveTCB
	//HEAD
	Active_tcb=&tcb[0];
	tcb[0].next=&tcb[1];
	tcb[0].prev=NULL;
	tcb[0].type =SYSTEM;
	tcb[0].prio=0x0000;//�ō��̗D�揇��
	strcpy(tcb[0].name,"head");
	tcb[0].t_tcb =ret;//���^�[����p
	//TAIL
	tcb[1].prev=&tcb[0];
	tcb[1].next=NULL;
	tcb[1].type=SYSTEM;
	tcb[1].prio=0xffff;//�Œ�̗D�揇��
	strcpy(tcb[1].name,"tail");
	tcb[1].t_tcb =ret;//���^�[����p
	//WaitTCB
	Wait_tcb=&tcb[2];
	for(i=2;i<TCB_MAX;i++){
		tcb[i].next=&tcb[i+1];
		tcb[i].prev=&tcb[i-1];
		tcb[i].prio=0x0000;
		tcb[i].t_tcb=NULL;
	}
	tcb[2].prev=NULL;
	tcb[TCB_MAX-1].next=NULL;
}
//�f�X�g���N�^
Ctask::~Ctask(){
	//�S�Ă��N���A�i�Q�[���I�����j
	TCB *A_temp=Active_tcb;//��Ɨp
	TCB *W_temp=Wait_tcb;  //��Ɨp
	while(A_temp->next !=NULL){
		//���e���N���A
		A_temp->flag =NULL;
		A_temp->name[0] =NULL;
		A_temp->prio =NULL;
		A_temp->parent =NULL;
		A_temp->t_tcb =NULL;
		A_temp->work[0] =NULL;
		A_temp=A_temp->next;
	}
	while(W_temp->next !=NULL){
		//���e���N���A
		W_temp->flag =NULL;
		W_temp->name[0] =NULL;
		W_temp->prio =NULL;
		W_temp->parent =NULL;
		W_temp->t_tcb =NULL;
		W_temp->work[0] =NULL;
		W_temp=W_temp->next;
	}
}
//�V�X�e���^�X�N�̃C�j�V�G�[�^
Ctask::Sys_Task_Initiator(prac_addr t_tcb,char re_flag){
	Sys_tcb->t_tcb=t_tcb;
	Sys_tcb->re_flag=re_flag;
}
//�V�X�e���^�X�N���s
char Ctask::Sys_Task (){
	if(Sys_tcb->t_tcb!=NULL)
		(Sys_tcb->t_tcb)();

	if(Sys_tcb->re_flag==RETURN)
		return 1;
	else
		return 0;
}
//�^�[�~�l�[�^�̃Z�b�g
Ctask::Sys_Task_SetTerminator(prac_addr t_tcb){
	TER_TCB *T_temp=Ter_tcb;//��Ɨp
	while(T_temp->t_tcb !=NULL){//�Ō�܂ňړ�
		T_temp=T_temp->next ;		
	}
	T_temp->t_tcb =t_tcb;//�Ō�ɑ��
}
//�^�[�~�l�[�^���Ōォ��P���s
Ctask::Sys_Task_Terminator(){
	TER_TCB *T_temp=Ter_tcb;//��Ɨp
	while(T_temp->t_tcb !=NULL){//�Ō�܂ňړ�
		T_temp=T_temp->next ;		
	}
	T_temp=T_temp->prev ;
	(*T_temp->t_tcb)();
	T_temp->t_tcb =NULL;
}
//�^�[�~�l�[�^��S�Ď��s
Ctask::Sys_Task_AllTerminator(){
	TER_TCB *T_temp=Ter_tcb;//��Ɨp
	while(T_temp->t_tcb !=NULL){//�Ō�܂ňړ�
		T_temp=T_temp->next ;		
	}
	T_temp=T_temp->prev ;
	while(T_temp->prev !=NULL){
		(*T_temp->t_tcb)();
		T_temp->t_tcb =NULL;
		T_temp=T_temp->prev ;		
	}
}
//�^�X�N�̐����i���������A�h���X��Ԃ��j
void *Ctask::MakeTask(char *name,/*���O*/prac_addr p_a/*���s�A�h���X*/,unsigned int prio/*�D��x*/,char type/*�^�X�N�̃^�C�v*/){
	TCB *A_temp=Active_tcb;//��Ɨp
	TCB *W_temp=Wait_tcb;  //��Ɨp
	//�D�揇�ʂ𒲂ׂ�	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//�p�����[�^��ۑ�
	W_temp->t_tcb=p_a;
	W_temp->prio =prio;
	W_temp->type =type;
	W_temp->parent =NULL;
	strcpy(Wait_tcb->name,name);
	//Wait_tcb��؂藣��
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//�؂藣����Wait_tcb��Active_tcb�ɂ�������
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//���������T�C�h�̍ŏI����
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	//�쐬�����^�X�N�̃A�h���X��ԋp
	return W_temp->work ;
}
//�D�揇�ʂ̈Ⴄ�����̐���
void *Ctask::RemakeTask(unsigned int prio/*�D��x*/){
	TCB *A_temp=Active_tcb;//��Ɨp
	TCB *W_temp=Wait_tcb;  //��Ɨp
	//�D�揇�ʂ𒲂ׂ�	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//�p�����[�^��ۑ�
	W_temp->prio =prio;

	//Wait_tcb��؂藣��
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//�؂藣����Wait_tcb��Active_tcb�ɂ�������
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//���������T�C�h�̍ŏI����
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	return W_temp;
}
//�q�^�X�N�̐���
void *Ctask::ChildMakeTask(char *name,/*���O*/prac_addr p_a/*���s�A�h���X*/,unsigned int prio/*�D��x*/,char type/*�^�X�N�̃^�C�v*/){
	TCB *A_temp=Active_tcb;//��Ɨp
	TCB *W_temp=Wait_tcb;  //��Ɨp
	//�D�揇�ʂ𒲂ׂ�	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//�p�����[�^��ۑ�
	W_temp->t_tcb=p_a;
	W_temp->prio =prio;
	//�e�̃A�h���X��ݒ�
	W_temp->parent =Active;
	W_temp->type =type;
	strcpy(Wait_tcb->name,name);
	//Wait_tcb��؂藣��
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//Wait_tcb��Active_tcb�ɂ�������
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//���������T�C�h�̍ŏI����
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	return W_temp->work ;
}
//�����A�h���X�̕ύX�i���łɖ��O���l�I�j
Ctask::ChangeTask(char *name,/*���O*/prac_addr p_a/*�����A�h���X*/){
	//�p�����[�^��ۑ�
	Active->t_tcb=p_a;
	strcpy(Active->name,name);
}
//���[�N�X�y�[�X�|�C���^��Ԃ�
void *Ctask::workspace(){
	return Active->work;
}
//�����̃A�h���X�|�C���^��Ԃ�(�q�^�X�N����鎞��)
TCB *Ctask::add_ret(){
	return Active;
}
//�e�̃A�h���X��Ԃ�
void *Ctask::p_add(){
	if(Active->parent==NULL)return NULL;
	return Active->parent;
}
//�e�̐e�̃A�h���X��Ԃ�
void *Ctask::p_p_add(){
	if(Active->parent->parent==NULL)return NULL;
	return Active->parent->parent;
}
//�e�̃��[�N�X�y�[�X��Ԃ�
void *Ctask::p_work_add(){
	if(Active->parent==NULL)return NULL;
	return Active->parent->work;
}
//������̃��[�N�X�y�[�X��Ԃ�
void *Ctask::p_p_work_add(){
	if(Active->parent->parent==NULL)return NULL;
	return Active->parent->parent->work;
}
//�A�N�e�B�u�̐擪�A�h���X���擾
void *Ctask::ActiveTop(){
	return Active_tcb;
}
//��ԕω�
void Ctask::MaskTask(unsigned int m_prio,unsigned int a_prio,char flag){
	if(m_prio>=a_prio)return;//�O�̗D�揇�ʂ��Ⴂ�ꍇ���^�[��
	TCB *A_temp=Active_tcb;//��Ɨp
	//�O�̗D�揇�ʂ�����܂ňړ�
	while(A_temp->prio < m_prio){
		A_temp=A_temp->next;
	}
	//��̗D�揇�ʂ�����܂Ńt���O������
	while(A_temp->prio >= a_prio){
		A_temp->flag=flag;
		A_temp=A_temp->next;
	}
}
//���E
Ctask::KillTask(){
	Active->flag=TASK_KILL;
}

//�e�����ʎ��A�q�����E��
Ctask::ChildKill(){
	TCB *A_temp=Active_tcb;
	TCB *temp;
	while(A_temp->next!=NULL){
		//�e�����Ȃ������Ȃ���
		if(A_temp->parent!=NULL){		
			//�e�̃A�h���X
			temp=A_temp->parent ;
			//�e�����ʗ\��Ȃ�q�����E��
			if(temp->flag==TASK_KILL)A_temp->flag =TASK_KILL;
			
			//�e���`�F���W���悤�Ƃ��Ă��鎞
			if(temp->flag ==TASK_CHAN){
				A_temp->parent =temp->parent_temp ;
				temp->flag =TASK_KILL;
			}
		}
		A_temp=A_temp->next ;
	}
}
//�I�[���L��
Ctask::AllKill(){
	TCB *A_temp=Active_tcb;
	while(A_temp->next!=NULL){
		//�V�X�e���s�b�a�ȊO���E��
		if(A_temp->type !=SYSTEM)A_temp->flag=TASK_KILL;
		A_temp=A_temp->next;
	}
}

//�w��D�揇�ʎE��
void Ctask::TergetKillTask(unsigned int prio){
	TCB *A_temp=Active_tcb;//��Ɨp
	//�O�̗D�揇�ʂ�����܂ňړ�
	while(A_temp->next !=NULL){
		if(A_temp->prio ==prio)A_temp->flag =TASK_KILL;
		A_temp=A_temp->next;
	}
}
//�w��͈͂��E���i�܂Ƃ߂ăL���j
void Ctask::CircleKillTask(unsigned int m_prio,unsigned int a_prio){
	if(m_prio>=a_prio)return;//�O�̗D�揇�ʂ��Ⴂ�ꍇ���^�[��
	TCB *A_temp=Active_tcb;//��Ɨp
	//�O�̗D�揇�ʂ�����܂ňړ�
	while(A_temp->prio < m_prio){
		A_temp=A_temp->next;
	}
	//��̗D�揇�ʂ�����܂Ńt���O������
	while(A_temp->prio >= a_prio){
		A_temp->flag=TASK_KILL;
		A_temp=A_temp->next;
	}
}
//�D�揇�ʂ�ύX(�L�����������ɏ����I)�@�L���t���O��D�悳���邽�߁I�I
void Ctask::ChangePrio(unsigned int prio){
	if(Active->flag==TASK_KILL)return;
	Active->flag=TASK_CHAN;
	Active->prio_temp=prio;
}
//�D�揇�ʂ�ύX�i�q�������Ȃ��ꍇ�j(�L�����������ɏ����I)�@�L���t���O��D�悳���邽�߁I�I
void Ctask::ChangePrio2(unsigned int prio){
	if(Active->flag==TASK_KILL)return;
	Active->flag=TASK_CHAN2;
	Active->prio_temp=prio;
}
//�`�F���W�p
Ctask::Change(){
	TCB *A=Active_tcb;//��Ɨp
	TCB *temp;
	//�D�揇�ʂ𒲂ׂ�	
	while(A->next!=NULL){
		if(A->flag ==TASK_CHAN){
			temp=(TCB *)RemakeTask(A->prio_temp);
			temp->flag =0;
			strcpy(temp->name,A->name);
			temp->t_tcb =A->t_tcb;
			temp->type =A->type ;
			memcpy(temp->work,A->work,128);
			A->parent_temp =temp;
		}
		if(A->flag ==TASK_CHAN2){
			temp=(TCB *)RemakeTask(A->prio_temp);
			temp->flag =0;
			strcpy(temp->name,A->name);
			temp->t_tcb =A->t_tcb;
			temp->type =A->type ;
			memcpy(temp->work,A->work,128);
			A->parent_temp =temp;
			A->flag =TASK_KILL;
		}
		A=A->next;	
	}
}
//�e�����ʎ��A�q�����E��
Ctask::ChildChange(){
	TCB *A_temp=Active_tcb;
	TCB *temp;
	while(A_temp->next!=NULL){
		//�e�����Ȃ������Ȃ���
		if(A_temp->parent!=NULL){		
			//�e�̃A�h���X
			temp=A_temp->parent ;
		
		}
		A_temp=A_temp->next ;
	}
}
//���ʗ\��̃^�X�N���E��
Ctask::Kill(){
	TCB *A_temp=Active_tcb;//��Ɨp
	TCB *W_temp=Wait_tcb;  //��Ɨp
	TCB *A_temp2;//��Ɨp

	while(A_temp->next !=NULL){
		//�L���t���O��������E��
		if((A_temp->flag == TASK_KILL)){
			A_temp2=A_temp->prev;
			//���e���N���A		
			A_temp->flag =0;
			A_temp->name[0] =NULL;
			A_temp->prio =0x0000;
			A_temp->parent =NULL;
			A_temp->t_tcb =NULL;
			A_temp->work[0] =NULL;

			//�A�N�e�B�u����͂���
			A_temp->prev->next = A_temp->next;
			if(A_temp->next!=NULL)A_temp->next->prev = A_temp->prev;			
			//Wait_tcb��Actve_tcb�ɂ�������
			A_temp->prev= NULL;
			A_temp->next= Wait_tcb;
			//���������T�C�h�̍ŏI����
			Wait_tcb-> prev = A_temp;
			Wait_tcb = A_temp;

			A_temp=A_temp2;
		}
		A_temp=A_temp->next;
	}
}
//�^�X�N���\��
Ctask::w_cnt(){
	TCB *A_temp=Active_tcb;
	static int cnt;
	HDC hdc;
	cnt=0;
	while(A_temp!=NULL){
		A_temp=A_temp->next ;
		cnt++;
	}
	char text[15];
	//���W��\��
	sprintf(text,"%d",cnt );
	draw.GetDC (0,&hdc);
	TextOut(hdc,0,18,text,strlen(text));
	draw.ReleaseDC (0,hdc);
}
//�^�X�N���\��
Ctask::a_name(){
	TCB *A_temp=Active_tcb;
	int cnt=0;
	HDC hdc;

	draw.GetDC(0,&hdc);
	char text[15];
	while(A_temp!=NULL){
		wsprintf(text,A_temp->name );
		TextOut(hdc,280,0+18*cnt,text,strlen(text));
		A_temp=A_temp->next ;
		cnt++;
	}
	//���W��\��
	draw.ReleaseDC(0,hdc);
}

//�A������Ă���^�X�N�𓮍�
void Ctask::Dispatcher(){
	Active = Active_tcb;
	//�V�X�e���^�X�N���s
	if(Sys_Task ())return;
	while(Active->next !=NULL){
		//���ʗ\��A�����Ă���^�X�N�͎��s���Ȃ�
		if((Active->flag !=TASK_KILL)|(Active->flag !=TASK_STOP)|(Active->flag !=TASK_CHAN)){
			(*Active->t_tcb)();
		}
		//���ɐi�߂�
		Active = Active->next;
	}
	//�t���O�������Ă���ƃ`�F���W
	Change();
	//�q�����E��
	ChildKill();
	//�Q����s���邱�Ƃő����E��
	ChildKill();
	//���ʗ\��^�X�N���E��
	Kill();

	//�f�o�b�O�\���p
	static char key_f,key;
	if((GetAsyncKeyState(VK_F12)&0x8000)==0)key_f=0;
	if((GetAsyncKeyState(VK_F12)&0x8000)&&(key_f==0)){
		key_f=1;
		if(key==1)
			key=0;
		else
			key=1;
	}
	if(key==1){
		//�f�o�b�O�p
		w_cnt();
		a_name();
		//�t���[���J�E���g�\��
		FrameCnt();
	}
}
