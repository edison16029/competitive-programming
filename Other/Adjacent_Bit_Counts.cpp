#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i <= n; i++)
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
    int t,n,k;
    cin>>t>>n>>k;

    vector<vector<ll>> dp(n+1, vector<ll>(n));
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 2; i <= n; i++){
        dp[i][i-1] = 1;
    }
    dp[1][0] = 2;
    dp[1][1] = 0;
    dp[2][0] = 3;

    for(int i = 3; i <= n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j] + dp[i-2][j] + dp[i-1][j-1] - dp[i-2][j-1];
        }
    }

    // for(int i = 0; i<=n ; i++){
    //     fo(j,k){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Answer";

    cout<<t<<" "<<dp[n][k]<<endl;


    

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    cin >> t;
    //deb(t);
    
    while(t--){
        
        solve();
    }
    
    return 0;
}