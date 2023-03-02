#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][2] = {};

	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	if (arr[0][0] == arr[1][0])
		arr[3][0] = arr[2][0];
	else
	{
		if (arr[0][0] == arr[2][0])
			arr[3][0] = arr[1][0];
		else
			arr[3][0] = arr[0][0];
	}

	if (arr[0][1] == arr[1][1])
		arr[3][1] = arr[2][1];
	else
	{
		if (arr[0][1] == arr[2][1])
			arr[3][1] = arr[1][1];
		else
			arr[3][1] = arr[0][1];
	}

	cout << arr[3][0] << " " << arr[3][1];

	return 0;
}