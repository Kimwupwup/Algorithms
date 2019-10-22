#include <vector>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int cur, int size, vector<int>& v) {
    int parent = cur;
    int left_child = cur * 2 + 1;
    int right_child = cur * 2 + 2;

    if (left_child < size && v[left_child] > v[parent]) parent = left_child;
    if (right_child < size && v[right_child] > v[parent]) parent = right_child;

    if (parent != cur) {
        swap(v[parent], v[cur]);
        heapify(parent, size, v);
    }
}

void heap_sort(vector<int>& v) {
    int size = v.size();
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(i, size, v);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(0, i, v);
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    heap_sort(v);
    for (int a : v) {
        cout << a << " ";
    }
}