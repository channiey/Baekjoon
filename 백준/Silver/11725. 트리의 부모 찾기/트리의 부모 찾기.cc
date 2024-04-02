#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(vector<int>* Graph, bool* Checked, int* Parents, const int& index)
{
	Checked[index] = true;

	for (const int i : Graph[index])
	{
		if (!Checked[i])
		{
			Checked[i] = true;
			Parents[i] = index;
			DFS(Graph, Checked, Parents, i);
		}
	}

	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t{}, n1{}, n2{};
	std::cin >> t;

	vector<int>* Graph = new vector<int>[t+1];
	bool* Checked = new bool[t + 1] {};
	int* Parents = new int[t + 1] {};

	for (size_t i = 0; i < t - 1; i++)
	{
		std::cin >> n1 >> n2;
		Graph[n1].push_back(n2);
		Graph[n2].push_back(n1);
	}

	Checked[1] = true;
	DFS(Graph, Checked, Parents, 1);

	for (size_t i = 2; i <= t; i++)
		std::cout << Parents[i] << "\n";
	
	delete[] Graph;
	delete[] Checked;
	delete[] Parents;

	return 0;
}