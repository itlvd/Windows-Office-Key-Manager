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
		if ( status == "online" || status == "Online") {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		else if (status == "get web" || status == "Get Web" ) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		else if (status == "die" || status == "Die" || status == "Block" || status == "block" || status == "Blocked") {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		else if (status == "by phone" || status == "byphone" || status == "By Phone") {
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
void ListKey::push_back(Key* key) {
	_key.push_back(key);
}

string wiring() {
	string str = "\0";
	for (int i = 0; i < 5; i++) {
		string temp;
		getline(cin, temp, '\n');
		str = str + temp + " ";
	}
	return str;
}

Key* parse(string temp) {
	string keytext = "\0";
	string type = "\0";
	string subtype = "\0";
	string status = "\0";

	size_t key_s = temp.find("Key: ");
	size_t key_send = temp.find(" ", key_s + 6);
	keytext = temp.substr(key_s + 5, 29);

	size_t retail_found = temp.find("Retail");

	if (retail_found != string::npos) type = "Retail";
	else type = "Volume";

	size_t subtype_s = temp.find("Win 10 RTM Professional");
	if (subtype_s != string::npos) {
		subtype = "Win10 Pro";
		goto STATUS;
	}

	subtype_s = temp.find("Win 10 RTM Education Retail");
	if (subtype_s != string::npos) {
		subtype = "Win10 Edu";
		goto STATUS;
	}

	subtype_s = temp.find("Win 10 RTM EnterpriseS");
	if (subtype_s != string::npos) {
		size_t ltsc = temp.find("[RS5]X21");
		if (ltsc != string::npos) {
			subtype = "LTSC";
			goto STATUS;
		}
		else {
			subtype = "LTSB";
			goto STATUS;
		}
	}

	subtype_s = temp.find("Win 10 RTM Enterprise");
	if (subtype_s != string::npos) {
		subtype = "Win10 Enterprise";
		goto STATUS;
	}

	subtype_s = temp.find("ProPlus2019");
	if (subtype_s != string::npos) {
		subtype = "ProPlus2019";
		goto STATUS;
	}

	subtype_s = temp.find("Office16_ProPlus");
	if (subtype_s != string::npos) {
		subtype = "ProPlus2016";
		goto STATUS;
	}

	subtype_s = temp.find("HomeBusiness2019");
	if (subtype_s != string::npos) {
		subtype = "HomeAndBusiness2019";
		goto STATUS;
	}

	subtype_s = temp.find("HomeBusines");
	if (subtype_s != string::npos) {
		subtype = "HomeAndBusiness2016";
		goto STATUS;
	}

	subtype_s = temp.find("HomeStudent2019");
	if (subtype_s != string::npos) {
		subtype = "HomeAndStudent2019";
		goto STATUS;
	}

	subtype_s = temp.find("HomeStudent");
	if (subtype_s != string::npos) {
		subtype = "HomeAndStudent2016";
		goto STATUS;
	}

	subtype_s = temp.find("ProjectPro2019");
	if (subtype_s != string::npos) {
		subtype = "ProjectPro2019";
		goto STATUS;
	}

	subtype_s = temp.find("Office16_ProjectPro");
	if (subtype_s != string::npos) {
		subtype = "ProjectPro2016";
		goto STATUS;
	}

	subtype_s = temp.find("VisioPro2019");
	if (subtype_s != string::npos) {
		subtype = "VisioPro2019";
		goto STATUS;
	}

	subtype_s = temp.find("Office16_VisioPro");
	if (subtype_s != string::npos) {
		subtype = "VisioPro2016";
		goto STATUS;
	}



STATUS:
	size_t status_s = temp.find("Online");
	if (status_s != string::npos) {
		status = "Online";
	}

	status_s = temp.find("0xC004C008");
	if (status_s != string::npos) {
		status = "Get web";
	}

	status_s = temp.find("0xC004C060");
	if (status_s != string::npos) {
		status = "Block";
	}

	status_s = temp.find("Get Web");
	if (status_s != string::npos) {
		status = "Get Web";
	}

	status_s = temp.find("Remaining: ");
	if (status_s != string::npos) {
		size_t pos = temp.find(" ", status_s + 12);
		status = temp.substr(status_s + 11, pos - status_s - 11);
	}

	Key *key;

	if (type == "Retail") key = new KeyRetail();
	else key = new KeyVL();

	key->setTextKey(keytext);
	key->setSubTypeKey(subtype);
	key->setStatus(status);

	time_t now = time(0);
	key->setDateKey(now);
	return key;
}