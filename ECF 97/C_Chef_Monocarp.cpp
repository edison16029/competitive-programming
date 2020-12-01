#include<bits/stdc++.h>
using namespace std;
long long c,n,i,t,a[222],dp[222][444],j,k;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=2*n;i++) dp[0][i]=0;
		for(j=1;j<=n;j++) for(i=j;i<=2*n;i++){
			c=1e6;
			for(k=j;k<=i;k++) if(c>abs(k-a[j])+dp[j-1][k-1]) c=abs(k-a[j])+dp[j-1][k-1];
			dp[j][i]=c;
		}
		cout<<dp[n][2*n]<<"\n";
	}
}