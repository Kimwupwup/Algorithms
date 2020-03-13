/**
 * 백준 6236번 - 용돈 관리
 * 
 * TODO:
 * 이분 탐색
 * */
#include <iostream>

using namespace std;

const int MAX = 100001;
const int INF = 987654321;

int n, m;
int matrix[MAX];

bool chk(int k) {
    int cnt = 0;
    int money = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (money < matrix[i]) {
            cnt++;
            money = k;

            if (money < matrix[i])
                return false;
        }
        money -= matrix[i];
    }
    
    return cnt <= m;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int left = 1;
    int right = INF;
    int mid;
    int ret = INF;
    while (left <= right) {
        mid = (left + right) / 2;

        if (chk(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        }
        else {
            left = mid + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}