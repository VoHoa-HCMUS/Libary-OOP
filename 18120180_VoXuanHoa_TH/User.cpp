#include "User.h"
void User::MuaSach(DanhSach l)
{
	int m = 0;
	int op1;
	while (true)
	{
		cout << "Nhap 1 de mua, 0 de thoat:";
		cin >> op1;
		switch (op1)
		{
		case 0:
			break;
		case 1:
		{
			string name;
			int num;
			cout << "Nhap ten sach can mua: ";
			cin.ignore();
			getline(cin, name);
			if (l.Count(name) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			else if (l.Count(name) == 1)
			{
				cout << "Nhap so luong can mua: ";
				cin >> num;
				h[m].SetSoLuong(num);
				h[m].AddSach(l.GetSachTheoTen(name), m);
			}
			else
			{
				cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
				l.TimSachTheoTen(name);
				string ma;
				cout << "Nhap ma sach can mua: ";
				getline(cin, ma);
				cout << "Nhap so luong can mua: ";
				cin >> num;
				h[m].SetSoLuong(num);
				h[m].AddSach(l.GetSachTheoMa(ma), m);
			}
		}
		break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		if (op1 == 0)
			break;
	}
	if (m)
	{
		string id;
		cout << "Ban da mua:" << endl;
		h->XuatHoaDon(h, m);
		cout << "Tong tien: " << h->TinhTien(h, m);
		int op2;
		cout << endl;
		while (true)
		{
			cout << "Nhap 1 de xoa sach, 2 de thay doi so luong sach, 3 de them sach, 0 de in hoa don: ";
			cin >> op2;
			switch (op2)
			{
			case 0:
			{
				if (h->KiemTraHoaDonRong(h, m))
					cout << "Ban chua mua gi ca!" << endl;
				else
				{
					cout << "Hoa don cua ban: " << endl;
					h->XuatHoaDon(h, m);
					cout << "Tong tien phai tra: " << h->TinhTien(h, m) << endl;
					time_t hientai = time(0);
					string ThoiGianMua = ctime(&hientai);
					cout << "Thoi gian mua: " << ThoiGianMua;
				}
			}
			break;
			case 1:
			{
				CapNhatHoaDon(l,m,op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				h->XuatHoaDon(h, m);
				cout << "Tong tien: " << h->TinhTien(h, m);
				cout << endl;
			}
			break;
			case 2:
			{
				CapNhatHoaDon(l,m,op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				h->XuatHoaDon(h, m);
				cout << "Tong tien: " << h->TinhTien(h, m);
				cout << endl;
			}
			break;
			case 3:
			{
				CapNhatHoaDon(l,m,op2);
				cout << "Hoa don sau khi cap nhat:" << endl;
				h->XuatHoaDon(h, m);
				cout << "Tong tien: " << h->TinhTien(h, m);
				cout << endl;
			}
			break;
			default:
				cout << "Lua chon khong hop le!" << endl;
			break;
			}
			if (op2 == 0)
				break;
		}
	}
}
void User::CapNhatHoaDon(DanhSach l,int &m, int type)
{
	switch (type)
	{
	case 1:
	{
		string id;
		cout << "Nhap ma sach can xoa:";
		cin.ignore();
		getline(cin, id);
		h->XoaSach(h, m, id);
	}
	break;
	case 2:
	{
		if (h->KiemTraHoaDonRong(h, m))
			cout << "Ban chua mua gi ca!" << endl;
		{
			string id;
			cout << "Nhap ma sach thay doi:";
			cin.ignore();
			getline(cin, id);
			if (!h->KiemTraSachThuocHoaDon(h, m, id))
				cout << "Khong co cuon nao co ma " << id << " trong hoa don!" << endl;
			else
			{
				int newnum;
				cout << "Nhap so luong moi: ";
				cin >> newnum;
				for (int i = 0; i < m; i++)
				{
					if (h[i].GetSach().GetMa() == id)
					{
						h[i].SetSoLuong(newnum);
						break;
					}
				}
			}
		}
	}
	break;
	case 3:
	{
		string name;
		int num;
		cout << "Nhap ten sach can them: ";
		cin.ignore();
		getline(cin, name);
		if (l.Count(name) == 0)
		{
			cout << "Khong tim thay sach." << endl;
		}
		else if (l.Count(name) == 1)
		{
			cout << "Nhap so luong can mua: ";
			cin >> num;
			h[m].SetSoLuong(num);
			h[m].AddSach(l.GetSachTheoTen(name), m);
		}
		else
		{
			cout << "Tim thay " << l.Count(name) << " cuon " << name << ":" << endl;
			l.TimSachTheoTen(name);
			string ma;
			cout << "Nhap ma sach can them: ";
			getline(cin, ma);
			cout << "Nhap so luong can mua: ";
			cin >> num;
			h[m].SetSoLuong(num);
			h[m].AddSach(l.GetSachTheoMa(ma), m);
		}
	}
	break;
	default:
		break;
	}
}
void User::DangNhap(int &op)
{
	data.LoadDataBase();
	while (true)
	{
		try
		{
			cout << "Nhap 1 de dang nhap,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw 0;
			if (op == 0)
				break;
			cout << "Nhap ten dang nhap: ";
			cin.ignore();
			getline(cin, accountname);
			if (accountname.substr(0, 3) == "TG-")
				throw 1;
			if (accountname.substr(0, 4) == "NXB-")
				throw 2;
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (data.CheckAccount(accountname, password) == 1)
				break;
			else if (data.CheckAccount(accountname, password) == 0)
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
			else if (x == 1)
				cout << "Tai khoan chi danh cho Tac Gia!!!" << endl;
			else if(x==2)
				cout << "Tai khoan chi danh cho Nha Xuat Ban!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}
void User::DangKi()
{
	data.LoadDataBase();
	cout << "Luu y !!!: Ten tai khoan va mat khau khong duoc chua ki tu dac biet." << endl;
	while (true)
	{
		try
		{
			int op;
			cout << "Nhap 1 de dang ki,0 de thoat: ";
			cin >> op;
			if (op != 1 && op != 0)
				throw -2;
			if (op == 0)
			{
				system("CLS");
				break;
			}
			cout << "Nhap ten tai khoan: ";
			cin.ignore();
			getline(cin, accountname);
			if (accountname.substr(0, 3) == "TG-")
				throw 1;
			if (accountname.substr(0, 4) == "NXB-")
				throw 2;
			if (accountname.substr(0, 3) == "AD-")
				throw 3;
			cout << "Nhap mat khau: ";
			getline(cin, password);
			if (data.CheckValidRegister(accountname, password) == -1)
				throw -1;
			else if (data.CheckValidRegister(accountname, password) == 0||data.CheckValidRegister(accountname,password)==2)
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
		catch (int x)
		{
			if (x == -1)
				cout << "Ten nguoi dung da ton tai,vui long chon ten khac!!!" << endl;
			else if (x == 1)
				cout << "Ten tai khoan chi danh rieng cho Tac Gia, vui long chon ten khac!!!" << endl;
			else if (x == 2)
				cout << "Ten tai khoan chi danh rieng cho Nha Xuat Ban, vui long chon ten khac!!!" << endl;
			else if (x == 0)
				cout << "Ten tai khoan hoac mat khau khong hop le!!!" << endl;
			else if (x == 3)
				cout << "Ten tai khoan chi danh rieng cho Admin, vui long chon ten khac!!!" << endl;
			else
				cout << "Lua chon khong hop le!!!" << endl;
		}
	}
}