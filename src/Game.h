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

    int resultLottery[20];
    int stawka              = 1;
    int loopGame            = 1;
    int startMoney          = 10000;
    int endResultLottery    = 0;
   
public:
    struct Statistics
    {
        int winNumber;
        int RTP;
        int tabSignWin_Rate[2];
    };
    int tabSignWin[2];
    Game();
    void    setStatiscic();
    void    checkResultGame();
    void    clear();
    
    void    showLotteryResult(); 
    void    showWinLine();
    
    void    setRate(int rate);
    int     getRate();

    void    setStartMoney(int money);
    int     getStartMoney();
    
    void    setLoopGames(int loop);
    int     getLoopGame();

    Statistics& getStatistics() {
        return stats;         // Zwracanie referencji do obiektu
    }
    private:
    Statistics stats;
};

