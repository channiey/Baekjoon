#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int iSize = 1024;
	int iCountAlpha = 0, iCountWord = 0;
	char szAlphabet [iSize] = {}, szWord[iSize] = {};
	
	for (int i = 'a'; i <= 'z'; ++i)
		szAlphabet[i - 'a'] = i;

	cin >> szWord;

	iCountAlpha = strlen(szAlphabet);
	iCountWord = strlen(szWord);

	for (int i = 0; i < iCountAlpha; ++i)
	{
		for (int j = 0; j < iCountWord; ++j) 
		{
			if (szAlphabet[i] == szWord[j])
			{
				cout << j << " ";
				break;
			}
			else if (iCountWord - 1 == j)
			{
				cout << -1 << " ";
			}
		}
	}
	return 0;
}