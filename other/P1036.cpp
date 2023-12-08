#include <bits/stdc++.h>
using namespace std;
int rst = 0, n, k;

bool isprime(long long num){
  double inter = sqrt(num);
  for(int i = 2; i <= inter ; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

void dfs(int arr[], int choose, int pos, int end, long long crt_sum){
  if(end - pos + 1 < choose) return;
  if(choose == 0){
    if(isprime(crt_sum)){
      rst++;
    }
    return;
  }
  for(int i = pos; i <= end; i++){
    if(end - i + 1 < choose) break;
    if(choose > 0){
      dfs(arr, choose - 1, i + 1, end, crt_sum + arr[i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> k; int a[n + 1];
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  dfs(a, k, 1, n, 0ll);
  cout << rst;
}