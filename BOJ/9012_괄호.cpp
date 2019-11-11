#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    int t;
    stack<char> st;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        while (!st.empty())
        {
            st.pop();
        }
        bool isFound = true;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(')
                st.push(str[j]);
            else
            {
                if (st.empty())
                {
                    isFound = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (!st.empty() || isFound == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}