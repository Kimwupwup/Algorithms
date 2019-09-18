#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int current_weight = 0;
    int time = 0;
    queue<int> ready;
    queue<pair<int, int>> bridge;

    for (int truck_weight : truck_weights)
    {
        ready.push(truck_weight);
    }

    while (!ready.empty() || !bridge.empty())
    {

        if (weight >= current_weight + ready.front())
        {
            if (!ready.empty())
            {
                int truck = ready.front();
                ready.pop();
                current_weight += truck;
                bridge.push({truck, bridge_length});
            }
        }

        int size = bridge.size();

        for (int i = 0; i < size; i++)
        {
            int truck = bridge.front().first;
            int leng = bridge.front().second;
            bridge.pop();
            leng--;

            bridge.push({truck, leng});
        }

        if (bridge.front().second == 0)
        {
            int truck = bridge.front().first;
            bridge.pop();
            current_weight -= truck;
        }
        answer++;
    }

    return answer + 1;
}

int main()
{
    vector<int> bridge_lengths = {2, 100, 100};
    vector<int> weights = {10, 100, 100};
    vector<vector<int>> truck_weights = {{7, 4, 5, 6}, {10}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}};

    for (int i = 0; i < bridge_lengths.size(); i++)
    {
        cout << solution(bridge_lengths[i], weights[i], truck_weights[i]) << '\n';
    }
}