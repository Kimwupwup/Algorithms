/**
 * 백준 3986번 - 좋은 단어
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int n;
int ret = 0;
vector<string> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        if (v[i].size() % 2)
            continue;
        bool good = true;
        vector<char> st;
        for (int j = 0; j < v[i].size(); j++) {
            if (st.empty())
                st.push_back(v[i][j]);
            else {
                if (v[i][j] == st[st.size() - 1])
                    st.pop_back();
                else {
                    st.push_back(v[i][j]);
                }
            }
        }
        if (st.empty())
            ret++;
    }
    cout << ret << "\n";
    return 0;
}