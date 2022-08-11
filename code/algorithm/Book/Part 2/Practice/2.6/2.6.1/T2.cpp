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
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else {
        x=1,y=0;
    }
    return d;
}
double _a,_b;
int x,y;
void solve(){
    int LCM,GCD;
    cin>>GCD>>LCM;
    _a=_b=1/LCM;
    extgcd(_a,_b,x,y);
    cout<<x<<" "<<y<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

