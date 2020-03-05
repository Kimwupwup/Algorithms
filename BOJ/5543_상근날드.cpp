/**
 * 백준 5543번 - 상근날드
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> burger(3);
    vector<int> juice(2);
    for (int i = 0; i < 3; i++) {
        cin >> burger[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> juice[i];
    }
    sort(burger.begin(), burger.end());
    sort(juice.begin(), juice.end());

    cout << burger[0] + juice[0] - 50 << "\n";
    return 0;
}