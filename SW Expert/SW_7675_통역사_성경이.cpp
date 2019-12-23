/**
 * SW Expert 7675번 - 통역사 성경이
 * 
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    vector<int> ret;
    vector<string> v;
    for (int t = 1; t <= T; t++) {
        ret.clear();
        v.clear();

        int n;
        cin >> n;
        ret.resize(n);

        int cnt = 0;
        while (true) {
            string str;
            if (cnt == n)
                break;
            
            getline(cin, str);

            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
                    cnt ++;
                }
            }
            v.push_back(str);
        }

        cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            int isUpper = 0;
            int isUnder = 0;
            int isNum = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == '.' || v[i][j] == '?' || v[i][j] == '!' || v[i][j] == ' ') {
                    if (isUpper == 1 && isNum == 0)
                        ret[cnt]++;
                    if (v[i][j] == '.' || v[i][j] == '?' || v[i][j] == '!')
                        cnt++;
                    isUpper = 0;
                    isUnder = 0;
                    isNum = 0;
                    continue;
                }

                if (v[i][j] <= 'Z' && v[i][j] >= 'A' && isUnder == 0)
                    isUpper++;   
                else if (isUpper == 0)
                    isUnder++;      
                else if (v[i][j] <= '9' && v[i][j] >= '0')
                    isNum++;    
            }
        }
        cout << "#" << t << " ";
        for (int a : ret)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}