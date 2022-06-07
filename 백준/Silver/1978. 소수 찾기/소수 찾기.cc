#include <iostream>
#include <vector>
using namespace std;

void Get_Datas(int &iN, vector <int> &vec); // 데이터 입력 함수
int Calculate_NumOfPrime(int& iN, vector <int>& vec); // 소수 갯수 계산 함수

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN(0);
	vector <int> vec;

	Get_Datas(iN, vec);

	cout << Calculate_NumOfPrime(iN, vec);

	return 0;
}

void Get_Datas(int& iN, vector <int>& vec)
{
	int iTemp(0);

	do
	{
		cin >> iN;
	} while (100 < iN);


	for (int i = 0; i < iN; ++i)
	{
		do
		{
			cin >> iTemp;
		} while ((iTemp < 1) || (1000 < iTemp));

		vec.push_back(iTemp);
	}
}

int Calculate_NumOfPrime(int& iN, vector <int>& vec)
{
	bool bFlag(1);
	int iCount(0);

	for (int i = 0; i < iN; ++i) // 벡터의 숫자를 차례로 대입
	{
		if (vec[i] == 1) // 1일 경우 필터링 
			continue;

		for (int j = 2; j < vec[i]; ++j) // 벡터 숫자를 (1 ~ 벡터숫자-1)의 수로 나눠 소수 판단
		{
			if (vec[i] % j == 0)
			{
				bFlag = false;
				break;
			}
		}

		if (bFlag)
			iCount++;
	
		bFlag = true;
	}

	return iCount;
}