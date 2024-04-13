/*
	1 ~ N까지 자연수 중에서 길이가 M인 수열을 모두 구하라

	중복 수열 제외, 같은 수는 여러번 골라도 된다.
	출력 순서는 오름차순이다.
*/

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

	for (int i = 1; i <= max; i++)
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