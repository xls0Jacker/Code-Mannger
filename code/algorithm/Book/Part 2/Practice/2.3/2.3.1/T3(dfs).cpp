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
// 捡苹果 Apple Catching
// 1≤T≤1000 1≤W≤30

//穷竭搜索dfs试水
int T,W;
int vis[MAX_T+1];
int ans=-1;
void dfs(int t,int cnt,int sum){
    if(t==T+1){
        ans=max(ans,sum);
        return;
    }
    if(vis[t]==1 and cnt%2==0){//在1号位 移动偶数次 仍在1号位
        dfs(t+1,cnt,sum+1);//不移动
        if(cnt<W) dfs(t+1,cnt+1,sum);//移动
        else return;
    }
    else if(vis[t]==1 and cnt%2==1){//在1号位 移动奇数次 在2号位
        dfs(t+1,cnt,sum);//不移动
        if(cnt<W) dfs(t+1,cnt+1,sum+1);//移动
        else return;
    }
    else if(vis[t]==2 and cnt%2==0){//在2号位 移动偶数次 在1号位
        dfs(t+1,cnt,sum);//不移动
        if(cnt<W) dfs(t+1,cnt+1,sum+1);//移动
        else return;
    }
    else if(vis[t]==2 and cnt%2==1){//在2号位 移动奇数次 在2号位
        dfs(t+1,cnt,sum+1);//不移动
        if(cnt<W) dfs(t+1,cnt+1,sum);//移动
        else return;
    }
    return;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

void solve(){
    dfs(1,0,0);//开始在1号位
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>T>>W;
    Rep(1,i,T){
        cin>>vis[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

