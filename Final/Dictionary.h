#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary
{
private:
	int kelimeSayisi = 1;
	set<string> words;
	vector<string> secrets;

	bool TestLegalSecretWord(string word);
public:

	Dictionary();
	Dictionary(string dosyaAdi);
	~Dictionary();

	string BringValidWord();
	bool IsWordValid(string word);
};