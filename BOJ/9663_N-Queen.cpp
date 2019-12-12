/**
 * 백준 9663번 - N-Queen
 * 백트래킹
 * 
 * */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 15;

int matrix[MAX];
int n;

bool check(int i) {
    int k = 1;
    bool isFound = true;

    for (; k < i; k++) {
        if (isFound == false)
            break;
        if (matrix[i] == matrix[k] || abs(matrix[i] - matrix[k]) == i - k)
            isFound = false;
    }
    return isFound;
}

int do_it(int i) {
    int ret = 0;
    if (check(i)) {
        if (i == n)
            return 1;
        else
            for (int j = 1; j <= n; j++) {
                matrix[i + 1] = j;
                ret += do_it(i + 1);
            }
    }
    return ret;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    cout << do_it(0) << endl;
    return 0;
}