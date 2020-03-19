/**
 * 백준 11004번 - K번째 수
 * 
 * TODO:
 * heap sort, quick sort, quick selection
 * heap sort, (stl - sort) 두 가지 방식으로도 충분히 통과가 가능합니다.
 * 
 * quick sort는 불가능하다. 최악의 경우 O(n^2)의 시간이 걸리기 때문에 시간 초과
 * quick selection 또한, 잘 구현하지 않으면 quick sort 와 마찬가지로 
 * 피벗이 한쪽으로 쏠리는 문제가 발생하여 최악의 경우 O(n^2)이 됩니다.
 * 
 * https://en.wikipedia.org/wiki/Quickselect#Time_complexity
 * Like quicksort, the quickselect has good average performance, 
 * but is sensitive to the pivot that is chosen. 
 * If good pivots are chosen, meaning ones that consistently 
 * decrease the search set by a given fraction, 
 * then the search set decreases in size exponentially 
 * and by induction (or summing the geometric series) one sees 
 * that performance is linear, as each step is linear 
 * and the overall time is a constant times this 
 * (depending on how quickly the search set reduces). 
 * However, if bad pivots are consistently chosen, 
 * such as decreasing by only a single element each time, 
 * then worst-case performance is quadratic: O(n2). 
 * This occurs for example in searching for the maximum element of a set, 
 * using the first element as the pivot, and having sorted data. 
 * 
 * 이론적으로 quick selection 은 최악의 경우 O(n) 이지만, 평균 케이스에서 오버헤드가 너무 큽니다.
 * nth_element() 라는 함수가 있어서 이것을 사용하면 됩니다.
 * */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* quick selection */
// const int MAX = 5000001;
// int matrix[MAX];

// void swap(int a, int b) {
//     int temp = matrix[a];
//     matrix[a] = matrix[b];
//     matrix[b] = temp;
// }

// int parition(int left, int right) {
//     int pivot = matrix[left];
//     int low = left + 1;
//     int high = right;

//     while (low <= high) {
//         while (pivot >= matrix[low] && low <= right)
//             low++;

//         while (pivot <= matrix[high] && high >= (left + 1))
//             high--;

//         if (low <= high)
//             swap(low, high);
//     }
    
//     swap(left, high);
//     return high;
// }

// int quick_search(int left, int right, int m) {
//     int pivot = parition(left, right);
//     if (pivot == m) return matrix[pivot];
//     if (pivot > m) 
//         return quick_search(left, pivot - 1, m);
//     else if (pivot < m)
//         return quick_search(pivot + 1, right, m);
//     return -1;
// }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    nth_element(v.begin(), v.begin() + m - 1, v.end());
    cout << v[m - 1];
    return 0;
}