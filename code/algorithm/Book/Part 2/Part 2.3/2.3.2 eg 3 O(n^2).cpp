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
const int MAX_N=1e3+5;
int n;
int a[MAX_N];
//最长上升子序列问题pp
// 1<=n<=1e3 0<=ai<=1e6
//定义dp[i]为以ai为末尾的最长上升子序列长度
//递推关系如下:
//dp[i]=max{1,dp[j]+1|j<i and aj<ai}
int dp[MAX_N];
void solve(){ 
    int res=0;//O(n^2)
    rep(0,i,n){
        dp[i]=1;
        rep(0,j,i){
            if(a[j]<a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){
        cin>>a[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

