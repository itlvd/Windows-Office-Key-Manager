#include"screen.h"

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void gotoxy1(short x, short y)
{
	system("cls");
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SelectionInScreenWelcome(int selection) {
	switch (selection)
	{
	case 0:
		gotoxy(66 ,9);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Add Key";
		break;
	case 1:
		gotoxy(63, 10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Show List Key";
		break;
	default:
		break;
	}
}

void restoreColorInScreenWelcome(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	switch (selection)
	{
	case 0:
		gotoxy(66, 9);
		cout << "Add Key";
		break;
	case 1:
		gotoxy(63, 10);
		cout << "Show List Key";
		break;
	default:
		break;
	}
}

void screenWelcome() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	int x = 55;
	gotoxy1(x, 1);
	cout << "VNKOWTOX OFFICE KEY MANAGER";
	Sleep(100);
	gotoxy1(x + 4, 2);
	cout << "Author: Le Van Dong";
	Sleep(100);
	gotoxy1(x + 7, 3);
	cout << "Version: 1.0";
	Sleep(100);
	gotoxy1(x + 2, 4);
	cout << "**Developer with love**";
	Sleep(100);


	gotoxy(x, 1);
	cout << "VNKOWTOX OFFICE KEY MANAGER";
	gotoxy(x + 4, 2);
	cout << "Author: Le Van Dong";
	gotoxy(x + 7, 3);
	cout << "Version: 1.1";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	int x1 = 45;
	gotoxy(x1, 7);
	cout << "===============================================\n";
	gotoxy(x1, 8);
	cout << char(92) << char(92) << "                                           //\n";
	gotoxy(x1 + 1, 9);
	cout << char(92) << char(92) << "                                         //\n";
	gotoxy(x1 + 2, 10);
	cout << char(92) << char(92) << "                                       //\n";
	gotoxy(x1 + 3, 11);
	cout << char(92) << char(92) << "                                     //\n";
	/*gotoxy(x1 + 4, 12);
	cout << char(92) << char(92) << "                                   //\n";
	gotoxy(x1 + 5, 13);
	cout << char(92) << char(92) << "                                 //\n";*/
	/*gotoxy(x1 + 6, 14);
	cout << char(92) << char(92) << "                               //\n";
	gotoxy(x1 + 7, 15);
	cout << char(92) << char(92) << "                             //\n";
	gotoxy(x1 + 8, 16);
	cout << char(92) << char(92) << "                           //\n";
	gotoxy(x1 + 9, 17);
	cout << char(92) << char(92) << "                         //\n";
	gotoxy(x1 + 10, 18);
	cout << char(92) << char(92) << "                       //\n";*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(x1 + 21, 9);
	cout << "Add Key";
	gotoxy(x1 + 18, 10);
	cout << "Show List Key";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}

int selectionOfWelcome() {
	SelectionInScreenWelcome(0); // Moi vo thi chon cai 1
	char c; // selection
	int now = 0;
	while (true) {
		c = _getch();
		if (c == '\r') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
			return now;
		}
		else if (c == 72) { // Turn up
			restoreColorInScreenWelcome(now);
			now--;
		}
		else if (c == 80) { // Turn down
			restoreColorInScreenWelcome(now);
			now++;
		}
		if (now < 0) {
			now = numselectWelcome - 1;
		}
		else if (now > numselectWelcome - 1) {
			now = 0;
		}
		SelectionInScreenWelcome(now);
	}
	
}

void screenRetailOrVL() {
	gotoxy(64, 1);
	cout << "Retail Or Volume?";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoxy(66, 9);
	cout << "Windows Retail";
	gotoxy(66, 10);
	cout << "Windows Volume";
	gotoxy(66, 11);
	cout << "Office Retail";
	gotoxy(66, 12);
	cout << "Office Volume";
}

void selectionInScreenRetailOrVL(int selection) {
	switch (selection)
	{
	case 0:
		gotoxy(66, 9);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Windows Retail";
		break;
	case 1:
		gotoxy(66, 10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Windows Volume";
		break;
	case 2:
		gotoxy(66, 11);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Office Retail";
		break;
	case 3:
		gotoxy(66, 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Office Volume";
		break;
	default:
		break;
	}
}

void restoreColorInScreenRetailOrVL(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	switch (selection)
	{
	case 0:
		gotoxy(66, 9);
		cout << "Windows Retail";
		break;
	case 1:
		gotoxy(66, 10);
		cout << "Windows Volume";
		break;
	case 2:
		gotoxy(66, 11);
		cout << "Office Retail";
		break;
	case 3:
		gotoxy(66, 12);
		cout << "Office Volume";
		break;
	default:
		break;
	}
}

int selectionOfRetailOrVl() {
	selectionInScreenRetailOrVL(0); // Moi vo thi chon cai 1
	char c; // selection
	int now = 0;
	while (true) {
		c = _getch();
		if (c == '\r') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			return now;
		}
		else if (c == 72) { // Turn up
			restoreColorInScreenRetailOrVL(now);
			now--;
		}
		else if (c == 80) { // Turn down
			restoreColorInScreenRetailOrVL(now);
			now++;
		}
		if (now < 0) {
			now = 4 - 1;
		}
		else if (now > 4 - 1) {
			now = 0;
		}
		selectionInScreenRetailOrVL(now);
	}
}

void screenWindows() {
	int x = 70;
	gotoxy(x, 1);
	cout << "Version of Windows 10";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	gotoxy(x, 7);
	cout << "Windows 10 Pro";
	gotoxy(x, 8);
	cout << "Windows 10 Education";
	gotoxy(x, 9);
	cout << "Windows 10 Enterprise";
	gotoxy(x, 10);
	cout << "Windows 10 Workstation";
	gotoxy(x, 11);
	cout << "Windows 10 LTSC";
	gotoxy(x, 12);
	cout << "Windows 10 LTSB 2016";
	gotoxy(x, 13);
	cout << "Khac";
}

void selectionInWindowsScreen(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	switch (selection)
	{
	case 0:
		gotoxy(70, 7);
		cout << "Windows 10 Pro";
		break;
	case 1:
		gotoxy(70, 8);
		cout << "Windows 10 Education";
		break;
	case 2:
		gotoxy(70, 9);
		cout << "Windows 10 Enterprise";
		break;
	case 3:
		gotoxy(70, 10);
		cout << "Windows 10 Workstation";
		break;
	case 4:
		gotoxy(70, 11);
		cout << "Windows 10 LTSC";
		break;
	case 5:
		gotoxy(70, 12);
		cout << "Windows 10 LTSB 2016";
		break;
	case 6:
		gotoxy(70, 13);
		cout << "Khac";
		break;
	default:
		break;
	}
}

void restoreColorInWindowsScreen(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	switch (selection)
	{
	case 0:
		gotoxy(70, 7);
		cout << "Windows 10 Pro";
		break;
	case 1:
		gotoxy(70, 8);
		cout << "Windows 10 Education";
		break;
	case 2:
		gotoxy(70, 9);
		cout << "Windows 10 Enterprise";
		break;
	case 3:
		gotoxy(70, 10);
		cout << "Windows 10 Workstation";
		break;
	case 4:
		gotoxy(70, 11);
		cout << "Windows 10 LTSC";
		break;
	case 5:
		gotoxy(70, 12);
		cout << "Windows 10 LTSB 2016";
		break;
	case 6:
		gotoxy(70, 13);
		cout << "Khac";
		break;
	default:
		break;
	}
}

int selectionOfWindows() {
	selectionInWindowsScreen(0); // Moi vo thi chon cai 1
	char c; // selection
	int now = 0;
	while (true) {
		c = _getch();
		if (c == '\r') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			return now;
		}
		else if (c == 72) { // Turn up
			restoreColorInWindowsScreen(now);
			now--;
		}
		else if (c == 80) { // Turn down
			restoreColorInWindowsScreen(now);
			now++;
		}
		if (now < 0) {
			now = 6;
		}
		else if (now > 6) {
			now = 0;
		}
		selectionInWindowsScreen(now);
	}
}

void screenOffice() {
	int x = 65;
	gotoxy(x, 1);
	cout << "Version of Office";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	gotoxy(x - 10, 7);
	cout << "ProPlus2019";
	gotoxy(x - 10, 8);
	cout << "Pro2019";
	gotoxy(x - 10, 9);
	cout << "HomeAndBusiness2019";
	gotoxy(x - 10, 10);
	cout << "HomeAndStudent2019";
	gotoxy(x - 10, 11);
	cout << "VisioPro2019";
	gotoxy(x - 10, 12);
	cout << "ProjectPro2019";

	gotoxy(x + 22, 7);
	cout << "ProPlus2016";
	gotoxy(x + 22, 8);
	cout << "Pro2016";
	gotoxy(x + 22, 9);
	cout << "HomeAndBusiness2016";
	gotoxy(x + 22, 10);
	cout << "HomeAndStudent2016";
	gotoxy(x + 22, 11);
	cout << "VisioPro2016";
	gotoxy(x + 22, 12);
	cout << "ProjectPro2016";
	gotoxy(x + 10, 14);
	cout << "Khac";
}

/*1-5 2019 10-15 2016 => easy calculator*/
void selectionInOfficeScreen(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	switch (selection)
	{
	case 0:
		gotoxy(55, 7);
		cout << "ProPlus2019";
		break;
	case 1:
		gotoxy(55, 8);
		cout << "Pro2019";
		break;
	case 2:
		gotoxy(55, 9);
		cout << "HomeAndBusiness2019";
		break;
	case 3:
		gotoxy(55, 10);
		cout << "HomeAndStudent2019";
		break;
	case 4:
		gotoxy(55, 11);
		cout << "VisioPro2019";
		break;
	case 5:
		gotoxy(55, 12);
		cout << "ProjectPro2019";
		break;
	case 10:
		gotoxy(87, 7);
		cout << "ProPlus2016";
		break;
	case 11:
		gotoxy(87, 8);
		cout << "Pro2016";
		break;
	case 12:
		gotoxy(87, 9);
		cout << "HomeAndBusiness2016";
		break;
	case 13:
		gotoxy(87, 10);
		cout << "HomeAndStudent2016";
		break;
	case 14:
		gotoxy(87, 11);
		cout << "VisioPro2016";
		break;
	case 15:
		gotoxy(87, 12);
		cout << "ProjectPro2016";
		break;
	case 16:
		gotoxy(75, 14);
		cout << "Khac";
		break;

	default:
		break;
	}
}

void restoreColorInOfficeScreen(int selection) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	switch (selection)
	{
	case 0:
		gotoxy(55, 7);
		cout << "ProPlus2019";
		break;
	case 1:
		gotoxy(55, 8);
		cout << "Pro2019";
		break;
	case 2:
		gotoxy(55, 9);
		cout << "HomeAndBusiness2019";
		break;
	case 3:
		gotoxy(55, 10);
		cout << "HomeAndStudent2019";
		break;
	case 4:
		gotoxy(55, 11);
		cout << "VisioPro2019";
		break;
	case 5:
		gotoxy(55, 12);
		cout << "ProjectPro2019";
		break;
	case 10:
		gotoxy(87, 7);
		cout << "ProPlus2016";
		break;
	case 11:
		gotoxy(87, 8);
		cout << "Pro2016";
		break;
	case 12:
		gotoxy(87, 9);
		cout << "HomeAndBusiness2016";
		break;
	case 13:
		gotoxy(87, 10);
		cout << "HomeAndStudent2016";
		break;
	case 14:
		gotoxy(87, 11);
		cout << "VisioPro2016";
		break;
	case 15:
		gotoxy(87, 12);
		cout << "ProjectPro2016";
		break;
	case 16:
		gotoxy(75, 14);
		cout << "Khac";
		break;

	default:
		break;
	}
}

int selectionOfOffice() {
	selectionInOfficeScreen(0); // Moi vo thi chon cai 1
	char c; // selection
	int now = 0;
	while (true) {
		c = _getch();
		if (c == '\r') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			return now;
		}
		else if (c == 72) { // Turn up
			restoreColorInOfficeScreen(now);
			now--;
		}
		else if (c == 80) { // Turn down
			restoreColorInOfficeScreen(now);
			now++;
		}
		else if (c == 75) {// Turn left
			restoreColorInOfficeScreen(now);
			now-=10;
		}
		else if (c == 77) {
			restoreColorInOfficeScreen(now);
			now += 10;
		}

		if (now < -4) now += 20;
		else if (now == -1 || now == 9) now += 6;
		else if (now >= 20) now -= 20;
		else if (now == 7) now -= 7;
		else if (now == 6) now = 16;
		else if (now == 17) now -= 7;
		selectionInOfficeScreen(now);
	}
}