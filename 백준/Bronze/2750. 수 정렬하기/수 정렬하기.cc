#include <iostream>

void Swap(int* Data, const int& n, const int& m);

void Heapify(int* Data, const int& size, const int& node);

void HeapSort(int* Data, const int& size);

int main()
{
	int size{};

	std::cin >> size;

	int* Data = new int[size] {};

	for (int i = 0; i < size; i++)
		std::cin >> Data[i];
	
	HeapSort(Data, size);

	for (int i = 0; i < size; i++)
		std::cout << Data[i] << "\n";

	delete[] Data;

	return 0;
}

void Swap(int* Data, const int& n, const int& m)
{
	const int temp = Data[n];
	Data[n] = Data[m];
	Data[m] = temp;
}

void Heapify(int* Data, const int& size, const int& node)
{
	int largest{ node };
	int left{ 2 * node + 1}, right{ 2 * node + 2 };

	if (left < size && Data[largest] < Data[left])
		largest = left;

	if (right < size &&Data[largest] < Data[right])
		largest = right;

	if (node != largest)
	{
		Swap(Data, node, largest);
		Heapify(Data, size, largest);
	}

	return;
}

void HeapSort(int* Data, const int& size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(Data, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		Swap(Data, 0, i);
		Heapify(Data, i, 0);
	}

	return;
}
