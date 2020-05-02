/**
 * 백준 1731번 - 추론
 * 
 * */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    vector<int> v;

    cin >> N;

    while (N--) {
        int a;
        cin >> a;

        v.push_back(a);
    }

    vector<int> a, b;
    for (int i = 1; i < v.size(); i++) {
        a.push_back(v[i] - v[i - 1]);
        b.push_back(v[i] / v[i - 1]);
    }
    if (a[0] == a[1])
        cout << v[v.size() - 1] + a[0] << "\n";
    else if (b[0] == b[1])
        cout << v[v.size() - 1] * b[0] << "\n";
    return 0;
}
