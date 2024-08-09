/*
 * Game.h
 *
 *  Created on: 5 sie 2024
 *      Author: Matys
 */
#include <iostream>
#include <unistd.h>
#include "LogicGame.h"
// #define DEBUG_GAME

using namespace std;

class Game : public LogicGame
{
private:
    int loopGame             = 100;
    int win                  = 0;
    int lose                 = 0;
    double HF                = 0.0;
    double RTP               = 0.0;
    int rateLos              = 100;
    int rateEdit             = 1;
    int startMoney           = 10000;
    int endResultLottery     = 0;
    int loseResult           = 0;
    int winResult            = 0;
    int resultLottery[NR_PAY_LINE];
    int winStatTab[NR_WINS];
public:

    Game();
    int     getMoney();
    void    checkResultGame();
    void    showStats();
    void    showLotteryResult(); 
    void    showWinLine();

    void    setRate(int rate);
    int     getRate();

    void    setStartMoney(int money);
    int     getStartMoney();
    
    void    setLoopGames(int loop);
    int     getLoopGame();

    void    showResult();
    void    symbolWinStat();

private:
    void    clearResult();
    // Statistics& getStatistics() {
    //     return stats;         // Zwracanie referencji do obiektu
    // }
    // private:
    // Statistics stats;
};

