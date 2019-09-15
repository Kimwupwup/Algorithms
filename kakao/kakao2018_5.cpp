#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

void solution(string str1, string str2)
{
    vector<string> str1_set;
    vector<string> str2_set;
    vector<string> all_set;

    for (int i = 0; i < str1.size(); i++)
    {
        str1[i] = tolower(str1[i]);
    }
    
    for (int i = 0; i < str2.size(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string temp = "";
        for (int j = i; j < i + 2; j++)
        {
            if (str1[j] < 'a' || str1[j] > 'z') continue;
            temp += str1[j];
        }
        if (temp.size() != 2) continue;
        str1_set.push_back(temp);
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        string temp = "";
        for (int j = i; j < i + 2; j++)
        {
            if (str2[j] < 'a' || str2[j] > 'z') continue;
            temp += str2[j];
        }
        if (temp.size() != 2) continue;
        str2_set.push_back(temp);
    }

    sort(str1_set.begin(), str1_set.end());
    sort(str2_set.begin(), str2_set.end());
    
    int idx1 = 0;
    int idx2 = 0;
    int cnt = 0;

    while (true)
    {
        if (idx1 == str1_set.size() || idx2 == str2_set.size()) break;

        if (str1_set[idx1] > str2_set[idx2])
        {
            if (idx2 < str2_set.size())
            {
                idx2++;
            } 
        }
            
        else if (str1_set[idx1] < str2_set[idx2])
        {
            if (idx1 < str1_set.size())
            {
                idx1++;
            }
        }
                
        else if (str1_set[idx1] == str2_set[idx2])
        {
            cnt++;
            idx1++;
            idx2++;
        }
    }
    
    int ret = (double)(cnt / (double)(str1_set.size() + str2_set.size() - cnt)) * 65536;
    if (cnt == 0) ret = 65536;
    cout << ret << endl;
}
int main()
{
    vector<string> str1 = {"FRANCE", "handshake", "aa1+aa2", "E=M*C^2"};
    vector<string> str2 = {"french", "shake hands", "AAAA12", "e=m*c^2"};

    for (int i = 0; i < str1.size(); i++)
    {
        solution(str1[i], str2[i]);
    }
    return 0;
}