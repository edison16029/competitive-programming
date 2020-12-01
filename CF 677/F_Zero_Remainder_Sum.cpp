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

ll findSum(vi &arr,int m,int div){
    ll answer = INT_MIN;
    map<int,int> count;
    for(auto val : arr) count[val]++;
    ll dp[70][70];
    for(int i = 0; i < m-2; i++){
        for(int j = i+1; j < m-1; j++){
            for(int k = j+1; k < m; k++){
                ll sum = arr[i] + arr[j] + arr[k];
                if(sum%div == 0){
                    deb(i);
                    deb(j);
                    deb(k);
                    deb(sum);
                    answer = max(answer,sum);
                }

            }
        }
    }
    deb(answer);
    return answer;
}

void solve(){
    int n,m,k;
    ll answer = 0;
    cin>>n>>m>>k;
    fo(i,n){
        vi arr(m);
        fo(j,m){
            cin>>arr[j];
        }
        answer += findSum(arr,m,k);
    }

    cout<<answer<<endl;
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