#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6;

int dp[N + 1];

int add(int a, int b) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    dp[i] = 0;
    for(int j = 1; j <= 6; ++j) {
      if(i - j < 0) break;
      dp[i] = add(dp[i], dp[i - j]);
    }
  }
  cout << dp[n] << '\n';
}