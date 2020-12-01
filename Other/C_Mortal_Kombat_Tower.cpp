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

int findRecursive(int index, int &n, vi &bossType, bool friendsTurn,bool isFirst,vector<int, vector<pair<int,int>>> &dp){
    int currentPoint = 0;
    if(friendsTurn){
        currentPoint+= bossType[index];
    }

    if(index == n-1){
        if(friendsTurn) return bossType[index];
        return 0;
    }



    int changed, continued;

    changed = findRecursive(index+1,n,bossType,!friendsTurn,true,dp);
    if(isFirst){
        continued = findRecursive(index+1,n,bossType,friendsTurn,false,dp);
    }
    else{
        continued = INT_MAX;
    }
    // cout<<"=================";
    // deb(index);
    // deb(friendsTurn);
    // deb(isFirst);
    // deb(changed);
    // deb(continued);
    // cout<<"=================";

    int answer = min( changed,continued );
    answer += currentPoint;
    return answer;

}

void solve(){
    int n;
    
    cin>>n;
    vi input(n);
    fo(i,n){
        cin>>input[i];
    }
    vector<int, vector<pair<int,int>>> dp(200005, vector<pair<int,int>>(2));
    bool friendTurn = true;
    int skipPointsUsed = 0;
    if(n>1)
        skipPointsUsed = min(findRecursive(1,n,input,friendTurn,false,dp), findRecursive(1,n,input,!friendTurn,true,dp));
    skipPointsUsed += input[0];
    cout<<skipPointsUsed<<endl;


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