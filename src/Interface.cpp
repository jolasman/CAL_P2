#include "Interface.h"

/*apresenta no ecra o menu de opções entre os outros submenus para a possivel navegacao do utilizador*/
void mainMenu() {
	int result = -1;
	while (result == -1) {
		system("CLS");
		cout << "--------------------------------Find the word---------------------------------\n\n";
		cout << "1. Play" << endl;
		cout << "2. Instructions" << endl;
		cout << "0. Exit\n\n";
		cout << "Choose a number: ";
		string input;
		getline(cin, input);
		if (cin.fail()) {
			result = -1;
			cin.clear();
			cout << "Invalid input!";
			Sleep(300);
		} else result = parseInput(input);
		switch (result) {
		case 0:
			exitScreen();
			break;
		case 1:
			cout << "GAME PLACEHOLDER" << endl;
			Sleep(200);
			result = -1;
			break;
		case 2:
			instructionScreen();
			break;
		default:
			result = -1;
			break;
		}
	}
}

/*apresenta no ecra o menu de saida*/
void exitScreen() {
	system("CLS");
	cout << "\n\n\n-----------------------------Thank You For Playing------------------------------\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n                                                       Program by:";
	cout << "\n                                                               Joel Carneiro";
	cout << "\n                                                               Daniel Mendonca";
	cout << "\n                                                               Francisco Lopes\n\n";
}
/*apresenta no ecra o menu de instrucoes*/
void instructionScreen() {
	system("CLS");
	cout << "-----------------------------Find the word---------------------------------\n\n\n";
	cout << "This is a two player game.\n\n";
	cout << "Initially one player chooses a word with a size no longer than 5 letters.\n\n";
	cout << "The players try to form new words containing the word already on the table.\n\n";
	cout << "For that purpose, the players alternate between choosing a letter to add to the start or end of the word on the table.\n\n";
	cout << "The game ends when a player can no longer add a letter to the word and the last player to play wins the game.\n\n";
	cout << "The winner should show what word he was thinking of.\n\n\n";
	cout << "                        (press any key to continue)";
	_getch();
	mainMenu();
}

int parseInput(string &input) {
	stringstream convert(input);
	int result;
	if (!(convert >> result)) {
		cout << "Invalid input!";
		Sleep(300);
		result = -1;
	}
	return result;
}