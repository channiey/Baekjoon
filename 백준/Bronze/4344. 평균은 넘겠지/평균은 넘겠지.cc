#include <iostream>
using namespace std;

int main(void)
{
	int iTestCaseN(0), iStudentN(0), iAvg(0), iHighRankerN(0);

	// Get Number of Testcase
	cin >> iTestCaseN;
	cin.get();

	double* arrAvgs = new double[iTestCaseN];

	// Calculate the Average per line
	for (int i = 0; i < iTestCaseN; ++i)
	{
		do 
		{
			cin >> iStudentN;

		} while ((iStudentN < 1) || (1000 < iStudentN));

		
		int* arrScores = new int[iStudentN];
		for (int j = 0; j < iStudentN; ++j) 
		{
			do
			{
				cin >> arrScores[j];
			} while ((arrScores[j] < 0) || (100 < arrScores[j]));

			iAvg += arrScores[j];
		}
		cin.get();

		iAvg /= iStudentN;
		for (int j = 0; j < iStudentN; ++j)
		{
			if (arrScores[j] > iAvg)
				iHighRankerN++;
		}

		arrAvgs[i] = double(iHighRankerN) / double(iStudentN) * 100;

		iAvg = iHighRankerN = 0;
		delete[] arrScores;
	}

	// Print the Result
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < iTestCaseN; ++i)
	{
		cout << arrAvgs[i] << "%\n";
	}

	delete[] arrAvgs;
	return 0;
}