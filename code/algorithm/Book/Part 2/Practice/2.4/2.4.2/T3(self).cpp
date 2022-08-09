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
// 标记祖先 Marked Ancestor
// 1<=N,Q<=1e5
int par[MAX_N],_rank[MAX_N];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
bool vis[MAX_N+1];
//并查集的实现(改)
void Init(int n){//初始化
    rep(0,i,n){
        par[i]=i;
        _rank[i]=0;
    }
}

int find(int x){//查询x的根
    if(par[x]==x){
        return x;
    }
    else {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){//合并x和y所属的集合
    x=find(x);
    y=find(y);
    if(x==y){//本身就在同一集合
        return;
    }
    //rank不同
    if(_rank[x]<_rank[y]){//rank小的向rank大的连边
        par[x]=y;
    }
    else {
        par[y]=x;
        if(_rank[x]==_rank[y]) _rank[x]++;//x的高度增加
    }
    
}

bool same(int x,int y){//判断x和y是否属于同一集合
    return find(x)==find(y);
}

int Find(int x){//找最近的标记过的祖先
    if(vis[par[x]]){
        return par[x];
    }
    if(par[x]==x){//自己是自己祖先
        return x;
    }
    else {
        return par[x]=Find(par[x]);
    }
}

int N,Q;

void prev(){
    Init(N); 
    vis[1]=true;
    int x;//位次i的祖先
    Rep(2,i,N){
        cin>>x;
        unite(i,x);
    }

}
void solve(){
    int x;//标记位次
    char sign;//标记
    ll sum=0;
    rep(0,i,Q){
        cin>>sign>>x;
        if(sign=='Q'){
            sum+=Find(x);
        }
        else {
            vis[x]=true;
        }
    }
    cout<<sum<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N>>Q and N!=0 and Q!=0){
        memset(par,0,sizeof(par));
        memset(_rank,0,sizeof(_rank));
        memset(vis,0,sizeof(vis));
        prev();
        solve();
    }
    frepC;
    sys;
    return 0;
}

