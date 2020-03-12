/**
 * 백준 2493번 - 탑
 * 
 * TODO:
 * 스택
 * */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<pair<int, int>> st;
    vector<int> ret(n);
    st.push_back({v[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--) {
        int size = st.size();
        for (int j = 0; j < size; j++) {
            if (st.back().first <= v[i]) {
                ret[st.back().second] = i + 1;
                st.pop_back();
                continue;
            }
            break;
        }
        st.push_back({v[i], i});
    }
    for (int a : ret)
        cout << a << " ";
    cout << '\n';
    return 0;
}