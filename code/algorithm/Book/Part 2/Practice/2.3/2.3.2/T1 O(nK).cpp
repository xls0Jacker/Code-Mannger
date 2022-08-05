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
const int MAX_N=100;
const int MAX_M=1e5;
// 金币 Coins
// 1≤n≤100 1≤M≤1e5 1≤Ai≤1e5 1<=Ci<=1e3

//思路：
//定义dp[i+1][j]为前i个数是否能加和为k，有
//dp[i+1][j]=(k<=C[i]且j-k*A[i]>=0时dp[i][j-k*A[i]]为真的k)
//解决方法：
//如dp[i+1][j]=0,dp[i][j-k*A[i]]=1(条件合法)
//则dp[i+1][j]|=dp[i][j-k*A[i]]=>1(0|1=1)（按位或运算）

//再将数组进行重复利用进一步减少空间复杂度

//优化思路：
//定义dp[i+1][j]为使用前i位数达到j的第i种数的最大剩余数目，有
//dp[i+1][j]={
//Ci dp[i][j]>=0 （前面的(i-1)位数字使用后仍有余数，不需要使用第i位数）
//-1 j<A[i] or dp[i+1][j-A[i]]<=0 （第i位数超过或不足）
//dp[i+1][j-A[i]]-1 其他 （第i位数的数目减一）
//}

//再将数组进行重复利用进一步减少空间复杂度
int n,M;
int dp[MAX_M+2];
int A[MAX_N+1],C[MAX_N+1];
void solve(){//O(nK)
    dp[0]=0;
    rep(0,i,n){
        Rep(0,j,M){
            if(dp[j]>=0){
                dp[j]=C[i];
            }
            else if(j<A[i] or dp[j-A[i]]<=0){
                dp[j]=-1;
            }
            else dp[j]=dp[j-A[i]]-1;
        }
    }
    int ans=0;
    Rep(1,i,M){//排除总额为0的情况
        if(dp[i]>=0) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>n>>M and n!=0 and M!=0){
        memset(A,0,sizeof(A));
        memset(C,0,sizeof(C));
        memset(dp,-1,sizeof(dp));
        rep(0,i,n){
            cin>>A[i];
        }
        rep(0,i,n){
            cin>>C[i];
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

