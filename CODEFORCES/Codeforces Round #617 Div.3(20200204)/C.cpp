#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> v;
    v.resize(n);

    priority_queue<int, vector<int>, greater<int>> ret;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n; i++) {
        if (v[i] % (a + b) == 0 || v[i] % (a + b) > a)
            ret.push((v[i] % (a + b)) % a ? (v[i] % (a + b)) % a + 1 : (v[i] % (a + b)) % a);
    }

    int cnt = 0;
    while (k) {
        int num = ret.top();
        ret.pop();
        k -= num;
        if (k >= 0)
            cnt++;
        else
            break;
    }

    cout << cnt << "\n";
    return 0;
}