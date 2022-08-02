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
// 碰撞游戏 Stripies
// 1≤n≤100,1≤w≤10000

// 猜想：
// 从大到小排，取相邻的计算其值（如果合理）
// 之后将其值压入数组

//猜想成立

//证明：
//没有
int n;
priority_queue<double> w;
void solve(){
    while(w.size()!=1){
        double q1=w.top();w.pop();//取前两个球
        double q2=w.top();w.pop();
        double val=2*sqrt(q1*q2);
        w.push(val);
    }
    printf("%.3lf\n",w.top());
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    double W;
    rep(0,i,n){
        cin>>W;
        w.push(W);
    }
    solve();
    frepC;
    sys;
    return 0;
}

