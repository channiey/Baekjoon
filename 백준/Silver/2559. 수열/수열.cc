#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n{}, k{}, res{};
	cin >> n >> k;

	vector<int> AccTable(n);

	cin >> AccTable[0];
	for (int i = 1; i < n; i++)
	{	
		cin >> AccTable[i];
		AccTable[i] += AccTable[i - 1];
	}

	res = AccTable[k - 1];
	for (int i = k; i < n; i++)
		res = max(res, AccTable[i] - AccTable[i - k]);

	cout << res;

	return 0;
}