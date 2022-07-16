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

void solve(){
    ll sum=0;//存款
    ll ret=0;//结余
    int prec;//预算
    Rep(1,i,12){
        ret+=300;//新月份加钱
        cin>>prec;
        if(prec>ret){//预算超结余
            cout<<-i<<endl;
            return;
        }
        else {
            ret-=prec;//减去预算
            int t=ret/100;//倍数
            ret%=100;//结余
            sum+=100*t;//存款上涨
        }
    }
    double ANS=ret*1.0+sum*1.2;
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

