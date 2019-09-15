#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a ? true : false;
}

string solution(vector<int> numbers)
{
    vector<string> num;
    for (int temp : numbers)
    {
        string str = "";
        str = to_string(temp);
        num.push_back(str);
    }
    sort(num.begin(), num.end(), cmp);
    string ret = "";
    for (string temp : num)
        ret += temp;
    if (ret[0] == '0')
        return "0";
    return ret;
}

int main()
{
    vector<vector<int>> numbers = {{6, 10, 2}, {3, 30, 34, 5, 9}, {3, 32}};
    for (vector<int> test_set : numbers)
    {
        cout << solution(test_set) << endl;
    }
    return 0;
}