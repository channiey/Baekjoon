#include <iostream>

const int Fibonacci(const int& n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int n{};

	std::cin >> n;

	std::cout << Fibonacci(n);

	return 0;
}