/**
 * 백준 1038번 - 감소하는 수
 * 
 * TODO:
 * 큐
 * */
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000;

int N;
queue<long long> q;
long long desc[MAX + 1];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        desc[i] = i;
    }

    int idx = 9;
    while (idx <= N) {
        if (q.empty()) break;

        long long cur = q.front();
        q.pop();

        int last = cur % 10;
        for (int i = 0; i < last; i++) {
            q.push(cur * 10 + i);
            desc[++idx] = cur * 10 + i;
        }
    }

    if (!desc[N] && N) {
        cout << -1 << "\n";
    }
    else {
        cout << desc[N] << "\n";
    }
    return 0;
}