#include <iostream>

using namespace std;

int main(void)
{
	char chTemp = 0;
	int iCount = 0;
	bool bSpace = false;

	chTemp = getchar();
	if (' ' == chTemp)
		bSpace = true;

	while ('\n' != chTemp)
	{
		chTemp = getchar();

		if ((!bSpace && ' ' == chTemp) || (!bSpace && '\n' == chTemp))
		{
			++iCount;
			bSpace = true;
		}
		else
		{
			bSpace = false;
		}
	}

	cout << iCount;

	return 0;
}