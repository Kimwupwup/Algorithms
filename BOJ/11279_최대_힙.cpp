#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    priority_queue<int> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            if (pq.empty())
                v.push_back(0);
            else
            {
                v.push_back(pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(temp);
        }
    }
    for (int a : v)
        cout << a << "\n";
}