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
const int MAX=105;
int N;
int team[MAX];
void solve(){
    int scl=1;
    int n=N;
    while(n--){
        cout<<"#"<<scl<<endl;
        int cnt=10,tmp=scl;
        if(team)
        while(team[scl-1]--){
            rep(0,i,10){
                cout<<tmp<<" ";
                tmp+=N;
            }
            cout<<endl;
        }
        scl++;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){
        cin>>team[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

