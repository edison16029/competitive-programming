#include <bits/stdc++.h>

using namespace std;

const int N = 5001;

long long dp[N][N][2];
int arr[N];
int n;

long long rec(int l, int r, int who) {
  if(l > r) return 0;
  long long& lrw = dp[l][r][who];
  if(lrw != -1) return lrw;
  if(who == 0) {
    lrw = max(arr[l] + rec(l + 1, r, 1), 
              arr[r] + rec(l, r - 1, 1));
  } else {
    lrw = min(rec(l + 1, r, 0), 
              rec(l, r - 1, 0));
  }
  return lrw;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cout << rec(0, n - 1, 0) << '\n';
}