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
const int MAX_N=1e5;
const int MAX_M=1e5;
int N;
//并查集的实现：
int par[MAX_N+1],_rank[MAX_N+1];
void Init(int n){
  rep(0,i,N){
      par[i]=i;
      _rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x){
      return x;
  }
  else {
      return par[x]=find(par[x]);
  }
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y){
      return;
  }
  if(_rank[x]<_rank[y]){
      par[x]=y;
  }
  else {
      par[y]=x;
      if(_rank[x]==_rank[y]) _rank[x]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

struct Edge{
  int u,v,cost;
};
bool cmp(Edge e1,Edge e2){
  return e1.cost<e2.cost;
}

Edge eg[MAX_M+1];
int MAX = -1;
int krsukal(){
  sort(eg, eg + N - 1, cmp);
  Init(N);
  int res=0;
  rep(0, i, N - 1){
    Edge e=eg[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res+=e.cost;
      MAX = max(e.cost, MAX);
    }
  }
  return res;
}
void solve(){
  cout << krsukal() - MAX << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> N;
  int A, B, C;
  rep(0, i, N - 1){
    cin >> A >> B >> C;
    eg[i] = (Edge){A, B, C};
  }
  solve();
  frepC;
  sys;
  return 0;
}