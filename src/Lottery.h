/*
 * Lottery.h
 *
 *  Created on: 5 sie 2024
 *      Author: Matys
 */
#include <iostream>
#include <vector>

// #define DEBUG_LOTTERY

using namespace std;
class Lottery
{
public:
	static  constexpr int NR_COLUMN = 5;
	static  constexpr int NR_ROW = 3;
	static  constexpr int NR_SYMBOLS = 8;
	static  constexpr int NR_PAY_LINE = 21; //20 + scatter
	static  constexpr int NR_RATE = 9;
	static  constexpr int NR_WINS = 25;
private:
	// int volatilitTab[NR_COLUMN][NR_SYMBOLS] = // ~~ RTP 0.8 
	// {
	// 	{ 1, 20, 9,  5,   6,  5, 4, 3  },// roll 1
	// 	{ 1,  5, 20, 4,   7,  2, 5, 2  },// roll 2
	// 	{ 1,  5, 2, 20,   6,  7, 4, 2  },// roll 3
	// 	{ 1, 15, 4,  3,   5,  2, 8, 2  },// roll 4
	// 	{ 1,  5, 5,  2,   4,  8, 4, 2  } // roll 5
	// };
	int volatilitTab[NR_COLUMN][NR_SYMBOLS] = //RTP 0.75
	{
		{ 1, 20, 9,  5,   6,  5, 4, 3  },// roll 1
		{ 1,  5, 20, 4,   7,  2, 5, 2  },// roll 2
		{ 2,  5, 2, 20,   6,  7, 4, 3  },// roll 3
		{ 1, 15, 4,  3,   5,  2, 8, 2  },// roll 4
		{ 2,  5, 5,  2,   4,  8, 4, 3  } // roll 5
	};
	vector < int > volatilit[NR_COLUMN];
	void setValueVector(int Sign,int numberTick,  int numberRolls);

protected:

	int lotteryResultTab[NR_COLUMN][NR_ROW];

public:

	Lottery();
	void startLottery();
};




