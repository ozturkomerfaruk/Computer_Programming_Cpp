#include "Dictionary.h"

bool Dictionary::TestLegalSecretWord(string word)
{
	bool boolValue = true;
	for (int birinciKelime = 0; birinciKelime < secrets.size(); birinciKelime++)
	{
		for (int ikinciKelime = birinciKelime + 1; ikinciKelime < word.length(); ikinciKelime++)
		{
			if (word[birinciKelime] == word[ikinciKelime])
			{
				boolValue = false;
			}
		}
	}
	return boolValue;
}

Dictionary::Dictionary() {};

Dictionary::Dictionary(string dosyaAdi)
{
	string kelimeler;
	string wordHolder;
	fstream dataFile;
	dataFile.open(dosyaAdi, ios::in);

	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{
		dataFile >> kelimeler;
		while (!dataFile.eof())
		{
			this->words.insert(kelimeler);
			dataFile >> kelimeler;
		}

		for (set<string>::iterator it = this->words.begin(); it != this->words.end(); ++it)
		{
			wordHolder = *it;
			if (TestLegalSecretWord(wordHolder))
				this->secrets.push_back(wordHolder);
			this->kelimeSayisi++;
		}

	}
	dataFile.close();
}

Dictionary::~Dictionary()
{
	words.clear();
	secrets.clear();
}

string Dictionary::BringValidWord()
{
	srand(time(NULL));
	cout << "Bilbakalim Oyununa Hosgeldiniz " << endl 
		<< "Aklimda 5 harfli " << kelimeSayisi << " kadar kelime bulunmakta ve simdi "
		<< "onlardan bir tanesini yani :) "<< endl << "5 harften olusan bir kelime tuttum." << endl;
	cout << "Oyuna gecmeden once bir ipucudan bahsetmek istiyorum." << endl
		<< "Eger tahmin etmekte zorlaniyorsaniz 'xxxxx' yazdiginizda gizli kelime sizin karsiniza cikacaktir." << endl;
	int rnd = rand() % secrets.size();
	string val = secrets[rnd];
	return val;
}

bool Dictionary::IsWordValid(string word)
{
	int flag = 0;

	for (set<string>::iterator foreachWordIt = this->words.begin(); foreachWordIt != this->words.end(); ++foreachWordIt)
	{
		string wordHolder = *foreachWordIt;
		if (word == wordHolder)
		{
			flag = 1;
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}