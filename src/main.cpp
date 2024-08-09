/*
 * main.cpp
 *
 *  Created on: 2 sie 2024
 *      Author: Matys
 */
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Game.h"

using namespace std;

void headText()
{
    cout << "***************** Raport skrócony *****************" << endl;
    cout << "***************************************************" << endl;
    cout << "Modu: slotGameSimulator (wersja 1.0)" << endl;
    cout << endl;
}
inline void wait_on_enter()
{
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}
int main(int argc, char *argv[])
{  
    srand ( time(0) );

    Game start;
    fstream plik; 

    // vector<int> tab;
    // int loop = 0;
    // bool exit = false;
    int gamesCount = 100000;
    int startCredit = 5000000;
    string creditOutFile = "plik.txt";
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-gamesCount") == 0 && i + 1 < argc) {
            gamesCount = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-startCredit") == 0 && i + 1 < argc) {
            startCredit = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-creditOutFile") == 0 && i + 1 < argc) {
            creditOutFile = argv[i + 1];
        }
        // if (strcmp(argv[i], "-symbols") == 0 && i + 1 < argc) {
        //     tab.push_back(atoi(argv[i + 1]));
        // } 
    }
    
    headText();

    start.setRate(100); 
    start.setLoopGames(gamesCount);
    start.setStartMoney(startCredit);
  
    // if(tab.size() > 0 ) 
    //{
    // cout << "TabelaConvert\n ";
	// for (int i = 0; i < 15; i++) {
	// 	if (i == 5 || i == 10)
	// 		printf("\n");
	// 	cout << tab[i]<<", ";
	// }
    // }

    //tu kod usuwający zawartosc plik.txt
    plik.open(creditOutFile, ios::out | ios::trunc);
    if (plik) {
        plik.close(); // Zamknięcie pliku, aby usunąć zawartość
    } else {
        cerr << "Nie można otworzyć pliku do usunięcia zawartości!" << endl;
        return 1; // Wychodzi z programu, jeśli nie udało się otworzyć pliku
    }

    plik.open(creditOutFile, ios::out | ios::app);
    if (plik.good())
    {
        for (int i = 0; i < gamesCount; i++)
        {
            // if(/*statycznaTablica*/false)
            // {
            //     start.staticTabCheck(tab);
            // }
            // else

            start.checkResultGame() ;
        
            plik << "Lottery NR, "<<i
                //  << ",wygrana ," << start.getMoney() 
                 <<",Money, " << start.getStartMoney() 
                 << endl ; 
                        
        }
        plik.close();
    }
    else
    {
        cerr << "Nie można otworzyć pliku!" << endl;
    }

    //resultLottery
    start.showResult();
    cout<<endl<<endl;
    start.showStats();

    printf("\n\nKoniec\n");
    return 0;
}

