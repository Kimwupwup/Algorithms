/**
 * 백준 5639번 - 이진 검색 트리
 * 트리 문제
 * 
 * TODO:
 * 이진 탐색 트리의 전위 순회는 트리에 노드를 넣는 순서와 동일하므로
 * 순서대로 노드를 넣고 그 토대로 후위 순회를 진행하면 된다.
 * 메모리 및 입력 부분을 신경써야 한다.
 * */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data = 0;
    node *left = NULL;
    node *right = NULL;
};

void post_order(node *tmp) {
    if (tmp->left != NULL)
        post_order(tmp->left);
    if (tmp->right != NULL)
        post_order(tmp->right);
    cout << tmp->data << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int temp;
    cin >> temp;
    node *root = new node;
    root->data = temp;

    while (cin >> temp) {
        node *parent = root;
        node *tmp = new node;
        tmp->data = temp;        

        while (true) {
            if (parent->data > tmp->data) {
                if (parent->left != NULL) 
                    parent = parent->left;                
                else {
                    parent->left = tmp;
                    break;
                }                    
            }
            else {
                if (parent->right != NULL) 
                    parent = parent->right;                
                else {
                    parent->right = tmp;
                    break;
                }
            }
        }
    }

    post_order(root);

    return 0;
}