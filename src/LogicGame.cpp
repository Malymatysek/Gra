#include "LogicGame.h"


LogicGame::LogicGame()
{
    init();
}

void LogicGame::init()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 2; j++)
            tabWin[i][j] = 0;
}
void LogicGame::checkScatter(int iterator)
{
    scatterNr = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                if (lotteryResultTab[i][j] == 0) 
                {
                    scatterNr++;
                    break;
                }
        }

    }

    bonusValue(0, scatterNr);

#ifdef DEBUG 
    cout << "Tab[" << iterator << "] = " << 0 << "\n";
    cout << "Tab[" << iterator << "] = " << scatterNr << "\n";
#endif
}
void LogicGame::checkPayLineAndSet(int iterator, int *tabSignWin)
{
    int paySign;
    int multiplier;

    for (int i = 0; i < 5; i++)
    {
         if (i == 0)
         {
             paySign = lotteryResultTab[i][PayLine[iterator][i] - 1]; // win place in first roll
             multiplier = i + 1;
         }
         else
         {
             if (paySign == lotteryResultTab[i][PayLine[iterator][i] - 1])// next sign is the same?
             {
                 multiplier = i + 1; // win
             }
             else
             {
                 break;     // end
             }
         }
    }
    tabSignWin[0] = paySign;
    tabSignWin[1] = multiplier;

    tabWin[iterator][0] = paySign;
    tabWin[iterator][1] = multiplier;
#ifdef DEBUG 
    cout << "Tab[" << iterator << "] = " << paySign << "\n";
    cout << "Tab[" << iterator << "] = " << multiplier << "\n";
   #endif
}
double LogicGame::getMoneyLine(int symbol_win, int multiplier_win) 
{
    return Rates[multiplier_win][symbol_win];
}
void LogicGame::checkPayLine(int iterator)
{
    int paySign;
    int multiplier;

    for (int i = 0; i < 5; i++)
    {
         if (i == 0)
         {
             paySign = lotteryResultTab[i][PayLine[iterator][i] - 1]; // win place in first roll
             multiplier = i + 1;
         }
         else
         {
             if (paySign == lotteryResultTab[i][PayLine[iterator][i] - 1])// next sign is the same?
             {
                 multiplier = i + 1; // win
             }
             else
             {
                 break;     // end
             }
         }
    }
    tabWin[iterator][0] = paySign;
    tabWin[iterator][1] = multiplier;
#ifdef DEBUG 
    cout << "Tab[" << iterator << "] = " << paySign << "\n";
    cout << "Tab[" << iterator << "] = " << multiplier << "\n";
   #endif
}
int LogicGame::bonusValue(int symbol_win, int multiplier_win)
{
    if ((symbol_win == SIGN::GRAPES) || (symbol_win == SIGN::WATERLEMON))
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return WinningRates[WIN_RATES::Val_25];  
        }  //25 
        if (multiplier_win == BONUS::_x4)
        { 
            return  WinningRates[WIN_RATES::Val_10];
        } //10
        if (multiplier_win == BONUS::_x3) 
        { 
            return WinningRates[WIN_RATES::Val_2_5];
        } //2.5 
    }
    else if (symbol_win == SIGN::SEVEN)
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return  WinningRates[WIN_RATES::Val_250];
        }   //250 
        if (multiplier_win == BONUS::_x4) 
        { 
            return  WinningRates[WIN_RATES::Val_50];
        }  //50 
        if (multiplier_win == BONUS::_x3) 
        { 
            return  WinningRates[WIN_RATES::Val_5]; 
        }   //5 
    }
    else if (symbol_win == SIGN::SCATTER)
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return  WinningRates[WIN_RATES::Val_50];
        } //50 
        if (multiplier_win == BONUS::_x4) 
        { 
            return  WinningRates[WIN_RATES::Val_10]; 
        } //10
        if (multiplier_win == BONUS::_x3) 
        { 
            return  WinningRates[WIN_RATES::Val_2]; 
        } //2 
    }
   // if (symbol_win == (SIGN::CHERRY || SIGN::LEMON || SIGN::ORANGE || SIGN::PLUM))
    else
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return  WinningRates[WIN_RATES::Val_10];
        }    //10 
        if (multiplier_win == BONUS::_x4) 
        { 
            return WinningRates[WIN_RATES::Val_2_5];
        }    //2.5 
        if (multiplier_win == BONUS::_x3) 
        { 
            return  WinningRates[WIN_RATES::Val_1];
        }     //1 
        if (multiplier_win == BONUS::_x2 && SIGN::CHERRY == symbol_win) 
        { 
            return  WinningRates[WIN_RATES::Val_0_25];
        }  //0.25
    }
    return 0;
} 
void LogicGame::showWinLine()
{
    for (int i = 0; i < 20; ++i)
    {
        std::cout << "Layer " << i << ":" << std::endl;
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                if (CheckLineWin[i][j][k] == 0)
                {
                    cout << CheckLineWin[i][j][k] << " ";
                }
                else
                    cout << "\033[41m" << CheckLineWin[i][j][k] << " ";
                    cout << "\033[0m";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

