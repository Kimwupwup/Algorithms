#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int temp = -1;
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int maxi = 0;
            for (int k = 0; k < 4; k++) {
                if (maxi < land[i - 1][k] && j != k) {
                    maxi = land[i - 1][k];
                }
            }
            land[i][j] += maxi;
        }
    }
    sort(land[land.size() - 1].begin(), land[land.size() - 1].end(), greater<int>());
    answer = land[land.size() - 1][0];
    return answer;
}