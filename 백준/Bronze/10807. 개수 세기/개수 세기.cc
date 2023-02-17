#include <iostream>

using namespace std;

int main(void)
{
	int iN = 0, iV = 0, iTemp = 0, iCount = 0;

	// 배열 동적할당 선언
	do
	{
		cin >> iN;
	} while (1 > iN || 100 < iN);
	int* arrNum = new int[iN];

	// 숫자 입력 받기
	for (size_t i = 0; i < iN; i++)
	{
		do
		{
			cin >> iTemp;
		} while (-100 > iTemp || 100 < iTemp);
		arrNum[i] = iTemp;
	}

	// 찾아야 할 숫자 입력받기
	do
	{
		cin >> iV;
	} while (-100 > iTemp || 100 < iTemp);

	// 갯수 찾기
	for (size_t i = 0; i < iN; i++)
	{
		if (iV == arrNum[i])
			++iCount;
	}

	cout << iCount;

	return 0;
}
