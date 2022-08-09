#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <winbgim.h>
#include <string>
#include <fstream>

using namespace std;

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

// sinh vien
struct sinh_vien // ds lien ket don
{
	char masv[16];
	char ho[21];
	char ten[11];
	char phai[5];
	char password[17];
	sinh_vien *pnext;
	DIEM_THI *first_DIEM_THI;	
};
typedef struct sinh_vien SINH_VIEN;
struct ds_sinh_vien
{
	sinh_vien *phead=NULL;
	sinh_vien *ptail=NULL;
	int sl=0;	
};
typedef struct ds_sinh_vien DS_SINH_VIEN;

// cau hoi
struct cau_hoi // ds tuyen tinh
{
	int ID;
	char noidung[72];
	char dapanA[72];
	char dapanB[72];
	char dapanC[72];
	char dapanD[72];
	char dapan[2];
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
	char mamh[16]; // khoa chinh
	char tenmh[51];
	mon_hoc *left;
	mon_hoc *right;
	DS_CAU_HOI ds_ch;
};
typedef struct mon_hoc MON_HOC;
typedef MON_HOC* PTR_MH;
//struct ds_mon_hoc
//{
//	PTR_MH tree=NULL;
//	int sl=0;
//};
//typedef struct ds_mon_hoc DS_MON_HOC;
// lop
struct lop // mang con tro
{
	char malop[16];
	char tenlop[51];
	DS_SINH_VIEN *first_SINH_VIEN= new DS_SINH_VIEN[100];
};
typedef struct lop LOP;
struct ds_lop
{
	LOP *ds[25];
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

