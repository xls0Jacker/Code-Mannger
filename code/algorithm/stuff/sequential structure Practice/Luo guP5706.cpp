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
float n;
int m;
void solve(){
    cin>>n>>m;
    float ANS=n/m;
    int NUM=m*2;
    printf("%.3lf\n%d",ANS,NUM);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

