/**
 * Codeforces round #605 20191212
 * 
 * A. Three Friends
 * 
 * 3명의 친구가 서로 만날거다. 첫 번째 친구는 x = a에서 기다린다. 두 번째 친구는 x = b에서 기다린다.
 * 그리고 세 번째 친구는 x = c에서 기다린다.
 * 각 친구들은 서로 상관없이 x를 왼쪽, 오른쪽 한칸씩 움직일 수 있다. 안움직일 수 있다.(x = x - 1 || x = x + 1)
 * 각 짝의 최소 거리를 계산하라. |a:b| + |b:c| + |a:c|
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

vector<int> v;
int ret;

void solution(int idx) {
    if (idx == v.size()) {
        int a, b, c;

        a = abs(v[0] - v[1]);
        b = abs(v[0] - v[2]);
        c = abs(v[1] - v[2]);
        if (ret > a + b + c) {
            ret = a + b + c;
        }
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            v[idx] -= 1;
            solution(idx + 1);
            v[idx] += 1;
        } else if (i == 1) {
            v[idx] += 1;
            solution(idx + 1);
            v[idx] -= 1;
        }
    }
    solution(idx + 1);
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        v.clear();
        v.resize(3);
        ret = INT_MAX;

        int input;
        for (int i = 0; i < 3; i++) {
            cin >> input;
            v[i] = input;
        }

        solution(0);

        cout << ret << "\n";
    }
    return 0;
}