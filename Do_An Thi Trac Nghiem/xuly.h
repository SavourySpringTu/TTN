void resetThongBao();
// ================= XU LY LOP =====================

int kttrungLop(DS_LOP ds_lop,char m_lop[]);
void themLop(DS_LOP &ds_lop,LOP lop);
void xoaLop(DS_LOP &ds_lop,LOP lop);
void suaLop(DS_LOP &ds_lop,char m_lop_edit[16],char t_lop_edit[51]);

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
		resetThongBao();
		outtextxy(1030,150,"THEM THANH CONG !");
	}
	else
	{
		resetThongBao();
		outtextxy(1030,150,"LOI MA LOP TRUNG !");
	}
}
void xoaLop(DS_LOP &ds_lop,LOP lop)
{
	int temp=kttrungLop(ds_lop,lop.malop);
	if (temp!=-1)
	{
		for(int i=temp;i<ds_lop.sl-1;i++)
		{
			cout<<i<<" ="<<i+1<<endl;
			strcpy(ds_lop.ds[i]->malop, ds_lop.ds[i+1]->malop);
			strcpy(ds_lop.ds[i]->tenlop, ds_lop.ds[i+1]->tenlop);
		}
		ds_lop.sl--;
		resetThongBao();
		outtextxy(1030,150,"XOA THANH CONG !");
	}
	else
	{
		resetThongBao();
		setbkcolor(MAU_XANH_DUONG_NHAT);
		setcolor(MAU_DEN);
		outtextxy(1030,150,"XOA KHONG THANH CONG !");
	}
}
void suaLop(DS_LOP &ds_lop,char m_lop_edit[16],char t_lop_edit[51])
{
	int temp=kttrungLop(ds_lop,m_lop_edit);
	setbkcolor(MAU_XANH_DUONG_NHAT);
	if(temp!=-1)
	{
		strcpy(ds_lop.ds[temp]->tenlop,t_lop_edit);
		resetThongBao();
		outtextxy(1030,150,"SUA THANH CONG !");
	}
	else
	{
		resetThongBao();
		outtextxy(1030,150,"SUA KHONG THANH CONG !");
	}
}

// doc ghi file lop
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
		createFileSV(ds_lop.ds[i]->malop);
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
	resetThongBao();
	outtextxy(1030,150,"MASV KHONG TON TAI !");
	return NULL;
}
void themSV(DS_SINH_VIEN &ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17],char m_lop[16])
{
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
		cout<<"them doc msv:"<<p->masv<<endl;
		ds_sv.sl++;
	}
}
void xoaSV(DS_SINH_VIEN &ds_sv,char m_sv[16],char m_lop[16])
{
	for(SINH_VIEN *p=ds_sv.phead;p!=NULL;p=p->pnext)
	{
		if(strcmp(ds_sv.phead->masv,m_sv)==0)
		{
			ds_sv.phead=p->pnext;
			delete p;
			break;
		}
		else if(strcmp(p->pnext->masv,m_sv)==0)
		{
			SINH_VIEN *q=p->pnext;
			p->pnext=q->pnext;
			delete q;
			break;
		}
	}
	resetThongBao();
	outtextxy(1030,150,"XOA SINH VIEN THANH CONG !");
}
void suaSV(DS_SINH_VIEN &ds_sv,char m_lop[16],char m_sv_edit[16],char t_sv_edit[11],char h_sv_edit[21],char p_sv_edit[5],char ps_edit[17])
{
	SINH_VIEN *p=timSV(ds_sv,m_sv_edit);
	if(p==NULL)
	{
		resetThongBao();
		outtextxy(1030,150,"MA SINH VIEN KHONG TON TAI !");
	}
	else
	{
		strcpy(p->ho,h_sv_edit);
		strcpy(p->ten,t_sv_edit);
		strcpy(p->phai,p_sv_edit);
		strcpy(p->password,ps_edit);
		resetThongBao();
		outtextxy(1030,150,"SUA THANH CONG");	
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
	cout<<"doc file sv xong:"<<endl;
}
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
	cout<<"ghi sv file xong"<<endl;
}
void createFileSV(char m_lop[16]) // tao file
{
	ofstream MyFile(strcat(m_lop,".txt"));
	MyFile.close();
}

// xy ly mon hoc
mon_hoc* kttrungMH(PTR_MH p,char m_mh[16])
{
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		p=kttrungMH(p->left,m_mh);
		if(strcmp(p->mamh,m_mh)==0)
			return p;
		p=kttrungMH(p->right,m_mh);
	}
	return NULL;
}
void themMH(PTR_MH &t, char m_mh[16],char t_mh[51])
{
	if(t==NULL)
	{
		PTR_MH p=new MON_HOC;
		strcpy(p->mamh,m_mh);
		strcpy(p->tenmh,t_mh);
		t=p;
		t->left=NULL;
		t->right=NULL;
		resetThongBao();
		outtextxy(1030,150,"THEM THANH CONG");	
	}
	else
	{
		if(strcmp(t->mamh,m_mh)>0)
		{
			themMH(t->left,m_mh,t_mh);
		}
		else if(strcmp(t->mamh,m_mh)<0)
		{
			themMH(t->right,m_mh,t_mh);
		}
	}
}
// doc ghi file mon phoc
