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

int n;
int matrix[51][51];
int dp[51][51];
// int count;
bool isValid(int i, int j, bool hasToBePath){
    // ::count++;
    // deb2(i,j);
    if(!hasToBePath && matrix[i][j] == 0 ) {dp[i][j] = 1;return true;}
    if(hasToBePath && matrix[i][j] == 0 ) {return false;}

    if( i==n || j ==n) {dp[i][j] = 1;return true;}
    if(dp[i][j+1] || dp[i+1][j]){
        dp[i][j] = 1;
        return true;
    }
    bool right = isValid(i, j+1, true);
    bool left =  isValid(i+1, j, true);

    if (right || left) dp[i][j] = 1;

    // bool right = isValid(i, j+1, true);
    // bool left =  isValid(i+1, j, true);
    // deb(right);deb(left);
    // cout<<"===============\n";
    // foeq(i,n){
    //     foeq(j,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"===============\n";
    return dp[i][j];

}

void solve(){
    // ::count = 0;
    int num;
    cin>>num;
    n = num;
    foeq(i,n){
        foeq(j,n){
            char x;
            cin>>x;
            matrix[i][j] = x - '0';
            dp[i][j] = 0;
        }
    }

    bool valid = true;

    foeq(i,n){
        foeq(j,n){
            //Add dp
            // if(dp[i][j] || matrix[i][j] == 0) continue;
            // if(!isValid(i,j,false)){
            //     valid = false;
            //     break;
            // }
            if(i==n || j ==n ) continue;
            if(matrix[i][j] == 1 && matrix[i+1][j] == 0 && matrix[i][j+1] == 0){
                valid = false;
                break;
            }
        }
        if(!valid) break;
    }
    if(valid) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    // cout<<::count<<endl;

    // foeq(i,n){
    //     foeq(j,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
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