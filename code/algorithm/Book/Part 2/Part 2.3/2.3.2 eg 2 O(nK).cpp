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
//通常利用DP求出bool的结果的话会有不少的浪费，
//同样的复杂度往往可以得到更多的信息
//定义dp[i+1][j]为用前i种数加和得到j时第i种数最多剩余的数量
//有如下的递推关系：
//dp[i+1][j]
//={
//  mi dp[i][j]>=0
//  -1 j<a[i] or dp[i+1][j-a[i]]<=0
//  dp[i+1][j-a[i]]-1 其他  
//}
//我们发现 dp[i+1]计算时只有dp[i+1]
//这里我们可以重复利用数组来节约空间
int dp[MAX_K];
void solve(){//O(nK)做法
    memset(dp,-1,sizeof(dp));
    dp[0]=false;
    rep(0,i,n){
        Rep(0,j,K){
            if(dp[j]>=0){
                dp[j]=m[i];
            }
            else if(j<a[i] or dp[j-a[i]]<=0){
                dp[j]=-1;
            }
            else dp[j]=dp[j-a[i]]-1;
        }
    }
    if(dp[K]>=0) puts("Yes");
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

