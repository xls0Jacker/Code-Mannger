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
int n,W;
int w[MAX],v[MAX];
//01背包问题
//1<=n<=100 1<=wi,vi<=100 1<=W<=10000
//针对每个物品是否放入背包进行搜索
int rec(int i,int j){//物品位次 当前容量//O(2^n)做法//n个物品都有选和不选两种选项
    int res;
    if(i==n){//无物可装
        res=0;
    }
    else if(j<w[i]){//装不下
        res=rec(i+1,j);
    }
    else {
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
    return res;
}
void solve(){
    cout<<rec(0,W)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>w[i];
    }
    rep(0,i,n){//O(n)
        cin>>v[i];
    }
    cin>>W;
    solve();
    frepC;
    sys;
    return 0;
}

/*
    测试数据:
4
2 1 3 2
3 2 4 2
5
*/