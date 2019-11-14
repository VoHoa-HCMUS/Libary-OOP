#include "Admin.h"
void Admin::XoaSach(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
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
				cout << "Nhap ten sach can xoa: ";
				cin.ignore();
				getline(cin, name);
				if (l.Count(name) == 0)
				{
					cout << "Khong tim thay sach." << endl;
				}
				else
					if (l.Count(name) == 1)
					{
						l.XoaSachTheoTen(name);
						cout << "Thu vien sau khi xoa cuon " << name << " :" << endl;
						l.Xuat();
						data.LoadBook(l);
					}
					else
					{
						string id;
						cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
						l.XuatSachTrung(name);
						cout << "Nhap ma sach can xoa: ";
						getline(cin, id);
						l.XoaSachTheoMa(id);
						cout << "Thu vien sau khi xoa cuon " << name << " co ma "<<id<<":"<< endl;
						l.Xuat();
						data.LoadBook(l);
					}
			}
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
void Admin::ThemSach(DanhSach& l)
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
			string name, id, NXB,tg;
			int gia;
			cout << "Nhap ten sach can them: ";
			cin.ignore();
			getline(cin, name);
			cout << "Nhap ma sach can them: ";
			getline(cin, id);
			cout << "Nhap tac gia cua cuon sach can them: ";
			getline(cin, tg);
			cout << "Nhap NXB cua quyen sach: ";
			getline(cin, NXB);
			cout << "Nhap gia sach: ";
			cin >> gia;
			l.ThemSach(name, id, tg, NXB, gia);
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
void Admin::SuaSach(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de sua, 0 de thoat: ";
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
				cout << "Nhap ten sach can sua: ";
				cin.ignore();
				getline(cin, name);
				if (l.Count(name) == 0)
				{
					cout << "Khong tim thay sach." << endl;
				}
				else
					if (l.Count(name) == 1)
					{
						int newgia;
						cout << "Nhap gia moi: ";
						cin >> newgia;
						l.SuaGiaSachTheoTen(name,newgia);
						cout << "Thu vien sau khi sua gia cuon " << name << " :" << endl;
						l.Xuat();
						data.LoadBook(l);
					}
					else
					{
						string id;
						cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
						l.XuatSachTrung(name);
						cout << "Nhap ma sach can sua: ";
						getline(cin, id);
						int newgia;
						cout << "Nhap gia moi: ";
						cin >> newgia;
						l.SuaGiaSachTheoMa(id, newgia);
						cout << "Thu vien sau khi sua gia cuon " << name << " co ma " << id << ":" << endl;
						l.Xuat();
						data.LoadBook(l);
					}
			}
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
void Admin::DangNhap(int &op)
{
	data.LoadDataBase();
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
			cout << "Nhap ten dang nhap: ";
			cin.ignore();
			getline(cin, accountname);
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (data.CheckAdminAccount(accountname, password) == 1)
				break;
			else if (data.CheckAdminAccount(accountname, password) == 0)
				throw false;
			else
				throw - 1;
		}
		catch (bool)
		{
			cout << "Ten dang nhap hoac mat khau sai!!!" << endl;
		}
		catch (int x)
		{
			if (x == -1)
				cout << "Tai khoan khong ton tai!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void Admin::XoaSachCuaTacGia(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
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
				cout << "Nhap ten tac gia can xoa: ";
				cin.ignore();
				getline(cin, name);
				if (l.XoaSachTheoTacGia(name))
				{
					cout << "Thu vien sau khi xoa sach cua tac gia " << name << ":" << endl;
					l.Xuat();
					data.LoadBook(l);
				}
				else
					cout << "Khong tim thay tac gia" << endl;
			}
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
void Admin::XoaSachCuaNXB(DanhSach& l)
{
	int op;
	while (true)
	{
		cout << "Nhap 1 de xoa, 0 de thoat: ";
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
				cout << "Nhap ten Nha Xuat Ban can xoa: ";
				cin.ignore();
				getline(cin, name);
				if (l.XoaSachTheoTacGia(name))
				{
					cout << "Thu vien sau khi xoa sach cua nha xuat ban "<<name << ":" << endl;
					l.Xuat();
					data.LoadBook(l);
				}
				else 
					cout << "Khong tim thay NXB" << endl;
			}
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
void Admin::XoaAccount(int op1)
{
	switch (op1)
	{
	case 1:
	{
		while (true)
		{
			int op;
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op;
			switch (op)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa(co dang TG-Ten Tac Gia): ";
				cin.ignore();
				getline(cin, name);
				if (name.substr(0, 3) != "TG-")
					cout << "Ten tai khoan khong hop le!!!" << endl;
				else if (!data.DeleteAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					data.LoadAccount();
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	case 2:
	{

		while (true)
		{
			int op;
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op;
			switch (op)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa(co dang NXB-Ten Nha Xuat Ban): ";
				cin.ignore();
				getline(cin, name);
				if (name.substr(0, 4) != "NXB-")
					cout << "Ten tai khoan khong hop le!!!" << endl;
				else if (!data.DeleteAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					data.LoadAccount();
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	case 3:
	{
		while (true)
		{
			int op;
			cout << "Nhap 1 de xoa,0 de thoat:";
			cin >> op;
			switch (op)
			{
			case 0:
			{

			}
			break;
			case 1:
			{
				string name;
				cout << "Nhap ten tai khoan can xoa: ";
				cin.ignore();
				getline(cin, name);
				if (!data.DeleteAccount(name))
					cout << "Tai khoan khong ton tai!!!" << endl;
				else
				{
					data.LoadAccount();
					cout << "Xoa thanh cong!!!" << endl;
				}
			}
			break;
			default:
				cout << "Lua chon khong hop le!!!" << endl;
				break;
			}
			if (op == 0)
			{
				system("CLS");
				break;
			}
		}
	}
	break;
	default:
		break;
	}
}