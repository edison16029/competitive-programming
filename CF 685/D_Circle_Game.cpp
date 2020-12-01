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
int counter = 0;
bool withinDistance(int x, int y,int d){
    if(x*x + y*y <= d*d) return true;
    return false;
}
void debugger(int x, int y, int turn, bool currentPlayerWins){
    string str = turn == 0 ? "Ashish" : "Utkarsh";
    if(currentPlayerWins)
        cout<<"At ("<<x<<","<<y<<") "<<str<<" wins";
    else
        cout<<"At ("<<x<<","<<y<<") "<<str<<" loses";
    cout<<"\n";
}
bool play(int x, int y, int k, int d, int turn){
    bool moveRight = false, moveTop = false;
    if(withinDistance(x+k,y,d))
        moveRight = play(x+k, y, k, d, !turn);
    if(withinDistance(x,y+k,d))
        moveTop = play(x, y+k, k, d, !turn);

    return moveRight || moveTop;
    
    

    // return turn == 0 ? currentPlayerWins : !currentPlayerWins;
}

void solve(){
    int d,k;
    cin>>d>>k;
    int turn = 0; //  Ashish represents 0 and Utkarsh represents 1

    bool moveRightUtkarshWins = true, moveTopUtkarshWins = true;;
    if(withinDistance(0+k,0,d))
        moveRightUtkarshWins = play(0+k, 0, k, d, !turn);
    if(withinDistance(0,0+k,d))
        moveTopUtkarshWins = play(0, 0+k, k, d, !turn);

    if(!moveRightUtkarshWins || !moveTopUtkarshWins){
        cout<<"Ashish";
    }
    else{
        cout<<"Utkarsh";
    }
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