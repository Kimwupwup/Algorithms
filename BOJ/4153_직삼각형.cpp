#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    while (true)
    {
        v.clear();
        for (int i = 0; i < 3; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        if (v[0] == 0 && v[2] == 0)
            return 0;
        int sum = (v[0] * v[0]) + (v[1] * v[1]);
        if (sum == v[2] * v[2])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}