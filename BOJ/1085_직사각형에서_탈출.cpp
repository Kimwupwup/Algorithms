#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int minX = x < w - x ? x : w - x;
    int minY = y < h - y ? y : h - y;
    cout << (minX < minY ? minX : minY);
}