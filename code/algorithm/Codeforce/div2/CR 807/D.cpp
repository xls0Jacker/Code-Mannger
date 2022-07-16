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

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if(s[0]!=t[0] or s[n-1]!=t[n-1]){
        cout<<"-1"<<endl;
        return;
    }
    vector<ll>q_s,q_t;
    rep(0,i,n-1){
        if(s[i]!=s[i+1]) q_s.push_back(i);
        if(t[i]!=t[i+1]) q_t.push_back(i);
    }
    if(q_s.size()!=q_t.size()){
        cout<<"-1"<<endl;
    }
    else {
        ll k=q_s.size();
        ll ANS=0;
        rep(0,i,k){
            ANS+=abs(q_s[i]-q_t[i]);
        }
        cout<<ANS<<endl;
    }
}

int main(){
    frep;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    frepC;
    sys;
    return 0;
}

