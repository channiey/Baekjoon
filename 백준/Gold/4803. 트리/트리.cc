#include <iostream>
#include <vector>
using namespace std;

const bool DFS(const vector<vector<int>>& Vertices, 
	vector<bool>& Checked, const int& index, const int& prev)
{
	if (Checked[index])
		return false;

	Checked[index] = true;

	for (const int& adjacent : Vertices[index])
	{
		if (prev == adjacent)
			continue;
		
		if (Checked[adjacent])
			return false;

		const bool res{ DFS(Vertices, Checked, adjacent, index) };

		if (!res)
			return res;
	}
	return true;
}

const int GetNumOfTree(const vector<vector<int>>& Vertices)
{
	vector<bool> Checked{};
	Checked.resize(Vertices.size(), false);

	int numOfTree{};

	for (int i = 1; i < Vertices.size(); i++)
	{
		if (Checked[i])
			continue;

		const bool res{ DFS(Vertices, Checked, i, 0) };

		if (res)
			++numOfTree;
	}

	return numOfTree;
} 

void PrintResult(const int& testcase, const int& result)
{
	cout << "Case " << testcase << ": ";
	switch (result)
	{
	case 0 :
		cout << "No trees.\n";
		break;
	case 1:
		cout << "There is one tree.\n";
		break;
	default:
		cout << "A forest of " << result << " trees.\n";
		break;
	}
}

int main()
{
	int numOfVertex{}, numOfEdge{}, numOfCase{};
	int vertex{}, adjacent{};
	cin >> numOfVertex >> numOfEdge;

	while (numOfVertex | numOfEdge)
	{
		vector<vector<int>> Vertices;
		Vertices.resize(numOfVertex + 1); 

		while (numOfEdge--)
		{
			int vertex{}, adjacent{};
			cin >> vertex >> adjacent;
			Vertices[vertex].push_back(adjacent);
			Vertices[adjacent].push_back(vertex);
		}
		
		const int result{ GetNumOfTree(Vertices) };
		PrintResult(++numOfCase, result);

		cin >> numOfVertex >> numOfEdge;
	}
	return 0;
}