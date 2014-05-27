#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include "Interface.h"

using namespace std;


/*apresenta no ecra o menu de opções entre os outros submenus para a possivel navegacao do utilizador*/
void main_menu()
{
	system("CLS");
	cout << "-----------------------------Encontra a Palavra---------------------------------\n\n";
	cout << "1. Play" << endl;
	cout << "2. Help" << endl;
	cout << "3. Option" << endl;
	cout << "0. Exit\n\n";
	cout << "Choose a number: ";
}
/*apresenta no ecra o menu de saida*/
void screen_exit(){

	system("CLS");
	cout << "\n\n\n-----------------------------Thank You For Playing------------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       program by:";
	cout << "\n                                                               Joel Carneiro";
	cout << "\n                                                               Daniel Mendonca";
	cout << "\n                                                               Francisco Lopes\n\n";
}

/*chama as funcoes para construir o menu*/
void game_menu(){
int n;
bool loop1 = 1, loop2;
char choice;

	while (loop1 == 1)
	{
	main_menu();

	loop2 = 1;
	while (loop2 == 1)
	{
		cin >> choice;
		n = choice - '0';
		switch (n)
		{
		case 1:
			cin.clear();
			cin.ignore(1000, '\n');
			

			loop2 = 0;
			break;
		case 2:
			cin.clear();
			cin.ignore(1000, '\n');
		

			loop2 = 0;
			break;
		case 3:
			cin.clear();
			cin.ignore(1000, '\n');
			

			loop2 = 0;
			break;
		case 0:
			cin.clear();
			cin.ignore(1000, '\n');
			screen_exit();
			loop1 = 0;
			loop2 = 0;
			break;
		default:
			cin.clear();
			cin.ignore(1000, '\n');
			break;
			}
		}
	}
}