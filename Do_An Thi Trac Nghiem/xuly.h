// ================= XU LY LOP =====================

int kttrungLop(DS_LOP ds_lop,char m_lop[]);
void themLop(DS_LOP &ds_lop,LOP lop);
void xoaLop(DS_LOP &ds_lop,LOP lop);
void xuaLop(DS_LOP &ds_lop,char temp1[],char m_lopxua[],char t_lopxua[]);

// ================== XU LY SINH VIEN =============

SINH_VIEN *khoitao(char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17]);
int kttrungSV(DS_SINH_VIEN ds_sv,char m_sv[16]);
void themSV(DS_SINH_VIEN &ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17],char m_lop[16]);
void giaophongSV(DS_SINH_VIEN &ds_sv);

// ================= DOC GHI FILE LOP =============

// LOP
void docfileLop(DS_LOP &ds_lop);
void ghifileLop(DS_LOP ds_lop);
void createFileSV(char m_lop[16]);
// SINH VIEN
void docfileSV(DS_SINH_VIEN &ds_sv,char m_lop[16]);
void ghifileSV(DS_SINH_VIEN &ds_sv,char m_lop[16]);

//=================================================
int kttrungLop(DS_LOP ds_lop,char m_lop[])
{
	for(int i=0;i<ds_lop.sl;i++)
	{
		if(strcmp(m_lop,ds_lop.ds[i]->malop)==0)
		{
			return i;
		}
	}
	return -1;
}
void themLop(DS_LOP &ds_lop,LOP lop)
{
	setcolor(MAU_DEN);
	setbkcolor(MAU_XANH_DUONG_NHAT);
	int temp=kttrungLop(ds_lop,lop.malop);
	if(temp==-1)
	{
		ds_lop.ds[ds_lop.sl]=new LOP;
		*ds_lop.ds[ds_lop.sl]=lop;
		ds_lop.sl++;
		ghifileLop(ds_lop);
		outtextxy(1030,150,"THEM THANH CONG !");
	}
	else
	{
		outtextxy(1030,150,"LOI MA LOP TRUNG !");
	}
}
void xoaLop(DS_LOP &ds_lop,LOP lop)
{
	int temp=kttrungLop(ds_lop,lop.malop);
	cout<<"temp la: "<<temp<<endl;
	if (temp!=-1)
	{
		for(int i=temp;i<ds_lop.sl-1;i++)
		{
			cout<<i<<" ="<<i+1<<endl;
			strcpy(ds_lop.ds[i]->malop, ds_lop.ds[i+1]->malop);
			strcpy(ds_lop.ds[i]->tenlop, ds_lop.ds[i+1]->tenlop);
		}
		ds_lop.sl--;
		setbkcolor(MAU_XANH_DUONG_NHAT );
		ghifileLop(ds_lop);
		outtextxy(1030,150,"XOA THANH CONG !");
	}
	else
	{
		setbkcolor(MAU_XANH_DUONG_NHAT );
		outtextxy(1030,150,"XOA KHONG THANH CONG !");
	}
}
void xuaLop(DS_LOP &ds_lop,char temp1[],char m_lopxua[],char t_lopxua[])
{
	int temp=kttrungLop(ds_lop,temp1);
	setbkcolor(MAU_XANH_DUONG_NHAT);
	if(temp!=-1)
	{
		strcpy(ds_lop.ds[temp]->malop,m_lopxua);
		strcpy(ds_lop.ds[temp]->tenlop,t_lopxua);
		ghifileLop(ds_lop);
		outtextxy(1030,150,"XUA THANH CONG !");
	}
	else
	{
		outtextxy(1030,150,"XUA KHONG THANH CONG !");
	}
}

void docfileLop(DS_LOP &ds_lop)
{
	ifstream fileIn;
	fileIn.open("ds_lop.txt",ios_base :: in);
	fileIn>>ds_lop.sl;
	fileIn.ignore();
	for(int i=0;i<ds_lop.sl;i++)
	{
		ds_lop.ds[i]=new LOP;
		fileIn.getline(ds_lop.ds[i]->malop,sizeof(ds_lop.ds[i]->malop),'\n');
		fileIn.getline(ds_lop.ds[i]->tenlop,sizeof(ds_lop.ds[i]->tenlop),'\n');
	} 
	fileIn.close();
}
void ghifileLop(DS_LOP ds_lop)
{
	ofstream fileOut;
	fileOut.open("ds_lop.txt", ios_base::out);

	fileOut << ds_lop.sl<< endl;
	for (int i = 0; i < ds_lop.sl; i++) 
	{
		fileOut << ds_lop.ds[i]->malop << endl;
		fileOut << ds_lop.ds[i]->tenlop << endl;

	}
	fileOut.close();
}

// xu ly sinh vien
SINH_VIEN *khoitao(char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17])
{
	SINH_VIEN *p=new SINH_VIEN;
	strcpy(p->masv,m_sv);
	strcpy(p->ho,h_sv);
	strcpy(p->ten,t_sv);
	strcpy(p->phai,p_sv);
	strcpy(p->password,ps);
	p->pnext=NULL;
	return p;
}
int kttrungSV(DS_SINH_VIEN ds_sv,char m_sv[16])
{
	for(SINH_VIEN *p = ds_sv.phead;p!=NULL;p=p->pnext)
	{
		if(strcmp(m_sv,p->masv)==0)
		{
			return 0;
		}
	}
	return -1;
}
SINH_VIEN *timSV(DS_SINH_VIEN ds_sv,char m_sv[16])
{
	for(SINH_VIEN *p=ds_sv.phead;p!=NULL;p=p->pnext)
	{
		if(strcmp(m_sv,p->masv)==0)
		{
			return p;
		}
	}
	outtextxy(1030,150,"MA SINH VIEN KHONG TON TAI !");
	return NULL;
}
void themSV(DS_SINH_VIEN &ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17],char m_lop[16])
{
	cout<<"them 1"<<endl;
	setbkcolor(MAU_XANH_DUONG_NHAT);
	SINH_VIEN *p=khoitao(m_sv,h_sv,t_sv,p_sv,ps);
	int temp=kttrungSV(ds_sv,m_sv);
	if(temp==-1)
	{
		if(ds_sv.phead==NULL)
		{
			ds_sv.phead=ds_sv.ptail=p;
		}
		else
		{
			ds_sv.ptail->pnext=p;
			p->pnext=NULL;
			ds_sv.ptail=p;
		}
		ghifileSV(ds_sv,m_lop);
		ds_sv.sl++;
		cout<<"them xong roi ne"<<endl;
	}
}

// doc ghi file sinh vien
void docfileSV(DS_SINH_VIEN &ds_sv,char m_lop[16])
{
	char m_lop_temp[16]="";
	strcpy(m_lop_temp,m_lop);
	ifstream fileIn;
	fileIn.open(strcat(m_lop_temp,".txt"),ios_base :: in);
	fileIn>>m_lop;
	fileIn.ignore();
	SINH_VIEN sv;
	while(!fileIn.eof())
	{
		fileIn.getline(sv.masv, sizeof(sv.masv),'\n');
		
		if(strlen(sv.masv) == 0) {  //kiem tra ky tu space cuoi cung trong file
			break;
		}
		fileIn.getline(sv.ho, sizeof(sv.ho),'\n');
		fileIn.getline(sv.ten, sizeof(sv.ten),'\n');
		fileIn.getline(sv.phai, sizeof(sv.phai), '\n');
		fileIn.getline(sv.password, sizeof(sv.password), '\n');
			
		themSV(ds_sv,sv.masv,sv.ho,sv.ten,sv.phai,sv.password,m_lop);	
	}
	fileIn.close();
	cout<<"doc 1:"<<endl;
}
//void giaophongSV(DS_SINH_VIEN &ds_sv)
//{
//	for(int i=0;i<ds_sv.sl;i++)
//	{
//		SINH_VIEN *p=ds_sv.phead;
//		cout<<"ma sv: "<<p->masv;
//		ds_sv.phead=ds_sv.phead->pnext;
//		p->pnext=NULL;
//		delete p;
//	}
//	ds_sv.sl=0;
//	cout<<"ds_sv.sl: "<<ds_sv.sl<<endl;
//	cout<<"giai phong xong"<<endl;
//}
void ghifileSV(DS_SINH_VIEN &ds_sv,char m_lop[16])
{
	char m_lop_temp[16]="";
	strcpy(m_lop_temp,m_lop);
	
	ofstream fileOut;
	fileOut.open(strcat(m_lop_temp,".txt"),ios_base :: out);
	SINH_VIEN *p= new SINH_VIEN;
	fileOut <<m_lop<< endl;
	for(SINH_VIEN *p=ds_sv.phead;p!=NULL;p=p->pnext)
	{
		fileOut << p->masv << endl;
		fileOut << p->ho << endl;
		fileOut << p->ten << endl;
		fileOut << p->phai << endl;
		fileOut << p->password << endl;
	}
	fileOut.close();
	cout<<"ghi file xong"<<endl;
}
void createFileSV(char m_lop[16]) // tao file
{
	ofstream MyFile(strcat(m_lop,".txt"));
	MyFile.close();
}
