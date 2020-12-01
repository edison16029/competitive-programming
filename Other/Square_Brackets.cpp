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

// difference is # Open Brackets minus the closed ones

vector<vector<int>> dp(40, vector<int>(40)); //i is index, j is difference
set<int> indices;
int countWays(int index, int &length, int difference){
    if(index == length){
        // cout<<"================"<<difference<<endl;
        if(difference == 1) return 1;
        return 0;
    }
    if(difference < 0 ) return 0;
    if(difference == 0){
        if(dp[index+1][difference+1] == -1)
            dp[index+1][difference+1] = countWays(index+1, length, difference+1 );
        return dp[index+1][difference+1];
    }
    if(dp[index+1][difference+1] == -1)
        dp[index+1][difference+1] = countWays(index+1, length, difference+1 );
    if(dp[index+1][difference-1] == -1){
        if(indices.find(index) != indices.end()){
            return dp[index+1][difference+1];
        // if(false)
            // dp[index+1][difference-1] = 0;
            // cout<<"index found\n";
            }
        else
            dp[index+1][difference-1] = countWays(index+1, length, difference-1 );
    }
    // cout<<"For index = "<<index<<" diff = "<<difference<<" Open : "<<dp[index+1][difference+1]<<endl;
    // cout<<"For index = "<<index<<" diff = "<<difference<<" Close : "<<dp[index+1][difference-1]<<endl;
        
    return dp[index+1][difference+1] + dp[index+1][difference-1];
}

void solve(){
    int n,k;

    for(int i = 0; i <40; i++){
        for(int j = 0; j <40; j++){
            dp[i][j] = -1;
        }
    }
    indices.clear();
    cin>>n>>k;
    fo(i,k){
        int val;
        cin>>val;
        indices.insert(val);
    }
    if(indices.find(2*n) != indices.end()) {
        // cout<<"Not calling";
        cout<<0<<endl; 
        return;
    }

    int m = 2*n;
    cout<<countWays(2,m,1)<<endl;
    // for(int i = 1; i <10; i++){
    //     for(int j = 1; j <10; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // fo(i,k){
    //     // int positionS;
    //     // cin>>positionS;
    //     // brackets[positionS] = 0;
    //     cout<<countWays(0,n,0);

    // }
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