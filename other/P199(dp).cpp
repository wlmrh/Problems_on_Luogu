#include<bits/stdc++.h>
using namespace std;
int solve(int num);
//int angle(int len);
//void update(int& a, int& b, int& c);
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int result = solve(n);
  cout << result % 10000;
  return 0;
}
/*
int solve(int num)
{
  if(num == 1) return 1;
  if(num == 2) return 2;
  if(num == 3) return 5;
  return solve(num - 1) % 10000 + solve(num - 2) % 10000 + angle(num - 2)  * 2 % 10000;
}

int angle(int len)
{
  if(len == 1) return 1;
  if(len == 2) return 2;
  return solve(len - 1) + angle(len - 1);
}
*/
int solve(int num)
{
  if(num == 1) return 1;
  if(num == 2) return 2;
  if(num == 3) return 5;
  if(num == 4) return 11;
/*  int recent[3] = {0}, sum = 9;
  recent[1] = 5;
  recent[2] = 11;
  for(int i = 1; i <= num - 3; i++)
  {
    update(recent[1], recent[2], sum);
  }
  return recent[2];
*/
  int sum = 20, inter;
  int recent[3] = {0};
  recent[1] = 5;
  recent[2] = 11;
  for(int i = 1; i <= num - 4; i++)
  {
    inter = recent[2];
    recent[2] = (2 * sum - (recent[1] + recent[2]) + 10000) % 10000;
    recent[1] = inter;
    sum = (sum + recent[2] + 10000) % 10000;
  }
  return recent[2];
}

/*void update(int& a, int& b, int& c)
{
  int inter;
  inter = b;
  b = a + b + c;
  a = inter;
  c += b;
}*/