#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<bool>& isVisited, vector<vector<int>>& graph,
	const int& idx, int& cnt)
{
	isVisited[idx] = true;
	cnt++;

	for (const int& nextIdx : graph[idx])
	{
		if (!isVisited[nextIdx])
			DFS(isVisited, graph, nextIdx, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{}, m{}, cnt{}, v1{}, v2{};
	vector<bool> isVisited;
	vector<vector<int>> graph;

	cin >> n >> m;
	graph.resize(n + 1);
	isVisited.resize(n + 1);

	while(m--)
	{
		cin >> v1 >> v2;
		
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	DFS(isVisited, graph, 1, cnt);
	--cnt;

	cout << cnt;

	return 0;
}