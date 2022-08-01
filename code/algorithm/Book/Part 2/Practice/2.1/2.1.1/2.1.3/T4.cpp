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
const int MAX_R=10,MAX_C=1e4;
//烤饼游戏 Osenbei
//1≤r≤10,1≤c≤10000

//思路：
//从数据中我们可以发现，行的数值范围比列的范围要小，
//对于每一行可以选择翻转或者不反转，
//与此同时，我们可以直接对列进行翻转，
//当该列的0的数量大于1的数量时，
//翻转该列
//统计1的总数，并且不断更新
int M[MAX_R+1][MAX_C+1];
int r,c;//行 列 
int ans;
void dfs(int x){//行数
    if(x==r){
        int sum=0;
        rep(0,i,c){//统计1的最大个数
            int res=0;
            rep(0,j,r){
                if(M[j][i]==1){
                    res++;
                }
            }
            res=max(res,r-res);
            sum+=res;//更新当前情况最大值
        }
        ans=max(ans,sum);//更新所有情况的最大值
        return;
    }
    dfs(x+1);//不反转这一行
    rep(0,i,c){//翻转这一行
        M[x][i]=1-M[x][i];
    }
    dfs(x+1);
}
void solve(){
    dfs(0);
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>r>>c and r!=0 and c!=0){
        rep(0,i,r){
            rep(0,j,c){
                cin>>M[i][j];
            }
        }
        ans=0;
        solve();
    }
    frepC;
    sys;
    return 0;
}

