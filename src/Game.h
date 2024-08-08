/*
 * Game.h
 *
 *  Created on: 4 sie 2024
 *      Author: Matys
 */
#include <iostream>
#include <unistd.h>
#include "LogicGame.h"

using namespace std;

class Game : public LogicGame
{
private:

    int loopGame                = 1;
    double resultLottery[20];
    double rateLos              = 20;
    double startMoney           = 10000;
    double endResultLottery     = 0;
    double loseResult           = 0;
    double winResult            = 0;
public:

    Game();
    void    setStatiscic();
    void    checkResultGame();
    void    clear();
    
    void    showLotteryResult(); 
    void    showWinLine();
    
    void    setRate(double rate);
    double  getRate();

    void    setStartMoney(double money);
    double  getStartMoney();
    
    void    setLoopGames(int loop);
    int     getLoopGame();

    // Statistics& getStatistics() {
    //     return stats;         // Zwracanie referencji do obiektu
    // }
    // private:
    // Statistics stats;
};

