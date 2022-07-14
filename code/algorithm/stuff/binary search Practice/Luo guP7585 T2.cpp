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
//求最大嫉妒值的最小值 >=
const int MAX=1e7;
int n,m;//孩数 弹珠种类数
int a[MAX];
int N;//最大嫉妒值

bool check(ll x){//当前最大的嫉妒值
    int cnt=0;
    Rep(1,i,m){
        cnt+=ceil(a[i]/1.0/x);//最大可平均分配人数//不足1人向上取整
    }
    return cnt<=n;
}

void solve(){
    //输入
    cin>>n>>m;
    Rep(1,i,m){
        cin>>a[i];
        N+=a[i];
    }
    ll l=0,r=N;
    while(l+1<r){
        ll m=(l+r)/2;
        if(check(m)) l=m;
        else r=m;
    }
    cout<<r<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

