#include <bits/stdc++.h>
using namespace std;
int fa[50005 * 3], cmd[3], rst = 0;

int find(int n)
{
  return fa[n] == n? n : (find(fa[n]));
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= 3 * n; i++)
  {
    fa[i] = i;
  }
  while(k--)
  {
    cin >> cmd[0] >> cmd[1] >> cmd[2];
    if(cmd[1] > n || cmd[2] > n)
    {
      rst++; continue;
    }
    //该语句为命令1时
    if(cmd[0] == 1)
    {
      if(find(cmd[1] + n) == find(cmd[2]) || find(cmd[2] + n) == find(cmd[1])) {rst++; continue;}
      fa[find(cmd[1])] = find(cmd[2]); fa[find(cmd[1] + n)] = find(cmd[2] + n); fa[find(cmd[1] + 2 * n)] = find(cmd[2] + 2 * n);
    }
    //
    //该命令为命令2时
    else
    {
      if(cmd[1] == cmd[2]) {rst++; continue;}
      fa[find(cmd[1] + n)] = find(cmd[2]); fa[find(cmd[1])] = find(cmd[2] + n * 2); fa[find(cmd[1] + 2 * n)] = find(cmd[2] + n);
    }
  }
  cout << rst;
  return 0;
}