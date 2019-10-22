#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution1(vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;
    int mid;
    sort(v.begin(), v.end());
    while (left <= right) {
        mid = (left + right) / 2;
        if (v[mid] == target) return mid;
        else if (v[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int solution(vector<int>& v, int target, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (v[mid] == target) return mid;
    else if (v[mid] > target) return solution(v, target, left, mid - 1);
    else return solution(v, target, mid + 1, right);
}

int main() {
    vector<int> v = {5, 3, 2, 1, 6, 4, 7};
    sort(v.begin(), v.end());
    cout << solution(v, 4, 0, v.size() - 1);
    return 0;
}