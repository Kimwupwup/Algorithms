#include <iostream>
#include <math.h>
#include <memory.h>

using namespace std;

const int MAX = 10001;
bool matrix[MAX];

int main()
{
    memset(matrix, true, sizeof(matrix));

    matrix[1] = false;
    for (int i = 2; i < sqrt(10001); i++)
        if (matrix[i])
            for (int j = i + i; j <= 10001; j += i)
                matrix[j] = false;

    int n, left, right;
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> n;

        for (int i = n / 2; i <= n; i++)
        {
            if (matrix[i] && matrix[n - i])
            {
                cout << n - i << " " << i << endl;
                break;
            }
        }

        /* 이게 아주 조금 더 빨랐다. */
        // left = n / 2;
        // right = n / 2;

        // while (true)
        // {
        //     while (!matrix[left])
        //         if (left > 0)
        //             left--;
        //     while (!matrix[right])
        //         if (right < n)
        //             right++;

        //     if (left + right == n)
        //     {
        //         cout << left << " " << right << endl;
        //         break;
        //     }
        //     else if (left + right < n)
        //         right++;
        //     else if (left + right > n)
        //         left--;
        // }
    }
    return 0;
}