#include <iostream>
#include <cmath>
using namespace std;

int Get_Number(); // 사용자로부터 양의 정수 N을 입력 받음

int Calculate_Keyword (int iN); // 1 ~ N의 숫자 중에 한수의 갯수를 카운트

int main(void)
{
	int iN(0), iCount(0);

	iN = Get_Number();
	
	iCount = Calculate_Keyword(iN);

	cout << iCount;

	return 0;
}

int Get_Number()
{
	int iN(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (1000 < iN));

	return iN;
}

int Calculate_Keyword(int iN)
{
	int iCount(0), iSize(0), iTemp1(0), iTemp2(0), iDif(0);

	// 1 ~ iN 반복, 한수를 찾으면 iCount++
	for (int i = 1; i <= iN; ++i) 
	{
		// iN을 자릿수별로 나눠 동적 배열에 저장
		iTemp1 = i;

		iSize = log10(i) + 1; 

		int* arrTemp = new int[iSize]; 

		for (int j = iSize - 1, k = 0; j >= 0; --j, ++k) 
		{
			arrTemp[k] = iTemp1 / pow(10, j);
			iTemp2 = iTemp1 / pow(10, j);
			iTemp1 -= iTemp2 * pow(10, j);
		}


		// 위 배열을 이용하여, 숫자 iN의 각 자리수가 등차수열을 이루는지 판별 
		if ((iSize == 1) || (iSize == 2)) 
			iCount++;
		else 
		{
			iDif = arrTemp[1] - arrTemp[0];
			for (int i = 2; i < iSize; ++i)
			{
				if (iDif != arrTemp[i] - arrTemp[i - 1]) 
					break;

				iDif = arrTemp[i] - arrTemp[i - 1];

				if (i == iSize - 1)
					iCount++;
			}
		}

		iDif = 0;
		delete[] arrTemp;
	}

	return iCount;
}