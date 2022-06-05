#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define SIZE 10000

int Get_NotSelfNum(int iN); // 문제에서의 d(n)

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> vecSelfNum, vecNotSelfNum;
	int iTemp(0), index(0);

	// 10,000이하의 셀프넘버가 아닌 수들을 구함 (vecNotSelfNum 세팅)
	for (int i = 0; i <= SIZE; ++i)
	{
		iTemp = Get_NotSelfNum(i);

		if (iTemp <= SIZE)
			vecNotSelfNum.push_back(iTemp);
	}
	
	// SIZE만큼의 또 다른 벡터 생성 (vecSelfNum 세팅)
	for (int i = 0; i <= SIZE; ++i)
	{
		vecSelfNum.push_back(i);
	}

	// 셀프넘버 세팅 (vecSelfNum에서 vecNotSelfNum을 빼주는 형식)
	for (int i = 0; i < vecNotSelfNum.size(); ++i)
	{
		index = vecNotSelfNum[i];

		vecSelfNum[index] = NULL;
	}

	// 셀프넘버 출력
	for (int i = 0; i < vecSelfNum.size(); ++i)
	{
		if (vecSelfNum[i] != NULL)
			cout << vecSelfNum[i] << "\n";
	}

	return 0;
}

int Get_NotSelfNum(int iN)
{
	int iSum(iN), iTemp(0);

	for (int i = 4; i >= 0; --i)
	{
		iSum += iN / pow(10, i);
		if (iN != iSum)
		{
			iTemp = (iN / pow(10, i));
			iN -= iTemp * pow(10, i);
		}
	}

	return iSum;
}