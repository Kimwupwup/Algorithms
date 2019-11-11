#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    while (true)
    {
        vector<char> v;
        bool isFound = true;
        string str;
        getline(cin, str);
        if (str.length() == 1 && str[0] == '.')
            break;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                v.push_back(str[i]);
            else if (str[i] == '[')
                v.push_back(str[i]);
            else if (str[i] == ')')
            {
                if (!v.empty() && v[v.size() - 1] == '(')
                {
                    v.pop_back();
                }
                else
                {
                    isFound = false;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (!v.empty() && v[v.size() - 1] == '[')
                {
                    v.pop_back();
                }
                else
                {
                    isFound = false;
                    break;
                }
            }
        }
        if (isFound == true && v.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}