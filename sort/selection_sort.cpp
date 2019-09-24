#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& v) {
    
    for (int i = 0; i < v.size(); i++) {
        int mini = 987654321;
        int idx = 0 ;

        for (int j = i; j < v.size(); j++) {
            if (mini > v[j]) {
                mini = v[j];
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