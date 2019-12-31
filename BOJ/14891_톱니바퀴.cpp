/**
 * 백준 14891번 - 톱니바퀴
 * 
 * 톱니바퀴는 deque로 구현한다.
 * CW: pop_back() -> push_front()
 * CCW: pop_front() -> push_back()
 * 3시: index 2
 * 9시: index 6
 * 12시: index 0
 * 6시: index 4
 * */
#include <bits/stdc++.h>

using namespace std;


deque<char> dq[4];
int n;
vector<pair<int, int>> v;

bool turn(int idx, bool cw) {
    if (cw) {
        int temp = dq[idx].front();
        dq[idx].pop_front();
        dq[idx].push_back(temp);
    } else {
        int temp = dq[idx].back();
        dq[idx].pop_back();
        dq[idx].push_front(temp);
    }
    return !cw;
}

void solve(int idx, int type) {
    int cur_left = dq[idx][6];
    int cur_right = dq[idx][2];
    bool clock_wise = type == 1 ? true : false;
    
    for (int i = idx - 1; i >= 0; i--) {
        if (cur_left != dq[i][2]) {
            cur_left = dq[i][6];
            cur_right = dq[i][2];
            clock_wise = turn(i, clock_wise);
        } else {
            break;
        }
    }

    cur_left = dq[idx][6];
    cur_right = dq[idx][2];
    clock_wise = type == 1 ? true : false;
    for (int i = idx + 1; i < 4; i++) {
        if (cur_right != dq[i][6]) {
            cur_left = dq[i][6];
            cur_right = dq[i][2];
            clock_wise = turn(i, clock_wise);
        } else {
            break;
        }
    }
    clock_wise = type == 1 ? true : false;
    turn(idx, !clock_wise);

}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 4; i++) {
        dq[i].resize(8);
        for (int j = 0; j < 8; j++) {
            cin >> dq[i][j];
        }
    }

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n; i++) {
        int idx = v[i].first;
        int type = v[i].second;
        solve(idx - 1, type);
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (dq[i][0] == '1')
            ret += pow(2, i);
    }
    cout << ret << "\n";
    return 0;
}