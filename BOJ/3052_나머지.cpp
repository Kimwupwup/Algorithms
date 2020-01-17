/**
 * 백준 3052번 - 나머지
 * 
 * */
#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    set<int> s;
    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        s.insert(temp % 42);
    }
    cout << s.size() << "\n";
    return 0;
}