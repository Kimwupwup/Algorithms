/**
 * 백준 10868번 - 최솟값
 * 
 * TODO:
 * 세그먼트 트리
 * */
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> v;
vector<int> tree;

int init(int node, int start, int end) {
    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return INT_MAX;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);

    v.resize(n);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(1, 0, n - 1, a, b) << "\n";
    }

    return 0;
}