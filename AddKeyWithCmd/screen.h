#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>

using namespace std;

const int numselectWelcome = 2;

void FixConsoleWindow();
void gotoxy(short x, short y);
void gotoxy1(short x, short y);
void resizeConsole(int width, int height);
void screenWelcome();
void SelectionInScreenWelcome(int selection);
void restoreColorInScreenWelcome(int selection);
int selectionOfWelcome();