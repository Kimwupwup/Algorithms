#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        q.push(i + 1);

    bool isSSara = false;
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front() << "\n";
            break;
        }
        if (isSSara == false)
        {
            q.pop();
            isSSara = true;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            isSSara = false;
        }
    }
    return 0;
}