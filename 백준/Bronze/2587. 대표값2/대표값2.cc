#include <iostream>

int main()
{
	const int max{ 5 };

	int Bucket[9]{};
	int acc{}, input{};

	for (int i = 0; i < max; i++) 
	{
		std::cin >> input;
		
		++Bucket[input / 10 - 1]; // Radix Sort 개념 사용
	
		acc += input;
	}

	std::cout << acc / max << std::endl;

	for (int i = 0, j = 0; i < 9; i++) 
	{
		if (max / 2 < j + Bucket[i])
		{
			std::cout << (i + 1) * 10;
			break;
		}
		else
			j += Bucket[i];
	}

	return 0;
}
