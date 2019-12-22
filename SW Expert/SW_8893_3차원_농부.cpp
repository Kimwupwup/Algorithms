/**
 * SW Expert 8893번 - 3차원 농부
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

vector<int> cow;
vector<int> horse;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;

        int cow_x, horse_x;
        cin >> cow_x >> horse_x;

        int dist_x = abs(horse_x - cow_x); 

        cow.clear();
        horse.clear();
        cow.resize(n);
        horse.resize(m);

        for (int i = 0; i < n; i++)
            cin >> cow[i];
        for (int i = 0; i < m; i++) 
            cin >> horse[i];

        sort(cow.begin(), cow.end());
        sort(horse.begin(), horse.end());

        int mini = INT_MAX;
        int cnt = 0;
        int cow_pt = 0, horse_pt = 0;
        while (true) {
            if (cow_pt >= cow.size() || horse_pt >= horse.size())
                break;
            int ret = abs(cow[cow_pt] - horse[horse_pt]);
            if (ret < mini) {
                mini = ret;
                cnt = 1;
            } else if (ret == mini) {
                cnt++;
            }

            if (cow[cow_pt] < horse[horse_pt]) {
                cow_pt++;
            } else {
                horse_pt++;
            }
        }
        
        cout << "#" << t << " " << mini + dist_x << " " << cnt << "\n";
    }
    return 0;
}