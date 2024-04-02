#include <iostream>	
#include <vector>
#include <memory.h>

using namespace std;

#define MAX 100001

bool Checked[MAX]{};
vector<pair<int, int>> Nodes[MAX];
int maxNode{}, maxDist{};

void DFS(const int& node, const int& dist)
{
	if (Checked[node])
		return;

	if (maxDist < dist)
	{
		maxDist = dist;
		maxNode = node;
	}
	
	Checked[node] = true;

	for (size_t i = 0; i < Nodes[node].size(); i++)
	{
		const int n{ Nodes[node][i].first };
		const int d{ dist + Nodes[node][i].second };
		DFS(n, d);
	}
}

int main()
{
	int numOfNode{}, node{}, adjcent{}, dist{};
	cin >> numOfNode;

	for (int i = 1; i <= numOfNode; i++)
	{
		cin >> node >> adjcent;

		while (adjcent != -1)
		{
			cin >> dist;
			Nodes[node].push_back({ adjcent, dist });
			cin >> adjcent;
		}
	}

	DFS(1, 0);
	memset(Checked, false, sizeof(Checked));
	maxDist = 0;
	DFS(maxNode, 0);
	
	cout << maxDist;

	return 0;
}