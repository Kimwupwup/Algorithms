#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ret;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            if (pq.empty())
            {
                ret.push_back(0);
            }
            else
            {
                ret.push_back(pq.top());
                pq.pop();
            }
        }
        else
            pq.push(temp);
    }
    for (int a : ret)
        cout << a << "\n";
    return 0;
}