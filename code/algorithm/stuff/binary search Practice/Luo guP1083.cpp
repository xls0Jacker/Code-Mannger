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
const int MAX=1e7;
int n,m;//天数 订单数量
ll r[MAX];//每天可用的教室数量
ll d[MAX],s[MAX],t[MAX];//租借的数量 租借开始 租借结束
ll a[MAX],c[MAX];//差分用 存前缀和
bool check(int x){//当前订单号
    memset(a,0,sizeof(a));
    Rep(1,i,x){//差分
        a[s[i]]+=d[i];
        a[t[i]+1]-=d[i];
    }
    Rep(1,i,n) c[i]=c[i-1]+a[i];//求前缀和
    Rep(1,i,n){
        if(c[i]>r[i]) return false;//租借数量超过当天可借的数量
    }
    return true;
}
void solve(){
    //输入
    cin>>n>>m;
    Rep(1,i,n) cin>>r[i];
    Rep(1,i,m) cin>>d[i]>>s[i]>>t[i];
    //二分订单数
    int l=1,r=m+1;
    while(l+1<r){
        int m=(r+l)/2;
        if(check(m)) l=m;
        else r=m;
    }//找第一个不成立的订单数前一个成立的位置
    if(l==m) cout<<0<<endl;
    else {
        if(!check(l)) l--;//若1不成立，而l从1开始，无法找到前一个点 此时l--来抵消后面的l++
        cout<<-1<<endl<<l+1<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

