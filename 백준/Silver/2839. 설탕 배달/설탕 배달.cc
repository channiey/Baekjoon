#include <iostream>
using namespace std;

int Calculate_Data(int iN);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN(0);

	do
	{
		cin >> iN;
	} while (iN < 3 || 5000 < iN);
	
	cout << Calculate_Data(iN) << endl;

	return 0;
}

int Calculate_Data(int iN)
{
	int iMin (iN);

	for (int i = iN / 5; i >= 0; --i)
	{
		for (int j = iN / 3; j >= 0; --j)
		{
			if (iN - ((i * 5) + (j * 3)) == 0)
				iMin = (iMin > i + j) ? i + j : iMin;
		}
	}

	if (iMin == iN)
		return -1;
	else
		return iMin;
}
