#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>

using namespace std;

const int numselectWelcome = 3;


void FixConsoleWindow();
void gotoxy(short x, short y);
void gotoxy1(short x, short y);
void resizeConsole(int width, int height);
void screenWelcome();
int selectionOfWelcome();
void screenRetailOrVL();
int selectionOfRetailOrVl();
void screenWindows();
int selectionOfWindows();
void screenOffice();
int selectionOfOffice();
void screenStatus(int x);
int selectionOfStatus(int x);
void screenMenu();
int selectionOfMenu();