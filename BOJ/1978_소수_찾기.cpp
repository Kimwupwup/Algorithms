#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool matrix[1000];

int main()
{
    memset(matrix, true, sizeof(matrix));
    vector<int> v;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    matrix[1] = false;
    for (int i = 2; i <= 1000; i++)
    {
        if (matrix[i] == true)
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                matrix[j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (matrix[v[i]] == true)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}