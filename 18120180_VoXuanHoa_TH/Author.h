#pragma once
#include"Guest.h"
class Author: public virtual Guest
{
private:
	int SLsach;
public:
    void DangNhap(int&);
	void DangKi();
    void XoaSach(DanhSach&);
	void ThemSach(DanhSach&);
	void SuaSach(DanhSach&);
	bool KiemTraDangNhap(string);
	string TenTacGia(string);
	int KiemTraSachThuocTacGia(DanhSach, string);
	void SetSLSach(DanhSach l);
    int GetSLSach();
};

