/**
 * 백준 1114번 - 통나무 자르기
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int MAX = 10002;

int l, k, c;
int matrix[MAX];

bool possible(int mid) {
    int dist = 0;
    int cnt = 0;

    for (int i = k; i >= 1; i--) {
        dist += matrix[i] - matrix[i - 1];
        if (dist > mid) {
            dist = matrix[i] - matrix[i - 1];
            cnt++;
            if (dist > mid) {
                cnt = c + 1;
                break;
            }
        }
    }
    return cnt <= c;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> l >> k >> c;
    for (int i = 1; i <= k; i++) {
        cin >> matrix[i];
    }
    matrix[0] = 0;
    matrix[++k] = l;
    sort(matrix, matrix + k + 1);

    int left = 0;
    int right = INF;
    int mid;
    int ret = INT_MAX;

    while (left <= right) {
        mid = (left + right) / 2;

        if (possible(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        } else {
            left = mid + 1;
        }
    }

    int dist = 0;
    int cnt = 0;
    int idx = 0;
    for (int i = k; i >= 1; i--) {
        dist += matrix[i] - matrix[i - 1];
        if (dist > ret) {
            dist = matrix[i] - matrix[i - 1];
            cnt++;
            idx = i;
        }
    }
    if (cnt < c) idx = 1;
    cout << ret << " " << matrix[idx] << "\n";
    return 0;
}