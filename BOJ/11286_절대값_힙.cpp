#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ret;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == 0)
        {
            if (pq.empty())
            {
                ret.push_back(0);
            }
            else
            {
                ret.push_back(pq.top().second);
                pq.pop();
            }
        }
        else
        {
            pq.push({abs(temp), temp});
        }
    }

    for (int a : ret)
        printf("%d\n", a);

    return 0;
}