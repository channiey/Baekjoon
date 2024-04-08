#include <iostream>
#include <cmath>

const long long HashFunction(const char* arr, const int& size)
{
	const int r{ 31 }, m{ 1234567891 };
	long long acc{};

	for (int i = 0; i < size; i++)
		acc += int(arr[i] - 'a' + 1) * (long long)pow(r, i);

	return acc % m;
}

int main()
{
	int len{};
	std::cin >> len;

	char* arr = new char[len] {};	
	for (int i = 0; i < len; i++)
		std::cin >> arr[i];

	std::cout << HashFunction(arr, len);
	
	delete[] arr;
	return 0;
}