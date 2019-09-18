#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    vector<pair<int, int>> priorities_set;

    for (int i = 0; i < priorities.size(); i++) {
        priorities_set.push_back({i, priorities[i]});
    }

    while (!priorities_set.empty()) {
        int idx = priorities_set[0].first;
        int priority = priorities_set[0].second;
        int prev_size = priorities_set.size();
        priorities_set.erase(priorities_set.begin());

        for (int i = 0; i < priorities_set.size(); i++) {
            if (priority < priorities_set[i].second) {
                priorities_set.push_back({idx, priority});
                break;
            }
        }
        if (priorities_set.size() != prev_size) {
            answer++;
            if (idx == location) {
                return answer;
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> priorities = {{2, 1, 3, 2}, {1, 1, 9, 1, 1, 1}};
    vector<int> locations = {2, 0};

    for (int i = 0; i < 2; i++)
    {
        cout << solution(priorities[i], locations[i]) << endl;
    }
}