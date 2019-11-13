#include <iostream>
#include <queue>
#include <string>

using namespace std;
queue<int> q;
int n;
string str;
int num;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (str == "pop")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (str == "size")
        {
            cout << q.size() << "\n";
        }
        else if (str == "empty")
        {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (str == "front")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (str == "back")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}