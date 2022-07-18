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
const int mod=11;
void solve(){
    string s;
    cin>>s;
    int sum=0;
    int cnt=1;
    rep(0,i,s.size()-1){
        if(s[i]!='-'){
            sum+=(s[i]-'0')*cnt;
            cnt++;
        }
    }
    sum%=mod;
    bool f=false;
    char tmp;
    if(sum==10){//处理特况
        tmp='X';
        f=1;
    }
    if(!f){
        if(sum==(s[s.size()-1]-'0')){
            cout<<"Right"<<endl;
        }
        else {
            s.replace(s.size()-1,1,to_string(sum));
        cout<<s<<endl;
        }
    }
    else {
        if(tmp==s[s.size()-1]){
            cout<<"Right"<<endl;
        }
        else {
            s.replace(s.size()-1,1,"X");
            cout<<s<<endl;
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

