#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int>& checked, vector<vector<int>>& graph, const int& idx, int& cnt)
{
	checked[idx] = cnt++;
	for (const int nextIdx : graph[idx])
	{
		if (!checked[nextIdx])
			DFS(checked, graph, nextIdx, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> checked;
	vector<vector<int>> graph;
	int n{}, m{}, r{}, node1{}, node2{}, order{ 1 };
	
	cin >> n >> m >> r;
	graph.resize(n + 1);
	checked.resize(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(checked, graph, r, order);

	for (int i = 1; i <= n; i++)
		cout << checked[i] << "\n";

	return 0;
}