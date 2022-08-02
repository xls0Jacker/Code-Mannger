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
const int MAX_N=1e4;
//酸奶工厂 Yogurt factory
//1<=N<=1e4 1<=S<=100 1<=ci<=5000 1<=yi<=1e4

//思路：
//对于第i周和第(i+1)周，
//当ci+1-ci>S时，尽量买ci直至买够，
//当ci+1-ci<=S时，买够即可
//反例，当ci+1-ci-1>2S，此时也是尽量买ci，所以以上想法不成立；
//思路2：
//对于之前的每一个ci购买与当前值进行比较，取最小值，
//满足以下等式：
//ci-cj>(i-j)*S (j<i)
int N,S;
ll c[MAX_N+1],y[MAX_N+1];
void solve(){
    ll ans=0;
    ans+=y[0]*c[0];//第一周必买
    rep(1,i,N){
        ll res=y[i]*c[i];
        rep(0,j,i){
            res=min(res,y[i]*(c[j]+(i-j)*S));
        }
        ans+=res;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N>>S){
        memset(c,0,sizeof(c));
        memset(y,0,sizeof(y));
        rep(0,i,N){
            cin>>c[i]>>y[i];
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

