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
const int MAX_N=1e3+5,MAX_M=1e3+5;
int n,m,M;
//划分数
//1<=m<=n<=1e3 2<=M<=1e4
//若视n的m划分为ai，那么当对于每一个ai>0时有(ai-1)为n-m的m划分;若存在ai=0时有(ai-1)为n的m-1划分
//定义dp[i][j]为j的i划分
//递推关系如下：
//dp[i][j]=dp[i][j-i]+dp[i-1][j];
int dp[MAX_N][MAX_M];
void solve(){
    dp[0][0]=1;
    Rep(1,i,m){
        Rep(0,j,n){
            if(i<=j){
                dp[i][j]=(dp[i][j-i]+dp[i-1][j])%M;
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[m][n]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>m>>M;
    solve();
    frepC;
    sys;
    return 0;
}

