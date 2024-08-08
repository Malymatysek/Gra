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
            return multiplier_win * WinningRates[WIN_RATES::Val_25];  
        }  //25 
        if (multiplier_win == BONUS::_x4)
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_10];
        } //10
        if (multiplier_win == BONUS::_x3) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_2_5];
        } //2.5 
    }
    else if (symbol_win == SIGN::SEVEN)
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_250];
        }   //250 
        if (multiplier_win == BONUS::_x4) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_50];
        }  //50 
        if (multiplier_win == BONUS::_x3) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_5]; 
        }   //5 
    }
    else if (symbol_win == SIGN::SCATTER)
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_50];
        } //50 
        if (multiplier_win == BONUS::_x4) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_10]; 
        } //10
        if (multiplier_win == BONUS::_x3) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_2]; 
        } //2 
    }
   // if (symbol_win == (SIGN::CHERRY || SIGN::LEMON || SIGN::ORANGE || SIGN::PLUM))
    else
    {
        if (multiplier_win == BONUS::_x5) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_10];
        }    //10 
        if (multiplier_win == BONUS::_x4) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_2_5];
        }    //2.5 
        if (multiplier_win == BONUS::_x3) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_1];
        }     //1 
        if (multiplier_win == BONUS::_x2 && SIGN::CHERRY == symbol_win) 
        { 
            return multiplier_win * WinningRates[WIN_RATES::Val_0_25];
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
//void LogicGame::isWinline(/*int tab[5][3]*/)
//{// 0 sprawdziæ w osobnej funkcji
//    int winSign = 0;
//    int bonus = 0;
//    for (int i = 0; i < 20; ++i)//linie wygrywaj¹ce
//    {
//        winSign = 0;
//        bonus = 0;
//        for (int k = 0; k < 5; ++k) //zmiana bebna
//        {
//
//            for (int j = 0; j < 3; ++j)//iteracja bebna
//            {
//                if (j == 0 && CheckLineWin[i][j][k] == 1)// sprawdziæ gdzie na bebnie jest 1 
//                {                                        // na pierewszym bebnie
//                    winSign = tab[k][j];                // zapisaæ jaki w tym miejscy jest znak
//                    bonus = 1;
//                    break;                              //zmieniæ beben
//                }
//                else if (CheckLineWin[i][j][k] == 1)    //znaleæ na 2 bebnie '1'
//                {
//                    if (winSign == tab[k][j])           //sprawdziæ czy znak tam jest taki sam jak poprzedni
//                    {
//                        bonus++;
//                    }
//                    else                // ++ albo break;
//                    {
//                       break;
//                    }  
//                }
//                
//              
//            }
//            //zmiana bebna
//        }
//        //linie wygrywaj¹ce
//    }
//
//    // po wszystkich liniach
//}
//uint32_t LogicGame::checkWinSymbolInLine()
//{
//    for (int i = 0; i < 20; ++i) 
//    {
//        std::cout << "Layer " << i << ":" << std::endl;
//        for (int j = 0; j < 3; ++j)
//        {
//            for (int k = 0; k < 5; ++k) 
//            {
//                if(CheckLineWin[i][j][k] == 0)
//                {
//                    cout << CheckLineWin[i][j][k] << " ";
//                }
//                else
//                    cout << "\033[41m"<< CheckLineWin[i][j][k] << " ";                     
//                    cout << "\033[0m"; 
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }
//    //CheckLineWin
//
//
//
//
//
// return 0;
//}

//uint32_t LogicGame::checkWinLottery(uint16_t iterator, vector <uint16_t> los)
//{                                              
//    uint16_t bonus = 0;
//    uint16_t winSymbol = 0; 
//
//    bool exit = true;
//    bool firstTime = true;
//
//    for (int i = 0; i < 15; i++)
//    {
//        if (LineWin[iterator][i] == 1 && exit)  // MAX x5
//        {
//            if (firstTime)
//            {
//                winSymbol = los[i];            //zapamiêtanie wygranego symbolu
//                firstTime = false;
//                bonus = 1;                    //mno¿nik wygranej '1'               
//            }
//            if (winSymbol == los[i])
//            {
//                bonus++;
//            }
//            else
//            {
//                exit = false;
//                /*return 0;*/
//            }
//        }
//    }
//#ifdef DEBUG 
//    //tu ma byc wynik
//        if (bonus == 5)
//            cout << "\033[31mWygrana"<<winSymbol <<"X" << bonus << "  val:" << bonusValue(winSymbol, bonus)<< "\n\033[0m";
//        else if (bonus == 4)
//            cout << "\033[38;5;208mWygrana " << winSymbol << " X" << bonus << "  val:" << bonusValue(winSymbol, bonus) << "\n\033[0m";
//        else if (bonus == 3)
//            cout << "\033[33mWygrana " << winSymbol << " X" << bonus << "  val:" << bonusValue(winSymbol, bonus) << "\n\033[0m";
//        else if (bonus == 2 && winSymbol == 1) //wisienki                               
//            cout << "\033[32mWygrana " << winSymbol << " X" << bonus << " val:" << bonusValue(winSymbol, bonus) << "\n\033[0m";
//        else
//        {
//            bonus = 0;
//            cout << "PRZEGRALES " << winSymbol << " X" << bonus<< " val " << bonusValue(winSymbol, bonus) << "\n";
//        }
//#endif
//
//    return bonusValue(winSymbol, bonus) / 10; 
//}
//void LogicGame::lotteryStart()
//{
//    startLottery(); 
//   /* for (int i = 0; i < 15; i++)
//    {
//        dane.push_back(getTab(i)); 
//    } */
//}
