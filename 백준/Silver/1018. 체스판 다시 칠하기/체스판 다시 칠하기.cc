#include <iostream>

const int& GetMin(const int& iX, const int& iY) { return (iX < iY) ? iX : iY; }

const char arrW[8][8]
{
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
};

const char arrB[8][8]
{
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
};

char arrInput[50][50]{};

const int CalCnt(const int& iRow, const int& iCol, const bool& bStartW);

int main()
{
	int iN{}, iM{}, iCnt{}, iMin{64};

	std::cin >> iN >> iM;

	for (size_t i = 0; i < iN; i++)
	{
		for (size_t j = 0; j < iM; j++)
		{
			std::cin >> arrInput[i][j];
		}
	}

	for (size_t i = 0; i <= iN - 8; i++)
	{
		for (size_t j = 0; j <= iM - 8; j++)
		{
			iCnt = GetMin(CalCnt(i, j, true), CalCnt(i, j, false));

			iMin = (iCnt < iMin) ? iCnt : iMin;
		}
	}

	std::cout << iMin;

	return 0;
}

const int CalCnt(const int& iRow, const int& iCol, const bool& bStartW)
{
	int iCnt{};

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (bStartW)
			{
				if (arrW[i][j] != arrInput[iRow + i][iCol + j])
					++iCnt;
			}
			else
			{
				if (arrB[i][j] != arrInput[iRow + i][iCol + j])
					++iCnt;
			}
		}
	}

	return iCnt;
}
