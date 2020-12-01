#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int dp[N][N];

int rec(int l, int b) {
  if(l == b) return 0;
  int& lb = dp[l][b];
  if(lb != -1) return lb;
  lb = INT_MAX;
  for(int i = 1; i < l; ++i) lb = min(lb, 1 + rec(i, b) + rec(l - i, b));
  for(int i = 1; i < b; ++i) lb = min(lb, 1 + rec(l, i) + rec(l, b - i));
  return lb;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  int a, b; cin >> a >> b;
  cout << rec(a, b) << '\n';
}