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
double a,b,c;
void solve(){
    cin>>a>>b>>c;
    double p=0.5*(a+b+c);
    double ANS=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf\n",ANS);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

