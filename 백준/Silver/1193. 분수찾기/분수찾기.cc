#include <iostream>

using namespace std;

int main(void)
{
	int iInput = 0, iNum = 0, iSum = 0, iX = 1, iY = 1; // iNum : 현재 숫자
	int iNumInLine = 1; // 현재 대각 라인에서의 순서 (즉, 현재 대각라인의 첫 시작이라면 1로 초기화)
	int iAllNumInLine = 1; //현재 대각 라인의 숫자 총 갯수 (현재 숫자가 4라면, 숫자 대각 라인의 숫자의 총 갯수 = 3) .. 대각 라인 숫자의 총 개수는 이전 라인에서 1씩 증가

	bool bUpRight = true; // 최초 대각 이동 방향

	do
	{
		cin >> iInput;
	} while (1 > iInput || 10000000 < iInput);

	while (iNum < iInput-1) 
	{
		++iNum;
		/*cout << "현재 숫자 : " << iNum << endl;
		cout << "현재 위치 : " << iY << " / " << iX << endl; (행렬 주의)
		cout << "현재 라인에서의 순서 : " << iNumInLine << endl;
		cout << "현재 라인에서의 총 숫자 개수 : " << iAllNumInLine << endl;*/

		if (iAllNumInLine == iNumInLine) // 가로 세로 이동
		{
			// 개수 컨트롤
			++iAllNumInLine;
			iNumInLine = 1;
			

			// 이동
			if (bUpRight) // 직전에 우상향해서 도착 = X 증가
			{
				++iX;
				//cout << "우측 이동\n\n";
			}
			else
			{
				++iY;
				//cout << "아래 이동\n\n";
			}

			// 대각 방향 체인지
			bUpRight = !bUpRight;
		}
		else // 대각선 이동 
		{
			// 이동
			if (bUpRight)
			{
				++iX;
				--iY;
				//cout << "우상향 이동\n\n";
			}
			else
			{
				--iX;
				++iY;
				//cout << "좌하향 이동\n\n";
			}

			// 개수 컨트롤
			++iNumInLine;
		}
	}
	cout << iY << "/" << iX << endl;
}