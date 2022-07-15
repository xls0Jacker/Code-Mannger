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
//求斐波拉契数列的an项%mod
const int MAX=100;
const ll mod=1e9+7;
ll n;//数列下标
struct M{
    ll a[MAX][MAX];
};
//矩阵乘法
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
//矩阵乘法快速幂
M fast_power(M a,ll b){
    M ret;
    memset(ret.a,0,sizeof(ret.a));
    rep(0,i,4){
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
    M A,B;
    //输入
    cin>>n;
    memset(A.a,0,sizeof(A.a));
    memset(B.a,0,sizeof(B.a));
    A.a[0][0]=A.a[0][1]=1;
    /*
        A | 1 1 |
    */
    B.a[0][0]=0;
    B.a[0][1]=B.a[1][1]=B.a[1][0]=1;
    //矩阵快速幂
    if(n!=1) B=fast_power(B,n-2);
    else {
        cout<<1<<endl;
        return;
    }
    M ANS=mul(A,B);
    //输出
    cout<<ANS.a[0][1]<<endl;
}  

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

