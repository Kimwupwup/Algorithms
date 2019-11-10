#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ret = 0;
    while (n != 0)
    {
        ret += n / 5;
        n /= 5;
    }
    cout << ret << endl;
    return 0;
}