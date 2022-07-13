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
int n,m;//总个数及访问次数
int a[MAX],b[MAX];

void solve(){
    cin>>n>>m;
    rep(0,i,n){
        cin>>a[i];
    }
    rep(0,i,m){
        cin>>b[i];
    }
    sort(b,b+m);
    rep(0,i,n){
        int l=-1,r=m;
        while(l+1!=r){
            int mid=(l+r)/2;
            if(b[mid]==a[i]){
                cout<<a[i]<<" ";
                break;
            }
            else if(b[mid]<a[i]) l=mid;
            else {
                r=mid;
            }
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
