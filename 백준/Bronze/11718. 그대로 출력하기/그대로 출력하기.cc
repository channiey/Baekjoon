#include <iostream>
#include <string>
#include <string.h>

int main()
{
	std::string strInput;

	while (true)
	{
		getline(std::cin, strInput);

		if ("" == strInput)
			break;

		std::cout << strInput << std::endl;
	}

	return 0;
}