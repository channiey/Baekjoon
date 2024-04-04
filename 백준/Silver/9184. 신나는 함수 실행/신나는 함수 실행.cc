#include <iostream>

#define MAX 20
int arr[MAX+1][MAX + 1][MAX + 1]{};

const int w(int a, int b, int c)
{    
    if (0 >= a || 0 >= b || 0 >= c)
        return 1;
    else if (MAX < a || MAX < b || MAX < c)
        return w(MAX, MAX, MAX);
    else if (arr[a][b][c] != 0) // Memorization
        return arr[a][b][c];
    else if (a < b && b < c)
    {
        // Memorization
        arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return arr[a][b][c];
    }
    else
    {
        // Memorization
        arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return arr[a][b][c];
    }
}

int main()
{
    int a{}, b{}, c{}, res{};

    std::cin >> a >> b >> c;
    while (-1 != a || -1 != b || - 1 != c)
    {
        res = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, res);
        std::cin >> a >> b >> c;
    }
	return 0;
}