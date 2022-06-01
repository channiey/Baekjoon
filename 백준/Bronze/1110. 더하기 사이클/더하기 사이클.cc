#include <iostream>
using namespace std;

void Set_Datas(int &iN1, int &iN2, int &iOrigin);
void Calculate_Datas(int& iN1, int& iN2, int& iOrigin, int& iFlag);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN1(0), iN2(0), iFlag(0), iOrigin(0);

	Set_Datas(iN1, iN2, iOrigin);

	Calculate_Datas(iN1, iN2, iOrigin, iFlag);

	cout << iFlag;
	
	return 0;
}

void Set_Datas(int& iN1, int& iN2, int& iOrigin)
{
	cin >> iN1;

	if (iN1 >= 10)
	{
		iN2 = iN1 % 10;
		iN1 = iN1 / 10;
	}
	else
	{
		iN2 = 0;
	}

	iOrigin = iN1 * 10 + iN2;
}

void Calculate_Datas(int& iN1, int& iN2, int& iOrigin, int& iFlag)
{
	int iTemp(0);

	while (1)
	{
		iTemp = ((iN1 + iN2) % 10);
		iN1 = iN2;
		iN2 = iTemp;

		iFlag++;

		if (iOrigin == (iN1 * 10 + iN2))
			break;
	}
}