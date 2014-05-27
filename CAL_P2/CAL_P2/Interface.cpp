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
/*apresenta no ecra o menu de opcoes*/
void screen_intructions(){

	system("CLS");
	cout << "-----------------------------Encontra a Palavra---------------------------------\n\n";
	cout << "\nEste e um jogo para dois jogadores, A e B.";
	cout << "\n\nInicialmente e colocada na mesa uma palavra de N letras (N<5).";

	cout << "\n\nOs jogadores tentam construir novas palavras a partir da palavra da mesa\n";
	cout << ",isto e, palavras que contenham a palavra da mesa.";

	cout << "\n\nAssim, os jogadores jogam alternadamente adicionando uma letra a palavra\n";
	cout << "da mesa (no inicio ou no fim).\n\n";

	cout << "\nO jogo termina quando um dos jogadores nao consegue adicionar qualquer letra\n";
	cout <<	"a palavra da mesa, e perde o jogo.";

	cout << "\n\nO jogador vencedor deve mostrar a palavra em que estava a pensar.\n";
	cout << "\n\n\n                        (press any key to continue)\n\n";
	_getch();
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
			screen_intructions();
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