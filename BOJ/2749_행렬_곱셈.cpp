#include <iostream>
#include <memory.h>

using namespace std;
int n, m, k;

int A[100][100];
int B[100][100];
int ret[100][100];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> B[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l < k; l++)
                ret[i][l] += A[i][j] * B[j][l];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << ret[i][j] << " ";
        cout << endl;
    }
    return 0;
}