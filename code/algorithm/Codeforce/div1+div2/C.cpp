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
bool cmp(ll x,ll y)
{
    return x>y;
}
bool cmp_(ll x,ll y)
{
    return x<y;
}
void solve(){
    int n,m,ans=0;
    cin>>n>>m;
    vector<ll>a(m);
    vector<ll>len;
    rep(0,i,m){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp_);
    if(a[0]!=1)
        len.push_back(a[0]-1);
    if(a[m-1]!=n)
        len.push_back(n-a[m-1]);
    if(a[0]!=1 and a[m-1]!=n){
        len[0]+=len[1];
        len.erase(len.end()-1);
    }
    rep(1,i,m){
        if(a[i]-a[i-1]>1)
            len.push_back(a[i]-a[i-1]-1);
    }
    sort(len.begin(),len.end(),cmp);
    int bo=0;
    rep(0,i,len.size())
    {
        len[i]-=bo*4;
        if(len[i]>1)
            len[i]--;
        if(len[i]<=0)
            break;
        ans+=len[i];
        bo++;
    }
    cout<<n-ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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
