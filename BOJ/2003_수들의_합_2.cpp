/**
 * 백준 2003번 - 수들의 합 2
 * 
 * TODO:
 * 그리드
 * */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    vector<int> v;

    cin >> n >> m;

    int ret = 0, sum = 0, ptr = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);

        sum += v[i];

        while (sum > m) {
            sum -= v[ptr++];
        }

        if (sum == m)
            ret++;
    }
        
    cout << ret << "\n";

    return 0;
}