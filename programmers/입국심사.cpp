#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

bool check(long long time, vector<int> times, int n) {
    long long temp = 0;
    for (int i = 0; i < times.size(); i++) {
        temp += time / times[i];
    }
    return temp >= n;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end(), greater<int>());
    long long answer = 0;
    long long left = 0, right = times[0] * n;
    long long result = LLONG_MAX;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(mid, times, n)) {
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        cout << mid << endl;
    }
    answer = result;
    return answer;
}

int main() {
    vector<int> times = {7, 10};
    cout << solution(6, times);
}
