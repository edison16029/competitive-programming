#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define foeq(i, n) for (int i = 1; i <= n; i++)
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

ll findMax(int i, int n, vector<int> &arr, vector<int> &dp){
    if(i > n) return 0;
    if(dp[i] != -1) return dp[i];
    ll score = arr[i];
    score += findMax(i + arr[i], n, arr, dp);
    dp[i] = score;
    return dp[i];


}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        dp[i] = -1;
    }
    ll answer = LONG_MIN;
    for(int i = 1; i <= n; i++){
        answer = max(answer, findMax(i, n, arr, dp));
    }
    cout<<answer;
    cout<<"\n";
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