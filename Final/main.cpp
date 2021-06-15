#include "Dictionary.h"
#include "Words.h"
using namespace std;

int main()
{
    cout << (char)0xA9 << " " << char(153) << "MER FARUK " << char(153) << "ZT" << char(154) << "RK" << endl
        << "iletisim" << char(64) << "ozturkomerfaruk.com" << endl
        << "ESOG" << char(154) << " OKUL NUMARASI: 152120171018" << endl;
    int sinir = 97;
    for (int i = 0; i < sinir; i++)
        cout << char(176);
    cout << endl;
    for (int i = 0; i < sinir; i++)
        cout << char(177);
    cout << endl;
    for (int i = 0; i < sinir; i++)
        cout << char(178);
    cout << endl;
    for (int i = 0; i < sinir; i++)
        cout << char(177);
    cout << endl;
    for (int i = 0; i < sinir; i++)
        cout << char(176);
    cout << endl;
    system("color F");

	Words oyun;
	oyun.PlayGame(oyun);	

	char yesNo = ' ';
    cout << endl << "Tekrar Oynamak Ister misiniz? (e/H)" << endl;
    cin >> yesNo;
    switch (yesNo)
    {
    case 'e':
        system("cls");
        main();  
        break;
    case 'E':
        main();
        break;
    default:
        cout << "(E)vet harfinin bas harfi haricinde ki tum harflerde oyun sonlanacaktir." <<
            endl << "Yanlis bir harf girdiyseniz, oyunu yeniden baslatabilirsiniz!" << endl;
        system("pause");
        return 0;
        break;
    }

	system("pause");
    return 0;
}