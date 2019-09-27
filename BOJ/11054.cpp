#include <iostream>
#include <vector>

using namespace std;

int n;
int matrix[1000];
int fcache[1000];
int bcache[1000];

void LIS() {
    for (int i = 0; i < n; i++) {
        fcache[i] = 1;

        for (int j = 0; j <= i; j++) {
            if (matrix[i] > matrix[j] && fcache[j] + 1 > fcache[i]) {
                fcache[i] = fcache[j] + 1;
            }
        }
    }
}

void RLIS() {
    for (int i = n - 1; i >= 0; i--) {
        bcache[i] = 1;

        for (int j = n - 1; j >= i; j--) {
            if (matrix[i] > matrix[j] && bcache[j] + 1 > bcache[i]) {
                bcache[i] = bcache[j] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    LIS();
    RLIS();

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int temp = fcache[i] + bcache[i];

        if (maxi < temp) {
            maxi = temp;
        }
    }
    cout << maxi - 1 << endl;
    return 0;
}