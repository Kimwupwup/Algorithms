#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(vector<int> ntm, vector<string> time_table)
{
    int minute;
    string ret;
    int cur_minute = 9 * 60;
    sort(time_table.begin(), time_table.end());

    vector<int> int_time_table;
    for (int i = 0; i < time_table.size(); i++)
    {
        int t_hour = 0;
        int t_minute = 0;
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                t_hour += (time_table[i][j] - '0') * 10;
            }
            else if (j == 1)
            {
                t_hour += time_table[i][j] - '0';
            }
            if (j == 3)
            {
                t_minute += (time_table[i][j] - '0') * 10;
            }
            else if (j == 4)
            {
                t_minute += time_table[i][j] - '0';
            }
        }
        int_time_table.push_back((t_hour * 60) + t_minute);
    }

    for (int i = 0; i < ntm[0]; i++)
    {
        int maximum = ntm[2];
        for (int j = 0; j < int_time_table.size(); j++)
        {
            if (int_time_table[j] == -1) continue;
            if (maximum == 0) break;
            if (i == ntm[0] - 1 && maximum == 1)
            {
                // cout << (cur_minute/60) << ":" << (cur_minute%60) << " " << "Cone" << " on" << endl;
                minute = min(int_time_table[j] - 1, cur_minute);
                maximum--;
                break;
            }
            
            if (cur_minute >= int_time_table[j])
            {
                int_time_table[j] = -1;
                maximum--;
            }
        }
        if (i == ntm[0] - 1 && maximum != 0)
        {
            minute = cur_minute;
        }
        cur_minute += ntm[1];
    }
    if (minute/60 < 10) cout << "0" << minute/60 << ":";
    else cout << minute/60 << ":";
    if (minute%60 < 10) cout << "0" << minute%60;
    else cout << minute%60;
    cout << endl;
}

int main()
{
    vector<vector<int>> ntm = {{1, 1, 5}, {2, 10, 2}, {2, 1, 2}, {1, 1, 5}, {1, 1, 1}, {10, 60, 45}};
    vector<vector<string>> time_table = 
        {{"08:00", "08:01", "08:02", "08:03"},
        {"09:10", "09:09", "08:00"},
        {"09:00", "09:00", "09:00", "09:00"},
        {"00:01", "00:01", "00:01", "00:01", "00:01"},
        {"23:59"},
        {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}};

    for (int i = 0; i < ntm.size(); i++)
    {
        solution(ntm[i], time_table[i]);
    }
    return 0;
}