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
#define F(x) a*x*x*x+b*x*x+c*x+d
double a,b,c,d;

bool check(double m,double r){
    return F(m)*F(r)<0;
}

double binary(){
    double l=-101,r=101;
    while(l+1!=r){
        double m=(l+r)/2;
        if(check(m,r)){
            l=m;
        }
        else r=m;
    }
    return l;
}

void solve(){
    cin>>a>>b>>c>>d;
    binary();
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

