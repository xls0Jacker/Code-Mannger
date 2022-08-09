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
const int MAX_N=300;
const int INF=1e9+7;
// 亲密的奶牛 Six Degrees of Cowvin Bacon
// 2≤N≤300,1≤M≤10000

//思路：
//将一场电影的人的距离设为1，
//之后用Floyd_Warshell算法得到两两之间的最短距离，
//最后找到并输出和处理最短距离即可
int N,M;
int d[MAX_N+1][MAX_N+1];
int x[MAX_N+1];
ll a[MAX_N+1];
void add_edge(int x,int y,int z=1){
    d[x][y]=z;
}

void prev(){
    rep(0,i,N){
        rep(0,j,N){
            d[i][j]=INF;
            if(i==j){
                d[i][j]=0;
            }
        }
    }
    int k;
    while(M--){
        memset(x,0,sizeof(x));
        cin>>k;
        rep(0,i,k){
            cin>>x[i];
            x[i]--;//化作0开始的下标
        }
        rep(0,i,k-1){//可以自己画个图模拟一下
            rep(i+1,j,k){
                add_edge(x[i],x[j]);//不用输出坐标不做处理
                add_edge(x[j],x[i]);
            }   
        }
    }
}
void solve(){
    rep(0,k,N){
        rep(0,i,N){
            rep(0,j,N){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(0,i,N){
        rep(0,j,N){
            a[i]+=d[i][j];
        }
    }
    cout<<floor(*min_element(a,a+N)/1.0/(N-1)*100)<<endl;//除得浮点数后，再乘100后向下取整
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    prev();
    solve();
    frepC;
    sys;
    return 0;
}

