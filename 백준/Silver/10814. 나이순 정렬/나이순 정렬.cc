#include <iostream>
#include <string>	

using namespace std;

struct INFO
{
	int age{};
	string name{};
};

void MergeSort(INFO* Data, const int& left, const int& right);

void Merge(INFO* Data, const int& left, const int& middle, const int& right);

int main()
{
	int num{};
	cin >> num;

	INFO* Data = new INFO[num];

	for (int i = 0; i < num; i++)
		cin >> Data[i].age >> Data[i].name;

	MergeSort(Data, 0, num - 1);
	
	for (int i = 0; i < num; i++)
		cout << Data[i].age << " " << Data[i].name << "\n";

	delete[] Data;
	
	return 0;
}

void MergeSort(INFO* Data, const int& left, const int& right)
{
	if (left >= right)
		return;

	const int middle{ (left + right) / 2 };

	MergeSort(Data, left, middle);
	MergeSort(Data, middle + 1, right);

	Merge(Data, left, middle, right);
}

void Merge(INFO* Data, const int& left, const int& middle, const int& right)
{
	const int size = right - left + 1;

	INFO* Sorted = new INFO[size]; 

	int a{ left }, b{ middle + 1 }, sortedIndex{ 0 };

	while (a <= middle && b <= right)
	{
		if (Data[a].age <= Data[b].age)
			Sorted[sortedIndex++] = Data[a++];
		else
			Sorted[sortedIndex++] = Data[b++];
	}

	if (a <= middle)
	{
		for (int i = a; i <= middle; i++)
			Sorted[sortedIndex++] = Data[i];
	}
	else
	{
		for (int i = b; i <= right; i++)
			Sorted[sortedIndex++] = Data[i];
	}

	for (int i = left; i <= right; i++)
		Data[i] = Sorted[i - left];

	delete[] Sorted;
}
