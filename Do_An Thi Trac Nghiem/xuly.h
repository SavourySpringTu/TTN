// lop
int kttrungLop(DS_LOP ds_lop,char m_lop[]);
void themLop(DS_LOP &ds_lop,LOP lop);
void xoaLop(DS_LOP &ds_lop,LOP lop);

// doc ghi tao file
void docfileLop(DS_LOP &ds_lop);
void ghifileLop(DS_LOP ds_lop);
void createFileSV(char m_lop[16]);

// xy ly lop
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
void themSV(DS_SINH_VIEN &ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17])
{
	SINH_VIEN *p=khoitao(m_sv,h_sv,t_sv,p_sv,ps);
	int temp=kttrungSV(ds_sv,p->masv);
	if(temp==-1)
	{
		if(ds_sv.phead==NULL)
		{
			ds_sv.phead=p;
		}
		else
		{
			p->pnext=ds_sv.phead;
			ds_sv.phead=p;
		}
	}
	else
	{
		setbkcolor(MAU_XANH_DUONG_NHAT);
		outtextxy(1030,150,"MA SINH VIEN TRUNG !");
	}
}

// doc ghi file sinh vien
void docfileSV(DS_SINH_VIEN &ds_sv,char m_lop[16])
{
	char m_lop_temp[16]="";
	strcpy(m_lop_temp,m_lop);
	ifstream fileIn;
	fileIn.open(strcat(m_lop_temp,".txt"),ios_base :: in);
	fileIn>>ds_sv.sl;
	fileIn.ignore();
	for(SINH_VIEN *p=ds_sv.phead;p!=NULL;p=p->pnext)
	{
		fileIn.getline(p->masv,sizeof(p->masv),'\n');
		fileIn.getline(p->ho,sizeof(p->ho),'\n');
		fileIn.getline(p->ten,sizeof(p->ten),'\n');
		fileIn.getline(p->phai,sizeof(p->phai),'\n');
		fileIn.getline(p->password,sizeof(p->password),'\n');
	} 
	fileIn.close();
}
void createFileSV(char m_lop[16]) // tao file
{
	ofstream MyFile(strcat(m_lop,".txt"));
	MyFile.close();
}
