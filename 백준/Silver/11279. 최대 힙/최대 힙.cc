#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Insert(vector<unsigned int>& Heap, const unsigned int& data)
{
	Heap.push_back(data);

	int child = Heap.size() - 1;
	int parent{ (child - 1 ) / 2 };

	if (1 < Heap.size())
	{
		while (0 <= parent && Heap[child] > Heap[parent])
		{
			swap(Heap[child], Heap[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
	}
}

const unsigned int Delete(vector<unsigned int>& Heap)
{
	if (Heap.empty())
		return 0;
	
	const unsigned int top{ Heap.front() };

	Heap.front() = Heap.back();
	Heap.pop_back();

	int largest{ 0 }, parent{ 0 }, left{ 1 }, right{ 2 };

	while (true)
	{
		largest = parent;

		if (left < Heap.size() && Heap[largest] < Heap[left])
			largest = left;
		if (right < Heap.size() && Heap[largest] < Heap[right])
			largest = right;
			
		if (largest != parent)
		{
			swap(Heap[largest], Heap[parent]);

			parent = largest;
			left = parent * 2 + 1;
			right = parent * 2 + 2;
		}
		else
			break;
	}

	return top;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{};
	unsigned int x{};
	vector<unsigned int> MaxHeap;

	cin >> n;

	while (n--)
	{
		cin >> x;

		if (0 == x)
			cout << Delete(MaxHeap) << "\n";
		else
			Insert(MaxHeap, x);
	}
	return 0;
}