#include <iostream>

#define ALL 30
#define SUMBIT 28

using namespace std;

int main(void)
{
	int arrStudents[ALL] = {0};
	int iStudent = 0;

	// 입력을 받고, 배열에 넣는다.
	for (size_t i = 0; i < SUMBIT; i++)
	{
		do
		{
			cin >> iStudent;
		} while (1 > iStudent || 30 < iStudent);
		
		arrStudents[iStudent-1] = iStudent;
	}

	// 1부터 30까지 배열을 순회하며 해당 원소가 0인 경우, 그 자릿수를 출력한다.
	for (size_t i = 0; i < ALL; i++)
	{
		if (0 == arrStudents[i])
			cout << i+1 << endl;
	}

	return 0;
}