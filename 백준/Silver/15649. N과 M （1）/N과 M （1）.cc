#include <iostream>
#include <vector>	
#include <queue>
using namespace std;

void Print(queue<int>& Prev)
{
	while (Prev.size())
	{
		cout << Prev.front() << " ";
		Prev.pop();
	}

	cout << "\n";
}

void Backtracking(const int& index, const int& max, queue<int> Prev, vector<bool> Checked)
{
	Prev.push(index);

	if (Prev.size() >= max)
		return Print(Prev);

	for (int i = 1; i < Checked.size(); i++)
	{
		if (!Checked[i])
		{
			Checked[i] = true;
			Backtracking(i, max, Prev, Checked);
			Checked[i] = false;
		}
	}
}

int main()
{
	int n{}, m{};
 
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		vector<bool> Checked(n + 1, false);
		queue<int> Prev;
		Checked[i] = true;
		Backtracking(i, m, Prev, Checked);
	}
	return 0;
}