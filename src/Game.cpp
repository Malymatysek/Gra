/*
 * Game.cpp
 *
 *  Created on: 4 sie 2024
 *      Author: Matys
 */
#include "Game.h"

Game::Game()
{
    for (int x = 0; x < 20; x++)
        resultLottery[x] = 0;
}
void Game::checkResultGame() 
{
    
    startMoney = startMoney - (stawka * 100); // minus stawka

    for (int i = 0; i < 20; i++)
    {
        checkPayLineAndSet(i, tabSignWin);
        // checkPayLine(i);
        resultLottery[i] = bonusValue(tabWin[i][0], tabWin[i][1]);
        endResultLottery += resultLottery[i];
    }
    cout << " Wygrana : " << endResultLottery << endl;

    startMoney = startMoney + endResultLottery; // suma w portfelu
#ifdef DEBUG
    for (int j = 0; j < 20; j++)S
    {
        endResultLottery += resultLottery[j];
        cout << " Tab[" << j << "]: " << resultLottery[j] << endl;
    }
#endif 
}
void Game::setStatiscic()
{

}
void Game::clear()
{
    endResultLottery = 0;
}
void Game::showWinLine()
{
    LogicGame::showWinLine(); 
}
void Game::showLotteryResult() 
{
    cout << "  Uklad gry \n";
    cout << " Stan konta : " << startMoney << "\n";

    for (int j = 0; j < 3; j++)
    {
        for ( int i = 0; i < 5; i++)
        {
            printf("%d, ", lotteryResultTab[i][j]);  
        }
        printf("\n");
    }
    printf("\n");
}
void Game::setRate(int rate)
{
    stawka = rate;
}
int Game::getRate()
{
    return stawka;
}
void Game::setStartMoney(int money)
{
  startMoney = money;
}
int Game::getStartMoney()
{
    return startMoney;
}
void Game::setLoopGames(int loop) 
{
    loopGame = loop;
}
int  Game::getLoopGame()
{
    return loopGame;
}
//void Gra::checkWin()
//{
//    startMoney = startMoney - (stawka * 100); // minus stawka
//
//    for (int j = 0; j < 20; j++)
//    { 
//        if (0 < checkWinLottery(j, dane)) 
//        {
//            resultLottery[j] = checkWinLottery(j, dane);
//            endResultLottery += resultLottery[j];
//        }
//    }
//    cout << " Wygrana : " << endResultLottery << endl;
//
//    startMoney = startMoney + endResultLottery; // suma w portfelu
//
//#ifdef DEBUG
//    for (int j = 0; j < 20; j++)S
//    {
//        endResultLottery += resultLottery[j];
//        cout << " Tab[" << j << "]: " << resultLottery[j] << endl;
//    }
//#endif 
//}
//void Gra::printGame()
//{
//    cout << "  Uklad gry \n";
//    cout << "Twoje pieniazki : "<< startMoney <<"\n";
//
//    for (size_t i = 0; i < dane.size(); i++)
//    {
//        if (i == 5 || i == 10)
//        {
//            printf("\n");
//        }
//        printf("%d, ", dane[i]);
//    }
//    printf("\n");
//}