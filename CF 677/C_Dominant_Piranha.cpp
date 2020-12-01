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
    int n;
    cin>>n;
    ll val;
    map<ll,int> count;
    // map<ll,int> greatestIndex;
    ll greatest = INT_MIN;
    vl arr(n+1);
    foeq(i,n){
        cin>>val;
        arr[i] = val;  
        greatest = max(greatest,val);
        count[val] +=1;
        // greatestIndex[val] = i+1;
    }
    int answer = -1;
    if(count[greatest] == n) answer = -1;
    else {
        if(arr[1] == greatest && arr[2] != greatest){
            answer = 1;
        }
        else{
            for(int i = 2; i <= n-1; i++){
                if(arr[i] == greatest && (arr[i-1] != greatest || arr[i+1] != greatest)){
                    answer = i;
                    break;
                }
            }
        }
        if(answer == -1) answer = n;
    }
    cout<<answer;

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