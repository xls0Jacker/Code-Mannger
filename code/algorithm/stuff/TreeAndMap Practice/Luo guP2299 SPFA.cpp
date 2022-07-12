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

//正式内容
int dis[MAX];//dis[i] 源点s->i的最短距离
bool inq[MAX];//inq[i] 表示i是否在对列
const int INF=0x3f3f3f3f;
//输出路径
//int pre[MAX];
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
            if(dis[v]>dis[u]+eg[i].l){
                dis[v]=dis[u]+eg[i].l;
                //pre[v]=u;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
}

// void print(int s,int f){
//     if(s==f){
//         cout<<s<<" ";
//         return;
//     }
//     print(s,pre[f]);
//     cout<<f<<endl;
// }

void solve(){
    cin>>n>>m;
    int x,y,value;
    Rep(1,i,m){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
    }
    // Rep(1,i,n){
    //     pre[i]=i;
    // }
    spfa(1);
    cout<<dis[n]<<endl;
    //print(1,n);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

