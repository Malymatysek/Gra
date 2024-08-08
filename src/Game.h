/*
 * Game.h
 *
 *  Created on: 4 sie 2024
 *      Author: Matys
 */
#include <iostream>
#include <unistd.h>
#include "LogicGame.h"
// #define DEBUG
using namespace std;

class Game : public LogicGame
{
private:
    int loopGame                = 100;
    int resultLottery[NR_PAY_LINE];
    int rateLos              = 100;
    int rateEdit             = 1;
    int startMoney           = 10000;
    int endResultLottery     = 0;
    int loseResult           = 0;
    int winResult            = 0;
    int statistic[100][3];
    int winStatTab[25];
public:

    Game();
    void    setStatiscic();
    void    checkResultGame();
    void    clear();
    void    showStats();
    void    showLotteryResult(); 
    void    showWinLine();
    
    void    setRate(int rate);
    int     getRate();

    void    setStartMoney(int money);
    int  getStartMoney();
    
    void    setLoopGames(int loop);
    int     getLoopGame();
    void    symbolWinStat();
    int     getMoney();
    // Statistics& getStatistics() {
    //     return stats;         // Zwracanie referencji do obiektu
    // }
    // private:
    // Statistics stats;
};

