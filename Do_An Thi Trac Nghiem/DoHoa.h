#pragma once

#include "Define.h"
#include "ctdl.h"
#include "xuly.h"

using namespace std;

int mapID[WIDTH][HEIGHT];

// Map ID
void ResetmapID();
void GanID();

void reset_layout(int x1,int y1,int x2,int y2, int color);

// Draw
void TaoHCN(int x1, int y1, int x2, int y2,int mau,int id, int mauvien);

void reset_layout(int x1,int y1,int x2,int y2, int color);

// ho tro
void validateText(char s[]);
void xoaKiTu(char s[90],int vitrixoa);
void xoaKhoangTrangDauVaKeNhau(char *str);
void xoaKhoangTrangCuoi(char *str);

// Input
void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space);

// draw tab
void drawSign();
void drawMenu();
void drawSV(DS_LOP &ds_lop,DS_SINH_VIEN &ds_sv);
void drawLop(DS_LOP &ds_lop);
void drawDS_LOP(DS_LOP &ds_lop);
void drawMonhoc();

// xu ly
void sign();
void menu();
void SV();
void lop();
void monhoc();


//
void menu();
void all();

void ResetmapID()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			mapID[i][j] = 0;
		}
	}
}

void GanID(int x1, int y1, int x2, int y2, int id)
{
	for (int i = x1; i < x2; i++)
	{
		for (int j = y1; j < y2; j++)
		{
			mapID[i][j] = id;
		}
	}
}
void TaoHCN(int x1, int y1, int x2, int y2,int mau,int id, int mauvien)
{
	setfillstyle(1, mau);
	bar(x1, y1, x2, y2);
	setcolor(mauvien);
	rectangle(x1, y1, x2, y2);
}

void reset_layout(int x1,int y1,int x2,int y2, int color) { //ve chong bar len ben tren 
	setfillstyle(1,color);
	bar(x1,y1,x2,y2);
}

void validateText(char s[]) {
	xoaKhoangTrangDauVaKeNhau(s);
    xoaKhoangTrangCuoi(s);
	
	for (int i = 0; s[i] != '\0'; i++)  //in hoa chu cai dau cua tung tu`
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if (s[i - 1] == ' ' || i == 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
        }
    }
}

void xoaKiTu(char s[90],int vitrixoa)
{
	int n=strlen(s);
    for(int i=vitrixoa; i<n; i++)
     s[i]=s[i+1];
	s[n-1]='\0'; //giam di do dai chuoi
}
void xoaKhoangTrangCuoi(char *str) {
	if(str[strlen(str)-1]==' ') //xoa khoang trang cuoi chuoi
		xoaKiTu(str,strlen(str)-1);
}

//xoa khoang trang dau chuoi va ke nhau
void xoaKhoangTrangDauVaKeNhau(char *str) {
	for(int i=0;i<strlen(str);i++)  
		if(str[i]==' '&& str[i+1]==' ')  //Neu cac khoang trang ke nhau
		{
			xoaKiTu(str,i);
			i--;
		}
    if(str[0]==' ') //xoa khoang trang dau chuoi
		xoaKiTu(str,0);
}

void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space){
	while(kbhit())	char c= getch();   //======nuot phim khi chua click

	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);

	int l = strlen(s);
	s[l+1] = '\0';
	s[l] = '|';
	while(true){
		outtextxy(x,y,s);
		delay(0.0001);
		clearmouseclick(WM_LBUTTONDOWN);

		if(kbhit()){
			char c = getch();
				//Neu space = 1 thi khong cho nhap space, space = 0 thi cho nhap space 

			if(('a'<=c && c<='z'||'A'<=c && c<='Z'||'0'<=c && c<='9' ) && l < maxLen && space == 1){
				if('a' <= c && c<= 'z') {
					c = c - 32;
				}
				s[l] = c;
				l++;
				s[l] = '\0'; //ky tu ket thuc
			
				outtextxy(x,y,s);
			
			}
			else if(('a'<=c && c<='z'||'A'<=c && c<='Z'||'0'<=c && c<='9' || c == ' ' ) && l < maxLen && space == 0){
			
				s[l] = c;
				l++;
				s[l] = '\0'; //ky tu ket thuc
				outtextxy(x,y,s);
			}
			else if(c==8 && l!=0){ //backspace
	
				s[l-1] = '|';
				s[l] = ' ';
				outtextxy(x,y,s);
				l--;					
					
			}
			else if(c==13){ // check enter
				s[l] = '\0';
				if(space == 0) {
					reset_layout(x, y, x1 - 1, y1 - 1, MAU_TRANG);
					validateText(s);
				}
				outtextxy(x,y,s);
				break;
			}
					
		
		}
		else { //neu khong co phim nhap vao
			s[l] = '|';
			delay(100);
			outtextxy(x,y,s);
			s[l] = ' ';
			delay(100);
			outtextxy(x,y,s);
		}	
	}
}
void drawSign()
{
	ResetmapID();
	
	settextstyle(10,0,5);
	setcolor(MAU_DEN);
	outtextxy(490,120,"THI TRAC NGHIEM");
		
	setbkcolor(MAU_XANH_DUONG_NHAT);
	outtextxy(580,270,"ÐANG NHAP");
		
	settextstyle(10,0,2);
	outtextxy(485,360,"User");
	TaoHCN(540,350,840,400,MAU_TRANG,1,MAU_DEN);
	GanID(540,350,840,400,1);
	outtextxy(435,460,"Password");
	TaoHCN(540,450,840,500,MAU_TRANG,2,MAU_DEN);
	GanID(540,450,840,500,2);
		
	settextstyle(10,0,2);
	setbkcolor(MAU_HONG);
	TaoHCN(610,550,770,580,MAU_HONG,3,MAU_DEN);
	GanID(610,550,770,580,3);
	outtextxy(630,555,"DANG NHAP");
		
	setbkcolor(MAU_XANH_DUONG_NHAT);
	settextstyle(10,0,2);
	setcolor(MAU_TRANG);
	outtextxy(1000,720,"GV: LU NGUYEN KY THU");
	outtextxy(1000,770,"N19DCCN173- BUI XUAN TU");
	outtextxy(1000,800,"N19DCCN015-NGUYEN THANH NAM");  
}
void sign()
{
	int x=-1;
	int y=-1;
    drawSign();
	char user[5]="";  
	char password[5];             
    while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(mapID[x][y]==1)
			{
				nhapText(545,360,840,400,user,5,0);
			}
			if(mapID[x][y]==2)
			{
				nhapText(545,460,840,500,password,5,0);
			}
			if(mapID[x][y]==3)
			{
				cout<<"user: "<<user[0]<<endl;
				cout<< sizeof user / sizeof(char)<<endl;
				cout<<"ps: "<<password<<endl;
				cout<< sizeof user / sizeof(char)<<endl;
				if(user[0]=='G'&&user[1]=='v' && password[0]=='G' && password[1]=='v')
				{
					menu();
				}
				else
				{
					settextstyle(10,0,3);
					setcolor(MAU_DO);
					outtextxy(400,650,"Sai thong tin tai khoan hoac mat khau !");
				}
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		delay(0.1);
	}
}
void drawMenu()
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	settextstyle(10,0,3);
	setbkcolor(MAU_XANH_DUONG);
	TaoHCN(560,100,820,150,MAU_XANH_DUONG,1,MAU_DEN);
	GanID(560,100,820,150,1);
	setcolor(MAU_TRANG);
	outtextxy(620,110,"SINH VIEN");
	
	TaoHCN(560,200,820,250,MAU_XANH_DUONG,2,MAU_DEN);
	GanID(560,200,820,250,2);
	setcolor(MAU_TRANG);
	outtextxy(640,210,"LOP HOC");
	
	TaoHCN(560,300,820,350,MAU_XANH_DUONG,3,MAU_DEN);
	GanID(560,300,820,350,3);
	setcolor(MAU_TRANG);
	outtextxy(640,310,"MON HOC");
	
	TaoHCN(560,400,820,450,MAU_XANH_DUONG,4,MAU_DEN);
	GanID(560,400,820,450,4);
	setcolor(MAU_TRANG);
	outtextxy(615,410,"CAU HOI THI");
	
	TaoHCN(560,500,820,550,MAU_XANH_DUONG,5,MAU_DEN);
	GanID(560,500,820,550,5);
	setcolor(MAU_TRANG);
	outtextxy(635,510,"DIEM THI");
	
	TaoHCN(560,600,820,650,MAU_XANH_DUONG,6,MAU_DEN);
	GanID(560,600,820,650,6);
	setcolor(MAU_TRANG);
	outtextxy(590,610,"THI TRAC NGHIEM");
	
	TaoHCN(560,700,820,750,MAU_XANH_DUONG,7,MAU_DEN);
	GanID(560,700,820,750,7);
	setcolor(MAU_TRANG);
	outtextxy(652,710,"THOAT");		 
}
void menu()
{
	int x=-1;
	int y=-1;
	drawMenu();
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(mapID[x][y]==1)
			{
				SV();
			}
			else if(mapID[x][y]==2)
			{
				lop();
			}
			else if(mapID[x][y]==3)
			{
				monhoc();
			}
//			else if(mapID[x][y]==4)
//			else if(mapID[x][y]==5)
//			else if(mapID[x][y]==6)
			else if(mapID[x][y]==7)
			{
				break;
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawSV(DS_LOP &ds_lop,DS_SINH_VIEN &ds_sv)
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN);
	GanID(20,10,100,40,1);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,145,155,175,MAU_HONG,0,MAU_DEN);
	outtextxy(70,150,"MA LOP");
	TaoHCN(160,145,390,175,MAU_TRANG,2,MAU_DEN);
	GanID(160,145,390,175,2);
	
	TaoHCN(420,145,500,175,MAU_HONG,3,MAU_DEN);
	GanID(420,145,500,175,3);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(435,150,"FIND");
	
// draw ds
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT 1
	GanID(20,10,100,40,1);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");
	
	drawDS_LOP(ds_lop);
}
void SV()
{
	DS_LOP ds_lop;
	DS_SINH_VIEN ds_sv;
	int x=-1;
	int y=-1;
	docfileLop(ds_lop);
	drawSV(ds_lop,ds_sv);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(mapID[x][y]==1)
			{
				menu();
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawLop(DS_LOP &ds_lop)
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	//draw them xoa sua
	settextstyle(10,0,2);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,105,155,135,MAU_HONG,0,MAU_DEN);
	outtextxy(73,108,"MA LOP");
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); // NHAP MA LOP 4
	GanID(160,105,390,135,4);
	TaoHCN(65,155,155,185,MAU_HONG,0,MAU_DEN);
	outtextxy(69,158,"TEN LOP");
	TaoHCN(160,155,650,185,MAU_TRANG,5,MAU_DEN); // NHAP TEN LOP 5
	GanID(160,155,650,185,5);
	TaoHCN(700,105,780,135,MAU_XANH_LA,6,MAU_DEN); // THEM 6
	GanID(700,105,780,135,6);
	TaoHCN(700,155,780,185,MAU_XANH_LA,7,MAU_DEN); // XOA 7
	GanID(700,155,780,185,7);
	TaoHCN(700,205,780,235,MAU_XANH_LA,8,MAU_DEN);// SUA 8
	GanID(700,205,780,235,8);
	setcolor(MAU_TRANG);
	setbkcolor(MAU_XANH_LA);
	outtextxy(715,110,"THEM");
	outtextxy(720,160,"XOA");
	outtextxy(720,210,"SUA");
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT 1
	GanID(20,10,100,40,1);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");
	
	drawDS_LOP(ds_lop);	
}
void lop()
{
	DS_LOP ds_lop;
	int x=-1;
	int y=-1;
	docfileLop(ds_lop);
	drawLop(ds_lop);
	char m_lop[16]="";
	char t_lop[51]="";
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						menu();
						break;	
					}
				case 4:
					{
						nhapText(165,110,390,135,m_lop,16,0);
						break;	
					}
				case 5:
					{
						nhapText(165,160,550,185,t_lop,51,0);
						break;	
					}
				case 6:
					{
						if(strlen(m_lop)==0 || strlen(t_lop)==0)
						{
							setbkcolor(MAU_XANH_DUONG_NHAT);
							outtextxy(1030,150,"TEN VA MA RONG !");
						}
						else
						{
							LOP *p=new LOP;
							strcpy(p->malop,m_lop);
							strcpy(p->tenlop,t_lop);
							themLop(ds_lop,*p);
							delete p;
						}
						break;	
					}
				case 7:
					{
						if(strlen(m_lop)==0 || strlen(t_lop)==0)
						{
							setbkcolor(MAU_XANH_DUONG_NHAT);
							outtextxy(1030,150,"TEN VA MA RONG !");
						}
						else
						{
							LOP *p=new LOP;
							strcpy(p->malop,m_lop);
							strcpy(p->tenlop,t_lop);
							xoaLop(ds_lop,*p);
							delete p;
							break;
						}
						break;		
					}
				case 8:
					{
						break;	
					}
				case 10:
					{
						if(ds_lop.sl==0)
						{
							setbkcolor(MAU_XANH_DUONG_NHAT );
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						strcpy(m_lop,ds_lop.ds[0]->malop);
						nhapText(165,110,390,135,m_lop,16,0);
						strcpy(t_lop,ds_lop.ds[0]->tenlop);
						nhapText(165,160,550,185,t_lop,51,0);
						break;	
					}
				case 11:
					{
						strcpy(m_lop,ds_lop.ds[1]->malop);
						nhapText(165,110,390,135,m_lop,16,0);
						strcpy(t_lop,ds_lop.ds[1]->tenlop);
						nhapText(165,160,550,185,t_lop,51,0);
						break;	
					}
				case 12:
					{
						strcpy(m_lop,ds_lop.ds[2]->malop);
						nhapText(165,110,390,135,m_lop,16,0);
						strcpy(t_lop,ds_lop.ds[2]->tenlop);
						nhapText(165,160,550,185,t_lop,51,0);
						break;	
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawDS_LOP(DS_LOP &ds_lop)
{
	TaoHCN(35,315,980,755,MAU_TRANG,0,MAU_DEN);
	GanID(35,315,980,755,0);
	setbkcolor(MAU_TRANG);
	outtextxy(65,325,"STT");
	outtextxy(230,325,"MA LOP");
	outtextxy(600,325,"TEN LOP");
	
	
	rectangle(35,315,980,755);
	line(35,355,980,355);
	line(150,315,150,755);
	line(400,315,400,755);
	line(35,395,980,395);
	line(35,435,980,435);
	line(35,475,980,475);
	line(35,515,980,515);
	line(35,555,980,555);
	line(35,595,980,595);
	line(35,635,980,635);
	line(35,675,980,675);
	line(35,715,980,715);
	int a=356,a1=395;
	for(int i=10;i<20;i++) // GAN ID CHO CAC PHAN TU DS
	{
		GanID(35,a,980,a1,i);
		a+=40, a1+=40;
	}
	
	setbkcolor(MAU_HONG);
	TaoHCN(35,760,115,790,MAU_HONG,0,MAU_DEN); // TRUOC 2
	outtextxy(40,765,"TRUOC");
	GanID(35,760,115,790,2);
	TaoHCN(900,760,980,790,MAU_HONG,0,MAU_DEN); // SAU 3
	outtextxy(905,765,"SAU");
	GanID(900,760,980,790,3);
	
	// xuat du lieu tu file ds
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int y=365;
	for(int i=0;i<ds_lop.sl;i++)
	{
		cout<<ds_lop.ds[i]->malop<<", "<<ds_lop.ds[i]->tenlop<<endl;
		outtextxy(165,y,ds_lop.ds[i]->malop);
		outtextxy(415,y,ds_lop.ds[i]->tenlop);
		y+=40;
	}
}
void drawMonhoc()
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	//draw them xoa sua
	settextstyle(10,0,2);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,105,155,135,MAU_HONG,0,MAU_DEN);
	outtextxy(73,108,"MA MON");
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); // NHAP MA LOP 4
	GanID(160,105,390,135,4);
	TaoHCN(65,155,155,185,MAU_HONG,0,MAU_DEN);
	outtextxy(69,158,"TEN MON");
	TaoHCN(160,155,650,185,MAU_TRANG,5,MAU_DEN); // NHAP TEN LOP 5
	GanID(160,155,650,185,5);
	TaoHCN(700,105,780,135,MAU_XANH_LA,6,MAU_DEN); // THEM 6
	GanID(700,105,780,135,6);
	TaoHCN(700,155,780,185,MAU_XANH_LA,7,MAU_DEN); // XOA 7
	GanID(700,155,780,185,7);
	TaoHCN(700,205,780,235,MAU_XANH_LA,8,MAU_DEN);// SUA 8
	GanID(700,205,780,235,8);
	setcolor(MAU_TRANG);
	setbkcolor(MAU_XANH_LA);
	outtextxy(715,110,"THEM");
	outtextxy(720,160,"XOA");
	outtextxy(720,210,"SUA");
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT 1
	GanID(20,10,100,40,1);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");
	
	TaoHCN(35,315,980,755,MAU_TRANG,0,MAU_DEN);
	GanID(35,315,980,755,0);
	setbkcolor(MAU_TRANG);
	outtextxy(65,325,"STT");
	outtextxy(230,325,"MA MON");
	outtextxy(600,325,"TEN MON HOC");
	
	
	rectangle(35,315,980,755);
	line(35,355,980,355);
	line(150,315,150,755);
	line(400,315,400,755);
	line(35,395,980,395);
	line(35,435,980,435);
	line(35,475,980,475);
	line(35,515,980,515);
	line(35,555,980,555);
	line(35,595,980,595);
	line(35,635,980,635);
	line(35,675,980,675);
	line(35,715,980,715);
	int a=356,a1=395;
	for(int i=10;i<20;i++) // GAN ID CHO CAC PHAN TU DS
	{
		GanID(35,a,980,a1,i);
		a+=40, a1+=40;
	}
	
	setbkcolor(MAU_HONG);
	TaoHCN(35,760,115,790,MAU_HONG,0,MAU_DEN); // TRUOC 2
	outtextxy(40,765,"TRUOC");
	GanID(35,760,115,790,2);
	TaoHCN(900,760,980,790,MAU_HONG,0,MAU_DEN); // SAU 3
	outtextxy(905,765,"SAU");
	GanID(900,760,980,790,3);
	
}
void monhoc()
{
	int x=-1;
	int y=-1;
	drawMonhoc();
	char m_lop[16]="";
	char t_lop[51]="";
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						menu();
						break;
					}
				case 4:
					{
						nhapText(165,110,390,135,m_lop,16,0);
						break;	
					}
				case 5:
					{
						nhapText(165,160,650,185,t_lop,51,0);
						break;
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void all()
{
	initwindow(WIDTH,HEIGHT); 
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
    menu();
}
