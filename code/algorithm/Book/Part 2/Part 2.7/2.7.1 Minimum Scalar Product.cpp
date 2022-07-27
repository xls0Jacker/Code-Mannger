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
const int MAX_N=805;
//最小标量集
//small:
//1<=n<=8 -1000<=xi,yi<=1000
//Large:
//100<=n<=800 -100000<=xi,yi<=100000

//猜想：
//一个数组按升序排列 另一个数组按降序排列
//此时内积最小

//猜想证明：
//设集合x升序排列，集合y降序排列
//当n=2时，
//对于：
//① x1y1+x2y2
//② x1y2+x2y1
//①-② x1(y1-y2)+x2(y2-y1)=(x1-x2)(y1-y2)<=0
//故①<=②
//当n>2时，
//存在i<j，满足同样的关系

//猜想成立
int n;
int v1[MAX_N],v2[MAX_N];
void solve(){
    sort(v1,v1+n);
    sort(v2,v2+n);
    ll ans=0;
    rep(0,i,n) ans+=(ll)v1[i]*v2[n-i-1];
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>v1[i];
    }
    rep(0,i,n){//O(n)
        cin>>v2[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

