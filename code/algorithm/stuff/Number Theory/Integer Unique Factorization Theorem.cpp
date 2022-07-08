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
//求n!末尾有多少个0？
void solve(){
    int n;
    cin>>n;
    int ANS=0;
    for(int i=5;i<=n;i*=5){
        ANS+=n/i;
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

