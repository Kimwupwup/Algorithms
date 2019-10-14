#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    vector<bool> eratosthenes;
    int num;
    
    cin >> num;
    eratosthenes.resize(num + 1, true);

    eratosthenes[1] = false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (eratosthenes[i] == true) {
            for (int j = i * i; j <= num; j += i) {
                eratosthenes[j] = false;
            }
        }
    }

    for (int i = 1; i <= num; i++) {
        if (eratosthenes[i] == true) cout << i << " ";
    }
    return 0;
}