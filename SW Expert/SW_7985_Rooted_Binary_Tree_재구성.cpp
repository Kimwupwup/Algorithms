/**
 * SW Expert 7985번 - Rooted Binary Tree 재구성
 * 
 * Binary tree
 * 중위 순회
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;
vector<int> ret;

void solution(int left, int right, int idx) {
    int middle = (left + right) / 2;

    if (left > right) 
        return;
    
    ret[idx] = v[middle];
    solution(left, middle - 1, idx * 2);
    solution(middle + 1, right, idx * 2 + 1);
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        v.clear();
        ret.clear();

        int n;
        cin >> n;
        int node_cnt = pow(2, n) - 1;

        v.resize(node_cnt + 1);
        ret.resize(node_cnt + 1);

        for (int i = 1; i <= node_cnt; i++) {
            cin >> v[i];
        }

        solution(1, node_cnt, 1);
        cout << "#" << t << " ";
        for (int i = 1; i <= n; i++) {
            int cur = pow(2, i) - 1;
            
            for (int j = pow(2, i - 1); j <= cur; j++) {
                cout << ret[j] << " ";
            }
          
            cout << "\n";
        }
       
    }

    return 0;
}