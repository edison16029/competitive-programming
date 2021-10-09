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

int nonPrimal(vector<int> &arr){

    for(auto x : arr){
        if(x == 1 or x == 4 or x == 6 or x == 8 or x == 9) {
            return x;
        }
    }
    return -1;
}

int twoOrFiveNonLeftMost(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int x = arr[i];
        if(x == 2 || x == 5){
            return x;
        }
    }
    return -1;
}

bool someFun(vector<int> &arr, int left, int right){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == left and arr[j] == right){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int k;

    cin>>k;

    vector<int> array = vector<int>(k);

    for(int i = 0; i < k; i++){
        char x;
        cin>>x;
        int val = x - '0';
        array[i] = val;
    }
    int nonPrimalDigit = nonPrimal(array);
    if(nonPrimalDigit != -1){
        cout<<1<<endl<<nonPrimalDigit<<endl;
        return;
    }

    int twoOrFive = twoOrFiveNonLeftMost(array);
    if(twoOrFive != -1){
        cout<<2<<endl;
        cout<<array[0]<<twoOrFive<<endl;
        return;
    }

    cout<<2<<endl;
    if(someFun(array,2,7)){
        cout<<27<<endl;
    }
    else if(someFun(array,3,3)){
        cout<<33<<endl;
    }
    else if(someFun(array,7,7)){
        cout<<77<<endl;
    }
    return;
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