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
char maze[MAX][MAX];
//N,M<=100
const int INF=1e8;
typedef pair<int,int> P;
int sx,sy;
int gx,gy;
int d[MAX][MAX];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};//正序 反序

int bfs(){//O(4xNxM)
    queue<P>que;
    Rep(1,i,N){//O(NxM)
        Rep(1,j,M){
            d[i][j]=INF;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy]=0;
    while(que.size()){//O(NxM)
        P p=que.front();
        que.pop();
        if(p.first==gx and p.second==gy) break;
        rep(0,i,4){//O(4)
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(nx>=1 and nx<=N and ny>=1 and ny<=M and maze[nx][ny]!='#' and d[nx][ny]==INF){
                que.push(P(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    return d[gx][gy];
}
void solve(){//O(NxM)做法
    int res=bfs();
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    Rep(1,i,N){
        Rep(1,j,M){
            cin>>maze[i][j];
            if(maze[i][j]=='S'){
                sx=i,sy=j;
            }
            if(maze[i][j]=='G'){
                gx=i,gy=j;
            }
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

/*
    测试数据:
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/

