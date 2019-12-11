/**
 * SW Expert 8888번 - 시험
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n, t, p;

vector<vector<int>> v;
vector<vector<int>> ret;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> n >> t >> p;
        
        v.clear();
        ret.clear();

        v.resize(n + 1);
        ret.resize(n + 1);
        for (int people = 1; people <= n; people++) {
            for (int test = 0; test < t; test++) {
                int ac;
                cin >> ac;
                v[people].push_back(ac);
            }
        }

        for (int test = 0; test < t; test++) {
            int cnt = 0;
            for (int people = 1; people <= n; people++) {
                if (v[people][test] == 0) {
                    cnt++;
                }
            }
            for (int people = 1; people <= n; people++) {
                if (v[people][test] == 1) {
                    ret[people].push_back(cnt);
                }
            }
        }

        int cost = 0;
        int grade = 1;
        for (int a : ret[p])
            cost += a;
        
        for (int people = 1; people <= n; people++) {
            int tmp_cost = 0;
            for (int tmp : ret[people]) {
                tmp_cost += tmp;
            }

            if (tmp_cost > cost) {
                grade++;
            }
            if (tmp_cost == cost && people != p && ret[people].size() > ret[p].size()) {
                grade++;
            }
            if (tmp_cost == cost && people != p && ret[people].size() == ret[p].size() && people < p) {
                grade++;
            }
        }
        cout << "#" << test_case << " " << grade << "\n";
    }
    return 0;
}