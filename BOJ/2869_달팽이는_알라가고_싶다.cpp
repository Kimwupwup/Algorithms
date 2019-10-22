#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    int day;

    cin >> a >> b >> v;
    day = (v - b - 1) / (a - b) + 1;
    cout << day;
}