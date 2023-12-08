#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main()
{
  int n, m;
  cin >> n >> m;
  arr.resize(n + 1);
  for(int i = 1 ; i <= n; i++)
  {
    cin >> arr[i];
  }
  for(int i = 1; i <= m; i++)
  {
    int num;
    cin >> num;
    cout << arr[num] << endl;
  }
  return 0;
}