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
const int MAX_N=5*1e4,MAX_K=1e6;
//以下为并查集的实现:
int par[3*MAX_N],ranks[3*MAX_N];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
//并查集的实现
void Init(int n){//初始化
    rep(0,i,n){
        par[i]=i;
        ranks[i]=0;
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
    if(ranks[x]<ranks[y]){//rank小的向rank大的连边
        par[x]=y;
    }
    else {
        par[y]=x;
        if(ranks[x]==ranks[y]) ranks[x]++;//x的高度增加
    }
}

bool same(int x,int y){//判断x和y是否属于同一集合
    return find(x)==find(y);
}
int T[MAX_K],X[MAX_K],Y[MAX_K];//T表示信息的类型 第一种->1 第二种->2
int N,K;//动物数 信息数
//食物链
//1<=N<=50000 0<=K<=1e5
//对于每只动物创建3个元素 i-A i-B i-C，并利用这3*N个元素建立并查集
//对于每一条信息，按照以下操作：
//第一种，合并x-A y-A;x-B y-B;x-C y-C
//第二种，合并x-A y-B;x-B y-C;x-C y-A
//每次合并之前判断是否有冲突
void solve(){
    Init(3*N);
    int ans=0;
    rep(0,i,K){//O(kα(n))?
        int t=T[i];
        int x=X[i]-1,y=Y[i]-1;//把输入变成0,1...N-1
        if(x<0 or N<=x or y<0 or N<=y){//输入位置判断是否合法
            ans++;
            continue;
        }
        if(t==1){//situation 1
            if(same(x,y+N) or same(x,y+2*N)){
                ans++;
            }
            else {
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            } 
        }
        else {//situation 2
            if(same(x,y) or same(x,y+2*N)){
                ans++;
            }
            else {
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            } 
        }   
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //frep;
    cin>>N>>K;
    rep(0,i,K){//O(n)
        cin>>T[i]>>X[i]>>Y[i];
    }
    solve();
    //frepC;
    //sys;
    return 0;
}

