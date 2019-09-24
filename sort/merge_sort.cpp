#include <iostream>
#include <vector>

using namespace std;

void merge(int left, int right, vector<int>& v) {
    vector<int> temp(v.size());
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }

    int tmp = i > mid ? j : i;

    while (k <= right) temp[k++] = v[tmp++];

    for (int i = left; i <= right; i++) v[i] = temp[i];
}

void partition(int left, int right, vector<int>& v) {
    int mid;
    if (left < right) {
        mid = (right + left) / 2;
        partition(left, mid, v);
        partition(mid + 1, right, v);
        merge(left, right, v);
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    partition(0, v.size() - 1, v);

    for (int i : v) {
        cout << i << " ";
    }
}