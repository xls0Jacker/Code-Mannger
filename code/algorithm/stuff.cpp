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
const int INF=1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    Rep(1,i,n){
        cin>>a[i];
    }
    vector<pair<int,int>>fri(m+1);
    rep(0,i,m){
        cin>>fri[i].first>>fri[i].second;
    }
    if(m%2==0){
        cout<<0<<endl;
    }
    else {
        vector<int>p(n+1);
        rep(0,i,m){
            p[fri[i].first]++;p[fri[i].second]++;
        }
        int MIN1=INF;
        Rep(1,i,n){
            if(p[i]&1){//朋友对数为偶数
                MIN1=min(MIN1,a[i]);
            }
        }
        int MIN2=INF;
        rep(0,i,m){
            if(p[fri[i].first]%2==0 and p[fri[i].second]%2==0){
                MIN2=min(MIN2,a[fri[i].first]+a[fri[i].second]);
            }   
        }
        cout<<min(MIN1,MIN2)<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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


