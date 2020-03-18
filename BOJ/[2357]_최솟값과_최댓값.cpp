/**
 * 백준 2357번 - 최솟값과 최댓값
 * 
 * TODO:
 * 세그먼트 트리
 * */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 100000;

vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> init(vector<pair<int, int>> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = {arr[start], arr[start]};
    int mid = (start + end) / 2;

    pair<int, int> a = init(tree, node * 2, start, mid);
    pair<int, int> b = init(tree, node * 2 + 1, mid + 1, end);

    return tree[node] = {min(a.first, b.first), max(a.second, b.second)};
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return {1111111111, 0};
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;

    pair<int, int> a = query(tree, node * 2, start, mid, left, right);
    pair<int, int> b = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return {min(a.first, b.first), max(a.second, b.second)};
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);

    tree.resize(tree_size);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    init(tree, 1, 0, n - 1);
    // cout << tree[1].first << " " << tree[1].second;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        pair<int, int> ret = query(tree, 1, 0, n - 1, a - 1, b - 1);
        cout << ret.first << " " << ret.second << "\n";
    }

    return 0;
}