///////////////////////////////////////////////////////////////////////////
//		�h���[�c�[���N���X�@�b�o�o
//								    Programmed by �G�~�@���j				
///////////////////////////////////////////////////////////////////////////

#include"main.h"

//�R���X�g���N�^
Dtool::Dtool(){
}
//�f�X�g���N�^
Dtool::~Dtool (){
	for(int i=0;i<DRAW_MAX;i++){
		if(lpSurface[i].Surface!=NULL){
			//�f�[�^�������Ă���΃����[�X�A�m�t�k�k
			lpSurface[i].Surface->Release();
			lpSurface[i].Surface=NULL;	
		}	
	}
	//�h���[�̉��
	//�f�B�X�v���C���[�h�����ɖ߂�	
	lpDDraw->RestoreDisplayMode();
	//primary&backbuffer������
	lpPrimary->Release();
}
//�G72�����i�s�֐�
void Dtool::move72(int *x,int *y,char dir,int kyori){
	if(dir<0)return;
	(*x)+=(int)(kyori*cos_tbl[dir*5]);
	(*y)-=(int)(kyori*sin_tbl[dir*5]);
}
//�_�C���N�g�̃C�j�V�����C�Y
Dtool::Init(HWND hwnd){
	//�E�B���h�E�n���h���̕ۑ�
	Hwnd = hwnd;
	//�e�\����
	DDSURFACEDESC Dds;
	DDSCAPS Ddscaps;
	//---------------------DirectDraw�֘A-----------------------
	//ddraw���N���G�C�g
	result=DirectDrawCreate(NULL,&lpDDraw,NULL);
	if(result!=DD_OK)Error(Hwnd,"�_�C���N�g�h���[�̐������o���܂���");
	
	//�t���X�N���[�����[�h��
	result=lpDDraw->SetCooperativeLevel(hwnd,DDSCL_EXCLUSIVE|DDSCL_FULLSCREEN|DDSCL_ALLOWREBOOT|DDSCL_ALLOWMODEX);
	if(result!=DD_OK)Error(Hwnd,"�l�n�c�d�w�Ńt���X�N���[�����o���܂���");
	
	//��ʂ̑傫���ƐF���̌���
	result=lpDDraw->SetDisplayMode(SCREEN_WIDTH,SCREEN_HEIGHT,8);
	if(result!=DD_OK)Error(Hwnd,"�𑜓x���ύX�ł��܂���");
	
	//Dds�̐ݒ��primary�T�[�t�@�X�̍쐬
	Dds.dwSize=sizeof(Dds);
	Dds.dwFlags=DDSD_CAPS|DDSD_BACKBUFFERCOUNT;
	Dds.ddsCaps.dwCaps=DDSCAPS_PRIMARYSURFACE|DDSCAPS_FLIP|DDSCAPS_COMPLEX;
	Dds.dwBackBufferCount=1;
	result=lpDDraw->CreateSurface (&Dds,&lpPrimary,NULL);
	if(result!=DD_OK)Error(Hwnd,"�v���C�}���[�T�[�t�F�C�X�������o���܂���");
	
	Ddscaps.dwCaps=DDSCAPS_BACKBUFFER;
	result=lpPrimary->GetAttachedSurface(&Ddscaps,&lpSurface[0].Surface);
	if(result!=DD_OK)Error(Hwnd,"�v���C�}���[�T�[�t�F�C�X���A�^�b�`�o���܂���");
	//�O�Ԃ̓o�b�N�o�b�t�@
	for(int i=1;i<DRAW_MAX;i++)
		lpSurface[i].Surface =NULL;

	//	//�������A��]�̊g�k�p�e���v�T�[�t�F�C�X
	MakeSurface(20,320,320,DDSCAPS_OFFSCREENPLAIN|DDSCAPS_SYSTEMMEMORY,253);
	
	//�������e�[�u���̌v�Z
	for(int j=0,k=0,l=0;j<256;j++){
		if(k==16){l++;k=0;}		
		tomei_tbl[l][k]=j;
		k++;
	}
	//sin.cos�̌v�Z
	for(i=0;i<360;i++){
		cos_tbl[i]=(float)cos(i*3.141592/180);
		sin_tbl[i]=(float)sin(i*3.141592/180);	
	}

}
//�r�b�g�}�b�v�̃��[�h
void Dtool::MakeSurface(char draw_cnt,char *fname,int flag,int color){
	//�o�b�N�o�b�t�@�̏ꍇ���^�[��
	if(draw_cnt==0)return;
	//�T�[�t�F�C�X����邽�߂̐ݒ�
	DDSURFACEDESC Dds;
	//�T�C�Y�̎擾
	Dds.dwSize=sizeof(Dds);
	//�t���O�𗧂Ă����̂��g�p�ł���
	Dds.dwFlags=DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH;
	//�u�q�`�l�A�V�X�e�����������g�p���邩�ݒ�
	Dds.ddsCaps.dwCaps=flag;

	//�e��ϐ���
	HBITMAP hBmp=NULL;
	BITMAP bm;
	HDC hdc,hMemdc;
	LPDIRECTDRAWPALETTE lpPal;
	RGBQUAD rgb[256];
	
	//�r�b�g�}�b�v�̏��擾
	hBmp=(HBITMAP)LoadImage(GetModuleHandle(NULL),fname,IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	GetObject(hBmp,sizeof(bm),&bm);

	//direct X5�ł́A���C���T�[�t�F�X��艡���͑傫�����Ȃ�
	Dds.dwWidth = bm.bmWidth > SCREEN_WIDTH ? SCREEN_WIDTH : bm.bmWidth;
	Dds.dwHeight = abs(bm.bmHeight);
	//�T�[�t�F�C�X�̃N���G�C�g
	lpDDraw->CreateSurface(&Dds,&lpSurface[draw_cnt].Surface,NULL);

	hMemdc=CreateCompatibleDC(NULL);
	SelectObject(hMemdc,hBmp);
	GetDIBColorTable(hMemdc,0,256,rgb);
	//�p���b�g�̕ۑ�
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
	//�p���b�g�����
	lpDDraw->CreatePalette(DDPCAPS_8BIT,pe,&lpPal,NULL);
	//�p���b�g�Z�b�g����
	lpPrimary->SetPalette(lpPal);
	//�r�b�g�}�b�v����������[�t�F�C�X�ɓ]��
	result=lpSurface[draw_cnt].Surface->GetDC(&hdc);
	if(result!=DD_OK)return;
	BitBlt(hdc,0,0,bm.bmWidth,bm.bmHeight,hMemdc,0,0,SRCCOPY);
	lpSurface[draw_cnt].Surface->ReleaseDC(hdc);
	//�g���I�������J�����悤�ˁI
	DeleteDC(hMemdc);
	lpPal->Release();
	DeleteObject(hBmp);
	//�J���[�L�[�̐ݒ�
	DDCOLORKEY key;
	//�J���[�L�[�̍ő�l�A�ŏ��l�ݒ�
	key.dwColorSpaceHighValue=color;
	key.dwColorSpaceLowValue=color;
	//�J���[�L�[�̃Z�b�g
	result=lpSurface[draw_cnt].Surface->SetColorKey (DDCKEY_SRCBLT,&key);
	if(result!=DD_OK)return;
	//���X�g���̕ۑ��p//
	//�ēǍ��Ɏg�p
	sprintf(lpSurface[draw_cnt].SaveData, "%s", fname);
	//�X�v���C�g�T�C�Y�̎擾
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
//�r�b�g�}�b�v�̃��[�h
void Dtool::MakeSurface(char draw_cnt,int w,int h,int flag,int color){
	//�o�b�N�o�b�t�@�̏ꍇ���^�[��
	if(draw_cnt==0)return;
	//�T�[�t�F�C�X����邽�߂̐ݒ�
	DDSURFACEDESC Dds;
	//�T�C�Y�̎擾
	Dds.dwSize=sizeof(Dds);
	//�t���O�𗧂Ă����̂��g�p�ł���
	Dds.dwFlags=DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH;
	//�u�q�`�l�A�V�X�e�����������g�p���邩�ݒ�
	Dds.ddsCaps.dwCaps=flag;
	//direct X5�ł́A���C���T�[�t�F�X��艡���͑傫�����Ȃ�
	Dds.dwWidth =w ;
	Dds.dwHeight =h ;
	//�T�[�t�F�C�X�̃N���G�C�g
	lpDDraw->CreateSurface(&Dds,&lpSurface[draw_cnt].Surface,NULL);
	//�J���[�L�[�̐ݒ�
	DDCOLORKEY key;
	//�J���[�L�[�̍ő�l�A�ŏ��l�ݒ�
	key.dwColorSpaceHighValue=color;
	key.dwColorSpaceLowValue=color;
	//�J���[�L�[�̃Z�b�g
	lpSurface[draw_cnt].Surface->SetColorKey (DDCKEY_SRCBLT,&key);

	//���X�g���̕ۑ��p//
	//�ēǍ��Ɏg�p
	sprintf(lpSurface[draw_cnt].SaveData, "NULL");
	//�X�v���C�g�T�C�Y�̎擾
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

//�͈͎w��h��Ԃ�
Dtool::Cls(int cnt,int x,int y,int w,int h,int color){
	RECT Scr={x,y,w,h};
	DDBLTFX dfx;
	dfx.dwSize=sizeof(dfx);
	//�F�̐ݒ�
	dfx.dwFillColor=color;
	//�o�b�N�o�b�t�@��h��Ԃ�
	lpSurface[cnt].Surface ->Blt(&Scr,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&dfx);	
}
Dtool::GetDC  (int cnt,HDC *hdc){
	lpSurface[cnt].Surface ->GetDC (hdc);
}
Dtool::ReleaseDC (int cnt,HDC hdc){
	lpSurface[cnt].Surface ->ReleaseDC (hdc);
}
//�t�H���g�`��֐�
Dtool::FontShow(int cnt,char *str, int size, int x, int y, int rgb)
{
	//�t�H���g�����ϐ�
	static HFONT    NewFont,OldFont;;
	static HDC      hdc;
	static PLOGFONT FontInfo;
	
	lpSurface[cnt].Surface->GetDC(&hdc);
	//�t�H���g�C���t�H������
	FontInfo  = (PLOGFONT)GlobalAlloc(GPTR, sizeof(LOGFONT));
	//�t�H���g�^�C�v�ݒ�
	BOOL Bold = TRUE;
	lstrcpy(FontInfo->lfFaceName, "�W������");
	FontInfo->lfWeight     = (Bold == FALSE)*FW_NORMAL + (Bold == TRUE)*FW_BOLD;
	FontInfo->lfEscapement = 0;
	FontInfo->lfWidth      = 0;
	FontInfo->lfHeight     = size;
	FontInfo->lfItalic     = false;
	FontInfo->lfUnderline  = FALSE;
	FontInfo->lfCharSet    = SHIFTJIS_CHARSET;

	//�f�o�C�X�R���e�L�X�g�擾
	NewFont = CreateFontIndirect(FontInfo);
	OldFont = (HFONT)SelectObject(hdc, NewFont);
	//������`�揈��
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, rgb);
	TextOut(hdc, x, y, str, strlen(str));
	//�f�o�C�X�R���e�L�X�g�J��
	SelectObject(hdc, OldFont);
	DeleteObject(NewFont);
	lpSurface[cnt].Surface->ReleaseDC(hdc);
	//�t�H���g�C���t�H�J��
	GlobalFree((LOCALHANDLE)FontInfo);
}
//���̃p���b�g��
char Dtool::BlackIn(char nrgb){	
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//�����珜���Ɍ��ɖ߂��Ă���
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
	//�S�Č��ɖ߂�����
	if(check==1){return 1;}
	return 0;
}
//�t�F�[�h�A�E�g
char Dtool::BlackOut(char nrgb){
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//�����ɍ���
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
	//�S�č��ɂȂ�����
	if(check==1){return 1;}
	return 0;
}
//���̃p���b�g��
char Dtool::WhiteIn(char nrgb){	
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//�����珜���Ɍ���
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
	//�S�Č��ɖ߂�����
	if(check==1){return 1;}
	return 0;
}
//�t�F�[�h�A�E�g
char Dtool::WhiteOut(char nrgb){
	char check=1;
	LPDIRECTDRAWPALETTE lpPal;
	//�����ɔ���
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
	//�S�Ĕ��Ȃ�
	if(check==1){return 1;}
	return 0;
}
//�o�b�N�o�b�t�@�̃��X�g�A
Dtool::BackRestore(){
	lpPrimary->Restore();
	lpSurface[0].Surface->Restore ();
}
//�w��T�[�t�F�C�X�̃��X�g�A
Dtool::Restore(int cnt){
	lpSurface[cnt].Surface ->Restore ();
	if(lpSurface[cnt].kind ==0)
		MakeSurface(cnt,lpSurface[cnt].SaveData ,lpSurface[cnt].flag ,lpSurface[cnt].ColorKey);
	else
		MakeSurface(cnt,lpSurface[cnt].dwWidth ,lpSurface[cnt].dwHeight,lpSurface[cnt].flag ,lpSurface[cnt].ColorKey);
}
//���C���`��֐�
Dtool::DrawLine(int cnt/*�]����ԍ�*/,int x1/*�w��*/,int y1/*�w��*/,int x2/*�w��*/,int y2/*�x��*/,int size/*�y���T�C�Y*/,int rgb/*�F*/)
{
	HDC hdc;
	HPEN hpen;
	hpen = CreatePen(PS_SOLID,size,rgb); //�`��p�y���̍쐬
	lpSurface[cnt].Surface ->GetDC(&hdc);//�f�o�C�X�R���e�L�X�g�̎擾
	SelectObject(hdc, hpen);
	//���C���`�揈��
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	//�I�u�W�F�N�g�̃����[�X
	DeleteObject(hpen);
	lpSurface[cnt].Surface ->ReleaseDC(hdc);
}
//�O���t�B�b�N��]�]���֐�
Dtool::TurnBltFast(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int sou/*�]�����ԍ�*/,
			   RECT rc/*�]�������N�g*/,int Angle/*��]�p�x*/,int cx/*�����ɉ�]�i���S�j*/,int cy/*�����ɉ�]�i���S�j*/,int tou)
{
	DDSURFACEDESC ddsrc,ddtar;
	unsigned char *psrc,*ptar;
	int TmpX,TmpY,i,j,left,top,right,bottom;
	//�������₷���悤��4�̒��_�̍��W��z��ɑ��
	int xx[4]={0,0,rc.right-rc.left,rc.right-rc.left};
	int yy[4]={0,rc.bottom-rc.top,0,rc.bottom-rc.top};

	//�p�x��0-360�͈͓̔��ɏC��
	Angle-=90;
	while(Angle<0){
		Angle+=360;
	}
	
	while(Angle>=360){
		Angle-=360;
	}

	//���S���̕�����XY���W��␳
	x+=cx;
	y+=cy;

	//��]��̍��E�̒[�̍��W������
	left=65535;
	right=0;
	for(i=0;i<4;i++){
		TmpX=(int)((xx[i]-cx)*cos_tbl[Angle]-(yy[i]-cy)*-sin_tbl[Angle]);
		if(TmpX<left)left=TmpX;
		if(TmpX>right)right=TmpX;
	}

	//��]��̏㉺�̒[�̍��W������
	top=65535;
	bottom=0;
	for(i=0;i<4;i++){
		TmpY=(int)((xx[i]-cx)*-sin_tbl[Angle]+(yy[i]-cy)*cos_tbl[Angle]);
		if(TmpY<top)top=TmpY;
		if(TmpY>bottom)bottom=TmpY;
	}
	
	//�t�Z�̂��߁A�p�x�𔽓]������(�����0-360�͈͓̔��ɏC��)
	Angle=-Angle;
	while(Angle<0){
		Angle+=360;
	}
	//�]������̪���ۯ�
	memset(&ddsrc,0,sizeof(DDSURFACEDESC));
	ddsrc.dwSize=sizeof(ddsrc);
	result=lpSurface[sou].Surface->Lock(NULL,&ddsrc,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	psrc=(unsigned char *)ddsrc.lpSurface;

	//�]���滰̪���ۯ�
	memset(&ddtar,0,sizeof(DDSURFACEDESC));
	ddtar.dwSize=sizeof(ddtar);
	result=lpSurface[tar].Surface->Lock(NULL,&ddtar,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	ptar=(unsigned char *)ddtar.lpSurface;


	if(result==DD_OK){
	//��]��̍��W�։�]�O�̉摜��]������
	for(i=left;i<right;i++){
		//�د��ݸ�
		if((x+i)<0||(x+i)>=320)continue;
		for(j=top;j<bottom;j++){
			//�د��ݸ�
			if((y+j)<0||(y+j)>=240)continue;
			//��]�O�̍��W���v�Z
			TmpX=(int)(i*cos_tbl[Angle]-j*-sin_tbl[Angle])+cx;
			TmpY=(int)(i*-sin_tbl[Angle]+j*cos_tbl[Angle])+cy;
			//���摜�͈͓̔��łȂ���Γ]�����Ȃ�
			if(TmpX<0)continue;
			if(TmpX>=rc.right-rc.left)continue;
			if(TmpY<0)continue;
			if(TmpY>=rc.bottom-rc.top)continue;
			//�����F�͓]�����Ȃ�
			if(*(psrc+TmpX+rc.left+(TmpY+rc.top)*ddsrc.lPitch)==tou)continue;
			//�]���滰̪��ɓ_���߰
			*(ptar+(x+i)+(y+j)*ddtar.lPitch)=*(psrc+TmpX+rc.left+(TmpY+rc.top)*ddsrc.lPitch);
		}
	}
	lpSurface[tar].Surface->Unlock(NULL);
	lpSurface[sou].Surface->Unlock(NULL);
	}
}

//�������]���֐�
Dtool::AlphaBltFast(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,
					 int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,char tomeido/*�����x*/,char flag/*�t���O*/)
{
	DDSURFACEDESC ddsrc,ddtar;
	unsigned char *psrc,*ptar;
	int i,j,i_temp,j_temp;
	char k,l;

	//�]������̪���ۯ�
	memset(&ddsrc,0,sizeof(DDSURFACEDESC));
	ddsrc.dwSize=sizeof(ddsrc);
	result=lpSurface[sou].Surface->Lock(NULL,&ddsrc,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	psrc=(unsigned char *)ddsrc.lpSurface;

	//�]���滰̪���ۯ�
	memset(&ddtar,0,sizeof(DDSURFACEDESC));
	ddtar.dwSize=sizeof(ddtar);
	result=lpSurface[tar].Surface->Lock(NULL,&ddtar,DDLOCK_WAIT|DDLOCK_SURFACEMEMORYPTR,NULL);
	ptar=(unsigned char *)ddtar.lpSurface;

	if(result==DD_OK){
		for(i=rc.left;i<rc.right;i++){
			i_temp=i-rc.left ;
			//�د��ݸ�
			if((x+i_temp)<0||(x+i_temp)>=320)continue;
			for(j=rc.top; j<rc.bottom ;j++){
				j_temp=j-rc.top  ;
				//�د��ݸ�
				if((y+j_temp)<0||(y+j_temp)>=240)continue;
			
				//�����F�͓]�����Ȃ�	
				if(*(psrc+i+j*ddsrc.lPitch)==253)continue;
				if(*(psrc+i+j*ddsrc.lPitch)==255)continue;

				switch(flag){
				case 0:
					//���̐F�͈͈͂̔͂̔�����
					l=*(psrc+i+j*ddsrc.lPitch)>>4;
					k=(*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)&0x0f)-tomeido;
					break;
				case 1:
					//�w�i�ƃT�[�t�F�C�X���킹�Ĕ�����					
					l=*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)>>4;
					k=*(ptar+(x+i_temp)+(y+j_temp)*ddtar.lPitch)&0x0f;
					k+=(*(psrc+i+j*ddsrc.lPitch)&0x0f)-tomeido;
					break;
				case 2:
					//�Ó]�A���]�̔�����
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
//���S�`��
Dtool::TurnBltFastCenter(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int sou/*�]�����ԍ�*/,
			   RECT rc/*�]�������N�g*/,int Angle/*��]�p�x*/,int cx/*�����ɉ�]�i���S�j*/,int cy/*�����ɉ�]�i���S�j*/)
{	
	int width  = (int)((rc.right -rc.left )/2);
	int height = (int)((rc.bottom -rc.top )/2);
	TurnBltFast( tar,x-width,y-height,sou,rc,Angle,cx,cy,253);
}
//�������]���֐�
Dtool::AlphaBltFastCenter(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,
					 int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,char tomeido/*�����x*/,char flag/*�t���O*/)
{
	int width  = (int)((rc.right -rc.left )/2);
	int height = (int)((rc.bottom -rc.top )/2);
	AlphaBltFast( tar,x-width,y-height,sou,rc,tomeido,flag);
}
Dtool::TDAlphaBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z,
					 int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,char tomeido/*�����x*/,char flag/*�t���O*/)
{

	RECT src;	
	//cx,cy�̍��W�Ɍ������ĂR�c�]��
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//�͈͓��Ȃ��
		//�������Ă����ʒu������
		x = x - 145;
		y = y - 120;
		//���݈ʒu���C�����A
		x = (int)(x * pers);
		y = (int)(y * pers);
		//�������Ă����ʒu�𑫂�		
		x = x + 145;
		y = y + 120;
		//�g��A�k���]��
		int width  = (int)((rc.right -rc.left )*zoom/2);
		int height = (int)((rc.bottom -rc.top )*zoom/2);
		src=ClipBlt(20,x-width,y-height,zoom,zoom,sou,rc,DDBLT_WAIT);
		AlphaBltFastCenter( tar,x,y,20,src,tomeido,flag);
	}
}
Dtool::AlphaBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z,float sx/*���g�嗦*/,float sy/*���g�嗦*/,
					 int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,char tomeido/*�����x*/,char flag/*�t���O*/)
{

	float pers = (float)(320.0f-z)/320.0f; 
	//�������Ă����ʒu������
	x = x - 145;
	y = y - 120;
	//���݈ʒu���C�����A
	x = (int)(x * pers);
	y = (int)(y * pers);
	//�������Ă����ʒu�𑫂�		
	x = x + 145;
	y = y + 120;

	RECT src;
	int width  = (int)((rc.right -rc.left )*sx/2);
	int height = (int)((rc.bottom -rc.top )*sy/2);
	src=ClipBlt(20,x-width,y-height,sx,sy,sou,rc,DDBLT_WAIT);
	AlphaBltFastCenter( tar,x,y,20,src,tomeido,flag);
}

Dtool::TDTurnBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z/*�y���W*/,int sou/*�]�����ԍ�*/,
			   RECT rc/*�]�������N�g*/,int Angle/*��]�p�x*/,int cx/*�����ɉ�]�i���S�j*/,int cy/*�����ɉ�]�i���S�j*/)
{
	RECT temp;
	//�����`�̉摜�Ɍ���
	unsigned int a=(rc.right -rc.left),b=(rc.bottom -rc.top);
	Cls(20,0,0,a,b,253);
	SetRect(&temp,0,0,a,b);
	TurnBltFast( 20,0,0,sou,rc,Angle,cx,cy,253);
	TDClipBltCenter(tar,x,y,z,145,120,20,temp,DDBLT_KEYSRC|DDBLT_WAIT);
}
//�ʏ�u���b�g�t�@�[�X�g
Dtool::BltFast(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,
				   int sou/*�]����ԍ�*/,RECT rc/*�]���惌�N�g*/,int flag/*�t���O*/){
	result=lpSurface[tar].Surface->BltFast(x,y,lpSurface[sou].Surface,&rc,flag);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
}

//�N���b�v���ău���b�g�t�@�[�X�g
Dtool::ClipBltFast(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,
				   int sou/*�]����ԍ�*/,RECT rc/*�]���惌�N�g*/,int flag/*�t���O*/){
	RECT dammy=rc;
	//�N���b�s���O����
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
Dtool::ClipBltFast2(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,
				   int sou/*�]����ԍ�*/,RECT rc/*�]���惌�N�g*/,int flag/*�t���O*/){
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
//�t���b�v���ău���b�g
RECT Dtool::ClipBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,float sx/*�w�g�嗦*/, float sy/*�x�g�嗦*/,
			   int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{	
	//�e�ϐ�
	RECT	spriteRect, myRect;
	float	blt_w = (rc.right - rc.left) * sx; 
	float 	blt_h = (rc.bottom - rc.top ) * sy;
	float	left_sub = 0, right_sub = 0, top_sub = 0, down_sub = 0;
	//�N���b�s���O����
	//�`�悪��ʍ��[���͂ݏo�Ă��鎞�̏���
	if (x < 0)	left_sub = -(float)x;
	//�`�悪��ʉE�[���͂ݏo�Ă��鎞�̏���
	if ((x + blt_w) > 320) right_sub = (float)320 - (x + blt_w);
	//�`�悪��ʏ�[���͂ݏo�Ă��鎞�̏���
	if (y < 0)	top_sub = -(float)y;
	//�`�悪��ʉ��[���͂ݏo�Ă��鎞�̏���
	if ((y + blt_h) > 320) down_sub = (float)320 - (y + blt_h);
	// �\����␳
	spriteRect.left		= (int)((float)x + left_sub);
	spriteRect.top		= (int)((float)y + top_sub);
	spriteRect.right	= (int)((float)x + blt_w + right_sub);
	spriteRect.bottom	= (int)((float)y + blt_h + down_sub);
	// �\�����␳
	myRect.left			= rc.left + (int)(left_sub  / sx);
	myRect.top			= rc.top + (int)(top_sub   / sy);
	myRect.right		= rc.right + (int)(right_sub / sx);
	myRect.bottom		= rc.bottom + (int)(down_sub  / sy);
	//�`��
	result=lpSurface[tar].Surface->Blt(&spriteRect,lpSurface[sou].Surface, &myRect,flag, NULL);
	
	if(result== DDERR_SURFACELOST){
		BackRestore();
		Restore(tar);
		Restore(sou);
	}
	return spriteRect;
}

//���S�`��
Dtool::ClipBltCenter(int tar/*�]����ԍ�*/,int x,/*�w���W*/int y/*�x���W*/,float sx/*�w�g�嗦*/, float sy/*�x�g�嗦*/,
					 int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{	
	int width  = (int)((rc.right -rc.left )*sx/2);
	int height = (int)((rc.bottom -rc.top )*sy/2);
	ClipBlt(tar,x-width,y-height,sx,sy,sou,rc,flag);
}
//�X�N���[���u���b�g
Dtool::ScroolBlt(int tar/*�]����ԍ�*/,float *RollX/*���ϐ�*/,float *RollY/*�x�ϐ�*/,float xSpeed/*���X�s�[�h*/,
				 float ySpeed/*�x�X�s�[�h*/,int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{
	//�e�ϐ�
	int   x,y;
	int   w=(rc.right  - rc.left ),h=(rc.bottom  - rc.top );
	//�X�N���[���`��
	for (y = 0; y < 240 / h + 2; y++)
		for (x = 0; x < 320 / w + 2; x++)	
			ClipBltFast2(tar,x * w + (int)*RollX, y * h + (int)*RollY,sou,rc, flag);
	//�ړ��ʃv���X
	*RollX += xSpeed;
	*RollY += ySpeed;
	//���~�b�g���z������
	if (*RollX < (float)(-w)) *RollX += (float)w;
	if (*RollX > (float)(0))  *RollX -= (float)w;
	if (*RollY < (float)(-h)) *RollY += (float)h;
	if (*RollY > (float)(0))  *RollY -= (float)h;
}
//�[���R�c�N���b�v�]��
Dtool::TDClipBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z/*�y���W*/,
				 int cx,int cy,int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{
	//cx,cy�̍��W�Ɍ������ĂR�c�]��
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//�͈͓��Ȃ��
		//�������Ă����ʒu������
		x = x - cx;
		y = y - cy;
		//���݈ʒu���C�����A
		x = (int)(x * pers);
		y = (int)(y * pers);
		//�������Ă����ʒu�𑫂�		
		x = x + cx;
		y = y + cy;
		//�g��A�k���]��
		ClipBlt(tar,x,y,zoom,zoom,sou,rc,flag);
	}
}
//�[���R�c�N���b�v�]��
Dtool::TDClipBltCenter(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z/*�y���W*/,
				 int cx,int cy,int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{
	//cx,cy�̍��W�Ɍ������ĂR�c�]��
	float pers = (float)(320.0f-z)/320.0f; 
	float zoom = pers*0.9f + 0.1f;
	if (z < 320) {//�͈͓��Ȃ��
		//�������Ă����ʒu������
		x = x - cx;
		y = y - cy;
		//���݈ʒu���C�����A
		x = (int)(x * pers);
		y = (int)(y * pers);
		//�������Ă����ʒu�𑫂�		
		x = x + cx;
		y = y + cy;
		//�g��A�k���]��
		ClipBltCenter(tar,x,y,zoom,zoom,sou,rc,flag);
	}
}
//�[���R�c�]��
Dtool::TDBlt(int tar/*�]����ԍ�*/,int x/*�w���W*/,int y/*�x���W*/,int z/*�y���W*/,
				 int cx,int cy,int sou/*�]�����ԍ�*/,RECT rc/*�]�������N�g*/,int flag/*�t���O*/)
{
	//cx,cy�̍��W�Ɍ������ĂR�c�]��
	float pers = (float)(320.0f-z)/320.0f; 
	if (z < 320) {//�͈͓��Ȃ��
		//�������Ă����ʒu������
		x = x - cx;
		y = y - cy;
		//���݈ʒu���C�����A
		x = (int)(x * pers);
		y = (int)(y * pers);
		//�������Ă����ʒu�𑫂�		
		x = x + cx;
		y = y + cy;
		//�g��A�k���]��
		ClipBltCenter(tar,x,y,1,1,sou,rc,flag);
	}
}
//�����[�X
Dtool::Release (){
	for(int i=1;i<DRAW_MAX-1;i++){
		if(lpSurface[i].Surface!=NULL){
			lpSurface[i].Surface ->Release ();
			lpSurface[i].Surface=NULL;
		}
	}
}
//�t���b�v
void Dtool::Flip (){
	lpPrimary->Flip(NULL,DDFLIP_WAIT);
	if(result!=DD_OK)return;
}
