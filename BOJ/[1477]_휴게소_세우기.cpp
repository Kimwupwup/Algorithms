/**
 * 백준 1477번 - 휴게소 세우기
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> v;
int n, m, l;

int count(int mid) {
    int ret = 0;
    for (int i = 1; i < n + 2; i++) {
        ret += (v[i] - v[i - 1] - 1) / mid;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> l;
    v.push_back(0);
    v.push_back(l);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int left = 0;
    int right = l;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (count(mid) > m)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    cout << left << "\n";
    return 0;
}