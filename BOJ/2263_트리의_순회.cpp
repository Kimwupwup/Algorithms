/**
 * 백준 2263번 - 트리의 순회
 * 트리 문제
 * 
 * FIXME:
 * 후위 순회의 마지막이 root 이다.
 * 후위 순회의 처음부분은 왼쪽 순회 부분, 그 다음 부분은 오른쪽 순회 부분이다.
 * 중위 순회의 root 왼쪽은 왼쪽 순회 부분, 오른쪽은 오른쪽 순회 부분이다.
 * 
 * 후위 순회에서 찾은 root를 중위 순회에서 바로 찾을 수 있는 방법이 필요하다.
 * 중위 순회에 들어있는 노드의 인덱스를 저장하면 된다.
 * 
 * 중위 순회: [ 왼 쪽 ] [ root ] [ 오 른 쪽 ]
 * 후위 순회: [ 왼 쪽 ] [ 오 른 쪽 ] [ root ]
 * 위 부분들에서 왼쪽과 오른쪽도 똑같은 성질을 가지고 있으므로,
 * 재귀적으로 분할하여 처리하면 된다.
 * 중위, 후위의 왼쪽, 오른쪽의 갯수는 같다.
 * */

#include <iostream>

using namespace std;

const int MAX = 100001;
int n;
int in_order[MAX];
int post_order[MAX];
int idx[MAX];

void divide (int in_start, int in_end, int post_start, int post_end) {

    // 일어날 수 없다.
    if (in_start > in_end || post_start > post_end) return;

    // root 는 post_order 의 맨 마지막이다.
    // 전위 순회 이므로 바로 출력한다.
    int root = post_order[post_end];
    cout << root << " ";

    // 왼쪽 순회 처리
    divide(in_start, idx[root] - 1, post_start, post_start + (idx[root] - in_start) - 1);
    
    // 오르쪽 순회 처리
    divide(idx[root] + 1, in_end, post_start + (idx[root] - in_start), post_end - 1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> in_order[i];
    
    for (int i = 0; i < n; i++)
        cin >> post_order[i];
    
    // root의 인덱스트를 쉽게 찾기 위해서 각 노드들의 인덱스를 저장한다.
    for (int i = 0; i < n; i++)
        idx[in_order[i]] = i;
    
    divide(0, n - 1, 0, n - 1);
    return 0;
}