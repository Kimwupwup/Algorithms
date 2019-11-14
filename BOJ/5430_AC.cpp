/* 백준 5430번 AC - Wuppu */
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

deque<int> dq;
int t, n;
string p, number;
bool isFront = true;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        isFront = true;
        dq.clear();
        cin >> p;
        cin >> n;
        cin >> number;
        
        int num = 0;
        int prod = 1;

        for (int j = number.size() - 2; j > 0; j--)
        {
            if (number[j] >= '0' && number[j] <= '9')
            {
                num += (number[j] - '0') * prod;
                prod *= 10;
            }
            else
            {
                dq.push_front(num);
                num = 0;
                prod = 1;
            }
        }
        if (n != 0)
            dq.push_front(num);

        bool isFound = true;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == 'R')
                isFront = !isFront;
            else
            {
                if (dq.empty())
                {
                    cout << "error" << endl;
                    isFound = false;
                    break;
                }
                if (isFront)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (!isFound)
            continue;
        if (!isFront)
            reverse(dq.begin(), dq.end());
        cout << "[";
        for (int j = 0; j < dq.size(); j++)
        {
            cout << dq[j];
            if (j + 1 != dq.size())
                cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}