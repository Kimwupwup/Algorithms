/**
 * 백준 2747번 - 피보나치 수
 * 
 * TODO:
 * DP
 * */
#include <iostream>

using namespace std;

const int MAX = 46;
long long matrix[MAX];
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n;
    matrix[1] = 1;
    matrix[2] = 1;

    for (int i = 3; i <= n; i++) {
        matrix[i] = matrix[i - 1] + matrix[i - 2];
    }

    cout << matrix[n] << "\n";
    
    return 0;
}
