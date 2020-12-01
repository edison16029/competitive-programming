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
    vector<int> input(2*n+1); 
    for(int i = 1; i <= 2*n ; i++){
        char c;
        cin>>c;
        if(c == '+'){
            input[i] = 0;
        }
        else{
            int val;
            cin>>val;
            input[i] = val;
        }
    }

    // for(int i = 1; i <= 2*n ; i++){
    //     cout<<input[i]<<" ";
    // }

    int lowestAllowed = 0;
    int elementsInShelf = 0;
    stack<int> lowestAllowedStack;
     vi answer(n+1);
    for(int i = 1; i <= 2*n ; i++){
        int addedCount = 0;
        // int j = i;
        while(input[i]==0){
            addedCount++;
            i++;
        }
        if(i > 2*n) {
            cout<<"NO1\n";
            return;
        }
        int val = input[i];
        
        while(addedCount--){
            lowestAllowedStack.push(val);
            // cout<<val<<" ";
        }
        
        int index = lowestAllowedStack.size();
        
        lowestAllowed = lowestAllowedStack.top();
        lowestAllowedStack.pop();
        lowestAllowedStack.push(-1);
        if(val < lowestAllowed){
            // deb2(val,lowestAllowed);
            cout<<"NO3\n";
            return;
        }
        answer[index] = val;
        
        
    }
    // cout<<"\n";

   
    // for(int i = 1; i <= 2*n ; i++){
    //     int val = input[i];
    //     if(!val) continue;
    //     if(lowestAllowedStack.empty()){
    //         cout<<"NO2\n";
    //         return;
    //     }
    //     int index = lowestAllowedStack.size();
    //     lowestAllowed = lowestAllowedStack.top();
    //     lowestAllowedStack.pop();
    //     if(val < lowestAllowed){
    //         deb2(val,lowestAllowed);
    //         cout<<"NO3\n";
    //         return;
    //     }
    //     answer[index] = val;




    // }

    cout<<"YES\n";
    foeq(i,n){
        cout<<answer[i]<<" ";
    }

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