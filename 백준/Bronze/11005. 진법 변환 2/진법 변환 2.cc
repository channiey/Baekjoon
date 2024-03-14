#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int iNumber = 0, iBase = 0;

	std::cin >> iNumber >> iBase;
	vector<int> vecResult;

	while (iNumber)
	{
		vecResult.push_back(iNumber % iBase);

		iNumber /= iBase;
	}
	
	for (int i = vecResult.size() - 1; 0 <= i;  --i)
	{
		if (9 < vecResult[i])
			cout << char('A' + vecResult[i] - 10);
		else
			cout << vecResult[i];
	}

	return 0;
}