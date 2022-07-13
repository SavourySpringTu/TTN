// lop
int kttrungLop(DS_LOP ds_lop,char m_lop[]);
void themLop(DS_LOP &ds_lop,LOP lop);
void xoaLop(DS_LOP &ds_lop,LOP lop);

// doc ghi file
void docfileLop(DS_LOP &ds_lop);
void ghifileLop(DS_LOP ds_lop);

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

// xu ly sinh vien
monhoc* khoi_tao_node_sv()
{
	tree *p=new tree;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void themmonhoc(DS_MON_HOC ds_mh,char m_mon[16],char t_mon[51])
{
	tree *p=khoi_tao_node_sv();
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

	}
	fileOut.close();
}
