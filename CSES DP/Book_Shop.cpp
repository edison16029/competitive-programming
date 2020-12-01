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

/*
https://cses.fi/problemset/view/1158/
*/
int maxPagesPossible(int i, vector<int> &cost, vector<int> &pages, int &n, int costLeft, vector<vector<int>> &dp){
    if(costLeft <= 0 ) return 0;
    if(i > n) return 0;

    // Case 1 : Current book is included
    int currentBookIncludedCost = 0;

    if(dp[i][costLeft] == -1){
        if(cost[i] <= costLeft)
            currentBookIncludedCost =  pages[i] + maxPagesPossible(i+1, cost, pages, n, costLeft - cost[i], dp);
        int currentBookExcludedCost =  maxPagesPossible(i+1, cost, pages, n, costLeft, dp);
        dp[i][costLeft] = max(currentBookIncludedCost, currentBookExcludedCost);
    }
    
    return dp[i][costLeft];


}

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> cost(n+1);
    for(int i = 1; i <= n; i++){
        cin>>cost[i];
    }

    vector<int> pages(n+1);
    for(int i = 1; i <= n; i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = -1;
        }
    }


    int answer = maxPagesPossible(1, cost, pages, n, x, dp);
    cout<<answer;
    cout<<"\n";
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