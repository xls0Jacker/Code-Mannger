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
int t;
int a[5];
void solve(){
    cin>>t;
    int cnt;
    while(t--){
        cnt=0;
        Rep(1,i,4){
            cin>>a[i];
            if(a[i]==1) cnt++;
        }
        if(cnt==4){
            cout<<2<<endl;
        }
        else if(cnt==0){
            cout<<0<<endl;
        }
        else cout<<1<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

