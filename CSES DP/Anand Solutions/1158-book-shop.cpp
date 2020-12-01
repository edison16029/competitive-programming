#pragma GCC optimise('Ofast')
#pragma GCC optimise('unroll-loops')

#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int X = 1e5 + 1;

int n;
int h[N], s[N];
int dp[N][X];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int x;
  cin >> n >> x;
  for(int i = 0; i < n; ++i) cin >> h[i];
  for(int i = 0; i < n; ++i) cin >> s[i];
  dp[0][h[0]] = s[0];
  for(int i = 1; i < n; ++i) {
    for(int j = 0; j <= x; ++j) {
      dp[i][j] = dp[i - 1][j];
      if(j - h[i] >= 0) {
        dp[i][j] = max(dp[i][j], s[i] + dp[i - 1][j - h[i]]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= x; ++i) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << '\n';
}
