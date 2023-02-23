#include <iostream>

using namespace std;

inline void Swap(int* const _pA, int* const _pB) { int iTemp = *_pA; *_pA = *_pB; *_pB = iTemp; }

void Reverse(int* _pArr, const int _iA, const int _iB);

int main(void)
{
	int iN = 0, iM = 0, iI = 0, iJ = 0;

	do
	{
		cin >> iN >> iM;
	} while (1 > iN || 100 < iN || 1 > iM || 100 < iM);

	int* pArr = new int[iN]; // N개의 배열을 만든다.

	for (int i = 0; i < iN; ++i)
		pArr[i] = i + 1;


	for (int i = 0; i < iM; ++i) // M번 만큼 역순으로 한다.
	{
		do
		{
			cin >> iI >> iJ;
		} while (false);

		Reverse(pArr, iI - 1, iJ - 1);
	}

	for (int i = 0; i < iN; ++i)
		cout << pArr[i] << " ";

	delete[] pArr;
	return 0;
}

void Reverse(int* _pArr, const int _iA, const int _iB)
{
	for (int i = _iA, j = _iB; i < j; ++i, --j)
	{
		Swap(&_pArr[i], &_pArr[j]);
	}
}