#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        bool isFlip = false;
        int m1 = 1, m2 = 1;
        int cnt = 3;
        while (true)
        {
            if (isFlip)
                m1 = (m1 + m2) % m;
            else
                m2 = (m1 + m2) % m;
            isFlip = !isFlip;
            if (m1 == 1 && m2 == 1)
            {
                cout << n << " " << cnt - 2 << endl;
                break;
            }
            cnt++;
        }
    }
}