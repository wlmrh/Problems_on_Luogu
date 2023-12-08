#include <bits/stdc++.h>
using namespace std;

#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}

typedef struct{
  int start = 0, end = 0, length = 0;
}route;

int n, m, rst = 0, fa[5005]; route roads[200005];

int find(int node)
{
  return fa[node] == node? node : (find(fa[node]));
}

bool solve()
{
  int pos = 1;
  for(int i = 1; i <= n - 1; i++)
  {
    if(pos > m) return false;
    int a = find(roads[pos].start), b = find(roads[pos].end);
    if(a == b) {pos++; i--; continue;}
    rst += roads[pos].length;
    fa[b] = a;
  }
  return true;
}

bool cmp(route r1, route r2)
{
  return r1.length < r2.length;
}

int main()
{
  n = read(), m = read();  
  iota(fa, fa + n, 0);
  for(int i = 1; i <= m; i++)
  {
    roads[i].start = read(), roads[i].end = read(), roads[i].length = read();
  }
  sort(roads, roads + m, cmp);
  if(solve()) printf("%d", rst);
  else printf("orz");
  return 0;
}
