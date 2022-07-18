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
const int MAX=1e7;
bool a[MAX];
void solve(){
    int l,m;
    cin>>l>>m;
    Rep(0,i,l){
        a[i]=true;
    }
    int ls,rs;
    while(m--){
        cin>>ls>>rs;
        Rep(ls,i,rs){
            a[i]=false;
        }
    }
    int cnt=0;
    Rep(0,i,l){
        if(a[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

