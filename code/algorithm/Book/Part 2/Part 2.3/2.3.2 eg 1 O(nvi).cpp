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
const int MAX_N=100,MAX_V=100,MAX_W=1e7+5;
const int INF=1e9+7;
int n,W;
int w[MAX_W],v[MAX_V];
//01背包 -2
//1<=n<=100 1<=vi<=100 1<=wi<=1e7 1<=W<=1e9
//此时若与之前相同采用O(nW)复杂度会超时
//我们发现，相较于重量而言，价值的范围比较小，我们可以试着转换一下dp的对象
//定义dp[i+1][j]为前i个物品总重量的最小值
//初始值 dp[0][0]=dp[0][j]=0 其余为INF
//dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
int dp[MAX_N+1][MAX_N*MAX_V+1];
void solve(){//O(n∑ivi)做法
    fill(dp[0],dp[0]+MAX_N*MAX_V+1,INF);
    dp[0][0]=0;
    rep(0,i,n){
        Rep(0,j,MAX_N*MAX_V){
            if(j<v[i]){
                dp[i+1][j]=dp[i][j];
            }
            else dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    int res=0;
    Rep(0,i,MAX_N*MAX_V){//找最小成立价值
        if(dp[n][i]<=W){
            res=i;
        }
    }
    cout<<res<<endl;
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

