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
const int MAX_N=1000;
const int MAX_M=20000;
// 贝茜的怨念 Bad Cowtractors
// 2≤N≤1000 1≤M≤20000
// 1≤A,B≤N,1≤C≤100000

//思路：
//题意告诉我们这时一个无环的生成树，
//此时我们需要求最大的代价，
//考虑到输入的规模及方式，
//使用krsukal算法求解最小生成树，
//将边改为负值，
//即可求得最大生成树（输出注意加上负号即可）
int N,M;
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

int krsukal(){
    sort(eg,eg+M,cmp);
    Init(N);
    int res=0;
    rep(0,i,M){
        Edge e=eg[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
void solve(){
    cout<<-krsukal()<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    int A,B,C;
    rep(0,i,M){
        cin>>A>>B>>C;
        eg[i]=(Edge){A,B,-C};
    }
    solve();
    frepC;
    sys;
    return 0;
}

