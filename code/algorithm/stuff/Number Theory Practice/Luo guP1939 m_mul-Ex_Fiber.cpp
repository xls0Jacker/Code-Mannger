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
const int MAX=100;
const ll mod=1e9+7;
struct M{
    ll a[MAX][MAX];
};

M mul(M a,M b){
    M c;
    memset(c.a,0,sizeof(c.a));
    rep(0,i,4){
        rep(0,j,4){
            rep(0,k,4){
                c.a[i][j]+=(a.a[i][k]*b.a[k][j])%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}

ll T[MAX];
M fast_power(M a,ll b){
    M ret;
    memset(ret.a,0,sizeof(ret.a));
    rep(0,i,4){
        ret.a[i][i]=1;
    }
    while(b){
        if(b&1) ret=mul(ret,a);
        b>>=1;
        a=mul(a,a);
    }
    return ret;
}

void solve(){
    int t;
    cin>>t;
    ll n;//查询位次
    Rep(1,i,t){
        cin>>n;
        M A,B;
        memset(A.a,0,sizeof(A.a));
        memset(B.a,0,sizeof(B.a));
        A.a[0][0]=A.a[0][1]=A.a[0][2]=1;
        B.a[0][2]=B.a[1][0]=B.a[2][1]=B.a[2][2]=1;
        if(n==1 or n==2) {
            cout<<1<<endl;
            continue;
        }
        B=fast_power(B,n-3);
        M ANS=mul(A,B);
        cout<<ANS.a[0][2]<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

