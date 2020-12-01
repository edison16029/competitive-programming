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

typedef struct Movestruct {
    int x1, x2, x3, y1, y2, y3;
} operation;
int countVal = 0;
bool conditionSatisfied(int a, int b, int c, int d){
    countVal++;
    // if(a == 0 && b == 0 && c == 0 && d == 0) return true;
    // return false;
    return a+b+c+d == 3;
}
void setOperation(int x1, int y1, int x2, int y2, int x3, int y3, operation &op){
    op.x1 = x1;
    op.x2 = x2;
    op.x3 = x3;
    op.y1 = y1;
    op.y2 = y2;
    op.y3 = y3;
}

void operate(int i, int j, vector<vector<int>> &mat,vector<operation> &answer){
    int skip = 1;
    int a,b,c,d;
    a = mat[i][j];
    b = mat[i][j+1];
    c = mat[i+1][j];
    d = mat[i+1][j+1];
    
    while(true){
        // if(countVal >= 10){
        //     cout<<"===================";
        //     break;
        // }
        // cout<<"Debug = "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        if(conditionSatisfied(a,b,c,d)){
            operation op;
            if(a == 0)
                setOperation(i, j+1, i+1, j, i+1, j+1, op);
            else if(b==0)
                setOperation(i, j, i+1, j, i+1, j+1, op);
            else if(c==0)
                setOperation(i, j, i, j+1, i+1, j+1, op);
            else
                setOperation(i, j, i, j+1, i+1, j, op);                                
            answer.push_back(op);
            break;
        }
        
        if(skip == 1){
            b = !b;
            c = !c;
            d = !d;
            operation op;
            setOperation(i, j+1, i+1, j, i+1, j+1, op);
            answer.push_back(op);
        }
        else if(skip == 2){
            a = !a;
            c = !c;
            d = !d;
            operation op;
            setOperation(i, j, i+1, j, i+1, j+1, op);
            answer.push_back(op);
        }
        else if(skip == 3){
            a = !a;
            b = !b;
            d = !d;
            operation op;
            setOperation(i, j, i, j+1, i+1, j+1, op);
            answer.push_back(op);
        }
        else{
            a = !a;
            b = !b;
            c = !c;
            operation op;
            setOperation(i, j, i, j+1, i+1, j, op);
            answer.push_back(op);
        }

        skip = (skip+1)%4;
    }
    

    mat[i][j] = 0;
    mat[i][j+1] = 0;
    mat[i+1][j] = 0;
    mat[i+1][j+1] = 0;
}

void checkAndOperate(int i, int j, vector<vector<int>> &mat,vector<operation> &answer, int order){
    int a,b,c,d;
    a = mat[i][j];
    b = mat[i][j+1];
    c = mat[i+1][j];
    d = mat[i+1][j+1];

    int inputOrder = a+b+c+d;
    if(inputOrder == order || order == 4){
        operate(i,j,mat,answer);
    }
    
}
void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> mat(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin>>c;
            mat[i][j] = c == '0' ? 0 : 1;
        }
    }

    vector<operation> answer;
    vector<int> orderOfWindow{3,2,1,4};

    for(int order : orderOfWindow){
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                checkAndOperate(i, j, mat, answer, order);
            }
        }
    }
    

    cout<<answer.size()<<"\n";
    for(operation op : answer){
        cout<<op.x1<<" "<<op.y1<<" "<<op.x2<<" "<<op.y2<<" "<<op.x3<<" "<<op.y3<<"\n";
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