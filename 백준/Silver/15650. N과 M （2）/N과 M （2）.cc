#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CombineSequence(vector<int>& visited, const string& acc,
	const int& idx, const int& len)
{
	if (len <= acc.size())
	{
		for (const char& ch : acc)
			cout << ch << " ";

		cout << "\n";
		return;
	}

	for (int i = idx; i < visited.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			CombineSequence(visited, acc + to_string(i), i, len);
			visited[i] = false;
		}
	}
}

int main()
{
	int n{}, m{};
	cin >> n >> m;

	vector<int> visited;
	visited.resize(n + 1, false);

	CombineSequence(visited, string{}, 1, m);

	return 0;
}