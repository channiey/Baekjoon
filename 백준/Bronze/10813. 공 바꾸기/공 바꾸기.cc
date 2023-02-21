#include <iostream>

using namespace std;

inline void Swap(int* _pA, int* _pB) { int iTemp = *_pA; *_pA = *_pB; *_pB = iTemp; }

int main(void)
{
	int iN = 0, iM = 0, iI = 0, iJ = 0; // iN = 바구니의 개수, iM = 공을 바꿀 횟수
	do {
		cin >> iN >> iM;
	} while (1 > iN || 100 < iN || 1 > iM || 100 < iM);

	int* pArr = new int[iN]; // 순서대로 바구니에 공을 채운다.
	for (int i = 0; i < iN; ++i) 
	{
		pArr[i] = i + 1;
	}

	for (int i = 0; i < iM; ++i) // iM번만큼 공을 바꾼다.
	{
		do {
			cin >> iI >> iJ;
		} while (1 > iI || iI > iJ || iN < iJ);

		Swap(&pArr[iI-1], &pArr[iJ-1]);
	}


	for (int i = 0; i < iN; ++i)
	{
		cout << pArr[i] << " ";
	}

	delete[] pArr;

	return 0;
}