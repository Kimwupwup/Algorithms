/**
 * SW Expert 8934번 - 펠린드롬 공포증
 * 
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int matrix[3];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(matrix, 0, sizeof(matrix));

        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
            matrix[str[i] - 'a']++;
        
        int mini = min(matrix[0], min(matrix[1], matrix[2]));
        for (int i = 0; i < 3; i++)
            matrix[i] -= mini;
        
        bool ret = true;
        for (int i = 0; i < 3; i++)
            if (matrix[i] > 1)
                ret = false;

        if (ret)
            cout << "#" << t << " " << "YES" << "\n";
        else 
            cout << "#" << t << " " << "NO" << "\n";
    }
    return 0;
}