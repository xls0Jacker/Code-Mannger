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
const int MAX=100;
int N,M;
string s1="qiandao";
string s2="easy";
void solve(){
    string s[MAX];
    bool vis[MAX];
    memset(vis,0,sizeof(vis));
    cin>>N>>M;
    cin.get();
    Rep(1,i,N){
        getline(cin,s[i]);
        if(s[i].find(s1,0)==string::npos and s[i].find(s2,0)==string::npos){
            vis[i]=1;
        }
    }
    bool f=0;
    int cnt=-1;
    string tmp;
    Rep(1,i,N){//找M+1次的数组
        if(vis[i]){
            cnt++;
            tmp=s[i];
            if(cnt==M) break;
        }
    }
    if(cnt!=M) cout<<"Wo AK le"<<endl;
    else cout<<tmp<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

