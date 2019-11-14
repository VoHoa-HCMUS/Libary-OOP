#pragma once
#include"DanhSach.h"
#include<Windows.h>
#include"DataBase.h"
class Guest
{
protected:
	string accountname;
	string password;
	DataBase data;
public:
	virtual void DangNhap(int& op) {};
	virtual void DangKi() {};
    void TimSach(DanhSach);
	virtual void XoaAccount(int) {};
	virtual void MuaSach(DanhSach) {};
	virtual void SetSLSach(DanhSach) {};
	virtual void ThemSach(DanhSach&) {};
	virtual void XoaSach(DanhSach&) {};
	virtual void SuaSach(DanhSach&) {};
	virtual void XoaSachCuaTacGia(DanhSach&) {};
	virtual void XoaSachCuaNXB(DanhSach&) {};
	virtual int GetSLSach() { return 0; };
	void SetDataBase(DanhSach&);
};

