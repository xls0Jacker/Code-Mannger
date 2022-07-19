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
int f[1005];//可以打表或者打表找规律递推
void solve(){
    int n;
    cin>>n;
    f[0]=f[1]=1;
    Rep(2,i,n){
        if(i%2==0){
            f[i]=f[i-1]+f[i/2];
        }
        else {
            f[i]=f[i-1];
        }
    }
    cout<<f[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

