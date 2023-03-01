#include <iostream>

using namespace std;

int main(void)
{
	
	while (1)
	{
		int iA = 0, iB = 0;
		cin >> iA >> iB;

		if (0 == iA && 0 == iB) break;

		if (0 == (iB % iA))
			cout << "factor" << endl;
		else if (0 == (iA % iB))
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}

	return 0;
}