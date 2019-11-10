#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<int> v;

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        int a;

        cin >> str;
        if (str == "push")
        {
            cin >> a;
            v.push_back(a);
        }
        else if (str == "pop")
        {
            if (v.empty())
                cout << -1 << endl;
            else
            {
                cout << v[v.size() - 1] << endl;
                v.pop_back();
            }
        }
        else if (str == "size")
        {
            cout << v.size() << endl;
        }
        else if (str == "empty")
        {
            cout << (v.empty() ? 1 : 0) << endl;
        }
        else if (str == "top")
        {
            if (v.empty())
                cout << -1 << endl;
            else
                cout << v[v.size() - 1] << endl;
        }
    }
    return 0;
}