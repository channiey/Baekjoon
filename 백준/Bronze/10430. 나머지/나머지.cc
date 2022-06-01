#include <iostream>
using namespace std;

int main(void)
{

	int A, B, C;

	do
	{
		cin >> A >> B >> C;

	} while ((A < 2) || (10000 < C));

	cout << (A + B) % C << endl;
	cout << ((A % C) + (B % C)) % C << endl;
	cout << (A * B) % C << endl;
	cout << ((A % C) * (B % C)) % C << endl;

	return 0;
}