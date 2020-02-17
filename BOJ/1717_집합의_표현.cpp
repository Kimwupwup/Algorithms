/**
 * 백준 1717번 - 집합의 표현
 * 
 * TODO:
 * Union find
 * 
 * 0 을 입력받았을 때, a 의 루트를 b 의 루트로 바꿔주면서 하나의 집합으로 합친다.
 * 1 을 입력받았을 때, a 의 루트와 b 의 루트를 비교하여 같으면 같은 집합, 아니면 다른 집합
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int n, m;
int matrix[MAX];

int union_find(int idx) {
    if (idx == matrix[idx]) 
        return idx;
    return matrix[idx] = union_find(matrix[idx]);
}

void merge(int a, int b) {
    int parent_a = union_find(a);
    int parent_b = union_find(b);

    if (parent_a != parent_b) {
        matrix[parent_a] = matrix[parent_b];
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        matrix[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) {
            merge(a, b);
        }
        else {
            int parent_a = union_find(a);
            int parent_b = union_find(b);

            if (parent_a == parent_b)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }
    return 0;
}