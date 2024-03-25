#include <iostream>

void Swap(int* Data, const int& n, const int& m);

void HeapSort(int* Data, const int& size);

void Heapify(int* Data, const int& size, const int& parent);

int main()
{
	int num{};

	std::cin >> num;

	int* Data = new int[num];

	for (int i = 0; i < num; i++)
		std::cin >> Data[i];

	HeapSort(Data, num);

	for (int i = 0; i < num; i++)
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

void HeapSort(int* Data, const int& size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(Data, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		Swap(Data, 0, i);
		Heapify(Data, i, 0);
	}
}

void Heapify(int* Data, const int& size, const int& parent)
{
	int largest{ parent };

	int left{ 2 * parent + 1 }, right{ 2 * parent + 2 };

	if (left < size && Data[largest] < Data[left])
		largest = left;

	if (right < size && Data[largest] < Data[right])
		largest = right;

	if (parent != largest)
	{
		Swap(Data, parent, largest);
		Heapify(Data, size, largest);
	}

	return;
}
