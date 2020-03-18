/**
 * 백준 7578번 - 공장
 * 
 * TODO:
 * 세그먼트 트리 (누적합)
 * */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000001;

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int update(vector<int> &tree, int node, int idx, int start, int end) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) {
        return tree[node] = 1;
    }
    
    int mid = (start + end) / 2;
    
    return tree[node] = update(tree, node * 2, idx, start, mid) + update(tree, node * 2 + 1, idx, mid + 1, end);
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (1 + h);

    vector<int> tree(tree_size);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int matrix[MAX];
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        matrix[temp] = i;
    }

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += query(tree, 1, 0, n - 1, matrix[v[i]], n - 1);
        update(tree, 1, matrix[v[i]], 0, n - 1);
    }
    cout << ret << "\n";

    return 0;
}