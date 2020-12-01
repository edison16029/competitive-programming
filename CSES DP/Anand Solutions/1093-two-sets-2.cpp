#include <bits/stdc++.h>

using namespace std;

const int N = 501;
const int M = N * (N + 1) / 2;
const int mod = 1e9 + 7;

inline int add(int a, int b, int mod = mod) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

inline int mul(int a, int b, int mod = mod) {
  return (long long) a * b % mod;
}

int dp[N][M];
int n;
int total;

int rec(int cur, int suma) {
  if(cur == n + 1) {
    return suma == total - suma;
  }
  int& cs = dp[cur][suma];
  if(cs != -1) return cs;
  return cs = add(rec(cur + 1, suma), rec(cur + 1, suma + cur));
}

int mpow(long long x, long long y, int mod = mod) {
  x = x % mod;
  int res = 1;
  while(y) {
    if(y & 1 == true) res = mul(res, x, mod);
    x = mul(x, x, mod);
    y >>= 1;
  }
  return res;
}

int inv(int x) {
  return mpow(x, mod - 2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n;
  total = n * (n + 1) / 2;
  cout << mul(rec(1, 0), inv(2)) << '\n';
}