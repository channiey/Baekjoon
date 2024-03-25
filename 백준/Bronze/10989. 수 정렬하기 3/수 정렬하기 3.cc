#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int num{}, temp{};
	int Data[10001]{};

	std::cin >> num;

	// count 
	for (int i = 0; i < num; i++)
	{
		std::cin >> temp;
		++Data[temp];
	}

	// Acc
	for (int i = 1; i < 10001; i++)
	{
		Data[i] += Data[i - 1];
	}

	// Calculate
	for (int i = 1; i < 10001; i++)
	{
		if (Data[i - 1] != Data[i]) 
		{
			const int diff = Data[i] - Data[i - 1];

			for (int j = 0; j < diff; j++)
				std::cout << i << "\n";
		}
	}

	return 0;
}
