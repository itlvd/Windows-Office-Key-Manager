#include"function.h"


int main() {
	resizeConsole(1200, 600);
	FixConsoleWindow();
	SetConsoleTitleA("Windows-Office Key Manager - Le Van Dong (levandong.com)");
	
	ListKey key;
	key.readFile();

HOME:
	system("cls");
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
			gotoxy(50, 7);
			cout << "Input your key: ";
			getline(cin, keytext);
			system("cls");
			if (Key::checkValidTextKey(keytext)) break;
			else {
				gotoxy(50, 8);
				cout << "Something went wrong! Please try again!";
			}

		} while (true);

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
				system("cls");
				do {
					gotoxy(40, 7);
					cout << "Input version of Windows:(Win8 Pro, Win8 Edu,...)(Under 25 characters):";
					gotoxy(40, 8);
					getline(cin, subtype);
					system("cls");
					if (subtype.length() < 25) break;
					gotoxy(40, 6);
					cout << "Something went wrong! Please try again!";
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
				system("cls");
				do {
					gotoxy(40, 7);
					cout << "Input version Office:(Office2010Pro, Office2010Project,...)(Under 25 characters):";
					gotoxy(40, 8);
					getline(cin, subtype);
					system("cls");
					if (subtype.length() < 25) break;
					gotoxy(40, 6);
					cout << "Something went wrong! Please try again!";
				} while (true);
				break;
				break;
			default:
				break;
			}
		}

		system("cls");

		screenStatus(65);

		switch (selectionOfStatus(65))
		{
		case 0:
			status = "Online";
			break;
		case 1:
			status = "Get Web";
			break;
		case 2:
			status = "By Phone";
			break;
		case 3: 
			status = "Block";
			break;
		case 4:
			system("cls");
			do
			{
				gotoxy(50, 7);
				cout << "Status: ";
				getline(cin, status);
				system("cls");
				if (status.length() < 12) break;
				else {
					gotoxy(50, 8);
					cout << "Something went wrong! Please try again!\n";
				}
			} while (true);
		default:
			break;
		}


		key.add(type, keytext, status, subtype);
		goto PRINTLISTKEY;
		
	}
	else if (x == 1) {
	PRINTLISTKEY:
		system("cls");
		key.printListKey();
		screenMenu();

		switch (selectionOfMenu())
		{
		case 0: // back to home
			goto HOME;
			break;
		case 1: // add new key
			cin.ignore();
			goto ADDKEY;
			break;
		case 2:
			cin.ignore();
			goto QUICKADD;
			break;
		case 3: { // edit status
			int index;
			do {
				gotoxy(70, 2);
				cout << "               ";
				gotoxy(70, 2);
				cout << "Input ID: ";
				cin >> index;
				if (index > 0 && index <= key.size()) break;
				gotoxy(70, 1);
				cout << "Something went wrong! Please try again!";
			} while (true);

			screenStatus(130);
			string status_edit;
			switch (selectionOfStatus(130))
			{
			case 0:
				status_edit = "Online";
				break;
			case 1:
				status_edit = "Get Web";
				break;
			case 2:
				status_edit = "By Phone";
				break;
			case 3:
				status_edit = "Block";
				break;
			case 4:
				do
				{
					gotoxy(70, 1);
					cout << "                                           ";
					gotoxy(70, 2);
					cout << "                  ";
					gotoxy(70, 2);
					cout << "Status: ";
					getline(cin, status_edit);
					getline(cin, status_edit);
					if (status_edit.length() < 12) break;
					else {
						gotoxy(70, 3);
						cout << "Something went wrong! Please try again.\n";
					}
				} while (true);
			default:
				break;
			}

			key.editStatus(index, status_edit);
			goto PRINTLISTKEY;
			break;
		}
		case 4:
			int index;
			do {
				gotoxy(70, 2);
				cout << "               ";
				gotoxy(70, 2);
				cout << "Input ID: ";
				cin >> index;
				if (index > 0 && index <= key.size()) break;
				gotoxy(70, 1);
				cout << "Something went wrong! Please try again!";
			} while (true);
			key.del(index);
			goto PRINTLISTKEY;
		default:
			break;
		}

	}
	else if (x == 2) {
	QUICKADD:
	system("cls");
	gotoxy(45, 1);
	cout << "Please right-click then Enter. Format like khoatoantin.com/pidms";
	gotoxy(0, 2);
	string str_temp = wiring();
	Key* key_temp = parse(str_temp);
	key.push_back(key_temp);
	goto PRINTLISTKEY;
	}

	key.outFile();
	key.clear();
	gotoxy(0, 25);
	return 0;
}