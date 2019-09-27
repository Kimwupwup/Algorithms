#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> subset;
vector<bool> v;

void DFS(int idx, int sum, int cnt, vector<int> nums) {
    if (cnt == 3) {
        subset.push_back(sum);
        return;
    }

    for (int i = idx + 1; i < nums.size(); i++) {
        DFS(i, sum + nums[i], cnt + 1, nums);
    }
}

int solution(vector<int> nums) {
    int answer = -1;

    for (int i = 0; i < nums.size(); i++) {
        DFS(i, nums[i], 1, nums);
    }
    sort(subset.begin(), subset.end(), greater<int>());
    v.resize(subset[0] + 1 , true);

    for (int k = 0; k < subset.size(); k++) {
        if (!v[subset[k]]) continue;
        for (int i = 2; i <= subset[k]; i++) {
            if (v[i]) {
                for (int j = 2; i * j <= subset[k]; j++) v[i * j] = false;
            }
        }
        if (v[subset[k]] == true) answer++;
    }
    

    return answer + 1;
}