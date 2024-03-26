#include <iostream>
#include <string>

using namespace std;

/*

	자료 개수 : 2만개 이하

	자료 : 50자내의 소문자 영단어

	정렬 기준 : 짧은 길이 -> 사전순 

	단서 조항 : 중복 제거

	조건 : 2s, 256mb

*/


void Swap(string* Data, const int& left, const int& right);

void MergeSort(string* Data, string* Sub, const int& left, const int& right);

void Merge(string* Data, string* Sub, const int& left, const int& mid, const int& right);

const int Unique(string* Data, const int& size);

int main()
{
	int num{};

	cin >> num;

	string* Data = new string[num];
	string* Sub = new string[num];

	for (int i = 0; i < num; i++)
		cin >> Data[i];
	
	MergeSort(Data, Sub, 0, num - 1);

	const int resultIndex{ Unique(Data, num) };

	for (int i = 0; i < resultIndex; i++)
		cout << Data[i] << "\n";

	delete[] Data;
	delete[] Sub;

	return 0;
}

void Swap(string* Data, const int& left, const int& right)
{
	const string temp = Data[left];
	Data[left] = Data[right];
	Data[right] = temp;
}

void MergeSort(string* Data, string* Sub, const int& left, const int& right)
{
	if (left >= right)
		return;

	const int mid{ (left + right) / 2 };

	MergeSort(Data, Sub, left, mid);
	MergeSort(Data, Sub, mid + 1, right);

	Merge(Data, Sub, left, mid, right);
}

void Merge(string* Data, string* Sub, const int& left, const int& mid, const int& right)
{
	int a{ left }, b{ mid + 1 }, sortedIndex{ left };

	while (a <= mid && b <= right)
	{
		if (Data[a].length() < Data[b].length())
			Sub[sortedIndex++] = Data[a++];
		else if (Data[a].length() == Data[b].length())
		{
			if(Data[a] < Data[b])
				Sub[sortedIndex++] = Data[a++];
			else
				Sub[sortedIndex++] = Data[b++];
		}
		else
			Sub[sortedIndex++] = Data[b++];
	}

	if (a <= mid)
	{
		for (int i = a; i <= mid; i++)
			Sub[sortedIndex++] = Data[i];
	}
	else
	{
		for (int i = b; i <= right; i++)
			Sub[sortedIndex++] = Data[i];
	}

	for (int i = left; i <= right; i++)
		Data[i] = Sub[i];
}

const int Unique(string* Data, const int& size)
{
	int resultIndex{ 1 };

	for (int i = 0; i < size - 1; i++)
	{
		if (Data[i] != Data[i + 1])
			Data[resultIndex++] = Data[i + 1];
	}

	return resultIndex;
}
