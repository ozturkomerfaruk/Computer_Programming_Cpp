#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "Dictionary.h"

using namespace std;

class Words : Dictionary
{
private:
	int numguesses;
	bool cheated;
	string secret;
	
	int countofMatchLetters(string);
	int countofTruePlaceLetters(string);
public:
	Words();
	~Words();

	void PlayGame(Words&);
};