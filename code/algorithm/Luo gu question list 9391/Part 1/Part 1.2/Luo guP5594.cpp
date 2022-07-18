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
bool a[1005][1005];
int ans;

void solve(){ 
    //输入
    int n,m,k;
    cin>>n>>m>>k;
    Rep(1,i,n){
        Rep(1,j,m){
            int x;
            cin>>x;
            a[x][j]=1;//存合理天数的套数
        }
    }
    //处理
    Rep(1,i,k){
        ans=0;
        Rep(1,j,m){
            if(a[i][j]) ans++;
        }
        cout<<ans<<" ";
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

