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
//定义dp[i]为长度为i+1的上升子序列末元素的最小值
//递推关系如下:
//dp[i]=min(dp[i],aj) i=0 or dp[i-1]<aj
//此时最后一位满足dp[i]<INF的i+1即是答案
const int INF=1e9+7;
int dp[MAX_N];
void solve(){//O(nlogn)做法
    fill(dp,dp+n,INF);//O(n)
    rep(0,i,n){//O(nlogn)
        *lower_bound(dp,dp+n,a[i])=a[i];//O(logn)
    }
    cout<<(lower_bound(dp,dp+n,INF)-dp)<<endl;//O(logn)
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

