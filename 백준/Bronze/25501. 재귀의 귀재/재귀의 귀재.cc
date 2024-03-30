#include <iostream>	
#include <string.h>

int recursion(const char* s, int l, int r, int& n) {
    ++n;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, n);
}

int isPalindrome(const char* s, int& n) {
    return recursion(s, 0, strlen(s) - 1, n);
}

int main()
{
    int T{}, N{};
    std::cin >> T;

    while (T--)
    {
        char arr[1001]{};

        std::cin >> arr;

        std::cout << isPalindrome(arr, N) << " " << N << "\n";

        N = 0;
    }
	return 0;
}