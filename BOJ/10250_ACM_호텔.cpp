#include <iostream>
#include <string>

using namespace std;

int main()
{
    int test;
    int h, w, n;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> h >> w >> n;
        int y, x;
        n -= 1;
        y = n % h + 1;
        x = n / h + 1;
        cout << y;
        if (x < 10)
            cout << "0" << x;
        else
            cout << x;
        cout << endl;
    }
    return 0;
}