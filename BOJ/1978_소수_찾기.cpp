#include <iostream>
#include <vector>

using namespace std;

bool matrix[101];

int main()
{
    vector<int> v;
    int num;
    cin >> num;
    matrix[1] = false;

    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 2; i <= 100; i++)
    {
        if (matrix[i] == true)
        {
            for (int j = i * i; j <= 100; j += i)
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