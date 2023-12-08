#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
#define inf 99999999
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  a.resize(n + 1, inf);
  b.resize(n + 1, inf);
  for(int i = 1; i <= n ; i++)
  {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int strength = 0;
  int pointer1 = 1, pointer2 = 1, crt = 1;
  for(int i = 1; i <= n - 1; i++)
  {
    int sml1 = (a[pointer1] > b[pointer2])? b[pointer2++] : a[pointer1++];
    int sml2 = (a[pointer1] > b[pointer2])? b[pointer2++] : a[pointer1++];
    int add = sml1 + sml2;
    strength += add;
    b[crt++] = add;
  }
  cout << strength;
  return 0;
}