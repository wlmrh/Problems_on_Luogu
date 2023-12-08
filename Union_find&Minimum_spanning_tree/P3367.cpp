#include <bits/stdc++.h>
using namespace std;
int n, m, z, x, y, fa[10005];

int find(int x)
{
  if(fa[x] == x) return x;
  return find(fa[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  iota(fa, fa + n + 1, 0);
  for(int i = 0; i < m ; i++)
  {
    cin >> z >> x >> y;
    if(z == 1) fa[find(y)] = find(x);
    else
    {
      if(find(x) == find(y)) printf("Y\n");
      else printf("N\n");
    }
  }
}