#include <iostream>

#include "Interface.h"

using namespace std;


/*apresenta no ecra o menu de opções entre os outros submenus para a possivel navegacao do utilizador*/
void menu_inicial()
{
	system("CLS");
	cout << "-----------------------------Encontra a Palavra---------------------------------\n\n";
	cout << "1. Play" << endl;
	cout << "2. Help" << endl;
	cout << "3. Option" << endl;
	cout << "0. Exit\n\n";
	cout << "Choose a number: ";
}