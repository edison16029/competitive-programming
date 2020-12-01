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
    ll n;
    cin>>n;
    vector<ll> heights(n+1);
    for(int i = 1; i <= n; i++){
        cin>>heights[i];
    }
    vector<ll> dp(n+1);
    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);

    vector<ll> pow2(n);
    ll val = 1;
    pow2[0] = val;
    int index = 1;
    while(val<n){
        val*=2;
        pow2[index++] = val;
    }

    for(int i = 2; i <= n; i++){
        ll minEnergy = INT_MAX;
        for(int j = 0; j < index; j++){
            int previousBuilding = i - pow2[j];
            if(previousBuilding < 1) break;
            ll energySpent = abs(heights[i] - heights[previousBuilding]);
            minEnergy = min(minEnergy, dp[previousBuilding] + energySpent );
        }
        dp[i] = minEnergy;
        // deb(minEnergy);
    }

    cout<<dp[n]<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    // cin >> t;
    //deb(t);
    
    while(t--){
        solve();
    }
    
    return 0;
}