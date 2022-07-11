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

void solve(){
    string s;
    cin>>s;
    string s0;
    int l=s.size();
    if(l<=4){
        if(s[0]<'2'){
            s.insert(0,"20");
            s.insert(4,"-");
        }
        else if(s[0]=='2' and s[1]=='0'){
            s.insert(0,"20");
            s.insert(4,"-");
        }
        else if(s[0]=='2' and s[1]=='1'){
            s.insert(0,"20");
            s.insert(4,"-");
        }
        else{
            s.insert(0,"19");
            s.insert(4,"-");
        }
        cout<<s<<endl;
    }
    else{
        s.insert(4,"-");
        cout<<s<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

