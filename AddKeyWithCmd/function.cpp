#include"function.h"

//===================================================Key========================================================

Key::Key(string text, bool type, time_t date) {
	_text_key = text;
	_date_key = date;
}

Key::Key() {
	_text_key = "\0";
	_date_key = NULL;
}

bool Key::checkValidTextKey(string text) {
	return text.length() == 29 && text[5] == '-' && text[11] == '-' && text[17] == '-' && text[23] == '-';
}

//================================================Key retail================================================

string KeyRetail::toString() {
	stringstream writer;
	stringstream writetime;

	time_t timet = getDateKey();

	tm *time = localtime(&timet);
	
	writetime << setfill('0') << setw(2) << time->tm_mday << "/" << setfill('0') << setw(2) << time->tm_mon + 1 << "/" << time->tm_year + 1900 << " " << setfill('0') << setw(2) << time->tm_hour << ":" << setfill('0') << setw(2) << time->tm_min << ":" << setfill('0') << setw(2) << time->tm_sec;

	

	writer << "|  " << getTextKey() << "  |  " << left << setfill(' ') << setw(13) << getStatus() << "  |  " << getTypeKey() << "  |  " << left << setfill(' ') << setw(25) << getSubTypeKey() << "  |  " << writetime.str() << "  |";
	return writer.str();
}


string KeyVL::toString() {
	stringstream writer;
	stringstream writetime;
	time_t timet = getDateKey();
	tm* time = localtime(&timet);

	writetime << setfill('0') << setw(2) << time->tm_mday << "/" << setfill('0') << setw(2) << time->tm_mon + 1 << "/" << time->tm_year + 1900 << " " << setfill('0') << setw(2) << time->tm_hour << ":" << setfill('0') << setw(2) << time->tm_min << ":" << setfill('0') << setw(2) << time->tm_sec;

	writer << "|  " << getTextKey() << "  |  " << left << setfill(' ') << setw(13) << getStatus() << "  |  " << getTypeKey() << "  |  " << left << setfill(' ') << setw(25) << getSubTypeKey() << "  |  " << writetime.str() << "  |";
	return writer.str();
}


//=============================================LIST KEY=============================================

/*Format: Type_Key_Subtype_Date
return true if read successful
return false if fail to read*/
bool ListKey::readFile() {
	ifstream FileIn;
	FileIn.open("key.txt");

	if (!FileIn.is_open()) {
		cout << "File khong ton tai! Co loi mo file\n";
		return 0; // fail open
	}
	
	while (!FileIn.eof()) {
		Key* temp;
		string type;// Retail or VL
		string temptext;
		time_t temptime;

		getline(FileIn, type, '|');
		if (type == "Retail") {// new memory for Retail or VL
			temp = new KeyRetail();
		}
		else if("Volume") {
			temp = new KeyVL();
		}
		else {
			return 0; // fail to read
		}
		
		getline(FileIn, temptext, '|');
		if (!Key::checkValidTextKey(temptext)) return 0;// wrong format of key
		temp->setTextKey(temptext);

		getline(FileIn, temptext, '|');
		temp->setStatus(temptext);


		getline(FileIn, temptext, '|');
		temp->setSubTypeKey(temptext);
		
		FileIn >> temptime;
		temp->setDateKey(temptime);

		_key.push_back(temp);

	}

	FileIn.close();
	return 1;
}

void ListKey::printListKey() {
	int n = _key.size();
	cout << "\tBy: Le Van Dong\n\tWebsite: https://levandong.com\n\tForum: https://vn-z.vn\n\n";
	cout << "|  ID  |  KEY                            |     Status      |  Type    |  Detail                     |  Last Modified        |\n";
	cout << "|======|=================================|=================|==========|=============================|=======================|\n";
	for (int i = 0; i < n; i++) {
		string status = _key[i]->getStatus();
		if ( status == "online") {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		else if (status == "get web" ) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		else if (status == "die") {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else if (status == "by phone") {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout << "|   " << i + 1 << "  " << _key[i]->toString() << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

bool ListKey::outFile() {
	ofstream FileOut;
	FileOut.open("key.txt");

	if (!FileOut.is_open()) {
		cout << "Co loi trong qua trinh ghi ra file\n";
		return 0; //Fail open
	}

	int n = _key.size();
	for (int i = 0; i < n; i++) {
		FileOut << _key[i]->getTypeKey() << "|" << _key[i]->getTextKey() << "|"  << _key[i]->getStatus() << "|" << _key[i]->getSubTypeKey() << "|" << _key[i]->getDateKey() << endl;
	}

	FileOut.close();
	return true;
}

void ListKey::clear() {
	int n = _key.size();
	for (int i = 0; i < n; i++) {
		delete _key[i];
	}
}

void ListKey::add(string type, string key, string status, string subtype) {
	Key* temp;
	time_t now = time(0);

	if (type == "Retail") {
		temp = new KeyRetail();
	}
	else {
		temp = new KeyVL();
	}

	temp->setTextKey(key);
	temp->setSubTypeKey(subtype);
	temp->setDateKey(now);
	temp->setStatus(status);
	_key.push_back(temp);

}

void ListKey::editStatus(int index, string status) {
	time_t now = time(0);
	_key[index - 1]->setStatus(status);
	_key[index - 1]->setDateKey(now);
}
void ListKey::del(int index) {
	_key.erase(_key.begin() + index - 1);
}