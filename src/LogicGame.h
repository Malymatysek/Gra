#include <iostream>
#include <vector>
#include "Lottery.h"

//#define DEBUG
using namespace std;

class LogicGame : public Lottery
{
public:
	int tabWin[NR_PAY_LINE][2];
	int scatterNr;

private:
	static constexpr int WinningRates[9] = { 25, 100, 250, 200, 500, 1000, 2500, 5000, 25000 };// podziel przez 10
	static constexpr bool	  CheckLineWin[NR_PAY_LINE][NR_ROW][NR_COLUMN] =
	{
		{
			{0,0,0,0,0},
			{1,1,1,1,1}, 
			{0,0,0,0,0}
		}, //1
		{
			{1,1,1,1,1},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}, //2
		{
			{0,0,0,0,0}, 
			{0,0,0,0,0}, 
			{1,1,1,1,1}
		}, //3
		{
			{0,0,1,0,0},
			{1,1,0,1,1},
			{0,0,0,0,0}
		}, //4
		{
			{1,0,0,0,1},
			{0,1,0,1,0},
			{0,0,1,0,0}
		}, //5
		{
			{0,0,1,0,0},
			{0,1,0,1,0},
			{1,0,0,0,1}
		}, //6
		{
			{0,1,0,1,0},
			{1,0,1,0,1},
			{0,0,0,0,0}
		}, //7
		{
			{0,0,0,0,0},
			{1,0,1,0,1},
			{0,1,0,1,0}
		}, //8
		{
			{1,1,0,0,0},
			{0,0,1,0,0},
			{0,0,0,1,1}
		}, //9
		{
			{0,0,0,1,1}, 
			{0,0,1,0,0}, 
			{1,1,0,0,0}
		}, //10
		{
			{0,0,1,0,0},
			{0,1,0,1,1},
			{1,0,0,0,0}
		}, //11
		{
			{0,0,1,1,1},
			{0,1,0,0,0},
			{1,0,0,0,0}
		}, //12
		{
			{1,0,0,0,0},
			{0,1,0,0,0},
			{0,0,1,1,1}
		}, //13
		{
			{1,0,0,0,0},
			{0,1,0,1,1},
			{0,0,1,0,0}
		}, //14
		{
			{1,0,1,0,1},
			{0,1,0,1,0},
			{0,0,0,0,0}
		}, //15
		{
			{0,0,0,0,0},
			{0,1,0,1,0},
			{1,0,1,0,1}
		}, //16
		{
			{1,1,0,0,0},
			{0,0,1,1,1},
			{0,0,0,0,0}
		}, //17
		{
			{0,0,0,0,0},
			{0,0,1,1,1},
			{1,1,0,0,0}
		}, //18
		{
			{0,0,0,0,1},
			{0,0,0,1,0},
			{1,1,1,0,0}
		}, //19
		{
			{1,1,1,0,0},
			{0,0,0,1,0},
			{0,0,0,0,1}
		}  //20

	}; 
	static constexpr int PayLine[NR_PAY_LINE][NR_COLUMN] =
	{
		{2,2,2,2,2},//1
		{1,1,1,1,1},//2
		{3,3,3,3,3},//3
		{2,2,1,2,2},//4
		{3,2,1,2,3},//5
		{2,1,2,1,2},//6
		{2,3,2,3,2},//7
		{1,1,2,3,3},//8
		{3,3,2,1,1},//9
		{3,2,1,2,2},//10
		{3,2,1,1,1},//11
		{1,2,3,3,3},//12
		{1,2,3,2,2},//13
		{1,2,1,2,1},//14
		{3,2,3,2,3},//15
		{1,1,2,2,2},//16
		{1,1,2,2,2},//17
		{3,3,2,2,2},//18
		{3,3,3,2,1},//19
		{1,1,1,2,3} //20
	};
	enum WIN_RATES
	{
		Val_0_25 = 0,
		Val_1 = 1,
		Val_2_5 = 2,
		Val_2 = 3,
		Val_5 = 4,
		Val_10 = 5,
		Val_25 = 6,
		Val_50 = 7,
		Val_250 = 8,
	};
	enum BONUS
	{
		_x2 = 2,
		_x3 = 3,
		_x4 = 4,
		_x5 = 5,
	};
	enum SIGN
	{
		SCATTER = 0,
		CHERRY = 1,
		LEMON = 2,
		ORANGE = 3,
		PLUM = 4,
		GRAPES = 5,
		WATERLEMON = 6,
		SEVEN = 7,
	};

public:

	LogicGame();

	void		init();
	void		showWinLine();
	void		checkScatter(int iterator);
	void		checkPayLine(int iterator);
	int	bonusValue(int symbol_win, int multiplier_win);


	void checkPayLineAndSet(int iterator, int *tabSignWin);
	//void isWinline(/*int tab[5][3]*/);
	/*int getWinTab();
	uint32_t checkWinSymbolInLine();
	uint32_t checkWinLottery(uint16_t iterator, vector <uint16_t> losy);*/
};