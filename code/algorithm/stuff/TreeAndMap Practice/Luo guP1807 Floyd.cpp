#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
//最长路 Floyd
/*

    边长改为负权
    找负的最小值
    加上绝对值后即是找正的最大值

*/
int n,m;//点 边
const int MAX=1510;

int S[MAX][MAX];

void solve(){
    cin>>n>>m;
    Rep(1,i,n){//建立邻接矩阵（变体）
        Rep(1,j,n){
            if(i==j) S[i][j]=0;
            else S[i][j]=0x3f3f3f3f;
        }
    }
    int x,y,l;
    Rep(1,i,m){
        cin>>x>>y>>l;
        S[x][y]=min(S[x][y],-l);
    }
    Rep(1,k,n){
        Rep(1,j,n){
            Rep(1,i,n){
                if(S[i][k]!=0x3f3f3f3f and S[k][j]!=0x3f3f3f3f)
                    S[i][j]=min(S[i][j],S[i][k]+S[k][j]);
            }
        }
    }
    if(S[1][n]==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<-S[1][n]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

