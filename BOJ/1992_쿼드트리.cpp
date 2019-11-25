#include <iostream>
using namespace std;
const int MAX = 65;
char matrix[MAX][MAX];
int n;

void partition(int sy, int sx, int ey, int ex)
{
    int middleY = (sy + ey) / 2;
    int middleX = (sx + ex) / 2;
    char current = matrix[sy][sx];

    for (int i = sy; i < ey; i++)
    {
        for (int j = sx; j < ex; j++)
        {
            if (current != matrix[i][j])
                current = '2';
            if (current == '2')
            {
                cout << "(";
                partition(sy, sx, middleY, middleX);
                partition(sy, middleX, middleY, ex);
                partition(middleY, sx, ey, middleX);
                partition(middleY, middleX, ey, ex);
                cout << ")";
                return;
            }
        }
    }
    cout << current;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    partition(0, 0, n, n);
    return 0;
}