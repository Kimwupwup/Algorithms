#include <string>
#include <vector>

using namespace std;

long long d[101][100001];

int solution(int n, vector<int> money)
{
    int answer = 0;

    d[0][0] = 1;
    for (int i = money[0]; i <= n; i += money[0])
        d[0][i] = 1;

    for (int j = 1; j < money.size(); j++)
        for (int i = 0; i <= n; i++)
            if (i >= money[j])
                d[j][i] += d[j][i - money[j]] % 1000000007;

    answer = d[money.size() - 1][n];
    return answer;
}
