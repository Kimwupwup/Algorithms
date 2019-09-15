#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<vector<int>> answer;
int visited[10000];
vector<vector<int>> node;
vector<vector<int>> tem;

void DFS(int idx, int type)
{
    int next;
    if (type == 0) {
        for (int i = 0; i < 2; i++)
        {
            next = node[idx][i];
            if (next == -1) continue;
            if (!visited[next])
            {
                answer[type].push_back(tem[next][2]);
                visited[next] = true;
                DFS(next, type);
            }
        }
    }
    if (type == 1) {
        for (int i = 0; i < 2; i++)
        {
            next = node[idx][i];
            if (next == -1) continue;
            if (!visited[next])
            {
                visited[next] = true;
                DFS(next, type);
            }
        }
        answer[type].push_back(tem[idx][2]);
    }
}
bool cmp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }
    return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    int size = nodeinfo.size();
    node.resize(size, {-1, -1});
    answer.resize(2);

    for (int i = 0; i < size; i++)
    {
        nodeinfo[i].push_back(i + 1);
        //cout << nodeinfo[i][2] << " " << nodeinfo[i][0] << " " << nodeinfo[i][1] << "\n";
    }

    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    tem = nodeinfo;
    
    int root = 0;

    for (int i = 1; i < size; i++)
    {
        int idx = root;
        while (true)
        {
            if (nodeinfo[idx][0] > nodeinfo[i][0])
            {
                if (node[idx][0] == -1)
                {
                    node[idx][0] = i;
                    break;
                }
                else
                    idx = node[idx][0];
            }
            else if (nodeinfo[idx][0] < nodeinfo[i][0])
            {
                if (node[idx][1] == -1)
                {
                    node[idx][1] = i;
                    break;
                }
                else
                    idx = node[idx][1];
            }
        }
    }
    answer[0].push_back(nodeinfo[0][2]);
    DFS(root, 0);
    memset(visited, false, sizeof(visited));
    DFS(root, 1);
    // for (vector<int> v : node)
    // {
    //     for (int temp : v)
    //     {
    //         cout << temp << " ";
    //     }
    //     cout << endl;
    // }
    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo =
        {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};

    vector<vector<int>> ret = solution(nodeinfo);
    for (vector<int> v : ret)
    {
        for (int temp : v)
        {
            cout << temp << " ";
        }
        cout << "\n";
    }
    return 0;
}