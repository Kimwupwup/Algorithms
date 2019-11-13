#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, m;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    cout << "<";

    int cnt = 0;
    while (!q.empty())
    {
        if (cnt != m - 1)
        {
            cnt++;
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        else
        {
            cnt = 0;
            cout << q.front();
            q.pop();
            if (!q.empty())
                cout << ", ";
        }
    }
    cout << ">";
    return 0;
}