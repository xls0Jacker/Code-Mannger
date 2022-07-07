#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//来回最短路径求最大值
//Dijkstra单源最小值 ＋ 单终点最小值 + sort
const int MAX=1e6;
int n,m;
int s,f;
struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;
void add_edge(int a,int b,int c){
    counts++;
    eg[counts].u=a; eg[counts].v=b;
    eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}

int dis[MAX];
bool vis[MAX];
void Dijk(int s){
    memset(dis,0x3f,sizeof(dis));
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dis[s]=0;
    q.push(mii(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v,l=eg[i].l;
            int k=max(dis[u],l);//切换约束条件，将求和转化为求边权最大值
            if(k<dis[v]){
                dis[v]=k;
                q.push(mii(dis[v],v));
            }
        }
    }
}


void solve(){
    cin>>n>>m>>s>>f;
    int x,y,value;
    Rep(1,i,m){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
    }
    Dijk(s);
    cout<<dis[f]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

