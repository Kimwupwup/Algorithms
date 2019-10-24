#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char matrix[50][50];
vector<int> answer;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= n - 8; j++)
        {
            for (int k = 0; k <= m - 8; k++)
            {
                char offset = i == 0 ? 'B' : 'W';
                int cnt = 0;
                for (int jj = j; jj < j + 8; jj++)
                {
                    for (int kk = k; kk < k + 8; kk++)
                    {
                        if (matrix[jj][kk] != offset)
                            cnt++;
                        offset = offset == 'B' ? 'W' : 'B';
                    }
                    offset = offset == 'B' ? 'W' : 'B';
                }
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer[0] << endl;
    return 0;
}