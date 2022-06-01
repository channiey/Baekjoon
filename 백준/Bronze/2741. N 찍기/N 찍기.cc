#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (100000 < iN));

	for (int i = 1; i <= iN; ++i)
	{
		cout << i << "\n";
	}
	return 0;
}