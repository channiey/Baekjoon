#include <iostream>
using namespace std;

int main(void)
{
	int A, B;

	do 
	{
		cin >> A >> B;
	} while ((A < 1) || (10000 < B));

	cout << A + B << endl;
	cout << A - B << endl;
	cout << A * B << endl;
	cout << A / B << endl;
	cout << A % B << endl;

	return 0;
}