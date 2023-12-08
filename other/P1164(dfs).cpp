#include<bits/stdc++.h>
using namespace std;
int a[101], m, n;
int methods = 0;
void dfs(int money, int ord);

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  dfs(m, 1);
  cout << methods;
  return 0;
}

void dfs(int money, int ord)
{
  if(money < 0) return;
  if(money == 0) {methods++; return;}
  if(ord == n + 1) return;
  dfs(money - a[ord], ord + 1);
  dfs(money, ord + 1);
}