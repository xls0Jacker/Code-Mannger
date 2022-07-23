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
const int MAX_V=1000;
//二分图判定
//1<=n<=1000
//从任意一个顶点出发，依次确定相邻顶点的颜色
//深度优先搜索实现
vector<int>G[MAX_V];
int V;
int color[MAX_V];//染成1 or -1
bool dfs(int v,int c){
    color[v]=c;
    rep(0,i,G[v].size()){
        if(color[G[v][i]]==c) return false;//相邻顶点同色
        if(color[G[v][i]]==0 and !dfs(G[v][i],-c)) return false;//相邻顶点未被染色，则染成-c
    }
    return true;//所有顶点均染色
}

void solve(){
    rep(0,i,V){
        if(color[i]==0){//所在顶点并未染色
            if(!dfs(i,1)){
                puts("No");
                return;
            }
        }
    }
    puts("Yes");
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

