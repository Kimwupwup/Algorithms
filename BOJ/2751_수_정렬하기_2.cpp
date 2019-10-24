#include <iostream>
#include <queue>

using namespace std;
int n, input, i;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> input;
        pq.push(input);
    }
    for (i = 0; i < n; i++)
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    return 0;
}