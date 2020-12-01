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

vl possibles(23);
void solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<1<<endl;
        return;
    }

    ll chooseVal = 1;
    for(int i=n;i>n/2;i--) chooseVal*=i;
    ll denom = 1;
    for(int i=n/2;i>=1;i--) denom*=i;
    chooseVal/=denom;
    chooseVal/=2;

    
    
    
    // deb(possibles[8]);
    // deb(chooseVal);

    ll answer = chooseVal * possibles[n/2] * possibles[n/2];
    // deb(answer);
    cout<<answer<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    // cin >> t;
    //deb(t);
    possibles[2] = 1;
    for(int i = 3; i<=20 ; i++)
        possibles[i] = possibles[i-1]*(i-1);
    while(t--){
        solve();
    }
    
    return 0;
}