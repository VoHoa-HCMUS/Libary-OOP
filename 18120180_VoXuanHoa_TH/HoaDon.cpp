#include "HoaDon.h"
#include <iomanip>
void HoaDon::AddSach(Sach b,int &m)
{
	a.Set(b);
	m++;
}
int HoaDon::TinhTien(HoaDon h[],int m)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += h[i].a.GetGia()*h[i].Soluong;
	}
	return sum;
}
void HoaDon::SetSoLuong(int num)
{
	Soluong = num;
}
void HoaDon::XuatHoaDon(HoaDon h[], int m)
{
	cout << left << setw(5) << "STT" << setw(5) << "SL" << setw(5) << "Ma" << setw(20) << "Ten" << setw(30) << "NXB" << setw(40) << "TacGia" << "Gia" << endl;
	int j = 1;
	for (int i = 0; i < m; i++)
	{
		if (h[i].a.GetMa() != "")
		{ 
			cout << left << setw(5) << j;
			cout << left << setw(5) << h[i].GetSoLuong();
			h[i].a.Xuat();
			j++;
		}
	}
}
void HoaDon::XoaSach(HoaDon h[], int m,string id)
{
	for (int i = 0; i < m; i++)
	{
		if (h[i].GetSach().GetMa() == id)
		{
			h[i].SetSoLuong(0);
			h[i].a.~Sach();
		}
	}
}
Sach HoaDon::GetSach()
{
	return a;
}
int HoaDon::GetSoLuong()
{
	return Soluong;
}
bool HoaDon::KiemTraHoaDonRong(HoaDon h[], int m)
{
	for (int i = 0; i < m; i++)
	{
		if (h[i].a.GetMa() != "")
			return false;
	}
	return true;
}
bool HoaDon::KiemTraSachThuocHoaDon(HoaDon h[], int m,string id)
{
	for (int i = 0; i < m; i++)
	{
		if (h[i].a.GetMa() == id)
			return true;
	}
	return false;
}