#include <iostream>	
#include <vector>

using namespace std;

const bool IsPerfect(const int& iInput, vector<int>& _vecDivisor);
void PrintDivisors(const int& iInput, const vector<int>& _vecDivisor);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iInput = 0;
	vector<int> vecDivisor;

	while (true)
	{
		cin >> iInput;

		if (-1 == iInput) break;

		if (IsPerfect(iInput, vecDivisor))
			PrintDivisors(iInput, vecDivisor);
		else
			cout << iInput << " is NOT perfect.";

		cout << endl;

		vecDivisor.clear();
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

void PrintDivisors(const int& iInput, const vector<int>& _vecDivisor)
{
	cout << iInput << " = ";

	for (int iDivisor : _vecDivisor)
	{
		cout << iDivisor;

		if (iDivisor != _vecDivisor.back())
			cout << " + ";
	}
}
