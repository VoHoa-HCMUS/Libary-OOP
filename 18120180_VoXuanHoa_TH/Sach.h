#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
class Sach
{
private:
	string Ten;
	string Ma;
	string NXB;
	string TacGia;
	int Gia;
public:
	void Set(Sach b);
	void Nhap(ifstream *filein);
	void Xuat();
	string GetTen();
	string GetMa();
	string GetTacGia();
	string GetNXB();
	int GetGia();
	void SetTen(string);
	void SetMa(string);
	void SetTacGia(string);
	void SetNXB(string);
	void SetGia(int);
	bool KiemTraTenTacGia(string);
	bool KiemTraTenNXB(string);
};

