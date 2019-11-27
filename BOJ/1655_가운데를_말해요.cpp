#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        if (maxHeap.empty())
            maxHeap.push(temp);
        else if (maxHeap.size() == minHeap.size())
            maxHeap.push(temp);
        else
            minHeap.push(temp);

        if (!maxHeap.empty() && !minHeap.empty() && !(maxHeap.top() <= minHeap.top()))
        {
            int a = maxHeap.top();
            int b = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            maxHeap.push(b);
            minHeap.push(a);
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}