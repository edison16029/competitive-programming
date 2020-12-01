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
 
int answer;
 
const int mod = 998244353;
 
int addMod(int x, int y){
    return ((x+y)%mod+mod)%mod;
}
 
int subMod(int x, int y){
    return ((x-y)%mod+mod)%mod;
}
 
int mulMod(int x, int y){
    return ((x*y)%mod+mod)%mod;
}
 
void count(multiset<int> &a, multiset<int> &b,int n){
    
    // //
    // cout<<"Counting\n";
    // cout<<"Multiset a = ";
    // tr(it,a){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // cout<<"Multiset b = ";
    // tr(it,b){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // //
    
    
    if(a.size() != b.size() || a.size() != n) return;
    
    
 
    multiset<int>::iterator ita;
    multiset<int>::reverse_iterator itb;
    ita = a.begin();
    itb = b.rbegin();
 
    
    while(ita != a.end()){
        answer = addMod(answer, abs(*ita - *itb));
        ita++;
        itb++;
    }
 
 
}
void fun(int index, int n, multiset<int> &a, multiset<int> &b, vector<int> &arr){
    if(a.size() > n || b.size() > n) return;
    if(index > 2*n){
        count(a,b,n);
        return;
    }
    int val = arr[index];
    if(a.size() < n){
        a.insert(val);
        fun(index+1,n,a,b,arr);
        a.erase(a.find(val));
    }
    if(b.size() < n){
        b.insert(val);
        fun(index+1,n,a,b,arr);
        b.erase(b.find(val));
    }

 
 
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(2*n+1);
    for(int i = 1; i <= 2*n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    multiset<int> a, b;
    fun(1,n,a,b,arr);
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