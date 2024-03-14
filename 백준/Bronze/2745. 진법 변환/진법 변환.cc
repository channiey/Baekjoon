#include <iostream>
#include <string>

using namespace std;

const int MyPow(int iBase, int iRep)
{
	int iResult = 1;

	while (iRep)
	{
		if (iRep & 1)
			iResult *= iBase;
		iRep >>= 1;
		iBase *= iBase;
	}
	
	return iResult;
}

int main()
{
	int iBase = 0, iResult = 0;
	string strNumber;

	std::cin >> strNumber >> iBase;

	for (size_t i = 0; i < strNumber.length(); i++)
	{
		int iBase_10 = strNumber[i];

		if (isdigit(strNumber[i]))
			iBase_10 = strNumber[i] - '0';
		else
			iBase_10 = iBase_10 - 'A' + 10;

		iResult += iBase_10 * MyPow(iBase, strNumber.length() - i - 1);
	}
	
	cout << iResult;

	return 0;
}