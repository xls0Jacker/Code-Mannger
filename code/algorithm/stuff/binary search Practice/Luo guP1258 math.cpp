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
double s,a,b;
void solve(){
    cin>>s>>a>>b;
    double x=(b+a)*s/(b+3*a);
    double t=x/b+(s-x)/a;
    printf("%.6lf\n",t);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}
