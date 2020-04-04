#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        while (n--)
            cout << "*";
        cout << "\n";
    }
    return 0;
}