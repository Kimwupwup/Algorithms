#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;
int visited[101];

int DFS(int idx) {
    if (visited[idx] == idx) return idx;
    else {
        return visited[idx] = DFS(visited[idx]);
    }
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    
    for (int i = 0; i < n; i++) visited[i] = i;

    vector<vector<int>> v;
    for (int i = 0; i < costs.size(); i++) {
        v.push_back({costs[i][2], costs[i][0], costs[i][1]});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int start = DFS(v[i][1]);
        int end = DFS(v[i][2]);
        int cost = v[i][0];

        if (start != end) {
            visited[start] = end;
            answer += cost;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> cost = {
        {0, 1, 1},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 1},
        {2, 3, 8}
    };
    cout << solution(4, cost);
}