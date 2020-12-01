#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
const int mod = 1e9 + 7;

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
  int n, x; cin >> n >> x;
  vector<int> arr(n);
  for(auto& x: arr) {
    cin >> x;
  }
  sort(arr.begin(), arr.end());
  dp[0] = 1;
  for(int i = 1; i <= x; ++i) {
    dp[i] = 0;
    for(auto y: arr) {
      if(i - y < 0 || dp[i - y] == INT_MAX) continue;
      dp[i] = add(dp[i], dp[i - y]);
    }
  }
  cout << dp[x] << "\n";
}