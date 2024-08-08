
#include <iostream>
#include <vector>
// #define ROW 3
// #define COL 5 
// #define SYM 8
// #define PAY_LINE 20
// #define RATE 9
// #define DEBUG 


using namespace std;
class Lottery
{
public:
	static  constexpr int NR_COLUMN = 5;
	static  constexpr int NR_ROW = 3;
	static  constexpr int NR_SYMBOLS = 8;
	static  constexpr int NR_PAY_LINE = 21;//20+scatter
	static  constexpr int NR_RATE = 9;

private:
	int volatilitTab[NR_COLUMN][NR_SYMBOLS] =
	{
		{ 5, 21,7, 7,  7,  3, 2, 2  },// roll 1
		{ 3, 21,11, 7,  7,  2, 3, 2 },// roll 2
		{ 5, 7, 9, 13, 6,  1, 1, 2  },// roll 3
		{ 10, 3, 5, 2, 13,  3, 3, 2  },// roll 4
		{ 10, 8, 3, 5,  2,  2, 2, 2  } // roll 5
	};
	vector < int > volatilit[NR_COLUMN];
	void setValueVector(int Sign,int numberTick,  int numberRolls);

protected:

	int lotteryResultTab[NR_COLUMN][NR_ROW];

public:

	Lottery();
	void startLottery();
};




