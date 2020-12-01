#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n; cin >> n; 
  vector<int> x(n), y(n), p(n);
  map<int, int> compress;
  for(int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> p[i];
    ++y[i];
    compress[x[i]]; compress[y[i]];
  }
  int id = 0;
  for(auto& x: compress) {
    x.second = id++;
  }
  vector<vector<pair<int, int>>> projects(id);
  for(int i = 0; i < n; ++i) {
    projects[compress[y[i]]].emplace_back(compress[x[i]], p[i]);
  }

  vector<long long> dp(id, 0);
  for(int i = 0; i < id; ++i) {
    if(i > 0) {
      dp[i] = dp[i - 1];
    }
    for(auto p: projects[i]) {
      dp[i] = max(dp[i], dp[p.first] + p.second);
    }
  }
  cout << dp[id - 1] << '\n';
}
