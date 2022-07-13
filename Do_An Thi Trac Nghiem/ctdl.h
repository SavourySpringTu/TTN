#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <winbgim.h>
#include <string>
#include <fstream>

using namespace std;

// sinh vien
struct sinh_vien // ds lien ket don
{
	char masv[16];
	char ho[21];
	char ten[11];
	char phai[5];
	string password[17];
	sinh_vien *pnext;	
};
typedef struct sinh_vien SINH_VIEN;
struct ds_sinh_vien
{
	sinh_vien *phead=NULL;
	int sl=0;	
};
typedef struct ds_sinh_vien DS_SINH_VIEN;

// cau hoi
struct cau_hoi // ds tuyen tinh
{
	int ID;
	char noidung[126];
	char dapanA[126];
	char dapanB[126];
	char dapanC[126];
	char dapanD[126];
	char dapan;
	char mamh[16];	
};
typedef struct cau_hoi CAU_HOI;
struct ds_cau_hoi
{
	CAU_HOI ds[200];
	int sl=0;
};
typedef struct ds_cau_hoi DS_CAU_HOI;

// mon hoc
struct mon_hoc // cay nhi phan
{
	char mamh[16];
	char tenmh[51];
	mon_hoc *left;
	mon_hoc *right;
	DS_CAU_HOI ds_cau_hoi;
};
typedef struct mon_hoc *tree;
struct ds_mon_hoc
{
	tree ds=NULL;
	int sl=0;
};
typedef struct ds_mon_hoc DS_MON_HOC;

// diem thi
struct diem_thi// ds lien ket don
{
	char mamh[16];
	float diem;
	diem_thi *pnext;
};
typedef struct diem_thi DIEM_THI;
struct ds_diem_thi 
{
	diem_thi *phead=NULL;
	int sl=0;
};
typedef struct ds_diem_thi DS_DIEM_THI;

// lop
struct lop // mang con tro
{
	char malop[16];
	char tenlop[51];
	DS_SINH_VIEN ds_sinh_vien;
};
typedef struct lop LOP;
struct ds_lop
{
	LOP *ds[10];
	int sl=0;
};
typedef struct ds_lop DS_LOP;

// bai thi
struct bai_thi
{
	int socauhoi;
	char* dapanchon;
	cau_hoi* cht;
};

