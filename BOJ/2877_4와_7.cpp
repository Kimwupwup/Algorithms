#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string str;
    cin >> n;

    while (n > 0)
    {
        int temp = n % 2;
        n /= 2;
        str += (temp == 1 ? 4 : 7) + '0';
        if (temp == 0)
            n -= 1;
    }

    reverse(str.begin(), str.end());
    cout << str;
}