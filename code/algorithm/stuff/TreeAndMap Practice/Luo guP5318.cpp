#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
//图的深搜和广搜
const int MAX=1e6+10;
int n,m;

vector<int> eg[MAX];
void add_edge(int a,int b){
   eg[a].push_back(b);
}

bool vis[MAX];
void dfs(int x,int cnt){//当前节点位置 访问节点数
    vis[x]=1;
    cout<<x<<" ";
    if(cnt==n) return;
    for(int i=0;i<eg[x].size();i++){
        if(!vis[eg[x][i]]) dfs(eg[x][i],cnt++);
    }
}

void bfs(int x){
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int y=q.front();
        q.pop();
        cout<<y<<" ";
        rep(0,i,eg[y].size()){
            if(!vis[eg[y][i]]){
                vis[eg[y][i]]=1;
                q.push(eg[y][i]);
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    int x,y;//创图
    Rep(1,i,m){
        cin>>x>>y;
        add_edge(x,y);
    }
    Rep(1,i,n) sort(eg[i].begin(),eg[i].end());
    dfs(1,0);
    cout<<endl;
    bfs(1);
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

