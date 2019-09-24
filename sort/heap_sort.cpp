/* min-heap-sort */

#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>& v, int n, int current) {
    int parent = current;
    int left_child = (current * 2) + 1;
    int right_child = (current * 2) + 2;

    if (left_child < n && v[left_child] > v[parent]) parent = left_child;
    if (right_child < n && v[right_child] > v[parent]) parent = right_child;

    if (parent != current) {
        swap(v[parent], v[current]);
        heapify(v, n, parent);
    }
}

void heap_sort(vector<int>& v) {
    int n = v.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    heap_sort(v);

    for (int a : v) {
        cout << a << " ";
    }
}