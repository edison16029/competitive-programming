#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 101;
const int mod = 1e9 + 7;

int dp[N][M];
int arr[N];
int n, m;

inline int add(int a, int b, int mod = mod) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

inline int mul(int a, int b, int mod = mod) {
  return (long long) a * b % mod;
}

int rec(int cur, int val) {
  if(cur == n) return 1;
  if(arr[cur] && abs(arr[cur] - val) > 1) return 0;
  int& cv = dp[cur][val];
  if(cv != -1) return cv;
  cv = 0;
  if(arr[cur]) cv = rec(cur + 1, arr[cur]);
  else {
    cv = rec(cur + 1, val);
    if(val < m) cv = add(cv, rec(cur + 1, val + 1));
    if(val > 1) cv = add(cv, rec(cur + 1, val - 1));
  } 
  return cv;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int ans = 0;
  if(arr[0]) {
    ans = rec(1, arr[0]);
  } else {
    for(int i = 1; i <= m; ++i) {
      ans = add(ans, rec(1, i));
    }
  }
  cout << ans << '\n';
}