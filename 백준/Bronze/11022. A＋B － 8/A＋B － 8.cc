#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT(0);

	do
	{
		cin >> iT;
	} while (iT < 0);

	int* arr = new int[iT*2];

	for (int i = 0; i < iT*2; i+=2)
	{
		do
		{
			cin >>arr[i] >> arr[i+1];

		} while ((arr[i] <= 0) || (10 <= arr[i + 1]));

	}

	for (int i = 0, j = 1; i < iT * 2; i += 2, ++j)
	{
		cout << "Case #" << j << ": " 
			<< arr[i] << " + " << arr[i + 1] 
			<< " = " << arr[i] + arr[i + 1] << "\n";
	}
	
	delete[] arr;

	return 0;
}