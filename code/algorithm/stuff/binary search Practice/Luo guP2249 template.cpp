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
int n,m;//总个数及访问次数
int a[MAX];
int num;
bool check(int mid){//m处的a[m]值 //自主实现
    return mid<num;
}

int binary(){//二分模板
    int l=-1,r=n;
    while(l+1!=r){
        int m=(l+r)/2;
        if(check(a[m])){//此处看情况进行修改 其他地方原封不动
            l=m;
        }
        else {
            r=m;
        }
    }
    return r;
}

void solve(){
    cin>>n>>m;
    rep(0,i,n){
        cin>>a[i];
    }
    sort(a,a+n);//二分前置条件
    bool f=false;//处理符号
    Rep(1,i,m){
        cin>>num;
        int p=binary();
        if(a[p]!=num){//后续处理
            if(f) cout<<" ";
            cout<<"-1";
            f=true;
        }
        else {
            if(f) cout<<" ";
            cout<<p+1;
            f=true;
        }
    }
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

