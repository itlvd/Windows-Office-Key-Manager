#include"function.h"


int main() {
	resizeConsole(1200, 600);
	FixConsoleWindow();
	SetConsoleTitleA("Windows-Office Key Manager - Le Van Dong (levandong.com)");
	
	ListKey key;
	key.readFile();

	HOME:
	screenWelcome();
	int x = selectionOfWelcome();

	if (x == 0) {
		ADDKEY:
		system("cls");
		
		string keytext;
		string type;
		string subtype;
		string status;
		do {
			cout << "Nhap key: ";
			getline(cin, keytext);

			if (Key::checkValidTextKey(keytext)) break;
			else {
				cout << "Nhap sai vui long nhap lai!\n";
			}

		} while (true);

		system("cls");
		screenRetailOrVL();
		int itype = selectionOfRetailOrVl();
		if (itype == 0 || itype == 2) {// Retail
			type = "Retail";
		}
		else {
			type = "Volume";
		}

		system("cls");
		if (itype == 0 || itype == 1) { // Windows 
			screenWindows();
			switch (selectionOfWindows())
			{
			case 0:
				subtype = "Win10 Pro";
				break;
			case 1:
				subtype = "Win10 Edu";
				break;
			case 2:
				subtype = "Win10 Enterprise";
				break;
			case 3:
				subtype = "Win10 Workstation";
				break;
			case 4: 
				subtype = "LTSC";
				break;
			case 5:
				subtype = "LTSB";
				break;
			case 6:
				do {
					cout << "Nhap loai key windows:(Win8 Pro, Win8 Edu,...)(Duoi 25 ky tu): \n";
					getline(cin, subtype);
					if (subtype.length() < 25) break;
				} while (true);
				break;
			default:
				break;
			}

		}
		else {
			screenOffice();
			switch (selectionOfOffice())
			{
			case 0:
				subtype = "ProPlus2019";
				break;
			case 1:
				subtype = "Pro2019";
				break;
			case 2:
				subtype = "HomeAndBusiness2019";
				break;
			case 3:
				subtype = "StudentAndStudent2019";
				break;
			case 4:
				subtype = "VisioPro2019";
				break;
			case 5:
				subtype = "ProjectPro2019";
				break;
			case 10:
				subtype = "ProPlus2016";
				break;
			case 11:
				subtype = "Pro2016";
				break;
			case 12:
				subtype = "HomeAndBusiness2016";
				break;
			case 13:
				subtype = "HomeAndStudent2016";
				break;
			case 14:
				subtype = "VisioPro2016";
				break;
			case 15:
				subtype = "ProjectPro2016";
				break;
			case 16:
				do {
					cout << "Nhap loai key office:(Pro2010, Project 2010,...)(Duoi 25 ky tu): \n";
					getline(cin, subtype);
					if (subtype.length() < 25) break;
				} while (true);
				break;
			default:
				break;
			}
		}
		system("cls");
		cout << "Nhap status cua key (Online, get web, by phone): \n";
		getline(cin, status);
		key.add(type, keytext, status, subtype);
		system("cls");
		key.printListKey();
		gotoxy(130, 5);
		cout << "Home(h)";
		gotoxy(130, 6);
		cout << "Add(a)";
		gotoxy(130, 7);
		cout << "Edit Status(e)";
		gotoxy(130, 8);
		cout << "Delete Key(d)";
		gotoxy(130, 9);
		cout << "Save, Exit(s)";
		while (true) {
			char c = _getch();
			if (c == 'H' || c == 'h') goto HOME;
			else if (c == 'S' || c == 's') break;
			else if (c == 'A' || c == 'a') goto ADDKEY;
			else if (c == 'E' || c == 'e') {
				int index;
				do {
					gotoxy(70, 2);
					cout << "Nhap STT key:";
					cin >> index;
					if (index > 0 && index <= key.size()); break;
				} while (true);
				gotoxy(70, 2);
				cout << "Nhap Status thay doi:";
				string temp;
				getline(cin, temp);
				getline(cin, temp);
				key.editStatus(index, temp);
				goto PRINTLISTKEY;
			}
			else if (c == 'D' || c == 'd') {
				gotoxy(70, 2);
				cout << "Nhap STT key de xoa:      ";
				int index;
				cin >> index;
				key.del(index);
				goto PRINTLISTKEY;
			}
			else {
				continue;
			}
		}
	}
	else if (x == 1) {
	PRINTLISTKEY:
		system("cls");
		key.printListKey();
		gotoxy(130, 5);
		cout << "Home(h)";
		gotoxy(130, 6);
		cout << "Add(a)";
		gotoxy(130, 7);
		cout << "Edit Status(e)";
		gotoxy(130, 8);
		cout << "Delete Key(d)";
		gotoxy(130, 9);
		cout << "Save, Exit(s)";
		while (true) {
			char c = _getch();
			if (c == 'H' || c == 'h') goto HOME;
			else if (c == 'S' || c == 's') break;
			else if (c == 'A' || c == 'a') goto ADDKEY;
			else if (c == 'E' || c == 'e') {
				int index;
				do {
					gotoxy(70, 2);
					cout << "Nhap STT key:";
					cin >> index;
					if (index > 0 && index <= key.size()); break;
				} while (true);
				gotoxy(70, 2);
				cout << "Nhap Status thay doi:";
				string temp;
				getline(cin, temp);
				getline(cin, temp);
				key.editStatus(index, temp);
				goto PRINTLISTKEY;
			}
			else if (c == 'D' || c == 'd') {
				gotoxy(70, 2);
				cout << "Nhap STT key de xoa:      ";
				int index;
				cin >> index;
				key.del(index);
				goto PRINTLISTKEY;
			}
			else {
				continue;
			}
		}

	}

	key.outFile();
	key.clear();
	gotoxy(0, 25);
	return 0;
}