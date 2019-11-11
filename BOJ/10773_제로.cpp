#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    int n;
    int temp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 0)
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(temp);
    }
    if (st.empty())
        cout << 0 << endl;
    else
    {
        int ret = 0;
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        cout << ret << endl;
    }
    return 0;
}