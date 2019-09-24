#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick_sort(int left, int right, vector<int>& v) {
    int pivot = left;
    int j = pivot;
    int i = left + 1;
    
    if (left < right) {
        for (; i <= right; i++) {
            if (v[i] < v[pivot]) {
                j++;
                swap(v[i], v[j]);
            }
        }
        swap(v[left], v[j]);
        pivot = j;

        quick_sort(left, pivot - 1, v);
        quick_sort(pivot + 1, right, v);
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    quick_sort(0, v.size() - 1, v);
    for (int a : v) {
        cout << a << " ";
    }
}