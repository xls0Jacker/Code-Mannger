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
const int MAX_N=2*1e5;
int n,x;
int a[MAX_N+1];
void solve(){
    int pos=0;
    int Min=1e9+7;
    int Max=-1;
    int cnt=0;
    while(pos!=n){
        Max=max(a[pos],Max);
        Min=min(a[pos],Min);
        pos++;
        if(-x+Max<=x+Min) continue;//合法
        if(a[pos-2]>a[pos-1]) Max=a[pos-1];
        if(a[pos-2]<a[pos-1]) Min=a[pos-1];
        cnt++;
    }
    cout<<cnt<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        memset(a,0,sizeof(a));
        rep(0,i,n){
            cin>>a[i];
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

