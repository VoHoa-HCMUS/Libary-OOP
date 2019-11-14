#include "Publisher.h"
void Publisher::DangNhap(int& op)
{
	data.LoadDataBase();
	cin.ignore();
	while (true)
	{
		try
		{
			cout << "Nhap 1 de dang nhap,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw 2;
			if (op == 0)
				break;
			cout << "Nhap ten dang nhap(co dang NXB-Ten Nha Xuat Ban): ";
			cin.clear();
			cin.ignore();
			getline(cin, accountname);
			if (!KiemTraDangNhap(accountname))
				throw false;
			else
			{
				cout << "Nhap mat khau: ";
				getline(cin, password);
			}
			if (data.CheckAccount(accountname, password) == 1)
				break;
			else if (data.CheckAccount(accountname, password) == 0)
				throw 0;
			else if (data.CheckAccount(accountname, password) == -1)
				throw - 1;

		}
		catch (bool)
		{
			cout << "Ten tai khoan khong hop le!" << endl;
		}
		catch (int x)
		{
			if (x == 0)
				cout << "Ten dang nhap hoac mat khau sai!!!" << endl;
			else if (x == -1)
				cout << "Tai khoan khong ton tai!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
bool Publisher::KiemTraDangNhap(string name)
{
	if (name.substr(0, 4) != "NXB-")
	{
		return true;
	}
	return false;
}
string Publisher::TenNXB(string name)
{
	return(name.substr(4, name.length()));
}
void Publisher::ThemSach(DanhSach& l)
{
	while (true)
	{
		int op;
		cout << "Nhap 1 de them,0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string name, id, tacgia;
			int gia;
			cout << "Nhap ten sach can them: ";
			cin.ignore();
			getline(cin, name);
			cout << "Nhap ma sach can them: ";
			getline(cin, id);
			cout << "Nhap tac gia cua quyen sach: ";
			getline(cin, tacgia);
			cout << "Nhap gia sach: ";
			cin >> gia;
			l.ThemSach(name, id, tacgia, TenNXB(accountname), gia);
			cout << "Thu vien sau khi them cuon sach cua ban." << endl;
			l.Xuat();
			data.LoadBook(l);
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Publisher::XoaSach(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat:";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			if (l.KiemTraDanhSachRong())
				cout << "Danh sach rong" << endl;
			else
			{
				string name;
				cout << "Nhap ten sach can xoa:";
				cin.ignore();
				getline(cin, name);
				if (l.Count(name) == 0)
				{
					cout << "Khong tim thay sach." << endl;
				}
				else
					if (KiemTraSachThuocNXB(l,name)==0)
					{
						l.XoaSachTheoTen(name);
						cout << "Thu vien sau khi xoa cuon " << name << " :" << endl;
						l.Xuat();
						data.LoadBook(l);
					}
					else if(KiemTraSachThuocNXB(l, name) == 1)
					{
						string id;
						cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
						l.XuatSachTrung(name);
						cout << "Nhap ma sach can xoa: ";
						getline(cin, id);
						if (KiemTraSachThuocNXB(l, id) == 2)
						{
							l.XoaSachTheoMa(id);
							cout << "Thu vien sau khi xoa cuon " << name << " co ma " << id << ":" << endl;
							l.Xuat();
							data.LoadBook(l);
						}
						else
							cout << "Cuon sach khong thuoc ve NXB cua ban!" << endl;
					}
					else
						cout << "Cuon sach khong thuoc ve NXB cua ban!" << endl;
			}
		}
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
int Publisher::KiemTraSachThuocNXB(DanhSach l,string type)
{
	if (l.KiemTraNXB(type, TenNXB(accountname))==0&&l.Count(type)==1)
		return 0;
	if (l.KiemTraNXB(type, TenNXB(accountname))==0&& l.Count(type) > 1)
		return 1;
	if(l.KiemTraNXB(type, TenNXB(accountname)) == 1)
		return 2;
	return -1;
}
void Publisher::SetSLSach(DanhSach l)
{
	int num = l.DemSachCuaNXB(TenNXB(accountname));
	SLsach = num;
}
int Publisher::GetSLSach()
{
	return SLsach;
}
void Publisher::SuaSach(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de sua, 0 de thoat:";
		cin >> op;
		switch (op)
		{
		case 0:
		{

		}
		break;
		case 1:
		{
			if (l.KiemTraDanhSachRong())
				cout << "Danh sach rong" << endl;
			else
			{
				string name;
				cout << "Nhap ten sach can sua:";
				cin.ignore();
				getline(cin, name);
				if (l.Count(name) == 0)
				{
					cout << "Khong tim thay sach." << endl;
				}
				else
					if (KiemTraSachThuocNXB(l, name) == 0)
					{
						int newgia;
						cout << "Nhap gia moi: ";
						cin >> newgia;
						l.SuaGiaSachTheoTen(name,newgia);
						cout << "Thu vien sau sua gia cuon " << name << " :" << endl;
						l.Xuat();
						data.LoadBook(l);
					}
					else if (KiemTraSachThuocNXB(l, name) == 1)
					{
						string id;
						cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
						l.XuatSachTrung(name);
						cout << "Nhap ma sach can sua: ";
						getline(cin, id);
						int newgia;
						cout << "Nhap gia moi: ";
						cin >> newgia;
						if (KiemTraSachThuocNXB(l, id) == 2)
						{
							l.SuaGiaSachTheoMa(id,newgia);
							cout << "Thu vien sau sua gia cuon " << name << " co ma " << id << ":" << endl;
							l.Xuat();
							data.LoadBook(l);
						}
						else
							cout << "Ban khong la nha xuat ban cua cuon sach nay!" << endl;
					}
					else
						cout << "Ban khong la nha xuat ban cua cuon sach nay!" << endl;
			}
		}
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op == 0)
		{
			system("CLS");
			break;
		}
	}
}
void Publisher::DangKi()
{
	data.LoadDataBase();
	cout << "Luu y !!!: Ten tai khoan va mat khau khong duoc chua ki tu dac biet." << endl;
	while (true)
	{
		try
		{
			int op;
			cout << "Nhap 1 de dang ki,0 de thoat:";
			cin >> op;
			if (op != 1 && op != 0)
				throw -1;
			if (op == 0)
			{
				system("CLS");
				break;
			}
			cout << "Nhap ten dang nhap(co dang NXB-Ten Nha Xuat Ban): ";
			cin.clear();
			cin.ignore();
			getline(cin, accountname);
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (!KiemTraDangNhap(accountname) || data.CheckValidRegister(accountname, password) == 0 || data.CheckValidRegister(accountname, password) == 2)
				throw false;
			if (data.CheckValidRegister(accountname,password) == -1)
				throw 0;
			else
			{
				data.AddAccount(accountname, password);
				cout << "Dang ki thanh cong!!!";
				Sleep(500);
				system("CLS");
				break;
			}

		}
		catch (bool)
		{
			cout << "Ten tai khoan hoac mat khau khong hop le!" << endl;
		}
		catch (int x)
		{
			if (x == -1)
				cout << "Lua chon khong hop le!!!" << endl;
			else
				cout << "Ten nguoi dung da ton tai,vui long chon ten khac!!!" << endl;
		}
	}
}