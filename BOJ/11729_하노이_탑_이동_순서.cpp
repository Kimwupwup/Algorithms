/**
 * 백준 11729번 - 하노이 탑 이동 순서
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
void Hanoi(int idx, int from, int by, int to) {
    if (idx == 1)
        v.push_back({from, to});
    else {
        Hanoi(idx - 1, from, to, by);
        v.push_back({from, to});
        Hanoi(idx - 1, by, from, to);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Hanoi(n, 1, 2, 3);
    cout << v.size() << "\n";
    for (pair<int, int> p : v)
        cout << p.first << " " << p.second << "\n";
    return 0;
}