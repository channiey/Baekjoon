#include <iostream>
#include "string.h"

const int GetDialNumber(const char& chAlphabet);

int main()
{
	// Get Input
	const int iMaxSize = 16;

	char szText[iMaxSize] = {};

	std::cin >> szText;

	const int iSize = strlen(szText);
	

	// Calculate Seconds 
	int iSeconds = 0;

	for (int i = 0; i < iSize; ++i)
		iSeconds += GetDialNumber(szText[i]) + 1;


	// Print Result
	std::cout << (int)iSeconds;

	return 0;
}

const int GetDialNumber(const char& chAlphabet)
{
	int iDialNumber = 0;

	switch (chAlphabet)
	{
	case 'A':
	case 'B':
	case 'C':
		iDialNumber = 2;
		break;

	case 'D':
	case 'E':
	case 'F':
		iDialNumber = 3;
		break;

	case 'G':
	case 'H':
	case 'I':
		iDialNumber = 4;
		break;

	case 'J':
	case 'K':
	case 'L':
		iDialNumber = 5;
		break;

	case 'M':
	case 'N':
	case 'O':
		iDialNumber = 6;
		break;

	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		iDialNumber = 7;
		break;

	case 'T':
	case 'U':
	case 'V':
		iDialNumber = 8;
		break;

	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		iDialNumber = 9;
		break;

	default:
		break;
	}

	return iDialNumber;
}