/**
 * 백준 17135번 - 캐슬 디펜스
 * 
 * TODO:
 * next_permutation, 브루트 포스
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
vector<pair<int, int>> matrix;
vector<int> archer;
int n, m, d;
int ret = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            if (temp)
                matrix.push_back({i, j});
        }
    }

    for (int i = 0; i < m - 3; i++)
        archer.push_back(0);
    for (int i = 0; i < 3; i++)
        archer.push_back(1);
    
    do {
        int cnt = 0;
        vector<pair<int, int>> temp = matrix;

        vector<int> v;
        for (int i = 0; i < archer.size(); i++)
            if (archer[i])
                v.push_back(i);
        
        while (!temp.empty()) {
            int y = n;
            vector<int> target;

            for (int i = 0; i < v.size(); i++) {
                int x = v[i];
                int target_x = temp[0].second;
                int idx = 0;
                int dist = abs(y - temp[0].first) + abs(x - temp[0].second);

                for (int j = 1; j < temp.size(); j++) {
                    int temp_dist = abs(y - temp[j].first) + abs(x - temp[j].second);

                    if (dist > temp_dist) {
                        target_x = temp[j].second;
                        idx = j;
                        dist = temp_dist;
                    }
                    else if (dist == temp_dist && target_x > temp[j].second) {
                        target_x = temp[j].second;
                        idx = j;
                    }
                }

                if (d >= dist) {
                    target.push_back(idx);
                }
            }

            target.erase(unique(target.begin(), target.end()), target.end());
            sort(target.begin(), target.end(), greater<int>());

            for (int i = 0; i < target.size(); i++) {
                temp.erase(temp.begin() + target[i]);
                cnt++;
            }

            if (temp.empty())
                break;
            
            vector<pair<int, int>> copy_temp;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].first < n - 1) {
                    copy_temp.push_back({temp[i].first + 1, temp[i].second});
                }
            }
            temp = copy_temp;
        }
        ret = max(ret, cnt);
    } while (next_permutation(archer.begin(), archer.end()));

    cout << ret << "\n";
    return 0;
}