#include <iostream>
using namespace std;

int main(void)
{
	int iYear(0);

	do
	{
		cin >> iYear;
	} while ((iYear < 1) || (4000 < iYear));

	if (((iYear % 4 == 0) && (iYear % 100 != 0))
		|| ((iYear % 4 == 0) && (iYear % 400 == 0)))
		cout << 1;
	else
		cout << 0;

	return 0;
}