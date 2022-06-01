#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT(0), iTemp(0);

	do
	{
		cin >> iT;

	} while((iT < 1) || (1000000 < iT));

	int* arr = new int[iT * 2];

	for (int i = 0; i < iT * 2; i += 2)
	{
		do
		{
			cin >> iTemp;
			arr[i] = iTemp;

			cin >> iTemp;
			arr[i + 1] = iTemp;

		} while ((arr[i] < 1) || (1000 < arr[i]) || (arr[i + 1] < 1) || (1000 < arr[i + 1]));

	}

	for (int i = 0; i < iT * 2; i += 2)
	{

		cout << arr[i] + arr[i + 1] << "\n";

	}

	delete[] arr;
		
	return 0;
}