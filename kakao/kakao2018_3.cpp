#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string, int>> cashe;
    vector<int> cashesSize = {3, 3, 2, 5, 2, 0};
    vector<vector<string>> cities = 
        {{"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"},
        {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"},
        {"Jeju", "Pangyo", "NewYork", "newyork"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}};

    for (int k = 0; k < cashesSize.size(); k++)
    {
        for (int i = 0; i < cities[k].size(); i++)
        {
            for (int j = 0; j < cities[k][i].size(); j++)
            {
                cities[k][i][j] = tolower(cities[k][i][j]);
            }
        }
        int time = 0;
        cashe.clear();
        cashe.resize(cashesSize[k], {".", -1});

        for (int i = 0; i < cities[k].size(); i++)
        {
            bool isFound = false;
            int mini = 1000000000;
            int idx;
            for (int j = 0; j < cashe.size(); j++)
            {
                if (mini > cashe[j].second)
                {
                    mini = cashe[j].second;
                    idx = j;
                }
                if (cashe[j].first == ".")
                {
                    cashe[j] = {cities[k][i], i};
                    isFound = true;
                    time += 5;
                    cout << "5 ";
                    break;
                }
                else if (cashe[j].first == cities[k][i])
                {
                    cashe[j].second = i;
                    isFound = true;
                    time += 1;
                    cout << "1 ";
                    break;
                }
            }
            if (isFound == false)
            {
                cashe[idx] = {cities[k][i], i};
                time += 5;
                cout << "[5] ";
            }
        }
        cout << " : " << time << endl;
    }
    return 0;
}