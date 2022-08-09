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
// 城市帮派 Find them, Catch them
// 1≤T≤20 1<=N,M<=1e5

//思路：
//将不是一个帮派的连接起来，
//其中奇数项为同一个帮派，偶数项为另一帮派，
//未出现连接关系的（不在同一组的），不详

//解决方法：
//将非同一组的unite连接起来，
//根据其上一个点所在的动态数组存入另一数组中，？
//最后判断时，根据是否连接，
//若连接，检测这两个数是否在同一数组中，
//  若在，则为同一帮派，
//  反之，不在同一帮派，
//反之，不详

//难以实现

//思路2：
//开一个2*N的空间，
//不属于同一帮派的两个分别连接在前半区间和后半区间，
//
int par[MAX_N*2+1],_rank[MAX_N*2+1];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
//并查集的实现
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

int T;
int N,M;
string s[]={"In the same gang.","In different gangs.","Not sure yet."};
void solve(){
    Init(N*2);
    char sign;
    int a,b;
    while(M--){
        cin>>sign>>a>>b;
        if(sign=='D'){//双向成立
            unite(a,b+N);
            unite(a+N,b);
        }
        else {
            if(same(a,b) or same(a+N,b+N)){
                cout<<s[0]<<endl;
            }
            else if(same(a,b+N) or same(a+N,b)){
                cout<<s[1]<<endl;
            }
            else {
                cout<<s[2]<<endl;
            }
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>T;
    while(T--){
        memset(par,0,sizeof(par));
        memset(_rank,0,sizeof(_rank));
        cin>>N>>M;
        solve();
    }
    
    frepC;
    sys;
    return 0;
}

