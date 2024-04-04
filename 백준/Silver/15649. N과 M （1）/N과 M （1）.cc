#include <iostream>
#include <vector>
using namespace std;

void DFS(const int& cnt, const int& max, vector<int> Prev, vector<bool> Checked)
{
	if (cnt == max)
	{
		for (int i = 0; i < max; i++)
			cout << Prev[i] << " ";
		
		cout << "\n";
		return;
	}

	for (int i = 1; i < Checked.size(); i++)
	{
		if (!Checked[i])
		{
			Checked[i] = true;
			Prev[cnt] = i;
			DFS(cnt + 1, max, Prev, Checked);
			Checked[i] = false;
		}
	}
}

int main()
{
	int n{}, m{};
	cin >> n >> m;

	vector<int>Prev(m, 0);
	vector<bool>Checked(n + 1, false);
	
	DFS(0, m, Prev, Checked);
}