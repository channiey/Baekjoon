#include <iostream>

using namespace std;

int main(void)
{
	int X = 0, N = 0, a = 0, b = 0;
    int iX = 0, iN = 0;

    do {
        cin >> X;
    } while (1 > X || 1000000000 < X);
    
    do {
        cin >> N;
    } while (1 > N || 100 < N);


    for (int i = 0; i < N; ++ i)
    {
        do {
            cin >> a >> b;
        } while (1 > a || 1000000 < a || 1 > b || 10 < b);

        iX += a * b;
        iN += b;
    }
    
    if (X == iX)
        cout << "Yes";
    else
        cout << "No";

	return 0;
}
