#include "Lottery.h"

Lottery::Lottery()
{	// manipulacja wynikami losowania
	for (int j = 0; j < NR_COLUMN; j++)
	{	
		for (int i = 0; i < NR_SYMBOLS; i++)
		{
			setValueVector(i, volatilitTab[j][i],j);
		}

	}
}

void Lottery::setValueVector(int Sign, int numberTick, int numberRolls)
{
	for (int i = 0; i < numberTick; i++)
		volatilit[numberRolls].push_back(Sign);
		
#ifdef DEBUG 
	cout << "Ilosc " << Sign << " to : " << numberTick << "\n";
#endif
}

void Lottery::startLottery()
{
	int value = 0;
	int iterTAB = 0;
	bool scatter = false;

	for (int j = 0; j < NR_COLUMN; j++)
	for (int i = 0; i < NR_ROW; i++)
	{
		iterTAB = rand() % volatilit[j].size();  //liczba od 0 do max vector
		value = volatilit[j][iterTAB];

		if ( value == 0 && !scatter ) // val = 0
		{
			scatter = true;
		}

		while (scatter && value == 0)	// 0 mo¿e byæ tylko raz	
		{
			iterTAB = rand() % volatilit[j].size();
			value = volatilit[j][iterTAB]; 
		}

		lotteryResultTab[j][i] = value;
#ifdef DEBUG 
		cout << "Tabela : " << lotteryResultTab[j][i] << "\n";
#endif
	}
#ifdef DEBUG 
	cout << "\n";
#endif
}

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
//#ifdef DEBUG 
//	cout << "TabelaConvert\n ";
//	for (int i = 0; i < 15; i++) {
//		if (i == 5 || i == 10)
//			printf("\n");
//		cout << convertTab[i]<<", ";
//	}
//#endif
//	return convertTab[iterator];
//}
