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

ll getNthTerm(ll a, ll d, ll n){
    return a + (n-1) * d;
}

ll sumOfAP(ll a, ll d, ll n){ //works
    //Formula n/2[2a + (n – 1)d]
    ll sum;
    if(n%2 == 0){
        sum = (n/2) * ( (2*a) + ((n-1)*d) );
    }
    else{
        sum = n * ( a + ( (n-1)/2 * d ) );
    }
    return sum;
}
//maximise firstVaccineCount
ll binSearch(ll moneyLeft, ll totalVaccines, ll a, ll b, ll c, ll d){
    ll low = 0;
    ll high = totalVaccines;
    ll ans = (low + high) / 2;
    ll possibilty1 = sumOfAP(a,b, 0) + sumOfAP(c,d, totalVaccines);
    ll possibilty2 = sumOfAP(a,b, totalVaccines) + sumOfAP(c,d, 0);
    if(possibilty1 > moneyLeft and possibilty2 > moneyLeft){
        return -1;
    }
    while(low <= high){
        ll firstVaccineCount = (low + high) / 2;
        
        // cout<<"Ans in mid step: "<<ans<<endl;
        ll firstVaccineTotalCost = sumOfAP(a,b, firstVaccineCount);
        ll secondVaccineTotalCost = sumOfAP(c,d, totalVaccines - firstVaccineCount);
        ll total = firstVaccineTotalCost + secondVaccineTotalCost; 
        // deb(firstVaccineTotalCost);
        // deb(secondVaccineTotalCost);
        // deb(total);
        // deb(moneyLeft);
        // cout<<endl;
        if(total <= moneyLeft){
            low = firstVaccineCount+1;
            ans = firstVaccineCount;
        }
        else{
            high = firstVaccineCount-1;
        }
    }
    return ans;
}

ll searchTotalVaccines(ll moneyLeft, ll a, ll b, ll c, ll d){
    int maxVaccineCount = 0;
    while(true){
        // x is max v1 count, y is max v2 count
        ll x = binSearch(moneyLeft, maxVaccineCount, a, b, c, d); 
        ll y = binSearch(moneyLeft, maxVaccineCount, c, d, a, b);
        if(x == -1 and y == -1) return maxVaccineCount -1;
        maxVaccineCount++;
    }
}

void solve(){
    ll n;
    cin>>n;
    ll x,a,b,c,d,p,q,r,s,t,m;
    cin>>x>>a>>b>>c>>d;
    cin>>p>>q>>r>>s>>t>>m;
    ll moneyLeft;
    
    // ll maxFirstVaccine = binSearch(x, 0, a,b,c,d);
    // cout<<"MaxFV : "<<maxFirstVaccine<<endl;
    
    for(int i = 0; i < n; i++){
        moneyLeft = x;
        ll covax = 1;
        ll covi = 1;
        ll totalNumberOfMedicines = searchTotalVaccines(moneyLeft, a,b,c,d);
        cout<<totalNumberOfMedicines<<endl;
        // while(moneyLeft >= 0){
        //     ll costOfNthCovax = getNthTerm(a,b,covax);
        //     ll costOfNthCovi = getNthTerm(c,d,covi);
        //     if(costOfNthCovax < costOfNthCovi){
        //         moneyLeft -= costOfNthCovax;
        //         covax++;
        //     }
        //     else{
        //         moneyLeft -= costOfNthCovi;
        //         covi++;
        //     }
        // }
        // ll totalNumberOfMedicines = (covax - 1) + (covi - 1) - 1; //Last -1 is to sell the last one
        // cout<<totalNumberOfMedicines<<endl;

        a = (a + (totalNumberOfMedicines*t))%m + p;
        b = (b + (totalNumberOfMedicines*t))%m + q;
        c = (c + (totalNumberOfMedicines*t))%m + r;
        d = (d + (totalNumberOfMedicines*t))%m + s;
    }

    // cout<<getNthTerm(1, 25, 5);

    // cout<<"\n";
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