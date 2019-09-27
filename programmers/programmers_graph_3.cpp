#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

int uni[5000];

int find(int idx) {
    if (idx == uni[idx]) return idx;
    return uni[idx] = find(uni[idx]);
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {     
        bool isFound = false;   
        for (int i = 1; i <= n; i++) {
            uni[i] = i;
        }
        
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j][0] == i || edges[j][1] == i) continue;

            int parent_f = find(edges[j][0]);
            int parent_s = find(edges[j][1]);

            if (parent_f == parent_s) {
                isFound = true;
                break;
            }
            uni[parent_s] = parent_f;
        }
        if (isFound == false) {
            answer += i;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3},{2,4},{3,4}};
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,1},{2,7},{3,6}};

    cout << solution(4, edges1);
    cout << endl;
    cout << solution(8, edges2);
}