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

void printArray(const vector<ll> &arr) {
    for(const ll &x : arr){
        cout<<x<<" ";
    }
}

bool isStrictlyIncreasing(vector<ll> &arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        if(arr[i] >= arr[i+1]) return false;
    }
    return true;
}

//input - size and sorted array
void solveUtil(int n, vector<ll> &arr){
    if(isStrictlyIncreasing(arr)){
        reverse(arr.begin(), arr.end());
        printArray(arr);
        return;
    }

    map<ll, ll> f;
    ll greatestElement = 0;
    for(const ll &x : arr){
        f[x]++;
        if(f[x] > 2){
            printArray({-1});
            return;
        }
        greatestElement = max(greatestElement, x);
    }
    if(f[greatestElement] > 1){
        printArray({-1});
        return;
    }

    //Hill - Increasing
    for(int i = 0; i < n; i++){
        ll val = arr[i];
        if(f[val] > 1){
            cout<<val<<" ";
            f[val]--;
        }
    }

    //Hill - Peak and Decreasing
    for(int i = n-1; i >= 0; i--){
        ll val = arr[i];
        if(f[val] > 0){
            cout<<val<<" ";
            f[val]--;
        }
    }


}

void solve(){
    /**
     * Seq should be / or \ or /\ 
     * If any number repeats more than twice, then it is not possible
     * If the largest number repeats more than once, then it is not possible
     * (This is because, non largest number can come in up and down ramps)
     * If / is possible then \ is also possible ( just reverse the array)
     * Sorting is allowed
     *
    */

   /**
    * 1. Sort and then check if stricly increasing is possible.
    * if yes, print the \
    * 2. Check if count valiations succeed. if not, return -1
    * 3. 
    * a. Starting from 1, add all the numbers which appear twice 
    *   until we reach largest number
    * b. Add largets number
    * c. Add remaining numbers
    * 
    * */

   int n;
   cin>>n;
   vector<ll> arr(n);
   for(int i = 0; i < n; i++){
       cin>>arr[i];
   }
   sort(arr.begin(), arr.end());
   solveUtil(n, arr);



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