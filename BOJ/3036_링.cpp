#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
int n;
vector<int> v;

int GCD(int a, int b)
{
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 1; i < n; i++)
    {
        int temp = GCD(v[0], v[i]);
        cout << (v[0] / temp) << "/" << (v[i] / temp) << endl;
    }
    return 0;
}