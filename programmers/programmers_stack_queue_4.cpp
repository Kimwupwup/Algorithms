#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while (!progresses.empty()) {
        int cnt = 0;
        int size = progresses.size();
        for (int i = 0; i < size; i++) {
            if (progresses.front() >= 100) {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt++;
            }
            else {
                break;
            }
        }
        if (cnt != 0) answer.push_back(cnt);
        
        size = progresses.size();
        for (int i = 0; i < size; i++) {
            progresses[i] += speeds[i];
        }
    }
    return answer;
}

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    vector<int> ret = solution(progresses, speeds);
    for (int temp : ret) {
        cout << temp << " ";
    }
}