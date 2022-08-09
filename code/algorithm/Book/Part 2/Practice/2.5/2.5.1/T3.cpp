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
const int MAX_N=500;
const int MAX_M=2500,MAX_W=200;
// 虫洞 Wormholes
// 1≤F≤5 1≤N≤500 1≤M≤2500 1≤M≤200
// 1≤S,E≤N 1≤T≤10000

//思路:
//使用Bellford算法判断是否有s可达的负环（增边操作很简单就不写了）
struct edge{
    int from,to,cost;
};
edge es[2*MAX_M+MAX_W+1];
int d[MAX_N+1];
int e;
void add_edge(int x,int y,int z){
    es[e].from=x;es[e].to=y;
    es[e].cost=z;
}
int F;
int N,M,W;
void prev(){
    e=0;
    int S,E,T;
    rep(0,i,M){
        cin>>S>>E>>T;
        S--,E--;//化为从0开始
        add_edge(S,E,T);
        e++;
        add_edge(E,S,T);
        e++;
    }
    rep(0,i,W){
        cin>>S>>E>>T;
        S--,E--;//化为从0开始
        add_edge(S,E,-T);
        e++;
    }
}

bool find_negative_loop(){
    rep(0,i,N){
        rep(0,j,2*M+W){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                if(i==N-1) return true;
            }
        }
    }
    return false;
}

void solve(){
    if(find_negative_loop()){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>F;
    while(F--){
        memset(es,0,sizeof(es));
        memset(d,0,sizeof(d));
        cin>>N>>M>>W;
        prev();
        solve();
    }
    frepC;
    sys;
    return 0;
}

