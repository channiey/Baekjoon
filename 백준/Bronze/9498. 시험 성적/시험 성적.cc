#include <iostream>
using namespace std;

int main(void)
{
	int iScore(0);

	do
	{
		cin >> iScore;
	} while ((iScore < 0) || (100 < iScore));

	if (90 <= iScore)
		cout << "A";
	else if (80 <= iScore)
		cout << "B";
	else if (70 <= iScore)
		cout << "C";
	else if (60 <= iScore)
		cout << "D";
	else
		cout << "F";
    
	return 0;
}