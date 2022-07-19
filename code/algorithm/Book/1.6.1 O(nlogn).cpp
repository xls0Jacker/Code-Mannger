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
const int MAX=105;
int a[MAX];
//n <= 100 a[i]<=1e6
void solve(){//O(nlogn)做法
    int n;
    cin>>n;
    Rep(1,i,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    Rep(1,i,n-2){
        if(a[i]<a[i+1]+a[i+2]){
            cout<<a[i]+a[i+1]+a[i+2]<<endl;
            return;
        }
    }
    cout<<0<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

