#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    // vector<pair<string, int>> v;
    // for (int i = 0; i < genres.size(); i++)
    // {
    //     v.push_back({genres[i], plays[i]});
    // }
    // sort(v.begin(), v.end(), greater<pair<string, int>>());

    map<string, vector<pair<int, int>>> m;

    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]].push_back({i, plays[i]});
    }

    while (!m.empty())
    {
        string maxi_name;
        int maxi = 0;
        map<string, vector<pair<int, int>>>::iterator iter;
        for (iter = m.begin(); iter != m.end(); ++iter)
        {
            int sum = 0;
            sort((iter->second).begin(), (iter->second).end(), cmp);
            cout << iter->first << endl;
            for (int i = 0; i < (iter->second).size(); i++)
            {
                cout << (iter->second)[i].first << " " << (iter->second)[i].second << endl;
                sum += (iter->second)[i].second;
            }

            if (sum > maxi)
            {
                maxi_name = iter->first;
                maxi = sum;
            }
        }

        for (int i = 0; i < min((int)m[maxi_name].size(), 2); i++)
        {
            answer.push_back(m[maxi_name][i].first);
        }
        m.erase(maxi_name);

    }
    
    return answer;
}

int main()
{
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> ret = solution(genres, plays);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}