#include<bits/stdc++.h>
using namespace std;
bool cmp(int num1, int num2);
vector<int> wait;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int num[n + 1] = {0};
  double time = 0;
  iota(num + 1, num + n + 1, 1);
  for(int i = 0; i < n; i++)
  {
    int inter;
    cin >> inter;
    wait.push_back(inter);
  }
  sort(num + 1,num + n + 1, cmp);
  for(int i = 1; i <= n; i++)
  {
    time += wait[num[i] - 1] * (n - i);
  }
  for(int i = 1; i <= n; i++)
  {
    cout << num[i] << ' ';
  }
  cout << fixed << setprecision(2) << '\n' << time / (1ll * n);
  return 0;
}

bool cmp(int num1, int num2)
{
  return wait[num1 - 1] < wait[num2 - 1];
}