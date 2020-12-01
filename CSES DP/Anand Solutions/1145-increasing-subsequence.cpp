#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<int> arr(n);
  for(auto& x: arr) cin >> x;
  multiset<int> st;
  for(auto x: arr) {
    st.insert(x);
    auto it = next(st.lower_bound(x));
    if(it != st.end()) st.erase(it);
  }
  cout << st.size() << '\n';
}