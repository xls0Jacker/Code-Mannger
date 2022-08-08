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
// 修复网络 Wireless Network
// 1≤N≤1001 0≤d≤20000 0≤xi,yi≤20000
// O: 1≤p≤N S: 1<=q,p<=N
const int MAX_N=1001;
//思路：
//出现O时，将该电脑加入并查集,
//出现S时，判断其与其中任意一个已经加入并查集的数是否在范围之内，
//在且这个数在并查集中，则输出SUCCESS 反之输出FAIL

//解决方法:
//先对每一个坐标判断是否能够连接 (O(n(n-1)/2))
//之后若出现O时，把已经加入并查集的点遍历一遍，
//判断是否能够连接，把所有可以连接的点unite，（先用vector把已经压入的点存起来）
//出现S时，直接判断是否属于同一组，
//若成立则输出 SUCCESS 后跳出，反之输出 FAIL，
//完。
int par[MAX_N+2],_rank[MAX_N+2];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
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
int N;
ll d;
struct st{
    ll x,y;
    int index;
}node[MAX_N+2];

int vis[MAX_N+2][MAX_N+2];
void prev(){//判断每个电脑能否连接
    rep(0,i,N){
        rep(i+1,j,N){//之后S查找记得排除本身
            if((abs(node[j].x-node[i].x)*abs(node[j].x-node[i].x)+abs(node[j].y-node[i].y)*abs(node[j].y-node[i].y))<=d*d){//在⚪内
                vis[node[i].index][node[j].index]=vis[node[j].index][node[i].index]=true;
            }
        }
    }
}
void solve(){
    Init(N);
    char sign;//符号
    int a,b;//检测的数
    int c;//加入的数
    vector<int>v;//存已经进入并查集的点
    while(cin>>sign){
        if(sign=='O'){
            cin>>c;
            v.push_back(c);
            rep(0,i,v.size()){
                if(vis[v[i]][c]){
                    unite(v[i],c);//连接两台电脑
                }
            }
        }       
        else {
            cin>>a>>b;
            if(same(a,b)) cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>d;
    rep(0,i,N){
        cin>>node[i].x>>node[i].y;
        node[i].index=i+1;
    }
    prev();
    solve();
    frepC;
    sys;
    return 0;
}

