#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
using namespace std;
const int MAX_M=1e5;
const int MAX_N=1000;
//  奶牛派对 Silver Cow Party
//  1≤N≤1000 1≤M≤1e5 1≤X≤N
//  1≤A,B≤N,1≤T≤100

//思路：
//正向最短路径反向建边，(单向图)
//返回最短路径正向建边，
//无负权有重边有自环，
//可使用dijkstra堆优化进行求解

//思路2：
//将单源最短路dijkstra改写为任意两点间最短路，
//此时只用一遍dijkstra就可出答案

struct Edge{
    int u,v;
    int next;
    int l;
}eg[MAX_M+1];
int head[MAX_M+1];
int cnt;

void add_edge(int x,int y,int z){
    cnt++;
    eg[cnt].u=x;eg[cnt].v=y;eg[cnt].l=z;
    eg[cnt].next=head[x];
    head[x]=cnt;
}
int N,M,X;//顶点数 边数 终点编号（从1开始）
int xx[MAX_M+1],yy[MAX_M+1],zz[MAX_M+1];
int a[MAX_N+1];
void prev(){
    rep(0,i,M){
        cin>>xx[i]>>yy[i]>>zz[i];
        xx[i]--,yy[i]--;//化为从0开始
        add_edge(yy[i],xx[i],zz[i]);//反向建边
    }
}


int d[MAX_N+1][MAX_N+1];
bool vis[MAX_N+1];
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s][s]=0;
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mii(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v,l=eg[i].l;
            if(d[s][v]>d[s][u]+l){
                d[s][v]=d[s][u]+l;
                q.push(mii(d[s][v],v));
            }
        }
    }
}
void solve(){
    dijkstra(X);
    rep(0,i,N){
        a[i]=d[i][X]+d[X][i];
    }
    cout<<*max_element(a,a+N)<<endl;
    cout<<"Unfinished"<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M>>X;
    X--;//化为从0开始
    prev();
    solve();
    frepC;
    sys;
    return 0;
}

