#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
void DFS(int idx, int ret, vector<int> numbers, int target, int type) {
    if (type == 0) ret += numbers[idx];
    else if (type == 1) ret -= numbers[idx];

    if (idx == numbers.size() - 1 && target == ret) {
        ans++;
        return;
    }
    else if (idx == numbers.size() - 1 && target != ret) return;

    for (int i = 0; i < 2; i++) {
        DFS(idx + 1, ret, numbers, target, i);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    for (int i = 0; i < 2; i++) {
        DFS(0, 0, numbers, target, i);
    }
    return ans;
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, 3);

}