//这个版本的程序分别用-1,-2,-3来表示三个物种来体现三者关系，若遇到二者所属物种均未知的情况难以处理，所以需要换一个方法，只记录其father和child是谁
#include <bits/stdc++.h>
using namespace std;
int n, k, spe[50005] = {0}, rst = 0, cmd[3], isfst = 0, father[50005], child1[50005];
//三种物种分别用-1. -2, -3来表示
int find(int n)
{
  if(spe[n] < 0) return spe[n];
  if(spe[n] == n) return n;
  return find(spe[n]);//直到找到一个spe为真实物种或者其自身的一项
}

int fa(int sp1)
{
  if(sp1 == -1) return -3;
  if(sp1 == -2) return -1;
  if(sp1 == -3) return -2;
  return 0;
}

int child(int sp1)
{
  if(sp1 == -1) return -2;
  if(sp1 == -2) return -3;
  if(sp1 == -3) return -1;
  return 0;
}

bool fst_rule()//判断cmd1,cmd2能否为同一物种
{
  int a = find(cmd[1]), b = find(cmd[2]);
  if(a == b) return true;
  if(a < 0 && b < 0 && a != b) return false;//明确不为同一物种
  if(b < 0) {spe[a] = b; spe[cmd[1]] = b; father[a] = fa(b); father[cmd[1]] = fa(b); child1[a] = child(b); child1[cmd[1]] = child(b); return true;}//b物种已知，a未知
  if(a < 0) {spe[b] = a; spe[cmd[2]] = a; father[b] = fa(a); father[cmd[2]] = fa(a); child1[b] = child(a); child1[cmd[2]] = child(a); return true;}
  spe[b] = a; spe[cmd[2]] = a; child1[b] = child(a); father[b] = fa(a); child1[cmd[2]] = child(a); father[cmd[2]] = child(a);
  return true;//尚不知道是否为同一物种
}

//如果出现一个二号指令当前两个动物的物种都未知,则更改father数组与child数组
bool sec_rule()//判断cmd1是否能吃cmd2
{
  int a = find(cmd[1]), b = find(cmd[2]);
  if(fa(a) == b) return false;
  if(fa(b) == a) return true;
  if(a < 0) {spe[b] = child(a); spe[cmd[2]] = child(a); father[cmd[1]] = fa(spe[cmd[1]]); child1[cmd[1]] = child(spe[cmd[1]]); father[cmd[2]] = fa(spe[cmd[2]]); child1[cmd[2]] = child(spe[cmd[2]]); return true;}
  if(b < 0) {spe[a] = fa(b); spe[cmd[1]] = fa(b); father[cmd[1]] = fa(spe[cmd[1]]); child1[cmd[1]] = child(spe[cmd[1]]); father[cmd[2]] = fa(spe[cmd[2]]); child1[cmd[2]] = child(spe[cmd[2]]); return true;}
  father[b] = a; child1[a] = b;
  return true;
}

bool judge()
{
  if(cmd[1] > n || cmd[2] > n) return false;
  if(cmd[0] == 2 && cmd[1] == cmd[2]) return false;
  if(cmd[0] == 1) return fst_rule();
  if(cmd[0] == 2) return sec_rule();
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  iota(spe, spe + n + 1, 0); iota(father, father + n + 1, 0); iota(child1, child1 + n + 1, 0);
  for(int i = 1; i <= k; i++)
  {
    cin >> cmd[0] >> cmd[1] >> cmd[2];//读入指令
    if(!judge()) rst++;
    else//judge函数返回值为true,若为第一次则人为对于某些动物的种族进行分配
    {
      if(isfst == 0)
      {
        isfst++;
        if(cmd[0] == 1)
        {
          spe[cmd[1]] = spe[cmd[2]] = -1; father[cmd[1]] = father[cmd[2]] = -3; child1[cmd[1]] = child1[cmd[2]] = -2;
        }
        if(cmd[0] == 2)
        {
          spe[cmd[1]] = -1; spe[cmd[2]] = -2; child1[cmd[1]] = -2; child1[cmd[2]] = -3; father[cmd[1]] = -3; father[cmd[2]] = -1;
        }
      }
    }
  }
  printf("%d", rst); return 0;
}