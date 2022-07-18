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
const int MAX=1e7;
int a[MAX];
void solve(){
    int n,q;
    cin>>n>>q;
    Rep(1,i,n){
        cin>>a[i];
    }
    vector<int>v;
    int cnt=0;
    Per(1,i,n){
        if(a[i]<=cnt){
            v.push_back(1);
        }
        else if(cnt<q){
            v.push_back(1);
            cnt++;
        }
        else {
            v.push_back(0);
        }
    }
    Per(0,i,n-1){
        cout<<v[i];
    }
    cout<<endl;
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

