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
const int MAX=1e6+10;
int x[MAX];
//1<=L<=1e6 1<=n<=1e6 0<=xi<=L
void solve(){
    int L,n;
    cin>>L>>n;
    Rep(1,i,n){
        cin>>x[i];
    }
    int minT=0;
    Rep(1,i,n){
        minT=max(minT,min(x[i],L-x[i]));
    }
    int maxT=0;
    Rep(1,i,n){
        maxT=max(maxT,max(x[i],L-x[i]));
    }
    cout<<minT<<" "<<maxT<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    frepC;
    sys;
    return 0;
}

