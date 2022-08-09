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
const int MAX_N=10;
const int INF=1e9+7;
// 方便的地点 Convenient Location
// 1≤n≤45 0≤u,v≤9,u≠v,0≤w≤100
// 无重边，无自环

//思路：
//顶点数目较少，使用邻接矩阵存储，
//并且无重边，无自环，用临接矩阵也更方便，
//找最短路同样由于顶点数较少，可以过O(V^3)的时间复杂度，
//使用Floyd_Warshell的算法处理会比较方便
int d[MAX_N+1][MAX_N+1];
int n;
ll a[MAX_N+1];
void add_edge(int x,int y,int z){
    d[x][y]=z;
}

int V;//顶点数
void prev(){
    rep(0,i,10){
        rep(0,j,10){
            d[i][j]=INF;
            if(i==j){
                d[i][j]=0;
            }
        }
    }
    int x,y,value;
    V=-1;
    rep(0,i,n){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
        V=max(V,x);
        V=max(V,y);
    }
    V++;//输入最大为4，顶点数为5
}

void solve(){
    rep(0,k,V){
        rep(0,i,V){
            rep(0,j,V){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(0,i,V){
        rep(0,j,V){
            a[i]+=d[i][j];
        }
    }
    cout<<(min_element(a,a+V)-a)<<" "<<*min_element(a,a+V)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>n and n!=0){
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        prev();
        solve();
    }
    frepC;
    sys;
    return 0;
}

