#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Insert(vector<int>& heap, const int& data)
{
	heap.push_back(data);

	int child{ (int)heap.size() - 1 };
	int parent{ (child - 1) / 2 };

	if (2 <= heap.size())
	{
		while (0 <= parent && parent != child)
		{
			if (abs(heap[child]) == abs(heap[parent]))
			{
				if (heap[child] < heap[parent])
					swap(heap[child], heap[parent]);

				child = parent;
				parent = (child - 1) / 2;
			}
			else if (abs(heap[child]) < abs(heap[parent]))
			{
				swap(heap[child], heap[parent]);

				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
}

const int Delete(vector<int>& heap)
{
	if (heap.empty())
		return 0;
		
	const int value{ heap.front() };

	heap.front() = heap.back();
	heap.pop_back();

	int parent{ 0 }, smallest{ 0 }, left{ 1 }, right{ 2 };

	while (true)
	{
		if (left < heap.size())
		{
			if (abs(heap[smallest]) == abs(heap[left]))
			{
				if(heap[smallest] > heap[left])
					smallest = left;
			}
			else if (abs(heap[smallest]) > abs(heap[left]))
				smallest = left;
		}

		if (right < heap.size())
		{
			if (abs(heap[smallest]) == abs(heap[right]))
			{
				if(heap[smallest] > heap[right])
					smallest = right;
			}
			else if (abs(heap[smallest]) > abs(heap[right]))
				smallest = right;
		}

		if (parent != smallest)
		{
			swap(heap[smallest], heap[parent]);
			parent = smallest;

			left = parent * 2 + 1;
			right = parent * 2 + 2;
		}
		else
			break;
	}

	return value;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{}, x{};
	cin >> n;

	vector<int> heap;


	while (n--)
	{
		cin >> x;

		if (0 == x)
			cout << Delete(heap) << "\n";
		else
			Insert(heap, x);
	}

	return 0;
}