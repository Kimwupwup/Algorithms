/**
 * 백준 18798번 - OR과 쿼리
 * 
 * */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 250001;

int matrix[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i];
    }

    cin >> m;
    while (m--) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++) {
                int temp = matrix[i] | x;
               
                matrix[i] = temp;
            }
        }
        else {
            int cnt = 0;
            cin >> l >> r;
            for (int i = l; i <= r; i++) {
                if (matrix[i] == k) cnt++;
            }
            cout << cnt << "\n";
        }
    }

    return 0;
}