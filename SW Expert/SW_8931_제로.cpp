/**
 * SW Expert 8931번 - 제로
 * 
 * Stack
 * */
#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    
    int t;

    cin >> t;
    int saver = t;
    while (t--) {
        stack<int> st;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            if (temp != 0)
                st.push(temp);
            else {
                if (!st.empty())
                    st.pop();
            }
        }

        long long ret = 0;
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        cout << "#" << saver - t << " " << ret << "\n";
    }
    return 0;
}