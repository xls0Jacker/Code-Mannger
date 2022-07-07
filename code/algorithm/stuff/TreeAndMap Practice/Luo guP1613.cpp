#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;

int n,m;//点数目 边数目、
int cnt[1010];//每一点的入度和出度之和
int Ans;

void solve(){
    cin>>n>>m;
        Rep(1,i,m){//计算每条边的度数之和
            int x,y;
            cin>>x>>y;
            cnt[x]++;
            cnt[y]++;
        }
        Rep(1,i,n){
            if(cnt[i]%2) Ans++;//存在度数为奇数时++
        }
        if(Ans==0) cout<<Ans+1;
        else cout<<Ans/2<<endl;//笔画数为奇点数余2
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

