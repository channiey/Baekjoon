#include <iostream>

using namespace std;

int main(void)
{
	long long iA = 0, iB = 0, iC = 0;

	do
	{
		cin >> iA >> iB >> iC;
	} while (1 > iA || 1 > iB || 1 > iC || 1000000000000 < iA || 1000000000000 < iB || 1000000000000 < iC);

	cout << iA + iB + iC << endl;

	return 0;
}