#include <bits/stdc++.h>
using namespace std;
typedef struct games
{
  int start, end;
}gm;
bool cmp(gm gm1, gm gm2);
gm arr[1000005];

int main()
{
  ios::sync_with_stdio(false);
  int n, enter = 0, crt = 1, crt_end = 0;
  cin >> n;
  arr[0].end = 0;
  for(int i = 1; i <= n; i++)
  {
    cin >> arr[i].start >> arr[i].end;
  }
  sort(arr + 1, arr + n + 1, cmp);
  while(crt <= n)
  {
    if(arr[crt].start >= crt_end)
    {
      enter++;
      crt_end = arr[crt].end;
    }
    crt++;
  }
  cout << enter;
}

bool cmp(gm gm1, gm gm2)
{
  return gm1.end < gm2.end;
}