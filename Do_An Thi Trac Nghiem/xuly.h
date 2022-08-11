// ================== CHUNG ========================

void resetThongBao();
void createFile(char ma[16]);

// ================= XU LY LOP =====================

int kttrungLop(DS_LOP ds_lop,char m_lop[]);
void themLop(DS_LOP &ds_lop,char m_lop[16],char t_lop[51]);
void xoaLop(DS_LOP &ds_lop,char m_lop[16]);
void suaLop(DS_LOP &ds_lop,char m_lop_edit[16],char t_lop_edit[51]);

// ================== XU LY SINH VIEN =============

SINH_VIEN *khoitao(char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17]);
SINH_VIEN *kttrungSV(DS_LOP ds_lop,char m_sv[16]);
void themSV(DS_SINH_VIEN *&ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17]);
void xoaSV(DS_SINH_VIEN *&ds_sv,char m_sv[16]);
void suaSV(SINH_VIEN *p,char t_sv_edit[11],char h_sv_edit[21],char p_sv_edit[5],char ps_edit[17]);
void giaophongSV(DS_SINH_VIEN &ds_sv);

//================= XY LY MON HOC =================

MON_HOC* kttrungMH(PTR_MH p,char m_mh[16]);
MON_HOC* duyet_theo_stt(PTR_MH p,int &z,int x);
void themMH(PTR_MH &p,char m_mh[16],char t_mh[51]);
void xoaMH(PTR_MH &p,char m_mh[16]);
void suaMH(PTR_MH &p,char m_mh[16],char t_mh_edit[51]);

// ================ XU LY CAU HOI ================
void themCH(DS_CAU_HOI &ds_ch,int id,char nd[72],char d_an_A[72],char d_an_B[72],char d_an_C[72],char d_an_D[72],char d_an[2]);
void xoaCH(DS_CAU_HOI &ds_ch,int id);
void suaCH(DS_CAU_HOI &ds_ch,int id,char nd[72],char d_an_A[72],char d_an_B[72],char d_an_C[72],char d_an_D[72],char d_an[2]);

// ================= DOC GHI FILE LOP =============

void docfileLop(DS_LOP &ds_lop);
void ghifileLop(DS_LOP ds_lop);

// ============== DOC GHI SINH VIEN ===============

void docfileSV(DS_SINH_VIEN *&ds_sv,char m_lop[16]);
void ghifileSV(DS_SINH_VIEN *&ds_sv,char m_lop[16]);

// ============== DOC GHI MON HOC ================

void docfileMH(PTR_MH &p,int &slmh);
void ghifileMH(PTR_MH &p);
void dequyghifile(PTR_MH &p, ofstream& fileOut);

// ============== DOC GHI CAU HOI ================

void docfileCH(DS_CAU_HOI &ds_ch,char m_mh[16]);
void ghifileCH(DS_CAU_HOI ds_ch,char m_mh[16]);

//================ XU LY LOP =====================

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
void themLop(DS_LOP &ds_lop,char m_lop[16],char t_lop[51])
{
	LOP *p=new LOP;
	strcpy(p->malop,m_lop);
	strcpy(p->tenlop,t_lop);
	ds_lop.ds[ds_lop.sl]=p;
	ds_lop.sl++;
}
void xoaLop(DS_LOP &ds_lop,char m_lop[16])
{
	int temp=kttrungLop(ds_lop,m_lop);
	for(int i=temp;i<=ds_lop.sl-1;i++)
	{
		strcpy(ds_lop.ds[i]->malop, ds_lop.ds[i+1]->malop);
		strcpy(ds_lop.ds[i]->tenlop, ds_lop.ds[i+1]->tenlop);
	}
	ds_lop.sl--;
}
void suaLop(DS_LOP &ds_lop,char m_lop_edit[16],char t_lop_edit[51])
{
	int temp=kttrungLop(ds_lop,m_lop_edit);
	strcpy(ds_lop.ds[temp]->tenlop,t_lop_edit);
}

// ============= DOC GHI FILE LOP ===============
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
	cout<<"Doc file LOP xong!"<<endl;
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
		createFile(ds_lop.ds[i]->malop);
	}
	fileOut.close();
}

// =============== XU LY SINH VIEN ==================
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
SINH_VIEN *kttrungSV(DS_LOP ds_lop,char m_sv[16])
{
	for(int i=0;i<ds_lop.sl;i++)
	{
		for(SINH_VIEN *p=ds_lop.ds[i]->first_SINH_VIEN->phead;p!=NULL;p=p->pnext)
		{
			if(strcmp(m_sv,p->masv)==0)
			{
				return p;
			}
		}
	}
	return NULL;
}
void themSV(DS_SINH_VIEN *&ds_sv,char m_sv[16],char h_sv[21],char t_sv[11],char p_sv[5],char ps[17])
{
	setbkcolor(MAU_XANH_DUONG_NHAT);
	SINH_VIEN *p=khoitao(m_sv,h_sv,t_sv,p_sv,ps);
	if(ds_sv->phead==NULL)
	{
		ds_sv->phead=ds_sv->ptail=p;
	}
	else
	{
		ds_sv->ptail->pnext=p;
		p->pnext=NULL;
		ds_sv->ptail=p;
	}
	ds_sv->sl++;
}
void xoaSV(DS_SINH_VIEN *&ds_sv,char m_sv[16])
{
	for(SINH_VIEN *p=ds_sv->phead;p!=NULL;p=p->pnext)
	{
		if(strcmp(ds_sv->phead->masv,m_sv)==0)
		{
			ds_sv->phead=p->pnext;
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
}
void suaSV(SINH_VIEN *p,char t_sv_edit[11],char h_sv_edit[21],char p_sv_edit[5],char ps_edit[17])
{
	strcpy(p->ho,h_sv_edit);
	strcpy(p->ten,t_sv_edit);
	strcpy(p->phai,p_sv_edit);
	strcpy(p->password,ps_edit);
}

// =============== DOC GHI FILE SINH VIEN ==========
void docfileSV(DS_SINH_VIEN *&ds_sv,char m_lop[16])
{
	char m_lop_temp[16]="";
	strcpy(m_lop_temp,m_lop);
	
	ifstream fileIn;
	fileIn.open(strcat(m_lop_temp,".txt"),ios_base :: in);
	fileIn>>m_lop;
	fileIn.ignore();
	while(!fileIn.eof())
	{
		SINH_VIEN *sv=new SINH_VIEN;
		fileIn.getline(sv->masv, sizeof(sv->masv),'\n');
		
		if(strlen(sv->masv) == 0) {  //kiem tra ky tu space cuoi cung trong file
			break;
		}
		fileIn.getline(sv->ho, sizeof(sv->ho),'\n');
		fileIn.getline(sv->ten, sizeof(sv->ten),'\n');
		fileIn.getline(sv->phai, sizeof(sv->phai), '\n');
		fileIn.getline(sv->password, sizeof(sv->password), '\n');
			
		themSV(ds_sv,sv->masv,sv->ho,sv->ten,sv->phai,sv->password);	
	}
	fileIn.close();
	cout<<"Doc file SINH VIEN xong!"<<endl;
}
void ghifileSV(DS_SINH_VIEN *&ds_sv,char m_lop[16])
{
	char m_lop_temp[16]="";
	strcpy(m_lop_temp,m_lop);
	
	ofstream fileOut;
	fileOut.open(strcat(m_lop_temp,".txt"),ios_base :: out);
	fileOut <<m_lop<< endl;
	for(SINH_VIEN *p=ds_sv->phead;p!=NULL;p=p->pnext)
	{
		fileOut << p->masv << endl;
		fileOut << p->ho << endl;
		fileOut << p->ten << endl;
		fileOut << p->phai << endl;
		fileOut << p->password << endl;
	}
	fileOut.close();
	cout<<"ghi file sv xong"<<endl;
}
void createFile(char ma[16]) // tao file
{
	char m_temp[16]="";
	strcpy(m_temp,ma);
	ofstream MyFile(strcat(m_temp,".txt"));
	MyFile.close();
}

// ============ XU LY MON HOC ================
MON_HOC* duyet_theo_stt(PTR_MH p,int &z,int x)
{
	if(p!=NULL)
	{
		duyet_theo_stt(p->left,z,x);
		if(z==x)
		{
			return p;
		}
		z++;
		duyet_theo_stt(p->right,z,x);
	}
}
MON_HOC* kttrungMH(PTR_MH p,char m_mh[16])
{
	if (p == NULL)
    {
        return NULL;
    }
    else
    {
        if (strcmp(p->mamh,m_mh)>0)
        {
            kttrungMH(p->left, m_mh);
        }
        else if (strcmp(p->mamh,m_mh)<0) 
        {
            kttrungMH(p->right, m_mh);
        }
        else if(strcmp(p->mamh,m_mh)==0)
        {
            return p; 
        }
    }
}
///========test========
void test(PTR_MH p) 
{
	if(p!=NULL)
	{
		test(p->left) ;
		cout<<p->mamh<<endl;
		cout<<p->tenmh<<endl;
		test(p->right) ;
	}
}
//=====================
void themMH(PTR_MH &p,char m_mh[16],char t_mh[51])
{
	cout<<"mon them: "<<m_mh<<endl;
	if(p==NULL)
	{
		PTR_MH a=new MON_HOC;
		strcpy(a->mamh,m_mh);
		strcpy(a->tenmh,t_mh);
		a->left=NULL;
		a->right=NULL;
		p=a;
		cout<<p->mamh<<" "<<p->tenmh<<endl;
		cout<<"them xong"<<endl;
	}
	else
	{
		if(strcmp(p->mamh,m_mh)>0)
		{
			themMH(p->left,m_mh,t_mh);
		}
		else if(strcmp(p->mamh,m_mh)<0)
		{
			themMH(p->right,m_mh,t_mh);
		}
	}
}
void remove_case_3 ( PTR_MH &r , PTR_MH &rp )
{
	if (r->left != NULL) 
	{
		remove_case_3 (r->left,rp);	
	}
	else
	{
		strcpy(rp->mamh,r->mamh); 
		strcpy(rp->tenmh,r->tenmh); 
		rp = r;
		r = rp->right;
	}
}
void NodeTheMang(PTR_MH &X, PTR_MH &Y) 
{
    if (Y->left != NULL)
    {
        NodeTheMang(X, Y->left);
    }
    else 
    {
        strcpy(X->mamh,Y->mamh);
        strcpy(X->tenmh,Y->tenmh);
        X->ds_ch=Y->ds_ch;
        X = Y; 
        Y = Y->right; 
    }
}
void xoaMH(PTR_MH &p,char m_mh[16])
{
	if(p==NULL)
	{
		resetThongBao();
		outtextxy(1030,150,"KHONG CO MON HOC");
		return;
	}
	else
	{
		if(strcmp(p->mamh,m_mh)>0)
		{
			xoaMH(p->left,m_mh);
		}
		else if(strcmp(p->mamh,m_mh)<0)
		{
			xoaMH(p->right,m_mh);
		}
		else
		{
			PTR_MH temp=p;
			if(p->left==NULL)
			{
				p=p->right;
			}
			else if(p->right==NULL)
			{
				p=p->left;
			}
			else
			{
				PTR_MH Y = p->right;
				cout<<"vao node the mang"<<endl;
				NodeTheMang(temp, Y);
			}
			delete temp;
		}
	}	
}
void suaMH(PTR_MH &p,char m_mh[16],char t_mh_edit[51])
{
	MON_HOC *x=kttrungMH(p,m_mh);
	strcpy(x->tenmh,t_mh_edit);
}

// =========== DOC GHI FILE MON HOC =============

void docfileMH(PTR_MH &p,int &slmh)
{
	ifstream fileIn;
	fileIn.open("ds_monhoc.txt",ios_base :: in);
	MON_HOC mh;
	while(!fileIn.eof())
	{
		fileIn.getline(mh.mamh,sizeof(mh.mamh),'\n');
		if(strlen(mh.mamh) == 0) {  //kiem tra ky tu space cuoi cung trong file
			break;
		}
		fileIn.getline(mh.tenmh,sizeof(mh.tenmh),'\n');
		themMH(p,mh.mamh,mh.tenmh);
		slmh++;
	} 
	fileIn.close();
	cout<<"Doc file MON HOC xong!"<<endl;
}
void ghifileMH(PTR_MH &p)
{
	ofstream fileOut;
	fileOut.open("ds_monhoc.txt",ios_base :: out);
	dequyghifile(p,fileOut);
	fileOut.close();
	cout<<"ghi file mon hoc xong"<<endl;	
}
void dequyghifile(PTR_MH &p, ofstream& fileOut)
{ 
     if (p != NULL)
    {
        dequyghifile(p->left, fileOut);
        fileOut<< p->mamh<<endl;
        createFile(p->mamh);
        fileOut<< p->tenmh<<endl;
        dequyghifile(p->right,fileOut);
    }
}

// ============= XU LY CAU HOI ==================
int kttrungCH(DS_CAU_HOI ds_ch,int id) 
{
	cout<<"zo"<<endl;
	for(int i=0;i<ds_ch.sl;i++)
	{
		if(ds_ch.ds[i].ID==id)
		{
			return i;
		}
	}
	return -1;
}
int createID(DS_CAU_HOI ds_ch)
{
	int id;
	do
	{
		id=rand()%(999-100+1)+100;
	}while(kttrungCH(ds_ch,id)>=0);
	return id;
}
void themCH(DS_CAU_HOI &ds_ch,int id,char nd[72],char d_an_A[72],char d_an_B[72],char d_an_C[72],char d_an_D[72],char d_an[2])
{
	CAU_HOI *p=new CAU_HOI;
	p->ID=id;
	strcpy(p->dapan,d_an);
	strcpy(p->noidung,nd);
	strcpy(p->dapanA,d_an_A);
	strcpy(p->dapanB,d_an_B);
	strcpy(p->dapanC,d_an_C);
	strcpy(p->dapanD,d_an_D);
	cout<<"noi dung: "<<p->noidung<<endl;
	ds_ch.ds[ds_ch.sl]=*p;
	cout<<"noi dung: "<<ds_ch.ds[ds_ch.sl].noidung<<endl;
	ds_ch.sl++;
}
void xoaCH(DS_CAU_HOI &ds_ch,int id)
{
	for(int i=0;i<ds_ch.sl;i++)
	{
		if(ds_ch.ds[i].ID==id)
		{
			cout<<"xoa: "<<ds_ch.ds[i].ID<<endl;
			for(int j=i;j<=ds_ch.sl-1;j++)
			{
				ds_ch.ds[j].ID=ds_ch.ds[j+1].ID;
				strcpy(ds_ch.ds[j].dapan,ds_ch.ds[j+1].dapan);
				strcpy(ds_ch.ds[j].noidung,ds_ch.ds[j+1].noidung);
				strcpy(ds_ch.ds[j].dapanA,ds_ch.ds[j+1].dapanA);
				strcpy(ds_ch.ds[j].dapanB,ds_ch.ds[j+1].dapanB);
				strcpy(ds_ch.ds[j].dapanC,ds_ch.ds[j+1].dapanC);
				strcpy(ds_ch.ds[j].dapanD,ds_ch.ds[j+1].dapanD);
				ds_ch.sl--;
			}
			return;
		}
	}
}
void suaCH(DS_CAU_HOI &ds_ch,int id,char nd[72],char d_an_A[72],char d_an_B[72],char d_an_C[72],char d_an_D[72],char d_an[2])
{
	for(int i=0;i<ds_ch.sl;i++)
	{
		if(ds_ch.ds[i].ID==id)
		{
			strcpy(ds_ch.ds[i].dapan,d_an);
			strcpy(ds_ch.ds[i].noidung,nd);
			strcpy(ds_ch.ds[i].dapanA,d_an_A);
			strcpy(ds_ch.ds[i].dapanB,d_an_B);
			strcpy(ds_ch.ds[i].dapanC,d_an_C);
			strcpy(ds_ch.ds[i].dapanD,d_an_D);
			break;
		}
	}
}
// ============= GHI FILE CAU HOI ===============
void duyet_mh_doc_file_CH(PTR_MH p)
{
	if(p!=NULL)
	{
		duyet_mh_doc_file_CH(p->left);
		docfileCH(p->ds_ch,p->mamh);
		duyet_mh_doc_file_CH(p->right);
	}
}
void docfileCH(DS_CAU_HOI &ds_ch,char m_mh[16])
{
	char m_mh_temp[16]="";
	strcpy(m_mh_temp,m_mh);
	ifstream fileIn;
	fileIn.open(strcat(m_mh_temp,".txt"),ios_base :: in);
	fileIn>>ds_ch.sl;
	fileIn.ignore();
	for(int i=0;i<ds_ch.sl;i++)
	{
		fileIn>>ds_ch.ds[i].ID;
		fileIn.ignore();
		fileIn.getline(ds_ch.ds[i].noidung,sizeof(ds_ch.ds[i].noidung),'\n');
		if(strlen(ds_ch.ds[i].noidung) == 0) {  //kiem tra ky tu space cuoi cung trong file
			break;
		}
		fileIn.getline(ds_ch.ds[i].dapanA,sizeof(ds_ch.ds[i].dapanA),'\n');
		fileIn.getline(ds_ch.ds[i].dapanB,sizeof(ds_ch.ds[i].dapanB),'\n');
		fileIn.getline(ds_ch.ds[i].dapanC,sizeof(ds_ch.ds[i].dapanC),'\n');
		fileIn.getline(ds_ch.ds[i].dapanD,sizeof(ds_ch.ds[i].dapanD),'\n');
		fileIn.getline(ds_ch.ds[i].dapan,sizeof(ds_ch.ds[i].dapan),'\n');
	}
	fileIn.close();
	cout<<"Doc file CAU HOI xong!"<<endl;
}
void ghifileCH(DS_CAU_HOI ds_ch,char m_mh[16])
{
	char m_mh_temp[16]="";
	strcpy(m_mh_temp,m_mh);
	ofstream fileOut;
	fileOut.open(strcat(m_mh_temp,".txt"), ios_base::out);

	fileOut << ds_ch.sl<< endl;
	for (int i = 0; i < ds_ch.sl; i++) 
	{
		fileOut << ds_ch.ds[i].ID << endl;
		fileOut << ds_ch.ds[i].noidung << endl;
		fileOut << ds_ch.ds[i].dapanA << endl;
		fileOut << ds_ch.ds[i].dapanB << endl;
		fileOut << ds_ch.ds[i].dapanC << endl;
		fileOut << ds_ch.ds[i].dapanD << endl;
		fileOut << ds_ch.ds[i].dapan << endl;
	}
	fileOut.close();
}

// ================== THI =========================
int kttrungCH_Thi(int arr[],int slch,int id)
{
	for(int i=0;i<slch;i++)
	{
		if(id==arr[i])
		{
			return i;
		}
	}
	return -1;
}
void random_CH(DS_CAU_HOI ds_ch,int arr[],int slch)
{
	for(int i=0;i<slch;i++)
	{
		arr[i]=-1;
	}
	int vt;
	for(int i=0;i<slch;i++)
	{
		do
		{
			vt=rand()%((ds_ch.sl));
		}while(kttrungCH_Thi(arr,slch,ds_ch.ds[vt].ID)>=0);
		arr[i]=ds_ch.ds[vt].ID;	
	}
}
void themBT(DS_BAI_THI &ds_bt,int slc,char m_sv[16],char m_mh[16],char *ds_tl,int * ds_ch_thi)
{
	BAI_THI *p=new BAI_THI;
	
	p->slc=slc;
	strcpy(p->mamh,m_mh);
	strcpy(p->masv,m_sv);
	p->ds_tl=new char[p->slc];
	p->ds_ch_thi=new int[p->slc];
	p->ds_ch_thi=ds_ch_thi;
	p->ds_tl=ds_tl;
	
	ds_bt.ds[ds_bt.sl]=p;
	ds_bt.sl++;
}
//================== DOC GHI FILE BAI THI =====================
void docfileBT(DS_BAI_THI &ds_bt)
{


	ifstream fileIn;
	fileIn>>ds_bt.sl;
	fileIn.ignore();
	for(int i=0;i<ds_bt.sl;i++)
	{
		BAI_THI bt;
		fileIn>>ds_bt.sl;
		fileIn.ignore();
		fileIn>>bt.slc;
		fileIn.ignore();
		fileIn.getline(bt.mamh,sizeof(bt.mamh),'\n');
		if(strlen(bt.mamh) == 0) 
		{  
			break;
		}
		fileIn.getline(bt.masv,sizeof(bt.masv),'\n');
		bt.ds_tl=new char[bt.slc];
		for(int j=0;j<bt.slc;j++)
		{
			if(j==bt.slc-1)
			{
				char *a=new char;
				fileIn.getline(a,sizeof(a),'\n');	
				bt.ds_tl[j]=*a;
			}
			else
			{
				char *a=new char;
				fileIn.getline(a,sizeof(a),',');	
				bt.ds_tl[j]=*a;
			}
		}	
		for(int j=0;j<bt.slc;j++)
		{
			if(j==bt.slc-1)
			{
				char *a=new char;
				fileIn.getline(a,sizeof(a),'\n');	
				bt.ds_ch_thi[j]=*a;	
			}
			else
			{
				char *a=new char;
				fileIn.getline(a,sizeof(a),',');	
				bt.ds_ch_thi[j]=*a;	
			}
		}
		*ds_bt.ds[ds_bt.sl]=bt;
		ds_bt.sl++;
	}
	fileIn.close();
	cout<<"Doc file BAI THI xong!"<<endl;
}
