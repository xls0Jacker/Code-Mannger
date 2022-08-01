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
int n,m;
string a,b;
void solve(){
    int size=a.size()-b.size(),bo=0;
    for(int i=a.size()-1,j=b.size()-1; j>=1; j--,i--)
        if(a[i]!=b[j])
        {
            bo=1;
            break;
        }
    if(bo==1)
        cout<<"NO"<<endl;
    else
    {
        Rep(0,i,size)
            if(a[i]==b[0])
            {
                bo=1;
                break;
            }
        if(bo==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>a>>b;
        solve();
    }
    frepC;
    sys;
    return 0;
}
