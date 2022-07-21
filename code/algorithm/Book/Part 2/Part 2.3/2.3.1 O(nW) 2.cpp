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
const int MAX=105;
int n,W;
int w[MAX],v[MAX];
//01背包问题
//1<=n<=100 1<=wi,vi<=100 1<=W<=10000
//针对每个物品是否放入背包进行搜索
//加速方法 动态规划法（DP）
int dp[MAX][MAX];
void solve(){//O(nW)做法
    Per(0,i,n-1){
        Rep(0,j,W){
            if(j<w[i]){
                dp[i][j]=dp[i+1][j];
            }
            else {
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[0][W]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>w[i];
    }
    rep(0,i,n){//O(n)
        cin>>v[i];
    }
    cin>>W;
    solve();
    frepC;
    sys;
    return 0;
}

