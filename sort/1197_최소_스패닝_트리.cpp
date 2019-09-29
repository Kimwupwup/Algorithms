#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int visited[10001];

struct node {
    int u;
    int v;
    int cost;

    bool operator<(node const &e) {
        return cost < e.cost;
    }
};

int find(int num) {
    if (num == visited[num]) return num;

    return visited[num] = find(visited[num]);
}

int main() {
    int answer = 0;
    int v, e;
    cin >> v >> e;

    vector<node> vec;

    for (int i = 0; i < v; i++) visited[i] = i;

    for (int i = 0; i < e; i++) {
        node n;
        cin >> n.u >> n.v >> n.cost;
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        int parent_u = find(vec[i].u);
        int parent_v = find(vec[i].v);

        if (parent_u == parent_v) continue;

        visited[parent_v] = parent_u;
        answer += vec[i].cost;
    }
    cout << answer;
}