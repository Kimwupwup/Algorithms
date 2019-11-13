#include <iostream>
#include <queue>
using namespace std;

int t, n, m;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            q.push({num, j});
            pq.push(num);
        }
        
        int cnt = 0;
        while (!q.empty())
        {
            if (pq.top() != q.front().first) {
                pair<int, int> temp = q.front();
                q.pop();
                q.push(temp);
            }
            else {
                if (q.front().second == m)
                {
                    cnt++;
                    cout << cnt << endl;
                    break;
                }
                else
                {
                    cnt++;
                    q.pop();
                    pq.pop();
                }                
            }
        }
    }
    return 0;
}