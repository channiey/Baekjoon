#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int iN(0), iScore(0), iPlus(1);
	bool bFlag(0);

	char chTemp;

	// GetandCalculate_Datas
	cin >> iN;
	cin.get();

	int* arr = new int[iN];
	for (int i = 0; i < iN; ++i)
	{
		cin.get(chTemp); // Get a Line
		while (chTemp != '\n')
		{
			if (chTemp == 'O')
			{
				if (!bFlag) // successive
				{
					iScore++;
					bFlag = true;
					iPlus++;
				}
				else // not successive
				{
					iScore += iPlus;
					iPlus++;
				}
			}
			else
			{
				bFlag = false;
				iPlus = 1;
			}
			cin.get(chTemp);
		}
		arr[i] = iScore; // Initialize Variables
		bFlag = false;
		iScore = 0;
		iPlus = 1;
	}

	// Print_Result
	for (int i = 0; i < iN; ++i)
	{
		cout << arr[i] << "\n";
	}

	delete[] arr;

	return 0;
}