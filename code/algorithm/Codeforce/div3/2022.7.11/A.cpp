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
const int MAX=100;
ll a[MAX];
int n;
void solve(){
    cin>>n;
    ll tmp=1;
    a[1]=1;
    Rep(2,i,12){
        tmp*=10;
        a[i]=tmp;
    }
    ll m;
    Rep(1,i,n){
        cin>>m;
        Per(1,j,12){
            if(m>=a[j]){
                cout<<m-a[j]<<endl;
                break;
            }
        }
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

