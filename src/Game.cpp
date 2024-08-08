/*
 * Game.cpp
 *
 *  Created on: 4 sie 2024
 *      Author: Matys
 */
#include "Game.h"

Game::Game()
{   
    for (int i = 0; i < 25; i++)
        winStatTab[i] = 0;

    for (int x = 0; x < NR_PAY_LINE; x++)
        resultLottery[x] = 0;
}
//--------------------------------
void Game::checkResultGame() 
///--------------------------------
{
    endResultLottery = 0;
    LogicGame::oneLotteryResult(); 
    
    symbolWinStat();
    // showLotteryResult() ;
        
    for (int i = 0; i < NR_PAY_LINE; i++)
    {
        resultLottery[i] = rateEdit * tabWin[i][2];   // result one pay line one lottery
        endResultLottery = endResultLottery + resultLottery[i];       // result all pay line one lottery
    }

       

    startMoney = startMoney - rateLos;  // minus stawka z kredytu

    loseResult = loseResult + rateLos; //suma stawek

    winResult  =  winResult + endResultLottery; //suma wygranych

    startMoney = startMoney + endResultLottery; // suma w portfelu

    cout    << " Wygrana:"            << endResultLottery 
            << " SumaWygranych:"     << winResult 
            << " Stracone_Pieniadze:-"<< loseResult 
            << " Suma Konta:"        << startMoney 
            << " Bilans :"<< winResult-loseResult <<endl;
    

#ifdef DEBUG 
    for (int j = 0; j < NR_PAY_LINE; j++)
    {
        endResultLottery += resultLottery[j];
        cout << " TabResultLine[" << j << "]: " << resultLottery[j] << endl;
    }
#endif 
}
void Game::showStats()
{
    for (int j = 0; j < 25; j++)
    {
        cout << " TabResultLine[" << j << "]: " << winStatTab[j] << endl;
    }
}
void Game::symbolWinStat()
{
     for (int i = 0; i < NR_PAY_LINE; i++)
    {
    if(tabWin[i][2] == 25 )                      winStatTab[0]++;  // 2x Cherry 
    else if(tabWin[i][2] == 100 ) 
    {
        if(tabWin[i][0] == SIGN::CHERRY)         winStatTab[1]++;  // 3x chery             
        else if(tabWin[i][0] == SIGN::LEMON)     winStatTab[2]++;  // 3x lemon                 
        else if(tabWin[i][0] == SIGN::ORANGE)    winStatTab[3]++;  // 3x orange
        else if(tabWin[i][0] == SIGN::PLUM)      winStatTab[4]++;  // 3x plum

    }  
   
    else if(tabWin[i][2] == 200 ) 
    {
        winStatTab[5]++;   // 3x scatter
    }
    else if(tabWin[i][2] == 250 )
    {
        if(tabWin[i][0] == SIGN::GRAPES)         winStatTab[7]++;   // 3x grapes
        else if(tabWin[i][0] == SIGN::WATERLEMON)winStatTab[6]++;   // 3x watermelon      
        else if(tabWin[i][0] == SIGN::CHERRY)    winStatTab[8]++;   // 4x chery             
        else if(tabWin[i][0] == SIGN::LEMON)     winStatTab[9]++;   // 4x lemon    
        else if(tabWin[i][0] == SIGN::ORANGE)    winStatTab[10]++;  // 4x orange
        else if(tabWin[i][0] == SIGN::PLUM)      winStatTab[11]++;  // 4x plum
    }
    else if(tabWin[i][2] == 500 )               
    {
        winStatTab[12]++;  // 3x seven
    }    
    else if(tabWin[i][2] == 1000)               
    {
        if(tabWin[i][0] == SIGN::WATERLEMON)     winStatTab[13]++;  // 4x watermelon
        else if(tabWin[i][0] == SIGN::GRAPES)    winStatTab[14]++;  // 4x grapes
        else if(tabWin[i][0] == SIGN::SCATTER)   winStatTab[15]++;  // 4x scatter
        else if(tabWin[i][0] == SIGN::CHERRY)    winStatTab[16]++;  // 5x chery             
        else if(tabWin[i][0] == SIGN::LEMON)     winStatTab[17]++;  // 5x lemon    
        else if(tabWin[i][0] == SIGN::ORANGE)    winStatTab[18]++;  // 5x orange
        else if(tabWin[i][0] == SIGN::PLUM)      winStatTab[19]++;  // 5x plum
    } 
    else if(tabWin[i][2] == 2500)   
    {
        if(tabWin[i][0] == SIGN::WATERLEMON)     winStatTab[20]++;  // 5x watermelon
        else if(tabWin[i][0] == SIGN::GRAPES)    winStatTab[21]++;  // 5x grapes
    }            
    else if(tabWin[i][2] == 5000)   
    {
        if(tabWin[i][0] == SIGN::SEVEN)           winStatTab[22]++;  // 4x seven
        else if(tabWin[i][0] == SIGN::SCATTER)    winStatTab[23]++;  // 5x scatter
    }           
    else if(tabWin[i][2] == 25000)                winStatTab[24]++; // 5x seven
    }
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

    for (int j = 0; j < NR_ROW; j++)
    {
        for ( int i = 0; i < NR_COLUMN; i++)
        {
            printf("%d, ", lotteryResultTab[i][j]);  
        }
        printf("\n");
    }
    printf("\n");
}
void Game::setRate(int rate)
{
    rateLos = rate;
    if(rateLos >= 100)
        rateEdit = rateLos /100;
}
int Game::getRate()
{
    return rateLos;
}
int Game::getMoney()
{
   return endResultLottery;
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
