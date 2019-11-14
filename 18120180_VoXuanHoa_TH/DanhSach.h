#pragma once
#include"Sach.h"
#include<vector>
class DanhSach
{
private:
	vector<Sach> s;
public:
	void Nhap(ifstream*);
	void Xuat();
	int Count(string);
	void XuatSachTrung(string);
	Sach GetSachTheoTen(string);
	Sach GetSachTheoMa(string);
	void TimSachTheoTen(string);
	void TimSachTheoMa(string, bool&);
	void XoaSachTheoTen(string);
	void XoaSachTheoMa(string);
	bool XoaSachTheoTacGia(string);
	bool XoaSachTheoNXB(string);
	bool KiemTraDanhSachRong();
	void ThemSach(string, string, string, string,int);
	int KiemTraNXB(string, string);
	int KiemTraTacGia(string, string);
	int DemSachCuaTacGia(string);
	int DemSachCuaNXB(string);
	void SuaGiaSachTheoTen(string,int);
	void SuaGiaSachTheoMa(string, int);
	void XuatRaFile(ofstream&);
	void XuatSachTacGia();
	void XuatSachNXB();
};

