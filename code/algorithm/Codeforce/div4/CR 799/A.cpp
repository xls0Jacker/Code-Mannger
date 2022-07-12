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
int t;
int a;
int dis[4];
void solve(){
    cin>>t;
    Rep(1,i,t){
        cin>>a;
        Rep(1,i,3){
            cin>>dis[i];
        }
        int cnt=0;
        Rep(1,i,3){
            if(a<dis[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

