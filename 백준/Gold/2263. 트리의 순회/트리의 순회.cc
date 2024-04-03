#include <iostream>
#include <vector>
using namespace std;

int num{};
vector<int> Inorder, Postorder, InorderIndex;

void GetInput()
{
	cin >> num;

	Inorder.resize(num);
	Postorder.resize(num);
	InorderIndex.resize(num + 1);

	for (int i = 0; i < num; i++)
	{
		cin >> Inorder[i];
		InorderIndex[Inorder[i]] = i;
	}

	for (int i = 0; i < num; i++)
		cin >> Postorder[i];
}

void CalculatePreorder(const int& inStart, const int& inEnd, const int& postStart, const int& postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
		return;

	const int root{ Postorder[postEnd] };
	const int rootIndex{ InorderIndex[root] };
	const int leftSize{ rootIndex - inStart };
	const int rightSize{ inEnd - rootIndex };

	cout << root << " ";

	CalculatePreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1); // lc
	CalculatePreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1); // rc
}

int main()
{
	GetInput();
	CalculatePreorder(0, num - 1, 0, num - 1);

	return 0;
}