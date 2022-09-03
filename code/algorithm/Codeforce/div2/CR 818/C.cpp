#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
using namespace std;
const int MAX_N = 2e5;
int n;
int a[MAX_N + 1], b[MAX_N + 1];
void solve(){
	bool bo=true;
	rep(0, i, n)
		cin>>a[i];
	rep(0, i, n)
		cin>>b[i];
	rep(0, i, n)
		if(a[i]>b[i])
			bo=false;
	rep(0, i, n)
		if((i!=n-1&&a[i]<b[i]&&b[i]>b[i+1]+1)||(i==n-1&&a[i]<b[i]&&b[i]>b[0]+1))
			bo=false;
	if(bo==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
	int t;
	cin>>t;
	while(t--){ 
		cin>>n;
		solve();
	}
	frepC;
	sys;
	return 0;
}
