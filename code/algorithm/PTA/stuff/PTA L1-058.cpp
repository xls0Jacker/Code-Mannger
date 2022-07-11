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
//字符串的应用
string s;
void solve(){
    getline(cin,s);
    int l=s.length();
    rep(0,i,l){
        int cnt=0;
        int pos=s.find('6',i);
        if(pos!=-1){
            rep(pos,j,l){
                if(s[j]=='6'){
                    cnt++;
                }
                else break;
            }
            if(cnt>3 and cnt<=9){
                s.replace(pos,cnt,"9");
            }
            else if(cnt>9){
                s.replace(pos,cnt,"27");
            }
        }
        else break;
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

