#include <iostream>

using namespace std;
const int MAX = 128;
int matrix[MAX][MAX];
int n;
int cnt_white = 0;
int cnt_blue = 0;

void partition(int start_x, int last_x, int start_y, int last_y)
{
    int middle_x = (start_x + last_x) / 2;
    int middle_y = (start_y + last_y) / 2;
    int check = matrix[start_y][start_x];

    for (int i = start_x; i < last_x; i++)
    {
        for (int j = start_y; j < last_y; j++)
        {
            if (check == 1 && matrix[j][i] == 0)
                check = 2;
            else if (check == 0 && matrix[j][i] == 1)
                check = 2;
            if (check == 2)
            {
                partition(start_x, middle_x, start_y, middle_y);
                partition(middle_x, last_x, start_y, middle_y);
                partition(start_x, middle_x, middle_y, last_y);
                partition(middle_x, last_x, middle_y, last_y);
                return;
            }
        }
    }
    if (check == 1)
        cnt_blue++;
    else if (check == 0)
        cnt_white++;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    partition(0, n, 0, n);
    cout << cnt_white << "\n"
         << cnt_blue << endl;
}