#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<int>& visitCount, vector<vector<int>>& graph,
	const int& start)
{
	int order{ 1 };
	queue<int> q;

	visitCount[start] = order++;
	q.push(start);

	while (q.size())
	{
		const int idx{ q.front() };
		q.pop();

		for (const int& nextIdx : graph[idx])
		{
			if (!visitCount[nextIdx])
			{
				visitCount[nextIdx] = order++;
				q.push(nextIdx);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{}, m{}, r{}, order{1}, node1{}, node2{};
	cin >> n >> m >> r;

	vector<vector<int>> graph;
	vector<int> visitCount;

	graph.resize(n + 1);
	visitCount.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end(), greater<>());

	BFS(visitCount, graph, r);

	for (int i = 1; i <= n; i++)
		cout << visitCount[i] << "\n";

	return 0;
}