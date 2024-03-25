#include <iostream>
#include <queue>

using namespace std;

void RadixSort(int* Data, const int& size, const int& maxRadix);

int main()
{
	int students{}, winners{};

	cin >> students >> winners;

	int* Scores = new int[students];

	for (int i = 0; i < students; i++)
		cin >> Scores[i];

	RadixSort(Scores, students, 10000);

	std::cout << Scores[students - winners];

	delete[] Scores;

	return 0;
}

void RadixSort(int* Data, const int& size, const int& maxRadix)
{
	queue<int> Bucket[10]{};

	for (int place = 1; place <= maxRadix; place *= 10) 
	{
		for (int i = 0; i < size; i++)
		{
			const int digit = Data[i] / place % 10;

			Bucket[digit].push(Data[i]);
		}

		for (int i = 0, j = 0; i < 10; i++) 
		{
			while (Bucket[i].size())
			{
				Data[j++] = Bucket[i].front();
				Bucket[i].pop();
			}
		}
	}
}
