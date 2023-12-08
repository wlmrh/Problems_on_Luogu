#include <bits/stdc++.h>
using namespace std;

int judge[1025][1025] = {{0}};
void modify(int a, int b, int c);

int main()
{
  int n = 0;
  cin >> n;
  modify(1, 1, pow(2,n));
  for(int i = 1; i <= pow(2,n); i++)
  {
    for(int j = 1; j <= pow(2,n); j++)
    {
      if(judge[i][j] == 0) printf("1 ");
      else printf("0 ");
    }
    printf("\n");
  }
  return 0;
}

void modify(int a, int b, int c)
{
  if(c == 2) {judge[a][b] = 1; return;}
  for(int i = a; i < a + c / 2; i++)
  {
    for(int j = b; j < b + c / 2; j++) judge[i][j] = 1;
  }
  modify(a + c / 2, b, c / 2);
  modify(a, b + c / 2, c / 2);
  modify(a + c / 2, b + c / 2, c / 2);
  return;
}