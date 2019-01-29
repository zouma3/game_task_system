///////////////////////////////////////////////////////////////////////////
//		ドローツールクラス　ＣＰＰ
//								    Programmed by 雑敷　正史				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

//コンストラクタ
Dtool::Dtool(){
}
//デストラクタ
Dtool::~Dtool (){
	for(int i=0;i<DRAW_MAX;i++){
		if(lpSurface[i].Surface!=NULL){
			//データが入っていればリリース、ＮＵＬＬ
			lpSurface[i].Surface->Release();
			lpSurface[i].Surface=NULL;	
		}	
	}
	//ドローの解放
	//ディスプレイモードを元に戻す	
	lpDDraw->RestoreDisplayMode();
	//primary&backbufferを消滅
	lpPrimary->Release();
}
//敵72方向進行関数
void Dtool::move72(int *x,int *y,char dir,int kyori){
	if(dir<0)return;
	(*x)+=(int)(kyori*cos_tbl[dir*5]);
	(*y)-=(int)(kyori*sin_tbl[dir*5]);
}
//ダイレクトのイニシャライズ
Dtool::Init(HWND hwnd){
	//ウィンドウハンドルの保存
	Hwnd = hwnd;
	//各構造体
	DDSURFACEDESC Dds;
	DDSCAPS Ddscaps;
	//---------------------DirectDraw関連-----------------------
	//ddrawをクリエイト
	result=DirectDrawCreate(NULL,&lpDDraw,NULL);
	if(result!=DD_OK)Error(Hwnd,"ダイレクトドローの生成が出来ません");
	
	//フルスクリーンモードへ
	result=lpDDraw->SetCooperativeLevel(hwnd,DDSCL_EXCLUSIVE|DDSCL_FULLSCREEN|DDSCL_ALLOWREBOOT|DDSCL_ALLOWMODEX);
	if(result!=DD_OK)Error(Hwnd,"ＭＯＤＥＸでフルスクリーン化出来ません");
	
	//画面の大きさと色数の決定
	result=lpDDraw->SetDisplayMode(SCREEN_WIDTH,SCREEN_HEIGHT,8);
	if(result!=DD_OK)Error(Hwnd,"解像度が変更できません");
	
	//Ddsの設定でprimaryサーファスの作成
	Dds.dwSize=sizeof(Dds);
	Dds.dwFlags=DDSD_CAPS|DDSD_BACKBUFFERCOUNT;
	Dds.ddsCaps.dwCaps=DDSCAPS_PRIMARYSURFACE|DDSCAPS_FLIP|DDSCAPS_COMPLEX;
	Dds.dwBackBufferCount=1;
	result=lpDDraw->CreateSurface (&Dds,&lpPrimary,NULL);
	if(result!=DD_OK)Error(Hwnd,"プライマリーサーフェイスが生成出来ません");
	
	Ddscaps.dwCaps=DDSCAPS_BACKBUFFER;
	result=lpPrimary->GetAttachedSurface(&Ddscaps,&lpSurface[0].Surface);
	if(result!=DD_OK)Error(Hwnd,"プライマリーサーフェイスをアタッチ出来ません");
	//０番はバックバッファ
	for(int i=1;i<DRAW_MAX;i++)
		lpSurface[i].Surface =NULL;

	//	//半透明、回転の拡縮用テンプサーフェイス
	MakeSurface(20,320,320,DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	
	//半透明テーブルの計算
	for(int j=0,k=0,l=0;j<256;j++){
		if(k==16){l++;k=0;}		
		tomei_tbl[l][k]=j;
		k++;
	}
	//sin.cosの計算
	for(i=0;i<360;i++){
		cos_tbl[i]=(float)cos(i*3.141592/180);
		sin_tbl[i]=(float)sin(i*3.141592/180);	
	}

}
//ビットマップのロード
void Dtool::MakeSurface(char draw_cnt,char *fname,int flag,int color){
	//バックバッファの場合リターン
	if(draw_cnt==0)return;
	//サーフェイスを作るための設定
	DDSURFACEDESC Dds;
	//サイズの取得
	Dds.dwSize=sizeof(Dds);
	//フラグを立てたものを使用できる
	Dds.dwFlags=DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH;
	//ＶＲＡＭ、システムメモリを使用するか設定
	Dds.ddsCaps.dwCaps=flag;

	//各種変数等
	HBITMAP hBmp=NULL;
	BITMAP bm;
	HDC hdc,hMemdc;
	LPDIRECTDRAWPALETTE lpPal;
	RGBQUAD rgb[256];
	
	//ビットマップの情報取得
	hBmp=(HBITMAP)LoadImage(GetModuleHandle(NULL),fname,IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	GetObject(hBmp,sizeof(bm),&bm);

	//direct X5では、メインサーフェスより横幅は大きく取れない
	Dds.dwWidth = bm.bmWidth > SCREEN_WIDTH ? SCREEN_WIDTH : bm.bmWidth;
	Dds.dwHeight = abs(bm.bmHeight);
	//サーフェイスのクリエイト
	lpDDraw->CreateSurface(&Dds,&lpSurface[draw_cnt].Surface,NULL);

	hMemdc=CreateCompatibleDC(NULL);
	SelectObject(hMemdc,hBmp);
	GetDIBColorTable(hMemdc,0,256,rgb);
	//パレットの保存
	for(int i=0;i<256;i++){
		pe[i].peRed=rgb[i].rgbRed;
		pe[i].peGreen=rgb[i].rgbGreen;
		pe[i].peBlue=rgb[i].rgbBlue;
		pe[i].peFlags=PC_RESERVED|PC_NOCOLLAPSE;
		pe_temp[i].peRed=rgb[i].rgbRed;
		pe_temp[i].peGreen=rgb[i].rgbGreen;
		pe_temp[i].peBlue=rgb[i].rgbBlue;
		pe_temp[i].peFlags=PC_RESERVED|PC_NOCOLLAPSE;
	}
	//パレットを作る
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	//パレットセットする
	lpPrimary->SetPalette(lpPal);
	//ビットマップを作ったせーフェイスに転送
	result=lpSurface[draw_cnt].Surface->GetDC(&hdc);
	if(result!=DD_OK)return;
	BitBlt(hdc,0,0,bm.bmWidth,bm.bmHeight,hMemdc,0,0,SRCCOPY);
	lpSurface[draw_cnt].Surface->ReleaseDC(hdc);
	//使い終わったら開放しようね！
	DeleteDC(hMemdc);
	lpPal->Release();
	DeleteObject(hBmp);
	//カラーキーの設定
	DDCOLORKEY key;
	//カラーキーの最大値、最小値設定
	key.dwColorSpaceHighValue=color;
	key.dwColorSpaceLowValue=color;
	//カラーキーのセット
	result=lpSurface[draw_cnt].Surface->SetColorKey (DDCKEY_SRCBLT,&key);
	if(result!=DD_OK)return;
	//ロスト時の保存用//
	//再読込に使用
	sprintf(lpSurface[draw_cnt].SaveData, "%s", fname);
	//スプライトサイズの取得
	ZeroMemory(&Dds,sizeof(DDSURFACEDESC));
	Dds.dwSize = sizeof(DDSURFACEDESC);
	lpSurface[draw_cnt].Surface->GetSurfaceDesc(&Dds);
	lpSurface[draw_cnt].dwPitch  = (DWORD)Dds.lPitch;
	lpSurface[draw_cnt].dwWidth  = (DWORD)Dds.dwWidth;
	lpSurface[draw_cnt].dwHeight = (DWORD)Dds.dwHeight;
	lpSurface[draw_cnt].flag  = flag;
	lpSurface[draw_cnt].kind =0;
	lpSurface[draw_cnt].ColorKey = color;
}
//ビットマップのロード
void Dtool::MakeSurface(char draw_cnt,int w,int h,int flag,int color){
	//バックバッファの場合リターン
	if(draw_cnt==0)return;
	//サーフェイスを作るための設定
	DDSURFACEDESC Dds;
	//サイズの取得
	Dds.dwSize=sizeof(Dds);
	//フラグを立てたものを使用できる
	Dds.dwFlags=DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH;
	//ＶＲＡＭ、システムメモリを使用するか設定
	Dds.ddsCaps.dwCaps=flag;
	//direct X5では、メインサーフェスより横幅は大きく取れない
	Dds.dwWidth =w ;
	Dds.dwHeight =h ;
	//サーフェイスのクリエイト
	lpDDraw->CreateSurface(&Dds,&lpSurface[draw_cnt].Surface,NULL);
	//カラーキーの設定
	DDCOLORKEY key;
	//カラーキーの最大値、最小値設定
	key.dwColorSpaceHighValue=color;
	key.dwColorSpaceLowValue=color;
	//カラーキーのセット
	lpSurface[draw_cnt].Surface->SetColorKey (DDCKEY_SRCBLT,&key);

	//ロスト時の保存用//
	//再読込に使用
	sprintf(lpSurface[draw_cnt].SaveData, "NULL");
	//スプライトサイズの取得
	ZeroMemory(&Dds,sizeof(DDSURFACEDESC));
	Dds.dwSize = sizeof(DDSURFACEDESC);
	lpSurface[draw_cnt].Surface->GetSurfaceDesc(&Dds);
	lpSurface[draw_cnt].dwPitch  = (DWORD)Dds.lPitch;
	lpSurface[draw_cnt].dwWidth  = (DWORD)Dds.dwWidth;
	lpSurface[draw_cnt].dwHeight = (DWORD)Dds.dwHeight;
	lpSurface[draw_cnt].flag  = flag;
	lpSurface[draw_cnt].kind =1;
	lpSurface[draw_cnt].ColorKey = color;
}

//範囲指定塗りつぶし
Dtool::Cls(int cnt,int x,int y,int w,int h,int color){
	RECT Scr={x,y,w,h};
	DDBLTFX dfx;
	dfx.dwSize=sizeof(dfx);
	//色の設定
	dfx.dwFillColor=color;
	//バックバッファを塗りつぶす
	lpSurface[cnt].Surface ->Blt(&Scr,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&dfx);	
}
Dtool::GetDC  (int cnt,HDC *hdc){
	lpSurface[cnt].Surface ->GetDC (hdc);
}
Dtool::ReleaseDC (int cnt,HDC hdc){
	lpSurface[cnt].Surface ->ReleaseDC (hdc);
}
//フォント描画関数
Dtool::FontShow(int cnt,char *str, int size, int x, int y, int rgb)
{
	//フォント処理変数
	static HFONT    NewFont,OldFont;;
	static HDC      hdc;
	static PLOGFONT FontInfo;
	
	lpSurface[cnt].Surface->GetDC(&hdc);
	//フォントインフォ初期化
	FontInfo  = (PLOGFONT)GlobalAlloc(GPTR, sizeof(LOGFONT));
	//フォントタイプ設定
	BOOL Bold = TRUE;
	lstrcpy(FontInfo->lfFaceName, "標準明朝");
	FontInfo->lfWeight     = (Bold == FALSE)*FW_NORMAL + (Bold == TRUE)*FW_BOLD;
	FontInfo->lfEscapement = 0;
	FontInfo->lfWidth      = 0;
	FontInfo->lfHeight     = size;
	FontInfo->lfItalic     = false;
	FontInfo->lfUnderline  = FALSE;
	FontInfo->lfCharSet    = SHIFTJIS_CHARSET;

	//デバイスコンテキスト取得
	NewFont = CreateFontIndirect(FontInfo);
	OldFont = (HFONT)SelectObject(hdc, NewFont);
	//文字列描画処理
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, rgb);
	TextOut(hdc, x, y, str, strlen(str));
	//デバイスコンテキスト開放
	SelectObject(hdc, OldFont);
	DeleteObject(NewFont);
	lpSurface[cnt].Surface->ReleaseDC(hdc);
	//フォントインフォ開放
	GlobalFree((LOCALHANDLE)FontInfo);
}
//元のパレットへ
char Dtool::BlackIn(char nrgb){	
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//黒から除除に元に戻していく
	for(int i=0;i<256;i++){
		if(pe[i].peRed<=pe_temp[i].peRed-nrgb){
			pe[i].peRed+=nrgb;
			check=0;
		}else
			pe[i].peRed=pe_temp[i].peRed;
			
		if(pe[i].peGreen<=pe_temp[i].peGreen-nrgb){
			pe[i].peGreen+=nrgb;
			check=0;
		}else
			pe[i].peGreen=pe_temp[i].peGreen;
			
		if(pe[i].peBlue<=pe_temp[i].peBlue-nrgb){
			pe[i].peBlue+=nrgb;
			check=0;
		}else
			pe[i].peBlue=pe_temp[i].peBlue;
	}
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	lpPrimary->SetPalette(lpPal);
	lpPal->Release();
	//全て元に戻ったら
	if(check==1){return 1;}
	return 0;
}
//フェードアウト
char Dtool::BlackOut(char nrgb){
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//除除に黒く
	for(int i=0;i<256;i++){
		if(pe[i].peRed>=nrgb){
			pe[i].peRed-=nrgb;
			check=0;
		}else{
			pe[i].peRed=0;
		}
		if(pe[i].peGreen>=nrgb){
			pe[i].peGreen-=nrgb;
			check=0;
		}else{
			pe[i].peGreen=0;
		}
		if(pe[i].peBlue>=nrgb){
			pe[i].peBlue-=nrgb;
			check=0;
		}else{
			pe[i].peBlue=0;
		}
		pe[i].peFlags=PC_RESERVED|PC_NOCOLLAPSE;	
	}
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	lpPrimary->SetPalette(lpPal);
	lpPal->Release();
	//全て黒になったら
	if(check==1){return 1;}
	return 0;
}
//元のパレットへ
char Dtool::WhiteIn(char nrgb){	
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//白から除除に元に
	for(int i=0;i<256;i++){
		if(pe[i].peRed>=pe_temp[i].peRed+nrgb){
			pe[i].peRed-=nrgb;
			check=0;
		}else
			pe[i].peRed=pe_temp[i].peRed;
			
		if(pe[i].peGreen>=pe_temp[i].peGreen+nrgb){
			pe[i].peGreen-=nrgb;
			check=0;
		}else
			pe[i].peGreen=pe_temp[i].peGreen;
			
		if(pe[i].peBlue>=pe_temp[i].peBlue+nrgb){
			pe[i].peBlue-=nrgb;
			check=0;
		}else
			pe[i].peBlue=pe_temp[i].peBlue;
	}
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	lpPrimary->SetPalette(lpPal);
	lpPal->Release();
	//全て元に戻ったら
	if(check==1){return 1;}
	return 0;
}
//フェードアウト
char Dtool::WhiteOut(char nrgb){
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//除除に白に
	for(int i=0;i<256;i++){
		if(pe[i].peRed<=256-nrgb){
			pe[i].peRed+=nrgb;
			check=0;
		}else
			pe[i].peRed=255;
		
		if(pe[i].peGreen<=256-nrgb){
			pe[i].peGreen+=nrgb;
			check=0;
		}else
			pe[i].peGreen=255;
			
		if(pe[i].peBlue<=256-nrgb){
			pe[i].peBlue+=nrgb;
			check=0;
		}else
			pe[i].peBlue=255;

		pe[i].peFlags=PC_RESERVED|PC_NOCOLLAPSE;	
	}
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	lpPrimary->SetPalette(lpPal);
	lpPal->Release();
	//全て白なら
	if(check==1){return 1;}
	return 0;
}
//バックバッファのリストア
Dtool::BackRestore(){
	lpPrimary->Restore();
	lpSurface[0].Surface->Restore ();
}
//指定サーフェイスのリストア
Dtool::Restore(int cnt){
	lpSurface[cnt].Surface ->Restore ();
	if(lpSurface[cnt].kind ==0)
		MakeSurface(cnt,lpSurface[cnt].SaveData ,lpSurface[cnt].flag ,lpSurface[cnt].ColorKey);
	else
		MakeSurface(cnt,lpSurface[cnt].dwWidth ,lpSurface[cnt].dwHeight,lpSurface[cnt].flag ,lpSurface[cnt].ColorKey);
}
//ライン描画関数
Dtool::DrawLine(int cnt/*転送先番号*/,int x1/*Ｘ元*/,int y1/*Ｘ元*/,int x2/*Ｘ先*/,int y2/*Ｙ先*/,int size/*ペンサイズ*/,int rgb/*色*/)
{
	HDC hdc;
	HPEN hpen;
	hpen = CreatePen(PS_SOLID,size,rgb); //描画用ペンの作成
	lpSurface[cnt].Surface ->GetDC(&hdc);//デバイスコンテキストの取得
	SelectObject(hdc, hpen);
	//ライン描画処理
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	//オブジェクトのリリース
	DeleteObject(hpen);
	lpSurface[cnt].Surface ->ReleaseDC(hdc);
}
//グラフィック回転転送関数
Dtool::TurnBltFast(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int sou/*転送元番号*/,
			   RECT rc/*転送元レクト*/,int Angle/*回転角度*/,int cx/*を元に回転（中心）*/,int cy/*を元に回転（中心）*/,int tou)
{
	DDSURFACEDESC ddsrc,ddtar;
	unsigned char *psrc,*ptar;
	int TmpX,TmpY,i,j,left,top,right,bottom;
	//処理しやすいように4つの頂点の座標を配列に代入
	int xx[4]={0,0,rc.right-rc.left,rc.right-rc.left};
	int yy[4]={0,rc.bottom-rc.top,0,rc.bottom-rc.top};

	//角度を0-360の範囲内に修正
	Angle-=90;
	while(Angle<0){
		Angle+=360;
	}
	
	while(Angle>=360){
		Angle-=360;
	}

	//中心軸の分だけXY座標を補正
	x+=cx;
	y+=cy;

	//回転後の左右の端の座標をﾁｪｯｸ
	left=65535;
	right=0;
	for(i=0;i<4;i++){
		TmpX=(int)((xx[i]-cx)*cos_tbl[Angle]-(yy[i]-cy)*-sin_tbl[Angle]);
		if(TmpX<left)left=TmpX;
		if(TmpX>right)right=TmpX;
	}

	//回転後の上下の端の座標をﾁｪｯｸ
	top=65535;
	bottom=0;
	for(i=0;i<4;i++){
		TmpY=(int)((xx[i]-cx)*-sin_tbl[Angle]+(yy[i]-cy)*cos_tbl[Angle]);
		if(TmpY<top)top=TmpY;
		if(TmpY>bottom)bottom=TmpY;
	}
	
	//逆算のため、角度を反転させる(さらに0-360の範囲内に修正)
	Angle=-Angle;
	while(Angle<0){
		Angle+=360;
	}
	//転送元ｻｰﾌｪｽをﾛｯｸ
	memset(&ddsrc,0,sizeof(DDSURFACEDESC));
	ddsrc.dwSize=sizeof(ddsrc);
	result=lpSurface[sou].Surface->Lock(NULL,&ddsrc,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	psrc=(unsigned char *)ddsrc.lpSurface;

	//転送先ｻｰﾌｪｽをﾛｯｸ
	memset(&ddtar,0,sizeof(DDSURFACEDESC));
	ddtar.dwSize=sizeof(ddtar);
	result=lpSurface[tar].Surface->Lock(NULL,&ddtar,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	ptar=(unsigned char *)ddtar.lpSurface;


	if(result==DD_OK){
	//回転後の座標へ回転前の画像を転送する
	for(i=left;i<right;i++){
		//ｸﾘｯﾋﾟﾝｸﾞ
		if((x+i)<0||(x+i)>=320)continue;
		for(j=top;j<bottom;j++){
			//ｸﾘｯﾋﾟﾝｸﾞ
			if((y+j)<0||(y+j)>=240)continue;
			//回転前の座標を計算
			TmpX=(int)(i*cos_tbl[Angle]-j*-sin_tbl[Angle])+cx;
			TmpY=(int)(i*-sin_tbl[Angle]+j*cos_tbl[Angle])+cy;
			//元画像の範囲内でなければ転送しない
			if(TmpX<0)continue;
			if(TmpX>=rc.right-rc.left)continue;
			if(TmpY<0)continue;
			if(TmpY>=rc.bottom-rc.top)continue;
			//透明色は転送しない
			if(*(psrc+TmpX+rc.left+(TmpY+rc.top)*ddsrc.lPitch)==tou)continue;
			//転送先ｻｰﾌｪｽに点をｺﾋﾟｰ
			*(ptar+(x+i)+(y+j)*ddtar.lPitch)=*(psrc+TmpX+rc.left+(TmpY+rc.top)*ddsrc.lPitch);
		}
	}
	lpSurface[tar].Surface->Unlock(NULL);
	lpSurface[sou].Surface->Unlock(NULL);
	}
}

//半透明転送関数
Dtool::AlphaBltFast(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,
					 int sou/*転送元番号*/,RECT rc/*転送元レクト*/,char tomeido/*透明度*/,char flag/*フラグ*/)
{
	DDSURFACEDESC ddsrc,ddtar;
	unsigned char *psrc,*ptar;
	int i,j,i_temp,j_temp;
	char k,l;

	//転送元ｻｰﾌｪｽをﾛｯｸ
	memset(&ddsrc,0,sizeof(DDSURFACEDESC));
	ddsrc.dwSize=sizeof(ddsrc);
	result=lpSurface[sou].Surface->Lock(NULL,&ddsrc,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	psrc=(unsigned char *)ddsrc.lpSurface;

	//転送先ｻｰﾌｪｽをﾛｯｸ
	memset(&ddtar,0,sizeof(DDSURFACEDESC));
	ddtar.dwSize=sizeof(ddtar);
	result=lpSurface[tar].Surface->Lock(NULL,&ddtar,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	ptar=(unsigned char *)ddtar.lpSurface;

	if(result==DD_OK){
		for(i=rc.left;i<rc.right;i++){
			i_temp=i-rc.left ;
			//ｸﾘｯﾋﾟﾝｸﾞ
			if((x+i_temp)<0||(x+i_temp)>=320)continue;
			for(j=rc.top; j<rc.bottom ;j++){
				j_temp=j-rc.top  ;
				//ｸﾘｯﾋﾟﾝｸﾞ
				if((y+j_temp)<0||(y+j_temp)>=240)continue;
			
				//透明色は転送しない	
				if(*(psrc+i+j*ddsrc.lPitch)==253)continue;
				if(*(psrc+i+j*ddsrc.lPitch)==255)continue;

				switch(flag){
				case 0:
					//その色範囲の範囲の半透明
					l=*(psrc+i+j*ddsrc.lPitch)>>4;
					k=(*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)&0x0f)-tomeido;
					break;
				case 1:
					//背景とサーフェイス合わせて半透明					
					l=*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)>>4;
					k=*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)&0x0f;
					k+=(*(psrc+i+j*ddsrc.lPitch)&0x0f)-tomeido;
					break;
				case 2:
					//暗転、明転の半透明
					l=*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)>>4;
					k=(*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)&0x0f)-tomeido;
					break;
				default:
					break;
				}
				if(k<0){k=0;}if(k>15){k=15;}
				*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)=tomei_tbl[l][k];
			}
		}
	lpSurface[tar].Surface->Unlock(NULL);
	lpSurface[sou].Surface->Unlock(NULL);
	}

	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
}
//中心描画
Dtool::TurnBltFastCenter(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int sou/*転送元番号*/,
			   RECT rc/*転送元レクト*/,int Angle/*回転角度*/,int cx/*を元に回転（中心）*/,int cy/*を元に回転（中心）*/)
{	
	int width  = (int)((rc.right -rc.left )/2);
	int height = (int)((rc.bottom -rc.top )/2);
	TurnBltFast( tar,x-width,y-height,sou,rc,Angle,cx,cy,253);
}
//半透明転送関数
Dtool::AlphaBltFastCenter(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,
					 int sou/*転送元番号*/,RECT rc/*転送元レクト*/,char tomeido/*透明度*/,char flag/*フラグ*/)
{
	int width  = (int)((rc.right -rc.left )/2);
	int height = (int)((rc.bottom -rc.top )/2);
	AlphaBltFast( tar,x-width,y-height,sou,rc,tomeido,flag);
}
Dtool::TDAlphaBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z,
					 int sou/*転送元番号*/,RECT rc/*転送元レクト*/,char tomeido/*透明度*/,char flag/*フラグ*/)
{

	RECT src;	
	//cx,cyの座標に向かって３Ｄ転送
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//範囲内ならば
		//向かっていく位置を引く
		x = x - 145;
		y = y - 120;
		//現在位置を修正し、
		x = (int)(x * pers);
		y = (int)(y * pers);
		//向かっていく位置を足す		
		x = x + 145;
		y = y + 120;
		//拡大、縮小転送
		int width  = (int)((rc.right -rc.left )*zoom/2);
		int height = (int)((rc.bottom -rc.top )*zoom/2);
		src=ClipBlt(20,x-width,y-height,zoom,zoom,sou,rc,DDBLT_WAIT);
		AlphaBltFastCenter( tar,x,y,20,src,tomeido,flag);
	}
}
Dtool::AlphaBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z,float sx/*ｘ拡大率*/,float sy/*ｙ拡大率*/,
					 int sou/*転送元番号*/,RECT rc/*転送元レクト*/,char tomeido/*透明度*/,char flag/*フラグ*/)
{

	float pers = (float)(320.0f-z)/320.0f; 
	//向かっていく位置を引く
	x = x - 145;
	y = y - 120;
	//現在位置を修正し、
	x = (int)(x * pers);
	y = (int)(y * pers);
	//向かっていく位置を足す		
	x = x + 145;
	y = y + 120;

	RECT src;
	int width  = (int)((rc.right -rc.left )*sx/2);
	int height = (int)((rc.bottom -rc.top )*sy/2);
	src=ClipBlt(20,x-width,y-height,sx,sy,sou,rc,DDBLT_WAIT);
	AlphaBltFastCenter( tar,x,y,20,src,tomeido,flag);
}

Dtool::TDTurnBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z/*Ｚ座標*/,int sou/*転送元番号*/,
			   RECT rc/*転送元レクト*/,int Angle/*回転角度*/,int cx/*を元に回転（中心）*/,int cy/*を元に回転（中心）*/)
{
	RECT temp;
	//正方形の画像に限る
	unsigned int a=(rc.right -rc.left),b=(rc.bottom -rc.top);
	Cls(20,0,0,a,b,253);
	SetRect(&temp,0,0,a,b);
	TurnBltFast( 20,0,0,sou,rc,Angle,cx,cy,253);
	TDClipBltCenter(tar,x,y,z,145,120,20,temp,DDBLT_KEYSRC|DDBLT_WAIT);
}
//通常ブリットファースト
Dtool::BltFast(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,
				   int sou/*転送先番号*/,RECT rc/*転送先レクト*/,int flag/*フラグ*/){
	result=lpSurface[tar].Surface->BltFast(x,y,lpSurface[sou].Surface,&rc,flag);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
}

//クリップしてブリットファースト
Dtool::ClipBltFast(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,
				   int sou/*転送先番号*/,RECT rc/*転送先レクト*/,int flag/*フラグ*/){
	RECT dammy=rc;
	//クリッピング処理
	int w=rc.right -rc.left,h=rc.bottom -rc.top;
	if(x<0){
		dammy.left =rc.left +(0-x);
		x=0;
	}
	if((x+w)>320){
		dammy.right =rc.right -((x+w)-320);	
	}	
	if(y<0){
		dammy.top -=y;
		y=0;
	}
	if((y+h)>320){
		dammy.bottom  =rc.bottom  -((y+h)-320);	
	}
	result=lpSurface[tar].Surface->BltFast(x,y,lpSurface[sou].Surface,&dammy,flag);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
}
Dtool::ClipBltFast2(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,
				   int sou/*転送先番号*/,RECT rc/*転送先レクト*/,int flag/*フラグ*/){
	RECT dammy=rc;
	int w=rc.right -rc.left,h=rc.bottom -rc.top;
	if(x<0){
		dammy.left =rc.left +(0-x);
		x=0;
	}
	if((x+w)>320){
		dammy.right =rc.right -((x+w)-320);	
	}	
	if(y<0){
		dammy.top -=y;
		y=0;
	}
	if((y+h)>240){
		dammy.bottom  =rc.bottom  -((y+h)-240);	
	}
	result=lpSurface[tar].Surface->BltFast(x,y,lpSurface[sou].Surface,&dammy,flag);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
}
//フリップしてブリット
RECT Dtool::ClipBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,float sx/*Ｘ拡大率*/, float sy/*Ｙ拡大率*/,
			   int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{	
	//各変数
	RECT	spriteRect, myRect;
	float	blt_w = (rc.right - rc.left) * sx; 
	float 	blt_h = (rc.bottom - rc.top ) * sy;
	float	left_sub = 0, right_sub = 0, top_sub = 0, down_sub = 0;
	//クリッピング処理
	//描画が画面左端よりはみ出ている時の処理
	if (x < 0)	left_sub = -(float)x;
	//描画が画面右端よりはみ出ている時の処理
	if ((x + blt_w) > 320) right_sub = (float)320 - (x + blt_w);
	//描画が画面上端よりはみ出ている時の処理
	if (y < 0)	top_sub = -(float)y;
	//描画が画面下端よりはみ出ている時の処理
	if ((y + blt_h) > 320) down_sub = (float)320 - (y + blt_h);
	// 表示先補正
	spriteRect.left		= (int)((float)x + left_sub);
	spriteRect.top		= (int)((float)y + top_sub);
	spriteRect.right	= (int)((float)x + blt_w + right_sub);
	spriteRect.bottom	= (int)((float)y + blt_h + down_sub);
	// 表示元補正
	myRect.left			= rc.left + (int)(left_sub  / sx);
	myRect.top			= rc.top + (int)(top_sub   / sy);
	myRect.right		= rc.right + (int)(right_sub / sx);
	myRect.bottom		= rc.bottom + (int)(down_sub  / sy);
	//描画
	result=lpSurface[tar].Surface->Blt(&spriteRect,lpSurface[sou].Surface, &myRect,flag, NULL);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
	return spriteRect;
}

//中心描画
Dtool::ClipBltCenter(int tar/*転送先番号*/,int x,/*Ｘ座標*/int y/*Ｙ座標*/,float sx/*Ｘ拡大率*/, float sy/*Ｙ拡大率*/,
					 int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{	
	int width  = (int)((rc.right -rc.left )*sx/2);
	int height = (int)((rc.bottom -rc.top )*sy/2);
	ClipBlt(tar,x-width,y-height,sx,sy,sou,rc,flag);
}
//スクロールブリット
Dtool::ScroolBlt(int tar/*転送先番号*/,float *RollX/*ｘ変数*/,float *RollY/*Ｙ変数*/,float xSpeed/*ｘスピード*/,
				 float ySpeed/*Ｙスピード*/,int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{
	//各変数
	int   x,y;
	int   w=(rc.right  - rc.left ),h=(rc.bottom  - rc.top );
	//スクロール描画
	for (y = 0; y < 240 / h + 2; y++)
		for (x = 0; x < 320 / w + 2; x++)	
			ClipBltFast2(tar,x * w + (int)*RollX, y * h + (int)*RollY,sou,rc, flag);
	//移動量プラス
	*RollX += xSpeed;
	*RollY += ySpeed;
	//リミットを越えたら
	if (*RollX < (float)(-w)) *RollX += (float)w;
	if (*RollX > (float)(0))  *RollX -= (float)w;
	if (*RollY < (float)(-h)) *RollY += (float)h;
	if (*RollY > (float)(0))  *RollY -= (float)h;
}
//擬似３Ｄクリップ転送
Dtool::TDClipBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z/*Ｚ座標*/,
				 int cx,int cy,int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{
	//cx,cyの座標に向かって３Ｄ転送
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//範囲内ならば
		//向かっていく位置を引く
		x = x - cx;
		y = y - cy;
		//現在位置を修正し、
		x = (int)(x * pers);
		y = (int)(y * pers);
		//向かっていく位置を足す		
		x = x + cx;
		y = y + cy;
		//拡大、縮小転送
		ClipBlt(tar,x,y,zoom,zoom,sou,rc,flag);
	}
}
//擬似３Ｄクリップ転送
Dtool::TDClipBltCenter(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z/*Ｚ座標*/,
				 int cx,int cy,int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{
	//cx,cyの座標に向かって３Ｄ転送
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//範囲内ならば
		//向かっていく位置を引く
		x = x - cx;
		y = y - cy;
		//現在位置を修正し、
		x = (int)(x * pers);
		y = (int)(y * pers);
		//向かっていく位置を足す		
		x = x + cx;
		y = y + cy;
		//拡大、縮小転送
		ClipBltCenter(tar,x,y,zoom,zoom,sou,rc,flag);
	}
}
//擬似３Ｄ転送
Dtool::TDBlt(int tar/*転送先番号*/,int x/*Ｘ座標*/,int y/*Ｙ座標*/,int z/*Ｚ座標*/,
				 int cx,int cy,int sou/*転送元番号*/,RECT rc/*転送元レクト*/,int flag/*フラグ*/)
{
	//cx,cyの座標に向かって３Ｄ転送
	float pers = (float)(320.0f-z)/320.0f; 
	if (z < 320) {//範囲内ならば
		//向かっていく位置を引く
		x = x - cx;
		y = y - cy;
		//現在位置を修正し、
		x = (int)(x * pers);
		y = (int)(y * pers);
		//向かっていく位置を足す		
		x = x + cx;
		y = y + cy;
		//拡大、縮小転送
		ClipBltCenter(tar,x,y,1,1,sou,rc,flag);
	}
}
//リリース
Dtool::Release (){
	for(int i=1;i<DRAW_MAX-1;i++){
		if(lpSurface[i].Surface!=NULL){
			lpSurface[i].Surface ->Release ();
			lpSurface[i].Surface=NULL;
		}
	}
}
//フリップ
void Dtool::Flip (){
	lpPrimary->Flip(NULL,DDFLIP_WAIT);
	if(result!=DD_OK)return;
}
