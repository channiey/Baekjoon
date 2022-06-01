#include <iostream>
using namespace std;

int main(void)
{
	int A(0), B(0);

	do
	{
		cin >> A >> B;
	} while ((A < -10000) || (10000 < B));

	if (A > B)
		cout << ">";
	else if (A < B)
		cout << "<";
	else
		cout << "==";
	
	return 0;
}