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
const int MAX_V=1e6;
int V;
//Floyd-Warshell
//求解两点之间的最短路径
//可求负权 判负圈
int d[MAX_V][MAX_V];
void warshall_floyd(){//O(|V|^3)
    rep(0,k,V){
        rep(0,i,V){
            rep(0,j,V){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

bool find_negative_loop(){//self
    rep(0,i,V){
        if(d[i][i]<0){
            return true;
        }
    }
    return false;
}
void solve(){  

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

