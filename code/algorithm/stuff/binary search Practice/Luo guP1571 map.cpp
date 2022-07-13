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
const int MAX=1e6;
map<int,bool>mp;
int a[MAX],b[MAX];
int n,m;
void solve(){
    cin>>n>>m;
    Rep(1,i,n){
        cin>>a[i];
    }
    Rep(1,i,m){
        cin>>b[i];
        mp[b[i]]=true;
    }
    Rep(1,i,n){
        if(mp[a[i]]){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

