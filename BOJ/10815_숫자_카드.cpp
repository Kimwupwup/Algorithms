/**
 * 백준 10815번 - 숫자 카드
 * 
 * TODO:
 * map
 * */
#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<int, int> m;
    int N, M;

    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        m[temp] = 1;
    }

    cin >> M;
    while (M--) {
        int temp;
        cin >> temp;
        if (m.count(temp) == 0) cout << 0 << " ";
        else cout << 1 << " ";
    }
    
    return 0;
}