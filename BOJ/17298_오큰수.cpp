#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int n;
vector<int> v;
vector<int> ret;
stack<int> st;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    v.resize(n);
    ret.resize(v.size(), -1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] < v[i])
        {
            ret[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    for (int x : ret)
        cout << x << " ";
    return 0;
}