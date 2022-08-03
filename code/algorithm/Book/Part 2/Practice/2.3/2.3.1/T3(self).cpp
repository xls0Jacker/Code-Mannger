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
const int MAX_T=1000;
const int MAX_W=30;
// 捡苹果 Apple Catching
// 1≤T≤1000 1≤W≤30

//定义dp[i][j]为第i时间移动了j次后取得的果子数目，有
//若在移动后才有果子：
//dp[i+1][j]=max(dp[i+1][j],dp[i][j]);//不移动
//dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);//移动
//?（我也不知道为啥就过了）
int T,W;
int vis[MAX_T+1];
int dp[MAX_T+1][MAX_W+2];//由于数组的MAX_W与0均可能用到，所以不能多开1而是多开2
void solve(){
    Rep(1,i,T){
        Rep(0,j,W){
            if((vis[i]==1 and j%2==0) or (vis[i]==2 and j%2==1)){//不移动有果子
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);//不移动
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);//移动
            }
            else {//移动有果子 
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);//不移动
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);//移动
            }
        }
    }
    int ans=-1;
    Rep(0,i,W){
        ans=max(ans,dp[T+1][i]);
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>T>>W){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        Rep(1,i,T){
            cin>>vis[i];
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

