#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (v[j + 1] < v[j]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            } else {
                break;
            }
        }
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    insertion_sort(v);

    for (int a : v) {
        cout << a << " ";
    }
}