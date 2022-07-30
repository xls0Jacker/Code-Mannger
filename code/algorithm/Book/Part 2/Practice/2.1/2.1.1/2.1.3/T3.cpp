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
//Hopscotch 跳房子

//思路：
//dfs遍历每一格，
//将不同的字符串存入set，
//最后输出set的大小即可
int M[5][5];
set<vector<int>> s;
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};
void dfs(int x,int y,vector<int>&v){
    if(v.size()==6){
        s.insert(v);
        return;
    }
    v.push_back(M[x][y]);
    rep(0,i,4){
        int dx=x+xx[i],dy=y+yy[i];
        if(dx<0 or dx>=5 or dy<0 or dy>=5) continue;
        dfs(dx,dy,v);
    }
    v.pop_back();
    return;
}
void solve(){
    rep(0,i,5){
        rep(0,j,5){
            vector<int>v;//答案数组
            dfs(i,j,v);
        }
    }
    cout<<s.size()<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    rep(0,i,5){
        rep(0,j,5){
            cin>>M[i][j];
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

