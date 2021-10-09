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

int leftMostDigitPosition(ll n, ll d){
    int i = 0;

    int pos = -1;
    while(n){
        if(n % 10 == d){
            pos = i;
        }
        i++;
        n /= 10;
    }

    return pos;
}

ll getNextRoundedNumber(ll n, int pos){
    ll roundNumber = pow(10, pos);
    n = n / roundNumber;
    // deb(pos);
    // deb(n);
    n = n * roundNumber;
    // deb(n);
    n = n + roundNumber;
    // deb(n);
    return n;
}

void solve(){
    ll n, d;
    cin >> n >> d;

    int pos = leftMostDigitPosition(n,d);
    if(pos == -1){
        cout<<0;
    }
    else if(n < 10){
        cout<<1;
    }
    else{
        ll sum = 0;
        while(pos != -1){
            ll roundedNumber = getNextRoundedNumber(n, pos);
            sum +=  roundedNumber - n;
            n = roundedNumber;
            pos = leftMostDigitPosition(n,d);
        }
        cout<<sum;
    }
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