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
	cout << "Version: 1.1";
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