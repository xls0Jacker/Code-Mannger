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
const int MAX=105;
int N,M;
char field[MAX][MAX];
//N,M<=100
//从任意的'W'开始，不停把邻接的部分用'.'代替。1次DFS后与初始的这个W连接的所有W就被替换成了'.'，
//因此直到图中不再存在W为止，总共进行的DFS次数就是答案
void dfs(int x,int y){//O(8)
    field[x][y]='.';
    Rep(-1,dx,1){//O(3x3-1)
        Rep(-1,dy,1){
            int nx=x+dx,ny=y+dy;
            if(nx>=1 and nx<=N and ny>=1 and ny<=M and field[nx][ny]=='W'){
                dfs(nx,ny);
            }
        }
    }
}
void solve(){//O(NxM)做法
    int res=0;
    Rep(1,i,N){//O(NxMx8)
        Rep(1,j,M){
            if(field[i][j]=='W'){
                dfs(i,j);
                res++;
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    Rep(1,i,N){
        Rep(1,j,M){
            cin>>field[i][j];
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

