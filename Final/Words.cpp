#include "Words.h"

int Words::countofMatchLetters(string word)
{
	string strWord = word;
	int wordCounter = 0;
	for (int birinciKelime = 0; birinciKelime < 5; birinciKelime++)
	{
		for (int ikinciKelime = 0; ikinciKelime < word.size(); ikinciKelime++)
		{
			if (word.at(ikinciKelime) == secret.at(birinciKelime))
			{
				wordCounter++;
			}
		}
	}
	return wordCounter;
}

int Words::countofTruePlaceLetters(string word)
{
	int wordCounter = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word.at(i) == secret.at(i))
		{
			wordCounter++;
		}
	}
	return wordCounter;
}

Words::Words()
{
	numguesses = 0;
	cheated = false;
	secret = "";
}

Words::~Words() {};


void Words::PlayGame(Words& W)
{
	string dosyaAdi = "words.txt";
	Dictionary dictionary(dosyaAdi);

	secret = dictionary.BringValidWord();
	
	int smile = 2;
	cout << "Algoritmanin test edilmesi icin bu gizli kelimeyi "
		"size soyleyecegim (^-^*)/" << endl << "Sen simdi benim icin kelimeyi bilmiyormussun gibi yapar misin " << 
		char(smile) <<  " "  << char(smile) <<  " " << char(smile) << endl
		<< "Gizli kelime -> " << secret << endl;

	bool bilmeDurumu = true;
	bool sozlukDurumu, ipucuDurumu = false;
	string kullaniciTahmin = "";


	while (bilmeDurumu)
	{
		cout << "Tahmininiz Nedir: ";
		getline(cin, kullaniciTahmin);
		if (kullaniciTahmin.size() != 5)
		{
			cout << "Lutfen 5 haneli bir kelime giriniz." << endl;
		}
		else
		{
			if (kullaniciTahmin == "xxxxx")
				cheated = true;
			if (!cheated)
			{
				sozlukDurumu = dictionary.IsWordValid(kullaniciTahmin);
				if (sozlukDurumu)
				{
					numguesses++;
					if (kullaniciTahmin != secret)
					{
						int eslesenHarfSayisi = countofMatchLetters(kullaniciTahmin);
						int eslesenHarflerinDogruKonumu = countofTruePlaceLetters(kullaniciTahmin);
						cout << endl << "Eslesen Harf Sayisi: " << eslesenHarfSayisi << endl
							<< "Eslesen Harflerin Dogru Konumu: " << eslesenHarflerinDogruKonumu << endl;
					}
					else
					{
						if (ipucuDurumu == false)
							cout << "Bildiniz! " << numguesses << " tahminde dogru sonuca ulastiniz!" << endl;
						else
							cout << "Bildiniz! " << numguesses << " tahminde ipucu kullanarak dogru sonuca ulastiniz!" << endl;
						bilmeDurumu = false;
					}

				}
				else
				{
					cout << "Bu kelime sozlukte yok!" << endl;
				}
			}
			else
			{
				numguesses++;
				cout << endl << "Ipucu! Gizli Kelime: " << secret << endl;
				ipucuDurumu = true;
			}
			cheated = false;
		}
	}
}