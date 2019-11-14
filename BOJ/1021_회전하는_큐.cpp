/* 백준 1021번 회전하는 큐 - Wuppu */
#include <iostream>

using namespace std;

int n, m, cur, ret;
int matrix[51];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp, cnt = 0;
        cin >> temp;
        temp -= 1;

        while (cur != temp)
        {
            if (matrix[cur] == 0)
                cnt++;
            cur = (cur + 1) % n;
        }
        ret += n - i - cnt > cnt ? cnt : n - i - cnt;
        matrix[cur] = 1;
    }
    cout << ret << endl;
}

// deque<int> dq;
// vector<int> quest;
// int main()
// {
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         dq.push_back(i);
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int temp;
//         cin >> temp;
//         quest.push_back(temp);
//     }

//     deque<int> left;
//     deque<int> right;
//     int cnt = 0;
//     for (int i = 0; i < m; i++)
//     {
//         int leftCnt = 0;
//         int rightCnt = 0;
//         left = dq;
//         right = dq;
//         while (left.front() != quest[i])
//         {
//             leftCnt++;
//             int num = left.front();
//             left.pop_front();
//             left.push_back(num);
            
//         }
//         left.pop_front();

//         while (right.front() != quest[i])
//         {
//             rightCnt++;
//             int num = right.back();
//             right.pop_back();
//             right.push_front(num);
            
//         }
//         right.pop_front();

//         cnt += min(leftCnt, rightCnt);
//         if (leftCnt < rightCnt)
//         {
//             dq = left;
//         }
//         else
//             dq = right;
//     }
//     cout << cnt << endl;
//     return 0;
// }