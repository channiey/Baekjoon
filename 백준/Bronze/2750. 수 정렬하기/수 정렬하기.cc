#include <iostream>

using namespace std;

inline void Swap(int* _pA, int* _pB) { int iTemp = *_pA; *_pA = *_pB; *_pB = iTemp; }
void BubbleSort(int* _pArr, const int _iSize);
void PrintArr(int* _pArr, const int _iSize);

int main (void)
{
	int iN = 0, iTemp = 0;
	do
	{
		cin >> iN;
	} while (1 > iN || 1000 < iN);

	int *arr = new int[iN];

	for (int i = 0; i < iN; ++i)
	{
		do
		{
			cin >> iTemp;
		} while (-1000 > iTemp || 1000 < iTemp);

		arr[i] = iTemp;
	}

	BubbleSort(arr, iN);

	PrintArr(arr, iN);

	delete[] arr;

	return 0;
}

void BubbleSort(int* _pArr, const int _iSize)
{
	for (int i = 0; i < _iSize - 1; ++i)
	{
		for (int j = 0; j < _iSize - 1 - i; ++j)
		{
			if (_pArr[j] > _pArr[j + 1])
				Swap(&_pArr[j], &_pArr[j + 1]);
		}
	}
}

void PrintArr(int* _pArr, const int _iSize)
{
	for (int i = 0; i < _iSize; ++i)
	{
		cout << _pArr[i] << endl;
	}
}