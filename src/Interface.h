#ifndef _INTERFACE
#define _INTERFACE

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

void mainMenu();
void exitScreen();
void instructionScreen();
int parseInput(string &input);
#endif