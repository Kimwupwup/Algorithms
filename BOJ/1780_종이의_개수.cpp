#include <iostream>

using namespace std;

const int MAX = 2187;
int matrix[MAX][MAX];
int n;
int cnt[3];

void partition(int startY, int endY, int startX, int endX)
{
    int middleY1 = startY + ((endY - startY) / 3);
    int middleY2 = startY + ((endY - startY) / 3) * 2;
    int middleX1 = startX + ((endX - startX) / 3);
    int middleX2 = startX + ((endX - startX) / 3) * 2;

    int current = matrix[startY][startX];

    for (int i = startY; i < endY; i++)
    {
        for (int j = startX; j < endX; j++)
        {
            if (current != matrix[i][j])
                current = 2;
            if (current == 2)
            {
                partition(startY, middleY1, startX, middleX1);
                partition(startY, middleY1, middleX1, middleX2);
                partition(startY, middleY1, middleX2, endX);

                partition(middleY1, middleY2, startX, middleX1);
                partition(middleY1, middleY2, middleX1, middleX2);
                partition(middleY1, middleY2, middleX2, endX);

                partition(middleY2, endY, startX, middleX1);
                partition(middleY2, endY, middleX1, middleX2);
                partition(middleY2, endY, middleX2, endX);
                return;
            }
        }
    }
    if (current == -1)
        cnt[0]++;
    else if (current == 0)
        cnt[1]++;
    else if (current == 1)
        cnt[2]++;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    partition(0, n, 0, n);

    for (int a : cnt)
        cout << a << "\n";
}