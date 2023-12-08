#include <bits/stdc++.h>
using namespace std;
int l[14] = {0}, col[14] = {0}, crs1[14] = {0}, crs2[14] = {0}, ans[14] = {0}, n;

int main()
{
  cin >> n;
  dfs(1);
}

//(line, i)点
void dfs(int line)
{
  if(line == n + 1) return;
  for(int i = 1; i <= n; i++)
  {
    if(col[i] == 0 && crs2[line] = 0 && crs1[i] == 0)
    {
      col[i] = 1; crs2[line] = 1; crs1[i] = 1;
      dfs(line + 1);
      col[i] = 0; crs2[line] = 0; crs1[i] = 0;
    }
  }
  return 0;
}