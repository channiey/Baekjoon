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

	for (int i = iN; i > 0; --i)
	{
		cout << i << "\n";
	}
	return 0;
}