#include <iostream>
using namespace std;

int main (void)
{
	int iT(0), iTemp(0);

	cin >> iT;

	int* arr = new int[iT*2];

	for (int i = 0; i < iT*2; i+=2)
	{
		do
		{
			cin >> iTemp;
			arr[i] = iTemp;

			cin >> iTemp;
			arr[i + 1] = iTemp;

		} while ((arr[i] <= 0) || (10 <= arr[i]) || (arr[i + 1] <= 0) || (10 <= arr[i + 1]));

	}
	
	for (int i = 0; i < iT * 2; i += 2)
	{
		
		cout << arr[i] + arr[i + 1] << endl;

	}

	delete[] arr;
	
	return 0;
}