#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& v) {
    
    for (int i = 0; i < v.size(); i++) {
        int idx = i ;

        for (int j = i + 1; j < v.size(); j++) {
            if (v[idx] > v[j]) {
                idx = j;
            }
        }
        int temp = v[i];
        v[i] = v[idx];
        v[idx] = temp;
    }
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    selection_sort(v);
    for (int a : v) {
        cout << a << " ";
    }
}