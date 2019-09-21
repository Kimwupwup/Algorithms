#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int left = -30001;
    int right = 30001;
    sort(routes.begin(), routes.end());
    for (int i = 0; i < routes.size(); i++) {
        if (left <= routes[i][0] && right >= routes[i][0]) left = routes[i][0];
        if (left <= routes[i][1] && right >= routes[i][1]) right = routes[i][1];

        if (left != routes[i][0] && right != routes[i][1]) {
            answer++;
            left = routes[i][0];
            right = routes[i][1];
        }     
    }
    
    return answer + 1;
}

int main() {
    vector<vector<int>> routes = {
        {-20, 15},
        {-14, -5},
        {-18, -13},
        {-5, -3}
    };

    cout << solution(routes);
}