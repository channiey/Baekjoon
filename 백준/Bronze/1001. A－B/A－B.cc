#include <iostream>
using namespace std;

int main(void)
{
	int A, B;
	
	do
	{
		cin >> A >> B;
	} while ((A <= 0) || (B >= 10));

	cout << A - B;

	return 0;
}