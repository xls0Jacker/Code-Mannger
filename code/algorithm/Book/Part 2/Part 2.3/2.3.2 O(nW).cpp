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
const int MAX_N=105,MAX_W=1e4+5;
int n,W;
int w[MAX_N],v[MAX_N];
//完全背包问题
//1<=n<=100 1<=W<=1e4 1<=wi,vi<=100
/*  
    递推关系：
    dp[0][j]=0;
    dp[i+1][j]=max{dp[i][j-k*w[i]]+k*v[i])|0<=k};
    可知dp[i+1][j]计算k个的情况与dp[i+1][j-w[i]]计算(k-1)个的情况相同
    即dp[i+1][j]的递推中k>=1的部分已经在dp[i+1][j-w[i]]计算完毕
    故有以下变形:
    dp[i+1][j]
    =max{dp[i][j-k*w[i]]+k*v[i])|0<=k}
    =max{dp[i][j],max{dp[i][j-k*w[i]])|1<=k}
    =max{dp[i][j],max{dp[i][(j-w[i])-k*w[i]]|0<=k}+v[i])
    =max{dp[i][j],dp[i+1][j-w[i]]+v[i]};
*/
int dp[MAX_N][MAX_W];
void solve(){//O(nW)做法
    rep(0,i,n){
        Rep(0,j,W){
            if(j<w[i]){
                dp[i+1][j]=dp[i][j];
            }
            else {
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][W]<<endl;
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

