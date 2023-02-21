#include <iostream>

using namespace std;

int main(void)
{
	int iN = 0, iM = 0; 

	do {
		cin >> iN >> iM;
	} while (1 > iN || 100 < iN || 1 > iM || 100 < iM);

	int* arr = new int[iN] {};

	for (size_t i = 0; i < iM; ++i)
	{
		int iA = 0, iB = 0, iC = 0;

		do {
			cin >> iA >> iB >> iC;
		} while (1 > iA || iA > iB || iB > iN || 1 > iC || iC > iN);

		for (int j = iA-1; j < iB; ++j)
		{
			arr[j] = iC;
		}
	}

	for (size_t i = 0; i < iN; ++i)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}
