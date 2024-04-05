#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	char alphabet{};
	int question{}, left{}, right{}, cnt{};

	cin >> str >> question;
	
	while (question--)
	{
		cin >> alphabet >> left >> right;

		for (int i = left; i <= right; i++)
		{
			if (alphabet == str[i])
				++cnt;
		}
		cout << cnt << "\n";
		cnt = 0;
	}

	return 0;
}