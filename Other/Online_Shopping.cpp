#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> prices(n+1, vector<int>(m+1));
    vector<vector<int>> discounts(n+1, vector<int>(m+1));
    fo(i,n){
        for(int j = 0; j < m; j++){
            cin>>prices[i][j];
        }
    }
    fo(i,n){
        for(int j = 0; j < m; j++){
            cin>>discounts[i][j];
        }
    }
    int minCost = 10000000;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for(int j = 0; j < m; j++){
        dp[0][j] = prices[0][j];
        if(dp[0][j] < minCost) {
            minCost = dp[0][j];
        }
        // cout<<dp[0][j]<<" ";
    }
    // cout<<endl;

    for(int i = 1; i < n; i++){
        
        
        for(int j = 0; j < m; j++){
            int discountedPrice = prices[i][j] - discounts[i-1][j] ;
            discountedPrice = (discountedPrice > 0) ? discountedPrice : 0;
            int discountAppliedCost = dp[i-1][j] + discountedPrice;
            // deb(discountAppliedCost);
            int noDiscountAppliedCost = minCost + prices[i][j];
            dp[i][j] = min(discountAppliedCost, noDiscountAppliedCost);
            
            // cout<<dp[i][j]<<" ";
        }
        minCost = dp[i][0];
        for(int j = 1; j < m; j++){
            if(dp[i][j] < minCost) {
                minCost = dp[i][j];
            }        
        }

        // deb(minCost);
        // cout<<endl;
    }

    cout<<minCost<<endl;
    // cout<<endl;



}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    cin >> t;
    // deb(t);
    
    while(t--){
        solve();
    }
    
    return 0;
}