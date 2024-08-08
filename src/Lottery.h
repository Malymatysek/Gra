
#include <iostream>
#include <vector>
// #define ROW 3
// #define COL 5 
// #define SYM 8
// #define PAY_LINE 20
// #define RATE 9
//#define DEBUG 

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
		{ 2, 20, 15, 10, 10,  5, 5, 1 },// roll 1
		{ 2, 20, 15 ,10, 10,  5, 5, 1 },// roll 2
		{ 1, 30, 20, 15, 20, 15, 1, 1 },// roll 3
		{ 1, 40, 30, 25, 20, 10, 1, 1 },// roll 4
		{ 1, 50, 40, 30, 20, 10, 1, 1 } // roll 5
	};
	vector < int > volatilit[NR_COLUMN];
	void setValueVector(int Sign,int numberTick,  int numberRolls);

protected:

	int lotteryResultTab[NR_COLUMN][NR_ROW];

public:

	Lottery();
	void startLottery();
};

