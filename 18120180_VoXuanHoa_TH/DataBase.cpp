#include "DataBase.h"
void DataBase::LoadDataBase()
{
	fstream fileacc;
	name.push_back("AD-Hoa");
	password.push_back("1620");
	fileacc.open("account.txt");
	while (!fileacc.eof())
	{
		string s1;
		string s2;
		getline(fileacc, s1,',');
		name.push_back(s1);
		getline(fileacc, s2);
		password.push_back(s2);
	}
	fileacc.close();
}
int DataBase::CheckAccount(string s1, string s2)
{
	for (int i = 1; i < name.size(); i++)
	{
		if ((name[i] != s1 && password[i] == s2)||(name[i]==s1&&password[i]!=s2))
			return 0;
		if (name[i] == s1 && password[i] == s2)
			return 1;
	}
	return -1;
}
void DataBase::OutPutDataBase()
{
	for (int i = 0;i < name.size(); i++)
	{
		cout << name[i] << "   " << password[i] << endl;
	}
}
void DataBase::AddAccount(string name, string password)
{
	ofstream fileacc;
	fileacc.open("account.txt",ios::app);
	fileacc.seekp(0,ios::end);
	int pos = fileacc.tellp();
	if (pos == 0)
	{
		fileacc << name + "," + password;
	}
	else
	{
		fileacc << '\n';
		fileacc << name + "," + password;
	}
}
int DataBase::CheckAdminAccount(string s1, string s2)
{
	if ((name[0] != s1 && password[0] == s2) || (name[0] == s1 && password[0] != s2))
		return 0;
	if (name[0] == s1 && password[0] == s2)
		return 1;
	return -1;
}
int DataBase::CheckValidRegister(string s1,string s2)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == s1)
			return -1;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (toascii(s1[i]) >= 0 && toascii(s1[i]) <= 44)
			return 0;
	}
	for (int i = 0; i < s2.length(); i++)
	{
		if (toascii(s2[i]) >= 0 && toascii(s2[i]) <= 44)
			return 2;
	}
	return 1;
}
void DataBase::LoadBook(DanhSach l)
{
	ofstream filebook;
	filebook.open("books.txt", ios::trunc);
	l.XuatRaFile(filebook);
	filebook.close();
}
bool DataBase::DeleteAccount(string s1)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == s1)
		{
			name.erase(name.begin() + i);
			return true;
		}
	}
	return false;
}
void DataBase::LoadAccount()
{
	ofstream fileacc;
	fileacc.open("account.txt", ios::trunc);
	fileacc.seekp(0, ios::end);
	int pos = fileacc.tellp();
	if (pos == 0)
	{
		return;
	}
	else
	{
		while (!fileacc.eof())
		{
			for (int i = 0; i < name.size(); i++)
			{
				fileacc << name[i] + "," + password[i] + "\n";
			}
		}
	}
	fileacc.close();
}
//void DataBase::LoadDeletedAu()
//{
//	ifstream delau;
//	delau.open("deletedauthor.txt");
//	while (!delau.eof())
//	{
//		string s1, s2, s3, s4;
//		int x;
//		Sach a;
//		getline(delau, s1, ',');
//		if (s1[0] == '\n')
//			s1.erase(0, 1);
//		if (s1 == "")
//			break;
//		getline(delau, s2, ',');
//		getline(delau, s3, ',');
//		getline(delau, s4, ',');
//		delau >> x;
//		a.SetMa(s1);
//		a.SetTen(s2);
//		a.SetNXB(s3);
//		a.SetTacGia(s4);
//		a.SetGia(x);
//		deletedau.push_back(a);
//	}
//	delau.close();
//}
//void DataBase::LoadDeletedPub()
//{
//
//}
//bool DataBase::CheckDeledAu(string name,string id)
//{
//	for (int i = 0; i < deletedau.size(); i++)
//	{
//		if (deletedau[i].GetTacGia()==name&& deletedau[i].GetMa()==id)
//			return true;
//	}
//	return false;
//}
//void DataBase::UpdateDelBook(int type)
//{
//	if (type == 1)
//	{
//		ofstream filedel;
//		filedel.open("deletedauthor.txt", ios::trunc);
//		while (!filedel.eof())
//		{
//			for (int i = 0; i < name.size(); i++)
//			{
//				filedel << deletedau[i].GetMa() + "," + deletedau[i].GetTen() + "," + deletedau[i].GetNXB() + "," + deletedau[i].GetTacGia() + "," << deletedau[i].GetGia << "\n";
//			}
//		}
//		filedel.close();
//	}
//	else
//	{
//		ofstream filedel;
//		filedel.open("deletedpublisher.txt", ios::trunc);
//		while (!filedel.eof())
//		{
//			for (int i = 0; i < name.size(); i++)
//			{
//				filedel << deletedau[i].GetMa() + "," + deletedau[i].GetTen() + "," + deletedau[i].GetNXB() + "," + deletedau[i].GetTacGia() + "," << deletedau[i].GetGia << "\n";
//			}
//		}
//		filedel.close();
//	}
//}
//void DataBase::AddDelBook(int type,Sach a)
//{
//	deletedau.push_back(a);
//}