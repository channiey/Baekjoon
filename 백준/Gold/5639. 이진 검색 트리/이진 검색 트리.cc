#include <iostream>
#include <vector>
using namespace std;

void PrintPostorder(const vector<int>& Nodes, const int& start, const int& end)
{
	if (start > end)
		return;

	const int parent{ Nodes[start] };

	int index{ start + 1 };
	for (; index <= end; index++)
	{
		if (parent < Nodes[index])
			break;
	}

	PrintPostorder(Nodes, start + 1, index - 1);
	PrintPostorder(Nodes, index, end);
	cout << parent << "\n";
}

int main()
{
	int num{};
	vector<int> Nodes;
	
	while (cin >> num)
		Nodes.push_back(num);
	
	PrintPostorder(Nodes, 0, Nodes.size() - 1);

	return 0;
}