/*
 * Game.cpp
 *
 *  Created on: 5 sie 2024
 *      Author: Matys
 */
#include "Game.h"

Game::Game()
{   
    for (int i = 0; i < NR_WINS; i++)
        winStatTab[i] = 0;

    for (int x = 0; x < NR_PAY_LINE; x++)
        resultLottery[x] = 0;
}
//--------------------------------
void Game::checkResultGame() 
///--------------------------------
{
    LogicGame::oneLotteryResult(); 
    
    clearResult();
    
    symbolWinStat();        //write stats win symbols
        
    for (int i = 0; i < NR_PAY_LINE; i++)
    {
        resultLottery[i] = rateEdit * tabWin[i][2];//rateEdit = rate / 100 // result one pay line one lottery
        endResultLottery = endResultLottery + resultLottery[i];            // result all pay line one lottery
    }

       

    startMoney = startMoney - rateLos;                      // money - rate

    loseResult = loseResult + rateLos;                      // sum lose rate

    winResult  =  winResult + endResultLottery;             // sum winning

    startMoney = startMoney + endResultLottery;             // sum money + win money

    endResultLottery == 0 ? lose++ : win++;                 // counter win lose
    
    HF = (double)win / (double)(loseResult/100);            // factor HF
    
    RTP = (double)winResult / (double)loseResult ;          // factor RTP

    // cout    << " Wygrana "           << endResultLottery 
    //         << " SumaWygranych "     << winResult 
    //         << " Stracone_Pieniadze "<< loseResult 
    //         << " Suma Konta "        << startMoney 
    //         << " Bilans "            << winResult-loseResult 
    //         << " Wygrane "           << win
    //         << " Przegrane-"         << lose 
    //         << " HF "                << HF
    //         << " RTP "               << RTP
    //         <<endl;
    

#ifdef DEBUG_GAME 
    for (int j = 0; j < NR_PAY_LINE; j++)
    {
        endResultLottery += resultLottery[j];
        cout << " TabResultLine[" << j << "]: " << resultLottery[j] << endl;
    }
#endif 
}
//--------------------------------------------------
void Game::showStats()
//--------------------------------------------------
{
    cout
        << "Symbol   | LiczTraf | LiczbaTrafien%  | SumaWygranej | Cal.war.% | 1(w))" <<endl                                                                               //dzielenie przez zero!!                 //dzielenie przez zero!!
        << "Cherry X2   " << winStatTab[0]<<"      "<<(double)winStatTab[0]/loopGame<<"% |  x0.25 Suma "<< (double)winStatTab[0] * 0.25 <<"        "<< (double)winResult/((double)winStatTab[0] * 0.25)<<"  "<< (double)loopGame/winStatTab[0] <<endl

        << "Cherry X3   " << winStatTab[1]<<"       "<<(double)winStatTab[1]/loopGame<<"% |  x1.00 Suma "<< (double)winStatTab[1] * 1 <<"        "<< (double)winResult/((double)winStatTab[1] * 1.0)<<"        "<<(double) loopGame/winStatTab[1] << endl
        << "Lemon  X3   " << winStatTab[2]<<"       "<<(double)winStatTab[2]/loopGame<<"% |  x1.00 Suma "<< (double)winStatTab[2] * 1 <<"        "<< (double)winResult/((double)winStatTab[2] * 1.0)<<"        "<< (double)loopGame/winStatTab[2]<< endl
        << "Orange X3   " << winStatTab[3]<<"       "<<(double)winStatTab[3]/loopGame<<"% |  x1.00 Suma "<< (double)winStatTab[3] * 1 <<"        "<< (double)winResult/((double)winStatTab[3] * 1.0)<<"        "<< (double)loopGame/winStatTab[3]<< endl
        << "Plum   X3   " << winStatTab[4]<<"       "<<(double)winStatTab[4]/loopGame<<"% |  x1.00 Suma "<< (double)winStatTab[4] * 1 <<"        "<< (double)winResult/((double)winStatTab[4] * 1.0)<<"        "<< (double)loopGame/winStatTab[4]<< endl
        << "ScatterX3   " << winStatTab[5]<<"       "<<(double)winStatTab[5]/loopGame<<"% |  x2.00 Suma "<< (double)winStatTab[5] * 2 <<"        "<< (double)winResult/((double)winStatTab[5] * 2.0)<<"        "<< (double)loopGame/winStatTab[5]<< endl
        << "Grapes X3   " << winStatTab[6]<<"       "<<(double)winStatTab[6]/loopGame<<"% | x2.50 Suma "<< (double)winStatTab[6] * 2.5 <<"           "<< (double)winResult/((double)winStatTab[6] * 2.5)<<"        "<< (double)loopGame/winStatTab[6]<< endl
        << "WatermeX3   " << winStatTab[7]<<"        "<<(double)winStatTab[7]/loopGame<<"% |  x2.50 Suma "<< (double)winStatTab[7] * 2.5 <<"        "<< (double)winResult/((double)winStatTab[7] * 2.5)<<"        "<< (double)loopGame/winStatTab[7]<< endl

        << "Cherry X4   " << winStatTab[8]<<"       "<<(double)winStatTab[8]/loopGame<<"% |  x2.50 Suma "<< (double)winStatTab[8] * 2.5 <<"        "<< (double)winResult/((double)winStatTab[8] * 2.5)<<"        "<< (double)loopGame/winStatTab[8]<< endl
        << "Lemon  X4   " << winStatTab[9]<<"        "<<(double)winStatTab[9]/loopGame<<"% |  x2.50 Suma "<< (double)winStatTab[9] * 2.5 <<"        "<< (double)winResult/((double)winStatTab[9] * 2.5)<<"        "<< (double)loopGame/winStatTab[9]<< endl
        << "Orange X4   " << winStatTab[10]<<"         "<<(double)winStatTab[10]/loopGame<<"% |  x2.50 Suma "<< (double)winStatTab[10] * 2.5 <<"        "<< (double)winResult/((double)winStatTab[10] * 2.5)<<"     "<< (double)loopGame/winStatTab[10]<<endl
        << "Plum   X4   " << winStatTab[11]<<"        "<<(double)winStatTab[11]/loopGame<<"% |  x2.50 Suma "<< (double)winStatTab[11] * 2.5 <<"        "<< (double)winResult/((double)winStatTab[11] * 2.5)<<"        "<< (double)loopGame/winStatTab[11]<< endl

        << "Seven  X3   " << winStatTab[12]<<"        "<<(double)winStatTab[12]/loopGame<<"% |  x5.00 Suma "<< (double)winStatTab[12] * 5.0 <<"        "<< (double)winResult/((double)winStatTab[12] * 5.0)<<"        "<< (double)loopGame/winStatTab[12]<< endl

        << "Grapes X4   " << winStatTab[13]<<"         "<<(double)winStatTab[12]/loopGame<< "% |  x10.00 Suma "<< (double)winStatTab[13] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[13] * 10.0)<<"        "<< (double)loopGame/winStatTab[13]<< endl
        << "WatermeX4   " << winStatTab[14]<<"        "<<(double)winStatTab[13]/loopGame<<"% |  x10.00 Suma "<< (double)winStatTab[14] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[14] * 10.0)<<"      "<< (double)loopGame/winStatTab[13]<< endl
        << "ScatterX4   " << winStatTab[15]<<"        "<< (double)winStatTab[14]/loopGame<<"% |  x10.00 Suma "<< (double)winStatTab[15] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[15] * 10.0)<<"      "<< (double)loopGame/winStatTab[13]<< endl

        << "Cherry X5   " << winStatTab[16]<<"        "<<(double)winStatTab[16]/loopGame<< "% |  x10.00 Suma "<< (double)winStatTab[16] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[16] * 10.0)<<"        "<< (double)loopGame/winStatTab[16]<< endl
        << "Lemon  X5   " << winStatTab[17]<<"        "<<(double)winStatTab[17]/loopGame<< "% |  x10.00 Suma "<< (double)winStatTab[17] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[17] * 10.0)<<"        "<< (double)loopGame/winStatTab[17]<< endl
        << "Orange X5   " << winStatTab[18]<<"        "<<(double)winStatTab[18]/loopGame<< "% |  x10.00 Suma "<< (double)winStatTab[18] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[18] * 10.0)<<"        "<< (double)loopGame/winStatTab[18]<< endl
        << "Plum   X5   " << winStatTab[19]<<"        "<<(double)winStatTab[19]/loopGame<< "% |  x10.00 Suma "<< (double)winStatTab[19] * 10.0 <<"        "<< (double)winResult/((double)winStatTab[19] * 10.0)<<"        "<< (double)loopGame/winStatTab[19]<< endl
        << "Grapes X5   " << winStatTab[20]<<"        "<<(double)winStatTab[20]/loopGame<< "% |  x25.00 Suma "<< (double)winStatTab[20] * 25.0 <<"        "<< (double)winResult/((double)winStatTab[20] * 25.0)<<"        "<< (double)loopGame/winStatTab[20]<< endl
        << "WatermeX5   " << winStatTab[21]<<"        "<<(double)winStatTab[21]/loopGame<< "% |  x25.00 Suma "<< (double)winStatTab[21] * 25.0 <<"        "<< (double)winResult/((double)winStatTab[21] * 25.0)<<"        "<< (double)loopGame/winStatTab[21]<< endl

        << "Seven  X4   " << winStatTab[22]<<"        "<<(double)winStatTab[22]/loopGame<< "% |  x50.00 Suma "<< (double)winStatTab[22] * 50.0 <<"        "<< (double)winResult/((double)winStatTab[22] * 50.0)<<"        "<< (double)loopGame/winStatTab[22]<< endl
        << "ScatterX5   " << winStatTab[23]<<"        "<<(double)winStatTab[23]/loopGame<< "% |  x50.00 Suma "<< (double)winStatTab[23] * 50.0 <<"        "<< (double)winResult/((double)winStatTab[23] * 50.0)<<"        "<< (double)loopGame/winStatTab[23]<< endl

        << "Seven  X5   " << winStatTab[24]<<"        "<<(double)winStatTab[24]/loopGame<< "% |  x250.00 Suma "<< (double)winStatTab[24] * 250.0 <<"        "<< (double)winResult/((double)winStatTab[24] * 250.0)<<"        "<< (double)loopGame/winStatTab[24]<< endl ;

#ifdef DEBUG_GAME   
    for (int j = 0; j < 25; j++)
    {
        cout << " TabResultLine[" << j << "]: " << winStatTab[j] << endl;
    }
#endif 
}
void Game::showResult()
{
        cout   
            << " Suma Wygranych "    << winResult               <<endl
            << " Suma Stawek    "       << loseResult              <<endl
            << " Bilans         "            << winResult-loseResult    <<endl
            << " Stan Konta     "        << startMoney              <<endl
            << " Wygrane        "           << win                     <<endl
            << " Przegrane      "         << lose                    <<endl
            << " HF  "                << HF      << " %"         <<endl
            << " RTP "               << RTP     << " %"         <<endl;    
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
        if(tabWin[i][0] == SIGN::GRAPES)         winStatTab[13]++;  // 4x grapes
        else if(tabWin[i][0] == SIGN::WATERLEMON)winStatTab[14]++;  // 4x watermelon
        else if(tabWin[i][0] == SIGN::SCATTER)   winStatTab[15]++;  // 4x scatter
        else if(tabWin[i][0] == SIGN::CHERRY)    winStatTab[16]++;  // 5x chery             
        else if(tabWin[i][0] == SIGN::LEMON)     winStatTab[17]++;  // 5x lemon    
        else if(tabWin[i][0] == SIGN::ORANGE)    winStatTab[18]++;  // 5x orange
        else if(tabWin[i][0] == SIGN::PLUM)      winStatTab[19]++;  // 5x plum
    } 
    else if(tabWin[i][2] == 2500)   
    {
        if(tabWin[i][0] == SIGN::GRAPES)         winStatTab[20]++;  // 5x grapes
        else if(tabWin[i][0] == SIGN::WATERLEMON)winStatTab[21]++;  // 5x watermelon
    }            
    else if(tabWin[i][2] == 5000)   
    {
        if(tabWin[i][0] == SIGN::SEVEN)          winStatTab[22]++;  // 4x seven
        else if(tabWin[i][0] == SIGN::SCATTER)   winStatTab[23]++;  // 5x scatter
    }           
    else if(tabWin[i][2] == 25000)               winStatTab[24]++; // 5x seven
    }
}
void Game::clearResult()
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
