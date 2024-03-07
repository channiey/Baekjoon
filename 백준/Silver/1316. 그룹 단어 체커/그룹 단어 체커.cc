#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iNumberOfWholeWord = 0;
	int iNumberOfGroupWord = 0;
	string strInput;

	cin >> iNumberOfWholeWord;
	iNumberOfGroupWord = iNumberOfWholeWord;

	for (size_t i = 0; i < iNumberOfWholeWord; ++i)
	{
		cin >> strInput;

		string strSubs;
		strSubs.push_back(strInput.front());

		for (size_t j = 1; j < strInput.length(); ++j)
		{
			const char comp = *(strSubs.end() - 1);
			if (comp != strInput[j])
			{
				if (string::npos != strSubs.find(strInput[j]))
				{
					--iNumberOfGroupWord;
					break;
				}
				else
					strSubs.push_back(strInput[j]);
			}
		}
	}

	cout << iNumberOfGroupWord;

	return 0;
}