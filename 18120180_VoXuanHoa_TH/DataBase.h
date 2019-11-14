#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include"DanhSach.h"
using namespace std;
class DataBase
{
private:
	vector<string> name;
	vector<string> password;
	vector<Sach> deletedau;
	vector<Sach> deletedpub;
public:
	int CheckAccount(string, string);
	int CheckValidRegister(string,string);
	int CheckAdminAccount(string, string);
	void AddAccount(string, string);
	bool DeleteAccount(string);
	void LoadDataBase();
	void OutPutDataBase();
	void LoadBook(DanhSach l);
	void LoadAccount();
};

