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
//GCD and LCM
//0<a,b≤2,000,000,000

//辗转相除法
ll gcd(ll a,ll b){//O(log max(a,b))
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int A,B;
void solve(){
    cout<<gcd(A,B)<<" "<<lcm(A,B)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>A>>B){
        solve();
    }
    frepC;
    sys;
    return 0;
}










