/**
 * 백준 17281번 - ⚾
 * 
 * TODO:
 * 브루트 포스
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50;
int matrix[MAX][9];
vector<int> v;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 2; i <= 9; i++) {
        v.push_back(i);
    }

    int ret = 0;
    do {
        vector<int> temp = v;
        int score = 0;
        temp.insert(temp.begin() + 3, 1);

        int idx = 0;

        for (int i = 0; i < n; i++) {
            queue<int> q;
            int out = 3;
            while (out) {
                int hit = matrix[i][temp[idx] - 1];

                if (hit == 0) {
                    out--;
                }
                else {
                    int size = q.size();
                    for (int j = 0; j < size; j++) {
                        int cur = q.front();
                        q.pop();

                        if (cur + hit >= 4)
                            score++;
                        else 
                            q.push(cur + hit);
                    }
                    if (hit == 4)
                        score++;
                    else
                        q.push(hit);
                }
                idx = (idx + 1) % 9;
            }
        }
        ret = max(ret, score);
    } while (next_permutation(v.begin(), v.end()));
    cout << ret << "\n";
    return 0;
}