#include <iostream>

int main()
{
	int iN{}, iM{}, iSum{}, iMax{};

	std::cin >> iN >> iM;
	
	int* arr = new int[iN];

	for (int i = 0; i < iN; ++i)
	{
		std::cin >> arr[i];
	}

	for (int i = 0; i < iN - 2; ++i)
	{
		for (int j = i + 1; j < iN - 1; ++j)
		{
			for (int k = j + 1; k < iN; ++k)
			{
				iSum = arr[i] + arr[j] + arr[k];

				if (iSum <= iM && iMax < iSum)
					iMax = iSum;
			}
		}
	}

	delete[] arr;

	std::cout << iMax;

	return 0;
}
