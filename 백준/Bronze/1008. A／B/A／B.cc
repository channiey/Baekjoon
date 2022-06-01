#include <iostream>
using namespace std;

int main(void)
{
	int A, B;

	do 
	{
		cin >> A >> B;
	} while ((A <= 0) || (10 <= B));

	cout << fixed;
	cout.precision(9);

	cout << double(A) / double(B);

	return 0;
}