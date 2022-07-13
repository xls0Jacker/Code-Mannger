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
int num;
int a[MAX];
int n,m;
//WA*3
bool check(int mid){//找第一个>=的
    return mid<num;
}

int binary(){
    int l=-1,r=n;
    while(l+1!=r){
        int m=(l+r)/2;
        if(check(a[m])){
            l=m;
        }
        else r=m;
    }
    return r;
}

void solve(){
    cin>>n>>m;
    rep(0,i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ANS=0;
    rep(0,i,m){
        cin>>num;
        int p=binary();
        ll cnt=min(abs(num-a[p]),abs(num-a[p-1]));//找最小差值
        ANS+=cnt;
    }
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

