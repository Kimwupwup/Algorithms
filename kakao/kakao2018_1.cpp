#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toBinary(int n, int num)
{
    string ret;
    while (num != 0)
    {
        ret += (num % 2) + '0';
        num /= 2;
    }
    while (ret.size() != n)
    {
        ret += '0';
    }
    reverse(ret.begin(), ret.end());
    //cout << ret << endl;
    return ret;
}
void solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> matrix1;
    vector<string> matrix2;

    for (int temp : arr1)
        matrix1.push_back(toBinary(n, temp));

    for (int temp : arr2)
        matrix2.push_back(toBinary(n, temp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix2[i][j] == '1' || matrix1[i][j] == '1')
            {
                cout << '#';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main()
{
    int n = 6;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};
    solution(n, arr1, arr2);
}