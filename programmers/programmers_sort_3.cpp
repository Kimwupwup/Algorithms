#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = citations.size(); i > 0; i--)
    {
        int cnt = 0;
        int h = i;
        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] < h) break;
            cnt++;
        }
        if (cnt >= h) return h;
    }
    return answer;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution(citations) << endl;
    return 0;
}