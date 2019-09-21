#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    vector<vector<int>> v(n + 1);
    vector<int> visited(n + 1);
    vector<int> leaf;
    queue<int> q;

    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);        
    }

    q.push(1);
    visited[1] = true;


    while (!q.empty()) {
        int size = q.size();
        leaf.clear();
        for (int j = 0; j < size; j++) {

            int idx = q.front();
            leaf.push_back(idx);
            q.pop();

            for (int i = 0; i < v[idx].size(); i++) {

                int next = v[idx][i];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }   
            }
        }        
    }

    answer = leaf.size();
    return answer;
}

int solution1(int n, vector<vector<int>> edge)
{
    int answer = 0;
    vector<vector<int>> v(n + 1);
    vector<int> visited(n + 1);
    vector<int> leaf;
    queue<int> q[2];
    bool b = true;

    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);        
    }

    q[b].push(1);
    visited[1] = true;

    while (!q[b].empty()) {
        leaf.clear();
        while (!q[b].empty()) {
            int idx = q[b].front();
            leaf.push_back(idx);
            q[b].pop();

            for (int i = 0; i < v[idx].size(); i++) {
                int next = v[idx][i];
                if (!visited[next]) {
                    visited[next] = true;
                    q[!b].push(next);
                }   
            }
        }
        b = !b;
    }
    answer = leaf.size();
    return answer;
}

int main()
{
    vector<vector<int>> vertex = {
        {3, 6},
        {4, 3},
        {3, 2},
        {1, 3},
        {1, 2},
        {2, 4},
        {5, 2}
    };

    cout << solution(6, vertex);
}