#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n{}, m{};
	std::cin >> n >> m;

	int* AccTable = new int[n + 1] {};
	
	int t{};
	for (int i = 1; i <= n; i++)	
	{
		std::cin >> t;
		AccTable[i] = AccTable[i - 1] + t;
	}

	int i{}, j{};
	while (m--)
	{
		std::cin >> i >> j;
		std::cout << AccTable[j] - AccTable[i - 1] << "\n";
	}

	delete[] AccTable;
	return 0;
}