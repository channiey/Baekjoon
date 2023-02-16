#include <iostream>

using namespace std;

int main(void)
{
	int iLow = 0;
	int iHigh = 0;
	int iSum = 0;
	int iMinimum = 0;
	bool bPrime = true;

	do {
		cin >> iLow;
		cin >> iHigh;
	} while (1 > iLow || 1 > iHigh || iLow > iHigh || 10000 < iLow || 10000 < iHigh);

	for (int i = iLow; i <= iHigh; ++i) // 주어진 값을 모두 순환한다.
	{
		if (1 == i)
			continue;

		bPrime = true;
		for (int j = 2; j < i; ++j) // 주어진 수 n을 2 ~ n-1 의 값으로 순서대로 나눈다.
		{
			if (2 == i)
				continue;
			if (i % j == 0)
			{
				bPrime = false;
				break;
			}
		}
		if (bPrime)
		{
			if (0 == iSum)
				iMinimum = i;

			iSum += i;
		}
	}
	if (0 == iSum)
		cout << -1;
	else
	{
		cout << iSum << endl;
		cout << iMinimum << endl;
	}
	return 0;
}