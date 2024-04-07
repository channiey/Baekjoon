#include <iostream>

const long long Combination(const long long& n, const long long& r)
{
	long long res{ 1 }, factorial{ 1 };

	// permutation
	for (int i = n; i > n - r; i--)
		res *= i;

	for (int i = 1; i <= r; i++)
		factorial *= i;
	
	return res / factorial;
}

int main()
{
	long long n{}, m{}, acc{}, temp{}, cnt{};

	std::cin >> n >> m;

	long long* ModuloCnt = new long long[m] {};

	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;

		// 구간합 계산
		acc += temp;

		// 구간합에 대한 모듈로 연산값을 카운팅 (for. case.2)
		++ModuloCnt[acc % m]; 

		// case.1 (psum[i] % m == 0)
		if (0 == acc % m)
			++cnt;
	}

	for (int i = 0; i < m; i++)
	{
		// case.2 (psum[j] % m == psum[i] % m) 
		cnt += Combination(ModuloCnt[i], 2);
	}

	delete[] ModuloCnt;

	std::cout << cnt;

	return 0;
}