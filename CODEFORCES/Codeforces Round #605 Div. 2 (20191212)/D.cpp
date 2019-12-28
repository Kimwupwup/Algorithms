#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> ret;
int n;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        ret.clear();
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ret.push_back(v[j]);
        }
        for (int j = 1; j < n - 1; j++) {
            if (ret[i] > ret[i - 1]) {
                
            }
        }
    }


    return 0;
}