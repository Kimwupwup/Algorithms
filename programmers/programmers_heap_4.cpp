#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    vector<int> pq;
    priority_queue<int, vector<int>, less<int>> lower_pq;
    priority_queue<int, vector<int>, greater<int>> upper_pq;
    bool isLess = true;
    for (string str : operations)
    {
        int number = stoi(str.substr(2));
        if (str[0] == 'I')
        {
            pq.push_back(number);
            sort(pq.begin(), pq.end(), less<int>());
            isLess = true;
        }
        else if (str[0] == 'D') {
            if (!pq.empty() && number < 0) {
                if (isLess) {
                    reverse(pq.begin(), pq.end());
                    isLess = false;
                } 
                pq.pop_back();
            }
            else if (!pq.empty() && number > 0) {
                if (!isLess) {
                    reverse(pq.begin(), pq.end());
                    isLess = true;
                }
                pq.pop_back();
            }
        }
    }
    if (pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        if (!isLess) {
            answer.push_back(pq.front());
            reverse(pq.begin(), pq.end());
            answer.push_back(pq.front());
        }
        else {
            reverse(pq.begin(), pq.end());
            answer.push_back(pq.front());
            reverse(pq.begin(), pq.end());
            answer.push_back(pq.front());
        }
    }
    
    return answer;
}