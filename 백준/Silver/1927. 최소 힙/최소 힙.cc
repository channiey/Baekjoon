#include <iostream>
#include <vector>	
#include <algorithm>
using namespace std;

void Insert(vector<int>& heap, const int& data)
{
	heap.push_back(data);

	int child{ int(heap.size()) - 1 };
	int parent{ (child - 1) / 2 };

	if (2 <= heap.size())
	{
		while (0 <= parent && heap[child] < heap[parent])
		{
			swap(heap[child], heap[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
	}
}

const int Delete(vector<int>& heap)
{
	if (heap.empty())
		return 0;

	const int min{ heap.front() };
	heap.front() = heap.back();
	heap.pop_back();

	int parent{ 0 }, smallest{ 0 }, left{ 1 }, right{ 2 };

	while (true)
	{
		smallest = parent;

		if (left < heap.size() && heap[left] < heap[smallest])
			smallest = left;

		if (right < heap.size() && heap[right] < heap[smallest])
			smallest = right;

		if (smallest != parent)
		{
			swap(heap[smallest], heap[parent]);

			parent = smallest;
			left = parent * 2 + 1;
			right = parent * 2 + 2;
		}
		else
			break;
	}

	return min;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{}, x{};
	vector<int> MinHeap;

	cin >> n;

	while (n--)
	{
		cin >> x;

		if (0 == x)
			cout << Delete(MinHeap) << "\n";
		else
			Insert(MinHeap, x);
	}

	return 0;
}