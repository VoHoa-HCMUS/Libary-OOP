#pragma once
#include"Guest.h"
class Publisher:public virtual Guest
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
	string TenNXB(string);
	int KiemTraSachThuocNXB(DanhSach,string);
	void SetSLSach(DanhSach);
    int GetSLSach();
};

