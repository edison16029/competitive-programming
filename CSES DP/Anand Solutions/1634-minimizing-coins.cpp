#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int dp[N + 1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, x; cin >> n >> x;
  vector<int> arr(n);
  for(auto& x: arr) {
    cin >> x;
  }
  sort(arr.begin(), arr.end());
  dp[0] = 0;
  for(int i = 1; i <= x; ++i) {
    dp[i] = INT_MAX;
    for(auto y: arr) {
      if(i - y < 0 || dp[i - y] == INT_MAX) continue;
      dp[i] = min(dp[i], 1 + dp[i - y]);
    }
  }
  if(dp[x] == INT_MAX) cout << -1 << '\n';
  else cout << dp[x] << "\n";
}