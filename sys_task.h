///////////////////////////////////////////////////////////////////////////
//		擬似タスクシステムクラス
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#ifndef _TASK_
#define _TASK_

//関数アドレスの宣言
typedef void (*prac_addr)(void);

//ＴＣＢ構造体
struct TCB{
	int type;
	prac_addr t_tcb;  //practice address　関数の実行アドレス
	unsigned int prio;//priority（プライオーリティ）優先順位
	char name[15];    //タスクの名前
	char work[128];   //ワークスペース
	char flag;        //要求フラグ
	struct TCB *prev; //プレヴュー（前の構造体のアドレス）	
	struct TCB *next; //ネクスト（次の構造体のアドレス）
	struct TCB *parent;//親のアドレス
	//作業用
	unsigned int prio_temp;//priority（プライオーリティ）優先順位
	struct TCB *parent_temp;//親のアドレス
};
//システムＴＣＢの宣言
struct SYS_TCB{
	prac_addr t_tcb;  //practice address　関数の実行アドレス
	char work[128];   //ワークスペース(システムが管理するデータ（得点やら何やら）)
	char re_flag;     //リターンするかのフラグ
};
//ターミネータの宣言
struct TER_TCB{
	prac_addr t_tcb;  //practice address　関数の実行アドレス
	struct TER_TCB *prev; //プレヴュー（前の構造体のアドレス）	
	struct TER_TCB *next; //ネクスト（次の構造体のアドレス）
};
//ＴＣＢの数
#define TCB_MAX 1000//ＴＣＢの最大数
#define TER_MAX 5//ＴＣＢの最大数
//システムタスクのフラグ
#define RETURN 1
#define NORETURN 2
//要求フラグ
#define TASK_KILL 1
#define TASK_STOP 2
#define TASK_CHAN 3
#define TASK_CHAN2 4
//タイプ
#define	SYSTEM 0	// システム
#define	NO_TASK 1	// なし
#define	JIKI_TASK 2	// 自機タスク
#define	JIKI_DEAD_TASK 3	// 自機タスク
#define	ENEMY_TASK 4// エネミータスク
#define	SHOT_TASK 5	// ショットタスク
#define	E_SHOT1_TASK 6	// ショットタスク
#define	E_SHOT2_TASK 7	// ショットタスク

//タスククラス
class Ctask{
private:
	SYS_TCB system_tcb[1]; //システムタスク（常に一つだけ存在）
	SYS_TCB *Sys_tcb;

	TER_TCB Terminator[5];
	TER_TCB *Ter_tcb;

	TCB tcb[TCB_MAX];//タスク本体
	TCB *Active_tcb; //タスクアドレスシリーズ
	TCB *Wait_tcb;   //
	TCB *Active;     //実行用

public:
	Ctask();//コンストラクタ
	~Ctask();//デストラクタ

	//システムタスク実行
	char Sys_Task();
	
	//システムタスク（イニシエータ）
	Sys_Task_Initiator(prac_addr t_tcb,char re_flag);//
	
	//システムタスク（ターミネータ）
	Sys_Task_Terminator();//１つだけ実行
	Sys_Task_AllTerminator();//全て実行
	Sys_Task_SetTerminator(prac_addr t_tcb);//ターミネータのセット

	//タスク追加処理
	void *MakeTask(char *name,prac_addr p_a,unsigned int prio,char type/*タスクのタイプ*/);
	void *RemakeTask(unsigned int prio/*優先度*/);
	//子タスク追加処理
	void *ChildMakeTask(char *name,/*名前*/prac_addr p_a/*実行アドレス*/,unsigned int prio/*優先度*/,char type/*タスクのタイプ*/);
	//処理アドレスの変更（ついでに名前もネ！）
	ChangeTask(char *name,/*名前*/prac_addr p_a);
	//優先順位の変更//子供ありの場合
	void ChangePrio(unsigned int prio);
	//子供無しの場合
	void ChangePrio2(unsigned int prio);
	//ワークスペース
	void *workspace();
	//自分のアドレスを返す
	TCB *add_ret();
	//親のアドレスを返す
	void *p_add();
	//親の親のアドレスを返す
	void *p_p_add();
	//親のワークスペースを返す
	void *p_work_add();
	//おじんのワークスペースを返す
	void *p_p_work_add();
	//アクティブのアドレス
	void *ActiveTop();
	//状態変化（停止させたり　動作させたり）
	void MaskTask(unsigned int m_prio,unsigned int a_prio,char flag); 
	//自分を殺す
	KillTask();
	//親が死ぬ予定ならば子供を殺す
	ChildKill();
	//親が死ぬ予定ならば子供を殺す
	ChildChange();
	//オールキル
	AllKill();
	//キルを実行
	Kill();
	//チェンジを実行
	Change();

	//指定優先順位を殺す
	void TergetKillTask(unsigned int prio);
	//指定した範囲を殺す
	void CircleKillTask(unsigned int m_prio,unsigned int a_prio);

	//連結リストのタスクを順に実行
	void Dispatcher();

	//デバッグ用
	a_name();
	w_cnt();
};

#endif _TASK_