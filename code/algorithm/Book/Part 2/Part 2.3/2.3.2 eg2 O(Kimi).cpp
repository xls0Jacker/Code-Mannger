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
const int MAX_N=105,MAX_K=1e5+5;
int n,K;
int a[MAX_N],m[MAX_K];//数字 及其个数
//多重部分和问题
//1<=n<=100 1<=ai,mi<=1e5 1<=K<=1e5
//定义dp[i+1][j]为前i种数字能否加和为j
//有如下的递推关系：
//dp[i+1][j]=(0<=k<=mi且k*ai<=j时存在使dp[i][j-k*a[i]]为真的k)
bool dp[MAX_N][MAX_K];
void solve(){
    dp[0][0]=true;
    rep(0,i,n){
        Rep(0,j,K){
            for(int k=0;k<=m[i] and k*a[i]<=j;k++){
                dp[i+1][j]=dp[i][j-k*a[i]];
            }
        }
    }
    if(dp[n][K]) puts("Yes");
    else puts("No");
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>K;
    rep(0,i,n){//O(n)
        cin>>a[i];
    }
    rep(0,i,n){//O(n)
        cin>>m[i];
    }
    cin>>K;
    solve();
    frepC;
    sys;
    return 0;
}

