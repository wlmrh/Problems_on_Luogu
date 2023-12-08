#include <bits/stdc++.h>
using namespace std;
typedef struct is
{
  int num;
  int weight;
  double value;
}issue;
vector<issue> piles(1005);
bool cmp(issue a, issue b);

int main()
{
  ios::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  vector<int> num(n + 1);
  iota(num.begin(), num.end(), 0);
  for(int i = 1; i <= n; i++)
  {
    cin >> piles[i].weight >> piles[i].value;
    piles[i].value /= piles[i].weight;
  }
  sort(piles.begin(), piles.end(), cmp);
  int crt = 0;
  double money = 0;
  while(t > 0 && crt <= n)
  {
    if(piles[crt].weight <= t)
    {
      t -= piles[crt].weight;
      money += piles[crt].value * piles[crt].weight;
      crt++;
      continue;
    }
    money += t * piles[crt].value;
    break;
  }
  cout << fixed << setprecision(2) << money;
}

bool cmp(issue a, issue b)
{
  return a.value > b.value;
}