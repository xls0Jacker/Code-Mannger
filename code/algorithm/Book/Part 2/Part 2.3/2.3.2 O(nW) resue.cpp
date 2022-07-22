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
    dp[i+1][j]=max{dp[i][j],dp[i+1][j-w[i]]+v[i]};
    通过堆DP数组的再利用可以节约内存
    在这一递推式中，dp[i+1][j]计算只需要dp[i]和dp[i+1]，所以可用利用奇偶性质得到以下写法:
*/
int dp[2][MAX_W];
void solve(){//O(nW)做法
    rep(0,i,n){
        Rep(0,j,W){
            if(j<w[i]){
                dp[(i+1)&1][j]=dp[i&1][j];
            }
            else {
                dp[(i+1)&1][j]=max(dp[i&1][j],dp[(i+1)&1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n&1][W]<<endl;
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

