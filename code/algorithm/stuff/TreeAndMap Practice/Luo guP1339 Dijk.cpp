#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//无向图Dijkstra堆优化//其实就是把边反向又连了一次
const int MAX=1e5;
int n,m;

struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;
void add_edge(int a,int b,int c){
    counts++;
    eg[counts].u=a; eg[counts].v=b; eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}

int dis[MAX];
bool vis[MAX];
void Dijk(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push(mii(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v,l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.push(mii(dis[v],v));
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    int x,y,value;
    Rep(1,i,m){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
    }
    Dijk(s);
    cout<<dis[t]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

