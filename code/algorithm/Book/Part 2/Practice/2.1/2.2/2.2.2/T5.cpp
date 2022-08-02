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
const int MAX_N=1e5;
//赶牛 Protecting the Flowers
//2≤N≤1e5 1≤Ti≤2*1e6 1≤Di≤100

//思路：
//对于牛A和牛B，
//有T1,D1;T2,D2,
//若T1*D2<T2*D1，
//先赶走牛A：
//cost=2T1*D2;
//先赶走牛B：
//cost=2T2*D1;
//此时我们优先赶走牛A

//处理方法：
//一开始存总的cost，
//每走一只存减去其cost，再将剩下的值*2*其时间，
//最后累加得到最小时间
int N;
typedef pair<ll,ll> P;//时间 单位时间内吃的量
P q[MAX_N+1];

bool cmp(P a,P b){
    if(a.first*b.second<b.first*a.second){
        return 1;
    }
    else return 0;
}
void solve(){
    sort(q,q+N,cmp);
    ll ans=0;
    ll Totalcost=0;
    rep(0,i,N){//计算总单位时间内吃的量
        Totalcost+=q[i].second;
    }
    rep(0,i,N){//处理
        Totalcost-=q[i].second;
        ans+=2*q[i].first*Totalcost;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){
        cin>>q[i].first>>q[i].second;
    }
    solve();
    frepC;
    sys;
    return 0;
}

