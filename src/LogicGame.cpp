#include "LogicGame.h"


LogicGame::LogicGame()
{
   for (int i = 0; i < NR_PAY_LINE; i++)
        for (int j = 0; j < 2; j++)
            tabWin[i][j] = 0;
}
//--------------------------------------
void LogicGame::oneLotteryResult()
//--------------------------------------
{
    Lottery::startLottery();            //losowanie
    for (int i = 0; i < NR_PAY_LINE; i++)
    {
        if( i == 0 )
        {
            checkScatter();             //szukanie scatter
        }
        else
        {

            checkPayLine(i);            //przeglad wyszskich lini wygrywajacych
        }
    }      
}
//--------------------------------------
void LogicGame::staticTabCheck(vector<int> tab)
{//podaj vector statycznego losowania size[15]
for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if( i == 0 ) lotteryResultTab[i][j] = tab[j];
            if( i == 1 ) lotteryResultTab[i][j] = tab[j+5];
            if( i == 2 ) lotteryResultTab[i][j] = tab[j+10];
        }
    }                     
    for (int i = 0; i < NR_PAY_LINE; i++)
    {
        if( i == 0 )
        {
            checkScatter();      //szukanie scatter
        }
        else
        {

            checkPayLine(i);            //przeglad wyszskich lini wygrywajacych
        }
    }     
}
void LogicGame::checkScatter()
{
    int scatterNr = 0;
    for (int i = 0; i < NR_COLUMN; i++)
    {
        for (int j = 0; j < NR_ROW; j++)
        {
                if (lotteryResultTab[i][j] == 0) 
                {
                    scatterNr++;
                    break;
                }
        }

    }
    tabWin[0][0]= 0;
    tabWin[0][1]= scatterNr;
    tabWin[0][2]= getMoneyLine(0,scatterNr);

#ifdef DEBUG 
    cout << "Tab[" << 0 << "]Sign = " << tabWin[0][0] << "\n";
    cout << "Tab[" << 0 << "]   X = " << tabWin[0][1] << "\n";
    cout << "Tab[" << 0 << "] Win = " << tabWin[0][2] << "\n";
#endif
}
void LogicGame::checkPayLine(int iterator)
{

    int paySign;
    int multiplier;

    for (int i = 0; i < NR_COLUMN; i++)
    {
         if (i == 0)
         {
             paySign = lotteryResultTab[i][PayLine[iterator][i] - 1]; // win place in first roll
             multiplier = i;
         }
         else
         {
             if (paySign == lotteryResultTab[i][PayLine[iterator][i] - 1])// next sign is the same?
             {
                 multiplier = i; // win
             }
             else
             {
                 break;     // end
             }
         }
    }
    
    tabWin[iterator][0] = paySign;
    tabWin[iterator][1] = multiplier+1;
    tabWin[iterator][2] = getMoneyLine(paySign,multiplier);

#ifdef DEBUG 
    // cout << "Tab[" << iterator << "]Sign = " << tabWin[iterator][0] << "/100\n";
    // cout << "Tab[" << iterator << "]   X = " << tabWin[iterator][1] << "/100\n";
    // cout << "Tab[" << iterator << "] Win = " << tabWin[iterator][2] << "/100\n";
   #endif
}
double LogicGame::getMoneyLine(int symbol_win, int multiplier_win) 
{
    #ifdef DEBUG 
    if(Rates[multiplier_win][symbol_win] > 0)
    cout << "Wygrana ? result"<< Rates[multiplier_win][symbol_win] << " /100\n";
   #endif
    

    return Rates[multiplier_win][symbol_win];
}
// void LogicGame::checkPayLine(int iterator)
// {
//     int paySign;
//     int multiplier;
//     for (int i = 0; i < 5; i++)
//     {
//          if (i == 0)
//          {
//              paySign = lotteryResultTab[i][PayLine[iterator][i] - 1]; // win place in first roll
//              multiplier = i + 1;
//          }
//          else
//          {
//              if (paySign == lotteryResultTab[i][PayLine[iterator][i] - 1])// next sign is the same?
//              {
//                  multiplier = i + 1; // win
//              }
//              else
//              {
//                  break;     // end
//              }
//          }
//     }
//     tabWin[iterator][0] = paySign;
//     tabWin[iterator][1] = multiplier;
// #ifdef DEBUG 
//     cout << "Tab[" << iterator << "] = " << paySign << "\n";
//     cout << "Tab[" << iterator << "] = " << multiplier << "\n";
//    #endif
// }
// void LogicGame::showWinLine()
// {
//    for (int i = 0; i < 20; ++i)
//     {
//         for (int k = 0; k < 5; ++k)
//             {                
//                 if (PayLine[i][k] == 0)
//                 {
//                     cout << PayLine[i][k] << " ";
//                 }
//                 else
//                     cout << "\033[41m" << PayLine[i][k] << " ";
//                     cout << "\033[0m";
//             }
//     } 
// }
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

