#include "DanhSach.h"
#include <iomanip>
void DanhSach::Nhap(ifstream *filein)
{
	while (!filein->eof())
	{
		Sach a;
		a.Nhap(filein);
		if (a.GetMa() == "")
			return;
		s.push_back(a);
	}
}
void DanhSach::Xuat()
{
	int j = 1;
	cout << left << setw(5) << "STT" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << left << setw(5) << j;
		s[i].Xuat();
		j++;
	}
}
int DanhSach::Count(string name)
{
	int dem = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
			dem++;
	}
	return dem;
}
void DanhSach::XuatSachTrung(string name)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
			s[i].Xuat();
	}
}
Sach DanhSach::GetSachTheoTen(string name)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
			return s[i];
	}
}
Sach DanhSach::GetSachTheoMa(string ma)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == ma)
			return s[i];
	}
}
void DanhSach::TimSachTheoTen(string name)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
			s[i].Xuat();
	}
}
void DanhSach::TimSachTheoMa(string id,bool& check)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == id)
		{
			s[i].Xuat();
			return;
		}
	}
	check = false;
}
bool DanhSach::KiemTraDanhSachRong()
{
	if (s.size()==0)
		return true;
	return false;
}
void DanhSach::XoaSachTheoTen(string name)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
		{
			s.erase(s.begin()+i);
			return;
		}
	}
}
void DanhSach::XoaSachTheoMa(string id)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == id)
		{
			s.erase(s.begin() + i);
			return;
		}
	}
}
void DanhSach::ThemSach(string name, string id, string tacgia, string NXB, int gia)
{
	Sach a;
	a.SetTen(name);
	a.SetMa(id);
	a.SetTacGia(tacgia);
	a.SetNXB(NXB);
	a.SetGia(gia);
	s.push_back(a);
}
int DanhSach::KiemTraNXB(string type, string _NXB)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == type && s[i].KiemTraTenNXB(_NXB))
			return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == type && s[i].KiemTraTenNXB(_NXB))
			return 1;
	}
	return -1;
}
int DanhSach::KiemTraTacGia(string type, string tg)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == type && s[i].KiemTraTenTacGia(tg))
			return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == type && s[i].KiemTraTenTacGia(tg))
			return 1;
	}
	return -1;
}
int DanhSach::DemSachCuaTacGia(string name)
{
	int dem = 0;
	for(int i=0;i < s.size();i++)
	{
		if (s[i].KiemTraTenTacGia(name))
			dem++;
	}
	return dem;
}
int DanhSach::DemSachCuaNXB(string name)
{
	int dem = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].KiemTraTenNXB(name))
			dem++;
	}
	return dem;
}
void DanhSach::SuaGiaSachTheoTen(string name, int newgia)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTen() == name)
		{
			s[i].SetGia(newgia);
			return;
		}
	}
}
void DanhSach::SuaGiaSachTheoMa(string id, int newgia) 
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetMa() == id)
		{
			s[i].SetGia(newgia);
			return;
		}
	}
}
void DanhSach::XuatRaFile(ofstream& filebook)
{
	for (int i = 0; i < s.size();i++)
	{
	    filebook << s[i].GetMa() << "," << s[i].GetTen() << "," << s[i].GetNXB() << "," << s[i].GetTacGia() << "," << s[i].GetGia();
		filebook << '\n';
	}
}
bool DanhSach::XoaSachTheoTacGia(string au)
{
	int dem = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetTacGia() == au)
		{
			s.erase(s.begin() + i);
			dem++;
		}
	}
	if (dem == 0)
		return false;
	return true;
}
bool DanhSach::XoaSachTheoNXB(string pub)
{
	int dem = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].GetNXB() == pub)
		{
			s.erase(s.begin() + i);
			dem++;
		}
	}
	if (dem == 0)
		return false;
	return true;
}