#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 10001

bool Checked[MAX]{};
vector<pair<int, int>> Nodes[MAX];
int maxDist{}, maxNode{};

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

	for (int i = 0; i < Nodes[node].size(); i++)
	{
		const int n{ Nodes[node][i].first };
		const int d{ dist + Nodes[node][i].second };
		
		DFS(n, d);
	}
}

int main()
{
	int num{}, parent{}, child{}, weight{};

	cin >> num;

	for (int i = 1; i < num; i++)
	{
		cin >> parent >> child >> weight;
		Nodes[parent].push_back({ child, weight });
		Nodes[child].push_back({ parent, weight });
	}

	DFS(1, 0);
	memset(Checked, 0, sizeof(Checked));
	maxDist = 0;
	DFS(maxNode, 0);

	cout << maxDist;

	return 0;
}