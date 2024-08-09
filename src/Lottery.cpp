/*
 * Lottery.cpp
 *
 *  Created on: 5 sie 2024
 *      Author: Matys
 */
#include "Lottery.h"

Lottery::Lottery() 
{	
	for (int j = 0; j < NR_COLUMN; j++)
	{	
		for (int i = 0; i < NR_SYMBOLS; i++)
		{
			setValueVector(i, volatilitTab[j][i],j);// set lottery machine
		}
	}
}
void Lottery::setValueVector(int Sign, int numberTick, int numberRolls)
{
	for (int i = 0; i < numberTick; i++)
		volatilit[numberRolls].push_back(Sign);
		
#ifdef DEBUG_LOTTERY
	// cout << "Ilosc " << Sign << " to : " << numberTick << "\n";
#endif
}
//------------------------------------------------------
void Lottery::startLottery()
//------------------------------------------------------
{
	int value = 0;
	int iterTAB = 0;
	bool scatter = false;

	for (int j = 0; j < NR_COLUMN; j++)
	{
		scatter = false;

	for (int i = 0; i < NR_ROW; i++)
	{
			do
			{
				iterTAB = rand() % volatilit[j].size();  // lottery
				value = volatilit[j][iterTAB];
			} 
			while (value == 0 && scatter); 			  // one scatter in row

			if (value == 0 && !scatter) 			
			{
				scatter = true; 					
			}

			lotteryResultTab[j][i] = value;
	}
#ifdef DEBUG_LOTTERY 
for (int i = 0; i < NR_ROW; i++)
		cout<< " " << lotteryResultTab[j][i];

		cout << "\n";
#endif
	}
}
//------------------------------------------
//vector <int> Lottery::getValueTab(int nume)
//{
//	return volatilit[];
//}
//
//int Lottery::getTab(uint16_t iterator)
//{
//	for (int i = 0; i < 5; i++) 
//	{
//		convertTab[i] = tab[i][0];
//	}
//	for (int i = 0; i < 5; i++) 
//	{
//		convertTab[i+5] = tab[i][1];
//	}
//	for (int i = 0; i < 5; i++) 
//	{
//		convertTab[i+10] = tab[i][2];
//	}
//#ifdef DEBUG_LOTTERY
//	cout << "TabelaConvert\n ";
//	for (int i = 0; i < 15; i++) {
//		if (i == 5 || i == 10)
//			printf("\n");
//		cout << convertTab[i]<<", ";
//	}
//#endif
//	return convertTab[iterator];
//}
