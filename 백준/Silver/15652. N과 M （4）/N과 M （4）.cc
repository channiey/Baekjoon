#include <iostream>
#include <vector>
using namespace std;

void CombineSequence(vector<int>& sequence, const int& idx, 
	const int& len, const int& max)
{
	if (len <= idx)
	{
		for (const int& value : sequence)
			cout << value << " ";
		cout << "\n";
		return;
	}

	int i{ 1 };
	if (0 < idx)
		i = sequence[idx-1];
	for (; i <= max; i++)
	{
		sequence[idx] = i;
		CombineSequence(sequence, idx + 1, len, max);
	}
}

int main()
{
	int n{}, m{};
	cin >> n >> m;

	vector<int> sequence;
	sequence.resize(m, 1);

	CombineSequence(sequence, 0, m, n);
	return 0;
}