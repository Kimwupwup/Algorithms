#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red)
{
    vector<int> answer;
    vector<pair<int, int>> v;
    int height, width;
    int sum = brown + red;

    bool isFound = false;
    for (int i = 1; i <= sum; i++)
    {
        if (sum % i == 0)
        {
            if (i >= (sum / i))
            {
                height = i;
                width = sum / i;
                if (width <= 2) continue;
                v.push_back({height, width});
            }
        }
    }

    int red_height;
    int red_width;
    for (int i = 1; i <= red; i++)
    {
        if (red % i == 0)
        {
            red_height = i;
            red_width = red / i;

            for (int j = 0; j < v.size(); j++) {
                height = v[j].first;
                width = v[j].second;

                int height_sol = height - red_height;
                int width_sol = width - red_width;
                if (height_sol == 2 && width_sol == 2)
                {
                    answer.push_back(height);
                    answer.push_back(width);
                    return answer;
                }
            }
        }
    }
}


int main()
{
    vector<pair<int, int>> brown_red = {{10, 2}, {8, 1}, {24, 24}};

    for (pair<int, int> p : brown_red)
    {
        int brown = p.first;
        int red = p.second;

        cout << "[answer]\n";
        vector<int> ret = solution(brown, red);
        for (int temp : ret)
        {
            cout << temp << endl;
        }
        cout << endl;
    }
}