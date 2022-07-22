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
int a[MAX_N];
//多重集组合数
//1<=n,m,ai<=1e3 2<=M<=1e4
//定义dp[i+1][j]为从前i个物品中取出j个的组合数
//递推关系如下：
//dp[i+1][j]=∑_(𝑘=0)^min(j,a[i])dp[i][j-k];//O(nm^2)
//为减小时间复杂度，可转化为:
//∑_(𝑘=0)^min(j,a[i])dp[i][j-k]=∑_(𝑘=0)^min(j-1,a[i])dp[i][j-1-k]+dp[i][j]-dp[i][j-1-ai];
//=>dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-ai]; 
int dp[MAX_N][MAX_M];
void solve(){//O(nm)做法
    Rep(0,i,n){//O(n)
        dp[i][0]=1;//前i个物品选零个的方法总只有一种
    }
    rep(0,i,n){//O(nm)
        Rep(1,j,m){
            if(j-1-a[i]>=0){
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+M)%M;//(x+M)%M保证非负
            }
            else dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>m;
    rep(0,i,n){//O(n)
        cin>>a[i];
    }
    cin>>M;
    solve();
    frepC;
    sys;
    return 0;
}

