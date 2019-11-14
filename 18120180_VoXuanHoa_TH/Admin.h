#pragma once
#include"User.h"
#include"Publisher.h"
#include"Author.h"
class Admin :public User, public Publisher, public Author
{
public:
	void DangNhap(int&);
	void DangKi(){};
	void XoaSach(DanhSach&);
	void XoaSachCuaTacGia(DanhSach&);
	void XoaSachCuaNXB(DanhSach&);
	void XoaAccount(int);
	void ThemSach(DanhSach&);
	void SuaSach(DanhSach&);
	void SetSLSach(DanhSach) {};
	int GetSLSach() { return 0; };
};