///////////////////////////////////////////////////////////////////////////
//		擬似タスクシステムクラス
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

void ret(void){
	return;
}

//コンストラクタ
Ctask::Ctask(){//全てのＴＣＢを繋げる
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
	tcb[0].prio=0x0000;//最高の優先順位
	strcpy(tcb[0].name,"head");
	tcb[0].t_tcb =ret;//リターン専用
	//TAIL
	tcb[1].prev=&tcb[0];
	tcb[1].next=NULL;
	tcb[1].type=SYSTEM;
	tcb[1].prio=0xffff;//最低の優先順位
	strcpy(tcb[1].name,"tail");
	tcb[1].t_tcb =ret;//リターン専用
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
//デストラクタ
Ctask::~Ctask(){
	//全てをクリア（ゲーム終了時）
	TCB *A_temp=Active_tcb;//作業用
	TCB *W_temp=Wait_tcb;  //作業用
	while(A_temp->next !=NULL){
		//内容をクリア
		A_temp->flag =NULL;
		A_temp->name[0] =NULL;
		A_temp->prio =NULL;
		A_temp->parent =NULL;
		A_temp->t_tcb =NULL;
		A_temp->work[0] =NULL;
		A_temp=A_temp->next;
	}
	while(W_temp->next !=NULL){
		//内容をクリア
		W_temp->flag =NULL;
		W_temp->name[0] =NULL;
		W_temp->prio =NULL;
		W_temp->parent =NULL;
		W_temp->t_tcb =NULL;
		W_temp->work[0] =NULL;
		W_temp=W_temp->next;
	}
}
//システムタスクのイニシエータ
Ctask::Sys_Task_Initiator(prac_addr t_tcb,char re_flag){
	Sys_tcb->t_tcb=t_tcb;
	Sys_tcb->re_flag=re_flag;
}
//システムタスク実行
char Ctask::Sys_Task (){
	if(Sys_tcb->t_tcb!=NULL)
		(Sys_tcb->t_tcb)();

	if(Sys_tcb->re_flag==RETURN)
		return 1;
	else
		return 0;
}
//ターミネータのセット
Ctask::Sys_Task_SetTerminator(prac_addr t_tcb){
	TER_TCB *T_temp=Ter_tcb;//作業用
	while(T_temp->t_tcb !=NULL){//最後まで移動
		T_temp=T_temp->next ;		
	}
	T_temp->t_tcb =t_tcb;//最後に代入
}
//ターミネータを最後から１つ実行
Ctask::Sys_Task_Terminator(){
	TER_TCB *T_temp=Ter_tcb;//作業用
	while(T_temp->t_tcb !=NULL){//最後まで移動
		T_temp=T_temp->next ;		
	}
	T_temp=T_temp->prev ;
	(*T_temp->t_tcb)();
	T_temp->t_tcb =NULL;
}
//ターミネータを全て実行
Ctask::Sys_Task_AllTerminator(){
	TER_TCB *T_temp=Ter_tcb;//作業用
	while(T_temp->t_tcb !=NULL){//最後まで移動
		T_temp=T_temp->next ;		
	}
	T_temp=T_temp->prev ;
	while(T_temp->prev !=NULL){
		(*T_temp->t_tcb)();
		T_temp->t_tcb =NULL;
		T_temp=T_temp->prev ;		
	}
}
//タスクの生成（生成したアドレスを返す）
void *Ctask::MakeTask(char *name,/*名前*/prac_addr p_a/*実行アドレス*/,unsigned int prio/*優先度*/,char type/*タスクのタイプ*/){
	TCB *A_temp=Active_tcb;//作業用
	TCB *W_temp=Wait_tcb;  //作業用
	//優先順位を調べる	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//パラメータを保存
	W_temp->t_tcb=p_a;
	W_temp->prio =prio;
	W_temp->type =type;
	W_temp->parent =NULL;
	strcpy(Wait_tcb->name,name);
	//Wait_tcbを切り離す
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//切り離したWait_tcbをActive_tcbにくっつける
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//くっつけたサイドの最終処理
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	//作成したタスクのアドレスを返却
	return W_temp->work ;
}
//優先順位の違う自分の生成
void *Ctask::RemakeTask(unsigned int prio/*優先度*/){
	TCB *A_temp=Active_tcb;//作業用
	TCB *W_temp=Wait_tcb;  //作業用
	//優先順位を調べる	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//パラメータを保存
	W_temp->prio =prio;

	//Wait_tcbを切り離す
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//切り離したWait_tcbをActive_tcbにくっつける
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//くっつけたサイドの最終処理
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	return W_temp;
}
//子タスクの生成
void *Ctask::ChildMakeTask(char *name,/*名前*/prac_addr p_a/*実行アドレス*/,unsigned int prio/*優先度*/,char type/*タスクのタイプ*/){
	TCB *A_temp=Active_tcb;//作業用
	TCB *W_temp=Wait_tcb;  //作業用
	//優先順位を調べる	
	while(A_temp->next!=NULL){
		if(A_temp->prio < prio && A_temp ->next->prio>=prio)break;
		A_temp=A_temp->next ;
	}
	//パラメータを保存
	W_temp->t_tcb=p_a;
	W_temp->prio =prio;
	//親のアドレスを設定
	W_temp->parent =Active;
	W_temp->type =type;
	strcpy(Wait_tcb->name,name);
	//Wait_tcbを切り離す
	Wait_tcb=W_temp->next;
	Wait_tcb->prev =NULL;
	//Wait_tcbをActive_tcbにくっつける
	W_temp->prev= A_temp;
	W_temp->next= A_temp->next;
	//くっつけたサイドの最終処理
	A_temp->next-> prev = W_temp;
	A_temp-> next = W_temp;
	return W_temp->work ;
}
//処理アドレスの変更（ついでに名前もネ！）
Ctask::ChangeTask(char *name,/*名前*/prac_addr p_a/*処理アドレス*/){
	//パラメータを保存
	Active->t_tcb=p_a;
	strcpy(Active->name,name);
}
//ワークスペースポインタを返す
void *Ctask::workspace(){
	return Active->work;
}
//自分のアドレスポインタを返す(子タスクを作る時等)
TCB *Ctask::add_ret(){
	return Active;
}
//親のアドレスを返す
void *Ctask::p_add(){
	if(Active->parent==NULL)return NULL;
	return Active->parent;
}
//親の親のアドレスを返す
void *Ctask::p_p_add(){
	if(Active->parent->parent==NULL)return NULL;
	return Active->parent->parent;
}
//親のワークスペースを返す
void *Ctask::p_work_add(){
	if(Active->parent==NULL)return NULL;
	return Active->parent->work;
}
//おじんのワークスペースを返す
void *Ctask::p_p_work_add(){
	if(Active->parent->parent==NULL)return NULL;
	return Active->parent->parent->work;
}
//アクティブの先頭アドレスを取得
void *Ctask::ActiveTop(){
	return Active_tcb;
}
//状態変化
void Ctask::MaskTask(unsigned int m_prio,unsigned int a_prio,char flag){
	if(m_prio>=a_prio)return;//前の優先順位が低い場合リターン
	TCB *A_temp=Active_tcb;//作業用
	//前の優先順位が来るまで移動
	while(A_temp->prio < m_prio){
		A_temp=A_temp->next;
	}
	//後の優先順位が来るまでフラグを入れる
	while(A_temp->prio >= a_prio){
		A_temp->flag=flag;
		A_temp=A_temp->next;
	}
}
//自殺
Ctask::KillTask(){
	Active->flag=TASK_KILL;
}

//親が死ぬ時、子供も殺す
Ctask::ChildKill(){
	TCB *A_temp=Active_tcb;
	TCB *temp;
	while(A_temp->next!=NULL){
		//親がいない時やりなおし
		if(A_temp->parent!=NULL){		
			//親のアドレス
			temp=A_temp->parent ;
			//親が死ぬ予定なら子供も殺す
			if(temp->flag==TASK_KILL)A_temp->flag =TASK_KILL;
			
			//親がチェンジしようとしている時
			if(temp->flag ==TASK_CHAN){
				A_temp->parent =temp->parent_temp ;
				temp->flag =TASK_KILL;
			}
		}
		A_temp=A_temp->next ;
	}
}
//オールキル
Ctask::AllKill(){
	TCB *A_temp=Active_tcb;
	while(A_temp->next!=NULL){
		//システムＴＣＢ以外を殺す
		if(A_temp->type !=SYSTEM)A_temp->flag=TASK_KILL;
		A_temp=A_temp->next;
	}
}

//指定優先順位殺す
void Ctask::TergetKillTask(unsigned int prio){
	TCB *A_temp=Active_tcb;//作業用
	//前の優先順位が来るまで移動
	while(A_temp->next !=NULL){
		if(A_temp->prio ==prio)A_temp->flag =TASK_KILL;
		A_temp=A_temp->next;
	}
}
//指定範囲を殺す（まとめてキル）
void Ctask::CircleKillTask(unsigned int m_prio,unsigned int a_prio){
	if(m_prio>=a_prio)return;//前の優先順位が低い場合リターン
	TCB *A_temp=Active_tcb;//作業用
	//前の優先順位が来るまで移動
	while(A_temp->prio < m_prio){
		A_temp=A_temp->next;
	}
	//後の優先順位が来るまでフラグを入れる
	while(A_temp->prio >= a_prio){
		A_temp->flag=TASK_KILL;
		A_temp=A_temp->next;
	}
}
//優先順位を変更(キルをこれより後に書け！)　キルフラグを優先させるため！！
void Ctask::ChangePrio(unsigned int prio){
	if(Active->flag==TASK_KILL)return;
	Active->flag=TASK_CHAN;
	Active->prio_temp=prio;
}
//優先順位を変更（子供がいない場合）(キルをこれより後に書け！)　キルフラグを優先させるため！！
void Ctask::ChangePrio2(unsigned int prio){
	if(Active->flag==TASK_KILL)return;
	Active->flag=TASK_CHAN2;
	Active->prio_temp=prio;
}
//チェンジ用
Ctask::Change(){
	TCB *A=Active_tcb;//作業用
	TCB *temp;
	//優先順位を調べる	
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
//親が死ぬ時、子供も殺す
Ctask::ChildChange(){
	TCB *A_temp=Active_tcb;
	TCB *temp;
	while(A_temp->next!=NULL){
		//親がいない時やりなおし
		if(A_temp->parent!=NULL){		
			//親のアドレス
			temp=A_temp->parent ;
		
		}
		A_temp=A_temp->next ;
	}
}
//死ぬ予定のタスクを殺す
Ctask::Kill(){
	TCB *A_temp=Active_tcb;//作業用
	TCB *W_temp=Wait_tcb;  //作業用
	TCB *A_temp2;//作業用

	while(A_temp->next !=NULL){
		//キルフラグだったら殺す
		if((A_temp->flag == TASK_KILL)){
			A_temp2=A_temp->prev;
			//内容をクリア		
			A_temp->flag =0;
			A_temp->name[0] =NULL;
			A_temp->prio =0x0000;
			A_temp->parent =NULL;
			A_temp->t_tcb =NULL;
			A_temp->work[0] =NULL;

			//アクティブからはずす
			A_temp->prev->next = A_temp->next;
			if(A_temp->next!=NULL)A_temp->next->prev = A_temp->prev;			
			//Wait_tcbをActve_tcbにくっつける
			A_temp->prev= NULL;
			A_temp->next= Wait_tcb;
			//くっつけたサイドの最終処理
			Wait_tcb-> prev = A_temp;
			Wait_tcb = A_temp;

			A_temp=A_temp2;
		}
		A_temp=A_temp->next;
	}
}
//タスク名表示
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
	//座標を表示
	sprintf(text,"%d",cnt );
	draw.GetDC (0,&hdc);
	TextOut(hdc,0,18,text,strlen(text));
	draw.ReleaseDC (0,hdc);
}
//タスク名表示
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
	//座標を表示
	draw.ReleaseDC(0,hdc);
}

//連結されているタスクを動作
void Ctask::Dispatcher(){
	Active = Active_tcb;
	//システムタスク実行
	if(Sys_Task ())return;
	while(Active->next !=NULL){
		//死ぬ予定、眠っているタスクは実行しない
		if((Active->flag !=TASK_KILL)|(Active->flag !=TASK_STOP)|(Active->flag !=TASK_CHAN)){
			(*Active->t_tcb)();
		}
		//次に進める
		Active = Active->next;
	}
	//フラグが立っているとチェンジ
	Change();
	//子供を殺す
	ChildKill();
	//２回実行することで孫を殺す
	ChildKill();
	//死ぬ予定タスクを殺す
	Kill();

	//デバッグ表示用
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
		//デバッグ用
		w_cnt();
		a_name();
		//フレームカウント表示
		FrameCnt();
	}
}
