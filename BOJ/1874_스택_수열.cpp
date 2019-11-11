#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    vector<int> v;
    vector<char> ret;
    stack<int> st;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int idx = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (idx <= v[i])
        {
            for (int j = idx; j <= v[i]; j++, idx++)
            {
                st.push(j);
                ret.push_back('+');
            }
        }

        if (st.top() == v[i])
        {
            st.pop();
            ret.push_back('-');
        }
    }
    if (!st.empty())
        cout << "NO\n";
    else
        for (char t : ret)
            cout << t << "\n";
    return 0;
}