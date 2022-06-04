#include <iostream>
using namespace std;

#define SIZE 3

int main(void)
{
	int arr[SIZE];
	bool bFlag(0);
	int iSamecount(0), iSamenumber(0), iMax(0);

	// 주사위 3개를 배열에 입력받음
	for (int i = 0; i < SIZE; ++i)
	{
		do
		{
			cin >> arr[i];

		} while ((arr[i] < 1) || (6 < arr[i]));
	}

	// 배열에 똑같은 숫자가 몇 번 있는지 체크
	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = i + 1; j < SIZE; ++j)
		{
			if ((arr[i] == arr[j]) && (!bFlag))
			{
				iSamecount += 2;
				bFlag = !bFlag;
				iSamenumber = arr[i];
				
			}
			else if ((arr[i] == arr[j]) && (bFlag))
			{
				iSamecount++;
				bFlag = !bFlag;
				iSamenumber = arr[i];
			}
		}
		if (iSamecount == SIZE)
			break;
	}

	// 결과 출력
	switch (iSamecount)
	{
		case 0: 
			iMax = arr[0];
			for (int i = 1; i < SIZE; ++i)
			{
				iMax = (iMax < arr[i]) ? arr[i] : iMax;
			}
			cout << iMax * 100;
			break;

		case 2: cout << 1000 + iSamenumber * 100;
			break;

		case 3: cout << 10000 + iSamenumber * 1000;
			break;
	}

	return 0;
}