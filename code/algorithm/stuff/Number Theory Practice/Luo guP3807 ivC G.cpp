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
//通过逆元实现组合数//运用到欧拉函数的性质//G
const int MAX=1e6+10;
ll mod;//模
ll fac[MAX];//存阶乘
ll invfac[MAX];//存阶乘逆元
ll L;//边界
//快速幂
ll fast_power(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1) ret=ret*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ret;
}
ll C(ll n,ll m){//n下标 行数 || m上标 列数-1
    if(n<0 or m>n) return 0;//非法
    if(n==m or m==0) return 1;//此组合数值为1
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;//n!/[m!*(n-m)!]//此处除法采用逆元加速存储
}
void pre(){
    fac[0]=1;
    rep(1,i,L+1){//阶乘预处理
        fac[i]=fac[i-1]*i%mod;
    }
    invfac[L-1]=fast_power(fac[L-1],mod-2);//先求出n!的逆元
    Per(0,i,L-2){//阶乘逆元预处理//整个过程只调用了一次快速幂
        invfac[i]=invfac[i+1]*(i+1)%mod;
    }
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m>>mod;
        L=n+m;
        pre();
        ll ANS=C(n+m,m);
        cout<<ANS<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

