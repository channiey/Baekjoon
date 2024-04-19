#include <iostream>
using namespace std;

#define MAX 14

bool isUsedCol[MAX]{};
bool isUsedRightUp[MAX * 2 - 1]{};
bool isUsedRightDown[MAX * 2 - 1]{};

void Func(const int& row, const int& max, int& cnt)
{
	if (max <= row)
	{
		++cnt;
		return;
	}

	for (int col = 0; col < max; col++)
	{
		const int rightUp{ row + col };
		const int rightDown{ row - col + max - 1 };

		if (isUsedCol[col] || isUsedRightUp[rightUp] || isUsedRightDown[rightDown])
			continue;

		isUsedCol[col] = true; 
		isUsedRightUp[rightUp] = true; 
		isUsedRightDown[rightDown] = true;

		Func(row + 1, max, cnt);

		isUsedCol[col] = false; 
		isUsedRightUp[rightUp] = false;
		isUsedRightDown[rightDown] = false;
	}
}

int main()
{
	int n{}, cnt{};
	cin >> n;

	Func(0, n, cnt);

	cout << cnt;

	return 0;
}