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

void printMat(int n, int arr[][101]){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isAdjVal(int n, int m){
    if(abs(n-m) > 1)
        return false;
    return true;
}

bool isNotAdj(int n, int arr[][101]){
    int ans = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int val = arr[i][j];
            int t = i-1;
            int l = j-1;
            int r = j+1;
            int d = i+1;
            if(t >=1 &&  isAdjVal(val, arr[t][j])){
                return false;
            }
            if(d <=n &&  isAdjVal(val, arr[d][j])){
                return false;
            }
            if(l >=1 &&  isAdjVal(val, arr[i][l])){
                return false;
            }
            if(r <=n &&  isAdjVal(val, arr[i][r])){
                return false;
            }
        }
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    int a[101][101];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           a[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        int firstValue = i*i;
        int toAdd = i*2;
        // cout<<firstValue<<" ";
        a[i][1] = firstValue;
        int prevValue = firstValue+toAdd;
        for(int j = 2; j <= n-i+1; j++){
            // cout<<prevValue<<" ";
            a[i][j] = prevValue;
            toAdd+=2;
            prevValue+=toAdd;
        }
        // cout<<endl;
    }

    for(int i = n; i >= 2; i--){
        int row = n-i + 1;

        int firstValue = a[row][1] + 1;
        a[i][n] = firstValue;
        int toAdd= (n-i+2)*2;
        int prevValue = firstValue+toAdd;
        // cout<<"row : "<<row<<" "<<"FV : "<<firstValue<<endl;
        for(int j = n-1; j >= n-i+2; j--){
            a[i][j] = prevValue;
            toAdd+=2;
            prevValue+=toAdd;
        }
        
    }
    if(isNotAdj(n,a)){
        printMat(n, a);
    }
    else{
        cout<<-1<<endl;
    }
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