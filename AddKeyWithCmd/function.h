#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include"screen.h"
using namespace std;

class Key {
private:
	string _text_key;
	time_t _date_key;

public:

	Key();
	Key(string text, bool type, time_t date);
	//----------------------------------------------------------Getter - Setter - toString---------------
	void setTextKey(string text) { _text_key = text; }
	string getTextKey() { return _text_key; }

	virtual string getTypeKey() = 0;
	virtual void setSubTypeKey(string type) = 0;
	virtual string getSubTypeKey() = 0;

	virtual void setStatus(string status) = 0;
	virtual string getStatus() = 0;

	void setDateKey(time_t date) { _date_key = date; }
	time_t getDateKey() { return _date_key; }

	//==========================================FUNCTION ULTILITIES=========================================
	virtual string toString() = 0;
	static bool checkValidTextKey(string text);
	
};


class KeyRetail : public Key {
private:
	string _type = "Retail";
	string _subtype;
	string _status;
public:
	string getTypeKey() { return _type; }

	void setSubTypeKey(string type) { _subtype = type; }
	string getSubTypeKey() { return _subtype; }

	void setStatus(string status) { _status = status; }
	string getStatus() { return _status; }

	string toString();
};

class KeyVL : public Key {
private:
	string _type = "Volume";
	string _subtype;
	string _status;
public:

	string getTypeKey() { return _type; }

	void setSubTypeKey(string type) { _subtype = type; }
	string getSubTypeKey() { return _subtype; }

	void setStatus(string status) { _status = status; }
	string getStatus() { return _status; }

	string toString();
};


class ListKey {
private:
	vector<Key *> _key;
public:
	void printListKey();
	int size() { return _key.size(); }
	bool readFile();
	bool outFile();
	void clear();
	void add(string type, string key, string status, string subtype);
	void editStatus(int index, string status);
	void del(int index);

	//----------------------------------------------------------Sorting--------------------------
	//void SortListKey(bool type, bool isascending = 1);// sort with type retail or VL
	//void SortListKey(int date, bool isascending = 1); // sort with date
	//void SortListKey(bool isascending = 1); // Sort with name

	//----------------------------------------------------------Finding--------------------------
};
