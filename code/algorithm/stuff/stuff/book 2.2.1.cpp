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
int vv[6]={1,5,10,50,100,500};
int num[6];
int cnt;
int A;
void solve(){
    Rep(0,i,5){
        cin>>num[i];
    }
    int A;
    cin>>A;
    int ANS=0;
    Per(0,i,5){
        int t=min(A/vv[i],num[i]);
        A-=t*vv[i];
        ANS+=t;
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

