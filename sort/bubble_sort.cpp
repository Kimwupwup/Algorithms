#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& v) {
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    bubble_sort(v);

    for (int a : v) {
        cout << a << " ";
    }
}