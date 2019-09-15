#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> number3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer;
    vector<int> counter;

    int a = 1;
    int cnt = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a)
            cnt++;
        a++;
        if (a == 6)
            a = 1;
    }
    counter.push_back(cnt);

    a = 1;
    cnt = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (i % 2 == 1 && answers[i] == a)
            cnt++;
        if (i % 2 == 0 && answers[i] == 2)
            cnt++;
        if (i % 2 == 1)
        {
            a++;
            if (a == 2)
                a = 3;
            if (a == 6)
                a = 1;
        }
    }
    counter.push_back(cnt);

    a = 0;
    cnt = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == number3[a]) cnt++;
        a++;
        if (a == number3.size() - 1) a = 0;
    }
    counter.push_back(cnt);
    sort(counter.begin(), counter.end(), greater<int>());

    int idx;
    int maxi = counter[0];
    for (int i = 0; i < counter.size(); i++)
    {
        if (maxi == counter[i]) answer.push_back(i);
    }
    return answer;
}

int main()
{
    vector<vector<int>> answers = {{1, 2, 3, 4, 5}, {1, 3, 2, 4, 2}};
    for (vector<int> temp : answers)
        solution(temp);
    return 0;
}