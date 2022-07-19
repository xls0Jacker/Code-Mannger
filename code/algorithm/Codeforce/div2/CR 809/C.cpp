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
const int MAX=1e6+100;
int h[MAX];
int n;

int get_value(int i){
    if(h[i]<=max(h[i-1],h[i+1])){//本身不酷
        return (max(h[i+1],h[i-1])-h[i])+1;//差值＋1
    }
    else return 0;
}

void solve(){
    //memset(h,0,sizeof(h));
    cin>>n;
    Rep(1,i,n){
        cin>>h[i];
    }
    int cnt=0;
    ll sum=0;
    if(n%2!=0){//奇数
        for(int i=2;i<=n-1;i+=2){
            sum+=get_value(i);
        }
        cout<<sum<<endl;
        return;
    }
    else {//偶数
        for(int i=2;i<=n-1;i+=2){
            sum+=get_value(i);
        }
        ll ans=sum;
        for(int i=n-1;i>1;i-=2){
            sum-=get_value(i-1);
            sum+=get_value(i);
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
        return;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

