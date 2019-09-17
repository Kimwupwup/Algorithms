#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int current = 0;
    vector<int> term;

    term.push_back(dates[0] - 0);
    for (int i = 1; i < dates.size() - 1; i++) {
        term.push_back(dates[i + 1] - dates[i]);
    }
    term.push_back(k - dates[dates.size() - 1]);

    int idx = 0;
    while (true) {
        if (idx == term.size()) break;
        stock -= term[idx];
        if (stock < term[idx + 1]) {
            stock += supplies[idx];
            answer++;
        }
        idx++;
    }
    return answer;
}

int main() {
    cout << solution(4, {4, 10, 15}, {20, 5, 10}, 30);
}