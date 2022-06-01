#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT(0), iTemp1(0), iTemp2(0);

	do
	{
		cin >> iT;
	} while (iT < 0);

	int* arr = new int[iT];

	for (int i = 0; i < iT; ++i)
	{
		do
		{
			cin >> iTemp1 >> iTemp2;

		} while ((iTemp1 <= 0) || (10 <= iTemp2));

		arr[i] = iTemp1 + iTemp2;
	}

	for (int i = 0; i < iT; ++i)
	{
		cout << "Case #" << i + 1 << ": " << arr[i] << "\n";
	}
	
	delete[] arr;

	return 0;
}