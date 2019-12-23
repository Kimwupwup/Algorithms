/**
 * SW Expert 7732번 - 시간 개념
 * 
 * */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v[2];

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {

        v[0].clear();
        v[0].resize(3);

        v[1].clear();
        v[1].resize(3);

        int from_sec, to_sec;
        string from, to;
        cin >> from;
        cin >> to;

        for (int i = 0; i < from.size(); i += 3) {
            int temp = (from[i] - '0') * 10 + (from[i + 1] - '0');
            v[0][i / 3] = temp;            
        }
        for (int i = 0; i < to.size(); i += 3) {
            int temp = (to[i] - '0') * 10 + (to[i + 1] - '0');
            v[1][i / 3] = temp;            
        }

        from_sec = v[0][2] + v[0][1] * 60 + v[0][0] * 60 * 60;
        to_sec = v[1][2] + v[1][1] * 60 + v[1][0] * 60 * 60;

        int ret = (to_sec - from_sec) < 0 ? (to_sec + 86400 - from_sec) : to_sec - from_sec;

        int hour = ret / 3600;
        int minute = (ret % 3600) / 60;
        int sec = (ret % 3600) % 60;
        
        string str_ret = "";
        if (hour < 10)
            str_ret += "0";
        str_ret += to_string(hour);
        str_ret += ":";
        if (minute < 10)
            str_ret += "0";
        str_ret += to_string(minute);
        str_ret += ":";
        if (sec < 10)
            str_ret += "0";
        str_ret += to_string(sec);
        
        cout << "#" << t << " " << str_ret << "\n";
    }
    return 0;
}