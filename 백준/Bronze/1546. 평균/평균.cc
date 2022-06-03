#include <iostream>
using namespace std;

int main(void)
{
	int iN(0);
	double iSum(0), iMax(0);

	do
	{
		cin >> iN;
	} while (1000 < iN);

	double* arr = new double[iN];

	// Get_Datas
	for (int i = 0; i < iN; ++i)
	{
		do
		{
			cin >> arr[i];
		} while ((arr[i] < 0) || (100 < arr[i]));

		iMax = (iMax < arr[i]) ? arr[i] : iMax;
	} 

	// Calculate_Datas
	for (int i = 0; i < iN; ++i)
	{
		arr[i] = arr[i] / iMax * 100;

		iSum += arr[i];
	} 

	// Print_Result
	cout << iSum / iN;

	return 0;
}