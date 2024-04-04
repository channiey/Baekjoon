#include <iostream>
#include <vector>
using namespace std;

const int GetNumOfCases(const int& n)
{
	vector<int> Table(n + 1, 0);

	Table[0] = Table[1] = 1;

	for (int i = 2; i <= n; i++)
		Table[i] = (Table[i - 1] + Table[i - 2]) % 15746;

	return Table.back();
}

int main()
{
	int n{};

	cin >> n;
	cout << GetNumOfCases(n) % 15746;

	return 0;
}