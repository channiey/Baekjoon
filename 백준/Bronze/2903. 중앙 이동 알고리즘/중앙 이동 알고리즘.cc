#include <iostream>
#include <cmath>

int main()
{
	int iN = 0;

	std::cin >> iN;

	/*	
		Test Case				1		2		3		4	


		(A)	한 행의 정사각형 갯수	1		2		4		8	:	2의 n승
		
		(B)	한 행의 점의 갯수		2		3		5		9	:	(A) + 1
	
		(C)	전체 점의 갯수			4		9		25		81	:	(B)의 제곱 = 2의 n승 + 1의 제곱

	*/

	std::cout << (int)pow(pow(2, iN) + 1, 2);

	return 0;
}