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

bool comparator(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int, int>> arr(n);
    vi a(n);
    vi b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    
    for(int i = 0; i < n; i++){
        arr[i] = mp(a[i],b[i]);

    }
    sort(arr.begin(), arr.end(), comparator);

    // for(auto pa : arr){
    //     cout<<pa.F<<","<<pa.S<<endl;
    // }
    // cout<<"\n";

    vl aSuffixSum(n), aPrefixSum(n), bSuffixSum(n), bPrefixSum(n);
    aPrefixSum[0] = arr[0].F;
    bPrefixSum[0] = arr[0].S;

    for(int i = 1; i < n; i++){
        aPrefixSum[i] = arr[i].F + aPrefixSum[i-1];
        bPrefixSum[i] = arr[i].S + bPrefixSum[i-1];
    }

    aSuffixSum[n-1] = arr[n-1].F;
    bSuffixSum[n-1] = arr[n-1].S;
    
    for(int i = n-2; i >= 0; i--){
        aSuffixSum[i] = arr[i].F + aSuffixSum[i+1];
        bSuffixSum[i] = arr[i].S + bSuffixSum[i+1];
    }

    // cout<<"ASS : ";
    // for(ll val : aSuffixSum){
    //     cout<<val<<" ";
    // }
    // cout<<"\n";

    // cout<<"APS : ";
    // for(ll val : aPrefixSum){
    //     cout<<val<<" ";
    // }
    // cout<<"\n";

    // cout<<"BPS : ";
    // for(ll val : bPrefixSum){
    //     cout<<val<<" ";
    // }
    // cout<<"\n";

    // cout<<"BSS : ";
    // for(ll val : bSuffixSum){
    //     cout<<val<<" ";
    // }
    // cout<<"\n\n";

    ll answer = INT_MAX;

    if(aPrefixSum[0] > bSuffixSum[0]){ //Case where lowest delivery time is more than fetching all
        cout<<bSuffixSum[0]<<endl;
        return;
    }
    for(int i = 0; i < n-1; i++){
        ll newAns = max((ll)arr[i].F, bSuffixSum[i+1]);

        answer = min(answer, newAns);
    }

    answer = min(answer, (ll)arr[n-1].F);

    cout<<answer<<endl;





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