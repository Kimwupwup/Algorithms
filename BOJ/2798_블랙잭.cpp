#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> answer;
vector<int> v;
int n, m;
int main()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                answer.push_back(v[i] + v[j] + v[k]);
            }
        }
    }

    int mini = 987654321;
    int idx = 0;
    for (int i = 0; i < answer.size(); i++)
    {
        if (mini > abs(m - answer[i]) && m >= answer[i])
        {
            mini = abs(m - answer[i]);
            idx = i;
        }
    }
    cout << answer[idx] << endl;
    return 0;
}