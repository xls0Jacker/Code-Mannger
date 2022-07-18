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
    ll n;
    cin>>n;
    string s=to_string(n);
    Per(0,i,s.size()-1){
        if(s[i]=='0' and i!=0){//i!=0 用来处理单个0
            s.erase(s.begin()+i);//删除下标为i的字符
        }
        else break;
    }
    if(s[0]=='-'){
        reverse(s.begin()+1,s.end());
    }
    else {
        reverse(s.begin(),s.end());
    }
    cout<<s<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

