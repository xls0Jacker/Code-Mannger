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
const int MAX=1e4;
int t;
int n;


void solve(){
    int a[MAX];
    cin>>t;
    Rep(1,i,t){
        memset(a,0,sizeof(a));
        cin>>n;
        Rep(1,i,n){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int ANS=n-(unique(a+1,a+n+1)-(a+1));
        if(ANS%2==1){
            ANS++;
        }
        cout<<n-ANS<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

