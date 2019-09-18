#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    vector<int> temp;
    int size = heights.size();
    for (int i = 0; i < size; i++)
    {
        temp = heights;
        int height = temp[temp.size() - 1];
        temp.pop_back();
        heights.pop_back();

        while (!temp.empty())
        {
            int current_height = temp[temp.size() - 1];
            int current_idx = temp.size();
            temp.pop_back();

            if (height < current_height)
            {
                answer.push_back(current_idx);
                break;
            }
        }
        if (answer.size() == i)
        {
            answer.push_back(0);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
