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
    vector<int> arr(n+1);
    map<int, int> count;
    set<int> minutes;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        count[arr[i]] +=1;
    }
    for(int i = 1; i <= n; i++){
        int dish = arr[i];
        if(minutes.find(dish) == minutes.end()){
            minutes.insert(dish);
            count[dish]--;
        }
    }
    //minutes has unique numbers now
    // for(auto val : minutes){
    //     cout<<val<<" ";
    // }
    int answer = 0;
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= n; i++){
        int dish = arr[i];
        if(count[dish]>0){
            int displacement = 1;
            while(true){
                int pre = dish - displacement;
                int next = dish + displacement;
                if(pre>0  && minutes.find(pre)==minutes.end()){
                    minutes.insert(pre);
                    answer+=displacement;
                    count[dish]--;
                    break;
                }
                else if(minutes.find(next) == minutes.end()){
                    minutes.insert(next);
                    answer+=displacement;
                    count[dish]--;
                    break;
                }
                else{
                    displacement++;
                }
            }
        }
    }
    // cout<<"\n";
    // for(auto val : minutes){
    //     cout<<val<<" ";
    // }
    // cout<<"\n";
    cout<<answer<<endl;

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