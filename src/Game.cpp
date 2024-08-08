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
//--------------------------------
void Game::checkResultGame() 
///--------------------------------
{
    LogicGame::oneLotteryResult(); 
    

    startMoney = startMoney - rateLos; // minus stawka
        
    for (int i = 0; i < 20; i++)
    {
        resultLottery[i] = rateLos * tabWin[i][2];   // result one pay line one lottery
        endResultLottery = endResultLottery + resultLottery[i];       // result all pay line one lottery
    }
    endResultLottery = endResultLottery - rateLos;

    loseResult = loseResult + rateLos;
    winResult  =  winResult + endResultLottery;


    cout << " Wygrana : " << endResultLottery << endl;
    cout << " Stracone_Pieniadze : " << loseResult << endl;
    cout << " Wygrane_Pieniadze  : " << winResult << endl;
    
    startMoney = startMoney + endResultLottery; // suma w portfelu

#ifdef DEBUG
    for (int j = 0; j < 20; j++)
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
void Game::setRate(double rate)
{
    rateLos = rate;
}
double Game::getRate()
{
    return rateLos;
}
void Game::setStartMoney(double money)
{
  startMoney = money;
}
double Game::getStartMoney()
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
