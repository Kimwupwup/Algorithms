#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    v.resize(n + 1);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        v[i] = (v[i - 1] + v[i - 2]) % 15746;
    }
    cout << v[n] << endl;
    return 0;
}