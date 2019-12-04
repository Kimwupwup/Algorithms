/**
 * 백준 5639번 - 이진 검색 트리
 * 트리 문제
 * 
 * TODO:
 * 이진 탐색 트리의 전위 순회는 트리에 노드를 넣는 순서와 동일하므로
 * 순서대로 노드를 넣고 그 토대로 후위 순회를 진행하면 된다.
 * */

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000000;

vector<pair<int, int>> tree(MAX, {0, 0});
int matrix[MAX];

void post_order(int node) {
    int left = tree[node].first;
    int right = tree[node].second;
    
    if (left == 0 && right == 0)
        return;

    post_order(left);
    post_order(right);
    cout << node << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int temp;
    int root;

    scanf("%d", &root);

    // 입력이 끝날 때까지.
    while (scanf("%d", &temp) != EOF) {      
        int cur = root;

        while (true) {
            if (cur < temp) {
                if (tree[cur].second != 0)
                    cur = tree[cur].second;
                else  {
                    tree[cur].second = temp;
                    break;
                }                    
            }                
            else if (cur > temp) {
                if (tree[cur].first != 0)
                    cur = tree[cur].first;
                else {
                    tree[cur].first = temp;
                    break;
                }                    
            }                
        }
    }
    post_order(root);

    return 0;
}