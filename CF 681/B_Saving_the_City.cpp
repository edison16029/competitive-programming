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
    int a,b;
    cin>>a>>b;
    string str;
    cin>>str;
    int i = 0;
    while(i < str.size() && str[i] != '1'){
        i++;
    }
    int j = (int)str.size() - 1;
    while(j>=0 && str[j] != '1'){
        j--;
    }
    if(i > j){
        cout<<0<<endl;
        return;
    }
    // deb2(i,j);
    vi arr;
    // deb(str[1]);
    // deb(str.size());
    for(int index = i; index <= j;){
        if(str[index] == '1'){
            // arr.push_back(0);
            // int newIndex = index + 1;
            index++;
            while(index <= j && str[index] == '1'){
                index++;
            }
        }
        if(index > j) break;
        //currently pointing to 0
        int consecutiveZeroes = 0;

        while(str[index] == '0'){
            consecutiveZeroes++;
            index++;
        }
        arr.push_back(consecutiveZeroes);

    }

    // for(auto val : arr){
    //     deb(val);
    // }
    // cout<<"\n";

    int x = 1;
    while(b*x < a){
        x++;
    }
    // deb(x);

    int n = arr.size();
    int answer = a;
    for(int index = 0; index < n; index++){
        if(arr[index] >= x){
            answer+=a;
        }
        else{
            answer+= (b*arr[index]);
        }
    }

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