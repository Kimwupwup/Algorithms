/**
 * 백준 5525번 - IOIOI
 * 문자열 탐색
 * S : 찾을 문자열(I가 n + 1개, O가 n개)
 * M : 문자열
 * KMP 알고리즘
 * 다른 알고리즘으로 풀 수 있다.
 * **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_pi(string str)
{
    vector<int> pi(str.size(), 0);
    int j = 0;
    for (int i = 1; i < str.size(); i++)
    {
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string str1, string str2)
{
    vector<int> ret;
    vector<int> pi = get_pi(str1);
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < str2.size(); i++)
    {
        while (j > 0 && str2[i] != str1[j])
            j = pi[j - 1];

        if (str2[i] == str1[j])
        {
            if (j == str1.size() - 1)
            {
                ret.push_back(i - str1.size() + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return ret;
}

int main()
{
    string str1;
    string str2;
    int n, m;

    cin >> n;
    cin >> m;
    cin >> str2;

    for (int i = 0; i < n * 2 + 1; i++)
        if (i % 2 == 0)
            str1 += "I";
        else
            str1 += "O";
    vector<int> ret = kmp(str1, str2);

    cout << ret.size() << endl;
}