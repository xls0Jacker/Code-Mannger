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
//求A*B^n%mod
const int MAX=100;
const ll mod=1e9+7;
int n;
struct M{
    ll a[MAX][MAX];
};
//矩阵乘法
M mul(M a,M b){
    M c;
    memset(c.a,0,sizeof(c.a));
    rep(0,i,n){
        rep(0,j,n){
            rep(0,k,n){
                c.a[i][j]+=(a.a[i][k]*b.a[k][j])%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
//矩阵乘法快速幂
M fast_power(M a,ll b){
    M ret;
    memset(ret.a,0,sizeof(ret.a));
    rep(0,i,n){
        ret.a[i][i]=1;//生成单位矩阵E
    }
    while(b){
        if(b&1) ret=mul(ret,a);//矩阵乘法注意次序
        b>>=1;
        a=mul(a,a);
    }
    return ret;
}

void solve(){
    ll k;
    M m;
    //输入
    cin>>n>>k;
    rep(0,i,n){
        rep(0,j,n){
            cin>>m.a[i][j];
        }
    }
    //矩阵快速幂
    M ANS=fast_power(m,k);
    //输出
    rep(0,i,n){
        rep(0,j,n){
            cout<<ANS.a[i][j]<<" ";
        }
        cout<<endl;
    }
}  

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

