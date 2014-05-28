#include <iostream>

#include "Interface.h"
#include "StringMatch.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

#define DEBUG 1


/*
memory test
*/
void loadFromDictionary(vector<string> &dictionary, string filepath){

	ifstream file(filepath.c_str());
	if (!file)
	{ 
		system("pwd\n");
		cout << "Erro a abrir ficheiro de leitura\n";
		_getch();
		exit(1); }

	string tmp;

	while (!file.eof()) {
		getline(file, tmp);
		dictionary.push_back(tmp);
		tmp.clear();
	}
	file.close();

	if(DEBUG){
		cout <<dictionary.size()<< " nr of words"<<endl;
		_getch();
	}
}


int filter(vector<string> &dictionary, string const &pattern){

	int q;

	vector<int> filter_index;
	for(unsigned int i = 0; i < dictionary.size(); i++){
		if(kmp(dictionary[i], pattern, q) < 1)
			filter_index.push_back(i);
		else
			if(q == 0 && dictionary[i].size() == pattern.size())
				filter_index.push_back(i);

		cout<<dictionary[i]<< "  q="<<q<<endl;
	}


	if(filter_index.size() > 0)

		if(DEBUG)
		for(int j = 0; j< filter_index.size(); j++)
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
	return filter_index.size();
}



bool automatedMove(vector<string> &dictionary, string &pattern){

	return false;
}

bool userMove(vector<string> &dictionary, string &pattern){
	int option;

	do{
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		if(cin.fail()){
			cin.clear();
			cout<<"Invalid option"<<endl;
		}
		cout<<"Choose an option:\n1-Insert at the beggining\n2-Insert at the end\n";
		cin>>option;	
	}
	while(cin.fail());



	char attach;
	do{

		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		if(cin.fail()){
			cout<<"Invalid option"<<endl;
			cin.clear();
		}
		cout<<"Current word: "<<pattern<<endl<<"Insert char\n";
		cin>>attach;
	}
	while(cin.fail());

	string tmp_pattern;

	switch(option){
	case 1:
		tmp_pattern = attach + pattern;
		break;
	case 2:
		tmp_pattern = pattern + attach;
		break;
	default:
		return false;
	}

	int words_removed;
	if((words_removed=filter(dictionary, tmp_pattern)) < 1)
		return false;

	else{


		if(DEBUG)
		{
			cout<<"old pattern: "<<pattern<<endl;
		}
		pattern = tmp_pattern;
		if(DEBUG)
		{
			cout<<"new pattern: "<<pattern<<endl<<"Words removed: "<<words_removed<<endl;
		}

	}
	return true;

}

bool gameEnd(vector<string> &dictionary, string &pattern){
	return false;
}

int main()
{
	vector<string> words;
	string filepath("./resources/tester.txt");
	loadFromDictionary(words, filepath);

	//TODO user input starting_word
	string starting_word("ana");
	userMove(words, starting_word);
	_getch();

	//game_menu();


	return 0;

}