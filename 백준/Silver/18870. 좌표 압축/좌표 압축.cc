#include <iostream>
#include <algorithm>

const int BinarySearch(int* Data, const int& left, const int& right, const int& target);

void Swap(int* Data, const int& left, const int& right);

const int Partition(int* Data, const int& left, const int& right);

void QuickSort(int* Data, const int& left, const int& right);

const int Unique(int* Data, const int& size);

int main()
{
	int num{};

	std::cin >> num;

	int* OriginData = new int[num];
	int* SortedData = new int[num];

	for (int i = 0; i < num; i++)
	{
		std::cin >> OriginData[i];
		SortedData[i] = OriginData[i];
	}

	//QuickSort(SortedData, 0, num - 1);
	std::sort(SortedData, SortedData + num);

	const int finalIndex = Unique(SortedData, num);

	for (int i = 0; i < num; i++)
		std::cout << BinarySearch(SortedData, 0, finalIndex - 1, OriginData[i]) << " ";

	delete[] OriginData;
	delete[] SortedData;

	return 0;
}

const int BinarySearch(int* Data, const int& left, const int& right, const int& target)
{
	if (left > right)
		return -1;

	const int middle{ (left + right) / 2 };

	if (target == Data[middle])
		return middle;
	else if (target <= Data[middle])
		return BinarySearch(Data, left, middle - 1, target);
	else
		return BinarySearch(Data, middle + 1, right, target);
}

void Swap(int* Data, const int& left, const int& right)
{
	const int temp{ Data[left] };
	Data[left] = Data[right];
	Data[right] = temp;
}

const int Partition(int* Data, const int& left, const int& right)
{
	const int pivot{ left };

	int L{ left + 1 }, R{ right };

	while (L <= R)
	{
		while (L <= right && Data[L] < Data[pivot])
			++L;

		while (R > left && Data[R] > Data[pivot])
			--R;

		if (L > R)
			Swap(Data, pivot, R);
		else if (L == R && Data[L] == Data[R])
			break;
		else
			Swap(Data, L, R);
	}

	return R;
}

void QuickSort(int* Data, const int& left, const int& right)
{
	if (left >= right)
		return;

	const int pivot{ Partition(Data, left, right) };

	QuickSort(Data, left, pivot - 1);
	QuickSort(Data, pivot + 1, right);
}

const int Unique(int* Data, const int& size)
{
	int resultIndex{ 1 };

	for (int i = 0; i < size - 1; i++)
	{
		if (Data[i] != Data[i + 1])
			Data[resultIndex++] = Data[i + 1];
	}

	return resultIndex;
}
