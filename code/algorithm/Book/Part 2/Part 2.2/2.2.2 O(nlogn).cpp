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
const int MAX=1e5+10;
int N;
int s[MAX],t[MAX];
//区间问题
//1<=N<=1e5 1<=si<=ti<=1e9
//在可选的工作中，每次都选择结束时间最早的工作
pair<int,int> itv[MAX];
void solve(){//O(nlogn)做法
    rep(0,i,N){//O(N)
        itv[i].first=t[i];
        itv[i].second=s[i];
    }
    sort(itv,itv+N);//O(NlogN)//先排first first相同排second
    int ans=0,t=0;
    rep(0,i,N){//O(N)
        if(t<itv[i].second){
            ans++;
            t=itv[i].first;
        }
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N){
        rep(0,i,N){//O(N)
        cin>>s[i]>>t[i];
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

