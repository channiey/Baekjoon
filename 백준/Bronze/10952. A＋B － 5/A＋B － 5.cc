#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int iTemp1(0), iTemp2(0);
	
	vector <int> vSum;

	while (1)
	{
	
		cin >> iTemp1;
		cin >> iTemp2;

		if ((iTemp1 == 0) && (iTemp2 == 0)) 
			break;

		if ((0 < iTemp1) && (iTemp2 < 10)) 
			vSum.push_back(iTemp1 + iTemp2);
	}

	for (int i = 0; i < vSum.size(); ++i)
	{
		cout << vSum[i] << "\n";
	}

	return 0;
}	