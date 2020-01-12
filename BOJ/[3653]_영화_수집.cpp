/**
 * 백준 3653번 - 영화 수집
 * 
 * https://jaimemin.tistory.com/712
 * TODO:
 * Segment tree
 * */
#include <bits/stdc++.h>
using namespace std;

class segment_tree
{
public:
    int size;
    vector<long long> tree, collection;

    segment_tree(int n, int m)
    {
        size = n + m;
        collection.resize(n);
        tree.resize(4 * size, 0);
    }

    long long init(int node, int m, int left, int right)
    {
        if (left == right)
        {
            if (left >= m)
            {
                collection[left - m] = left;
                tree[node] = 1;
            }
            return tree[node];
        }
        int mid = (left + right) / 2;
        return tree[node] = init(node * 2, m, left, mid) + init(node * 2 + 1, m, mid + 1, right);
    }
    void init(int m)
    {
        init(1, m, 0, size - 1);
    }

    long long query(int node, int left, int right, int node_left, int node_right)
    {
        if (right < node_left || left > node_right) 
            return 0;
        if (left <= node_left && right >= node_right)
            return tree[node];
        
        int mid = (node_left + node_right) / 2;
        return query(node * 2, left, right, node_left, mid) + query(node * 2 + 1, left, right, mid + 1, node_right);
    }
    long long query(int left, int right) {
        return query(1, left, collection[right] - 1, 0, size - 1);
    }

    long long update(int idx, int node, int val, int node_left, int node_right) {
        if (idx < node_left || idx > node_right)
            return tree[node];
        if (node_left == node_right)
            return tree[node] = val;
        
        int mid = (node_left + node_right) / 2;
        return tree[node] = update(idx, node * 2, val, node_left, mid) + update(idx, node * 2 + 1, val, mid + 1, node_right);
    }

    long long update(int idx, int val) {
        return update(collection[idx], 1, val, 0, size - 1);
    }

    void change(int idx, int val) {
        collection[idx] = val;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        segment_tree seg_tree(n, m);
        seg_tree.init(m);

        int idx = m - 1;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;

            cout << seg_tree.query(0, num - 1) << " ";

            seg_tree.update(num - 1, 0);
            seg_tree.change(num - 1, idx);
            seg_tree.update(num - 1, 1);
            idx--;
        }
        cout << "\n";
    }

    return 0;
}