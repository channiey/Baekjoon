#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(vector<bool>& visited, vector<vector<int>>& graph,
	const int& idx)
{
	visited[idx] = true;

	cout << idx << " ";

	for (const int& nextIdx : graph[idx])
	{
		if (!visited[nextIdx])
			DFS(visited, graph, nextIdx);
	}
}

void BFS(vector<bool>& visited, vector<vector<int>>& graph,
	const int& start)
{
	queue<int> q;

	visited[start] = true;
	cout << start << " ";
	q.push(start);

	while (q.size())
	{
		const int idx{ q.front() };
		q.pop();

		for (const int& nextIdx : graph[idx])
		{
			if (!visited[nextIdx])
			{
				visited[nextIdx] = true;
				cout << nextIdx << " ";
				q.push(nextIdx);
			}
		}
	}
}

int main()
{
	vector<bool> visited;
	vector<vector<int>> graph;
	int n{}, m{}, v{}, t1{}, t2{};
	
	cin >> n >> m >> v;

	visited.resize(n + 1, false);
	graph.resize(n + 1);

	while (m--)
	{
		cin >> t1 >> t2;

		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	for (size_t i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(visited, graph, v);
	
	cout << "\n";
	fill(visited.begin(), visited.end(), false);

	BFS(visited, graph, v);

	return 0;
}