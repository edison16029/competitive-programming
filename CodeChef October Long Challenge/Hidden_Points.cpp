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

ll getEucDist(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}


void solve(){
    int n;
    cin >> n;
    ll min_distance = numeric_limits<long long>::max();
    // n = 3;
    // vector<ll> xs = {-1, 0, 0, 2};
    // vector<ll> ys = {-1, 0, 1, 0};

    // n = 4;
    // cout<<fixed<<"Bas ana: "<<-1e9<<"\tSon faiz: "<<9;
    // vector<ll> xs = {-1, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    // vector<ll> ys = {-1, (ll)-1e9, (ll)1e9, (ll)-1e9, (ll)1e9};
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            // fflush(stdout);
            cout<<"? "<<i<<" "<<j<<endl;
            ll dist;
            cin >> dist;
            // dist = getEucDist(xs[i], ys[i], xs[j], ys[j]);
            min_distance = min(min_distance, dist);
        }
    }
    cout<<"! "<<min_distance;
    cout<<endl;
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