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
int t;
void solve(){
    cin>>t;
    ll n,m;
    Rep(1,i,t){
        cin>>n>>m;
        cout<<n*(m+n*m)/2+m*(m+1)/2-m<<endl;
    }   
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

