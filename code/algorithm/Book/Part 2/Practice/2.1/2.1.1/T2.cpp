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
const int MAX_H=100,MAX_W=100;
//果园
//1<=H,W<=100

//思路：
//对每一块地进行遍历，若其与自身符号相同，
//则将其变为'.'，
//其后每一次不为'.'的地答案数+1
int H,W;
char M[MAX_H+1][MAX_W+1];
int ans;
void dfs(int x,int y,char c){
    if(x<0 or x>=H or y<0 or y>=H or M[x][y]!=c) return;
    M[x][y]='.';
    dfs(x-1,y,c);
    dfs(x+1,y,c);
    dfs(x,y+1,c);
    dfs(x,y-1,c);
}
void solve(){
    rep(0,i,H){//O(H*W)
        rep(0,j,W){
            if(M[i][j]!='.'){
                ans++;
                dfs(i,j,M[i][j]);
            }
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>H>>W and H!=0 and W!=0){
        memset(M,0,sizeof(M));//O(H*W)
        rep(0,i,H){//O(H*W)
            rep(0,j,W){
                cin>>M[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

