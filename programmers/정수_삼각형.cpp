#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    vector<vector<int>> cache(height);
    for (int i = 0; i < height; i++) {
        cache[i].resize(i + 1, 0);
    } 
    cache[0][0] = triangle[0][0];
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            cache[i + 1][j] = max(cache[i][j] + triangle[i + 1][j], cache[i + 1][j]);
            cache[i + 1][j + 1] = max(cache[i][j] + triangle[i + 1][j + 1], cache[i + 1][j + 1]);
        }
    }

    sort (cache.back().begin(), cache.back().end(), greater<int>());
    answer = cache.back().front();
    return answer;
}