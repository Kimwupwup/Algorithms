/**
 * 백준 10972번 - 다음 순열
 * 
 * TODO:
 * next_permutation
 * */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    if (next_permutation(v.begin(), v.end())) {
        for (int a : v)
            cout << a << " ";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}