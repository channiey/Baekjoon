#include <iostream>	
#include <vector>

using namespace std;

const bool IsPerfect(const int& iInput, vector<int>& _vecDivisor);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iInput = 0;

	while (true)
	{
		cin >> iInput;

		if (-1 == iInput) break;

		vector<int> vecDivisor;

		if (IsPerfect(iInput, vecDivisor))
		{
			cout << iInput << " = ";

			for (int iDivisor : vecDivisor)
			{
				cout << iDivisor;

				if (iDivisor != vecDivisor.back())
					cout << " + ";
			}
		}
		else
		{
			cout << iInput << " is NOT perfect.";
		}
		cout << endl;
	}

	return 0;
}

const bool IsPerfect(const int& iInput, vector<int>& _vecDivisor)
{
	int iSum = 0;

	for (int i = 1; i < iInput; i++)
	{
		if (0 == iInput % i)
		{
			iSum += i;
			_vecDivisor.push_back(i);
		}
	}

	return (iInput == iSum);
}