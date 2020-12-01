#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  bitset<M> dp; dp.reset();
  dp[0] = 1;
  for(int i = 0; i < n; ++i) {
    bitset<M> new_dp; new_dp.reset();
    for(int j = 0; j < M; ++j) {
      if(dp[j] == 1 && j + arr[i] < M) {
        new_dp[j + arr[i]] = 1;
      }
    }
    dp |= new_dp;
  }

  cout << dp.count() - 1<< '\n';
  for(int i = 1; i < M; ++i) {
    if(dp[i]) cout << i << " ";
  }
  cout << '\n';
}