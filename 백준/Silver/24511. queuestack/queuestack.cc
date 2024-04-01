#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n{}, m{};
	std::cin >> n;

	bool* bStack = new bool[n] {};
	deque<int> deque;

	for (int i = 0; i < n; i++)
		cin >> bStack[i];

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		if (bStack[i])
			continue;

		deque.push_back(m);
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		deque.push_front(m);
		cout << deque.back() << " ";
		deque.pop_back();
	}

	delete[] bStack;

	return 0;
}