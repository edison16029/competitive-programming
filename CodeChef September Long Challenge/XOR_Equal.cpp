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


void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    map<int, int> freq;

    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
    }
    if(x == 0){
        cout<<maxFreq<<" "<<0<<"\n";
        return;
    }
    int ans = 0;
    int operations = 0;
    for(int i = 0; i < n; i++){
        int p = arr[i];
        int q = p ^ x;
        int total = freq[p] + freq[q];
        if(total > ans){
            ans = total;
            operations = freq[q];
        }
        else if(total == ans){
            operations = min(operations, freq[q]);
        }
    }
    cout<<ans<<" "<<operations;


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