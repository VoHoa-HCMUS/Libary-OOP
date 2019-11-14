#pragma once
#include"Guest.h"
#include"HoaDon.h"
#include"DataBase.h"
class User: public virtual Guest
{
protected:
	HoaDon h[100];
public:
	virtual void MuaSach(DanhSach l);
    void CapNhatHoaDon(DanhSach l,int &m,int type);
    virtual void DangNhap(int&);
    void DangKi();
};

