#include "iostream"
#include "string.h"

int main()
{
	const int iMaxLength = 1001;

	char szText[iMaxLength] = {};
	int iIndex = 0;

	std::cin >> szText;

	do {
		std::cin >> iIndex;
	} while (1 > iIndex || strlen(szText) < iIndex || iMaxLength < iIndex);

	std::cout << szText[iIndex-1];

	return 0;
}