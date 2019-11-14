#include "Sach.h"
#include <iomanip>
void Sach::Nhap(ifstream *filein)
{
	getline(*filein, Ma, ',');
	if (Ma[0] == '\n')
	 Ma.erase(0,1);
	getline(*filein, Ten, ',');
	getline(*filein, NXB, ',');
	getline(*filein, TacGia, ',');
	*filein >> Gia;
}
void Sach::Xuat()
{
	cout << left << setw(5) << Ma << setw(20) <<  Ten << setw(30) << NXB << setw(40) << TacGia << Gia << endl;
}
string Sach::GetTen()
{
	return Ten;
}
string Sach::GetMa()
{
	return Ma;
}
int Sach::GetGia()
{
	return Gia;
}
void Sach::Set(Sach b)
{
	Gia = b.GetGia();
	Ten = b.GetTen();
	Ma = b.GetMa();
	TacGia = b.GetTacGia();
	NXB = b.GetNXB();
}
string Sach::GetTacGia()
{
	return TacGia;
}
string Sach::GetNXB()
{
	return NXB;
}
void Sach::SetTen(string name)
{
	Ten = name;
}
void Sach::SetMa(string id)
{
	Ma = id;
}
void Sach::SetTacGia(string tacgia)
{
	TacGia = tacgia;
}
void Sach::SetNXB(string _NXB)
{
	NXB = _NXB;
}
void Sach::SetGia(int _Gia)
{
	Gia = _Gia;
}
bool Sach::KiemTraTenTacGia(string au)
{
	string Temp = TacGia;
	Temp.append(" ft");
	int j = 0;
	for (int i = 0; i < Temp.length(); i++) 
	{
		if (Temp[i] == ' ' && Temp[i + 1] == 'f' && Temp[i + 2] == 't') 
		{
			if(au == Temp.substr(j, i - j))
			    return true;
			j = i + 4;
		}
	}
	return false;
}
bool Sach::KiemTraTenNXB(string pub)
{
	string Temp = NXB;
	Temp.append(" ft");
	int j = 0;
	for (int i = 0; i < Temp.length(); i++)
	{
		if (Temp[i] == ' ' && Temp[i + 1] == 'f' && Temp[i + 2] == 't')
		{
			if (pub == Temp.substr(j, i - j))
				return true;
			j = i + 4;
		}
	}
	return false;
}