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
int n,m;

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
bool inq[MAX];
void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;\
    queue<int>q;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v; int l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
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
    int x,y,value;
    Rep(1,i,m){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
    }
    spfa(1);
    cout<<dis[n]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

