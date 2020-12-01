#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
const int K = 101;
const int mod = 1e9 + 7;

int dp[K + 1][N + 1];
int arr[K];
int n, k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> k >> n;
  for(int i = 0; i < k; ++i) {
    cin >> arr[i];
  }
  dp[0][0] = 1;
  for(int i = 1; i <= k; ++i) {
    for(int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      int rem = j - arr[i - 1];
      if(rem >= 0) {
        (dp[i][j] += dp[i][rem]) %= mod;
      }
    }
  }
  cout << dp[k][n] << '\n';
}