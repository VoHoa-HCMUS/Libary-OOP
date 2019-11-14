#include "Guest.h"
void Guest::TimSach(DanhSach l)
{
	while (true)
	{
		int op;
		cout << "Nhap 1 de bat dau tim, 0 de thoat: ";
		cin >> op;
		switch (op)
		{
		case 0:
			break;
		case 1:
		{
			string s;
			cout << "Nhap ten sach can tim: ";
			cin.ignore();
			getline(cin, s);
			if (l.Count(s) == 0)
			{
				cout << "Khong tim thay sach." << endl;
			}
			if (l.Count(s) == 1)
			{
				cout << "Tim thay 1 cuon " << s << ":" << endl;
				l.TimSachTheoTen(s);
			}
			else
			{
				string id;
				cout << "Tim thay " << l.Count(s) << " cuon " << s << ":" << endl;
				l.XuatSachTrung(s);
				cout << "Nhap ma sach can tim: ";
				getline(cin, id);
				bool check = true;
				l.TimSachTheoMa(id,check);
				if (check == false)
					cout << "Khong tim thay cuon " << s << " co ma " << id << endl;
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
//void Guest::SetDataBase(DanhSach& l)
//{
//	data.LoadDeletedAu();
//}




