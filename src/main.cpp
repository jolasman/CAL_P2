#include <iostream>

#include "Interface.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
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
		getchar();
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
		getchar();
	}
}


int main()
{
	vector<string> words;
	string filepath("./resources/dictionary.txt");
	string starting_word;

	//loadFromDictionary(words, filepath);
	mainMenu();
	

	return 0;

}