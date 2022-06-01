#include <iostream>
using namespace std;

#define H 24
#define M 60

void Get_Datas(int& iCurH, int& iCurM, int& iReqM);
void Calculate_Datas(int& iCurH, int& iCurM, int& iReqM);

int main(void)
{
	int iCurH(0), iCurM(0), iReqM(0);

	Get_Datas(iCurH, iCurM, iReqM);

	Calculate_Datas(iCurH, iCurM, iReqM);

	cout << iCurH << " " << iCurM;

	return 0;
}

void Get_Datas(int& iCurH, int& iCurM, int& iReqM)
{
	do
	{
		cin >> iCurH >> iCurM;
	} while ((iCurH < 0) || ((H - 1) < iCurH) || (iCurM < 0) || ((M - 1) < iCurM));

	do
	{
		cin >> iReqM;
	} while ((iReqM < 0) || (1000 < iReqM));
}

void Calculate_Datas(int& iCurH, int& iCurM, int& iReqM)
{
	if ((iReqM / M) > 0)
	{
		iCurH += (iReqM / M);
		iCurM += (iReqM % M);

		if (iCurM > M-1)
		{
			iCurH++;
			iCurM -= M;
		}

		if (iCurH > H-1)
			iCurH -= H;
	}
	else
	{
		iCurM += iReqM;
		if (iCurM > M-1)
		{
			iCurH++;
			iCurM -= M;
		}

		if (iCurH > H - 1)
			iCurH -= H;
	}
}

