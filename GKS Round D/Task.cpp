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

bool isAP(int x, int y, int z){
    return z-y == y-x;
}

bool isAPPossible(int x, int z){
    return abs(x)%2 == abs(z)%2;
}

int getMiddleValue(int x, int z){
    return (x+z) / 2;
}

int getAPCountIncludingMiddle(int a1, int a2, int a3, int b1, int b3, 
    int c1, int  c2,int  c3, int  x){
        int count = 0;
        if(isAP(a1,x,c3)) count++;
        if(isAP(a3,x,c1)) count++;
        if(isAP(a2,x,c2)) count++;
        if(isAP(b1,x,b3)) count++;
        return count;
    }

void solve(int caseCount){
    int a1, a2, a3, b1, b3, c1, c2, c3, x;
    cin>>a1>>a2>>a3>>b1>>b3>>c1>>c2>>c3;
    int ans = 0;
    if(isAP(a1,a2,a3)) ans++;
    // cout<<"Ans : "<<ans<<endl;
    if(isAP(c1,c2,c3)) ans++;
    // cout<<"Ans : "<<ans<<endl;
    if(isAP(a1,b1,c1)) ans++;
    // cout<<"Ans : "<<ans<<endl;
    if(isAP(a3,b3,c3)) ans++;
    // cout<<"Ans : "<<ans<<endl;

    int maxCount = 0;
    if(isAPPossible(a1, c3)){
        x = getMiddleValue(a1, c3);
        int count = getAPCountIncludingMiddle(a1, a2, a3, b1, b3, c1, c2, c3, x);
        maxCount = max(maxCount, count);
    }
    if(isAPPossible(a2, c2)){
        x = getMiddleValue(a2, c2);
        int count = getAPCountIncludingMiddle(a1, a2, a3, b1, b3, c1, c2, c3, x);
        maxCount = max(maxCount, count);
    }
    if(isAPPossible(a3, c1)){
        x = getMiddleValue(a3, c1);
        int count = getAPCountIncludingMiddle(a1, a2, a3, b1, b3, c1, c2, c3, x);
        maxCount = max(maxCount, count);
    }
    if(isAPPossible(b1, b3)){
        x = getMiddleValue(b1, b3);
        // cout<<"x : "<<x<<endl;
        int count = getAPCountIncludingMiddle(a1, a2, a3, b1, b3, c1, c2, c3, x);
        maxCount = max(maxCount, count);
    }

    cout<<"Case #"<<caseCount<<": "<<(ans+maxCount)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int t = 1;
    cin >> t;
    //deb(t);
    int caseCount = 1;
    while(t--){
        solve(caseCount++);
        // break;
    }
    
    return 0;
}