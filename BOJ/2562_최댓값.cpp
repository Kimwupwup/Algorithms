/**
 * 백준 2562번 - 최댓값
 * 
 * */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int idx;
    int maxi = 0;
    int matrix[9];
    for (int i = 0; i < 9; i++) {
        cin >> matrix[i];
        if (matrix[i] > maxi) {
            maxi = matrix[i];
            idx = i + 1;
        }
    }
    cout << maxi << "\n" << idx << "\n";
    return 0;
}