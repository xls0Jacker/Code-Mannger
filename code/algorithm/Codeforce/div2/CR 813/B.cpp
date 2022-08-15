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
// int gcd(int a,int b){//O(log max(a,b))
//     if(b==0) return a;
//     return gcd(b,a%b);
// }

// int lcm(int a,int b){
//     return a*b/gcd(a,b);
// }
int n;
void solve(){
    if(n%2==0){
        for(int i=1;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
    }
    else {
        cout<<1<<" ";
        for(int i=2;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        solve();
    }
    frepC;
    sys;
    return 0;
}
