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
int a[5];
int x;
void solve(){
    Rep(1,i,4){
        cin>>a[i];
    }
    cin>>x;
    Rep(1,i,4){
        if(x>=a[i]){
            a[i]=x-a[i];
        }
        else a[i]=0;
    }
    Rep(1,i,4){
        cout<<a[i]<<" ";
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

