#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void init(vector<long long> &v, vector<long long> &tree, int node, int start, int end)
{
    if (start == end)
        tree[node] = start;
    else
    {
        int mid = (start + end) / 2;
        init(v, tree, node * 2, start, mid);
        init(v, tree, node * 2 + 1, mid + 1, end);

        if (v[tree[node * 2]] < v[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}

int query(vector<long long> &v, vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return tree[node];

    int middle = (start + end) / 2;
    int middle1 = query(v, tree, node * 2, start, middle, left, right);
    int middle2 = query(v, tree, node * 2 + 1, middle + 1, end, left, right);

    if (middle1 == -1)
        return middle2;
    else if (middle2 == -1)
        return middle1;
    else
    {
        if (v[middle1] < v[middle2])
            return middle1;
        else
            return middle2;
    }
}

long long getMax(vector<long long> &v, vector<long long> &tree, int start, int end)
{
    int n = v.size() - 1;
    int m = query(v, tree, 1, 1, n, start, end);

    long long area = (end - start + 1) * v[m];

    if (start < m)
    {
        long long temp = getMax(v, tree, start, m - 1);
        if (area < temp)
            area = temp;
    }
    if (end > m)
    {
        long long temp = getMax(v, tree, m + 1, end);
        if (area < temp)
            area = temp;
    }
    return area;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;

        vector<long long> v(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> v[i];

        // 세그먼트 트리
        int height = (int)ceil(log2(n));
        int tree_height = (1 << (height + 1));
        vector<long long> tree(tree_height);

        init(v, tree, 1, 1, n);
        cout << getMax(v, tree, 1, n) << endl;
    }
    return 0;
}