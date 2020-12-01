#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
int dp[N + 1];

int rec(int cur) {
  if(cur == 0) return 0;
  int& c = dp[cur];
  if(c != -1) return c;
  set<int> digits;
  int tmp = cur;
  while(tmp) {
    digits.emplace(tmp % 10);
    tmp /= 10;
  }
  c = INT_MAX;
  for(auto x: digits) {
    int res = rec(cur - x);
    if(res != INT_MAX) {
      c = min(c, 1 + res);
    }
  }
  return c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n;
  cout << rec(n) << '\n';
}