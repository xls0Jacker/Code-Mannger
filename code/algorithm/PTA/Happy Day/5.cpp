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
const int MAX=30;
int a[MAX];
bool vis[MAX];
void solve(){
    rep(0,i,24){
        cin>>a[i];
        if(a[i]>50){
            vis[i]=1;
        }
    }
    int tmp;
    cin>>tmp;
    while(tmp>=0 and tmp<=23){
        if(vis[tmp]) cout<<a[tmp]<<" Yes"<<endl;
        else cout<<a[tmp]<<" No"<<endl;
        cin>>tmp;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

