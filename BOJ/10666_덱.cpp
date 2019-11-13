#include <iostream>
#include <deque>

using namespace std;
deque<int> dq;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string str;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (str == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (str == "pop_front")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (str == "size")
            cout << dq.size() << endl;
        else if (str == "empty")
            cout << (dq.empty() ? 1 : 0) << endl;
        else if (str == "front")
            cout << (dq.empty() ? -1 : dq.front()) << endl;
        else if (str == "back")
            cout << (dq.empty() ? -1 : dq.back()) << endl;
    }
    return 0;
}