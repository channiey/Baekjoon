#include <iostream>

using namespace std;

int main(void)
{
	// Set Data
	int iN = 0, iM = 0;

	cin >> iN >> iM;

	int** arrA = new int*[iN];
	for (int i = 0; i < iN; ++i)
		arrA[i] = new int[iM];

	int** arrB = new int* [iN];
	for (int i = 0; i < iN; ++i)
		arrB[i] = new int[iM];


	// Get Input
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			do
			{
				cin >> arrA[i][j];	

			} while (-100 > arrA[i][j] || 100 < arrA[i][j]);
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			do
			{
				cin >> arrB[i][j];

			} while (-100 > arrB[i][j] || 100 < arrB[i][j]);
		}
	}

	// Print Result
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << arrA[i][j] + arrB[i][j] << " ";
		}
		cout << endl;
	}

	// Free Memory
	for (int i = 0; i < iN; ++i)
		delete[] arrA[i];
	delete[] arrA;

	for (int i = 0; i < iN; ++i)
		delete[] arrB[i];
	delete[] arrB;
}