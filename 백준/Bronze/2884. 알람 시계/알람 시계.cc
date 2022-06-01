#include <iostream>
using namespace std;

#define M_substract 45
#define H 24
#define M 60

int main(void)
{
	int iH(0), iM(0);

	do
	{
		cin >> iH >> iM;
	} while ((iH < 0) || ((H-1) < iH) || (iM < 0) || ((M-1) < iM));

	if (iM - M_substract < 0)
	{
		iH--;
		if (iH < 0)
			iH = H + iH;

		iM = M + (iM - M_substract);
	}
	else
		iM -= M_substract;

	cout << iH << " " << iM;

	return 0;
}
