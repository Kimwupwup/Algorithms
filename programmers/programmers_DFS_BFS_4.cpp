#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool dfs(string from, vector<vector<string>> &ticket,
         vector<int> &usedTicket, vector<string> &answer, int cnt)
{
    answer.push_back(from);

    for (int i = 0; i < ticket.size(); i++)
    {
        if (ticket[i][0].compare(from) == 0 && usedTicket[i] == 0)
        {
            usedTicket[i] = 1;
            bool endFlag = dfs(ticket[i][1], ticket, usedTicket, answer, cnt + 1);

            usedTicket[i] = 0;
        }
    }
    if (cnt == ticket.size())
    {
        return true;
    }
    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<int> usedTicket(tickets.size());
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, usedTicket, answer, 0);
    return answer;
}

int main()
{
    vector<vector<vector<string>>> tickets =
        {
            {{"ICN", "JFK"},
             {"HND", "IAD"},
             {"JFK", "HND"}},
            {{"ICN", "SFO"},
             {"ICN", "ATL"},
             {"SFO", "ATL"},
             {"ATL", "ICN"},
             {"ATL", "SFO"}}};

    vector<string> ret = solution(tickets[1]);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret.size() << " " << ret[i] << endl;
    }
}