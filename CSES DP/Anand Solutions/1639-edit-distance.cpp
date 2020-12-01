#include <bits/stdc++.h>

using namespace std;

const int N = 5002;

int dp[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
  string t; cin >> t;
  for(int i = 0; i <= s.size(); ++i) {
    for(int j = 0; j <= t.size(); ++j) {
      if(i == 0) dp[i][j] = j;
      else if(j == 0) dp[i][j] = i;
      else if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    }
  }
  cout << dp[s.size()][t.size()] << '\n';
}