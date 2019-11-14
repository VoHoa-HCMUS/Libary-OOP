#pragma once
#include"Sach.h"
class HoaDon
{
private:
	Sach a;
	int Soluong;
	int gia;
public:
	int TinhTien(HoaDon[],int);
	void AddSach(Sach,int&);
	void SetSoLuong(int);
	void XuatHoaDon(HoaDon[], int);
	void XoaSach(HoaDon[], int, string);
	bool KiemTraHoaDonRong(HoaDon[],int);
	bool KiemTraSachThuocHoaDon(HoaDon[], int, string);
	Sach GetSach();
	int GetSoLuong();
};

