#include <bits/stdc++.h>
using namespace std;
string cmd;
stack<char> cmd1;
vector<char> crt_cmd;
vector<char> crt_str;
vector<char> str;

int main()
{
  ios::sync_with_stdio(false);
  cin >> cmd;
  int len = cmd.length();
  for(int i = 0; i < len; i++)
  {
    char crt = cmd[i];
    if(crt != ']') {cmd1.push(crt); crt_str.push_back(crt); continue;}
    str.clear();
    crt_str.clear();
    while((crt = cmd1.top()) != '[')
    {
      crt_cmd.push_back(crt);
      cmd1.pop();
    }
    cmd1.pop();
    int num = 0, len = 0;
    for(vector<char>::reverse_iterator it = crt_cmd.rbegin(); it != crt_cmd.rend(); it++)
    {
      if(it == crt_cmd.rbegin()) num = *it - '0';
      str.push_back(*it);
    }
    len = str.capacity();
    for(int i = 0; i < num; i++)
    {
      for(int j = 0; j < len; j++)
      {
        cmd1.push(str[j]);
      }
    }
  }
  for(vector<char>::iterator it = str.begin(); it != str.end(); it++)
  {
    cout << *it;
  }
  for(vector<char>::reverse_iterator it = crt_str.rbegin(); it != crt_str.rend(); it++)
  {
    cout << *it;
  }
  return 0;
}