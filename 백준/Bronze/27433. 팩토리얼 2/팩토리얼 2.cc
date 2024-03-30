#include <iostream>

const long long Factorial(const long long& value)
{
	if (1 >= value)
		return 1;

	return value * Factorial(value - 1);
}

int main()
{
	long long n{};
	std::cin >> n;

	std::cout << Factorial(n);

	return 0;
}