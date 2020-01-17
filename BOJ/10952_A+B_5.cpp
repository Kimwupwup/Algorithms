/**
 * 백준 10952번 - A + B - 5
 * 
 * */
#include <iostream>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << (a + b) << "\n";
    }
    return 0;
}