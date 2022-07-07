#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
//有权邻接表的创建
int n,m;//点 边
const int MAX=1e5;

struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;
//增边
void add_edge(int a,int b,int c){
    counts++;
    eg[counts].u=a;eg[counts].v=b;eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}
//Dijkstra
int dis[MAX];
bool vis[MAX];
void dijk(int s){//距离及标记初始化
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>> q;//生成小根堆//first->dis second->pos
    q.push(mii(0,s));//压入源点
    dis[s]=0;
    while(!q.empty()){//判断堆顶是否走过，走过换下一堆顶
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){//在该堆中找最短路径
            int v0=eg[i].v,l0=eg[i].l;
            if(dis[v0]>dis[u]+l0){
                dis[v0]=dis[u]+l0;
                q.push(mii(dis[v0],v0));//压入短点
            }
            
        }
    }
    cout<<dis[n]<<endl;
}
//stuff

void solve(){
    cin>>n;
    int value;
    Rep(1,i,n){
        Rep(i+1,j,n){
            cin>>value;
            add_edge(i,j,value);
        }
    }
    dijk(1);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

