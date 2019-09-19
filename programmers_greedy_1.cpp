#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> people(n + 1);

    for (int idx : lost)
    {
        people[idx] = -1;
    }
    for (int idx : reserve)
    {
        if (people[idx] == -1) people[idx] = 0;
        else people[idx] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (people[i] == -1)
        {
            if (i - 1 > 0 && people[i - 1] == 1) {
                people[i] = 0;
                people[i - 1] = 0;
            }
            else if (i + 1 <= n && people[i + 1] == 1) {
                people[i] = 0;
                people[i + 1] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (people[i] != -1) answer++;
    }
    return answer;
}

int main()
{
    vector<int> n = {5, 5, 3};
    vector<vector<int>> losts = {{2, 4}, {2, 4}, {3}};
    vector<vector<int>> reserves = {{1, 3, 5}, {3}, {1}};

    for (int i = 0; i < n.size(); i++)
    {
        cout << solution(n[i], losts[i], reserves[i]) << endl;
    }
}