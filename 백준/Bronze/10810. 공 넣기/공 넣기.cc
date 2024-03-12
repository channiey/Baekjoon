/*

바구니 : 1 ~ N 개
공 : 1 ~ N 개 메ㅇ우 많음

가장 처음 바구니에 공 없음
1바구니당 1공

0. 앞으로 M 번째 공을 넣을 것이다.
1. 공을 넣을 바구니의 범위를 정함(연속된 번호)
2. 범위가 결정된 바구니에 모두 같은 번호의 공을 넣는다.
4. 바구니에 공이 있다면, 공을 빼고 새로 넣는다.


*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int iN = 0, iM = 0; // 바구니의 개수, 공을 넣을 횟수

	do {
		cin >> iN >> iM;
	} while (1 > iN || 100 < iN || 1 > iM || 100 < iM);

	int* arr = new int[iN] {};

	for (size_t i = 0; i < iM; ++i)
	{
		int iA = 0, iB = 0, iC = 0;

		do {
			cin >> iA >> iB >> iC;
		} while (1 > iA || iA > iB || iB > iN || 1 > iC || iC > iN);

		for (int j = iA-1; j < iB; ++j)
		{
			arr[j] = iC;
		}
	}

	for (size_t i = 0; i < iN; ++i)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}