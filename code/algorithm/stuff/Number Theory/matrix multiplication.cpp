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
//矩阵乘法快速幂
//求A*B^n
const int MAX=100;
struct M{
    int a[MAX][MAX];
};
//矩阵乘法
M mul(M a,M b){
    M c;
    memset(c.a,0,sizeof(c.a));
    rep(0,i,100){
        rep(0,j,100){
            rep(0,k,100){
                c.a[i][j]=a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}
//矩阵乘法快速幂
M fast_power(M a,int b){
    M ret;
    memset(ret.a,0,sizeof(ret.a));
    rep(0,i,100){
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

}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

