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
const int INF=1e9+7;
const int MAX_N=1e5;

int a[MAX_N+1];
int b[MAX_N+1];

int n;
void solve(){
    int mark=0,endd=0;
    map<int,int>mp;
    rep(0,i,n){
        cin>>a[i];
        if(i==0){
            mp[a[i]]=1;
            b[i]=1;
        }
        else {
            if(!mp.count(a[i])){
                mp[a[i]]=1;
                b[i]=b[i-1]+1;
            }
            else {
                if(a[i-1]!=a[i])
                    endd=i;
                b[i]=b[i-1];
            }
        }
        }
        mark=endd;
        Per(max(endd,1),i,n-1)
            if(a[i-1]>a[i])
            {
                mark=i;
                break;
            }
        if(mark==0)
            cout<<0<<endl;
        else
            cout<<b[mark-1]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n;
        solve();
    }
    frepC;
    sys;
    return 0;
}
