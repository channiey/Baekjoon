#include <iostream>
#include <vector>	
using namespace std;

int main()
{
	int n{}, k{}, max{}, sum{};

	cin >> n >> k;
	vector<int> Table(n);

	for (int i = 0; i < n; i++)
		cin >> Table[i];

	for (int i = 0; i < n; i++)
	{
		sum += Table[i];
		
		if (i + 1 < k) continue; // (k == 2, i == 1, 2, 3) ( k == 5, i == 4, 5, 6)

		if (i + 1 == k)
			max = sum;
		
		if (max < sum)
			max = sum;

		const int outData{ Table[i - k + 1] };

		sum -= outData;
	}

	cout << max;

	return 0;
}