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

void solve(){
    int n,k=1;
	cin>>n;
	while (n>k) {//判断在第几层
		n=n-k;
		k++;
	}
	if(k%2==0) cout<<n<<"/"<<(k+1-n);
	else cout<<k+1-n<<"/"<<n;
	cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}


//存表
/*
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

void solve(){
    vector<pair<int,int>> pii;
    ll cnt=0;
    Rep(1,k,4500){
        double i=1,j=1;
        if(k%2==0){//偶下大
            j=1.0*k;
            pii.push_back(make_pair(i,j));
            while(j!=1){
                i++,j--;
                pii.push_back(make_pair(i,j));
            }
        }
        else {//奇上大
            i=1.0*k;
            pii.push_back(make_pair(i,j));
            while(i!=1){
                i--,j++;
                pii.push_back(make_pair(i,j));
            }
        }
    }
    int n;
    cin>>n;
    n--;
    cout<<pii[n].first<<"/"<<pii[n].second<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

*/
