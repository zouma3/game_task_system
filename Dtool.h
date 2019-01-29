///////////////////////////////////////////////////////////////////////////
//		ドローツールクラス　Ｈ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#ifndef _DTOOL_
#define _DTOOL_

//デファイン宣言
//スクリーンの最大値
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

//サーフェイスの最大数
#define DRAW_MAX 21

//サーフェイス構造体
typedef struct {
	LPDIRECTDRAWSURFACE Surface;       // ビットマップ保持用サーフェス
	// サーフェスロスト対策データ↓
	char                 SaveData[30]; //ファイルネーム
	DWORD	             dwWidth;      // サーフェスサイズ
	DWORD	             dwHeight;
	DWORD	             dwPitch;
	char                 kind;
	int                  flag;
	COLORREF             ColorKey;     // カラーキー
} SurfaceData;

class Dtool{
private:
	//ダイレクトドロー
	LPDIRECTDRAW lpDDraw;
	//プライマリーサーフェイス
	LPDIRECTDRAWSURFACE lpPrimary;
	
	//０番がバックバッファとなる（たまにバックバッファも操作するため）
	//２０番が半透明、回転の拡縮用テンプサーフェイス
	SurfaceData lpSurface[DRAW_MAX];

	//半透明用テーブル（専用のパレットが必要）
	char tomei_tbl[16][16];
	//サイン、コサイン、テーブル
	double sin_tbl[360],cos_tbl[360];
	//パレット操作用
	PALETTEENTRY pe[256];
	//パレット操作したときの保存用
	PALETTEENTRY pe_temp[256];

	//クラス内で使うウィンドウハンドル（保存用）
	HWND Hwnd; 
	//初期化出来なかったとき
	HRESULT result;
public:
	//コンストラクタ
	Dtool();
	//デストラクタ
	~Dtool();
	//ダイレクトドロウイニシャライズ
	Init(HWND hwnd);
	
	//72方向移動関数
	void move72(int *x,int *y,char dir,int kyori);

	//ビットマップの大きさに合わせ、サーフェイス作成
	//ついでにカラーキーセット
	void MakeSurface(char draw_cnt,char *fname,int flag,int color);
	//サーフェイス作るだけ（MakeSurfaceのオーバーロード）
	void MakeSurface(char draw_cnt,int w,int h,int flag,int color);
	//バックバッファの塗りつぶし
	Cls(int cnt,int x,int y,int w,int h,int color);
	//ラインの描画
	DrawLine(int cnt,int x1,int y1,int x2,int y2, int size, int rgb);
	

	//回転転送(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、回転角度、中心ｘ、中心ｙ、カラーキーＮＯ)
	TurnBltFast(int tar,int x,int y,int sou,RECT rc,int Angle,int cx,int cy,int tou);
	//回転中心転送(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、回転角度、中心ｘ、中心ｙ)
	TurnBltFastCenter(int tar,int x,int y,int sou,RECT rc,int Angle,int cx,int cy);
	//半透明転送関数(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、透明度、転送の種類)
	AlphaBltFast(int tar,int x,int y,int sou,RECT rc,char tomeido,char flag);
	//半透明中心転送関数(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、透明度、転送の種類)
	AlphaBltFastCenter(int tar,int x,int y,int sou,RECT rc,char tomeido,char flag);
	//
	AlphaBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z,float sx/*ｘ拡大率*/,float sy/*ｙ拡大率*/,int sou/*転送元番号*/,RECT rc/*転送元レクト*/,char tomeido/*透明度*/,char flag/*フラグ*/);
	
	//半透明転送関数(転送先ＮＯ、ｘ座標、ｙ座標、ｚ座標、転送元ＮＯ、レクト、透明度、転送の種類)
	TDAlphaBlt(int tar,int x,int y,int z,int sou,RECT rc,char tomeido,char flag);
	//拡縮回転転送
	//回転中心転送(転送先ＮＯ、ｘ座標、ｙ座標、ｚ座標、転送元ＮＯ、レクト、回転角度、中心ｘ、中心ｙ)
	TDTurnBlt(int tar,int x,int y,int z,int sou,RECT rc,int Angle,int cx,int cy);

	//通常ブリットファースト(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、フラグ)
	BltFast(int tar,int x,int y,int sou,RECT rc,int flag);
	//クリップしてブリットファースト(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、フラグ)
	ClipBltFast(int tar,int x,int y,int sou,RECT rc,int flag);
	//クリップしてブリットファースト(転送先ＮＯ、ｘ座標、ｙ座標、転送元ＮＯ、レクト、フラグ)
	ClipBltFast2(int tar,int x,int y,int sou,RECT rc,int flag);
	//クリップしてブリット(転送先ＮＯ、ｘ座標、ｙ座標、横幅拡大率、縦幅拡大率、転送元ＮＯ、レクト、フラグ)
	RECT ClipBlt(int tar,int x, int y,float sx, float sy,int sou,RECT rc,int flag);
	//中心クリップブリット(転送先ＮＯ、ｘ座標、ｙ座標、横幅拡大率、縦幅拡大率、転送元ＮＯ、レクト、フラグ)
	ClipBltCenter(int tar,int x, int y,float sx, float sy,int sou,RECT rc,int flag);
	//スクロールブリット(転送先ＮＯ、ｘ座標（アドレス）、ｙ座標（アドレス）、ｘスピード、ｙスピード、転送元ＮＯ、レクト、フラグ)
	ScroolBlt(int tar,float *RollX,float *RollY,float xSpeed,float ySpeed,int sou,RECT rc ,int flag);
	//擬似３Ｄブリット(転送先ＮＯ、ｘ座標、ｙ座標、ｚ座標、ｘに向かって、ｙに向かって、転送元ＮＯ、レクト、フラグ)
	TDClipBlt(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	//擬似３Ｄブリットセンター(転送先ＮＯ、ｘ座標、ｙ座標、ｚ座標、ｘに向かって、ｙに向かって、転送元ＮＯ、レクト、フラグ)
	TDClipBltCenter(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	//画像の大きさはそのままで、ｘ、ｙ軸に転送
	TDBlt(int tar,int x,int y,int z,int cx,int cy,int sou,RECT rc,int flag);
	
	//全てリリース
	Release();
	//プライマリーとバックバッファのリストア
	BackRestore();
	//ＣＮＴのサーフェイスのリストア
	Restore(int cnt);
	//文字列の描画（サーファいすナンバー、文字列、文字サイズ、描画位置ｘ、描画位置ｙ、文字色）
	FontShow(int cnt,char *str, int size, int x, int y, int rgb);
	//cnt番号のサーフェイスのデバイスコンテキスト取得
	GetDC(int cnt,HDC *hdc);
	//cnt番号のサーフェイスのデバイスコンテキスト解放
	ReleaseDC(int cnt,HDC hdc);
	//黒から元にもどす（速さ）
	char BlackIn(char nrgb);
	//黒にフェードイン（速さ）
	char BlackOut(char nrgb);
	//白から元にもどす（速さ）
	char WhiteIn(char nrgb);
	//白にフェードイン（速さ）
	char WhiteOut(char nrgb);
	//フリップする
	void Flip();
};

#endif _DTOOL_
