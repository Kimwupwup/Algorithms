#include <iostream>
#include <queue>

using namespace std;

int m, n;
pair<pair<int, int>, int> start, finish;
int matrix[101][101];
bool visited[101][101][5];
vector<pair<int, int>> moveDir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int BFS()
{
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{start.first.first, start.first.second}, {start.second, 0}});
  visited[start.first.first][start.first.second][start.second] = true;

  while (!q.empty())
  {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int dir = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (y == finish.first.first && x == finish.first.second && dir == finish.second)
    {
      return cnt;
    }

    for (int i = 1; i <= 3; i++)
    {
      int nextY = y + moveDir[dir].first * i;
      int nextX = x + moveDir[dir].second * i;

      if (visited[nextY][nextX][dir])
        continue;

      if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n && matrix[nextY][nextX] == 0)
      {
        visited[nextY][nextX][dir] = true;
        q.push({{nextY, nextX}, {dir, cnt + 1}});
      }
      else
      {
        break;
      }
    }

    for (int i = 1; i <= 4; i++)
    {
      if (dir != i && !visited[y][x][i])
      {
        visited[y][x][i] = true;
        if ((dir == 1 && i == 2) || (dir == 2 && i == 1) || (dir == 3 && i == 4) || (dir == 4 && i == 3))
        {
          q.push({{y, x}, {i, cnt + 2}});
        }
        else
        {
          q.push({{y, x}, {i, cnt + 1}});
        }
      }
    }
  }
  return -1;
}

int main()
{
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];

  cin >> start.first.first >> start.first.second >> start.second;
  cin >> finish.first.first >> finish.first.second >> finish.second;

  start.first.first -= 1;
  start.first.second -= 1;
  finish.first.first -= 1;
  finish.first.second -= 1;

  cout << BFS() << endl;
  return 0;
}