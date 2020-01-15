/**
 * 백준 5545번 - 최고의 피자
 * 
 * TODO: 그리디
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b, c;
vector<int> costs;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b >> c;
    costs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    sort(costs.begin(), costs.end(), greater<int>());

    int sum = c;
    int div = a;
    int maxi = sum / div;
    for (int i = 0; i < n; i++) {
        div += b;
        sum += costs[i];
        if (maxi <= sum / div) {
            maxi = sum / div;
        }
        else {
            break;
        }
    }
    cout << int(maxi) << "\n";
    return 0;
}