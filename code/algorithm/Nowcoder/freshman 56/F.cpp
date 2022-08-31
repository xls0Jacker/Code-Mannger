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
const int MAX_N=2e5,MAX_M=2e5;

// 阿宁去游玩
// 2<=n<=2e5 1<=m,x,y,z<=2e5 1<=u,v<=n 0<=ai<=1

// 思路：
// 在连接边时，判断属性是否相同 之后选择最小的路径作为两者之间的路径
// 之后求最短路即可（考虑到数据规模，使用dijkstra堆优化的方法来求解）


// 解决方法：
// 在输入两个对象的边时，看下数组中的两个城市的属性是否相同
// 之后使用dijkstra堆优化求1到n的最短路
struct Edge{
  int u,v;
  int next;
  int l;
}eg[MAX_M+1];

int head[MAX_N+1];
int counts;

void add_edge(int a,int b,int c){
  counts++;
  eg[counts].u=a;eg[counts].v=b;
  eg[counts].l=c;
  eg[counts].next=head[a];
  head[a]=counts;
}

int dis[MAX_N+1];
bool vis[MAX_N+1];
void dijk(int s) {
  memset(dis,0x3f,sizeof(dis));
  dis[s]=0;
  typedef pair<int,int> pii,mii;
  priority_queue<pii,vector<pii>,greater<pii>> q;
  q.push(mii(0,s));
  while(!q.empty()) {
    int u=q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u]=true;
    for(int i=head[u];i;i=eg[i].next) {
      int v=eg[i].v,l=eg[i].l;
      if(dis[v] > dis[u] + l) {
        dis[v] = dis[u] + l;
        q.push(mii(dis[v],v));
      }
    }
  }
}
int n,m;
int x,y,z;
int a[MAX_N+1];
void solve(){
  dijk(0);
  cout<<dis[n-1]<<endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin>>n>>m;
  cin>>x>>y>>z;
  rep(0,i,n) {
    cin>>a[i];
  }
  int u,v;
  rep(0,i,m) {
    cin>>u>>v;
    u--,v--;
    if(a[u] == a[v]) { //属性相同
      add_edge(u,v,min(x,y+z));
      add_edge(v,u,min(x,y+z));
    } else {
      add_edge(u,v,min(x+z,y));
      add_edge(v,u,min(x+z,y));
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}

