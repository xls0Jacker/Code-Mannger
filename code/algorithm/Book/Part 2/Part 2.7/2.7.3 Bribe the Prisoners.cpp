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
const int MAX_Q=105;
const int INF=1e9+7;
//Bride the Prisoners
//1<=N<=100 Q<=P 1<=P<=1e4 1<=Q<=100

//猜想：
//在释放某个囚犯后，
//监狱分为两段，此后这两段独立，
//因此，我们可以认为：
//我们每次只需要找到最小的最初的释放犯人的价格，
//加上之前释放的犯人的价格，
//就可以找到最小价格了
//用dp[i][j]表示从A[i]到A[j]中全部囚犯释放的金币价格（不包括两端）
int P,Q;//囚犯个数 需释放的囚犯个数
int A[MAX_Q];//囚犯位次
int dp[MAX_Q][MAX_Q];//从A[i]到A[j]囚犯全部释放的金币价格
void solve(){
    A[0]=0;//假设两端有囚犯，方便处理 
    A[Q+1]=P+1;
    Rep(0,q,Q){//初始化
        dp[q][q+1]=0;
    }
    Rep(2,w,Q+1){//从短区间开始填充dp（区间长度2-->3-->4-->...-->Q+1）暴搜
        for(int i=0;i+w<=Q+1;i++){
            int j=i+w,t=INF;
            rep(i+1,k,j){//区间(i,j)内枚举犯人（不包括两端）
                t=min(t,dp[i][k]+dp[k][j]);
            }
            dp[i][j]=t+(A[j]-A[i]-2);
        }
    }
    cout<<dp[0][Q+1]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>P>>Q;
    Rep(1,i,Q){
        cin>>A[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

