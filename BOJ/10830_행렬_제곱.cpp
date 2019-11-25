#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ones(5, vector<int>(5));

vector<vector<int>> matrixMul(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= 1000;
        }
    return c;
}

vector<vector<int>> matrixPow(vector<vector<int>> &a, long long B)
{
    if (B == 0)
        return ones;
    else if (B == 1)
        return a;
    else if (B % 2 == 0)
    {
        vector<vector<int>> temp = matrixPow(a, B / 2);
        return matrixMul(temp, temp);
    }
    else
    {
        vector<vector<int>> temp = matrixPow(a, B - 1);
        return matrixMul(temp, a);
    }
}

int main()
{
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> ret(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
        ones[i][i] = 1;
    }
    ret = matrixPow(A, B);

    for (vector<int> v : ret)
    {
        for (int i : v)
            cout << i % 1000 << " ";
        cout << "\n";
    }
    return 0;
}