#include <vector>
#include <iostream>

using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick_sort(int left, int right, vector<int>& v) {
    // int pivot = left;
    // int j = left;
    // int i = left + 1;

    // if (left < right) {
    //     for (; i <= right; i++) {
    //         if (v[i] < v[pivot]) {
    //             j++;
    //             if (i != j) swap(v[i], v[j]);
    //         }
    //     }
    //     swap(v[pivot], v[j]);
    //     quick_sort(left, j - 1, v);
    //     quick_sort(j + 1, right, v);
    // }

    if (left > right) return;
    int pivot = v[(left + right) / 2];
    int low = left;
    int high = right;

    while (low <= high) {
        while (v[low] < pivot && low <= right) low++;
        while (v[high] > pivot && high >= left) high--;

        if (low <= high) {
            swap(v[low], v[high]);
            low++;
            high--;
        }
    }
    quick_sort(low, right, v);
    quick_sort(left, high, v);
}

int main() {
    vector<int> v = {5, 3, 2, 1, 9, 4, 7, 10, 8, 6};
    quick_sort(0, v.size() - 1, v);
    for (int a : v) cout << a << " ";
}