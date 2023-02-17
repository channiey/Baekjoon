#include <iostream>

#define NUM 10
#define DIVIDE 42

using namespace std;

int main(void)
{
	int arrNum[NUM] = {};
	int iInput = 0, iDifCount = 0, iRemain = 0;

	for (size_t i = 0; i < NUM; ++i)
	{
		do
		{
			cin >> iInput;
		} while (0 > iInput || 1000 < iInput);

		iRemain = (iInput % DIVIDE);
		arrNum[i] = iRemain;

		for (size_t j = 0; j < i; ++j)
		{
			if (iRemain == arrNum[j])
			{
				arrNum[i] = -1;
				++iDifCount;
				break;
			}
		}
	}

	cout << NUM - iDifCount;
	return 0;
}