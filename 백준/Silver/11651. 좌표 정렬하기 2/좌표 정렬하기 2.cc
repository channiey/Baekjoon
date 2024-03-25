#include<iostream>

struct COORD
{
	int x{}, y{};
};

void Swap(COORD* Data, const int& n, const int& m);

void HeapSort(COORD* Data, const int& size);

void Heapify(COORD* Data, const int& size, const int& parent);

int main()
{
	int size{};

	std::cin >> size;

	COORD* Coords = new COORD[size];

	for (int i = 0; i < size; i++)
		std::cin >> Coords[i].x >> Coords[i].y;

	HeapSort(Coords, size);

	for (int i = 0; i < size; i++)
		std::cout << Coords[i].x << " " << Coords[i].y << "\n";

	delete[] Coords;
	
	return 0;
}

void Swap(COORD* Data, const int& n, const int& m)
{
	const COORD temp{ Data[n] };
	Data[n] = Data[m];
	Data[m] = temp;
}

void HeapSort(COORD* Data, const int& size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(Data, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		Swap(Data, 0, i);
		Heapify(Data, i, 0);
	}
}

void Heapify(COORD* Data, const int& size, const int& parent)
{
	int largest{ parent };

	const int left{ 2 * parent + 1 }, right{ 2 * parent + 2 };

	if (left < size)
	{
		if (Data[largest].y < Data[left].y ||
			(Data[largest].y == Data[left].y && Data[largest].x < Data[left].x))
			largest = left;
	}

	if (right < size)
	{
		if (Data[largest].y < Data[right].y ||
			(Data[largest].y == Data[right].y && Data[largest].x < Data[right].x))
			largest = right;
	}

	if (parent != largest)
	{
		Swap(Data, parent, largest);
		Heapify(Data, size, largest);
	}

	return;
}
