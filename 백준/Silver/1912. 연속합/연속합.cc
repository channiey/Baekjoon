#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	int n{}, acc{}, max{};
	cin >> n;

	vector<int> Table(n, 0);
	for (int i = 0; i < n; i++)
		cin >> Table[i];

	max = acc = Table.front();

	for (int i = 1; i < n; i++)
	{
		if(Table[i] < acc + Table[i])
			acc += Table[i];
		else
			acc = Table[i];

		if (max < acc)
			max = acc;
	}

	cout << max;
		
	return 0;
}