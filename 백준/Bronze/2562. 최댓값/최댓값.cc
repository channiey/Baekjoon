#include <iostream>
using namespace std;

#define SIZE 9

int main(void)
{
	int iMax(0), iIndex(0);
	int* arr = new int[SIZE];
	
	for (int i = 0; i < SIZE; ++i)
	{
		do
		{
			cin >> arr[i];
		} while ((arr[i] < 1) || (100 < arr[i]));

		if (iMax < arr[i])
		{
			iMax = arr[i];
			iIndex = i+1;
		}
	}

	cout << iMax << "\n" << iIndex;

	delete[] arr;

	return 0;
}