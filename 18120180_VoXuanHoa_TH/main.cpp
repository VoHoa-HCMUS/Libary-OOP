#include"Admin.h"
#include"DataBase.h"
void main()
{
	ifstream* filein;
	filein = new ifstream;
	filein->open("books.txt");
	DanhSach l;
	int op;
	l.Nhap(filein);
	filein->close();
	Guest* u = new User;
	Guest* ad = new Admin;
	Guest* p = new Publisher;
	Guest* au = new Author;
	while (true)
	{
	loop:cout << "Chao mung den voi thu vien!" << endl;
		cout << "0.Exit." << endl;
		cout << "1.Dang ki." << endl;
		cout << "2.Dang nhap." << endl;
		cout << "3.Dang nhap voi tai khoan khach." << endl;
		cout << "Nhap lua chon: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
		}
		break;
		case 1:
		{
			system("CLS");
			while (true)
			{
			loop2:cout << "Chon loai tai khoan:" << endl;
				cout << "0.Exit" << endl;
				cout << "1.User." << endl;
				cout << "2.Nha xuat ban." << endl;
				cout << "3.Tac gia." << endl;
				cout << "Nhap lua chon: ";
				int op1;
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				case 1:
				{
					system("CLS");;
					u->DangKi();
					goto loop;
				}
				break;
				case 2:
				{
					system("CLS");
					p->DangKi();
					goto loop;
				}
				break;
				case 3:
				{
					system("CLS");

					au->DangKi();
					goto loop;
				}
				break;
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		case 2:
		{
			system("CLS");
			while (true)
			{
			loop1:cout << "Ban la:" << endl;
				cout << "0.Exit" << endl;
				cout << "1.User." << endl;
				cout << "2.Admin." << endl;
				cout << "3.Nha xuat ban." << endl;
				cout << "4.Tac gia." << endl;
				cout << "Nhap lua chon: ";
				int op1;
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				break;
				case 1:
				{
					system("CLS");
					int op3;
					u->DangNhap(op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					system("CLS");
					while (true)
					{
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Mua sach" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							l.Xuat();
						}
						break;
						case 2:
						{
							system("CLS");
							u->TimSach(l);
						}
						break;
						case 3:
						{
							system("CLS");
							u->MuaSach(l);
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							system("CLS");
							break;
						}
					}
				}
				break;
				case 2:
				{
					system("CLS");
					int op3;
					ad->DangNhap(op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					loop4:system("CLS");
					while (true)
					{
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Mua sach" << endl;
						cout << "4.Them sach" << endl;
						cout << "5.Xoa sach" << endl;
						cout << "6.Sua sach" << endl;
						cout << "7.Xoa tai khoan" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							l.Xuat();
						}
						break;
						case 2:
						{
							system("CLS");
							ad->TimSach(l);
						}
						break;
						case 3:
						{
							system("CLS");
							ad->MuaSach(l);
						}
						break;
						case 4:
						{
							system("CLS");
							ad->ThemSach(l);
						}
						break;
						case 5:
						{
							loop3:system("CLS");
							while (true)
							{
								int op;
								cout << "Menu:" << endl;
								cout << "0.Exit" << endl;
								cout << "1.Xoa sach cua tac gia" << endl;
								cout << "2.Xoa sach cua nha xuat ban" << endl;
								cout << "3.Xoa sach bat ki" << endl;
								cout << "Nhap lua chon: ";
								cin >> op;
								switch (op)
								{
								case 1:
								{
									system("CLS");
									ad->XoaSachCuaTacGia(l);
								}
								break;
								case 2:
								{
									system("CLS");
									ad->XoaSachCuaNXB(l);
								}
								break;
								case 3:
								{
									system("CLS");
									ad->XoaSach(l);
								}
								break;
								default:
									cout << "Lua chon khong hop le!!!";
									Sleep(500);
									goto loop3;
								}
								if (op == 0)
								{
									goto loop4;
								}
							}
							if (op == 0)
							{
								goto loop4;
							}
						}
						break;
						case 6:
						{
							system("CLS");
							l.Xuat();
							ad->SuaSach(l);
						}
						break;
						case 7:
						{
						loop5:system("CLS");
							while (true)
							{
								int op;
								cout << "Menu:" << endl;
								cout << "0.Exit" << endl;
								cout << "1.Xoa tai khoan cua tac gia" << endl;
								cout << "2.Xoa tai khoan cua nha xuat ban" << endl;
								cout << "3.Xoa tai khoan cua user" << endl;
								cout << "Nhap lua chon: ";
								cin >> op;
								switch (op)
								{
								case 0:
									break;
								case 1:
								case 2:
								case 3:
								{
									system("CLS");
									ad->XoaAccount(op);
								}
								break;
								default:
									cout << "Lua chon khong hop le!!!" << endl;
									Sleep(500);
									goto loop5;
								}
							}
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							goto loop4;
						}
					}
				}
				break;
				case 3:
				{
					system("CLS");
					int op3;
					p->DangNhap(op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					p->SetSLSach(l);
					system("CLS");
					while (true)
					{
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Them sach" << endl;
						cout << "4.Xoa sach" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							cout << "So luong sach cua ban trong thu vien la: " << p->GetSLSach() << endl;
							l.Xuat();
						}
						break;
						case 2:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << p->GetSLSach() << endl;
							p->TimSach(l);
						}
						break;
						case 3:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << p->GetSLSach() << endl;
							p->ThemSach(l);
						}
						break;
						case 4:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << p->GetSLSach() << endl;
							l.Xuat();
							p->XoaSach(l);
						}
						break;
						case 5:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << p->GetSLSach() << endl;
							l.Xuat();
							p->SuaSach(l);
						}
						break;
						default:
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							system("CLS");
							break;
						}
					}

				}
				break;
				case 4:
				{
					system("CLS");
					int op3;
					au->DangNhap(op3);
					if (op3 == 0)
					{
						system("CLS");
						goto loop1;
					}
					system("CLS");
					while (true)
					{
						au->SetSLSach(l);
						cout << "0.Dang xuat" << endl;
						cout << "1.In tat ca cac sach" << endl;
						cout << "2.Tim sach" << endl;
						cout << "3.Them sach" << endl;
						cout << "4.Xoa sach" << endl;
						cout << "5.Sua sach" << endl;
						int op2;
						cout << "Nhap lua chon: ";
						cin.clear();
						cin >> op2;
						switch (op2)
						{
						case 0:
						{
							system("CLS");
							goto loop1;
						}
						break;
						case 1:
						{
							cout << "So luong sach cua ban trong thu vien la: " << au->GetSLSach() << endl;
							l.Xuat();
						}
						break;
						case 2:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << au->GetSLSach() << endl;
							au->TimSach(l);
						}
						break;
						case 3:
						{
							system("CLS");
							cout << "So luong sach cua ban trong thu vien la: " << au->GetSLSach() << endl;
							au->ThemSach(l);
						}
						break;
						case 4:
						{
							system("CLS");
							l.Xuat();
							cout << "So luong sach cua ban trong thu vien la: " << au->GetSLSach() << endl;
							au->XoaSach(l);
						}
						break;
						case 5:
						{
							system("CLS");
							l.Xuat();
							cout << "So luong sach cua ban trong thu vien la: " << au->GetSLSach() << endl;
							au->SuaSach(l);
						}
						break;
						default:
							system("CLS");
							cout << "Lua chon ko hop le!" << endl;
							Sleep(500);
							break;
						}
					}
				}
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		break;
		case 3:
		{
			system("CLS");
			while (true)
			{
				Guest* g = new Guest;
				cout << "0.Exit" << endl;
				cout << "1.In tat ca cac sach" << endl;
				cout << "2.Tim sach" << endl;
				int op1;
				cout << "Nhap lua chon: ";
				cin.clear();
				cin >> op1;
				switch (op1)
				{
				case 0:
				{
					system("CLS");
					goto loop;
				}
				break;
				case 1:
				{
					l.Xuat();
				}
				break;
				case 2:
				{
					system("CLS");
					g->TimSach(l);
				}
				break;
				default:
					cout << "Lua chon ko hop le!" << endl;
					Sleep(500);
					system("CLS");
					break;
				}
			}
		}
		break;
		default:
			cout << "Lua chon ko hop le!" << endl;
			Sleep(500);
			system("CLS");
			break;
		}
		if (op == 0)
			break;
	}
}