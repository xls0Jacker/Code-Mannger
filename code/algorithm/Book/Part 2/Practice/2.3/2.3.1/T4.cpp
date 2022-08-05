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
const int MAX_N=1e6;
// 挤奶时间 Milking Time
// 1≤N≤1e6 1≤M≤1e3 0<=Si<Ti<=N 1<=Ei<=1e6 1<=R<=N 

//思路：
//定义dp[i]为时间i下的总效率的最大值，
//其满足其值为满足条件的（之前的）总效率效率加上当前效率的最大值
//dp[i]=max(dp[i],dp[j]+E[j]);

int N,M,R;
int dp[MAX_N+1];

struct L{
    int S,T,E;
}D[MAX_N+1];

bool cmp(L a,L b){
    return a.S<b.S;
}
void prev(){//转化为实际结束时间
    rep(0,i,M){
        D[i].T+=R;
    }
}
void solve(){//O(∑iMi)
    sort(D,D+M,cmp);//按开始时间排序方便找能达到的最大值
    rep(0,i,M){
        dp[i]=D[i].E;
        rep(0,j,i){
            if(D[j].T<=D[i].S){//在i所有的可达位置的中找最大值
                dp[i]=max(dp[i],dp[j]+D[i].E);
            }
        }
    }
    cout<<*max_element(dp,dp+M)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N>>M>>R){
        memset(dp,0,sizeof(dp));
        memset(D,0,sizeof(D));
        rep(0,i,M){
            cin>>D[i].S>>D[i].T>>D[i].E;
        }
        prev();
        solve();
    }
    frepC;
    sys;
    return 0;
}

