#pragma once

#include "Define.h"
#include "ctdl.h"
#include "xuly.h"

using namespace std;

int mapID[WIDTH][HEIGHT];

// Map ID
void ResetmapID();
void GanID(int x1, int y1, int x2, int y2, int id);
void create_circle(int x, int y,int radius,int id);

void reset_layout(int x1,int y1,int x2,int y2, int color);

// Draw
void TaoHCN(int x1, int y1, int x2, int y2,int mau,int id, int mauvien);

void reset_layout(int x1,int y1,int x2,int y2, int color);

// ho tro
void validateText(char s[]);
void xoaKiTu(char s[90],int vitrixoa);
void xoaKhoangTrangDauVaKeNhau(char *str);
void xoaKhoangTrangCuoi(char *str);
void resetThongBao();

// Input
void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space);

// draw tab
void drawSign();
void drawMenu();

void drawLop(DS_LOP ds_lop,int trang);
void drawDS_LOP(DS_LOP ds_lop,int trang);

void drawSV();
void drawDS_SV(DS_SINH_VIEN *ds_sv,char m_lop[16],int trangsv);
void drawSV_1();

void drawMonhoc(PTR_MH &p);
void drawDS_MH(PTR_MH p,int trangMH,int &slmh);
void outputDS_MH(PTR_MH p,int &y,int &i,int trangMH,int &slmh,int &i_temp)  ;

void drawDS_CH(DS_CAU_HOI &ds_ch,int trangCH);
void drawCauhoi();
void drawCauhoi_1(char m_mh[16]);
void drawthemCH(int id);
void drawsuaCH(DS_CAU_HOI ds_ch,int id);

void drawThi(int kt);
void drawThi_1(int trangThi);
void drawBai_Thi(DS_CAU_HOI ds_ch,int arr[],int trangThi,int slc);
void drawinputMSV(PTR_MH p,int slmh);

void drawDiem(DS_LOP ds_lop,int trang);
void drawDS_MH_DIEM(PTR_MH p,int trangMH,int slmh);

// xu ly
void sign();
void menu();
void SV(DS_LOP &ds_lop);
void lop(DS_LOP &ds_lop);
void monhoc(PTR_MH &p,int &slmh);
void cauhoi(PTR_MH p,int slmh);
void Thi(PTR_MH p,DS_LOP ds_lop,int slmh,char m_sv[16],int kt);
void inputMSV(PTR_MH p,int slmh,DS_LOP ds_lop);
void Diem(DS_LOP ds_lop,PTR_MH p,int slmh);

//
void all();

//======================================================

void create_circle(int x, int y,int radius,int id) 
{
	circle(x,y,radius);
	GanID(x-radius,y-radius,x+radius,y+radius,id);
}
void resetThongBao()
{
	TaoHCN(1010,55,1355,300,3,0,3);
	setbkcolor(MAU_XANH_DUONG_NHAT);
	setcolor(MAU_DEN);
}
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

void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space)
{
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
void drawDS_LOP(DS_LOP ds_lop,int trang)
{
	GanID(35,315,980,755,0); // gan id cho ds =0
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
	TaoHCN(35,760,115,790,MAU_HONG,2,MAU_DEN); // TRUOC 2
	outtextxy(40,765,"TRUOC");
	GanID(35,760,115,790,2);
	TaoHCN(900,760,980,790,MAU_HONG,3,MAU_DEN); // SAU 3
	outtextxy(905,765,"SAU");
	GanID(900,760,980,790,3);
	
	// xuat du lieu 
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int y=365;
	for(int i=trang*10;i<(10*(trang+1)) && i<ds_lop.sl;i++)
	{
		int tempstt=i;
		char stt[2]=""; 
		outtextxy(165,y,ds_lop.ds[i]->malop);
		outtextxy(415,y,ds_lop.ds[i]->tenlop);
		outtextxy(75,y,itoa(tempstt+1,stt,10));
		y+=40;
	}
}
void outputDS_MH(PTR_MH p,int &y,int &i,int trangMH,int &slmh,int &i_temp) 
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		outputDS_MH(p->left,y,i,trangMH,slmh,i_temp);
		if(i<=((trangMH+1)*10) && i==i_temp)
		{
			setcolor(MAU_DEN);
			setbkcolor(MAU_TRANG);
			outtextxy(165,y,p->mamh);
			outtextxy(415,y,p->tenmh);
			char stt[2]="";
			outtextxy(60,y,itoa(i,stt,10));
			i++;
			y+=40;
		}
		i_temp++;
		outputDS_MH(p->right,y,i,trangMH,slmh,i_temp);  
	}
}
void drawDS_MH(PTR_MH p,int trangMH,int &slmh)
{
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
	
	int y=365;
	int i=trangMH*10+1;
	int i_temp=1;
	outputDS_MH(p,y,i,trangMH,slmh,i_temp);
}
void drawSign()
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	settextstyle(10,0,5);
	setcolor(MAU_DEN);
	outtextxy(490,120,"THI TRAC NGHIEM");
		
	setbkcolor(MAU_XANH_DUONG_NHAT);
	outtextxy(580,270,"ÐANG NHAP");
		
	settextstyle(10,0,2);
	outtextxy(485,360,"User");
	TaoHCN(540,350,840,390,MAU_TRANG,1,MAU_DEN);
	GanID(540,350,840,390,1);
	outtextxy(435,460,"Password");
	TaoHCN(540,450,840,490,MAU_TRANG,2,MAU_DEN);
	GanID(540,450,840,490,2);
		
	settextstyle(10,0,2);
	setbkcolor(MAU_HONG);
	TaoHCN(610,550,770,580,MAU_HONG,3,MAU_DEN);
	GanID(610,550,770,580,3);
	outtextxy(630,555,"DANG NHAP");
	
	TaoHCN(610,750,770,780,MAU_XANH_LA,99,MAU_DEN);
	GanID(610,750,770,780,99);
	setbkcolor(MAU_XANH_LA);
	outtextxy(660,755,"THOAT");
		
	setbkcolor(MAU_XANH_DUONG_NHAT);
	settextstyle(10,0,2);
	setcolor(MAU_TRANG);
	outtextxy(1000,720,"GV: LUU NGUYEN KY THU");
	outtextxy(1000,770,"N19DCCN173 - BUI XUAN TU");
	outtextxy(1000,800,"N19DCCN015 - NGUYEN THANH NAM");  
}
void sign()
{
	int x=-1;
	int y=-1;
    drawSign();
	char user[16]="";  
	char password[16]=""; 
	
	DS_LOP ds_lop;
	docfileLop(ds_lop); 
	for(int i=0;i<ds_lop.sl;i++)
	{
		docfileSV(ds_lop.ds[i]->first_SINH_VIEN,ds_lop.ds[i]->malop);
	}   
    while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						nhapText(545,360,840,390,user,16,0);
						break;
					}
				case 2:
					{
						nhapText(545,460,840,490,password,16,0);
						break;
					}
				case 3:
					{
						if(strcmp(user,"")==0 || strcmp(password,"")==0)
						{
							settextstyle(10,0,3);
							setbkcolor(MAU_XANH_DUONG_NHAT);
							setcolor(MAU_TRANG);
							outtextxy(580,650,"THONG TIN RONG !");	
							break;						
						}
						if(strcmp(user,"Gv")==0 && strcmp(password,"Gv")==0)
						{
							menu();
						}
						else
						{
							for(int i=0;i<ds_lop.sl;i++)
							{
								for(SINH_VIEN *x=ds_lop.ds[i]->first_SINH_VIEN->phead;x!=NULL;x=x->pnext)
								{
									if(strcmp(user,x->masv)==0 && strcmp(password,x->password)==0)
									{
										int slmh=0;
										char m_sv_thi[16]="";
										int kt=1;
										strcpy(m_sv_thi,x->masv);
										PTR_MH p=NULL;
										docfileMH(p,slmh);	
										Thi(p,ds_lop,slmh,x->masv,kt);
										break;
									}
								}
							} 
							settextstyle(10,0,3);
							setbkcolor(MAU_XANH_DUONG_NHAT);
							setcolor(MAU_DO);
							outtextxy(530,650,"SAI THONG TIN TAI KHOAN !");
						}
						break;						
					}
				case 99:
					{
						return;
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
	outtextxy(655,710,"THOAT");		 
}
void menu()
{
	int x=-1;
	int y=-1;
	int slmh=0;
	char m_sv_sign[16]="";
	drawMenu();
	DS_LOP ds_lop;
	PTR_MH p=NULL;
	
	docfileLop(ds_lop);
	docfileMH(p,slmh);
	// doc file sinh vien
	for(int i=0;i<ds_lop.sl;i++)
	{
		docfileSV(ds_lop.ds[i]->first_SINH_VIEN,ds_lop.ds[i]->malop);
	}
	// doc file diem  
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						SV(ds_lop);
						break;
					}
				case 2:
					{
						lop(ds_lop);
						break;
					}
				case 3:
					{
						monhoc(p,slmh);
						break;
					}
				case 4:
					{
						cauhoi(p,slmh);
						break;
					}
				case 5:
					{
						Diem(ds_lop,p,slmh);
						break;
					}
				case 6:
					{
						inputMSV(p,slmh,ds_lop);
						break;
					}					
				case 7:
					{
						giaiphongMH(p);
						giaiphongLop(ds_lop);
						sign();
						break;
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawSV()
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
	TaoHCN(160,145,390,175,MAU_TRANG,31,MAU_DEN);
	GanID(160,145,390,175,31);
	
	TaoHCN(420,145,500,175,MAU_HONG,32,MAU_DEN);
	GanID(420,145,500,175,32);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(435,150,"FIND");
		
	// draw ds
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT
	GanID(20,10,100,40,1);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");
}
void drawSV_1()
{
	TaoHCN(25,55,995,300,MAU_XANH_DUONG_NHAT,0,MAU_DEN);
	GanID(25,55,995,300,0);
	
	setbkcolor(MAU_HONG);
	TaoHCN(65,105,155,135,MAU_HONG,0,MAU_DEN);
	outtextxy(73,108,"MA SV");
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); // NHAP MA SV 4
	GanID(160,105,390,135,4);
	TaoHCN(65,155,155,185,MAU_HONG,0,MAU_DEN);
	outtextxy(89,158,"TEN");
	TaoHCN(160,155,280,185,MAU_TRANG,5,MAU_DEN); // NHAP TEN SV 5
	GanID(160,155,250,185,5);
	TaoHCN(65,205,155,235,MAU_HONG,0,MAU_DEN);
	outtextxy(95,208,"HO");
	TaoHCN(160,205,280,235,MAU_TRANG,6,MAU_DEN); // NHAP HO SV 6
	GanID(160,205,280,235,6);
	TaoHCN(450,105,540,135,MAU_HONG,0,MAU_DEN);
	outtextxy(465,108,"MK");
	TaoHCN(545,105,785,135,MAU_TRANG,7,MAU_DEN); // NHAP PASSWORD SV 7
	GanID(545,105,785,135,7);
	TaoHCN(450,155,540,185,MAU_HONG,0,MAU_DEN);
	outtextxy(465,158,"PHAI");
	TaoHCN(545,155,655,185,MAU_TRANG,8,MAU_DEN); // NHAP PHAI SV 8
	GanID(545,155,655,185,8);
	
	TaoHCN(870,105,950,135,MAU_XANH_LA,9,MAU_DEN); // THEM 9
	GanID(870,105,950,135,9);
	TaoHCN(870,155,950,185,MAU_XANH_LA,33,MAU_DEN); // XOA 33
	GanID(870,155,950,185,33);
	TaoHCN(870,205,950,235,MAU_XANH_LA,34,MAU_DEN);// SUA 34
	GanID(870,205,950,235,34);
	setcolor(MAU_TRANG);
	setbkcolor(MAU_XANH_LA);
	outtextxy(885,110,"THEM");
	outtextxy(885,160,"XOA");
	outtextxy(885,210,"SUA");
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	TaoHCN(150,10,230,40,MAU_HONG,101,MAU_DEN);
	GanID(150,10,230,40,101);
	outtextxy(159,15,"SAVE");
	
	GanID(20,10,100,40,99);
}
void SV(DS_LOP &ds_lop)
{
	int x=-1;
	int y=-1;
	int tranglop=0;
	int trangsv=0;
	drawSV();
	drawDS_LOP(ds_lop,tranglop);
	char m_lop[16]="";
	char m_sv[16]="";
	char t_sv[11]="";
	char h_sv[21]="";
	char p_sv[5]="";
	char ps[17]="";
	char t_sv_edit[11]="";
	char h_sv_edit[21]="";
	char p_sv_edit[5]="";
	char ps_edit[17]="";
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			resetThongBao();
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						cout<<"ra menu"<<endl;
						menu();
						break;
					}
				case 2: // TRANG TRUOC DS LOP
					{
						if(tranglop==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							tranglop--;
							drawDS_LOP(ds_lop,tranglop);
						}
						break;
					}
				case 3: // TRANG SAU DS LOP
					{
						if((float(ds_lop.sl)/10)<=(1+tranglop))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							tranglop++;
							drawDS_LOP(ds_lop,tranglop);
						}
						break;
					}
				case 31:
					{
						nhapText(165,150,390,175,m_lop,16,0);
						break;
					}
				case 32: // FIND
					{
						setbkcolor(MAU_XANH_DUONG_NHAT);
						if(strcmp(m_lop,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");	
							break;
						}
						int temp=kttrungLop(ds_lop,m_lop);
						if(temp!=-1)
						{
							drawSV_1();
							drawDS_SV(ds_lop.ds[temp]->first_SINH_VIEN,ds_lop.ds[temp]->malop,trangsv);
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"MA LOP KHONG DUNG !");	
						}
						break;
					}
				case 4:
					{
						nhapText(165,110,390,135,m_sv,16,0);
						break;
					}
				case 5:
					{
						nhapText(165,160,280,185,t_sv,11,0);
						break;
					}
				case 6:
					{
						nhapText(165,210,280,235,h_sv,11,0);
						break;
					}
				case 7:
					{
						nhapText(550,110,785,135,ps,17,0);
						break;
					}
				case 8:
					{
						nhapText(550,160,655,185,p_sv,5,0);
						break;
					}
				case 9: // THEM SINH VIEN
					{
						if(strcmp(m_sv,"")==0 || strcmp(t_sv,"")==0 || strcmp(h_sv,"")==0 || strcmp(p_sv,"")==0 || strcmp(ps,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN KHONG DUOC RONG !");
							break;
						}
						else if(strcmp(p_sv,"Nam")==0 || strcmp(p_sv,"Nu")==0 || strcmp(p_sv,"Khac")==0)
						{
							setbkcolor(MAU_XANH_DUONG_NHAT);
							int temp_lop=kttrungLop(ds_lop,m_lop);
							SINH_VIEN *p=kttrungSV(ds_lop,m_sv);
							if(p==NULL)
							{
								themSV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_sv,h_sv,t_sv,p_sv,ps);
								drawDS_SV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop,trangsv);
								createFile(m_sv);	
								resetThongBao();
								outtextxy(1030,150,"THEM SINH VIEN THANH CONG");
							}
							else
							{
								resetThongBao();
								outtextxy(1030,150,"MA SINH VIEN TRUNG!");
							}
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"GIOI TINH KHONG HOP LE!");
							break;							
						}				
						break;
					}
				case 33: // XOA SINH VIEN
					{
						if(strcmp(m_sv,"")==0 )
						{
							resetThongBao();
							outtextxy(1030,150,"MA SINH VIEN RONG !");
							break;
						}
						SINH_VIEN *p=kttrungSV(ds_lop,m_sv);
						if(p==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"MA SINH VIEN KHONG TON TAI !");							
						}
						else
						{
							int temp_lop=kttrungLop(ds_lop,m_lop);
							xoaSV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_sv);
							drawDS_SV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop,trangsv);
							resetThongBao();
							outtextxy(1030,150,"XOA SINH VIEN THANH CONG !");
							break;
						}
					}
				case 34: //SUA SINH VIEN
					{
						SINH_VIEN *p=kttrungSV(ds_lop,m_sv);
						if(p==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"MA SINH VIEN KHONG DUNG!");
						}
						else
						{
							int temp_lop=kttrungLop(ds_lop,m_lop);
							strcpy(h_sv_edit,h_sv);
							strcpy(t_sv_edit,t_sv);
							strcpy(p_sv_edit,p_sv);
							strcpy(ps_edit,ps);
											
							suaSV(p,h_sv_edit,t_sv_edit,p_sv_edit,ps_edit);
							drawDS_SV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop,trangsv);	
							resetThongBao();
							outtextxy(1030,150,"SUA THANH CONG!");						
						}
					}
				case 35: // TRANG TRUOC DS SINH VIEN
					{
						if(trangsv==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							int temp_lop=kttrungLop(ds_lop,m_lop);
							trangsv--;
							drawDS_SV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop,trangsv);
						}
						break;
					}
				case 36: // TRANG SAU DS SINH VIEN
					{
						int temp=kttrungLop(ds_lop,m_lop);
						if((float(ds_lop.ds[temp]->first_SINH_VIEN->sl)/10)<=(1+trangsv))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							int temp_lop=kttrungLop(ds_lop,m_lop);
							trangsv++;
							drawDS_SV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop,trangsv);
						}
						break;
					}
				case 20:case 21:case 22:case 23:case 25:case 24:case 26:case 27:case 28:case 29:case 30:
					{
						int stt=mapID[x][y]-19;
						int temp_lop=kttrungLop(ds_lop,m_lop);
						if(ds_lop.ds[temp_lop]->first_SINH_VIEN->sl==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if(mapID[x][y]-19>ds_lop.ds[temp_lop]->first_SINH_VIEN->sl)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO SINH VIEN !");
						}
						else
						{
							int i=1;
							for(SINH_VIEN *p = ds_lop.ds[temp_lop]->first_SINH_VIEN->phead;p!=NULL && i<(10*(trangsv+1));p=p->pnext)
							{
								if((mapID[x][y]-19)==i)
								{								
									strcpy(m_sv,p->masv);
									strcpy(t_sv,p->ten);
									strcpy(h_sv,p->ho);
									strcpy(p_sv,p->phai);
									strcpy(ps,p->password);
								}
								i++;
							}
							strcpy(t_sv_edit,t_sv);
							strcpy(h_sv_edit,h_sv);
							strcpy(p_sv_edit,p_sv);
							strcpy(ps_edit,ps);
							
							setbkcolor(MAU_TRANG);
							reset_layout(166,111,390,135, MAU_TRANG);
							reset_layout(161,156,280,185, MAU_TRANG);
							reset_layout(161,206,280,235, MAU_TRANG);
							reset_layout(546,106,785,135, MAU_TRANG);
							reset_layout(546,156,655,185, MAU_TRANG);
							outtextxy(165,110,m_sv);
							outtextxy(165,160,t_sv_edit);
							outtextxy(165,210,h_sv_edit);
							outtextxy(550,160,p_sv_edit);
							outtextxy(550,110,ps_edit);							
						}
						break;
					}
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-10;
						if(ds_lop.sl==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+tranglop*10)-9>ds_lop.sl)
						{
							strcpy(m_lop,"");
							setcolor(MAU_TRANG);
							reset_layout(165,150,390,175,MAU_TRANG);
							resetThongBao();
							outtextxy(1030,150,"KHONG CO LOP !");
						}
						else
						{
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(165,150,390,175,MAU_TRANG);
							strcpy(m_lop,ds_lop.ds[stt+(tranglop*10)]->malop);
							outtextxy(165,150,m_lop);
						}
						break;	
					}
				case 99:
					{
						SV(ds_lop);
						break;
					}
				case 101:
					{
						int temp_lop=kttrungLop(ds_lop,m_lop);
						ghifileSV(ds_lop.ds[temp_lop]->first_SINH_VIEN,m_lop);
						resetThongBao();
						outtextxy(1030,150,"SAVE THANH CONG");	
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawDS_SV(DS_SINH_VIEN *ds_sv,char m_lop[16],int trangsv)
{  
	TaoHCN(35,315,980,755,MAU_TRANG,0,MAU_DEN);
	GanID(35,315,980,755,0);
	
	setbkcolor(MAU_TRANG);
	outtextxy(45,325,"STT");
	outtextxy(150,325,"MA SINH VIEN");
	outtextxy(400,325,"HO");
	outtextxy(515,325,"TEN");
	outtextxy(640,325,"PHAI");
	outtextxy(800,325,"PASSWORD");
	
	rectangle(35,315,980,755);
	line(35,355,980,355);
	line(100,315,100,755);
	line(350,315,350,755);
	
	line(470,315,470,755);
	line(600,315,600,755);
	line(730,315,730,755);
	
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
	for(int i=20;i<30;i++) // GAN ID CHO CAC PHAN TU DS
	{
		GanID(35,a,980,a1,i);
		a+=40, a1+=40;
	}
	
	setbkcolor(MAU_HONG);
	TaoHCN(35,760,115,790,MAU_HONG,35,MAU_DEN); // TRUOC 2
	outtextxy(40,765,"TRUOC");
	GanID(35,760,115,790,35);
	TaoHCN(900,760,980,790,MAU_HONG,36,MAU_DEN); // SAU 3
	outtextxy(905,765,"SAU");
	GanID(900,760,980,790,36);
	
	// xuat du lieu 
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int y=365;
	
	setbkcolor(MAU_TRANG);
	int i=0;
	for(SINH_VIEN *p = ds_sv->phead;p!=NULL && i<(10*(trangsv+1));p=p->pnext)
	{
		char stt[2]="";
		int itemp=i+1;
		if((trangsv*10)<=i)
		{
			outtextxy(60,y,itoa(itemp,stt,10));
			outtextxy(165,y,p->masv);
			outtextxy(360,y,p->ho);
			outtextxy(490,y,p->ten);
			outtextxy(610,y,p->phai);
			outtextxy(740,y,p->password);
			y+=40;
		}
		i++;
	}
}
void drawLop(DS_LOP ds_lop,int trang)
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
	
	TaoHCN(150,10,230,40,MAU_HONG,101,MAU_DEN);
	GanID(150,10,230,40,101);
	outtextxy(159,15,"SAVE");
	
	drawDS_LOP(ds_lop,trang);	
}
void lop(DS_LOP &ds_lop)
{
	int x=-1;
	int y=-1;
	int trang=0;
	drawLop(ds_lop,trang);
	char m_lop[16]="";
	char t_lop[51]="";
	char m_lop_edit[16]="";
	char t_lop_edit[51]="";
	char m_lop_temp[16]="";
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
				case 2: // TRANG TRUOC
					{
						if(trang==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trang--;
							drawDS_LOP(ds_lop,trang);
						}
						break;
					}
				case 3: // TRANG SAU
					{
						if((float(ds_lop.sl)/10)<=(1+trang))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							trang++;
							drawDS_LOP(ds_lop,trang);
						}
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
				case 6: // THEM LOP
					{
						if(strcmp(m_lop,"")==0 ||strcmp(t_lop,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						int temp_them=kttrungLop(ds_lop,m_lop);
						if(temp_them!=-1)
						{
							resetThongBao();
							outtextxy(1030,150,"MA LOP DA TON TAI !");							
						}
						else
						{
							themLop(ds_lop,m_lop,t_lop);
							strcpy(m_lop_temp,m_lop);
							drawDS_LOP(ds_lop,trang);
							resetThongBao();
							outtextxy(1030,150,"THEM THANH CONG!");	
						}
						break;
					}
				case 7: // XOA LOP
					{
						int temp=kttrungLop(ds_lop,m_lop);
						if(strcmp(m_lop,"")==0 ||strcmp(t_lop,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN KHONG DUOC");
							outtextxy(1030,170,"RONG !");
							break;
						}
						cout<<"1"<<endl;
						int kt=kttrungLop(ds_lop,m_lop);
						if(ds_lop.ds[temp]->first_SINH_VIEN->sl>0)
						{
							resetThongBao();
							outtextxy(1030,150,"LOP DA CO SINH VIEN");
							outtextxy(1030,170,"KHONG THE XOA!");
						}
						else if(kt!=-1)
						{
							char *abc=m_lop;
							xoaLop(ds_lop,m_lop);							
							drawDS_LOP(ds_lop,trang);
							remove(strcat(m_lop,".txt"));
							strcpy(m_lop,abc);
							ghifileLop(ds_lop);
							resetThongBao();
							outtextxy(1030,150,"XOA LOP THANH CONG !");	
							break;
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"MA LOP KHONG TON TAI !");							
						}
						break;		
					}
				case 8: // SUA LOP
					{
						strcpy(m_lop_edit,m_lop);
						strcpy(t_lop_edit,t_lop);
						if(strcmp(m_lop,"")==0 ||strcmp(t_lop,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						int temp_sua=kttrungLop(ds_lop,m_lop);
						if(temp_sua==-1)
						{
							resetThongBao();
							outtextxy(1030,150,"MA LOP KHONG TON TAI !");
						}
						else
						{
							suaLop(ds_lop,m_lop_edit,t_lop_edit);
							drawDS_LOP(ds_lop,trang);
							resetThongBao();
							outtextxy(1030,150,"SUA THANH CONG !");
						}
						break;	
					}
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-10;
						if(ds_lop.sl==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trang*10)-9>ds_lop.sl)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO LOP !");
						}
						else
						{
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,106,390,135,MAU_TRANG);
							reset_layout(161,156,650,185,MAU_TRANG);
							strcpy(m_lop,ds_lop.ds[stt+(trang*10)]->malop);
							outtextxy(165,110,m_lop);
							strcpy(t_lop,ds_lop.ds[stt+(trang*10)]->tenlop);
							outtextxy(165,160,t_lop);
							strcpy(m_lop_edit,"");
						}
						break;	
					}
				case 101:
					{
						ghifileLop(ds_lop);
						resetThongBao();
						outtextxy(1030,150,"SAVE THANH CONG !");
						break;						
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawMonhoc(PTR_MH &p)
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
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); // NHAP MA MH 4
	GanID(160,105,390,135,4);
	TaoHCN(65,155,155,185,MAU_HONG,0,MAU_DEN);
	outtextxy(69,158,"TEN MON");
	TaoHCN(160,155,650,185,MAU_TRANG,5,MAU_DEN); // NHAP TEN MH 5
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
	
	TaoHCN(150,10,230,40,MAU_HONG,101,MAU_DEN);
	GanID(150,10,230,40,101);
	outtextxy(159,15,"SAVE");
}
void monhoc(PTR_MH &p,int &slmh)
{
	int x=-1;
	int y=-1;
	int trangMH=0;
	char m_mh[16]="";
	char t_mh[51]="";
	char t_mh_edit[51]="";	
	
	drawMonhoc(p);
	drawDS_MH(p,trangMH,slmh);	
	
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
				case 2: // TRANG TRUOC DS MH
					{
						if(trangMH==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trangMH--;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 3: // TRANG SAU DS MH
					{
						if((float(slmh)/10)<=(1+trangMH))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							trangMH++;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 4:
					{
						nhapText(165,110,390,135,m_mh,16,0);
						break;	
					}
				case 5:
					{
						nhapText(165,160,650,185,t_mh,51,0);
						break;
					}
				case 6: // THEM MH
					{		
						MON_HOC *temp_them=kttrungMH(p,m_mh);
						if(temp_them==NULL)
						{
							themMH(p,m_mh,t_mh);
							slmh++;	
							drawDS_MH(p,trangMH,slmh);
							resetThongBao();
							outtextxy(1030,150,"THEM MON HOC THANH CONG");
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"MA MON HOC TRUNG");	
						}
						break;
					}
				case 7: // XOA MH
					{
						MON_HOC *temp_xoa=kttrungMH(p,m_mh);
						if(temp_xoa!=NULL)
						{
							xoaMH(p,m_mh);
							slmh--;
							test(p);
							drawDS_MH(p,trangMH,slmh);
							resetThongBao();
							outtextxy(1030,150,"XOA THANH CONG");
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"MA MON KHONG TON TAI");	
						}
						break;
					}
				case 8: // SUA MH
					{
						strcpy(t_mh_edit,t_mh);
						if(strcmp(m_mh,"")==0 ||strcmp(t_mh,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						MON_HOC* temp_sua=kttrungMH(p,m_mh);
						if(temp_sua==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"MA MON HOC KHONG TON TAI");
						}
						else
						{
							suaMH(p,m_mh,t_mh_edit);
							drawDS_MH(p,trangMH,slmh);
							resetThongBao();
							outtextxy(1030,150,"SUA MON HOC THANH CONG");						
						}
						break;							
					}
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-9;
						if(slmh==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trangMH*10)-9>slmh)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO MON HOC !");
						}
						else
						{
							int z=1;
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,106,390,135,MAU_TRANG);
							reset_layout(161,156,650,185,MAU_TRANG);
							MON_HOC *temp=duyet_theo_stt(p,z,stt+(trangMH*10));
							strcpy(m_mh,temp->mamh);
							outtextxy(165,110,m_mh);
							strcpy(t_mh,temp->tenmh);
							outtextxy(165,160,t_mh);
						}
						break;							
					}
				case 101:
					{
						ghifileMH(p);
						resetThongBao();
						outtextxy(1030,150,"SAVE THANH CONG");	
						break;
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawCauhoi()
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
	outtextxy(70,150,"MA MON");
	TaoHCN(160,145,390,175,MAU_TRANG,31,MAU_DEN);
	GanID(160,145,390,175,31);
	
	TaoHCN(420,145,500,175,MAU_HONG,32,MAU_DEN);
	GanID(420,145,500,175,32);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(435,150,"FIND");
	
	TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT
	GanID(20,10,100,40,1);
	outtextxy(27,15,"THOAT");	
}
void drawCauhoi_1(char m_mh[16])
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	settextstyle(10,0,2);
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	
	TaoHCN(25,55,995,300,MAU_XANH_DUONG_NHAT,0,MAU_DEN);
	GanID(25,55,995,300,0);
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,145,200,175,MAU_HONG,0,MAU_DEN);
	outtextxy(70,150,"MA MON HOC");
	TaoHCN(220,145,370,175,MAU_TRANG,0,MAU_DEN);
	
	TaoHCN(65,195,200,225,MAU_HONG,0,MAU_DEN);
	outtextxy(120,200,"ID");
	TaoHCN(220,195,370,225,MAU_TRANG,33,MAU_DEN);
	GanID(220,195,370,225,33);
	setbkcolor(MAU_TRANG);
	outtextxy(245,150,m_mh);
	
	TaoHCN(870,105,950,135,MAU_XANH_LA,4,MAU_DEN); // VAO THEM 
	GanID(870,105,950,135,4);
	TaoHCN(870,155,950,185,MAU_XANH_LA,5,MAU_DEN); // XOA 33
	GanID(870,155,950,185,5);
	TaoHCN(870,205,950,235,MAU_XANH_LA,6,MAU_DEN);// VAO SUA 34
	GanID(870,205,950,235,6);
	setcolor(MAU_TRANG);
	setbkcolor(MAU_XANH_LA);
	outtextxy(885,110,"THEM");
	outtextxy(885,160,"XOA");
	outtextxy(885,210,"SUA");
	
	setbkcolor(MAU_HONG);
	TaoHCN(150,10,230,40,MAU_HONG,101,MAU_DEN); // SAVE
	GanID(150,10,230,40,101);
	outtextxy(159,15,"SAVE");
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(20,10,100,40,MAU_HONG,99,MAU_DEN); // THOAT
	outtextxy(27,15,"THOAT");	
	GanID(20,10,100,40,99);	
}
void cauhoi(PTR_MH p,int slmh)
{
	int x=-1;
	int y=-1;
	int trangMH=0;
	int trangCH=0;
	char m_mh[16]="";
	char id_char[10]="";
	int id=atoi(id_char);
	char nd[72]="";
	char d_an_A[72]="";
	char d_an_B[72]="";
	char d_an_C[72]="";
	char d_an_D[72]="";
	char d_an[2]="";
	drawCauhoi();
	drawDS_MH(p,trangMH,slmh);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			resetThongBao();
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1: // thoat ra menu
					{
						menu();
						break;
					}
				case 2: // TRANG TRUOC DS MH
					{
						if(trangMH==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trangMH--;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 3: // TRANG SAU DS MH
					{
						if((float(slmh)/10)<=(1+trangMH))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							trangMH++;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 4: // VAO THEM CH
					{
						id = createID(p->ds_ch);
						itoa(id,id_char,10);
						drawthemCH(id);
						break;
					}
				case 5: // XOA
					{
						setbkcolor(MAU_XANH_DUONG_NHAT);
						if(id==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");	
							break;							
						}
						MON_HOC *a=kttrungMH(p,m_mh);
						int kt = kttrungCH(a->ds_ch,id); 
						if(kt==-1)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG TIM THAY MON HOC !");	
						}
						else
						{
							xoaCH(a->ds_ch,id);
							resetThongBao();
							outtextxy(1030,150,"XOA THANH CONG!");
							drawDS_CH(a->ds_ch,trangCH);
						}	
						break;
					}
				case 6: // VAO SUA CH
					{
						if(id==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						MON_HOC *a=kttrungMH(p,m_mh);
						int i=kttrungCH(a->ds_ch,id);
						if(i==-1)
						{
							resetThongBao();
							outtextxy(1030,150,"ID KHONG DUNG !");
							break;
						}
						else
						{
							strcpy(nd,a->ds_ch.ds[i].noidung);
							strcpy(d_an,a->ds_ch.ds[i].dapan);
							strcpy(d_an_A,a->ds_ch.ds[i].dapanA);
							strcpy(d_an_B,a->ds_ch.ds[i].dapanB);
							strcpy(d_an_C,a->ds_ch.ds[i].dapanC);
							strcpy(d_an_D,a->ds_ch.ds[i].dapanD);
							drawsuaCH(a->ds_ch,id);							
						}
						break;
					}
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-9;
						if(slmh==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trangMH*10)-9>slmh)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO MON HOC !");
						}
						else
						{
							int z=1;
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,151,390,175,MAU_TRANG);
							MON_HOC *temp=duyet_theo_stt(p,z,stt+(trangMH*10));
							strcpy(m_mh,temp->mamh);
							outtextxy(165,150,m_mh);
						}
						break;							
					}
				case 20:case 21:case 22:case 23:case 25:case 24:case 26:case 27:case 28:case 29:case 30:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						MON_HOC *a=kttrungMH(p,m_mh);
						int stt=mapID[x][y]-20;
						if(a->ds_ch.sl==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trangCH*10)-20>=a->ds_ch.sl)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO CAU HOI !");
						}
						else
						{
							reset_layout(221,196,370,225,MAU_TRANG);
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							outtextxy(225,200,itoa(a->ds_ch.ds[stt+(trangCH*10)].ID,id_char,10));
							id=a->ds_ch.ds[stt+(trangCH*10)].ID;
						}
						break;
					}
				case 31:
					{
	
						nhapText(165,150,390,175,m_mh,16,0);
						break;
					}
				case 32: // FIND MON HOC TRONG CAU HOI
					{
						setbkcolor(MAU_XANH_DUONG_NHAT);
						if(strcmp(m_mh,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");	
							break;
						}
						MON_HOC* temp_find=kttrungMH(p,m_mh);
						if(temp_find==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG TIM THAY MON HOC !");	
						}
						else
						{
							duyet_mh_doc_file_CH(p);
							drawCauhoi_1(m_mh);
							MON_HOC *a=kttrungMH(p,m_mh);
							drawDS_CH(a->ds_ch,trangCH);
						}
						break;
					}
				case 33: //NHAP ID
					{
						nhapText(225,200,370,225,id_char,3,0);
						id=atoi(id_char);
						break;
					}
				case 36: // TRUOC DS CH
					{
						if(trangCH==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trangCH--;
							MON_HOC *a=kttrungMH(p,m_mh);
							drawDS_CH(a->ds_ch,trangCH);
						}
						break;
					}
				case 37: // SAU DS CH
					{
						MON_HOC *a=kttrungMH(p,m_mh);
						if((float(a->ds_ch.sl)/10)<=(1+trangCH))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							trangCH++;
							drawDS_CH(a->ds_ch,trangCH);
						}				
						break;
					}
				case 40: // CHON DAP AN
					{
						setcolor(MAU_DEN);	
						fillellipse(42,320,5,5);
						reset_layout(32,370,52,390,MAU_TRANG);
						reset_layout(32,430,52,450,MAU_TRANG);
						reset_layout(32,490,52,510,MAU_TRANG);
						strcpy(d_an,"A");
						break;
					}
				case 41:
					{
						setcolor(MAU_DEN);
						fillellipse(42,380,5,5);
						reset_layout(32,310,52,330,MAU_TRANG);
						reset_layout(32,430,52,450,MAU_TRANG);
						reset_layout(32,490,52,510,MAU_TRANG);						
						strcpy(d_an,"B");
						break;
					}	
				case 42:
					{
						setcolor(MAU_DEN);
						fillellipse(42,440,5,5);
						reset_layout(32,310,52,330,MAU_TRANG);
						reset_layout(32,370,52,390,MAU_TRANG);
						reset_layout(32,490,52,510,MAU_TRANG);												
						strcpy(d_an,"C");
						break;
					}
				case 43:
					{
						setcolor(MAU_DEN);
						fillellipse(42,500,5,5);
						reset_layout(32,310,52,330,MAU_TRANG);
						reset_layout(32,370,52,390,MAU_TRANG);
						reset_layout(32,430,52,450,MAU_TRANG);						
						strcpy(d_an,"D");
						break;
					}									
				case 90:
					{
						nhapText(70,170,955,195,nd,72,0);
						break;
					}
				case 91:
					{
						nhapText(70,310,955,335,d_an_A,72,0);
						break;
					}
				case 92:
					{
						nhapText(70,370,955,395,d_an_B,72,0);
						break;
					}
				case 93:
					{
						nhapText(70,430,955,455,d_an_C,72,0);
						break;
					}
				case 94:
					{
						nhapText(70,490,955,515,d_an_D,72,0);
						break;
					}
				case 96: // them ch
					{
						if(strcmp(nd,"")==0||strcmp(d_an,"")==0||strcmp(d_an_A,"")==0||strcmp(d_an_B,"")==0||strcmp(d_an_C,"")==0||strcmp(d_an_D,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						MON_HOC *a=kttrungMH(p,m_mh);
						themCH(a->ds_ch,id,nd,d_an_A,d_an_B,d_an_C,d_an_D,d_an);
						id = createID(a->ds_ch);
						drawthemCH(id);
						resetThongBao();
						outtextxy(1030,150,"THEM THANH CONG !");
						break;
					}
				case 97: // SUA
					{
						if(strcmp(nd,"")==0||strcmp(d_an,"")==0||strcmp(d_an_A,"")==0||strcmp(d_an_B,"")==0||strcmp(d_an_C,"")==0||strcmp(d_an_D,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						MON_HOC *a=kttrungMH(p,m_mh);
						suaCH(a->ds_ch,id,nd,d_an_A,d_an_B,d_an_C,d_an_D,d_an);
						resetThongBao();
						outtextxy(1030,150,"SUA THANH CONG !");
						break;
					}
				case 98: // thoat ra ds_ch
					{
						strcpy(id_char,"");
						id=atoi(id_char);
						strcpy(nd,"");
						strcpy(d_an_A,"");
						strcpy(d_an_B,"");
						strcpy(d_an_C,"");
						strcpy(d_an_D,"");
						strcpy(d_an,""); // xoa nhap text khi out
						MON_HOC *a=kttrungMH(p,m_mh);
						drawCauhoi_1(m_mh);
						drawDS_CH(a->ds_ch,trangCH);
						break;
					}
				case 99: // thoat ra ds_mh
					{
						strcpy(m_mh,"");
						drawCauhoi();
						drawDS_MH(p,trangMH,slmh);
						trangCH=0;
						break;
					}
				case 101:
					{
						MON_HOC *a=kttrungMH(p,m_mh);
						ghifileCH(a->ds_ch,m_mh);
						resetThongBao();
						outtextxy(1030,150,"SAVE THANH CONG !");
						break;
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawDS_CH(DS_CAU_HOI &ds_ch,int trangCH)
{
	TaoHCN(35,315,980,755,MAU_TRANG,0,MAU_DEN);
	GanID(35,315,980,755,0);
	
	setbkcolor(MAU_TRANG);
	outtextxy(45,325,"STT");
	outtextxy(130,325,"ID");
	outtextxy(550,325,"NOI DUNG");
	
	rectangle(35,315,980,755);
	line(35,355,980,355);
	line(100,315,100,755);
	line(200,315,200,755);
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
	for(int i=20;i<30;i++) // GAN ID CHO CAC PHAN TU DS
	{
		GanID(35,a,980,a1,i);
		a+=40, a1+=40;
	}
	
	setbkcolor(MAU_HONG);
	TaoHCN(35,760,115,790,MAU_HONG,36,MAU_DEN); // TRUOC 36
	outtextxy(40,765,"TRUOC");
	GanID(35,760,115,790,36);
	TaoHCN(900,760,980,790,MAU_HONG,37,MAU_DEN); // SAU 37
	outtextxy(905,765,"SAU");
	GanID(900,760,980,790,37);
	int y=365;
	setbkcolor(MAU_TRANG);
	for(int i=trangCH*10;i<ds_ch.sl && i<(10*(trangCH+1));i++)
	{
		char id_temp[3]="";
		char stt_temp[2]="";
		int stt=i+1;
		outtextxy(65,y,itoa(stt,stt_temp,10));
		outtextxy(125,y,itoa(ds_ch.ds[i].ID,id_temp,10));
		outtextxy(220,y,ds_ch.ds[i].noidung);
		y+=40;
	}
}
void drawthemCH(int id)
{
	char temp[10]="";
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(1005,50,1360,800);
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,115,175,145,MAU_HONG,0,MAU_DEN);
	outtextxy(70,120,"NOI DUNG");
	setbkcolor(MAU_TRANG);
	TaoHCN(385,80,635,110,MAU_TRANG,0,MAU_DEN);
	outtextxy(400,85,"ID: ");
	outtextxy(440,85,itoa(id,temp,10));
	
	TaoHCN(65,165,955,195,MAU_TRANG,90,MAU_DEN); // NOI DUNG CAU HOI
	GanID(65,165,955,195,90);
	TaoHCN(65,305,955,335,MAU_TRANG,91,MAU_DEN); 
	GanID(65,305,955,335,91);
	TaoHCN(65,365,955,395,MAU_TRANG,92,MAU_DEN); 
	GanID(65,365,955,395,92);
	TaoHCN(65,425,955,455,MAU_TRANG,93,MAU_DEN);
	GanID(65,425,955,455,93);
	TaoHCN(65,485,955,515,MAU_TRANG,94,MAU_DEN); 
	GanID(65,485,955,515,94);
	setcolor(MAU_DEN);
	create_circle(42,320,15,40);	
	create_circle(42,380,15,41);
	create_circle(42,440,15,42);
	create_circle(42,500,15,43);
	fillellipse(42,320,15,15);
	fillellipse(42,380,15,15);
	fillellipse(42,440,15,15);
	fillellipse(42,500,15,15);
	
	TaoHCN(385,700,635,730,MAU_XANH_LA,96,MAU_DEN); // THEM CH
	GanID(385,700,635,730,96);
	setbkcolor(MAU_XANH_LA);
	outtextxy(488,705,"THEM");
		
	TaoHCN(20,10,100,40,MAU_HONG,98,MAU_DEN); // THOAT RA DS_CH
	GanID(20,10,100,40,98);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");	
}
void drawsuaCH(DS_CAU_HOI ds_ch,int id)
{
	char temp[10]="";
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(1005,50,1360,800);
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,115,175,145,MAU_HONG,0,MAU_DEN);
	outtextxy(70,120,"NOI DUNG");
	setbkcolor(MAU_TRANG);
	TaoHCN(385,80,635,110,MAU_TRANG,0,MAU_DEN);
	outtextxy(400,85,"ID: ");
	outtextxy(440,85,itoa(id,temp,10));
	
	TaoHCN(65,165,955,195,MAU_TRANG,90,MAU_DEN); // NOI DUNG CAU HOI
	GanID(65,165,955,195,90);
	TaoHCN(65,305,955,335,MAU_TRANG,91,MAU_DEN); 
	GanID(65,305,955,335,91);
	TaoHCN(65,365,955,395,MAU_TRANG,92,MAU_DEN); 
	GanID(65,365,955,395,92);
	TaoHCN(65,425,955,455,MAU_TRANG,93,MAU_DEN);
	GanID(65,425,955,455,93);
	TaoHCN(65,485,955,515,MAU_TRANG,94,MAU_DEN); 
	GanID(65,485,955,515,94);
	setcolor(MAU_DEN);
	create_circle(42,320,15,40);	
	create_circle(42,380,15,41);
	create_circle(42,440,15,42);
	create_circle(42,500,15,43);
	fillellipse(42,320,15,15);
	fillellipse(42,380,15,15);
	fillellipse(42,440,15,15);
	fillellipse(42,500,15,15);	
	
	// TEXT CU~ 
	int i=kttrungCH(ds_ch,id) ;
	setbkcolor(MAU_XANH_DUONG_NHAT);
	setcolor(MAU_DEN);
	if(strcmp(ds_ch.ds[i].dapan,"A")==0)
	{
		fillellipse(42,320,5,5);
	}
	else if(strcmp(ds_ch.ds[i].dapan,"B")==0)
	{
		fillellipse(42,380,5,5);
	}
	else if(strcmp(ds_ch.ds[i].dapan,"C")==0)
	{
		fillellipse(42,440,5,5);
	}
	else if(strcmp(ds_ch.ds[i].dapan,"D")==0)
	{
		fillellipse(42,500,5,5);
	}
	setbkcolor(MAU_TRANG);
	outtextxy(70,170,ds_ch.ds[i].noidung);
	outtextxy(70,310,ds_ch.ds[i].dapanA);
	outtextxy(70,370,ds_ch.ds[i].dapanB);
	outtextxy(70,430,ds_ch.ds[i].dapanC);
	outtextxy(70,490,ds_ch.ds[i].dapanD);
	TaoHCN(385,700,635,730,MAU_XANH_LA,97,MAU_DEN); // SUA CH
	GanID(385,700,635,730,97);
	setbkcolor(MAU_XANH_LA);
	outtextxy(488,705,"SUA");
		
	TaoHCN(20,10,100,40,MAU_HONG,98,MAU_DEN); // THOAT RA DS_CH
	GanID(20,10,100,40,98);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");	
}
void drawThi(int kt)
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
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); 
	GanID(160,105,390,135,4);
	
	TaoHCN(65,165,155,195,MAU_HONG,0,MAU_DEN);
	TaoHCN(160,165,390,195,MAU_TRANG,5,MAU_DEN); 
	GanID(160,165,390,195,5);
	
	TaoHCN(65,225,155,255,MAU_HONG,0,MAU_DEN);
	TaoHCN(160,225,390,255,MAU_TRANG,6,MAU_DEN); 
	GanID(160,225,390,255,6);
	
	outtextxy(73,108,"MA MON");
	outtextxy(73,168,"SO CAU");
	outtextxy(80,228,"TIME");
	
	TaoHCN(500,165,590,195,MAU_XANH_LA,7,MAU_DEN); // THI
	GanID(500,165,590,195,7);
	setbkcolor(MAU_XANH_LA);
	outtextxy(525,169,"THI");
	if(kt==0)
	{		
		TaoHCN(20,10,100,40,MAU_HONG,1,MAU_DEN); // THOAT 1
		GanID(20,10,100,40,1);
		setcolor(MAU_DEN);
		setbkcolor(MAU_HONG);
		settextstyle(10,0,2);
		outtextxy(27,15,"THOAT");
	}
	else
	{
		TaoHCN(20,10,100,40,MAU_HONG,102,MAU_DEN); // THOAT 1
		GanID(20,10,100,40,102);
		setcolor(MAU_DEN);
		setbkcolor(MAU_HONG);
		settextstyle(10,0,2);
		outtextxy(27,15,"THOAT");	
	}	
}
void drawBai_Thi(DS_CAU_HOI ds_ch,int arr[],int trangThi,int slc)
{
	cout<<"toi trang: "<<trangThi<<endl;
	char cau[10]="";
	itoa(trangThi+1,cau,10);
	setbkcolor(MAU_HONG);
	TaoHCN(120,120,210,150,MAU_HONG,0,MAU_DEN);
	outtextxy(125,125,"CAU:");
	outtextxy(180,125,cau);
	
	setbkcolor(MAU_TRANG);
	TaoHCN(250,165,1140,195,MAU_TRANG,0,MAU_DEN); // NOI DUNG CAU HOI
	TaoHCN(250,305,1140,335,MAU_TRANG,0,MAU_DEN); 
	TaoHCN(250,365,1140,395,MAU_TRANG,0,MAU_DEN); 
	TaoHCN(250,425,1140,455,MAU_TRANG,0,MAU_DEN);
	TaoHCN(250,485,1140,515,MAU_TRANG,0,MAU_DEN);
	
	create_circle(200,320,15,40);	
	create_circle(200,380,15,41);
	create_circle(200,440,15,42);
	create_circle(200,500,15,43);
	fillellipse(200,320,15,15);
	fillellipse(200,380,15,15);
	fillellipse(200,440,15,15);
	fillellipse(200,500,15,15);
	for(int i=0;i<ds_ch.sl;i++)
	{
		if(ds_ch.ds[i].ID==arr[trangThi])
		{
			outtextxy(255,170,ds_ch.ds[i].noidung);
			outtextxy(255,310,ds_ch.ds[i].dapanA);
			outtextxy(255,370,ds_ch.ds[i].dapanB);
			outtextxy(255,430,ds_ch.ds[i].dapanC);
			outtextxy(255,490,ds_ch.ds[i].dapanD);
		}
	} 
}
void drawThi_1(int trangThi)
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	rectangle(100,100,1280,750);
	
	setbkcolor(MAU_HONG);
	TaoHCN(100,760,180,790,MAU_HONG,8,MAU_DEN); // TRUOC 8
	outtextxy(105,765,"TRUOC");
	GanID(100,760,765,790,8);
	TaoHCN(1200,760,1280,790,MAU_HONG,9,MAU_DEN); // SAU 9
	outtextxy(1205,765,"SAU");
	GanID(1200,760,1280,790,9);
	
	TaoHCN(640,10,740,40,MAU_HONG,101,MAU_DEN); // NOP BAI 101
	GanID(640,10,740,40,101);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(645,15,"NOP BAI");
	
	TaoHCN(20,10,100,40,MAU_HONG,99,MAU_DEN); // THOAT 99
	GanID(20,10,100,40,99);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(27,15,"THOAT");
}
void Thi(PTR_MH p,DS_LOP ds_lop,int slmh,char m_sv[16],int kt)
{
	int x=-1;
	int y=-1;
	int trangMH=0;
	int trangThi=0;
	char m_mh[16]="";
	char slc_char[10]="";
	char time_char[10]="";
	int slc=atoi(slc_char);
	int time=atoi(time_char);
	bool kt_da=false;
	int arr[10]; // mang chua ID cua cac cau hoi thi [8,6,54,9,5,36];
	char *ds_tl=new char[10]; // mang chua ds cac cau tra loi cua bai thi
	DS_BAI_THI ds_bt;
	
	duyet_mh_doc_file_CH(p);
	docfileBT(ds_bt);
	
	drawThi(kt);
	drawDS_MH(p,trangMH,slmh);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 1:
					{
						delete ds_tl;
						giaiphongBT(ds_bt);
						menu();
						break;
					}
				case 2: // TRANG TRUOC DS MH
					{
						if(trangMH==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trangMH--;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 3: // TRANG SAU DS MH
					{
						if((float(slmh)/10)<=(1+trangMH))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							trangMH++;
							drawDS_MH(p,trangMH,slmh);
						}
						break;
					}
				case 4:
					{
						nhapText(165,110,390,135,m_mh,16,0);
						break;
					}
				case 5:
					{
						nhapText(165,170,390,195,slc_char,10,0);
						slc=atoi(slc_char);
						break;
					}
				case 6:
					{
						nhapText(165,230,390,255,time_char,10,0);
						time=atoi(time_char);
						break;
					}
				case 7: // VAO THI
					{
						BAI_THI bt;
						if(strcmp(slc_char,"")==0 || strcmp(m_mh,"")==0 || strcmp(time_char,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");
							break;
						}
						else if(slc>10 || slc <1)
						{
							resetThongBao();
							outtextxy(1030,150,"SL TU PHAI 1 DEN 10 !");
							break;
						}
						else if(time>360 || time <5)
						{
							resetThongBao();
							outtextxy(1030,150,"TIME TU PHAI 5 DEN 360!");
							break;
						}
						else
						{
							MON_HOC *a=kttrungMH(p,m_mh);
							if(a==NULL)
							{
								resetThongBao();
								outtextxy(1030,150,"MA KHONG TON TAI !");						
							}
							else if(a->ds_ch.sl==0)
							{
								resetThongBao();
								outtextxy(1030,150,"MON HOC KHONG CO CAU");	
								outtextxy(1030,170,"HOI");	
								break;
							}
							else if(ktmonhocdathi(ds_bt,m_mh,m_sv)==false)
							{
								resetThongBao();
								outtextxy(1030,150,"MON HOC DA THI");	
								break;								
							}
							else
							{		
								random_CH(a->ds_ch,arr,slc);
								drawThi_1(trangThi);
								drawBai_Thi(a->ds_ch,arr,trangThi,slc);							
							}							
						}
						break;
					}
				case 8:// TRANG TRUOC THI
					{
						if(trangThi==0)
						{
							setcolor(MAU_DEN);
							setbkcolor(MAU_XANH_DUONG_NHAT);
							outtextxy(550,800,"DA LA TRANG DAU !");
						}
						else
						{
							MON_HOC *a=kttrungMH(p,m_mh);
							trangThi--;
							drawBai_Thi(a->ds_ch,arr,trangThi,slc);
						}
						break;
					}
				case 9: // TRANG SAU THI
					{
						if(trangThi==(slc-1))
						{
							setcolor(MAU_DEN);
							setbkcolor(MAU_XANH_DUONG_NHAT);							
							outtextxy(550,800,"DA LA TRANG CUOI !");
						}
						else
						{
							if(kt_da==false)
							{
								ds_tl[trangThi]='X';
							}
							kt_da=false;
							MON_HOC *a=kttrungMH(p,m_mh);
							trangThi++;
							drawBai_Thi(a->ds_ch,arr,trangThi,slc);
						}
						break;
					}
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-9;
						cout<<"map: "<<mapID[x][y]<<endl;
						cout<<"trangMH: "<<trangMH<<endl;
						cout<<"slmh: "<<slmh<<endl;
						if(slmh==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trangMH*10)-9>slmh)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO MON HOC !");
						}
						else
						{
							int z=1;
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,106,390,135,MAU_TRANG);
							MON_HOC *temp=duyet_theo_stt(p,z,stt+(trangMH*10));
							setcolor(MAU_DEN);
							strcpy(m_mh,temp->mamh);
							outtextxy(165,110,m_mh);
						}
						break;							
					}
				case 40: // CHON DAP AN
					{
						ds_tl[trangThi]='A';
						kt_da=true;
						setcolor(MAU_DEN);	
						fillellipse(200,320,5,5);
						reset_layout(190,370,210,390,MAU_TRANG);
						reset_layout(190,430,210,450,MAU_TRANG);
						reset_layout(190,490,210,510,MAU_TRANG);
						break;
					}
				case 41:
					{
						ds_tl[trangThi]='B';
						kt_da=true;
						setcolor(MAU_DEN);
						fillellipse(200,380,5,5);
						reset_layout(190,310,210,330,MAU_TRANG);
						reset_layout(190,430,210,450,MAU_TRANG);
						reset_layout(190,490,210,510,MAU_TRANG);												
						break;
					}	
				case 42:
					{
						ds_tl[trangThi]='C';
						kt_da=true;
						setcolor(MAU_DEN);
						fillellipse(200,440,5,5);
						reset_layout(190,310,210,330,MAU_TRANG);
						reset_layout(190,370,210,390,MAU_TRANG);
						reset_layout(190,490,210,510,MAU_TRANG);																		
						break;
					}
				case 43:
					{
						ds_tl[trangThi]='D';
						kt_da=true;
						setcolor(MAU_DEN);
						fillellipse(200,500,5,5);
						reset_layout(190,310,210,330,MAU_TRANG);
						reset_layout(190,430,210,450,MAU_TRANG);
						reset_layout(190,370,210,390,MAU_TRANG);												
						break;
					}
				case 98:
					{
						break;
					}
				case 99:
					{
						Thi(p,ds_lop,slmh,m_sv,kt);
						break;
					}
				case 101: // NOP BAI THI
					{
						if(kt_da==false)
						{
							ds_tl[trangThi]='X';
						}
						if(trangThi<slc-1)
						{
							for(int i=trangThi+1;i<slc;i++)
							{
								ds_tl[i]='X';
							}
						}
						int *b=new int[slc];
						for(int i=0;i<slc;i++)
						{
							b[i]=arr[i];
						}
						int diem=tinhdiem(p,m_mh,ds_tl,b,slc);
						themBT(ds_bt,slc,diem,time,m_sv,m_mh,ds_tl,b);
						SINH_VIEN *z=kttrungSV(ds_lop,m_sv);
						themDiem(z->first_DIEM_THI,m_sv,m_mh,diem);
						
						cout<<"ghi file diem"<<endl;
						ghifileDiem(z->first_DIEM_THI,m_sv);
						ghifileBT(ds_bt);
						
						Thi(p,ds_lop,slmh,m_sv,kt);
						break;
					}
				case 102:
					{
						giaiphongBT(ds_bt);
						sign();
						break;
					}					
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawinputMSV(PTR_MH p,int slmh)
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	TaoHCN(65,145,155,175,MAU_HONG,0,MAU_DEN);
	outtextxy(70,150,"MA SV");
	TaoHCN(160,145,390,175,MAU_TRANG,1,MAU_DEN);
	GanID(160,145,390,175,1);
	TaoHCN(450,145,520,175,MAU_XANH_LA,2,MAU_DEN);
	GanID(450,145,520,175,2);
	setbkcolor(MAU_XANH_LA);
	outtextxy(455,150,"GO");
	
	TaoHCN(20,10,100,40,MAU_HONG,99,MAU_DEN); // THOAT 99
	GanID(20,10,100,40,99);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(27,15,"THOAT");
}
void inputMSV(PTR_MH p,int slmh,DS_LOP ds_lop)
{
	int x=-1;
	int y=-1;
	char m_sv[16]="";
	drawinputMSV(p,slmh);
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			switch(mapID[x][y])
			{
				case 99:
					{
						menu();
						break;
					}
				case 1:
					{
						nhapText(165,150,390,175,m_sv,16,0);
						break;
					}
				case 2:
					{
						SINH_VIEN *x=kttrungSV(ds_lop,m_sv);
						if(strcmp(m_sv,"")==0 || x==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"MA SINH VIEN KHONG HOP LE !");						
						}
						else
						{
							int kt=0;
							Thi(p,ds_lop,slmh,m_sv,kt);
						}
						break;
					}
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0.1);
	}
}
void drawDiem_1()
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	setcolor(MAU_DEN);
	rectangle(20,50,1000,800);
	rectangle(25,55,995,300);
	rectangle(25,305,995,795);
	rectangle(1005,50,1360,800);
	
	settextstyle(10,0,2);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,105,155,135,MAU_HONG,0,MAU_DEN);
	TaoHCN(160,105,390,135,MAU_TRANG,4,MAU_DEN); 
	GanID(160,105,390,135,4);	
	outtextxy(73,108,"MA MON");
	
	TaoHCN(420,105,500,135,MAU_HONG,33,MAU_DEN);
	GanID(420,105,500,135,33);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	outtextxy(425,110,"FIND");
		
	TaoHCN(20,10,100,40,MAU_HONG,99,MAU_DEN); // THOAT 99
	GanID(20,10,100,40,99);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");		
}
void drawDS_MH_DIEM(PTR_MH p,int trangMH,int slmh)
{
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
	for(int i=20;i<30;i++) // GAN ID CHO CAC PHAN TU DS
	{
		GanID(35,a,980,a1,i);
		a+=40, a1+=40;
	}
	
	TaoHCN(35,760,115,790,MAU_HONG,42,MAU_DEN); // TRUOC 42
	GanID(35,760,115,790,42);
	TaoHCN(900,760,980,790,MAU_HONG,43,MAU_DEN); // SAU 43
	GanID(900,760,980,790,43);
	setbkcolor(MAU_HONG);
	outtextxy(40,765,"TRUOC");
	outtextxy(905,765,"SAU");
	
	int y=365;
	int i=trangMH*10+1;
	int i_temp=1;
	outputDS_MH(p,y,i,trangMH,slmh,i_temp);
}
void drawDS_DIEM(DS_LOP ds_lop,char m_lop[16],char m_mh[16])
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
    cleardevice(); 
	ResetmapID();
	
	TaoHCN(35,315,980,755,MAU_TRANG,0,MAU_DEN);
	GanID(35,315,980,755,0);
		
	setbkcolor(MAU_TRANG);
	outtextxy(350,325,"MA SV");
	outtextxy(850,325,"DIEM");
	
	rectangle(35,315,980,755);
	line(35,355,980,355);
	line(760,315,760,755);
	line(35,395,980,395);
	line(35,435,980,435);
	line(35,475,980,475);
	line(35,515,980,515);
	line(35,555,980,555);
	line(35,595,980,595);
	line(35,635,980,635);
	line(35,675,980,675);
	line(35,715,980,715);
	
	settextstyle(10,0,2);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	TaoHCN(65,105,155,135,MAU_HONG,0,MAU_DEN);
	TaoHCN(160,105,390,135,MAU_TRANG,0,MAU_DEN); 
	outtextxy(73,108,"MA LOP");
	setbkcolor(MAU_TRANG);
	outtextxy(165,110,m_lop);
	
	TaoHCN(65,155,155,185,MAU_HONG,0,MAU_DEN);
	TaoHCN(160,155,390,185,MAU_TRANG,0,MAU_DEN); 
	setbkcolor(MAU_HONG);
	outtextxy(73,158,"MA MH");
	setbkcolor(MAU_TRANG);
	outtextxy(165,160,m_mh);
	
	
	
	TaoHCN(35,760,115,790,MAU_HONG,8,MAU_DEN); // TRUOC 8
	GanID(35,760,115,790,8);
	TaoHCN(900,760,980,790,MAU_HONG,9,MAU_DEN); // SAU 9
	GanID(900,760,980,790,9);
	setbkcolor(MAU_HONG);
	outtextxy(40,765,"TRUOC");
	outtextxy(905,765,"SAU");
	
	TaoHCN(20,10,100,40,MAU_HONG,101,MAU_DEN); // THOAT 101
	GanID(20,10,100,40,101);
	setcolor(MAU_DEN);
	setbkcolor(MAU_HONG);
	settextstyle(10,0,2);
	outtextxy(27,15,"THOAT");	
	
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	int y=365;
	char temp_diem[5]="";
	int a=kttrungLop(ds_lop,m_lop);
	cout<<"chay for"<<endl;
	for(SINH_VIEN *x=ds_lop.ds[a]->first_SINH_VIEN->phead;x!=NULL;x=x->pnext)
	{
		for(DIEM_THI *z=x->first_DIEM_THI->phead;z!=NULL;z=z->pnext)
		{
			if(strcmp(z->mamh,m_mh)==0)
			{
				itoa(z->diem,temp_diem,10);
				outtextxy(100,y,x->masv);
				outtextxy(860,y,temp_diem);
				y+=40;
			}
		}
	}
	
}
void Diem(DS_LOP ds_lop,PTR_MH p,int slmh)
{
	int x=-1;
	int y=-1;
	int tranglop=0;
	int trangmh=0;
	char m_lop[16]="";
	char m_mh[16]="";
	drawSV();
	drawDS_LOP(ds_lop,tranglop);
	
	for(int i=0;i<ds_lop.sl;i++)
	{
		for(SINH_VIEN *z=ds_lop.ds[i]->first_SINH_VIEN->phead;z!=NULL;z=z->pnext)
		{
			docfileDiem(z->first_DIEM_THI,z->masv);
		}
	}
	
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
				case 2: // TRANG TRUOC DS LOP
					{
						if(tranglop==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							tranglop--;
							drawDS_LOP(ds_lop,tranglop);
						}
						break;
					}
				case 3: // TRANG SAU DS LOP
					{
						if((float(ds_lop.sl)/10)<=(1+tranglop))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							tranglop++;
							drawDS_LOP(ds_lop,tranglop);
						}
						break;
					}
				case 8:
					{
						
						break;
					}
				case 9:
					{
						
						break;
					}				
				case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-10;
						if(ds_lop.sl==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+tranglop*10)-9>ds_lop.sl)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO LOP !");
						}
						else
						{
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,146,390,175,MAU_TRANG);
							strcpy(m_lop,ds_lop.ds[stt+(tranglop*10)]->malop);
							outtextxy(165,150,m_lop);
						}
						break;	
					}
				case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29:
					{
						resetThongBao();
						setbkcolor(MAU_XANH_DUONG_NHAT );
						int stt=mapID[x][y]-19;
						if(slmh==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DANH SACH RONG !");
							break;
						}
						else if((mapID[x][y]+trangmh*10)-19>slmh)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG CO MON HOC !");
						}
						else
						{
							int z=1;
							setbkcolor(MAU_TRANG);
							setcolor(MAU_DEN);
							reset_layout(161,106,390,135,MAU_TRANG);
							MON_HOC *temp=duyet_theo_stt(p,z,stt+(trangmh*10));
							strcpy(m_mh,temp->mamh);
							outtextxy(165,110,m_mh);
						}
						break;							
					}
				case 31:
					{
						nhapText(165,150,390,175,m_lop,16,0);
						break;
					}
				case 32: // FIND LOP
					{
						setbkcolor(MAU_XANH_DUONG_NHAT);
						if(strcmp(m_lop,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");	
							break;
						}
						int temp=kttrungLop(ds_lop,m_lop);
						if(temp!=-1)
						{
							drawDiem_1();
							drawDS_MH_DIEM(p,trangmh,slmh);
						}
						else
						{
							resetThongBao();
							outtextxy(1030,150,"MA LOP KHONG DUNG !");	
						}
						break;
					}
				case 33: // FIND MON HOC 
					{
						setbkcolor(MAU_XANH_DUONG_NHAT);
						if(strcmp(m_mh,"")==0)
						{
							resetThongBao();
							outtextxy(1030,150,"THONG TIN RONG !");	
							break;
						}
						MON_HOC* temp_find=kttrungMH(p,m_mh);
						if(temp_find==NULL)
						{
							resetThongBao();
							outtextxy(1030,150,"KHONG TIM THAY MON HOC !");	
						}
						else // XUAT DIEM 1 MON HOC CUA LOP
						{						
							drawDS_DIEM(ds_lop,m_lop,m_mh);
						}
						break;
					}
				case 42: // TRANG TRUOC DS MH
					{
						if(trangmh==0)
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG DAU !");
						}
						else
						{
							trangmh--;
							drawDS_MH_DIEM(p,trangmh,slmh);
						}
						break;
					}
				case 43: // TRANG SAU DS MH
					{
						if((float(slmh)/10)<=(1+trangmh))
						{
							resetThongBao();
							outtextxy(1030,150,"DA LA TRANG CUOI !");
						}
						else
						{
							cout<<"trangmh: "<<trangmh<<endl;
							trangmh++;
							drawDS_MH_DIEM(p,trangmh,slmh);
						}
						break;	
					}						
				case 99: // THOAT RA DS LOP
					{
						strcpy(m_lop,"");
						drawSV();
						drawDS_LOP(ds_lop,tranglop);
						break;
					}
				case 101: // THOAT RA DS MH
					{
						strcpy(m_mh,"");
						drawDiem_1();
						drawDS_MH_DIEM(p,trangmh,slmh);
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
    sign();
}
