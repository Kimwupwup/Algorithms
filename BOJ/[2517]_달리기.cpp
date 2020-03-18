/**
 * 백준 2517번 - 달리기
 * 
 * TODO:
 * map + lower_bound 
 * (시간초과 - distance() 함수가 O(n)에 실행되서 시간초과 
 * 그리고 iterator 를 사용하기에 인덱스를 반환해줄 방법이 없다.)
 * 
 * 세그먼트 트리
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 500000;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<int> &tree, int node, int start, int end, int idx) {
    if (!(start <= idx && idx <= end)) 
        return;

    tree[node] += 1;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx);
        update(tree, node * 2 + 1, mid + 1, end, idx);
    } 
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int h = (int)ceil(log2(MAX));
    int tree_size = 1 << (1 + h);

    vector<pair<int, int>> arr;
    vector<int> tree(tree_size);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back({temp, i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        arr[i].first = i;
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++) {
        int ret = i - query(tree, 1, 0, MAX, 0, arr[i].first) + 1;
        cout << ret << "\n";

        update(tree, 1, 0, MAX, arr[i].first);
    }
    return 0;
}