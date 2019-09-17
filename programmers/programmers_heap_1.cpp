#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool checkScoville(int temp, int K) {
    if (temp < K) return false;
    return true;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (true) {
        if (pq.size() == 1) {
            return -1;
        }

        answer++;
        
        int num1 = pq.top();
        pq.pop();

        int num2 = pq.top();
        pq.pop();

        int ret = num1 + (num2 * 2);
        pq.push(ret);
        
        if (checkScoville(pq.top(), K)) {
            return answer;
        }
    }
    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    
    cout << solution(scoville, 7);
}