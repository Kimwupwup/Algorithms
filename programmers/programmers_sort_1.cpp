#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> saver;
    for (vector<int> command : commands)
    {
        saver.clear();
        for (int i = command[0] - 1; i < command[1]; i++)
        {
            saver.push_back(array[i]);
        }

        sort(saver.begin(), saver.end());
        for (int i = 0; i < saver.size(); i++)
        {
            cout << saver[i] << " ";
        }
        cout << endl;
        answer.push_back(saver[command[2] - 1]);
    }

    return answer;
}

int main()
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> ret = solution(array, commands);
    for (int temp : ret)
        cout << temp << endl;
    return 0;
}
