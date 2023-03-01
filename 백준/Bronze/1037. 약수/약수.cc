#include <iostream>

using namespace std;

int main(void)
{
	int iMin = 1000000, iMax = 0, iTemp;
	int iCount = 0;
	int iA = 0, iB = 0;

	cin >> iCount;

	if (1 == iCount)
	{
		cin >> iTemp;
		cout << iTemp * iTemp;
		return 0;
	}

	for (int i = 0; i < iCount; ++i)
	{
		cin >> iTemp;

		iMin = (iMin > iTemp) ? iTemp : iMin;
		iMax = (iMax < iTemp) ? iTemp : iMax;
	}
	cout << iMin * iMax;
	
	return 0;
}