#include <iostream>

#define NUM 6

using namespace std;

int main(void)
{
	int iInput = 0;;
	int arrStd[NUM] = {1, 1, 2, 2, 2, 8};

	for (int i = 0; i < NUM; ++i)
	{
		do {
			cin >> iInput;
		} while (0 > iInput || 10 < iInput);

		if (arrStd[i] < iInput) 
			cout << arrStd[i] - iInput << " ";
		else  
			cout << arrStd[i] - iInput << " ";
	}
}
