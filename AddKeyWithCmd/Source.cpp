#include"function.h"


int main() {
	resizeConsole(1200, 600);
	FixConsoleWindow();
	SetConsoleTitleA("Key Windows-Office Manager - Le Van Dong (levandong.com)");
	
	ListKey key;
	key.readFile();

	screenWelcome();
	int x = selectionOfWelcome();

	if (x == 0) {
		system("cls");
		cout << "Nhap loai key: ";
		string type;
		getline(cin, type);

		string keytext;
		do {
			cout << "Nhap key: ";
			getline(cin, keytext);

			if (Key::checkValidTextKey(keytext)) break;
			else {
				cout << "Nhap sai vui long nhap lai!\n";
			}

		} while (true);

		cout << "Nhap ten key: ";
		string subtype;
		getline(cin, subtype);

		cout << "Nhap status: ";
		string status;
		getline(cin, status);

		key.add(type, keytext, status, subtype);
	}
	else if (x == 1) {
		system("cls");
		key.printListKey();
	}

	
	
	
	/*cout << "Nhap loai key: ";
	string type;
	getline(cin, type);

	cout << "Nhap key: ";
	string keytext;
	getline(cin, keytext);

	cout << "Nhap ten key: ";
	string subtype;
	getline(cin, subtype);

	cout << "Nhap status: ";
	string status;
	getline(cin, status);

	key.add(type, keytext, status, subtype);
	key.printListKey();
	*/
	key.outFile();
	key.clear();
	return 0;
}