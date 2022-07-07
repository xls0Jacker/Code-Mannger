#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//无向图多源spfa求最短路//不理解 
const int MAX=2000;
int n,m;
struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

struct ANS{
    int a,b;
}Ans[MAX];

bool cmp(ANS a,ANS b){
    if(a.a==b.a){
        return a.b<b.b;
    }
    else{
        return a.a<b.a;
    }
}

int head[MAX],counts;
void add_edge(int a,int b){
    counts++;
    eg[counts].u=a; eg[counts].v=b;
    eg[counts].l=1;
    eg[counts].next=head[a];
    head[a]=counts;
}

const int INF=0x3f3f3f3f;
bool inq[MAX];
int dis[MAX];
void spfa(int s,int f){
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    inq[s]=1;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v;
            //Begin
            if(v==f and u==s){//若为s->f跳出
                continue;
            }
            //End
            if(dis[u]+eg[i].l<dis[v]){
                dis[v]=dis[u]+eg[i].l;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int x[MAX],y[MAX];
int cnt;
void solve(){
    cin>>n>>m;
    Rep(1,i,m){
        cin>>x[i]>>y[i];
        add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
    }
    Rep(1,i,m){
        spfa(x[i],y[i]);
        if(dis[y[i]]>=INF){
            cnt++;
            Ans[cnt].a=min(x[i],y[i]);
            Ans[cnt].b=max(x[i],y[i]);
        }
    }
    sort(Ans+1,Ans+cnt+1,cmp);
    Rep(1,i,cnt){
        cout<<Ans[i].a<<" "<<Ans[i].b<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

