/**
 * 백준 6588번 - 골드바흐의 추측
 * 
 * TODO:
 * 에라토스테네스의 체, 브루트 포스
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
bool matrix[MAX];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    memset(matrix, true, sizeof(matrix));
    matrix[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (matrix[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                matrix[j] = false;
            }
        }
    }
    while (true) {
        cin >> n;
        if (n == 0) return 0;

        int left = 1;
        int right = n;
        while (left <= right) {
            while (!matrix[left])
                left++;
            while (!matrix[right])
                right--;
            
            if (left + right == n)
                break;
            else if (left + right < n)
                left++;
            else if (left + right > n)
                right--;
        }
        cout << n << " = " << left << " + " << right << "\n";
    }

    return 0;
}