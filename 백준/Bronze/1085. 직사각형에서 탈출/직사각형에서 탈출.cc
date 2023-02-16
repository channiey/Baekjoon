#include <iostream>

using namespace std;

int main(void)
{
	int x = 0, y = 0, w = 0, h = 0;

	do {
		cin >> x;
		cin >> y;
		cin >> w;
		cin >> h;
	} while (1 > w || 1 > h || 1000 < w || 1000 < h || 1 > x || 1 > y || w-1 < x || h-1 < y);

	int iMinWidth = (x < w - x) ? x : w - x;
	int iMinHeight = (y < h - y) ? y : h - y;

	if (iMinWidth > iMinHeight)
		cout << iMinHeight;
	else
		cout << iMinWidth;
	
	return 0;
}
