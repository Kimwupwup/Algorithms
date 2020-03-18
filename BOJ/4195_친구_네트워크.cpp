/**
 * 백준 4195번 - 친구 네트워크
 * 
 * TODO:
 * map, union find, BFS(시간 초과)
 * 각 이름에 고유한 인덱스를 정해주는 방식이 필요하다. (map<string, int>)
 * 고유한 인덱스를 사용하여 union_find() 함수로 부모가 일치 여부를 알 수 있다.
 * 부모가 일치하지 않는 친구가 들어왔을 경우, 부모를 한 쪽으로 연결시키고
 * 카운터를 더해준다. (각 부모에 자식이 얼마나 있는지 저장한다.)
 * */
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAX = 200001;
int matrix[MAX];
int counter[MAX];

int union_find(int a) {
    if (matrix[a] == a) return a;
    return matrix[a] = union_find(matrix[a]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int cnt = 0;
        cin >> n;

        for (int i = 0; i <= n * 2; i++) {
            matrix[i] = i;
            counter[i] = 1;
        }

        map<string, int> m;
        string a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (m.count(a) == 0) m[a] = cnt++;
            if (m.count(b) == 0) m[b] = cnt++;

            int parent_a = union_find(m[a]);
            int parent_b = union_find(m[b]);

            if (parent_a != parent_b) {
                matrix[parent_b] = parent_a;
                counter[parent_a] += counter[parent_b];
                counter[parent_b] = 1;
            }
            cout << counter[parent_a] << "\n";
        }
    }

    return 0;
}