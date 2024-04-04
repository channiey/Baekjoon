#include <iostream>
#include <vector>
using namespace std;

const long long GetLength(const int& n)
{
	if (3 >= n)
		return 1;
	else if (5 >= n)
		return 2;
	
	vector<long long> Table(n + 1, 0);

	Table[1] = Table[2] = Table[3] = 1;
	Table[4] = Table[5] = 2;

	for (int i = 6; i <= n; i++)
		Table[i] = Table[i - 1] + Table[i - 5];

	return Table.back();
}

int main()
{
	int t{}, n{};
	
	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << GetLength(n) << "\n";
	}
	return 0;
}