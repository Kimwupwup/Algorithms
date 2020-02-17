/**
 * 백준 3830번 - 교수님은 기다리지 않는다.
 * 
 * TODO:
 * DFS(시간 초과)
 * Union find
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

long long parent[MAX];
long long dist[MAX];
long long union_size[MAX];

int n, m;

int union_find(int idx) {
    if (idx == parent[idx])
        return idx;
    else {
        long long root = union_find(parent[idx]);
        dist[idx] += dist[parent[idx]];
        return parent[idx] = root;
    }
}

void make_union(long long a, long long b, long long w) {
    int parent_a = union_find(a);
    int parent_b = union_find(b);

    if (parent_a != parent_b) {
        if (union_size[parent_a] > union_size[parent_b]) {
            parent[parent_b] = parent_a;
            long long temp = dist[b] - dist[a] - w;
            dist[parent_b] -= temp;
            union_size[parent_a] += union_size[parent_b];
            union_size[parent_b] = 1;
        } 
        else {
            parent[parent_a] = parent_b;
            long long temp = dist[b] - dist[a] - w;
            dist[parent_a] += temp;
            union_size[parent_b] += union_size[parent_a];
            union_size[parent_a] = 1;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            dist[i] = 0;
            union_size[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            char c;
            long long a, b, w;

            cin >> c;
            if (c == '!') {
                cin >> a >> b >> w;
                make_union(a, b, w);
            }
            else if (c == '?') {
                cin >> a >> b;

                long long parent_a = union_find(a);
                long long parent_b = union_find(b);
                if (parent_a == parent_b)
                    cout << dist[parent_b] - dist[parent_a] << "\n";
                else 
                    cout << "UNKNOWN\n";
            }
        }
    }

    return 0;
}