#include <iostream>

using namespace std;

int matrix[15][15];

int main()
{
    int test;
    int k, n;
    for (int i = 0; i < 15; i++)
    {
        matrix[0][i] = i;
    }
    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            for (int l = 1; l <= j; l++)
            {
                matrix[i][j] += matrix[i - 1][l];
            }
        }
    }
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> k >> n;
        cout << matrix[k][n] << endl;
    }
}