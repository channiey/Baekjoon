#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define SIZE 3

int main(void)
{
	int num1(0);
	int num2[3];
	int res(0);

	cin >> num1;
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%1d", &num2[i]);
	}

	for (int i = SIZE-1, k = 1; 0 <= i; --i, k*=10)
	{
		cout << num1 * num2[i] << endl;

		res += num1 * num2[i] * k;
	}
	cout << res;

	return 0;
}