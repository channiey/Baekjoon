#include <iostream>
#include <cmath>
using namespace std;

void Get_Datas(int arrN[], int& iMul);

void Calculate_Datas(int arrZtoT[], int arrMul[], int& iMul, int& iSize);

void Print_Results(int arrZtoT[]);

int main(void)
{
	int* arrN = new int[3];
	int* arrZtoT = new int[10]();
	int iMul(1), iSize(0);

	Get_Datas(arrN, iMul);

	iSize = int(log10(iMul) + 1);
	int* arrMul = new int[iSize];

	Calculate_Datas(arrZtoT, arrMul, iMul, iSize);

	Print_Results(arrZtoT);

	delete[] arrN;
	delete[] arrZtoT;

	return 0;
}

void Get_Datas(int arrN[], int& iMul)
{
	for (int i = 0; i < 3; ++i)
	{
		do
		{
			cin >> arrN[i];
		} while ((arrN[i] < 100) || (1000 <= arrN[i]));

		iMul *= arrN[i];
	}
}

void Calculate_Datas(int arrZtoT[], int arrMul[], int& iMul, int& iSize)
{
	for (int i = 0, j = iSize; j > 0; ++i, --j)
	{
		if (i == 0)
		{
			arrMul[i] = iMul / pow(10, j - 1);
			continue;
		}

		iMul -= (arrMul[i - 1] * pow(10, j));

		arrMul[i] = iMul / pow(10, j - 1);
	}

	for (int i = 0; i < iSize; ++i)
	{
		switch (arrMul[i])
		{
			case 0: arrZtoT[0]++;
				break;
			case 1: arrZtoT[1]++;
				break;
			case 2: arrZtoT[2]++;
				break;
			case 3: arrZtoT[3]++;
				break;
			case 4: arrZtoT[4]++;
				break;
			case 5: arrZtoT[5]++;
				break;
			case 6: arrZtoT[6]++;
				break;
			case 7: arrZtoT[7]++;
				break;
			case 8: arrZtoT[8]++;
				break;
			case 9: arrZtoT[9]++;
				break;
		}
	}
}

void Print_Results(int arrZtoT[])
{
	for (int i = 0; i < 10; ++i)
	{
		cout << arrZtoT[i] << "\n";
	}
}