#include<bits/stdc++.h>
using namespace std;
 
 
// #define __DEBUG
 
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define itr(i, a) for (auto i = a.begin(); i != a.end(); i++)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<li, li> pl;
 
template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}
template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}
 
mt19937 rnd(time(NULL));
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
 
 
 
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef __DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int __time = clock();
	#endif
	/*-----------------------------------------------------------*/
	
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		forn(i,n)
		{
			cin>>arr[i];
		}
		sort(all(arr));
		// cout<<arr<<endl;
		// int dp[422][422];
 
		int dp[n+1][(2*n)+1] ;
 
		for (int i = 0; i <= n; i++)
			for (int x = 0; x <= 2 * n; x++)
				dp[i][x] = INF;
 
 
 
		dp[0][0] = 0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j < 2 *n ;j++)
			{
				dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
				if(i<n)
					dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j] +  abs(arr[i]- (j+1)));
			}
		}
 
		cout<<dp[n][2*n]<<endl;
 
	}
 
	
	
	/*-----------------------------------------------------------*/
 
 
	#ifdef __DEBUG
	cerr << endl << "TIME = " << clock() - __time <<" ms"<<endl;
	__time = clock();
	#endif
	return 0;
}