#include <bits/stdc++.h>
using namespace std;
int m, n, t, sx, sy, fx, fy, rst = 0;//n列m行
bool cancross[6][6] = {0};//记录点能否通过
int roads[4][2] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};

bool isin(int x, int y)
{
  return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int crtx, int crty)
{
  if(!isin(crtx, crty)) return;
  if(crtx == fx && crty == fy)
  {
    rst++;
    return;
  }
  for(int i = 0; i < 4; i++)
  {
    if(cancross[crtx + roads[i][0]][crty + roads[i][1]] == 0)
    {
      cancross[crtx + roads[i][0]][crty + roads[i][1]] = 1;
      dfs(crtx + roads[i][0], crty + roads[i][1]);
      cancross[crtx + roads[i][0]][crty + roads[i][1]] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m >> t >> sx >> sy >> fx >> fy;
  for(int i = 0; i < t; i++)
  {
    int x, y; cin >> x >> y;
    cancross[x][y] = 1;
  }
  cancross[sx][sy] = 1;
  dfs(sx, sy);
  cout << rst;
  return 0;
}