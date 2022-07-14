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
ll a[MAX];
int n,c;

bool check(int x){
    int m=a[1];
    int cnt=0;
    Rep(2,i,n){
        if(a[i]-m<x){
            cnt++;
        }
        else m=a[i];
    }
    if(cnt>n-c) return false;
    return true;
}

void solve(){
    //输入
    cin>>n>>c;
    Rep(1,i,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    //二分
    ll l=1,r=a[n]-a[1];
    while(l+1<r){
        int m=(l+r)/2;
        if(check(m)) l=m;
        else r=m;
    }
    cout<<l<<endl;//<=  最小值的最大值
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

