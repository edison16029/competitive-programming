#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int mod = 1e9 + 7;

string arr[N];
int dp[N][N];
int n;
int dx[] = {-1, 0};
int dy[] = {0, -1};

bool valid(int x, int y) {
  return (x >= 0 && x < n) && (y >= 0 && y < n) && (arr[x][y] != '*');
}

int add(int a, int b) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  dp[0][0] = (arr[0][0] == ".");
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if((i == j && j == 0) || (!valid(i, j))) continue;
      dp[i][j] = 0;
      for(int k = 0; k < 2; ++k) {
        int p = i + dx[k], q = j + dy[k];
        if(valid(p, q)) {
          dp[i][j] = add(dp[i][j], dp[p][q]);
        }
      }
    }
  }
  cout << dp[n - 1][n - 1] << "\n";
}