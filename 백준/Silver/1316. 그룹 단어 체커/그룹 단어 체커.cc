#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iInput = 0;
	int iResult = 0;
	string strInput;

	cin >> iInput;
	iResult = iInput;

	while (iInput--)
	{
		cin >> strInput;

		bool bUsed[26] = { false };
		bUsed[strInput[0] - 'a'] = true;

		for (size_t i = 1; i < strInput.length(); ++i)
		{
			if (strInput[i - 1] != strInput[i])
			{
				if (bUsed[strInput[i] - 'a'])
				{
					--iResult;
					break;
				}
				else
					bUsed[strInput[i] - 'a'] = true;
			}
		}
	}

	cout << iResult;

	return 0;
}