#include <iostream>

#define MAX 1024	
int Psum[MAX + 1][MAX + 1]{};
int Input[MAX + 1][MAX + 1]{};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n{}, m{};
	int x1{}, y1{}, x2{}, y2{};
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cin >> Input[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Psum[i][j] = 
				Input[i][j] + Psum[i-1][j] + Psum[i][j-1] - Psum[i-1][j-1];
		}
	}

	while (m--)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;

		const int res = Psum[x2][y2]
			- Psum[x1 - 1][y2] - Psum[x2][y1 - 1]
			+ Psum[x1 - 1][y1 - 1];

		std::cout << res << "\n";
	}

	return 0;
}