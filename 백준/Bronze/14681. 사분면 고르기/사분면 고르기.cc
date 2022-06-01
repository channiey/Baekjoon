#include <iostream>
using namespace std;

int main(void)
{
	int iPosX(0), iPosY(0);

	do
	{
		cin >> iPosX >> iPosY;
	} while (((iPosX < -1000) || (1000 < iPosX) || (iPosX == 0))
		|| ((iPosY < -1000) || (1000 < iPosY) || (iPosY == 0)));

	if (iPosX > 0)
		(iPosY > 0) ? cout << 1 : cout << 4;
	else
		(iPosY > 0) ? cout << 2 : cout << 3;

	return 0;
}
