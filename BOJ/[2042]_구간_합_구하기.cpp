/**
 * 백준 2042번 - 구간 합 구하기
 * 
 * TODO:
 * 세그먼트 트리 기초
 * */

#include <bits/stdc++.h>
using namespace std;

vector<long long> v;

class Segment_tree {
public:
    long long size;
    vector<long long> tree;

    Segment_tree(int n) {
        size = ceil(log2(n));
        size = (1 << (size + 1));
        tree.resize(size);
        size = n;
    }

    long long init(int node, int left, int right) {
        if (left == right) {
            return tree[node] = v[left];
        }
        int mid = (left + right) / 2;
        return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
    }
    void init() {
        init(1, 0, size - 1);
    }

    long long query(int node, int left, int right, int node_left, int node_right) {
        if (node_left > right || node_right < left)
            return 0;
        
        if (node_left >= left && node_right <= right)
            return tree[node];

        int mid = (node_left + node_right) / 2;
        return query(node * 2, left, right, node_left, mid) + query(node * 2 + 1, left, right, mid + 1, node_right);
    }
    long long query(int left, int right) {
        return query(1, left, right, 0, size - 1);
    }

    long long update(int idx, int value, int node, int node_left, int node_right) {
        if (idx < node_left || idx > node_right)
            return tree[node];
        if (node_left == node_right)
            return tree[node] = value;

        int mid = (node_left + node_right) / 2;
        return tree[node] = update(idx, value, node * 2, node_left, mid) + update(idx, value, node * 2 + 1, mid + 1, node_right);
    }
    void update(int idx, int value) {
        update(idx, value, 1, 0, size - 1);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    Segment_tree seg_tree(n);
    seg_tree.init();
    
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg_tree.update(b - 1, c);
            v[b - 1] = c;            
        } else {
            cout << seg_tree.query(b - 1, c - 1) << "\n";
        }
    }

    return 0;
}