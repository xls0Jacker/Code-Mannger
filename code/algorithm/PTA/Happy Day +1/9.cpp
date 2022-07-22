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
int N,M;
vector<pair<int,int>> q;
int K;
typedef pair<int,int> pii;
void solve(){
    int n;
    while(K--){
        map<int,bool>mp;
        cin>>n;
        int city;
        rep(0,i,n){
            cin>>city;
            mp[city]=1;
        }
        bool f=1;
        rep(0,i,M){
            if(!mp.count(q[i].first) and !mp.count(q[i].second)){
                f=0;
                break;
            }
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    int x,y;
    rep(0,i,M){
        cin>>x>>y;
        q.push_back(pii(x,y));
    }
    cin>>K;
    solve();
    frepC;
    sys;
    return 0;
}

