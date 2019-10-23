#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long long dx = x1 - x2;
        long long dy = y1 - y2;

        long long sum = (r1 + r2) * (r1 + r2);
        long long sub = (r1 - r2) * (r1 - r2);

        long long d = dx * dx + dy * dy;

        if (d == 0)
        {
            if (sub == 0)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        else if (d == sum || d == sub)
            cout << 1 << endl;
        else if (d < sum && d > sub)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}