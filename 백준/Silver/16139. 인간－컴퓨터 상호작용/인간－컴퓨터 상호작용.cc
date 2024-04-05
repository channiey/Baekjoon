#include <iostream>
#include <string>
using namespace std;

#define MAX 200000

int Table[26][MAX + 1]{}; 
// ex. Table[0][5] : 알파벳 a의, 문자열 5번까지 등장횟수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	char alphabet{};
	int question{}, left{}, right{};

	cin >> str >> question;

	// Creater Prefix Sum
	const int len{ int(str.length()) };
	for (int i = 0; i < 26; i++)
	{
		if (char('a' + i) == str[0])
			Table[i][0] = 1;

		for (int j = 1; j < len; j++)
		{
			Table[i][j] = Table[i][j - 1];

			// str의 j번째 문자열이 i인 경우
			if (char('a' + i) == str[j])
				++Table[i][j];
		}
	}

	while (question--)
	{
		cin >> alphabet >> left >> right;

		if (0 == left)
			cout << Table[alphabet - 'a'][right] << "\n";
		else
			cout << Table[alphabet - 'a'][right] - Table[alphabet - 'a'][left - 1] << "\n";
	}

	return 0;
}