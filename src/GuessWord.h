#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "StringMatch.h"
#include <conio.h>

using namespace std;

class GuessWord
{

	string word;
	string dictionary_path;
	vector<string> dictionary;
	bool user_turn;


public:
	GuessWord(void);
	GuessWord(string dictionary_path, string starting_word);
	~GuessWord(void);
	int loadFromDictionary();
	int filter();
	bool automatedMove();
	bool userMove();
	bool gameEnd();
	bool gameEngine();

};

