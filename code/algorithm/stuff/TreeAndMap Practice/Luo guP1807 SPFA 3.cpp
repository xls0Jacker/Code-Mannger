#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//最长路 spfa
const int MAX=1e5;

struct Edge{
    int u,v;
    int next;
    int l;
}eg[MAX];

int head[MAX];//头节点
int counts;//连接数

void add_edge(int a,int b,int c){
    counts++;//头节点a的边数增加
    eg[counts].u=a;eg[counts].v=b;eg[counts].l=-c;//创建a->b的连接
    eg[counts].next=head[a];//连接上一头节点
    head[a]=counts;//更新头节点
}

//正式内容
int dis[MAX];//dis[i] 源点s->i的最短距离
bool inq[MAX];//inq[i] 表示i是否在对列
const int INF=0x3f3f3f3f;
int n,m;

void spfa(int s){//源点
    for(int i=1;i<=n;i++){//所有点距离更新为无穷大 且状态为不在队中
        dis[i]=INF;
        inq[i]=false;
    }
    //加入源点开始寻找最短路径
    dis[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;
    //类bfs
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v;
            if(dis[u]+eg[i].l<dis[v]){
                dis[v]=dis[u]+eg[i].l;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    int u,v,l;
    Rep(1,i,m){
        cin>>u>>v>>l;
        add_edge(u,v,l);
    }
    spfa(1);
    if(dis[n]==INF) cout<<-1<<endl;
    else cout<<-dis[n]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

