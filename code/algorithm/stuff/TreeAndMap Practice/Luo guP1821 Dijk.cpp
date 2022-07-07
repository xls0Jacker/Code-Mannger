#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX=1e6;
int n,m,f;

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
void dijk(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
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
            int v=eg[i].v; int l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.push(mii(dis[v],v));
            }
        }
    }
}

int xx[MAX],yy[MAX],vv[MAX];
int Back[MAX];
int ANS[MAX];
void solve(){
    cin>>n>>m>>f;
    Rep(1,i,m){//找回家最短距离
        cin>>xx[i]>>yy[i]>>vv[i];
        add_edge(xx[i],yy[i],vv[i]);
    }
    dijk(f);
    Rep(1,i,n) Back[i]=dis[i];
    memset(head,0,sizeof(head));
    Rep(1,i,m){//找参加派对的最短距离//反向建边
        add_edge(yy[i],xx[i],vv[i]);
    }
    dijk(f);
    Rep(1,i,n){//存储总路径
        ANS[i]=Back[i]+dis[i];
    }
    sort(ANS+1,ANS+n+1,greater<int>());
    cout<<ANS[1]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

