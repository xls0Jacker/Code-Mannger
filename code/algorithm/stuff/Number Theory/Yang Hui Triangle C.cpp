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
//杨辉三角实现组合数//效率较低 具体见逆元加速实现组合数
const int MAX=100;
int C[MAX][MAX];
void pre(){
    C[0][0]=1;
    rep(1,i,MAX){
        C[i][0]=1;
        Rep(1,j,i){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
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

