#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//邻接表
const int MAX=1e4+10;
int n,m;
vector<int>eg[MAX];

void add_edge(int a,int b){
    eg[a].push_back(b);
}

int T[MAX],dp[MAX],ind[MAX];
int Ans;
void solve(){
    //读入
    cin>>n;
    Rep(1,i,n){
        int u,v;
        cin>>u>>T[u];
        while(cin>>v){
            if(!v) break;
            ind[u]++;
            add_edge(v,u);//u依赖v
        }
    }
    //Topo Sort
    queue<int>q;
    Rep(1,i,n){//找出并压入入度为0的点
        if(!ind[i]){
            dp[i]=T[i];
            q.push(i);
        }
    }
    while(!q.empty()){//遍历出边
        int x=q.front();
        q.pop();
        rep(0,i,eg[x].size()){
            int y=eg[x][i];
            ind[y]--;//入度减一
            if(!ind[y]) q.push(y);//入度为0压入
            dp[y]=max(dp[y],dp[x]+T[y]);//
        }
    }
    Rep(1,i,n) Ans=max(Ans,dp[i]);
    cout<<Ans<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

