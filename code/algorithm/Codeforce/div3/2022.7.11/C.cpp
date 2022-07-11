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
//wrong 2
void solve(){
    int n;
    cin>>n;
    Rep(1,i,n){
        string s;
        int u,v;//长度 测试样例数目
        cin>>u>>v;
        cin.get();
        getline(cin,s);
        Rep(1,i,v){
            string a,b;
            cin>>a>>b;
            int s0=s.find(a,0);
            int check=s.find(b,s0);
            if(check==-1){
                cout<<"NO"<<endl;
            }
            else cout<<"YES"<<endl;
        }
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

