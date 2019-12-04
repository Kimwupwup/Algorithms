/**
 * 백준 1991번 - 트리 순회
 * 트리 문제
 * 
 * TODO:
 * DFS 알고리즘
 * 
 * FIXME:
 * 전위: 방문 -> 왼쪽 -> 오른쪽
 * 중위: 왼쪽 -> 방문 -> 오른쪽
 * 후위: 왼쪽 -> 오른쪽 -> 방문
 * */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 26;
vector<pair<int, int>> nodes;
int n;

void DFS (int node, int type) {
    char ret = 'A' + node;
    if (type == 0) {        
        cout << ret;

        if (nodes[node].first != -1)
            DFS(nodes[node].first, type);\

        if (nodes[node].second != -1)
            DFS(nodes[node].second, type);
    } else if (type == 1) {
        if (nodes[node].first != -1)
            DFS(nodes[node].first, type);

        cout << ret;
        
        if (nodes[node].second != -1)
            DFS(nodes[node].second, type);
    } else if (type == 2) {
        
        if (nodes[node].first != -1)
            DFS(nodes[node].first, type);

        if (nodes[node].second != -1)
            DFS(nodes[node].second, type);
            
        cout << ret;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        char node, left, right;
        cin >> node >> left >> right;

        // . 을 입력했을 때, 예외처리
        if (left == '.') left = 'A' - 1;
        if (right == '.') right = 'A' - 1;

        nodes[node - 'A'] = {left - 'A', right - 'A'};
    }

    for (int i = 0; i < 3; i++) {
        DFS(0, i);
        cout << "\n";
    }
    return 0;
}