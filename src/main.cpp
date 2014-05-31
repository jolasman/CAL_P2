#include <iostream>

#include "Interface.h"
#include "StringMatch.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <time.h>
using namespace std;

#define DEBUG 0



int selectOption(int &option, int nr_options, string msg){
	//last option always is to quit
	bool error = false;
	string input;
	do{
		cin.clear();
		if(error){
			cout<<"invalid input"<<endl;
		}
		cout<<msg<<endl;
		getline(cin, input);
		stringstream convert(input);
		convert >> option;
		error= true;
	}
	while(cin.fail() || option > nr_options || option < 1);

	return 0;
}


int loadFromDictionary(vector<string> &dictionary, string filepath, string word){

	ifstream file(filepath.c_str());
	if (!file)
	{ 
		system("cls");
		cout << "Error opening dictionary!" << endl;
		system("cd");
		cout << filepath << endl << endl;
		cout << "Check if file is placed in the correct folder specified above." << endl;
		cout << "(press any key to continue)";
		_getch();
		return -1;
	}

	string tmp;
	system("CLS");
	cout<<"Preparing the game..."<<endl;

	while (!file.eof()) {
		getline(file, tmp);	
		int q;
		if(kmp(tmp, word, q) > 0 && word.size() < tmp.size()){
			dictionary.push_back(tmp);
		}
		tmp.clear();
	}
	file.close();

	return dictionary.size();
}


bool filter(vector<string> &dictionary, string const &pattern){

	int q;
	bool valid = false;

	vector<int> filter_index;

	if(DEBUG)
		cout<<"At filter(). Dictionary size= "<<dictionary.size()<<endl;

	for(unsigned int i = 0; i < dictionary.size(); i++)
	{
		int found;

		if(kmp(dictionary[i], pattern, q) < 1)
			filter_index.push_back(i);
		else
			if(q == 0 && dictionary[i].size() == pattern.size())
			{
				filter_index.push_back(i);
				valid = true;
			}

			if(DEBUG){
				cout<<"dictionary["<<i<<"]= "<<dictionary[i]<<"   q="<<q<<endl;
			}
	}


	if((dictionary.size() - filter_index.size()) > 0 || valid) //the word exists
	{
		if(DEBUG)
			for(int j = 0; j < filter_index.size(); j++)
			{
				cout<<"index to remove: "<< filter_index[j]<<endl;
				cout<<"index to remove after previous remotions: "<< filter_index[j] - j<<endl<<endl;
			}

			for(int i = 0; i<filter_index.size(); i++)
				dictionary.erase(dictionary.begin() + (filter_index[i]-i)); //the word index to remove varies with the number of previous remotions

			if(DEBUG){
				cout<<endl<<"remaining words"<<endl;
				for(int i = 0; i< dictionary.size(); i++)
					cout<<"#"<<i<<" : "<<dictionary[i]<<endl;
			}

			return true;
	}

	return false;
}



bool automatedMove(vector<string> &dictionary, string &pattern){
	int q;

	if(dictionary.size() > 0)
	{
		srand (time(NULL));
		int random_nr = rand() % dictionary.size();

		string chosen = dictionary[random_nr];
		kmp(chosen, pattern, q);

		if(q == 0)
		{ //pattern is a prefix of the chosen word
			pattern += chosen[pattern.size()];

			if(DEBUG)
				cout<<"prefix: New automated pattern :"<< pattern <<endl;

			filter(dictionary, pattern);
			return true;
		}


		if((q + pattern.size())>= chosen.size())
		{ //the pattern is a suffix of the chosen word
			pattern = chosen[q-1]+pattern;

			if(DEBUG)
				cout<<"suffix: New automated pattern :"<< pattern <<endl;

			filter(dictionary, pattern);
			return true;
		}


		random_nr = rand() % 2;

		if((random_nr/2)==0)
		{
			pattern += chosen[(q+pattern.size())];
			cout<<"adding last: New automated pattern :"<< pattern <<endl;

			return true;
		}

		pattern = chosen[(q-1)]+pattern;
		cout<<"adding first: New automated pattern :"<< pattern <<endl;

		filter(dictionary, pattern);

		return true;

	}


	return false;
}


bool userMove(vector<string> &dictionary, string &pattern){
	int option;
	string msg("\n\nChoose an option:\n1-Insert at the beggining\n2-Insert at the end");
	 msg= "Current Word: " + pattern + msg;

	 selectOption(option, 2, msg);

	 string attach;
	do{
		cout<<"\nCurrent word: "<<pattern<<endl<<"Insert char\n";
		getline(cin, attach);
	}
	while(cin.fail());

	string tmp_pattern;

	switch(option){
	case 1:
		tmp_pattern = attach[0] + pattern;
		break;
	case 2:
		tmp_pattern = pattern + attach[0];
		break;
	default:
		return false;
	}



	if(!filter(dictionary, tmp_pattern))
	{
		if(DEBUG)
			cout<<"userMove(): filter() return was false"<<endl;
		return false;
	}
	else
	{

		if(DEBUG)
		{
			cout<<"old pattern: "<<pattern<<endl;
		}

		pattern = tmp_pattern;

		if(DEBUG)
		{
			cout<<"new pattern: "<<pattern<<endl;
			cout<<"dictionary size: "<<dictionary.size()<<endl;
			for(int i =0; i < dictionary.size(); i++)
				cout<<"#"<<i<<" "<< dictionary[i]<<endl;
		}

	}
	return true;

}


bool gameEnd(vector<string> const &dictionary){
	if(dictionary.size() == 0)
		return true;
	return false;
}


bool gameEngine(string const &dictionary_path, string &word){
	vector<string> dictionary;
	int status;
	status = loadFromDictionary(dictionary, dictionary_path, word);

	if(dictionary.size() < 2)
	{
		if (status == -1) {
			return false;
		}
		cout << "Either the dictionary doesn't know the word given, or there aren't enough words cointaining that to play." << endl;
		cout << "(press any key to continue)";
		_getch();
		return false;
	}


	bool user_turn = false, quit = false;
	int option;
	string user_move_msg("1-try again\n2-quit");


	while(!gameEnd(dictionary) && !quit){
		switch(user_turn)
		{
		case true:
			cout<<"Computer wrote: "<<word<<endl;
			while(!userMove(dictionary, word))
			{
				selectOption(option, 2, user_move_msg);
				if(option == 2)
				{
					quit = true;
					break;
				}
			}
			user_turn= false;
			break;

		default:
			automatedMove(dictionary, word);
			user_turn = true;
			break;
		}
	}

	if(!quit){
		if(!user_turn)
			cout<<"Congratulations! You won!!!\nPress any key."<<endl;
		else
		cout<<"Computer wins with: "<< word<<"! Try again.\nPress any key."<<endl;

		_getch();
	}


	string play_again("Play another game?\n1-Yes\n2-No\n");
	selectOption(option, 2, play_again);

	if(option==1)
		return true;

	return false;
}

int main()
{
	string dictionary("dictionary.txt");
	string filepath = "./resources/" + dictionary;
	while (true) {
		bool replay = true;
		int choice;
		choice = mainMenu();
		switch (choice) {
		case 0:
			exitScreen();
			return 0;
			break;
		case 1:
			while (replay) {
				vector<string> words;
				string starting_word;
				do {
					cout << "Input starting word(word size must be greater than 2): ";
					getline(cin, starting_word);
				} while (starting_word.size() >= 5 || starting_word.size() <= 2);
				replay = gameEngine(filepath, starting_word);
			}
			break;
		case 2:
			instructionScreen();
			break;
		case 3:
			system("cls");
			cout << "Current dictionary: " << endl;
			system("cd");
			cout << "/resources/" << dictionary << endl << endl;
			cout << "The new dictionary should be placed in the resources folder located on the path written above!" << endl;
			cout << "Input name of new dictionary: (eg: novo.txt)" << endl;
			getline(cin, dictionary);
			if (cin.fail()) {
				dictionary = "dictionary.txt";
				cin.clear();
				cout << "Invalid input!";
				Sleep(300);
			}
			filepath = "./resources/" + dictionary;
			break;
		default:
			break;
		}
	}
}